#include "JPSocketClient.h"


CJPSocketClient::CJPSocketClient(std::string ip, int port)
	: m_ep(ip::address::from_string("127.0.0.1"), 45453)
	, m_socket(new socket_type(m_io))
{
	memset(m_buf, 0, sizeof(m_buf));
	strarConnect();
}


CJPSocketClient::~CJPSocketClient(void)
{
}

void CJPSocketClient::strarConnect()
{
	m_socket->async_connect(m_ep, std::bind(&CJPSocketClient::connectHandle, this, std::placeholders::_1));
}

void CJPSocketClient::run()
{
	m_io.run();
}

void CJPSocketClient::connectHandle(const boost::system::error_code& error)
{
	if(!error)
	{
		cout << "连接成功!" <<endl;
		//发送数据
		//m_socket->async_write_some(buffer("GET / HTTP/1.1 Host: 116.62.152.162:6060	User-Agent: NTRIP 1.00.180626.DecoderGNSS.G9928712002432302 Accept: */*"),
		//	std::bind(&CJPSocketClient::firstSendHandle, this, std::placeholders::_1));

		memset(m_buf, 0, sizeof(m_buf));
		m_socket->async_read_some(buffer(m_buf),std::bind(&CJPSocketClient::parseList, this, std::placeholders::_1));
	}
}

void CJPSocketClient::firstSendHandle(const boost::system::error_code& error)
{
	if(!error)
	{
		memset(m_buf, 0, sizeof(m_buf));
		m_socket->async_read_some(buffer(m_buf),std::bind(&CJPSocketClient::parseList, this, std::placeholders::_1));
		//m_socket->async_connect(m_ep, std::bind(&CJPSocketClient::connectHandle, this, std::placeholders::_1));
		//boost::asio::async_read(*m_socket,
		//	boost::asio::buffer(m_buf),//读取数据包数据部分
		//	boost::bind(&CJPSocketClient::parseList, this,
		//	boost::asio::placeholders::error));
	}
}

void CJPSocketClient::parseList(const boost::system::error_code& error)
{
	if(!error)
	{
		cout << m_buf <<endl;
	}
}
