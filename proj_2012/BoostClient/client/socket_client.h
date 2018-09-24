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
	//�첽����Tcp�ͻ���
	void asyncRun();
	//ͬ������Tcp�ͻ���
	void syncRun();
public:
	void start_connect(tcp::resolver::iterator endpoint_iterator);
private:

	void handle_connect(const boost::system::error_code& error);

	//void handle_read_header(const boost::system::error_code& error);
	//void handle_read_body(const boost::system::error_code& error);
	//�����������Ӧ����������״̬�����ݡ�
	void HandleReadStatusLine(const boost::system::error_code& err);

	void do_write(DataPacket msg);

	void handle_write(const boost::system::error_code& error);//��һ����Ϣ��������ʣ�µĲŸ��ò���;

	void do_close();

private:
	boost::thread t;
	boost::asio::io_service& io_service_;
	tcp::socket socket_;
	DataPacket read_msg_;
	packet_queue write_msgs_;
	boost::asio::streambuf m_response; //�������ݻ�������
};

//----------------------------------------------------------------------
//����Tcp�ͻ���
//async ture:�첽����  false:ͬ������
//----------------------------------------------------------------------
//�첽����Tcp�ͻ���
void startAsyncTcpClient(std::string ip, std::string port);
//ͬ������Tcp�ͻ���
void startSyncClient(std::string ip, std::string port);

void socket_connect();

//#include <boost/asio/ip/tcp.hpp>
//#include <boost/asio.hpp>
//#include <boost/bind.hpp>
//#include <iostream>
//#include <string>
 
//��װһ���ͻ������������쳣���紦��
//
class CClient
{
public:
	CClient(const std::string& strHost, const std::string& strService, 
		boost::asio::io_service& ioService)
		:m_resolver(ioService), m_socket(ioService)
	{		
		//����HTTP�����͸�������.
		std::ostream requestPacket(&m_request);
		requestPacket << "GET " << "http://www.boost.org/" << " HTTP/1.0\r\n";//http://www.boost.org
		requestPacket << "Host: " << "www.boost.org" << "\r\n";
		requestPacket << "Accept: */*\r\n";
		requestPacket << "Connection: close\r\n\r\n";
 
		//���ͽ�����������
		boost::asio::ip::tcp::resolver::query query(strHost, strService);
		m_resolver.async_resolve(query,
			boost::bind(&CClient::HandleResolve, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::iterator));
	}
 
private:
	//�������ͻ�Ӧ��
	void HandleResolve(const boost::system::error_code& err,
		boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
	{
		if (!err)
		{			
			//׼�����ӽ��ͺ��IP��ַ�� �Ա����ӵ���������
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
 
	//���ӵ��������ɹ�����ʧ�ܡ�
	void HandleConnect(const boost::system::error_code& err,
		boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
	{
		if (!err)
		{
			//���ӵ��������ɹ������ŷ����������ݸ���������
			boost::asio::async_write(m_socket, m_request,
				boost::bind(&CClient::HandleWriteRequest, this,
				boost::asio::placeholders::error));
		}
		else if (endpoint_iterator != boost::asio::ip::tcp::resolver::iterator())
		{
			//���ӷ�����ʧ�ܣ�����������һ���������Ķ˵㡣
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
 
	//�������������ݸ�������֮����
	void HandleWriteRequest(const boost::system::error_code& err)
	{
		if (!err)
		{
			//���͸��������ɹ�֮�󣬾Ϳ��Զ�ȡ��������Ӧ�����ݡ�
			boost::asio::async_read_until(m_socket, m_response, "\r\n",
				boost::bind(&CClient::HandleReadStatusLine, this,
				boost::asio::placeholders::error));
		}
		else
		{
			std::cout << "Error: " << err.message() << "\n";
		}
	}
 
	//�����������Ӧ����������״̬�����ݡ�
	void HandleReadStatusLine(const boost::system::error_code& err)
	{
		if (!err)
		{
			//������Ӧ�����ݡ�
			std::istream responsePacket(&m_response);
			std::string strhttpVersion;
			responsePacket >> strhttpVersion;
			unsigned int iStatusCode;
			responsePacket >> iStatusCode;
 
			std::string strStatusMessage;	
			std::getline(responsePacket, strStatusMessage);
 
			//������ͳ��������ݡ�
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
	boost::asio::ip::tcp::resolver m_resolver; //��������
	boost::asio::ip::tcp::socket m_socket; //�շ�����SOCKET��
	boost::asio::streambuf m_request; //�������ݻ�������
	boost::asio::streambuf m_response; //�������ݻ�������
};
 
//������������첽����
void Test_socket(void);


