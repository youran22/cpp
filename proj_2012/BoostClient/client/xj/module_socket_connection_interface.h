#ifndef MODULE_SOCKET_CONNECTION_INTERFACE_H_
#define MODULE_SOCKET_CONNECTION_INTERFACE_H_
#include "basic_interface.h"
#include <boost/function.hpp>

namespace OPLibrary 
{

class IModuleSocketConnectionDelegate 
{
public:
	/* 连接建立成功与否 */
	virtual void on_socket_connect(bool is_ok) = 0;

	/* 连接关闭 */
	virtual void on_socket_close() = 0;

	/* 接收到数据 */
	virtual void on_socket_data(const unsigned char* data, int len) = 0;
};

class IModuleSocketConnectionInterface : public IBasicCommon {
public:
	/** 
	 *  功能描述: 配置事件回调接口
	 */
	virtual void set_event_delegate(IModuleSocketConnectionDelegate* event) = 0;

	/** 
	 *  功能描述: 同步连接远程地址,函数阻塞
	 *  @param remote_address: 远程IP地址
	 *  @param port: 远程端口
	 *  @return true:连接成功 false:连接失败
	 */
	virtual bool sync_connect(const char* remote_address, unsigned int port) = 0;

	/** 
	 *  功能描述: 异步连接远程地址
	 *  @param remote_address: 远程IP地址
	 *  @param port: 远程端口
	 */
	virtual void asyn_connect(const char* remote_address, unsigned int port) = 0;

	/** 
	 *  功能描述: 连接是否打开
	 */
	virtual bool is_connect() = 0;

	/** 
	 *  功能描述: 发送数据,数据队列顺序发送， send_data是默认重发,无回调, send_data_extend是自己控制是否回调及重发
	 *  @param data: 需要发送数据缓冲区指针
	 *  @param len: 发送数据长度
	 *  @param fail_auto_resend: 失败是否重发数据
	 *  @param call_back: 成功与否的回调函数
	 */
	virtual bool send_data(const unsigned char* data, int len) = 0;

	virtual bool send_data_extend(const unsigned char* data, int len, bool fail_auto_resend, boost::function<void (const unsigned char*, int, bool)> call_back) = 0;

	/** 
	 *  功能描述: 开启,发送队列继续发送数据
	 */
	virtual void continue_send_data() = 0;

	/** 
	 *  功能描述: 暂停,发送数据的数据只发送到队列,不进行发送
	 */
	virtual void pause_send_data() = 0;

	/** 
	 *  功能描述: 清空未发送的缓冲区数据
	 */
	virtual void clear_cache() = 0;

	/** 
	 *  功能描述: 关闭连接
	 */
	virtual void close() = 0;
}; 

}

#endif