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


	//将从某个客户端收到的消息挂到 每一个客户端的write_msgs队尾 具体见ZLSessin_Participant::deliver

	void deliver(const ZLPacket& msg)

	{
		recent_packets_.push_back(msg);
		while (recent_packets_.size() > max_recent_msgs)
			recent_packets_.pop_front(); //room中保存的消息数有限

		std::for_each(participants_.begin(), participants_.end(),
			boost::bind(&ZLSessin_Participant::deliver, _1, boost::ref(msg)));
	}

private:
	std::set<session_participant_ptr> participants_;//用set来保存用户信息
	enum { max_recent_msgs = 100 };
	packet_queue recent_packets_;//用来保存从某个客户端接收到的信息
};