#pragma once
#include <iostream>
#include <string>
#include <sstream>

/*
//////////////////////////////////////////////////////
	其他命令：
		首次通信波特率9600(ok)
		S128=0 ——400MHz Narrow Band Modem
		S128=1 ——900MHz Frequency Hopping Modem
		S128=2 ——400MHz Frequency Hopping Modem
		
		S102=5		现串口波特率19200		
		S103=3		空中波特率230000
		AT&V<ENTER> //显示当前设置
//////////////////////////////////////////////////////
//主要看4.3.8 、5.3.8 Everyone-to-Everyone
		4.3.8
			Master //除了+++不用 其他的都要ENTER
				+++ 	//enter into Command Mode  					ok 不要换行 9600  之后要等1到2秒？？
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
			
		5.0 配置/单元模式
			5.1.1 命令模式
			1.
			2.
				AT&V 显示当前配置
			5.3.2
				AT&F1 - FH Master Fast PMP
				AT&F1 - FH Slave Fast PMP
				
				//AT&F1
				
				S105=1		点对多点网络中的每个单位必须有一个独特的单位地址。主设备是自动设置为1,不应该改变。//从设备自动设置为2，应该随着从设备的增加而改变；
				S140=65535	NetWork ID:default is 65535 means data is broadcast from the Master to all other units.//？
				S101=0		操作模式定义单元类型 如果是Master 则设置为0；//从设备为2
				S103=2		无线连接速度必须设置为系统中每个单元的值相同。链接利率上升可能会导致更高的吞吐量,但利率较低的链接通常提供更好的敏感性和整体的鲁棒性。//相同
				S133=5		NetWork Type:网络类型为点对多点操作时必须设置为0。AT&V命令所显示的内容会因为网络类型的不同而不同。//相同
				S102=7		串口波特率（数据格式 S110）必须匹配连接的设备。//相同
				S104=1234567890	在网络中的每个单元必须有相同的网络地址。强烈建议不要使用默认设置为1234567890。ATS104=XXXXXXX 命令用于修改。//相同
				S141=0		如果1或多个中继器存在于系统中，这个寄存器通知主设备。这只适用于主无线电。//无
				
				//AT&F2
				S105=2		
				S140=1	
				S101=2		
				S103=2		
				S133=5		
				S102=7		
				S104=1234567890
				S141=0					
				
				S118=1 		如果从设备是通过一个中继器连接，在这输入中继器的唯一地址；
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
