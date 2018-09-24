#pragma once
//
// ZLTcpClient.cpp
//ʵ�ֵĴ���˼·�ǣ��ڴ����Ŀͻ���ʵ���г�ʼ��socket�����ӷ������ˣ����Ҳ��ϵĽ������첽���������ӷ������˶����ݣ�
//��дsocket�������첽����


#include <cstdlib>
#include <deque>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include "ZLPacket.h"

using boost::asio::ip::tcp;

typedef std::deque<ZLPacket> packet_queue;

class ZLTcpClient
{
public:
	ZLTcpClient(boost::asio::io_service& io_service,
		tcp::resolver::iterator endpoint_iterator)
		: io_service_(io_service),
		socket_(io_service) //ʹ�ó�Ա������ֱ��ʹ����Щ����
	{
		boost::asio::async_connect(socket_, endpoint_iterator,
			boost::bind(&ZLTcpClient::handle_connect, this,
				boost::asio::placeholders::error)); //���еĲ����������첽�ķ�ʽ
	}

	void write(const ZLPacket& msg)
	{
		io_service_.post(boost::bind(&ZLTcpClient::do_write, this, msg)); //����Ϣ����Ͷ�ݸ�io_service
	}

	void close()
	{
		io_service_.post(boost::bind(&ZLTcpClient::do_close, this)); //���close�����ǿͻ���Ҫ������ֹʱ����  do_close�����Ǵӷ�������
																	 //������ʧ��ʱ����
	}

	//�첽����Tcp�ͻ���
	void asyncRun()
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
	void syncRun() {
		io_service_.reset();
		io_service_.run();
	}

private:

	void handle_connect(const boost::system::error_code& error)
	{
		if (!error)
		{
			boost::asio::async_read(socket_,
				boost::asio::buffer(read_msg_.data(), ZLPacket::header_length), //��ȡ���ݱ�ͷ
				boost::bind(&ZLTcpClient::handle_read_header, this,
					boost::asio::placeholders::error));//һ������Ϣ�������ȡ
		}
	}

	void handle_read_header(const boost::system::error_code& error)
	{
		if (!error && read_msg_.decode_header()) //�ֱ������ݱ�ͷ�����ݲ���
		{
			boost::asio::async_read(socket_,
				boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),//��ȡ���ݰ����ݲ���
				boost::bind(&ZLTcpClient::handle_read_body, this,
					boost::asio::placeholders::error));//
		}
		else
		{
			do_close();
		}
	}

	void handle_read_body(const boost::system::error_code& error)
	{
		if (!error)
		{
			std::cout.write(read_msg_.body(), read_msg_.body_length()); //�����Ϣ
			std::cout << "\n";
			boost::asio::async_read(socket_,
				boost::asio::buffer(read_msg_.data(), ZLPacket::header_length), //�������ȡ��һ�����ݰ�ͷ
				boost::bind(&ZLTcpClient::handle_read_header, this,
					boost::asio::placeholders::error)); //���һ�ζ�������������һ�����ݰ���  ������һ�ζ�����
		}
		else
		{
			do_close();
		}
	}

	void do_write(ZLPacket msg)
	{
		bool write_in_progress = !write_msgs_.empty(); //�յĻ�����Ϊfalse
		write_msgs_.push_back(msg); //��Ҫд������push��д����
		if (!write_in_progress)//���г�ʼΪ�� pushһ��msg�����һ��Ԫ����
		{
			boost::asio::async_write(socket_,
				boost::asio::buffer(write_msgs_.front().data(),
					write_msgs_.front().length()),
				boost::bind(&ZLTcpClient::handle_write, this,
					boost::asio::placeholders::error));//������Ϣ���ͻ���
		}
	}

	void handle_write(const boost::system::error_code& error)//��һ����Ϣ��������ʣ�µĲŸ��ò���
	{
		if (!error)
		{
			write_msgs_.pop_front();//�ղŴ�����һ������ ����Ҫpopһ��
			if (!write_msgs_.empty())
			{
				boost::asio::async_write(socket_,
					boost::asio::buffer(write_msgs_.front().data(),
						write_msgs_.front().length()),
					boost::bind(&ZLTcpClient::handle_write, this,
						boost::asio::placeholders::error)); //ѭ������ʣ�����Ϣ
			}
		}
		else
		{
			do_close();
		}
	}

	void do_close()
	{
		socket_.close();
	}

private:
	boost::thread t;
	boost::asio::io_service& io_service_;
	tcp::socket socket_;
	ZLPacket read_msg_;
	packet_queue write_msgs_;
};

//----------------------------------------------------------------------
//����Tcp�ͻ���
//async ture:�첽����  false:ͬ������
//----------------------------------------------------------------------
//�첽����Tcp�ͻ���
void startAsyncTcpClient(std::string ip, std::string port);
//ͬ������Tcp�ͻ���
void startSyncClient(std::string ip, std::string port);