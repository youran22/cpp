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

//int _tmain(int argc, _TCHAR* argv[]);
//main函数
int _tmain(int argc, _TCHAR* argv[])
{

	//CCESerialPort serial;
	//serial.Open(20);

	//file_open_test();

	test_string_all();

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

