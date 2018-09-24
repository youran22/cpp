#pragma once
#include "boost/bind.hpp"
#include "ZLPacket.h"
#include "ZLSessin_Participant.h"

class ZLRoom
{
public:
	void join(session_participant_ptr participant)
	{
		participants_.insert(participant);
		std::for_each(recent_packets_.begin(), recent_packets_.end(),
			boost::bind(&ZLSessin_Participant::deliver, participant, _1));
	}

	void leave(session_participant_ptr participant)
	{
		participants_.erase(participant);
	}


	//����ĳ���ͻ����յ�����Ϣ�ҵ� ÿһ���ͻ��˵�write_msgs��β �����ZLSessin_Participant::deliver

	void deliver(const ZLPacket& msg)

	{
		recent_packets_.push_back(msg);
		while (recent_packets_.size() > max_recent_msgs)
			recent_packets_.pop_front(); //room�б������Ϣ������

		std::for_each(participants_.begin(), participants_.end(),
			boost::bind(&ZLSessin_Participant::deliver, _1, boost::ref(msg)));
	}

private:
	std::set<session_participant_ptr> participants_;//��set�������û���Ϣ
	enum { max_recent_msgs = 100 };
	packet_queue recent_packets_;//���������ĳ���ͻ��˽��յ�����Ϣ
};