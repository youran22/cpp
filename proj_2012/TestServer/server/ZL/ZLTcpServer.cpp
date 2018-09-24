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

//�첽����Tcp������
void startAsyncTcpServer(std::string port) {
	boost::thread t1(boost::bind(&startZLTcpServer, port));//����һ����֧�̣߳��ص���myThread������	
}

//ͬ������Tcp������
void startSyncServer(std::string port) {
	startZLTcpServer(port);
}
