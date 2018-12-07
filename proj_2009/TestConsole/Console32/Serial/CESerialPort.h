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
//CE����ͨѶ��
class CCESerialPort
{
public:
	CCESerialPort(void);
	~CCESerialPort(void);

	//����
public:

	//�򿪺͹رմ���---------------------------------------------------------------------------
	//������,EGStar�򿪴��ڵ��øú���
	BOOL Open(int nPortNo, DWORD BaudRate=9600, int DataBits=8,int StopBits=ONESTOPBIT,int Parity=NOPARITY);
	//������,EGStar�رմ��ڵ��øú���
	BOOL Close();

	//[2010.09.03XB]����������,�����ж�,��Ҫ��ʱ�رմ���,��������
	//���ر�ʱ,����CLOSEHANDLE���ھ��,���Զ���һ������
	BOOL Close_DataAbend();  

	//ʵ�ִ򿪴���
	BOOL OpenPort(LPCTSTR Port,int Baudrate=9600,int DataBits=8,
		int StopBits=ONESTOPBIT,int Parity=NOPARITY); //,LPDataArriveProc proc=NULL,DWORD userdata=0); 
	BOOL ClosePort(); //ʵ�ֹرմ���

	BOOL IsOpen(); //�����Ƿ��Ѿ���


	//������ֹͣ�߳�----------------------------------------------------------
	BOOL Activate();//�򿪴��ں�,ʹ�øú������������߳�
	BOOL Deactivate(); //�رմ��ں�,ʹ�øú���ֹͣ�����߳�
	BOOL IsActive();  //�жϵ�ǰ�Ƿ��Ѿ��򿪴���;�򿪴���ʱ��,�����������Ҫ�ȹر�

	//ʵ�ֽ��մ��������̺߳���,���պ�ͨ����Ϣ���͸�������
	static DWORD WINAPI ReadPortThread(LPVOID lpParameter);


	//���������-----------------------------------------------------------------------------
	//ʹ������,���Է��Ͳ�ͬ���͵�����
	DWORD WritePort(char *data,int length); //��������
	DWORD WritePort(BYTE *buf, DWORD dwCharToWrite);
	BOOL     WritePort(CString strSend);
	//����,�����Ϸ�����
	BOOL     SendSOUTHCmd(unsigned char Command, CString Command_var);
	//����,�����Ϸ�����
	BOOL     SendRegCommand(unsigned char CmdID, int DataLen, CString DataStr);

	//2008.11.05������
	//����:���Ϳո�ָ��������16��������
	BOOL     SendHexCmdBySpace(CString szCommand);
	char      UseGetHexChar(char c);

	//���û��������������Ϣ���͵�Ŀ�ľ��
	void       ClrOtherHwnd();
	void       SetHwnd(HWND hSendWnd, int nMsgID);
	void       SetOtherHwnd(HWND hSendWnd, int nMsgID);
	void       CloseOtherHwnd(void);


	//��������-----------------------------------------------------------------------
	BOOL     InitDCB(DWORD BaudRate);
	DWORD ReadPort(char *data,int length); //��ȡһ�����ȵ�����
	int         GetCurPort();
	BOOL     SetDTR(DWORD dwFunc);
	BOOL     SetRTS(DWORD dwFunc);
	DWORD WriteFileToPort(LPCTSTR FileName); //�����ļ�

	//����
public:
	int	          m_nPort;		//��ǰ�򿪴��ں�

	HWND     m_hSendWnd;	//������Ϣ���

	HWND     m_hOtherSendWnd;	//������Ϣ���;��
	BOOL       m_bSetOtherSendWnd;//������Ϣ���;�����ñ�־

	int           m_nMsgID;
	int           m_nOtherMsgID;

	int		m_nSendCount;//device.update.end

public:
	HANDLE   m_hComm;         //�����豸handle
	HANDLE   m_hReadThread; //�������߳�handle
	BOOL       m_bReceiving;     //�Ƿ��������
	int           m_nBufferSize;    //�����С,һ�ζ�ȡ�����еĶ����ֽ�����

	//���������Լ���ʱ����
	DCB                     dcb;  //���ڲ�������
	COMMTIMEOUTS   CommTimeOuts;  //���ڳ�ʱ��������

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


	//20120203  SinoEwack    �����ڸ�Ϊ�����ݵ�����ȥ�����ڣ����첽�ķ�ʽ�򿪴���
	OVERLAPPED m_osRead,m_osWrite;
	HANDLE m_hShutCommEvent;
	void SetComBaudrate(int nBaud);
};
