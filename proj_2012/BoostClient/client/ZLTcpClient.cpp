#include "ZLTcpClient.h"
//启动Tcp客户端
void startTcpClient(std::string ip, std::string port)
{
	boost::asio::io_service io_service;

	tcp::resolver resolver(io_service);
	tcp::resolver::query query(ip, port); //输入ip（或域名）和端口号
	tcp::resolver::iterator iterator = resolver.resolve(query);
	ZLTcpClient c(io_service, iterator);
	io_service.run();
	return;
}

void startAsyncTcpClient(std::string ip, std::string port)
{
	boost::thread t1(boost::bind(&startTcpClient, ip,port));//创建一个分支线程，回调到myThread函数里	
}

void startSyncClient(std::string ip, std::string port)
{
	startTcpClient(ip,port);
}
