#include "ZLTcpClient.h"
//����Tcp�ͻ���
void startTcpClient(std::string ip, std::string port)
{
	boost::asio::io_service io_service;

	tcp::resolver resolver(io_service);
	tcp::resolver::query query(ip, port); //����ip�����������Ͷ˿ں�
	tcp::resolver::iterator iterator = resolver.resolve(query);
	ZLTcpClient c(io_service, iterator);
	io_service.run();
	return;
}

void startAsyncTcpClient(std::string ip, std::string port)
{
	boost::thread t1(boost::bind(&startTcpClient, ip,port));//����һ����֧�̣߳��ص���myThread������	
}

void startSyncClient(std::string ip, std::string port)
{
	startTcpClient(ip,port);
}
