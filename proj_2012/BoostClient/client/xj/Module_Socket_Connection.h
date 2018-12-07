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
// 2015年12月10日 17:12:52 : asyn_connect在投递之后,is_open便是返回true, 修改判断是否连上的方式
// 2016年04月27日 09:07:07 : send_data的函数扩展, 支持数据发送之后的相关处理, 如:是否失败重发, 是否回调发送状态

#define SEND_WAITING 0  //等待发送
#define SEND_DOING   1  //正在发送

	typedef struct _tagSendOne {
		int nSendStatus;
		//发送数据缓冲区
		char* cSendData;
		//需要发送数据总长度
		int nSendData;
		//已经发送的数据长度
		int nHaveSendData;
		//是否重发数据
		bool bFailResendData;
		//回调函数
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
	*  基础接口, 释放数据 
	*/
	virtual void release();

	/* IModuleSocketConnectionInterface */
	/** 
	 *  功能描述: 配置事件回调接口
	 */
	virtual void set_event_delegate(IModuleSocketConnectionDelegate* event) {event_delegate = event;}
	
	/** 
	 *  功能描述: 同步连接远程地址,函数阻塞
	 *  @param remote_address: 远程IP地址
	 *  @param port: 远程端口
	 *  @return true:连接成功 false:连接失败
	 */
	virtual bool sync_connect(const char* remote_address, unsigned int port);

	/** 
	 *  功能描述: 异步连接远程地址
	 *  @param remote_address: 远程IP地址
	 *  @param port: 远程端口
	 */
	virtual void asyn_connect(const char* remote_address, unsigned int port);

	/** 
	 *  功能描述: 连接是否打开
	 */
	virtual bool is_connect();

	/** 
	 *  功能描述: 发送数据,数据队列顺序发送， send_data是默认重发,无回调, send_data_extend是自己控制是否回调及重发
	 *  @param data: 需要发送数据缓冲区指针
	 *  @param len: 发送数据长度
	 *  @param fail_auto_resend: 失败是否重发数据
	 *  @param call_back: 成功与否的回调函数
	 */
	virtual bool send_data(const unsigned char* data, int len);

	virtual bool send_data_extend(const unsigned char* data, int len, bool fail_auto_resend, boost::function<void (const unsigned char*, int, bool)> call_back);

	/** 
	 *  功能描述: 开启,发送队列继续发送数据
	 */
	virtual void continue_send_data();

	/** 
	 *  功能描述: 暂停,发送数据的数据只发送到队列,不进行发送
	 */
	virtual void pause_send_data();

	/** 
	 *  功能描述: 清空未发送的缓冲区数据
	 */
	virtual void clear_cache();

	/** 
	 *  功能描述: 关闭连接
	 */
	virtual void close();

protected:
	/* 投递异步读取, 不可以外部操作 */
	void asyn_read();
	/* 投递异步写数据 */
	void asyn_write(void* pData, int nSize);

	/* 连接回调函数 */
	void handle_connect(const boost::system::error_code& error);
	/* 断开回调函数 */
	void handle_disconnect();
	/* 读取数据回调 */
	void handle_read(const boost::system::error_code& error, size_t szTransfered);
	/* 写入数据回调 */
	void handle_write(const boost::system::error_code& ec, std::size_t szSend, void* pData);
	
	/* 缓冲是否可以发送数据 */
	bool GetCacheWhetherCanSendData() { return cache_whether_send_data; }
	void SetCacheWhetherCanSendData(bool b) { cache_whether_send_data = b; }

protected:
	/* 事件回调 */
	IModuleSocketConnectionDelegate* event_delegate;
	/* 数据缓冲队列是否发送数据 */
	boost::atomic_bool cache_whether_send_data;
	/* 发送数据缓冲队列 */
	boost::mutex mtx_back_send_list;;
	std::list<SENDONE> back_send_list;
	/* 客户端核心 */
	boost::asio::ip::tcp::socket* socket_connection;
	boost::asio::io_service* io_service;
	boost::asio::io_service::work* io_work;
	boost::thread* thread_run_ioservice;
	char cache_buffer[4096];
	/* 客户端是否在线标识 */
	boost::atomic_bool whether_connection;
};

//extern "C" EXPORT void* __stdcall create_module_socket_connection(std::map<std::string, std::string>* config_map);
//extern "C" void* __stdcall create_module_socket_connection(std::map<std::string, std::string>* config_map) {
//	//建立对象
//	OPLibrary::CModuleSocketConnection* model = nullptr;
//	try {
//		model = new OPLibrary::CModuleSocketConnection();
//		if (!model) throw "创建失败";
//		return static_cast<OPLibrary::IModuleSocketConnectionInterface*>(model);
//	} catch (...) {}
//
//	return nullptr;
//}

}

#endif