#pragma once
#include <cstdlib>
#include <deque>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
using namespace boost::asio;



class Client
{
	typedef boost::asio::ip::tcp::socket socket_type;
	typedef std::shared_ptr<socket_type> sock_ptr;
public:
	Client();
	void run();
private:
	void start();
	void connect_handler(const boost::system::error_code& ec, sock_ptr sock);
	void read_handler(const boost::system::error_code& ec);
private:
	boost::asio::io_service m_io;//建立socket用,用来连接ip、端口；
	boost::asio::ip::tcp::endpoint m_ep;//封装ip、端口用；给socket连接的时候调用；
	enum { max_length = 1024 };
	char m_buf[max_length];
};

/*
io_service是这个库里面最重要的类；它负责和操作系统打交道，等待所有异步操作的结束，然后为每一个异步操作调用其完成处理程序。
*/