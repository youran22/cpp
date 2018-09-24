#pragma once
//
// ZLTcpServer.cpp
//服务器端程序，首先开启一个ZLTcpServer，用来初始话io_service和ZLRoom;  服务器每次只开启一个ZLRoom，ZLRoom的作用是
//1.保存用户信息  2.实现用户的join和leave  3.保存从每个客户端接收到的信息  4.将接收到的消息挂到每一个客户端write_msgs队尾
//每连接上一个客户端（socket）就开启一个新的ZLSession 并加入唯一的ZLRoom   ZLSession中实现分别对每一个客户端的异步读写//操作

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
		acceptor_(io_service, endpoint) //全局只有一个io_service和一个acceptor
	{
		start_accept();
	}

	void start_accept()
	{
		session_ptr new_session(new ZLSession(io_service_, room_));
		acceptor_.async_accept(new_session->socket(),
			boost::bind(&ZLTcpServer::handle_accept, this, new_session,
				boost::asio::placeholders::error));//监听客户端的到来，一旦有客户连接则立马执行下面的代码；
	}

	void handle_accept(session_ptr session,
		const boost::system::error_code& error)
	{
		if (!error)
		{
			session->start();
		}

		start_accept(); // 继续监听客户端连接请求 每连接上一个socket都会调用 
	}

private:
	boost::asio::io_service& io_service_;
	tcp::acceptor acceptor_;
	ZLRoom room_; //ZLRoom中没有重载构造函数 所以会直接调用默认构造函数
};

typedef boost::shared_ptr<ZLTcpServer> tcp_server_ptr;
typedef std::list<tcp_server_ptr> tcp_server_list;

//----------------------------------------------------------------------
//异步启动Tcp服务器
void startAsyncTcpServer(std::string port);
//同步启动Tcp服务器
void startSyncServer(std::string port);


