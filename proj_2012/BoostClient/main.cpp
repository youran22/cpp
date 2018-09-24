#include <tchar.h>
#include <string>
#include <iostream>
#include "client.h"
#include "JPSocketClient.h"
#include "main.h"



int _tmain(int argc, _TCHAR* argv[]) 
{
	//Test_CJPSocketClient();

	Test_Client();
	//Test_Simple0();

	//startAsyncTcpClient("127.0.0.1", "9001");
	//startSyncClient("127.0.0.1", "9001");

	while(1);
	return 0;
}


void Test_Simple0()
{
	try
	{
		boost::asio::io_service io;
		boost::asio::ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 45453);
		boost::asio::ip::tcp::socket sock(io);//通过io创建socket；

		sock.connect(ep);//socket通过endpoint封装的ip和端口连接；

		char str[1024];
		sock.read_some(buffer(str));//通过socket读取；
		std::cout << "receive from" << sock.remote_endpoint().address() << std::endl;;
		std::cout << str << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	getchar();
}
void Test_Client()
{
	try
	{
		std::cout << "client start." << std::endl;
		Client cl;
		cl.run();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
void Test_CJPSocketClient()
{
	CJPSocketClient Sock("", 6060);
	//Sock.strarConnect();
	Sock.run();
}