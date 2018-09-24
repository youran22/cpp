//服务器，主要接收新连接，并启动新连接接收数据。
#include "server.h"
#include "server/ZL/ZLTcpServer.h"
using namespace boost::asio;
//
class Server
{
	typedef ip::tcp::socket socket_type;
	typedef std::shared_ptr<socket_type> sock_ptr;

public:

	Server() :m_acceptor(m_io, ip::tcp::endpoint(ip::tcp::v4(), 45453))
	{
		accept();
	}

	void run()
	{
		m_io.run();
	}
private:

	void accept()
	{
		sock_ptr sock(new socket_type(m_io));//创建一个socket
		m_acceptor.async_accept(*sock,
			std::bind(&Server::accept_handler, this, std::placeholders::_1, sock));//异步连接
	}

	void accept_handler(const boost::system::error_code& ec, sock_ptr sock)
	{
		if (ec)
		{return;}
		std::cout << "client:";
		std::cout << sock->remote_endpoint().address() << std::endl;

		sock->async_write_some(buffer("hello asio"),
				std::bind(&Server::write_handler, this, std::placeholders::_1));

		accept();
	}

	void write_handler(const boost::system::error_code&)
	{
		std::cout << "send msg complete." << std::endl;
	}
private:
	io_service m_io;
	ip::tcp::acceptor m_acceptor;
};
int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		std::cout << "server" << std::endl;
		Server svr;
		svr.run();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	//try
	//{
	//	boost::asio::io_service io;
	//	ip::tcp::endpoint ep(ip::tcp::v4(), 45453);
	//	ip::tcp::acceptor acceptor(io, ep);
	//	while (1)
	//	{
	//		ip::tcp::socket sock(io);
	//		acceptor.accept(sock);
	//		std::cout << "client:" << sock.remote_endpoint().address() << std::endl;
	//		sock.write_some(buffer("hello asio"));
	//	}
	//}
	//catch (std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}


	//startAsyncTcpServer("9001");
	//startSyncServer("9001");


	while(1);
	return 0;
}

void test_boost_server1()
{
	//创建一个IO服务
	boost::asio::io_service ioService;	
	//创建服务器，端口为9001。
	CServer server(ioService, 9001);

	//响应IO服务
	ioService.run();
	while(1);
}