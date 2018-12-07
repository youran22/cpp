#include "Module_Socket_Connection.h"

namespace OPLibrary {

CModuleSocketConnection::CModuleSocketConnection() {
	event_delegate = nullptr;
	whether_connection = false;
	SetCacheWhetherCanSendData(false);
	io_service = new boost::asio::io_service();
	socket_connection = new boost::asio::ip::tcp::socket(*io_service);
	io_work = new boost::asio::io_service::work(*io_service);
	thread_run_ioservice = new boost::thread(boost::bind(&boost::asio::io_service::run, io_service));
	memset(cache_buffer, 0, sizeof(cache_buffer)/sizeof(char));
}

CModuleSocketConnection::~CModuleSocketConnection() {
	if (socket_connection != nullptr) {
		whether_connection = false;
		boost::system::error_code ec;
		socket_connection->shutdown(boost::asio::ip::tcp::socket::shutdown_both,ec);
		socket_connection->close(ec);
	} 
	if (io_service != nullptr) io_service->stop();
	if (thread_run_ioservice != nullptr) thread_run_ioservice->join();

	delete socket_connection;
	delete io_work;
	delete io_service;
	delete thread_run_ioservice;
	
	/* ��ջ������� */
	clear_cache();
}

void CModuleSocketConnection::release() {
	delete this;
}

bool CModuleSocketConnection::sync_connect(const char* remote_address, unsigned int port) {
	if (whether_connection == true) return true;
	if (remote_address == nullptr || port <= 0 || strlen(remote_address) == 0) return false;

	ip::tcp::endpoint ep(ip::address_v4::from_string(remote_address), port);
	boost::system::error_code ec;

	socket_connection->connect(ep, ec);
	/* ��������״̬��ʾ�� */
	whether_connection = !ec==false? true : false;

	handle_connect(ec);

	if (ec) return false;
	return true;
}

void CModuleSocketConnection::asyn_connect(const char* remote_address, unsigned int port) {
	if (whether_connection == true) return;
	if (remote_address == nullptr || port <= 0) return;

	boost::asio::ip::tcp::endpoint endp(boost::asio::ip::address::from_string(remote_address), port);
	socket_connection->async_connect(endp, boost::BOOST_BIND(&CModuleSocketConnection::handle_connect, this, boost::asio::placeholders::error));
}

bool CModuleSocketConnection::is_connect() {
	if (socket_connection == nullptr) return false;

	return whether_connection;
}

void CModuleSocketConnection::handle_connect(const boost::system::error_code& error) {
	/* ����ʧ�� */
	if (error) {
		/* ��������״̬��ʾ�� */
		whether_connection = false;
		if (event_delegate != nullptr) event_delegate->on_socket_connect(false);
		return;
	}

	/* ��������״̬��ʾ�� */
	whether_connection = true;
	/* �¼��ص� */
	if (event_delegate != nullptr) event_delegate->on_socket_connect(true);
	/* Ͷ���첽�¼� */
	asyn_read();
}

void CModuleSocketConnection::close() {
	if (socket_connection == nullptr || is_connect() == false) return;
	socket_connection->get_io_service().post(boost::BOOST_BIND(&CModuleSocketConnection::handle_disconnect, this));
}

void CModuleSocketConnection::clear_cache() {
	/* ��ջ������� */
	boost::lock_guard<boost::mutex> lock(mtx_back_send_list);
	std::list<SENDONE>::iterator it = back_send_list.begin();
	while (it != back_send_list.end()) {
		safe_delete(it->cSendData);
		it++;
	}
	back_send_list.clear();
}

void CModuleSocketConnection::handle_disconnect() {
	if (socket_connection == nullptr) return;
	if (is_connect() == false) return;

	/* ��������״̬��ʾ�� */
	whether_connection = false;

	boost::system::error_code ec;
	socket_connection->shutdown(boost::asio::ip::tcp::socket::shutdown_both,ec);
	socket_connection->close(ec);

	/* ʣ������ݻָ���ʼ�� */
	boost::lock_guard<boost::mutex> lock(mtx_back_send_list);
	std::list<SENDONE>::iterator it = back_send_list.begin();
	while (it != back_send_list.end()) {
		/* ���ڷ���ʧ��, ����Ҫ���·��͵�, ɾ��,�����ûص����� */
		if (it->bFailResendData == true) {
			it->nHaveSendData = 0; it->nSendStatus = SEND_WAITING;
			it++;
		} else {
			if (it->call_back.empty() == false)
				it->call_back((const unsigned char*)it->cSendData, it->nSendData, false);
			it = back_send_list.erase(it);
		}
	}

	/* �رջ��巢�Ͷ��� */
	SetCacheWhetherCanSendData(false);

	if (event_delegate != nullptr) event_delegate->on_socket_close();
}

void CModuleSocketConnection::asyn_read() {
	if (socket_connection == nullptr) return;
	socket_connection->async_read_some(
		boost::asio::buffer(cache_buffer, 4096), 
		boost::BOOST_BIND(&CModuleSocketConnection::handle_read, 
		this, _1, _2));
}

void CModuleSocketConnection::handle_read(const boost::system::error_code& error, size_t szTransfered) {
	if (error) { close(); return; }

	/* �¼��ص� */
	if (event_delegate != nullptr) event_delegate->on_socket_data((const unsigned char*)cache_buffer, szTransfered);
	/* Ͷ���첽�¼� */
	asyn_read();
}

void CModuleSocketConnection::asyn_write(void* pData, int nSize) {
	if (socket_connection == nullptr) return;
	boost::asio::async_write(
		*socket_connection, 
		boost::asio::buffer(pData, nSize), 
		boost::asio::transfer_at_least(nSize), 
		boost::BOOST_BIND(&CModuleSocketConnection::handle_write, this, _1, _2, pData));
}

bool CModuleSocketConnection::send_data(const unsigned char* data, int len) {
	boost::function<void (const unsigned char*, int, bool)> empty_call_back;

	send_data_extend(data, len, true, empty_call_back);

	return true;
}

bool CModuleSocketConnection::send_data_extend(const unsigned char* data, int len, bool fail_auto_resend, boost::function<void (const unsigned char*, int, bool)> call_back) {
	if (socket_connection == nullptr) return false;

	if (!data || len <= 0) return false;

	int nMallocLen = (len/4096 + 1) * 4096;
	char* pSendBuffer = (char*)malloc(nMallocLen);
	if (!pSendBuffer) return false;
	memset(pSendBuffer, 0, nMallocLen);
	memcpy(pSendBuffer, data, len);

	SENDONE sendOne;
	sendOne.cSendData = pSendBuffer;
	sendOne.nSendData = len;
	sendOne.nHaveSendData = 0;
	sendOne.nSendStatus = SEND_WAITING;
	sendOne.bFailResendData = fail_auto_resend;
	sendOne.call_back = call_back;

	boost::lock_guard<boost::mutex> lock(mtx_back_send_list);

	back_send_list.push_back(sendOne);

	/* ���Ͷ����Ƿ���ʱ�ر�,�������� */
	if (GetCacheWhetherCanSendData() == false) return true;

	/* ��ȡ����ĵ�һ�������Ƿ��ڷ���״̬, ��������˳�, �����͵�һ������ */
	SENDONE& sendDataHead = back_send_list.front();

	if (sendDataHead.nSendStatus == SEND_DOING) return true;

	sendDataHead.nSendStatus = SEND_DOING;

	asyn_write(sendDataHead.cSendData, sendDataHead.nSendData);

	return true;	
}

void CModuleSocketConnection::handle_write(const boost::system::error_code& ec, std::size_t szSend, void* pData) {
	if (socket_connection == nullptr) return;
	if (ec) { close(); return; }

	/* ��⵱ǰ���͵ĳ����Ƿ���ȫ���ĳ��� */
	boost::lock_guard<boost::mutex> lock(mtx_back_send_list);

	if (back_send_list.empty()) return;

	/* ��ȡ����ĵ�һ�������Ƿ��ڷ���״̬ */
	SENDONE& sendDataHead = back_send_list.front();

	/* ����������������, ���ݷ����쳣�� */
	if (sendDataHead.nSendStatus != SEND_DOING) return;
	
	//����û�з�����ȫ, ��������
	if (sendDataHead.nSendData > (szSend + sendDataHead.nHaveSendData)) {    
		sendDataHead.nHaveSendData += szSend;

		int nControlSize = sendDataHead.nSendData - sendDataHead.nHaveSendData;

		return asyn_write(sendDataHead.cSendData + sendDataHead.nHaveSendData, nControlSize);
	}
	//���ݷ������, �ͷſռ�, ����ȡ��һ������
	else if (sendDataHead.nSendData == (szSend + sendDataHead.nHaveSendData)) {
		/* ���ݷ��ͳɹ�, �鿴�Ƿ���Ҫ���ûص����� */
		if (sendDataHead.call_back.empty() == false)
			sendDataHead.call_back((const unsigned char*)sendDataHead.cSendData, sendDataHead.nSendData, true);

		safe_free(sendDataHead.cSendData);

		back_send_list.pop_front();

		if (back_send_list.empty()) return;

		SENDONE& nextSendData = back_send_list.front();

		nextSendData.nSendStatus = SEND_DOING;

		asyn_write(nextSendData.cSendData, nextSendData.nSendData);
	}
}

void CModuleSocketConnection::continue_send_data() {
	SetCacheWhetherCanSendData(true);
}

void CModuleSocketConnection::pause_send_data() {
	SetCacheWhetherCanSendData(false);
}

}