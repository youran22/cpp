#include <tchar.h>
#include <string>
#include <iostream>
#include "client.h"
#include "JPSocketClient.h"
#include "main.h"

int _tmain(int argc, _TCHAR* argv[]) 
{
	//test_client_socket();
	test_client_socket_2();

	//thread_2();

	//time_print_class();
	//time_print_class_third();
	//time_print_class_four();
	//time_print_class_five();
	//time_print_class_six();

	//base64_test();

	//test_config_all();
	//test_protojson();

	//UseScoket useSocket;
	//std::string str = "send data";
	//useSocket.post_message((const unsigned char* )str.c_str(), str.length());
	//TestServer();
	//Test_CJPSocketClient();

	//Test_Client();
	//Test_Simple0();

	//startAsyncTcpClient("127.0.0.1", "9001");
	//startSyncClient("127.0.0.1", "9001");

	while(1);
	return 0;
}

void TestServer()
{


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

#include "client/socket_client_async.h"
void test_client_socket()
{
	//socket_client_async client;
	//client.connect("172.16.92.118",65432);

	socket_client_async *client = new socket_client_async();
	client->connect("172.16.92.118",65432);
	delete client;
	while(1);
}
#include "client/xj/Module_Socket_Connection.h"
void test_client_socket_2()
{
	//OPLibrary::CModuleSocketConnection client;
	//if (client.is_connect())
	//{
	//	client.close();
	//}
	////client.set_event_delegate(static_cast<OPLibrary::IModuleSocketConnectionDelegate*>(this));
	////bool bok = client.sync_connect("172.16.92.118",65432);

	//client.asyn_connect("172.16.92.118",65432);

	//std::string str="abcd";
	//while(1)
	//{
	//	client.continue_send_data() ;
	//	client.send_data((const unsigned char *)str.c_str(), str.length());
	//	Sleep(1000);
	//}

	OPLibrary::CModuleSocketConnection *client = new OPLibrary::CModuleSocketConnection;
	client->asyn_connect("172.16.92.118",65432);
	std::string str="abcd";
	client->continue_send_data();
	client->send_data((const unsigned char *)str.c_str(), str.length());
	delete client;

	while(1);
}
void Test_CJPSocketClient()
{
	CJPSocketClient Sock("", 6060);
	//Sock.strarConnect();
	Sock.run();
}