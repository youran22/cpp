#include "socket_client.h"


CJPSocketClient::CJPSocketClient(boost::asio::io_service& io_service,
								tcp::resolver::iterator endpoint_iterator)
								: io_service_(io_service),
								socket_(io_service) //ʹ�ó�Ա������ֱ��ʹ����Щ����
{
	
}

//public:
void CJPSocketClient::write(const DataPacket& msg)
{
	io_service_.post(boost::bind(&CJPSocketClient::do_write, this, msg)); //����Ϣ����Ͷ�ݸ�io_service
}

void CJPSocketClient::close()
{
	io_service_.post(boost::bind(&CJPSocketClient::do_close, this)); //���close�����ǿͻ���Ҫ������ֹʱ����  do_close�����Ǵӷ�������
	//������ʧ��ʱ����
}

//�첽����Tcp�ͻ���
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

//ͬ������Tcp�ͻ���
void CJPSocketClient::syncRun() {
	io_service_.reset();
	io_service_.run();
}

void CJPSocketClient::start_connect(tcp::resolver::iterator endpoint_iterator)
{
		boost::asio::async_connect(socket_, endpoint_iterator,
		boost::bind(&CJPSocketClient::handle_connect, this,
		boost::asio::placeholders::error)); //���еĲ����������첽�ķ�ʽ
}

//private
void CJPSocketClient::handle_connect(const boost::system::error_code& error)
{
	if (!error)
	{
		//boost::asio::async_read(socket_,
		//	boost::asio::buffer(read_msg_.data(), DataPacket::header_length), //��ȡ���ݱ�ͷ
		//	boost::bind(&CJPSocketClient::handle_read_header, this,
		//	boost::asio::placeholders::error));

		boost::asio::async_read(socket_,
			boost::asio::buffer(read_msg_.data(), DataPacket::header_length), //��ȡ���ݱ�ͷ
			boost::bind(&CJPSocketClient::HandleReadStatusLine, this,
			boost::asio::placeholders::error));
	}
}

//void CJPSocketClient::handle_read_header(const boost::system::error_code& error)
//{
//	if (!error && read_msg_.decode_header()) //�ֱ������ݱ�ͷ�����ݲ���
//	{
//		boost::asio::async_read(socket_,
//			boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),//��ȡ���ݰ����ݲ���
//			boost::bind(&CJPSocketClient::handle_read_body, this,
//			boost::asio::placeholders::error));
//	}
//	else
//	{
//		std::cout << "�ر�����\r\n";
//		do_close();
//	}
//}
//
//void CJPSocketClient::handle_read_body(const boost::system::error_code& error)
//{
//	if (!error)
//	{
//		std::cout.write(read_msg_.body(), read_msg_.body_length()); //�����Ϣ
//		std::cout << "\n";
//		boost::asio::async_read(socket_,
//			boost::asio::buffer(read_msg_.data(), DataPacket::header_length), //�������ȡ��һ�����ݰ�ͷ
//			boost::bind(&CJPSocketClient::handle_read_header, this,
//			boost::asio::placeholders::error)); //���һ�ζ�������������һ�����ݰ���  ������һ�ζ�����
//	}
//	else
//	{
//		do_close();
//	}
//}

//�����������Ӧ����������״̬�����ݡ�
void CJPSocketClient::HandleReadStatusLine(const boost::system::error_code& err)
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

void CJPSocketClient::do_write(DataPacket msg)
{
	bool write_in_progress = !write_msgs_.empty(); //�յĻ�����Ϊfalse
	write_msgs_.push_back(msg); //��Ҫд������push��д����
	if (!write_in_progress)//���г�ʼΪ�� pushһ��msg�����һ��Ԫ����
	{
		boost::asio::async_write(socket_,
			boost::asio::buffer(write_msgs_.front().data(),
			write_msgs_.front().length()),
			boost::bind(&CJPSocketClient::handle_write, this,
			boost::asio::placeholders::error));
	}
}

void CJPSocketClient::handle_write(const boost::system::error_code& error)//��һ����Ϣ��������ʣ�µĲŸ��ò���
{
	if (!error)
	{
		write_msgs_.pop_front();//�ղŴ�����һ������ ����Ҫpopһ��
		if (!write_msgs_.empty())
		{
			boost::asio::async_write(socket_,
				boost::asio::buffer(write_msgs_.front().data(),
				write_msgs_.front().length()),
				boost::bind(&CJPSocketClient::handle_write, this,
				boost::asio::placeholders::error)); //ѭ������ʣ�����Ϣ
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

//����Tcp�ͻ���
void startTcpClient(std::string ip, std::string port)
{
	boost::asio::io_service io_service;//����socket��������service������

	tcp::resolver resolver(io_service);//tcp::resolverһ���tcp::resolver::query����ã�ͨ��query����ʹ���˼���֪������������ѯsocket����Ӧ��Ϣ��һ��������ǹ���socket�Ķ�����address��port���ѣ�ͨ��tcp::resolver������ʵ�����úͲ�ѯ
	tcp::resolver::query query(ip, port); //����ip�����������Ͷ˿ں�
	tcp::resolver::iterator iterator = resolver.resolve(query);
	CJPSocketClient c(io_service, iterator);// all the socket operations are handled by service
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

void socket_connect()
{
	// ����asio�඼��Ҫio_service����
	boost::asio::io_service iosev;
	// socket����
	boost::asio::ip::tcp::socket socket(iosev);
	// ���Ӷ˵㣬����ʹ���˱������ӣ������޸�IP��ַ����Զ������
	boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::from_string("116.62.152.162"), 6060);
	// ���ӷ�����
	boost::system::error_code ec;
	socket.connect(ep,ec);
	// ���������ӡ������Ϣ
	if(ec)
	{
		std::cout << boost::system::system_error(ec).what() << std::endl;
		return ;
	}
	// ��������
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

	//����IO�������
	boost::asio::io_service ioService;
	CClient client(strHost,strHttp, ioService);
	ioService.run();
}