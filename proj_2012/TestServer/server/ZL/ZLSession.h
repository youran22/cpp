#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>

#include "ZLPacket.h"
#include "ZLRoom.h"
#include "ZLSessin_Participant.h"

using boost::asio::ip::tcp;


class ZLSession
	: public ZLSessin_Participant,
	public boost::enable_shared_from_this<ZLSession>
{
public:
	ZLSession(boost::asio::io_service& io_service, ZLRoom& room)
		: socket_(io_service),
		room_(room)
	{
	}

	tcp::socket& socket()
	{
		return socket_;
	}

	void start()//ÿ����һ���µ�ZLSession�������
	{
		room_.join(shared_from_this());
		boost::asio::async_read(socket_,
			boost::asio::buffer(read_msg_.data(), ZLPacket::header_length),
			boost::bind(
				&ZLSession::handle_read_header, shared_from_this(),
				boost::asio::placeholders::error)); //�첽���ͻ��˷�������Ϣ һ���ͻ�������Ϣ��������ִ������Ĵ��룻
	}

	void deliver(const ZLPacket& msg)
	{
		bool write_in_progress = !write_msgs_.empty();//�ж϶����Ƿ�Ϊ��
		write_msgs_.push_back(msg); //��room�б������Ϣ�ҵ�write_msgs��β
		if (!write_in_progress)
		{
			boost::asio::async_write(socket_,
				boost::asio::buffer(write_msgs_.front().data(),
					write_msgs_.front().length()),
				boost::bind(&ZLSession::handle_write, shared_from_this(),
					boost::asio::placeholders::error));
		}
	}

	void handle_read_header(const boost::system::error_code& error)
	{
		if (!error && read_msg_.decode_header())
		{
			boost::asio::async_read(socket_,
				boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
				boost::bind(&ZLSession::handle_read_body, shared_from_this(),
					boost::asio::placeholders::error));
		}
		else
		{
			room_.leave(shared_from_this());
		}
	}

	void handle_read_body(const boost::system::error_code& error)
	{
		if (!error)
		{
			room_.deliver(read_msg_);
			boost::asio::async_read(socket_,
				boost::asio::buffer(read_msg_.data(), ZLPacket::header_length),
				boost::bind(&ZLSession::handle_read_header, shared_from_this(),
					boost::asio::placeholders::error));
		}
		else
		{
			room_.leave(shared_from_this());
		}
	}

	void handle_write(const boost::system::error_code& error)
	{
		if (!error)
		{
			write_msgs_.pop_front();
			if (!write_msgs_.empty())
			{
				boost::asio::async_write(socket_,
					boost::asio::buffer(write_msgs_.front().data(),
						write_msgs_.front().length()),
					boost::bind(&ZLSession::handle_write, shared_from_this(),
						boost::asio::placeholders::error)); //�������˽��յ�����Ϣ�͸����еĿͻ��ˣ��㲥�ķ�ʽ��
			}
		}
		else
		{
			room_.leave(shared_from_this());
		}
	}

private:
	tcp::socket socket_;
	ZLRoom& room_;
	ZLPacket read_msg_;
	packet_queue write_msgs_;
};

typedef boost::shared_ptr<ZLSession> session_ptr;