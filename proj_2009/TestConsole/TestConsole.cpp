// TestConsole.cpp : Defines the entry point for the console application.
//
#pragma region
#pragma endregion
#include "stdafx.h"
#include <atlstr.h>//CString
#include <iostream>


#pragma region W2A的用法
//#include "atlconv.h"
//USES_CONVERSION;
//missing type specifier - int assumed. Note: C++ does not support default-int
//error C2086: 'int _convert' : redefinition
#pragma endregion W2A的用法

#pragma region afxwin头文件包含错误
//#include <afxwin.h>//AfxMessageBxo
//afx.h(24) : fatal error C1189: #error :  Building MFC application with /MD[d] (CRT dll version) requires MFC shared dll version. Please #define _AFXDLL or do not use /MD[d]
#pragma endregion afxwin头文件包含错误

using namespace std;

int WideToMuti(char *p, wchar_t *wp)
{
	int nSize = ::WideCharToMultiByte(CP_ACP, 0, wp, -1, NULL, 0, NULL, FALSE);
	::WideCharToMultiByte(CP_ACP, 0, wp, nSize, p, nSize, NULL, FALSE);
	return 0;
}

#pragma region 指针的使用
//int c=30;
//int *copyString(int* p)//local function definitions are illegal
//{
//	int *temp = p;
//	p=&c;
//	return temp;
//}

#pragma endregion 指针的使用

void fun(int a,...)
{
	int *temp = &a;
	temp++;
	for (int i=0;i<a;++i)
	{
		cout<<*temp<<endl;
		temp++;
	}
}

//main函数
int _tmain(int argc, _TCHAR* argv[])
{

#pragma region va_start和va_end使用详解 
//'fun' : local function definitions are illegal
	int a=1;
	int b=2;
	int c=3;
	int d=4;
	fun(4,a,b,c,d);

#pragma endregion va_start和va_end使用详解 


#pragma region 指针的使用
	////int a=35;
	////int *pch = &a;
	//////int *copyString(int* p)//local function definitions are illegal
	//////{
	//////	int *temp = p;
	//////	*p=60;
	//////	return temp;
	//////}
	////int *pb = copyString(pch);
	////cout<<a<<endl;
	////cout<<*pch<<endl;
	////cout<<*pb<<endl;

	//class IncludeCharFunc
	//{
	//private:
	//	CString str1;
	//	CString str2;
	//	CString str3;
	//public:
	//	IncludeCharFunc(const char* p1, const char* p2, const char* p3)
	//	{
	//		str1 = CString(p1);
	//		str2 = CString(p2);
	//		str3 = CString(p3);
	//	}
	//public:
	//	int GetChar(char*& p1, char*& p2, char*& p3)
	//	{
	//		cout<<sizeof(p1)<<endl;
	//		WideToMuti(p1, str1.GetBuffer());
	//		WideToMuti(p2, str2.GetBuffer());
	//		WideToMuti(p3, str3.GetBuffer());
	//		return 0;
	//	}
	//};
	////char *p1 = NULL;
	////char *p2 = NULL;
	////char *p3 = NULL;
	////if(1)
	////{
	////	IncludeCharFunc inFunc("123","456","789");
	////	inFunc.GetChar(p1, p2, p3);
	////}
	////cout<<p1<<endl;
	////cout<<p2<<endl;
	////cout<<p3<<endl;
	////没有空间

	//char p1[128]={0};
	//char p2[128]={0};
	//char p3[128]={0};
	//char *p4 = &p1[0];
	//char *p5 = &p2[0];
	//char *p6 = &p3[0];//char*&的使用方法,但是这个是引用的表达吗？
	//cout<<sizeof(p1)<<endl;
	//if(2)
	//{
	//	IncludeCharFunc inFunc("123","456","789");
	//	inFunc.GetChar(p4,p5,p6);
	//}
	//cout<<p1<<endl;
	//cout<<p2<<endl;
	//cout<<p3<<endl;
#pragma endregion 指针的使用


#pragma region CString使用
	//char *pch = "曾经,有段";
	//CString str = CString(pch);
	//CString strL = str.Mid(str.Find(',')+1);
	//int a=10;
#pragma endregion CString使用


#pragma region 如果项目是unicode的CString会自动转换多字节字符吗？
	//const char *pch = "联通不";
	//wchar_t *pwch = L"联通不";
	//char buf[100]={0};
	////int i=0;
	////while(*p)
	////{
	////	buf[i++]=*p++;
	////}
	////buf[i]=0;
	//
	//DWORD nsize = WideCharToMultiByte(CP_ACP, 0, pwch, -1, NULL, 0, NULL, FALSE);
	//WideCharToMultiByte(CP_ACP, 0, pwch, -1, buf, nsize, NULL, FALSE);//转换后buf就是anci
	//CString str="";
	//str=pch;
	////str=buf;
	////str=CString(buf);//CString自动转换为宽字符；
	////str.Format("%s", buf);//不能自动转换：error C2664: 'void ATL::CStringT<BaseType,StringTraits>::Format(const wchar_t *,...)' : cannot convert parameter 1 from 'const char [3]' to 'const wchar_t *'
	//str.Format(_T("%s"), buf);//要这样用才行,这样的话如果在unicode下，则全部都必须这样用才行!
		//这样好像也不行？需要CString（buf）才可以？是的，或者str.Format(_T("%s"), CString(buf));
	//cout<<pwch<<endl;
	//cout<<str.GetBuffer()<<endl;
	//cout<<buf<<endl;
	//str=CString(pwch);//

	//cout<<"buf的大小="<<sizeof(buf)<<endl;
	//int a=10;
	/*
	1、如果是在unicode环境下定义的char数组，会自动转换为宽字符；
	2、但是如果函数是调用的是dll模块的，获取到的值应该是多字节，需要转换；//待验证???
	3、CString这个函数有点特比，它会根据项目环境的设置是宽字符的话，无论传宽字符还是多字节给它
	的构造函数都会转换成宽字符；
	*/
#pragma endregion 如果项目是unicode的CString会自动转换多字节字符吗？


#pragma region 字符数组当字符串
	//char buf[100] = {0};
	//for (int i=0;i<10;i++)
	//{
	//	buf[i]='a'+i;
	//}
	//int nLenth = strlen(buf);
	//cout<<"nLenth="<<nLenth<<endl;
	//cout<<buf<<endl;
#pragma endregion 字符数组当字符串


#pragma region 字符数组只能初始化一次
	//char buf[100] = {0};
	//for(int i=0;i<10;i++)
	//{
	//	/*buf[100]={0};*/
	//	memset(buf, 98,sizeof(buf));
	//	buf[i]='a';
	//	buf[i+1]='b';
	//	buf[i+2]=0;
	//	cout<<buf<<endl;
	//}
#pragma endregion 字符数组只能初始化一次

	while(1);
	return 0;
}

