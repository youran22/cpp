#pragma once
#include <cstdlib>
#include <deque>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
using namespace std;
using namespace boost::asio;

class CJPSocketClient
{
	typedef ip::tcp::socket socket_type;
	typedef std::shared_ptr<socket_type> sock_ptr;
public:
	CJPSocketClient(std::string ip, int port);
	~CJPSocketClient(void);
public:
	void strarConnect();
	void run();
private:
	void connectHandle(const boost::system::error_code& ec);
	void firstSendHandle(const boost::system::error_code& ec);
	void parseList(const boost::system::error_code& ec);
private:
	io_service m_io;
	ip::tcp::endpoint m_ep;

	sock_ptr m_socket;

	enum { max_length = 1024 };
	char m_buf[max_length];
};

