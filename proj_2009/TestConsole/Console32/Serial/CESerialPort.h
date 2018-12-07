#pragma once

#define  WM_PORT_SEND_CMD		WM_USER+1  
#define  EG_STRTIP_FULL_OPENCOM_ERROR		WM_USER+2
#define  WM_COMM_RXCHAR				WM_USER+7
struct BinPackage
{
	char headA;
	char headB;
	char headC;
	char encryption;
	unsigned char length[2];
	unsigned char total[4];
	unsigned char number[4];
	unsigned char mode;
	unsigned char data[513];
	unsigned char crc;
};
//CE串口通讯类
class CCESerialPort
{
public:
	CCESerialPort(void);
	~CCESerialPort(void);

	//操作
public:

	//打开和关闭串口---------------------------------------------------------------------------
	//核心类,EGStar打开串口调用该函数
	BOOL Open(int nPortNo, DWORD BaudRate=9600, int DataBits=8,int StopBits=ONESTOPBIT,int Parity=NOPARITY);
	//核心类,EGStar关闭串口调用该函数
	BOOL Close();

	//[2010.09.03XB]正常工作中,数据中断,需要及时关闭串口,否则死机
	//但关闭时,不能CLOSEHANDLE串口句柄,所以独立一个函数
	BOOL Close_DataAbend();  

	//实现打开串口
	BOOL OpenPort(LPCTSTR Port,int Baudrate=9600,int DataBits=8,
		int StopBits=ONESTOPBIT,int Parity=NOPARITY); //,LPDataArriveProc proc=NULL,DWORD userdata=0); 
	BOOL ClosePort(); //实现关闭串口

	BOOL IsOpen(); //串口是否已经打开


	//开启与停止线程----------------------------------------------------------
	BOOL Activate();//打开串口后,使用该函数开启接收线程
	BOOL Deactivate(); //关闭串口后,使用该函数停止接收线程
	BOOL IsActive();  //判断当前是否已经打开传后;打开串口时用,如果打开了则需要先关闭

	//实现接收串口数据线程函数,接收后通过消息发送给处理类
	static DWORD WINAPI ReadPortThread(LPVOID lpParameter);


	//发送命令函数-----------------------------------------------------------------------------
	//使用重载,可以发送不同类型的数据
	DWORD WritePort(char *data,int length); //发送数据
	DWORD WritePort(BYTE *buf, DWORD dwCharToWrite);
	BOOL     WritePort(CString strSend);
	//功能,发送南方命令
	BOOL     SendSOUTHCmd(unsigned char Command, CString Command_var);
	//功能,发送南方命令
	BOOL     SendRegCommand(unsigned char CmdID, int DataLen, CString DataStr);

	//2008.11.05新增加
	//功能:发送空格分隔命令体的16进制命令
	BOOL     SendHexCmdBySpace(CString szCommand);
	char      UseGetHexChar(char c);

	//设置或清除窗口数据消息发送的目的句柄
	void       ClrOtherHwnd();
	void       SetHwnd(HWND hSendWnd, int nMsgID);
	void       SetOtherHwnd(HWND hSendWnd, int nMsgID);
	void       CloseOtherHwnd(void);


	//其它函数-----------------------------------------------------------------------
	BOOL     InitDCB(DWORD BaudRate);
	DWORD ReadPort(char *data,int length); //读取一定长度的数据
	int         GetCurPort();
	BOOL     SetDTR(DWORD dwFunc);
	BOOL     SetRTS(DWORD dwFunc);
	DWORD WriteFileToPort(LPCTSTR FileName); //发送文件

	//数据
public:
	int	          m_nPort;		//当前打开串口号

	HWND     m_hSendWnd;	//发送消息句柄

	HWND     m_hOtherSendWnd;	//其他消息发送句柄
	BOOL       m_bSetOtherSendWnd;//其他消息发送句柄设置标志

	int           m_nMsgID;
	int           m_nOtherMsgID;

	int		m_nSendCount;//device.update.end

public:
	HANDLE   m_hComm;         //串口设备handle
	HANDLE   m_hReadThread; //读串口线程handle
	BOOL       m_bReceiving;     //是否持续接收
	int           m_nBufferSize;    //缓冲大小,一次读取缓冲中的多少字节数据

	//串口设置以及超时参数
	DCB                     dcb;  //串口参数变量
	COMMTIMEOUTS   CommTimeOuts;  //串口超时参数变量

public:
	//handle
	HANDLE m_hEvent[2];

	int m_nBaudrate; int m_nDataBits; int m_nStopBits;int m_nParity;

	BOOL  OpenSerialPort();
	static DWORD WINAPI OpenPortThread(LPVOID lpParameter);
	void  SetComPar(int nPort, int nBaud=9600,int nDataBits=8, 
		int nStopBits=ONESTOPBIT,int Parity=NOPARITY);
	BOOL OpenPort2(LPCTSTR Port,int Baudrate=9600,int DataBits=8,
		int StopBits=ONESTOPBIT,int Parity=NOPARITY); //,LPDataArriveProc proc=NULL,DWORD userdata=0);


	//20120203  SinoEwack    读串口改为有数据到来才去读串口，用异步的方式打开串口
	OVERLAPPED m_osRead,m_osWrite;
	HANDLE m_hShutCommEvent;
	void SetComBaudrate(int nBaud);
};
