#pragma once
#include <iostream>
#include <string>
#include <sstream>

/*
//////////////////////////////////////////////////////
	�������
		�״�ͨ�Ų�����9600(ok)
		S128=0 ����400MHz Narrow Band Modem
		S128=1 ����900MHz Frequency Hopping Modem
		S128=2 ����400MHz Frequency Hopping Modem
		
		S102=5		�ִ��ڲ�����19200		
		S103=3		���в�����230000
		AT&V<ENTER> //��ʾ��ǰ����
//////////////////////////////////////////////////////
//��Ҫ��4.3.8 ��5.3.8 Everyone-to-Everyone
		4.3.8
			Master //����+++���� �����Ķ�ҪENTER
				+++ 	//enter into Command Mode  					ok ��Ҫ���� 9600  ֮��Ҫ��1��2�룿��
				AT&F1	//load the &F1 factory default settings   	AT&F1<ENTER>
				S133=2	//change the Network Type(S133) to 2  		ATS133=2<ENTER>
				S113=0	//change Packet Retransmissions(S113) from 5 to 0 (increase from 0 if required)		ATS113=2<ENTER>
				AT&W	//save the change using the AT&W command	AT&W<ENTER>
				ATA  	//go online with the ATA command 			ATA<ENTER>
			Slaves
				enter into Command Mode
				AT&F2
				S133=2
				S105=2 //Unit Address
				//Destination Address 65535
				AT&W
				ATA
			
		5.0 ����/��Ԫģʽ
			5.1.1 ����ģʽ
			1.
			2.
				AT&V ��ʾ��ǰ����
			5.3.2
				AT&F1 - FH Master Fast PMP
				AT&F1 - FH Slave Fast PMP
				
				//AT&F1
				
				S105=1		��Զ�������е�ÿ����λ������һ�����صĵ�λ��ַ�����豸���Զ�����Ϊ1,��Ӧ�øı䡣//���豸�Զ�����Ϊ2��Ӧ�����Ŵ��豸�����Ӷ��ı䣻
				S140=65535	NetWork ID:default is 65535 means data is broadcast from the Master to all other units.//��
				S101=0		����ģʽ���嵥Ԫ���� �����Master ������Ϊ0��//���豸Ϊ2
				S103=2		���������ٶȱ�������Ϊϵͳ��ÿ����Ԫ��ֵ��ͬ�����������������ܻᵼ�¸��ߵ�������,�����ʽϵ͵�����ͨ���ṩ���õ������Ժ������³���ԡ�//��ͬ
				S133=5		NetWork Type:��������Ϊ��Զ�����ʱ��������Ϊ0��AT&V��������ʾ�����ݻ���Ϊ�������͵Ĳ�ͬ����ͬ��//��ͬ
				S102=7		���ڲ����ʣ����ݸ�ʽ S110������ƥ�����ӵ��豸��//��ͬ
				S104=1234567890	�������е�ÿ����Ԫ��������ͬ�������ַ��ǿ�ҽ��鲻Ҫʹ��Ĭ������Ϊ1234567890��ATS104=XXXXXXX ���������޸ġ�//��ͬ
				S141=0		���1�����м���������ϵͳ�У�����Ĵ���֪ͨ���豸����ֻ�����������ߵ硣//��
				
				//AT&F2
				S105=2		
				S140=1	
				S101=2		
				S103=2		
				S133=5		
				S102=7		
				S104=1234567890
				S141=0					
				
				S118=1 		������豸��ͨ��һ���м������ӣ����������м�����Ψһ��ַ��
			5.3.5 
				S248=100	Sync Timeout(4-65534)
			5.3.6
				S244=1		Channel Request Mode (Master and All Slaves)
				S251=10		Master Hop Allocation Timeout (2 or 3);
			5.3.7 Peer-to-Peer
			5.3.8 Everyone-to-Everyone
				Master
					+++
					AT&F1<ENTER>
					ATS128=2<ENTER>
					ATS133=2<ENTER>
					ATS113=0<ENTER>
					AT&W<ENTER>
					ATA<ENTER>
				Slaves
					+++
					AT&F2<ENTER>
					ATS128=2<ENTER>
					ATS133=2<ENTER>
					ATS105=2<ENTER>		//UA 2-65534
					ATS140=65535<ENTER>	//Destination Address
					AT&W<ENTER>
					ATA<ENTER>
			
			6.0
			6.1
*/
class CP400Cmd
{
public:
	CP400Cmd(void);
	~CP400Cmd(void);
public:
	static std::string GetOpenCmd();
	static std::string GetSaveChangeCmd();
	static std::string GetCloseCmd();
	
	static std::string GetATFnCmd(int nNum);
	static std::string GetATSnCmd(int nCmd, int nValue);
private:
	void Test();
};
