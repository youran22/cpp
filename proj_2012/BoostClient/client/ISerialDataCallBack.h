#ifndef SERVICE_DATA_CALLBACK_H_C17C0887_9699_4AA6_A451_80980D1337ED
#define SERVICE_DATA_CALLBACK_H_C17C0887_9699_4AA6_A451_80980D1337ED

class ISerialDataCallBack {
public:
  virtual ~ISerialDataCallBack() {}

  /**
   * \brief 串口数据回调
   * \param data 缓冲区指针
   * \param len 缓冲区数据长度
   */
  virtual void on_serial_data(const unsigned char* data, unsigned int len) = 0;

	virtual void on_net_data(const unsigned char* data, unsigned int len) = 0;
};

#endif