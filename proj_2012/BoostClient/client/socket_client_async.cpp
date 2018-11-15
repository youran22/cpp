#include "socket_client_async.h"
#include "../common/SimpleLog.h"

socket_client_async::socket_client_async ()   
{   
	_pdata_callback = nullptr;
	_isConnected = false;
} 
socket_client_async::socket_client_async (const std::string & hostname, unsigned short port)   
{  
	connect(hostname,port);
}   

socket_client_async::~socket_client_async()   
{  
	m_io_service->reset();
	m_io_service->stop();
	m_socket->shutdown(tcp::socket::shutdown_both);
	close();
	delete m_socket;   
	delete m_io_service;
	_pdata_callback = nullptr;
	_isConnected = false;
}  
bool socket_client_async::connect(const std::string & hostname, unsigned short port)
{
	_hostname = hostname;
	_server_port = port;

	_isConnected = false;
	m_io_service = new io_service();
	m_socket     = new tcp::socket(*m_io_service);

	tcp::resolver        resolver(*m_io_service);     
	boost::system::error_code ec;   
	tcp::resolver::query query(hostname, boost::lexical_cast<std::string, unsigned short>(port));   
	tcp::resolver::iterator iter = resolver.resolve(query, ec);   
	tcp::resolver::iterator end;

	// pick the first endpoint   
	if (iter != end && ec == 0)   
	{   
		tcp::endpoint endpoint = *iter;   

		std::cout << "Connecting to: " << endpoint << std::endl;   

		//同步连接打开
		m_socket->connect(endpoint, ec); 
		if (ec)   
		{   
			//std::cerr << "Error: " << ec << std::endl;   
			//throw ec;
			return false;
		}
		else
		{
			memset(m_data,0,sizeof(m_data));
			m_socket->async_read_some(boost::asio::buffer(m_data,_RECV_BUF_SIZE_),
				boost::bind(&socket_client_async::OnRecv,this,
				boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
			
			_isConnected = true;

			//m_io_service->run();
			asyncRun();
			return true;
		}
		//m_socket->async_connect(endpoint, boost::bind(&CClientASIO::OnConnect, this, boost::asio::placeholders::error));
		//m_io_service->run();
	}

	return true;
}
bool socket_client_async::isConnect()
{
	return _isConnected;
}

void socket_client_async::send(const std::string & message) 
{
	if (_isConnected)
	{
		m_socket->async_write_some(boost::asio::buffer(message.c_str(),message.size()),
			boost::bind(&socket_client_async::OnSend,this,
			boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
	}

}
void socket_client_async::send(const char* data,int len) 
{   
	if (_isConnected)
	{
		m_socket->async_write_some(boost::asio::buffer(data,len),
			boost::bind(&socket_client_async::OnSend,this,
			boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
	}
}

bool socket_client_async::OnConnect(const boost::system::error_code& error)
{
	std::cout<<"OnConnect"<<std::endl;
	if(!error)
	{
		memset(m_data,0,sizeof(m_data));
		m_socket->async_read_some(boost::asio::buffer(m_data,_RECV_BUF_SIZE_),
			boost::bind(&socket_client_async::OnRecv,this,
			boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
		_isConnected = true;
	}
	else
	{
		OnClose(error);
		return false;
	}
	return true;
}
bool socket_client_async::OnRecv(const boost::system::error_code& error,size_t bytes_transferred)
{
	//std::cout<<"OnRecv Bytes:"<<bytes_transferred<<std::endl;
	//char log_buffer[256]={0};
	//sprintf(log_buffer, "socket_client_async::OnRecv %d", 0);
	//SimpleLog::getInstance()->save_log(LOG_TYPE_DEBUG, log_buffer);
	if(!error)
	{
		//std::string strRecv = (char *)m_data;
		//std::cout<<strRecv<<std::endl;  
		if(_pdata_callback)
				_pdata_callback->on_serial_data((const unsigned char*)m_data,bytes_transferred);

		memset(m_data,0,sizeof(m_data));
		m_socket->async_read_some(boost::asio::buffer(m_data,_RECV_BUF_SIZE_),
			boost::bind(&socket_client_async::OnRecv,this,
			boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
	}
	else
	{
		OnClose(error);
		return false;
	}
	_isConnected = true;
	return true;
}

bool socket_client_async::OnSend(const boost::system::error_code& error,size_t bytes_transferred)
{
	//std::cout<<"OnSend Bytes:"<<bytes_transferred<<std::endl;
	if(error)
	{
		OnClose(error);
		return false;
	}
	_isConnected = true;
	return true;
}

void socket_client_async::OnClose(const boost::system::error_code& error)
{
	std::cout<<"OnClose"<<std::endl;

	m_socket->close(); 
	_isConnected = false;

	connect(_hostname,_server_port);
} 

//异步运行Tcp客户端
void socket_client_async::asyncRun()
{
	try
	{
		m_io_service->reset();
		thrd = boost::thread(boost::bind(&boost::asio::io_service::run, m_io_service));
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
}

void socket_client_async::close()
{
	m_socket->close();
}


/*
int main(int argc, char* argv[])
{
//CClientASIO c("127.0.0.1", 50020);  
//std::string strMsg="Hello,World!";
//c.send(strMsg);

//c.start();
//io_service_.run();

CClientASIO client;
client.connect("127.0.0.1", 50020);
return 0;
}
*/