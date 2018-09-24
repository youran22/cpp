#include "socket_client.h"


CJPSocketClient::CJPSocketClient(boost::asio::io_service& io_service,
								tcp::resolver::iterator endpoint_iterator)
								: io_service_(io_service),
								socket_(io_service) //使得成员函数能直接使用这些变量
{
	
}

//public:
void CJPSocketClient::write(const DataPacket& msg)
{
	io_service_.post(boost::bind(&CJPSocketClient::do_write, this, msg)); //将消息主动投递给io_service
}

void CJPSocketClient::close()
{
	io_service_.post(boost::bind(&CJPSocketClient::do_close, this)); //这个close函数是客户端要主动终止时调用  do_close函数是从服务器端
	//读数据失败时调用
}

//异步运行Tcp客户端
void CJPSocketClient::asyncRun()
{
	try
	{
		io_service_.reset();
		t = boost::thread(boost::bind(&boost::asio::io_service::run, &io_service_));
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
}

//同步运行Tcp客户端
void CJPSocketClient::syncRun() {
	io_service_.reset();
	io_service_.run();
}

void CJPSocketClient::start_connect(tcp::resolver::iterator endpoint_iterator)
{
		boost::asio::async_connect(socket_, endpoint_iterator,
		boost::bind(&CJPSocketClient::handle_connect, this,
		boost::asio::placeholders::error)); //所有的操作都采用异步的方式
}

//private
void CJPSocketClient::handle_connect(const boost::system::error_code& error)
{
	if (!error)
	{
		//boost::asio::async_read(socket_,
		//	boost::asio::buffer(read_msg_.data(), DataPacket::header_length), //读取数据报头
		//	boost::bind(&CJPSocketClient::handle_read_header, this,
		//	boost::asio::placeholders::error));

		boost::asio::async_read(socket_,
			boost::asio::buffer(read_msg_.data(), DataPacket::header_length), //读取数据报头
			boost::bind(&CJPSocketClient::HandleReadStatusLine, this,
			boost::asio::placeholders::error));
	}
}

//void CJPSocketClient::handle_read_header(const boost::system::error_code& error)
//{
//	if (!error && read_msg_.decode_header()) //分别处理数据报头和数据部分
//	{
//		boost::asio::async_read(socket_,
//			boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),//读取数据包数据部分
//			boost::bind(&CJPSocketClient::handle_read_body, this,
//			boost::asio::placeholders::error));
//	}
//	else
//	{
//		std::cout << "关闭连接\r\n";
//		do_close();
//	}
//}
//
//void CJPSocketClient::handle_read_body(const boost::system::error_code& error)
//{
//	if (!error)
//	{
//		std::cout.write(read_msg_.body(), read_msg_.body_length()); //输出消息
//		std::cout << "\n";
//		boost::asio::async_read(socket_,
//			boost::asio::buffer(read_msg_.data(), DataPacket::header_length), //在这里读取下一个数据包头
//			boost::bind(&CJPSocketClient::handle_read_header, this,
//			boost::asio::placeholders::error)); //完成一次读操作（处理完一个数据包）  进行下一次读操作
//	}
//	else
//	{
//		do_close();
//	}
//}

//处理服务器回应的数据完整状态行数据。
void CJPSocketClient::HandleReadStatusLine(const boost::system::error_code& err)
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

void CJPSocketClient::do_write(DataPacket msg)
{
	bool write_in_progress = !write_msgs_.empty(); //空的话变量为false
	write_msgs_.push_back(msg); //把要写的数据push至写队列
	if (!write_in_progress)//队列初始为空 push一个msg后就有一个元素了
	{
		boost::asio::async_write(socket_,
			boost::asio::buffer(write_msgs_.front().data(),
			write_msgs_.front().length()),
			boost::bind(&CJPSocketClient::handle_write, this,
			boost::asio::placeholders::error));
	}
}

void CJPSocketClient::handle_write(const boost::system::error_code& error)//第一个消息单独处理，剩下的才更好操作
{
	if (!error)
	{
		write_msgs_.pop_front();//刚才处理完一个数据 所以要pop一个
		if (!write_msgs_.empty())
		{
			boost::asio::async_write(socket_,
				boost::asio::buffer(write_msgs_.front().data(),
				write_msgs_.front().length()),
				boost::bind(&CJPSocketClient::handle_write, this,
				boost::asio::placeholders::error)); //循环处理剩余的消息
		}
	}
	else
	{
		do_close();
	}
}

void CJPSocketClient::do_close()
{
	socket_.close();
}

//启动Tcp客户端
void startTcpClient(std::string ip, std::string port)
{
	boost::asio::io_service io_service;//所有socket操作都由service来处理

	tcp::resolver resolver(io_service);//tcp::resolver一般和tcp::resolver::query结合用，通过query这个词顾名思义就知道它是用来查询socket的相应信息，一般而言我们关心socket的东东有address，port而已，通过tcp::resolver很容易实现设置和查询
	tcp::resolver::query query(ip, port); //输入ip（或域名）和端口号
	tcp::resolver::iterator iterator = resolver.resolve(query);
	CJPSocketClient c(io_service, iterator);// all the socket operations are handled by service
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

void socket_connect()
{
	// 所有asio类都需要io_service对象
	boost::asio::io_service iosev;
	// socket对象
	boost::asio::ip::tcp::socket socket(iosev);
	// 连接端点，这里使用了本机连接，可以修改IP地址测试远程连接
	boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::from_string("116.62.152.162"), 6060);
	// 连接服务器
	boost::system::error_code ec;
	socket.connect(ep,ec);
	// 如果出错，打印出错信息
	if(ec)
	{
		std::cout << boost::system::system_error(ec).what() << std::endl;
		return ;
	}
	// 接收数据
	char buf[100];
	size_t len=socket.read_some(boost::asio::buffer(buf), ec);
	std::cout << buf;
	std::cout.write(buf, len);
}

void Test_socket(void)
{
	//
	const std::string strHost("www.boost.org");
	const std::string strHttp("http");

	//定义IO服务对象。
	boost::asio::io_service ioService;
	CClient client(strHost,strHttp, ioService);
	ioService.run();
}