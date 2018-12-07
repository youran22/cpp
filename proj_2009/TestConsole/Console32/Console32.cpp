// Console32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// TestConsole.cpp : Defines the entry point for the console application.
//
#pragma region
#pragma endregion
#include "stdafx.h"
#include <atlstr.h>//CString
#include <iostream>
#include <stdarg.h>
#include "Console32.h"
#include "sortfunctions.h"
#include "Serial/CESerialPort.h"
#include "Serial/CP400Cmd.h"
#include <conio.h>//getch 

//int _tmain(int argc, _TCHAR* argv[]);
//main函数
int _tmain(int argc, _TCHAR* argv[])
{

	CCESerialPort serial;
	//serial.Open(20);
	serial.Open(6);
	CP400Cmd cp400;
	std::string str;
	while(1)
	{
		std::cout << "请输入命令："<<endl;
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
		serial.WritePort((char *)str.c_str(), str.length());
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
	

	//file_open_test();

	//test_string_all();

	//double *pD = new double[100];
	//pD[0]=3;
	//cout<<pD[0]<<endl;

	//char ch[5]={0};
	//std::string str;
	//int nSize = sprintf_s(ch, 10, "%02X", 394);
	//str=ch;
	//cout<<str<<endl;

	//char *p=ch;
	//cout<<p<<endl;
	//char p2=ch[0];
	//cout<<p2<<endl;

	//cout<<p->left(2)<<endl;

	//test_math_insertSort();

	while(1);
	return 0;
}
void test_math_insertSort()
{
	//insertion_sort test :三要点：测试数据，过程调用，程序输出；
	//int *arr = {2,20,7,87,6,9,54};//？？
	int arr[7] = {2,20,7,87,6,9,54};
	insertion_sort(arr, 7);
	int i=0;
	while(i<7)
	{
		printf("%d,",arr[i++]);
	}

	//insertionSort test
	insertionSort(arr, 7, 4, int_greater);
}

void test_serial()
{
	
}

