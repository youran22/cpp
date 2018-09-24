#include "ZLTcpServer.h"
#include "boost/thread.hpp"

void startZLTcpServer(std::string port)
{
	try
	{
		boost::asio::io_service io_service;
		using namespace std; // For atoi.
		tcp::endpoint endpoint(tcp::v4(), std::atoi(port.c_str()));
		tcp_server_ptr server(new ZLTcpServer(io_service, endpoint));
		server->start_accept();
		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return;
}

//异步启动Tcp服务器
void startAsyncTcpServer(std::string port) {
	boost::thread t1(boost::bind(&startZLTcpServer, port));//创建一个分支线程，回调到myThread函数里	
}

//同步启动Tcp服务器
void startSyncServer(std::string port) {
	startZLTcpServer(port);
}
