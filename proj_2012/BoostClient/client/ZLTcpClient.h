#pragma once
//
// ZLTcpClient.cpp
//实现的大致思路是：在创建的客户端实例中初始化socket、连接服务器端，并且不断的进行着异步读操作（从服务器端读数据）
//读写socket都是用异步操作


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
		socket_(io_service) //使得成员函数能直接使用这些变量
	{
		boost::asio::async_connect(socket_, endpoint_iterator,
			boost::bind(&ZLTcpClient::handle_connect, this,
				boost::asio::placeholders::error)); //所有的操作都采用异步的方式
	}

	void write(const ZLPacket& msg)
	{
		io_service_.post(boost::bind(&ZLTcpClient::do_write, this, msg)); //将消息主动投递给io_service
	}

	void close()
	{
		io_service_.post(boost::bind(&ZLTcpClient::do_close, this)); //这个close函数是客户端要主动终止时调用  do_close函数是从服务器端
																	 //读数据失败时调用
	}

	//异步运行Tcp客户端
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

	//同步运行Tcp客户端
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
				boost::asio::buffer(read_msg_.data(), ZLPacket::header_length), //读取数据报头
				boost::bind(&ZLTcpClient::handle_read_header, this,
					boost::asio::placeholders::error));//一旦有消息来，则读取
		}
	}

	void handle_read_header(const boost::system::error_code& error)
	{
		if (!error && read_msg_.decode_header()) //分别处理数据报头和数据部分
		{
			boost::asio::async_read(socket_,
				boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),//读取数据包数据部分
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
			std::cout.write(read_msg_.body(), read_msg_.body_length()); //输出消息
			std::cout << "\n";
			boost::asio::async_read(socket_,
				boost::asio::buffer(read_msg_.data(), ZLPacket::header_length), //在这里读取下一个数据包头
				boost::bind(&ZLTcpClient::handle_read_header, this,
					boost::asio::placeholders::error)); //完成一次读操作（处理完一个数据包）  进行下一次读操作
		}
		else
		{
			do_close();
		}
	}

	void do_write(ZLPacket msg)
	{
		bool write_in_progress = !write_msgs_.empty(); //空的话变量为false
		write_msgs_.push_back(msg); //把要写的数据push至写队列
		if (!write_in_progress)//队列初始为空 push一个msg后就有一个元素了
		{
			boost::asio::async_write(socket_,
				boost::asio::buffer(write_msgs_.front().data(),
					write_msgs_.front().length()),
				boost::bind(&ZLTcpClient::handle_write, this,
					boost::asio::placeholders::error));//发送消息到客户端
		}
	}

	void handle_write(const boost::system::error_code& error)//第一个消息单独处理，剩下的才更好操作
	{
		if (!error)
		{
			write_msgs_.pop_front();//刚才处理完一个数据 所以要pop一个
			if (!write_msgs_.empty())
			{
				boost::asio::async_write(socket_,
					boost::asio::buffer(write_msgs_.front().data(),
						write_msgs_.front().length()),
					boost::bind(&ZLTcpClient::handle_write, this,
						boost::asio::placeholders::error)); //循环处理剩余的消息
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
//启动Tcp客户端
//async ture:异步启动  false:同步启动
//----------------------------------------------------------------------
//异步启动Tcp客户端
void startAsyncTcpClient(std::string ip, std::string port);
//同步启动Tcp客户端
void startSyncClient(std::string ip, std::string port);