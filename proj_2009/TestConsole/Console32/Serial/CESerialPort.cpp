#include "../stdafx.h"
#include "CESerialPort.h"
#include <string>
//#include "MessageBoxDlg.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CCESerialPort::CCESerialPort()
{
	//初始化若干变量
	m_hComm = INVALID_HANDLE_VALUE;

	m_hReadThread = NULL;
	m_bReceiving = FALSE;

	m_nBufferSize = 1024; //缓冲大小

	m_nPort = 7;

	m_hSendWnd = NULL;
	m_nMsgID = -1;

	m_bSetOtherSendWnd = FALSE;
	m_hOtherSendWnd = NULL;
	m_nOtherMsgID = -1;

	m_hReadThread = NULL;
	m_osRead.hEvent = NULL;
	m_osWrite.hEvent = NULL;
	

	//20120206  SinoEwack
	memset(&m_osWrite,  0,  sizeof(OVERLAPPED));
	memset(&m_osRead,  0,  sizeof(OVERLAPPED));
	m_hReadThread = CreateEvent(NULL,TRUE,FALSE,NULL);
	m_osRead.hEvent  =  CreateEvent(  NULL,  TRUE,  FALSE,  NULL  );   
	m_osWrite.hEvent  =  CreateEvent(  NULL,  TRUE,  FALSE,  NULL ); 
	m_hShutCommEvent = CreateEvent(NULL,TRUE,FALSE,NULL);

	m_nSendCount = 0;
}
CCESerialPort::~CCESerialPort()
{
	ClosePort();
	CloseHandle(m_osWrite.hEvent);
	CloseHandle(m_osRead.hEvent);
	CloseHandle(m_hReadThread);
	CloseHandle(m_hShutCommEvent);
}

//接收数据线程
DWORD WINAPI CCESerialPort::ReadPortThread(LPVOID lpParameter)
{
	CCESerialPort* m_pSerial;

	m_pSerial=(CCESerialPort*)lpParameter;

	BOOL fReadState;
	DWORD dwLength;

	char* buf=new char[m_pSerial->m_nBufferSize];
	memset(buf, '\n', sizeof(m_pSerial->m_nBufferSize));

	DWORD   dwEvtMask;    
	HANDLE  EventWait[2];    
	OVERLAPPED  os;             //声明成局部变量
	memset(&os,0,sizeof(OVERLAPPED));                 //  初始化  
	os.hEvent = CreateEvent(NULL,TRUE,FALSE,NULL);    //生成事件
	EventWait[0] = os.hEvent;
	EventWait[1] = m_pSerial->m_hReadThread;

	while((m_pSerial->m_hComm!=INVALID_HANDLE_VALUE)&&(m_pSerial->m_bReceiving))
	{
		if(WaitForMultipleObjects(2,m_pSerial->m_hEvent,FALSE,INFINITE) == 0 /*WAIT_OBJECT_0*/)
		{
			CloseHandle(m_pSerial->m_hComm);
			m_pSerial->m_hComm=NULL;
			m_pSerial->m_hReadThread = NULL;
			m_pSerial->m_bReceiving = FALSE;
			AfxEndThread(100);
			return 0;
		}
		
		WaitCommEvent(m_pSerial->m_hComm, &dwEvtMask,&os); 
		if(WaitForSingleObject(os.hEvent,20) == WAIT_TIMEOUT)  //防止串口无时间发生时，线程一直在等时间发生挂掉
		{
			ResetEvent(os.hEvent);
			continue;
		}
		if( (dwEvtMask & EV_RXCHAR) != EV_RXCHAR )   //没有触发接收字符事件，重置串口事件后继续等待读串口事件
		{
			ResetEvent(os.hEvent);
			continue;
		}
	
		if(WaitForMultipleObjects(2,EventWait,FALSE,INFINITE) == WAIT_OBJECT_0) 
		{
			COMSTAT  ComStat;    //  串口状态结构  
			DWORD  dwErrorFlags;  
			ClearCommError(m_pSerial->m_hComm, &dwErrorFlags, &ComStat);   //对串口读之前应先使用ClearCommError函数清除错误    
			if( (dwEvtMask & EV_RXCHAR) == EV_RXCHAR )  // 触发了接收字符事件才进行读串口
			{
				//异步重叠I/O  读串口立即返回   返回FALSE有可能是进入后台读串口  
				fReadState = ReadFile(m_pSerial->m_hComm,buf,m_pSerial->m_nBufferSize,&dwLength,&m_pSerial->m_osRead);
				if(!fReadState)
				{
					if(  GetLastError()  ==  ERROR_IO_PENDING)    // ERROR_IO_PENDING  为读串口操作未完成，仍在后台读串口  
					{
						if (!GetOverlappedResult(m_pSerial->m_hComm,  &m_pSerial->m_osRead,  &dwLength,  TRUE))  //  挂起，直到读串口操作完成
						{
							ClearCommError(m_pSerial->m_hComm,  &dwErrorFlags,  &ComStat);
							//PurgeComm(m_pSerial->m_hComm,PURGE_RXCLEAR);
						}
					}
					
				}//end  if(!fReadState)
				if(dwLength!=0)
				{



					//test_fasong 南方命令 begin
					//std::string strData;
					//strData.append(buf, dwLength-2);
					//strData[0]='@';
					//strData.append(",OK");
					//strData.append(buf+dwLength-2,2);
					//m_pSerial->WritePort((char *)strData.c_str(), strData.length());

					////device.update.begin
					//if(m_pSerial->m_nSendCount==1)
					//{
					//	std::string strFile;
					//	BinPackage package;
					//	memset(&package, 0, sizeof(package));
					//	memcpy(buf, &package, dwLength-5);

					//	unsigned short nLenth=0;
					//	memcpy(&nLenth, package.length, sizeof(package.length));
					//	strFile.append((const char *)package.data, nLenth);

					//	//device.update.end
					//	strData = "@sic,,set,device.update.end,ok\r\n";
					//	m_pSerial->WritePort((char *)strData.c_str(), strData.length());
					//}					

					//std::string strTmp;
					//strTmp.append(buf+10, 19);
					//if(strTmp=="device.update.begin")
					//{
					//	m_pSerial->m_nSendCount++;
					//}
					//test_fasong 南方命令 end
				

					if (m_pSerial->m_hSendWnd!=NULL)
					{
						::SendMessage(m_pSerial->m_hSendWnd, m_pSerial->m_nMsgID, WPARAM(buf),	dwLength);
					}
					if (m_pSerial->m_bSetOtherSendWnd)
					{
						if (m_pSerial->m_hOtherSendWnd!=NULL)
						{
							::SendMessage(m_pSerial->m_hOtherSendWnd, m_pSerial->m_nOtherMsgID, WPARAM(buf),	dwLength);
						}
					}
				}

				ResetEvent(m_pSerial->m_osRead.hEvent);   //手动重置一次读事件为无信号
			}
		}//end if(WaitForMultipleObjects()) 		
		ResetEvent(os.hEvent);
		ResetEvent(m_pSerial->m_osRead.hEvent);   //手动重置一次读事件为无信号
	}//end while
	delete []buf;

	return 0;
}

BOOL CCESerialPort::OpenPort(LPCTSTR Port,int BaudRate,int DataBits,int StopBits,int Parity)//,LPDataArriveProc proc,DWORD userdata)
{
	if (m_hComm != NULL)
	{
		CloseHandle(m_hComm);
		m_hComm = NULL;
	}

	CString strPort = Port;
	int nPortNo=0;
	strPort = strPort.Right(strPort.GetLength()-3);
	char cPort[3];
	wcstombs(cPort,strPort,3);
	nPortNo = atoi(cPort);

	//2008.07.09,打开10以上的串口
	if (nPortNo>=10)
	{
		strPort.Format(L"\\\\.\\COM%d",nPortNo);
	}
	else
	{
		strPort.Format(L"COM%d:", nPortNo);
	}


	//210120206  SinoEwack
	SetEvent(m_osWrite.hEvent);  //设置写串口事件为有信号
	
	m_hComm = CreateFile(Port,
		GENERIC_READ|GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING, 
		FILE_FLAG_OVERLAPPED,//0,//FILE_ATTRIBUTE_NORMAL|FILE_FLAG_OVERLAPPED,
		NULL);

	DWORD n = GetLastError();

	if(m_hComm==INVALID_HANDLE_VALUE )
	{
		//CloseHandle(m_hComm);
		return FALSE;
	}

	GetCommState(m_hComm,&dcb);
	dcb.BaudRate = BaudRate;
	dcb.ByteSize = DataBits;
	dcb.Parity = Parity;
	dcb.StopBits = StopBits;

	dcb.fParity = FALSE;
	dcb.fBinary = TRUE;
	dcb.fDtrControl = 0;
	dcb.fRtsControl = 0;
	dcb.fOutX = dcb.fInX = dcb.fTXContinueOnXoff = 0;

	//-----------------------------------------------------------------------
	//改变DCB结构设置
	/*	dcb.BaudRate = BaudRate;            //波特率 
	dcb.fBinary = TRUE;                 //Win32不支持非二进制串行传输模式，必须为TRUE 
	dcb.fParity = TRUE;                 //启用奇偶校验 
	dcb.fOutxCtsFlow = FALSE;            //串行端口的输出由CTS线控制
	dcb.fOutxDsrFlow = FALSE;           //关闭串行端口的DSR流控制 
	dcb.fDtrControl = DTR_CONTROL_ENABLE;   //启用DTR线
	dcb.fDsrSensitivity = FALSE;        //如果设为TRUE将忽略任何输入的字节，除非DSR线被启用 
	dcb.fTXContinueOnXoff = TRUE;       //当为TRUE时，如果接收缓冲区已满且驱动程序已传送XOFF字符，将使驱动程序停止传输字符
	dcb.fTXContinueOnXoff = FALSE;
	dcb.fOutX = FALSE;                  //设为TRUE指定XON/XOFF控制被用于控制串行输出 
	dcb.fInX = FALSE;                   //设为TRUE指定XON/XOFF控制被用于控制串行输入 
	dcb.fErrorChar = FALSE;             //WINCE串行驱动程序的默认执行将忽略这个字段 
	dcb.fNull = FALSE;                  //设为TRUE将使串行驱动程序忽略收到的空字节 
	dcb.fRtsControl = RTS_CONTROL_ENABLE;   //启用RTS线 
	dcb.fAbortOnError = FALSE;          //WINCE串行驱动程序的默认执行将忽略这个字段
	dcb.ByteSize = 8;                   //每字节的位数 
	dcb.Parity = NOPARITY;              //无奇偶校验 
	dcb.StopBits = ONESTOPBIT;          //每字节一位停止位 */
	//-----------------------------------------------------------------------

	//设置状态参数
	SetCommMask(m_hComm,EV_RXCHAR|EV_CTS|EV_ERR);		
	SetupComm(m_hComm,16384,16384);		
	if(!SetCommState(m_hComm,&dcb))
	{
		MessageBox(NULL,_T("Can to setup parameter!"),L"Tip",MB_ICONINFORMATION);
		PurgeComm(m_hComm,PURGE_TXCLEAR|PURGE_RXCLEAR);
		ClosePort();
		return FALSE;
	}

	//设置超时参数
	GetCommTimeouts(m_hComm,&CommTimeOuts);		
	CommTimeOuts.ReadIntervalTimeout = 100;
	CommTimeOuts.ReadTotalTimeoutMultiplier = 1;
	CommTimeOuts.ReadTotalTimeoutConstant = 100;
	CommTimeOuts.WriteTotalTimeoutMultiplier = 100;
	CommTimeOuts.WriteTotalTimeoutConstant = 100;		
	if(!SetCommTimeouts(m_hComm,&CommTimeOuts))
	{
		MessageBox(NULL,_T("Can not to setup parameter"),L"Tip",MB_ICONINFORMATION);
		PurgeComm(m_hComm,PURGE_TXCLEAR|PURGE_RXCLEAR);
		ClosePort();
		return FALSE;
	}

	PurgeComm(m_hComm,PURGE_TXCLEAR|PURGE_RXCLEAR);	

	//设置端口上指定信号的状态 
	// SETDTR: 发送DTR (data-terminal-ready)信号
	// SETRTS: 发送RTS (request-to-send)信号
	EscapeCommFunction (m_hComm, SETDTR);
	EscapeCommFunction (m_hComm, SETRTS);

	Activate();

	return TRUE;
}

//[2010.09.03XB]正常工作中,数据中断,需要及时关闭串口,否则死机
//但关闭时,不能CLOSEHANDLE串口句柄,所以独立一个函数
BOOL CCESerialPort::Close_DataAbend() 
{
	Deactivate();

	if(m_hComm!=INVALID_HANDLE_VALUE)
	{
		//[2010.09.09XB]以上两句代码修改为以下三句代码
		SetCommMask(m_hComm,0);  
		EscapeCommFunction( m_hComm, CLRDTR | CLRRTS ) ;
		PurgeComm(m_hComm,PURGE_TXABORT | PURGE_RXABORT |
			PURGE_TXCLEAR | PURGE_RXCLEAR );

		m_hComm = INVALID_HANDLE_VALUE;

		return TRUE;
	}
	else
	{
		return FALSE;	
	}
}

BOOL CCESerialPort::ClosePort()
{
	SetEvent(m_hShutCommEvent);
	return TRUE;
}

//调用打开串口函数后,使用该函数开启接收线程
BOOL CCESerialPort::Activate()
{
	if(m_hComm==INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	//调用打开串口函数后,使用该函数开启接收线程
	if(!m_bReceiving)
	{
		//开始接收线程
		PurgeComm(m_hComm,PURGE_TXCLEAR|PURGE_RXCLEAR);
		m_bReceiving = TRUE;
		//设置事件状态后再启动读串口线程
		ResetEvent(m_osRead.hEvent);   //初始化串口读事件为无信号
		if (m_hReadThread == NULL)
		{
			m_hReadThread = CreateEvent(NULL,TRUE,FALSE,NULL);
		}
		SetEvent(m_hReadThread);      //初始化读串口线程事件为有信号
		ResetEvent(m_hShutCommEvent); //初始化关闭串口事件为无信号
		m_hEvent[0] = m_hShutCommEvent;
		m_hEvent[1] = m_hReadThread;
		m_hReadThread = CreateThread(NULL,0,ReadPortThread,this,0,NULL);
	}

	if(m_hReadThread!=NULL)
	{		
		return TRUE;
	}
	else
	{
		m_bReceiving = FALSE;
		return FALSE;
	}

	return FALSE;
}

BOOL CCESerialPort::Deactivate()
{
	if(m_hComm==INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	//停止接收线程
	if(m_bReceiving)
	{
		m_bReceiving = FALSE;
		WaitForSingleObject(m_hReadThread,500);
		CloseHandle(m_hReadThread);
		m_hReadThread = NULL;
		return TRUE;
	}

	return FALSE;
}

BOOL CCESerialPort::IsActive()
{
	return m_bReceiving;
}

DWORD CCESerialPort::WritePort(char *data,int length)
{
	if(m_hComm==INVALID_HANDLE_VALUE)
	{
		return 0;
	}
	//Buffer = data;
	BOOL fWriteState;
	DWORD dwBytesWritten=0;

	DWORD dwCharToWrite;
	dwCharToWrite = length*sizeof(char);
 
	COMSTAT  ComStat;
	DWORD   dwErrorFlags; 

	if(!WriteFile(m_hComm,data,dwCharToWrite,&dwBytesWritten,&m_osWrite))  //异步I/O  立即返回，未完成数据发送时返回FALSE，由后台进行发送；
	{
		if(  GetLastError()  ==  ERROR_IO_PENDING)   //重叠I/O未完成    
			if (!GetOverlappedResult(m_hComm, &m_osWrite, &dwCharToWrite, TRUE))  //挂起，直到操作完成  
			{
				ClearCommError(m_hComm, &dwErrorFlags, &ComStat); 
				PurgeComm(m_hComm,PURGE_TXCLEAR);
			}
	}
	return dwBytesWritten;
}

DWORD CCESerialPort::WritePort(BYTE *buf, DWORD dwCharToWrite)
{
	if(m_hComm==INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	BOOL fWriteState;
	DWORD dwBytesWritten=0;
 
	COMSTAT  ComStat;
	DWORD   dwErrorFlags; 

	if(!WriteFile(m_hComm,buf,dwCharToWrite,&dwBytesWritten,&m_osWrite))
	{
		if(  GetLastError()  ==  ERROR_IO_PENDING)       
			if (!GetOverlappedResult(m_hComm,  &m_osWrite,  &dwCharToWrite,  TRUE))  //  挂起，直到操作完成  m_osWrite.hEvent被重置后才返回
			{
				ClearCommError(m_hComm,  &dwErrorFlags,  &ComStat); 
			}
	} 

	return dwBytesWritten;
}

//////////////////////////////////////////////////////////////////////////
//功能：发送命令
//输入：strSend——发送的命令
//输出：无
//返回：如果发送成功，返回TRUE，否则返回FALSE
//日期：2006.05.08
//////////////////////////////////////////////////////////////////////////
BOOL CCESerialPort::WritePort(CString strSend)
{
	//2007.10.18, 增加
	strSend += "\r\n";

	char * buf;
	int bufLen = strSend.GetLength()+2;
	buf = new char[bufLen];

	//复制命令
	int length = strSend.GetLength();
	wcstombs(buf,strSend,length);

	BOOL bSucess = FALSE;
	if (WritePort(buf,strSend.GetLength()))
	{
		bSucess = TRUE;
		if (m_hOtherSendWnd!=NULL)
		{
			::SendMessage(m_hOtherSendWnd, WM_PORT_SEND_CMD,  WPARAM(buf),
				length);
		}
	}

	delete []buf;
	return bSucess;
}

DWORD CCESerialPort::ReadPort(char *data,int length)
{
	BOOL fReadState;
	DWORD dwLength,dwBytesRead;
	int TimeOutCount;

	dwBytesRead=0;
	TimeOutCount=0;

	char *buf;
	while(m_hComm!=INVALID_HANDLE_VALUE)
	{
		buf=new char[length];
		//fReadState=ReadFile(m_hComm,data,length,&dwLength,NULL);
		//20120203  SinoEwack
		fReadState=ReadFile(m_hComm,data,length,&dwLength,&m_osRead);   //异步

		if(!fReadState)
		{
			break;
		}
		else
		{
			dwBytesRead+=dwLength;
			data+=dwLength;			
		}
		if(dwBytesRead==length)
		{
			break;
		}
		if(dwLength!=0)
		{
			TimeOutCount=0;
		}
		else
		{
			TimeOutCount++;
			Sleep(5);
		}
		if(TimeOutCount==5)
		{
			break;
		}
	}

	delete []buf;

	return dwBytesRead;
}

DWORD CCESerialPort::WriteFileToPort(LPCTSTR FileName)
{
	if(m_hComm==INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	CFile cf;

	BOOL fWriteState;
	DWORD dwBytesWritten;
	DWORD dwCharToWrite;

	dwCharToWrite=0;

	if(!cf.Open(FileName,CFile::modeRead))
	{

		return 0;
	}
	dwCharToWrite=(DWORD)cf.GetLength();
	cf.Seek(0,CFile::begin);
	dwBytesWritten=0;

	if(m_hComm!=INVALID_HANDLE_VALUE&&dwCharToWrite!=0)
	{
		char* buf=new char[dwCharToWrite];
		cf.Read(buf,dwCharToWrite);

		fWriteState=WriteFile(m_hComm,buf,dwCharToWrite*sizeof(char),&dwBytesWritten,NULL);
		if(!fWriteState)
		{

		}
		delete []buf;		
	}
	cf.Close();
	return dwBytesWritten;
}

//////////////////////////////////////////////////////////////////////////
//功能：清除其他消息发送句柄
//输入：无
//输出：无
//返回：无
//日期：2006.07.28
//////////////////////////////////////////////////////////////////////////
void CCESerialPort::ClrOtherHwnd()
{
	m_hOtherSendWnd = NULL;

	m_bSetOtherSendWnd = FALSE;
}

//功能：获取当前打开的串口号
int CCESerialPort::GetCurPort()
{
	return m_nPort;
}

//功能：关闭串口
BOOL CCESerialPort::Close()
{
	return ClosePort();
}

//////////////////////////////////////////////////////////////////////////
//功能：判断端口是否打开
//输入：无
//输出：无
//返回：如果端口打开，返回TRUE，否则返回FALSE
//日期：2006.04.13
//////////////////////////////////////////////////////////////////////////
BOOL CCESerialPort::IsOpen()
{
	return IsActive();
}

//2008.11.05
//发送以空格分割命令体的16进制命令
//使用举例:串口调试中,输入十六进制命令(通用惯例都是以空格分割)
//topcon全站仪命令,由于topcon全站仪命令校验位和结束位的特殊性,
//直接使用"以空格分割的十六进制"命令形式
BOOL CCESerialPort::SendHexCmdBySpace(CString szCommand)
{
	char *token;
	char *tmpBuf; 

	int    nLength = szCommand.GetLength();
	tmpBuf = new char[nLength];
	wcstombs(tmpBuf,szCommand,nLength);

	//取出命令体,赋值给十六进制发送变量
	char hexCmdBuf[128]; //定义大些没关系,发送的时候带命令长度
	int    nCmdLength = 0;

	token = strtok(tmpBuf," ");
	while (token!=NULL)
	{
		char h,l;  //高位和低位
		int    nH,nL;
		h = token[0];
		l = token[1];

		nH = UseGetHexChar(h);
		nL = UseGetHexChar(l);
		if((nH>=16) || (nL>=16)) //超出范围,十六进制单个字符最大当然是F,即15
			break;
		else 
			nH = nH*16+nL;
		hexCmdBuf[nCmdLength] = (char)nH;
		nCmdLength++;

		token = strtok(NULL," ");
	}

	delete []tmpBuf;

	BOOL bSucessFlag = FALSE;

	bSucessFlag = WritePort(hexCmdBuf,nCmdLength);

	return bSucessFlag;
}

//////////////////////////////////////////////////////////////////////////
//功能：发送南方命令
//输入：Command——命令代号，Cmmand_var——命令参数
//输出：无
//返回：如果发送成功，返回True，否则返回False
//日期：2006.04.13
//////////////////////////////////////////////////////////////////////////
BOOL CCESerialPort::SendSOUTHCmd(unsigned char Command, CString Command_var)
{
	unsigned  char buf[1024], aa;
	char         buf1[1024], *po, buf2[10];	
	int            L,L1,i,num,num1,num2;

	memset(buf, 0, sizeof(buf));
	memset(buf1, 0, sizeof(buf1));
	memset(buf2, 0, sizeof(buf2));

	int length = Command_var.GetLength();

	wcstombs(buf1,Command_var,length);

	buf[0] = '$';
	buf[1] = Command; 
	buf[2] = buf[1]^0xFF;
	L = 0;
	L1 = 0;
	po = strtok(buf1," ");
	while (po!=NULL)
	{
		L++;
		strcpy(buf2,po);
		switch(buf2[0])
		{
		case 'A':
		case 'a':
			L1++;
			buf[4+L1] = buf2[1];
			break;
		case 'C':
		case 'c':
			L1++;
			//buf2[2] = 0;
			buf[4+L1] = atoi(&buf2[1]);
			break;
		case 'i':
		case 'I':
			num = atoi(&buf2[1]);
			L1++;
			buf[4+L1] = num-((num)/256)*256;
			L1++;
			buf[4+L1] = (num)/256;
			break;
		case 'L':
		case 'l':
			num = atol(&buf2[1]);
			num1 = num-((num)/(256*256))*256*256;  //低微
			num2 = (num)/(256*256);                //高位 

			L1++; buf[4+L1] = (num1)/256;
			L1++; buf[4+L1] = num1-((num1)/256)*256;

			L1++;  buf[4+L1] = (num2)/256;
			L1++;  buf[4+L1] = num2-((num2)/256)*256;
			break;
		}
		po = strtok(NULL," ");
	}
	buf[3] = L1-((L1)/256)*256;
	buf[4] = (L1)/256;

	aa = buf[0];
	for (i=1;i<L1+5;i++) 
		aa = aa^buf[i];
	buf[L1+5] = aa;

	//发送命令——2006.04.13
	BOOL bSuccessed=FALSE;

	bSuccessed = WritePort(buf, L1+6);

	return bSuccessed;
}

BOOL CCESerialPort::SetDTR(DWORD dwFunc)
{
	//设置DTR
	if (IsOpen())
	{
		return (EscapeCommFunction(m_hComm, dwFunc));
	}

	return false;
}

BOOL CCESerialPort::SetRTS(DWORD dwFunc)
{
	//设置DTR
	if (IsOpen())
	{
		return (EscapeCommFunction(m_hComm, dwFunc));
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////
//功能：设置消息发送句柄
//输入：hSendWnd——窗口句柄
//输出：无
//返回：无
//日期：2006.05.08
//////////////////////////////////////////////////////////////////////////
void CCESerialPort::SetHwnd(HWND hSendWnd, int nMsgID)
{
	m_hSendWnd = hSendWnd;

	m_nMsgID = nMsgID;
}

//////////////////////////////////////////////////////////////////////////
//功能：设置其他消息发送句柄
//输入：hSendWnd——窗口句柄
//输出：无
//返回：无
//日期：2007.07.28
//////////////////////////////////////////////////////////////////////////
void CCESerialPort::SetOtherHwnd(HWND hSendWnd, int nMsgID)
{
	m_hOtherSendWnd = hSendWnd;
	m_nOtherMsgID = nMsgID;
	m_bSetOtherSendWnd = TRUE;
}

//功能：打开串口
BOOL CCESerialPort::Open(int nPortNo, DWORD BaudRate,int DataBits,
						int StopBits,int Parity)
{
	CString strPort;
	ResetEvent(m_hReadThread);
	ResetEvent(m_hShutCommEvent);
	m_hEvent[1] = m_hReadThread;
	m_hEvent[0] = m_hShutCommEvent;

	if (m_hComm != NULL)
	{
		CloseHandle(m_hComm);
		m_hComm = NULL;
	}

	//2008.07.09,打开10以上的串口
	if (nPortNo>=10)
	{
		strPort.Format(L"\\\\.\\COM%d",nPortNo);
	}
	else
	{
		strPort.Format(L"COM%d:", nPortNo);
	}

	if (OpenPort(strPort, BaudRate, DataBits, StopBits, Parity))
	{
		m_nPort = nPortNo;

		return TRUE;
	} 
	else
	{
		//Error opening port
		CString szT;
		szT.LoadString(EG_STRTIP_FULL_OPENCOM_ERROR);
		//AfxMessageBox(szT);
		//CMessageBoxDlg dlg(szT);
		//dlg.DoModal();

		return FALSE;
	}
}

BOOL CCESerialPort::InitDCB(DWORD BaudRate)
{
	DCB PortDCB;
	DWORD dwError;
	PortDCB.DCBlength = sizeof (DCB);     

	//得到端口的默认设置信息
	GetCommState (m_hComm, &PortDCB);

	//改变DCB结构设置
	PortDCB.BaudRate = BaudRate;            //波特率 

	//根据DCB结构配置端口 
	if (!SetCommState (m_hComm, &PortDCB))
	{
		//不能配置串行端口
		MessageBox (NULL, TEXT("Unable to configure the serial port"), 
			TEXT("Error"), MB_OK);
		dwError = GetLastError ();
		return FALSE;
	}

	return TRUE;
}

//2008.07.15
//功能:关闭发送数据到其它窗口
void CCESerialPort::CloseOtherHwnd(void)
{
	m_hOtherSendWnd = FALSE;

	m_nOtherMsgID = -1;

	m_bSetOtherSendWnd = FALSE;
}

//2008.11.05,十六进制命令直发使用函数
//功能:将十六进制转换为十进制时,需要高位低位分别使用该函数
//然后组合得到十进制
//例AE变成174;30变成48
char CCESerialPort::UseGetHexChar(char c)
{
	if((c>='0')&&(c<='9'))
		return c-0x30;
	else if((c>='A')&&(c<='F'))
		return c-'A'+10;
	else if((c>='a')&&(c<='f'))
		return c-'a'+10;
	else 
		return 0x10;
}

//2008.11.25,发送南方命令
BOOL  CCESerialPort::SendRegCommand(unsigned char CmdID, int DataLen, CString DataStr)
{
	//[2009.12.24XB]今将数组大写改为1024
	unsigned char buf[1024];
	int   i;

	buf[0] = '$';
	buf[1] = CmdID;
	buf[2] = buf[1]^0xFF;

	for(i=0; i<DataLen; i++)
	{
		buf[i+5] = (BYTE)DataStr.GetAt(i);
	}

	buf[3] = DataLen-((DataLen)/256)*256;
	buf[4] = (DataLen)/256;	
	buf[DataLen+5] = buf[0];
	for (i=1;i<DataLen+5;i++) buf[DataLen+5] ^= buf[i];

	WritePort(buf,DataLen+6);

	return TRUE;	
}

//-------------------------------------------------------------------------------------------------------------
// 打开串口的另一个方法 [5/25/2011 moqinglu]
BOOL CCESerialPort::OpenSerialPort()
{
	m_hReadThread = CreateThread(NULL,0,OpenPortThread,this,0,NULL);

	int begion = GetTickCount();

	//等待5秒
	while ((GetTickCount() - begion < 2000) && !IsOpen())
	{
		::Sleep(100);
	}

	if (IsOpen() == TRUE)
	{
		m_bReceiving = FALSE;
		return TRUE;
	}
	else
		return IsOpen();
	//ClosePort();
}
DWORD WINAPI CCESerialPort::OpenPortThread(LPVOID lpParameter)
{
	CCESerialPort* m_pSerial;

	m_pSerial=(CCESerialPort*)lpParameter;


	char* buf=new char[m_pSerial->m_nBufferSize];

	ASSERT(m_pSerial); 
	//ASSERT(m_pSerial->m_hSendWnd!=NULL);   

	CString strPort;

	//2008.07.09,打开10以上的串口
	if (m_pSerial->m_nPort>=10)
	{
		strPort.Format(_T("\\\\.\\COM%d"),m_pSerial->m_nPort);
	}
	else
	{
		strPort.Format(_T("COM%d:"), m_pSerial->m_nPort);
	}

	if (!m_pSerial->OpenPort2(strPort, m_pSerial->m_nBaudrate, m_pSerial->m_nDataBits,m_pSerial->m_nStopBits ,m_pSerial->m_nParity))
	{
		CString strOpenError, strOpenErrorTip;
		return FALSE;
	}
	else
	{
		m_pSerial->m_bReceiving = TRUE;
	}

	delete[] buf;

	return 0;
}
BOOL CCESerialPort::OpenPort2(LPCTSTR Port,int BaudRate,int DataBits,int StopBits,int Parity)//,LPDataArriveProc proc,DWORD userdata)
{
	m_hComm = CreateFile(Port,GENERIC_READ|GENERIC_WRITE,0,0,OPEN_EXISTING,0,0);

	if(m_hComm==INVALID_HANDLE_VALUE )
	{
		return FALSE;
	}

	GetCommState(m_hComm,&dcb);
	dcb.BaudRate = BaudRate;
	dcb.ByteSize = DataBits;
	dcb.Parity = Parity;
	dcb.StopBits = StopBits;

	dcb.fParity = FALSE;
	dcb.fBinary = TRUE;
	dcb.fDtrControl = 0;
	dcb.fRtsControl = 0;
	dcb.fOutX = dcb.fInX = dcb.fTXContinueOnXoff = 0;


	//设置状态参数
	SetCommMask(m_hComm,EV_RXCHAR);		
	SetupComm(m_hComm,16384,16384);		
	if(!SetCommState(m_hComm,&dcb))
	{
		MessageBox(NULL,_T("Can to setup parameter!"),L"Tip",MB_ICONINFORMATION);
		PurgeComm(m_hComm,PURGE_TXCLEAR|PURGE_RXCLEAR);
		ClosePort();
		return FALSE;
	}

	//设置超时参数
	GetCommTimeouts(m_hComm,&CommTimeOuts);		
	CommTimeOuts.ReadIntervalTimeout = 100;
	CommTimeOuts.ReadTotalTimeoutMultiplier = 1;
	CommTimeOuts.ReadTotalTimeoutConstant = 100;
	CommTimeOuts.WriteTotalTimeoutMultiplier = 100;
	CommTimeOuts.WriteTotalTimeoutConstant = 100;		
	if(!SetCommTimeouts(m_hComm,&CommTimeOuts))
	{
		MessageBox(NULL,_T("Can not to setup parameter"),L"Tip",MB_ICONINFORMATION);
		PurgeComm(m_hComm,PURGE_TXCLEAR|PURGE_RXCLEAR);
		ClosePort();
		return FALSE;
	}

	PurgeComm(m_hComm,PURGE_TXCLEAR|PURGE_RXCLEAR);	

	//设置端口上指定信号的状态 
	EscapeCommFunction (m_hComm, SETDTR);
	EscapeCommFunction (m_hComm, SETRTS);


	return TRUE;
}
void CCESerialPort::SetComPar(int nPort, int nBaud,int nDataBits, 
							  int nStopBits,int Parity)
{
	//设置串口参数
	m_nPort = nPort;
	m_nBaudrate = nBaud;
	m_nParity = Parity;
	m_nDataBits = nDataBits;
	m_nStopBits = nStopBits;
}

void CCESerialPort::SetComBaudrate(int nBaud)
{
	GetCommState(m_hComm,&dcb);
	dcb.BaudRate = nBaud;
	SetCommState(m_hComm,&dcb);
	SetCommTimeouts(m_hComm,&CommTimeOuts);
	PurgeComm(m_hComm,PURGE_TXCLEAR|PURGE_RXCLEAR);
	EscapeCommFunction (m_hComm, SETDTR);
	EscapeCommFunction (m_hComm, SETRTS);
}
//-------------------------------------------------------------------------------------------------