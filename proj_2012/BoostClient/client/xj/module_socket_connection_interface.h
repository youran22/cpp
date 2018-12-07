#ifndef MODULE_SOCKET_CONNECTION_INTERFACE_H_
#define MODULE_SOCKET_CONNECTION_INTERFACE_H_
#include "basic_interface.h"
#include <boost/function.hpp>

namespace OPLibrary 
{

class IModuleSocketConnectionDelegate 
{
public:
	/* ���ӽ����ɹ���� */
	virtual void on_socket_connect(bool is_ok) = 0;

	/* ���ӹر� */
	virtual void on_socket_close() = 0;

	/* ���յ����� */
	virtual void on_socket_data(const unsigned char* data, int len) = 0;
};

class IModuleSocketConnectionInterface : public IBasicCommon {
public:
	/** 
	 *  ��������: �����¼��ص��ӿ�
	 */
	virtual void set_event_delegate(IModuleSocketConnectionDelegate* event) = 0;

	/** 
	 *  ��������: ͬ������Զ�̵�ַ,��������
	 *  @param remote_address: Զ��IP��ַ
	 *  @param port: Զ�̶˿�
	 *  @return true:���ӳɹ� false:����ʧ��
	 */
	virtual bool sync_connect(const char* remote_address, unsigned int port) = 0;

	/** 
	 *  ��������: �첽����Զ�̵�ַ
	 *  @param remote_address: Զ��IP��ַ
	 *  @param port: Զ�̶˿�
	 */
	virtual void asyn_connect(const char* remote_address, unsigned int port) = 0;

	/** 
	 *  ��������: �����Ƿ��
	 */
	virtual bool is_connect() = 0;

	/** 
	 *  ��������: ��������,���ݶ���˳���ͣ� send_data��Ĭ���ط�,�޻ص�, send_data_extend���Լ������Ƿ�ص����ط�
	 *  @param data: ��Ҫ�������ݻ�����ָ��
	 *  @param len: �������ݳ���
	 *  @param fail_auto_resend: ʧ���Ƿ��ط�����
	 *  @param call_back: �ɹ����Ļص�����
	 */
	virtual bool send_data(const unsigned char* data, int len) = 0;

	virtual bool send_data_extend(const unsigned char* data, int len, bool fail_auto_resend, boost::function<void (const unsigned char*, int, bool)> call_back) = 0;

	/** 
	 *  ��������: ����,���Ͷ��м�����������
	 */
	virtual void continue_send_data() = 0;

	/** 
	 *  ��������: ��ͣ,�������ݵ�����ֻ���͵�����,�����з���
	 */
	virtual void pause_send_data() = 0;

	/** 
	 *  ��������: ���δ���͵Ļ���������
	 */
	virtual void clear_cache() = 0;

	/** 
	 *  ��������: �ر�����
	 */
	virtual void close() = 0;
}; 

}

#endif