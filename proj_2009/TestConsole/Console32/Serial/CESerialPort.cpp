#include "../stdafx.h"
#include "CESerialPort.h"
#include <string>
//#include "MessageBoxDlg.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CCESerialPort::CCESerialPort()
{
	//��ʼ�����ɱ���
	m_hComm = INVALID_HANDLE_VALUE;

	m_hReadThread = NULL;
	m_bReceiving = FALSE;

	m_nBufferSize = 1024; //�����С

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

//���������߳�
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
	OVERLAPPED  os;             //�����ɾֲ�����
	memset(&os,0,sizeof(OVERLAPPED));                 //  ��ʼ��  
	os.hEvent = CreateEvent(NULL,TRUE,FALSE,NULL);    //�����¼�
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
		if(WaitForSingleObject(os.hEvent,20) == WAIT_TIMEOUT)  //��ֹ������ʱ�䷢��ʱ���߳�һֱ�ڵ�ʱ�䷢���ҵ�
		{
			ResetEvent(os.hEvent);
			continue;
		}
		if( (dwEvtMask & EV_RXCHAR) != EV_RXCHAR )   //û�д��������ַ��¼������ô����¼�������ȴ��������¼�
		{
			ResetEvent(os.hEvent);
			continue;
		}
	
		if(WaitForMultipleObjects(2,EventWait,FALSE,INFINITE) == WAIT_OBJECT_0) 
		{
			COMSTAT  ComStat;    //  ����״̬�ṹ  
			DWORD  dwErrorFlags;  
			ClearCommError(m_pSerial->m_hComm, &dwErrorFlags, &ComStat);   //�Դ��ڶ�֮ǰӦ��ʹ��ClearCommError�����������    
			if( (dwEvtMask & EV_RXCHAR) == EV_RXCHAR )  // �����˽����ַ��¼��Ž��ж�����
			{
				//�첽�ص�I/O  ��������������   ����FALSE�п����ǽ����̨������  
				fReadState = ReadFile(m_pSerial->m_hComm,buf,m_pSerial->m_nBufferSize,&dwLength,&m_pSerial->m_osRead);
				if(!fReadState)
				{
					if(  GetLastError()  ==  ERROR_IO_PENDING)    // ERROR_IO_PENDING  Ϊ�����ڲ���δ��ɣ����ں�̨������  
					{
						if (!GetOverlappedResult(m_pSerial->m_hComm,  &m_pSerial->m_osRead,  &dwLength,  TRUE))  //  ����ֱ�������ڲ������
						{
							ClearCommError(m_pSerial->m_hComm,  &dwErrorFlags,  &ComStat);
							//PurgeComm(m_pSerial->m_hComm,PURGE_RXCLEAR);
						}
					}
					
				}//end  if(!fReadState)
				if(dwLength!=0)
				{



					//test_fasong �Ϸ����� begin
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
					//test_fasong �Ϸ����� end
				

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

				ResetEvent(m_pSerial->m_osRead.hEvent);   //�ֶ�����һ�ζ��¼�Ϊ���ź�
			}
		}//end if(WaitForMultipleObjects()) 		
		ResetEvent(os.hEvent);
		ResetEvent(m_pSerial->m_osRead.hEvent);   //�ֶ�����һ�ζ��¼�Ϊ���ź�
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

	//2008.07.09,��10���ϵĴ���
	if (nPortNo>=10)
	{
		strPort.Format(L"\\\\.\\COM%d",nPortNo);
	}
	else
	{
		strPort.Format(L"COM%d:", nPortNo);
	}


	//210120206  SinoEwack
	SetEvent(m_osWrite.hEvent);  //����д�����¼�Ϊ���ź�
	
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
	//�ı�DCB�ṹ����
	/*	dcb.BaudRate = BaudRate;            //������ 
	dcb.fBinary = TRUE;                 //Win32��֧�ַǶ����ƴ��д���ģʽ������ΪTRUE 
	dcb.fParity = TRUE;                 //������żУ�� 
	dcb.fOutxCtsFlow = FALSE;            //���ж˿ڵ������CTS�߿���
	dcb.fOutxDsrFlow = FALSE;           //�رմ��ж˿ڵ�DSR������ 
	dcb.fDtrControl = DTR_CONTROL_ENABLE;   //����DTR��
	dcb.fDsrSensitivity = FALSE;        //�����ΪTRUE�������κ�������ֽڣ�����DSR�߱����� 
	dcb.fTXContinueOnXoff = TRUE;       //��ΪTRUEʱ��������ջ��������������������Ѵ���XOFF�ַ�����ʹ��������ֹͣ�����ַ�
	dcb.fTXContinueOnXoff = FALSE;
	dcb.fOutX = FALSE;                  //��ΪTRUEָ��XON/XOFF���Ʊ����ڿ��ƴ������ 
	dcb.fInX = FALSE;                   //��ΪTRUEָ��XON/XOFF���Ʊ����ڿ��ƴ������� 
	dcb.fErrorChar = FALSE;             //WINCE�������������Ĭ��ִ�н���������ֶ� 
	dcb.fNull = FALSE;                  //��ΪTRUE��ʹ����������������յ��Ŀ��ֽ� 
	dcb.fRtsControl = RTS_CONTROL_ENABLE;   //����RTS�� 
	dcb.fAbortOnError = FALSE;          //WINCE�������������Ĭ��ִ�н���������ֶ�
	dcb.ByteSize = 8;                   //ÿ�ֽڵ�λ�� 
	dcb.Parity = NOPARITY;              //����żУ�� 
	dcb.StopBits = ONESTOPBIT;          //ÿ�ֽ�һλֹͣλ */
	//-----------------------------------------------------------------------

	//����״̬����
	SetCommMask(m_hComm,EV_RXCHAR|EV_CTS|EV_ERR);		
	SetupComm(m_hComm,16384,16384);		
	if(!SetCommState(m_hComm,&dcb))
	{
		MessageBox(NULL,_T("Can to setup parameter!"),L"Tip",MB_ICONINFORMATION);
		PurgeComm(m_hComm,PURGE_TXCLEAR|PURGE_RXCLEAR);
		ClosePort();
		return FALSE;
	}

	//���ó�ʱ����
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

	//���ö˿���ָ���źŵ�״̬ 
	// SETDTR: ����DTR (data-terminal-ready)�ź�
	// SETRTS: ����RTS (request-to-send)�ź�
	EscapeCommFunction (m_hComm, SETDTR);
	EscapeCommFunction (m_hComm, SETRTS);

	Activate();

	return TRUE;
}

//[2010.09.03XB]����������,�����ж�,��Ҫ��ʱ�رմ���,��������
//���ر�ʱ,����CLOSEHANDLE���ھ��,���Զ���һ������
BOOL CCESerialPort::Close_DataAbend() 
{
	Deactivate();

	if(m_hComm!=INVALID_HANDLE_VALUE)
	{
		//[2010.09.09XB]������������޸�Ϊ�����������
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

//���ô򿪴��ں�����,ʹ�øú������������߳�
BOOL CCESerialPort::Activate()
{
	if(m_hComm==INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	//���ô򿪴��ں�����,ʹ�øú������������߳�
	if(!m_bReceiving)
	{
		//��ʼ�����߳�
		PurgeComm(m_hComm,PURGE_TXCLEAR|PURGE_RXCLEAR);
		m_bReceiving = TRUE;
		//�����¼�״̬���������������߳�
		ResetEvent(m_osRead.hEvent);   //��ʼ�����ڶ��¼�Ϊ���ź�
		if (m_hReadThread == NULL)
		{
			m_hReadThread = CreateEvent(NULL,TRUE,FALSE,NULL);
		}
		SetEvent(m_hReadThread);      //��ʼ���������߳��¼�Ϊ���ź�
		ResetEvent(m_hShutCommEvent); //��ʼ���رմ����¼�Ϊ���ź�
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

	//ֹͣ�����߳�
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

	if(!WriteFile(m_hComm,data,dwCharToWrite,&dwBytesWritten,&m_osWrite))  //�첽I/O  �������أ�δ������ݷ���ʱ����FALSE���ɺ�̨���з��ͣ�
	{
		if(  GetLastError()  ==  ERROR_IO_PENDING)   //�ص�I/Oδ���    
			if (!GetOverlappedResult(m_hComm, &m_osWrite, &dwCharToWrite, TRUE))  //����ֱ���������  
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
			if (!GetOverlappedResult(m_hComm,  &m_osWrite,  &dwCharToWrite,  TRUE))  //  ����ֱ���������  m_osWrite.hEvent�����ú�ŷ���
			{
				ClearCommError(m_hComm,  &dwErrorFlags,  &ComStat); 
			}
	} 

	return dwBytesWritten;
}

//////////////////////////////////////////////////////////////////////////
//���ܣ���������
//���룺strSend�������͵�����
//�������
//���أ�������ͳɹ�������TRUE�����򷵻�FALSE
//���ڣ�2006.05.08
//////////////////////////////////////////////////////////////////////////
BOOL CCESerialPort::WritePort(CString strSend)
{
	//2007.10.18, ����
	strSend += "\r\n";

	char * buf;
	int bufLen = strSend.GetLength()+2;
	buf = new char[bufLen];

	//��������
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
		fReadState=ReadFile(m_hComm,data,length,&dwLength,&m_osRead);   //�첽

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
//���ܣ����������Ϣ���;��
//���룺��
//�������
//���أ���
//���ڣ�2006.07.28
//////////////////////////////////////////////////////////////////////////
void CCESerialPort::ClrOtherHwnd()
{
	m_hOtherSendWnd = NULL;

	m_bSetOtherSendWnd = FALSE;
}

//���ܣ���ȡ��ǰ�򿪵Ĵ��ں�
int CCESerialPort::GetCurPort()
{
	return m_nPort;
}

//���ܣ��رմ���
BOOL CCESerialPort::Close()
{
	return ClosePort();
}

//////////////////////////////////////////////////////////////////////////
//���ܣ��ж϶˿��Ƿ��
//���룺��
//�������
//���أ�����˿ڴ򿪣�����TRUE�����򷵻�FALSE
//���ڣ�2006.04.13
//////////////////////////////////////////////////////////////////////////
BOOL CCESerialPort::IsOpen()
{
	return IsActive();
}

//2008.11.05
//�����Կո�ָ��������16��������
//ʹ�þ���:���ڵ�����,����ʮ����������(ͨ�ù��������Կո�ָ�)
//topconȫվ������,����topconȫվ������У��λ�ͽ���λ��������,
//ֱ��ʹ��"�Կո�ָ��ʮ������"������ʽ
BOOL CCESerialPort::SendHexCmdBySpace(CString szCommand)
{
	char *token;
	char *tmpBuf; 

	int    nLength = szCommand.GetLength();
	tmpBuf = new char[nLength];
	wcstombs(tmpBuf,szCommand,nLength);

	//ȡ��������,��ֵ��ʮ�����Ʒ��ͱ���
	char hexCmdBuf[128]; //�����Щû��ϵ,���͵�ʱ��������
	int    nCmdLength = 0;

	token = strtok(tmpBuf," ");
	while (token!=NULL)
	{
		char h,l;  //��λ�͵�λ
		int    nH,nL;
		h = token[0];
		l = token[1];

		nH = UseGetHexChar(h);
		nL = UseGetHexChar(l);
		if((nH>=16) || (nL>=16)) //������Χ,ʮ�����Ƶ����ַ����Ȼ��F,��15
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
//���ܣ������Ϸ�����
//���룺Command����������ţ�Cmmand_var�����������
//�������
//���أ�������ͳɹ�������True�����򷵻�False
//���ڣ�2006.04.13
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
			num1 = num-((num)/(256*256))*256*256;  //��΢
			num2 = (num)/(256*256);                //��λ 

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

	//���������2006.04.13
	BOOL bSuccessed=FALSE;

	bSuccessed = WritePort(buf, L1+6);

	return bSuccessed;
}

BOOL CCESerialPort::SetDTR(DWORD dwFunc)
{
	//����DTR
	if (IsOpen())
	{
		return (EscapeCommFunction(m_hComm, dwFunc));
	}

	return false;
}

BOOL CCESerialPort::SetRTS(DWORD dwFunc)
{
	//����DTR
	if (IsOpen())
	{
		return (EscapeCommFunction(m_hComm, dwFunc));
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////
//���ܣ�������Ϣ���;��
//���룺hSendWnd�������ھ��
//�������
//���أ���
//���ڣ�2006.05.08
//////////////////////////////////////////////////////////////////////////
void CCESerialPort::SetHwnd(HWND hSendWnd, int nMsgID)
{
	m_hSendWnd = hSendWnd;

	m_nMsgID = nMsgID;
}

//////////////////////////////////////////////////////////////////////////
//���ܣ�����������Ϣ���;��
//���룺hSendWnd�������ھ��
//�������
//���أ���
//���ڣ�2007.07.28
//////////////////////////////////////////////////////////////////////////
void CCESerialPort::SetOtherHwnd(HWND hSendWnd, int nMsgID)
{
	m_hOtherSendWnd = hSendWnd;
	m_nOtherMsgID = nMsgID;
	m_bSetOtherSendWnd = TRUE;
}

//���ܣ��򿪴���
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

	//2008.07.09,��10���ϵĴ���
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

	//�õ��˿ڵ�Ĭ��������Ϣ
	GetCommState (m_hComm, &PortDCB);

	//�ı�DCB�ṹ����
	PortDCB.BaudRate = BaudRate;            //������ 

	//����DCB�ṹ���ö˿� 
	if (!SetCommState (m_hComm, &PortDCB))
	{
		//�������ô��ж˿�
		MessageBox (NULL, TEXT("Unable to configure the serial port"), 
			TEXT("Error"), MB_OK);
		dwError = GetLastError ();
		return FALSE;
	}

	return TRUE;
}

//2008.07.15
//����:�رշ������ݵ���������
void CCESerialPort::CloseOtherHwnd(void)
{
	m_hOtherSendWnd = FALSE;

	m_nOtherMsgID = -1;

	m_bSetOtherSendWnd = FALSE;
}

//2008.11.05,ʮ����������ֱ��ʹ�ú���
//����:��ʮ������ת��Ϊʮ����ʱ,��Ҫ��λ��λ�ֱ�ʹ�øú���
//Ȼ����ϵõ�ʮ����
//��AE���174;30���48
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

//2008.11.25,�����Ϸ�����
BOOL  CCESerialPort::SendRegCommand(unsigned char CmdID, int DataLen, CString DataStr)
{
	//[2009.12.24XB]�������д��Ϊ1024
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
// �򿪴��ڵ���һ������ [5/25/2011 moqinglu]
BOOL CCESerialPort::OpenSerialPort()
{
	m_hReadThread = CreateThread(NULL,0,OpenPortThread,this,0,NULL);

	int begion = GetTickCount();

	//�ȴ�5��
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

	//2008.07.09,��10���ϵĴ���
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


	//����״̬����
	SetCommMask(m_hComm,EV_RXCHAR);		
	SetupComm(m_hComm,16384,16384);		
	if(!SetCommState(m_hComm,&dcb))
	{
		MessageBox(NULL,_T("Can to setup parameter!"),L"Tip",MB_ICONINFORMATION);
		PurgeComm(m_hComm,PURGE_TXCLEAR|PURGE_RXCLEAR);
		ClosePort();
		return FALSE;
	}

	//���ó�ʱ����
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

	//���ö˿���ָ���źŵ�״̬ 
	EscapeCommFunction (m_hComm, SETDTR);
	EscapeCommFunction (m_hComm, SETRTS);


	return TRUE;
}
void CCESerialPort::SetComPar(int nPort, int nBaud,int nDataBits, 
							  int nStopBits,int Parity)
{
	//���ô��ڲ���
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