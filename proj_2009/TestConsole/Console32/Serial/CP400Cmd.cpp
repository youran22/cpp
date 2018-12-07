#include "CP400Cmd.h"

CP400Cmd::CP400Cmd(void)
{
}

CP400Cmd::~CP400Cmd(void)
{
}

std::string CP400Cmd::GetOpenCmd()
{
	std::string str = "+++";
	return str;
}
std::string CP400Cmd::GetSaveChangeCmd()
{
	std::string str = "AT&W\r";
	return str;
}
std::string CP400Cmd::GetCloseCmd()
{
	std::string str = "ATA\r";
	return str;
}

std::string CP400Cmd::GetATFnCmd(int nNum)
{
	std::string str="AT&F";
	std::stringstream ssNum;
	ssNum<<nNum;
	str += ssNum.str();
	str += "\r";
	return str;
}
std::string CP400Cmd::GetATSnCmd(int nCmd, int nValue)
{
	std::string str="ATS";
	std::stringstream ssCmd, ssValue;
	ssCmd<<nCmd;
	ssValue<<nValue;
	str += ssCmd.str();
	str += "=";
	str += ssValue.str();
	str += "\r";
	return str;
}
void CP400Cmd::Test()
{
	//CCESerialPort serial;
	//serial.Open(6);
	CP400Cmd cp400;
	std::string str;
	while(1)
	{
		std::cout << "ÇëÊäÈëÃüÁî£º"<<endl;
		char ch = getch();
		switch(ch)
		{
		case '1':
			str = cp400.GetOpenCmd();
			break;
		case '2':
			str = cp400.GetATFnCmd(1);
			break;
		case '3':
			str = cp400.GetATSnCmd(128,2);
			break;
		case '4':
			str = cp400.GetATSnCmd(133,2);
			break;
		case '9':
			str = cp400.GetSaveChangeCmd();
			break;
		case '0':
			str = cp400.GetCloseCmd();
			break;
		case 'e':
			break;
		default:
			break;

		}
		std::cout<<ch<<endl;
		//serial.WritePort((char *)str.c_str(), str.length());
	}

	//master
	str = cp400.GetOpenCmd();
	str = cp400.GetATFnCmd(1);
	str = cp400.GetATSnCmd(128,2);
	str = cp400.GetATSnCmd(133,2);
	str = cp400.GetATSnCmd(113,0);
	str = cp400.GetSaveChangeCmd();
	str = cp400.GetCloseCmd();
	//slave
	str = cp400.GetATFnCmd(2);
	str = cp400.GetATSnCmd(128,2);
	str = cp400.GetATSnCmd(133,2);
	str = cp400.GetATSnCmd(105,2);
	str = cp400.GetATSnCmd(140,65535);
	str = cp400.GetSaveChangeCmd();
	str = cp400.GetCloseCmd();

}
