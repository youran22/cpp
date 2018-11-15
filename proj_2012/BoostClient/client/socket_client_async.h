
#ifndef socket_client_async_H_419959BA_BAAA_4830_B4B4_A56D2DB7ED47
#define socket_client_async_H_419959BA_BAAA_4830_B4B4_A56D2DB7ED47
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/thread/thread.hpp>

#include "ISerialDataCallBack.h"

//using namespace std; 
using boost::asio::io_service;   
using boost::asio::ip::tcp;

#define _RECV_BUF_SIZE_   8192

class socket_client_async  
{   
public:   
	socket_client_async ();
	socket_client_async (const std::string & hostname, unsigned short port);
	virtual ~socket_client_async();   

	// methods   
	virtual void send(const std::string & message);
	virtual void send(const char* data,int len);


	bool connect(const std::string & hostname, unsigned short port);
	bool isConnect();
	//异步运行Tcp客户端
	void asyncRun();
	//event call
	virtual bool OnConnect(const boost::system::error_code& error);
	virtual bool OnRecv (const boost::system::error_code& error,size_t bytes_transferred);
	virtual bool OnSend(const boost::system::error_code& error,size_t bytes_transferred);
	virtual void OnClose (const boost::system::error_code& error); 

	void setDataCallback(ISerialDataCallBack*  pcallback){_pdata_callback = pcallback;};

	void close();

private: 
	boost::thread  thrd;
	io_service* m_io_service;
	tcp::socket * m_socket; 
	char          m_data[_RECV_BUF_SIZE_];
	bool          _isConnected;

	ISerialDataCallBack*  _pdata_callback;

	std::string  _hostname;
	int          _server_port;
};   


#endif
