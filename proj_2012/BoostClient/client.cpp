#include "client.h"

Client::Client() :m_ep(ip::address::from_string("116.62.152.162"), 6060)
{
		start();
}
void Client::run()
{
	m_io.run();
}

void Client::start()
{
	sock_ptr sock(new socket_type(m_io));//通过io，创建一个socket；
	sock->async_connect(m_ep, std::bind(&Client::connect_handler, this, std::placeholders::_1, sock));//异步连接
}
void Client::connect_handler(const boost::system::error_code& ec, sock_ptr sock)
{
	if (ec)
	{return;}
	std::cout << "receive from:" << sock->remote_endpoint().address() << std::endl;
	int i=0;

//		sock->async_write_some(buffer("GET / HTTP/1.1\r\n\
//Host: 116.62.152.162:6060\r\n\
//User-Agent: NTRIP XW\r\n\
//Accept: */*\r\n\
//Connection: keep-alive\r\n\r\n"),std::bind(&Client::read_handler, this, std::placeholders::_1));

//ok
//	GET /KOC_9931 HTTP/1.1
//	Host: 116.62.152.162:6060
//	User-Agent:NTRIP 1.00.180626.DecoderGNSS.G9928712002432302
//	Accept: */*
//Connection: close
//Authorization: Basic MDAwMDoxMjM0


		sock->async_write_some(buffer("GET /KOC_9931 HTTP/1.1\r\n\
User-Agent: NTRIP EGSTAR\r\n\
Accept: */*\r\n\
Connection: close\r\n\
Authorization: Basic MDAwMDoxMjM0\r\n\r\n"),std::bind(&Client::read_handler, this, std::placeholders::_1));

	memset(m_buf, 0, sizeof(m_buf));
	sock->async_read_some(buffer(m_buf),
		std::bind(&Client::read_handler, this, std::placeholders::_1));//async_read_some

	sock->async_write_some(buffer("$GPGGA,091643,2300.00000,N,11000.00000,E,1,09,1.0,0.00,M,0.0,M,0,*72"),std::bind(&Client::read_handler, this, std::placeholders::_1));

	memset(m_buf, 0, sizeof(m_buf));
	sock->async_read_some(buffer(m_buf),
		std::bind(&Client::read_handler, this, std::placeholders::_1));

}
void Client::read_handler(const boost::system::error_code& ec)
{
	if (ec)
	{return;}
	//sock->async_read_some(buffer(m_buf),
	//	std::bind(&Client::read_handler, this, std::placeholders::_1, sock));//async_read_some
	std::cout << m_buf << std::endl;
}