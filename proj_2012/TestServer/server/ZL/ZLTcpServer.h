#pragma once
//
// ZLTcpServer.cpp
//�������˳������ȿ���һ��ZLTcpServer��������ʼ��io_service��ZLRoom;  ������ÿ��ֻ����һ��ZLRoom��ZLRoom��������
//1.�����û���Ϣ  2.ʵ���û���join��leave  3.�����ÿ���ͻ��˽��յ�����Ϣ  4.�����յ�����Ϣ�ҵ�ÿһ���ͻ���write_msgs��β
//ÿ������һ���ͻ��ˣ�socket���Ϳ���һ���µ�ZLSession ������Ψһ��ZLRoom   ZLSession��ʵ�ֱַ��ÿһ���ͻ��˵��첽��д//����

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "ZLRoom.h"
#include "ZLPacket.h"
#include "ZLSession.h"

using boost::asio::ip::tcp;

class ZLTcpServer
{
public:
	ZLTcpServer(boost::asio::io_service& io_service,
		const tcp::endpoint& endpoint)
		: io_service_(io_service),
		acceptor_(io_service, endpoint) //ȫ��ֻ��һ��io_service��һ��acceptor
	{
		start_accept();
	}

	void start_accept()
	{
		session_ptr new_session(new ZLSession(io_service_, room_));
		acceptor_.async_accept(new_session->socket(),
			boost::bind(&ZLTcpServer::handle_accept, this, new_session,
				boost::asio::placeholders::error));//�����ͻ��˵ĵ�����һ���пͻ�����������ִ������Ĵ��룻
	}

	void handle_accept(session_ptr session,
		const boost::system::error_code& error)
	{
		if (!error)
		{
			session->start();
		}

		start_accept(); // ���������ͻ����������� ÿ������һ��socket������� 
	}

private:
	boost::asio::io_service& io_service_;
	tcp::acceptor acceptor_;
	ZLRoom room_; //ZLRoom��û�����ع��캯�� ���Ի�ֱ�ӵ���Ĭ�Ϲ��캯��
};

typedef boost::shared_ptr<ZLTcpServer> tcp_server_ptr;
typedef std::list<tcp_server_ptr> tcp_server_list;

//----------------------------------------------------------------------
//�첽����Tcp������
void startAsyncTcpServer(std::string port);
//ͬ������Tcp������
void startSyncServer(std::string port);


