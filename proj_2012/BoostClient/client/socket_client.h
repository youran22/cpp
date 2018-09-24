#pragma once
#include <cstdlib>
#include <deque>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include "DataPacket.h"

using boost::asio::ip::tcp;

typedef std::deque<DataPacket> packet_queue;

class CJPSocketClient
{
public:
	CJPSocketClient(boost::asio::io_service& io_service,
		tcp::resolver::iterator endpoint_iterator);

	void write(const DataPacket& msg);
	void close();
	//异步运行Tcp客户端
	void asyncRun();
	//同步运行Tcp客户端
	void syncRun();
public:
	void start_connect(tcp::resolver::iterator endpoint_iterator);
private:

	void handle_connect(const boost::system::error_code& error);

	//void handle_read_header(const boost::system::error_code& error);
	//void handle_read_body(const boost::system::error_code& error);
	//处理服务器回应的数据完整状态行数据。
	void HandleReadStatusLine(const boost::system::error_code& err);

	void do_write(DataPacket msg);

	void handle_write(const boost::system::error_code& error);//第一个消息单独处理，剩下的才更好操作;

	void do_close();

private:
	boost::thread t;
	boost::asio::io_service& io_service_;
	tcp::socket socket_;
	DataPacket read_msg_;
	packet_queue write_msgs_;
	boost::asio::streambuf m_response; //接收数据缓冲区。
};

//----------------------------------------------------------------------
//启动Tcp客户端
//async ture:异步启动  false:同步启动
//----------------------------------------------------------------------
//异步启动Tcp客户端
void startAsyncTcpClient(std::string ip, std::string port);
//同步启动Tcp客户端
void startSyncClient(std::string ip, std::string port);

void socket_connect();

//#include <boost/asio/ip/tcp.hpp>
//#include <boost/asio.hpp>
//#include <boost/bind.hpp>
//#include <iostream>
//#include <string>
 
//封装一个客户端类来处理异常网络处理。
//
class CClient
{
public:
	CClient(const std::string& strHost, const std::string& strService, 
		boost::asio::io_service& ioService)
		:m_resolver(ioService), m_socket(ioService)
	{		
		//构造HTTP请求发送给服务器.
		std::ostream requestPacket(&m_request);
		requestPacket << "GET " << "http://www.boost.org/" << " HTTP/1.0\r\n";//http://www.boost.org
		requestPacket << "Host: " << "www.boost.org" << "\r\n";
		requestPacket << "Accept: */*\r\n";
		requestPacket << "Connection: close\r\n\r\n";
 
		//发送解释域名请求。
		boost::asio::ip::tcp::resolver::query query(strHost, strService);
		m_resolver.async_resolve(query,
			boost::bind(&CClient::HandleResolve, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::iterator));
	}
 
private:
	//域名解释回应。
	void HandleResolve(const boost::system::error_code& err,
		boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
	{
		if (!err)
		{			
			//准备连接解释后的IP地址， 以便连接到服务器。
			boost::asio::ip::tcp::endpoint endpoint= *endpoint_iterator;
			m_socket.async_connect(endpoint,
				boost::bind(&CClient::HandleConnect, this,
				boost::asio::placeholders::error, ++endpoint_iterator));
		}
		else
		{
			std::cout << "Error: " << err.message() << "\n";
		}
	}
 
	//连接到服务器成功或者失败。
	void HandleConnect(const boost::system::error_code& err,
		boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
	{
		if (!err)
		{
			//连接到服务器成功，接着发送请求数据给服务器。
			boost::asio::async_write(m_socket, m_request,
				boost::bind(&CClient::HandleWriteRequest, this,
				boost::asio::placeholders::error));
		}
		else if (endpoint_iterator != boost::asio::ip::tcp::resolver::iterator())
		{
			//连接服务器失败，继续连接下一个服务器的端点。
			m_socket.close();
			boost::asio::ip::tcp::endpoint endpoint = *endpoint_iterator;
			m_socket.async_connect(endpoint,
				boost::bind(&CClient::HandleConnect, this,
				boost::asio::placeholders::error, ++endpoint_iterator));
		}
		else
		{
			std::cout << "Error: " << err.message() << "\n";
		}
	}
 
	//当发送请求数据给服务器之后处理。
	void HandleWriteRequest(const boost::system::error_code& err)
	{
		if (!err)
		{
			//发送给服务器成功之后，就可以读取服务器回应的数据。
			boost::asio::async_read_until(m_socket, m_response, "\r\n",
				boost::bind(&CClient::HandleReadStatusLine, this,
				boost::asio::placeholders::error));
		}
		else
		{
			std::cout << "Error: " << err.message() << "\n";
		}
	}
 
	//处理服务器回应的数据完整状态行数据。
	void HandleReadStatusLine(const boost::system::error_code& err)
	{
		if (!err)
		{
			//分析回应的数据。
			std::istream responsePacket(&m_response);
			std::string strhttpVersion;
			responsePacket >> strhttpVersion;
			unsigned int iStatusCode;
			responsePacket >> iStatusCode;
 
			std::string strStatusMessage;	
			std::getline(responsePacket, strStatusMessage);
 
			//输出解释出来的数据。
			std::cout << "response: " << strhttpVersion << " "
				<< iStatusCode << " "
				<< strStatusMessage << std::endl;				
		}
		else
		{
			std::cout << "Error: " << err << "\n";
		}
	}
	
private:	
	boost::asio::ip::tcp::resolver m_resolver; //解释域名
	boost::asio::ip::tcp::socket m_socket; //收发数据SOCKET。
	boost::asio::streambuf m_request; //发送数据缓冲区。
	boost::asio::streambuf m_response; //接收数据缓冲区。
};
 
//测试网络服务异步处理。
void Test_socket(void);


