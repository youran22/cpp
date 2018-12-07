#ifndef MODULE_SOCKET_CONNECTION_H_
#define MODULE_SOCKET_CONNECTION_H_
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/unordered_map.hpp>
#include <boost/atomic.hpp>
#include "module_socket_connection_interface.h"
#include "common_define.h"
#include <string>
#include <map>

namespace OPLibrary {
// 2015��12��10�� 17:12:52 : asyn_connect��Ͷ��֮��,is_open���Ƿ���true, �޸��ж��Ƿ����ϵķ�ʽ
// 2016��04��27�� 09:07:07 : send_data�ĺ�����չ, ֧�����ݷ���֮�����ش���, ��:�Ƿ�ʧ���ط�, �Ƿ�ص�����״̬

#define SEND_WAITING 0  //�ȴ�����
#define SEND_DOING   1  //���ڷ���

	typedef struct _tagSendOne {
		int nSendStatus;
		//�������ݻ�����
		char* cSendData;
		//��Ҫ���������ܳ���
		int nSendData;
		//�Ѿ����͵����ݳ���
		int nHaveSendData;
		//�Ƿ��ط�����
		bool bFailResendData;
		//�ص�����
		boost::function<void (const unsigned char*, int, bool)> call_back;
		_tagSendOne() {
			nSendStatus = SEND_WAITING;
			cSendData = nullptr;
			nSendData = 0;
			nHaveSendData = 0;
			bFailResendData = true;
		}
	}SENDONE, *PSENDONE;

using namespace boost::asio;
class CModuleSocketConnection : public IModuleSocketConnectionInterface	{
public:
	CModuleSocketConnection();
	~CModuleSocketConnection();

	/* IBasicCommon */
	/* 
	*  �����ӿ�, �ͷ����� 
	*/
	virtual void release();

	/* IModuleSocketConnectionInterface */
	/** 
	 *  ��������: �����¼��ص��ӿ�
	 */
	virtual void set_event_delegate(IModuleSocketConnectionDelegate* event) {event_delegate = event;}
	
	/** 
	 *  ��������: ͬ������Զ�̵�ַ,��������
	 *  @param remote_address: Զ��IP��ַ
	 *  @param port: Զ�̶˿�
	 *  @return true:���ӳɹ� false:����ʧ��
	 */
	virtual bool sync_connect(const char* remote_address, unsigned int port);

	/** 
	 *  ��������: �첽����Զ�̵�ַ
	 *  @param remote_address: Զ��IP��ַ
	 *  @param port: Զ�̶˿�
	 */
	virtual void asyn_connect(const char* remote_address, unsigned int port);

	/** 
	 *  ��������: �����Ƿ��
	 */
	virtual bool is_connect();

	/** 
	 *  ��������: ��������,���ݶ���˳���ͣ� send_data��Ĭ���ط�,�޻ص�, send_data_extend���Լ������Ƿ�ص����ط�
	 *  @param data: ��Ҫ�������ݻ�����ָ��
	 *  @param len: �������ݳ���
	 *  @param fail_auto_resend: ʧ���Ƿ��ط�����
	 *  @param call_back: �ɹ����Ļص�����
	 */
	virtual bool send_data(const unsigned char* data, int len);

	virtual bool send_data_extend(const unsigned char* data, int len, bool fail_auto_resend, boost::function<void (const unsigned char*, int, bool)> call_back);

	/** 
	 *  ��������: ����,���Ͷ��м�����������
	 */
	virtual void continue_send_data();

	/** 
	 *  ��������: ��ͣ,�������ݵ�����ֻ���͵�����,�����з���
	 */
	virtual void pause_send_data();

	/** 
	 *  ��������: ���δ���͵Ļ���������
	 */
	virtual void clear_cache();

	/** 
	 *  ��������: �ر�����
	 */
	virtual void close();

protected:
	/* Ͷ���첽��ȡ, �������ⲿ���� */
	void asyn_read();
	/* Ͷ���첽д���� */
	void asyn_write(void* pData, int nSize);

	/* ���ӻص����� */
	void handle_connect(const boost::system::error_code& error);
	/* �Ͽ��ص����� */
	void handle_disconnect();
	/* ��ȡ���ݻص� */
	void handle_read(const boost::system::error_code& error, size_t szTransfered);
	/* д�����ݻص� */
	void handle_write(const boost::system::error_code& ec, std::size_t szSend, void* pData);
	
	/* �����Ƿ���Է������� */
	bool GetCacheWhetherCanSendData() { return cache_whether_send_data; }
	void SetCacheWhetherCanSendData(bool b) { cache_whether_send_data = b; }

protected:
	/* �¼��ص� */
	IModuleSocketConnectionDelegate* event_delegate;
	/* ���ݻ�������Ƿ������� */
	boost::atomic_bool cache_whether_send_data;
	/* �������ݻ������ */
	boost::mutex mtx_back_send_list;;
	std::list<SENDONE> back_send_list;
	/* �ͻ��˺��� */
	boost::asio::ip::tcp::socket* socket_connection;
	boost::asio::io_service* io_service;
	boost::asio::io_service::work* io_work;
	boost::thread* thread_run_ioservice;
	char cache_buffer[4096];
	/* �ͻ����Ƿ����߱�ʶ */
	boost::atomic_bool whether_connection;
};

//extern "C" EXPORT void* __stdcall create_module_socket_connection(std::map<std::string, std::string>* config_map);
//extern "C" void* __stdcall create_module_socket_connection(std::map<std::string, std::string>* config_map) {
//	//��������
//	OPLibrary::CModuleSocketConnection* model = nullptr;
//	try {
//		model = new OPLibrary::CModuleSocketConnection();
//		if (!model) throw "����ʧ��";
//		return static_cast<OPLibrary::IModuleSocketConnectionInterface*>(model);
//	} catch (...) {}
//
//	return nullptr;
//}

}

#endif