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
	boost::asio::io_service m_io;//����socket��,��������ip���˿ڣ�
	boost::asio::ip::tcp::endpoint m_ep;//��װip���˿��ã���socket���ӵ�ʱ����ã�
	enum { max_length = 1024 };
	char m_buf[max_length];
};

/*
io_service���������������Ҫ���ࣻ������Ͳ���ϵͳ�򽻵����ȴ������첽�����Ľ�����Ȼ��Ϊÿһ���첽������������ɴ������
*/