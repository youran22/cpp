#pragma once
#include <tchar.h>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/array.hpp>

void test_boost_server1();

//封装一个服务端类来处理网络。
//
class CConnect : 
	public boost::enable_shared_from_this< CConnect >
{
	static const int MAX_BUFSIZE = 1024;
public:
	CConnect(boost::asio::io_service& ioService)
		:m_Socket(ioService),
		m_strHit("\r\nResp: ")
	{
	}

	boost::asio::ip::tcp::socket& GetSocket(void)
	{
		return m_Socket;
	}

	void Start(void)
	{
		m_Socket.async_read_some(boost::asio::buffer(m_chBuffer, MAX_BUFSIZE),
			boost::bind(&CConnect::HandleRead, shared_from_this(),
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
	}

	void HandleRead(const boost::system::error_code& error,
		size_t bytes_transferred)
	{
		if (!error)
		{
			boost::asio::async_write(m_Socket,
				boost::asio::buffer(m_strHit),
				boost::bind(&CConnect::HandleWrite, shared_from_this(),
				boost::asio::placeholders::error));
			boost::asio::async_write(m_Socket,
				boost::asio::buffer(m_chBuffer, bytes_transferred),
				boost::bind(&CConnect::HandleWrite, shared_from_this(),
				boost::asio::placeholders::error));
		}
	}

	void HandleWrite(const boost::system::error_code& error)
	{
		if (!error)
		{
			m_Socket.async_read_some(boost::asio::buffer(m_chBuffer, MAX_BUFSIZE),
				boost::bind(&CConnect::HandleRead, shared_from_this(),
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
		}
	}
private:
	//
	boost::asio::ip::tcp::socket m_Socket;

	//
	boost::array<char, MAX_BUFSIZE> m_chBuffer;
	std::string m_strHit;
};

class CServer
{
public:
	//构造函数，主要提供IO服务和端口。
	CServer(boost::asio::io_service& ioService, short sPort)
		:m_ioService(ioService), 
		m_acceptor(ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), sPort))
	{
		//创建一个新连接，用来接收连接进来的客户端表示。
		boost::shared_ptr< CConnect > pConnect(new CConnect(m_ioService));
		//做连接准备。
		m_acceptor.async_accept(pConnect->GetSocket(),
			boost::bind(&CServer::HandleAccept, this, pConnect,
			boost::asio::placeholders::error));	
	}

	//收到客户端连接进来事件响应。
	void HandleAccept(boost::shared_ptr< CConnect > pNewConnect,
		const boost::system::error_code& error)
	{
		if (!error)
		{
			//如果没有错误，对连接进来的连接收发数据。
			pNewConnect->Start();

			//创建新的连接，以备下一个客户端连接进来。
			pNewConnect.reset(new CConnect(m_ioService));
			//做连接准备。
			m_acceptor.async_accept(pNewConnect->GetSocket(),
				boost::bind(&CServer::HandleAccept, this, pNewConnect,
				boost::asio::placeholders::error));
		}
	}

private:
	//IO服务
	boost::asio::io_service& m_ioService;
	//接收器，用来接收新连接进来。
	boost::asio::ip::tcp::acceptor m_acceptor;
};

