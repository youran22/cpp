// TestConsole.cpp : Defines the entry point for the console application.
//
#pragma region
#pragma endregion
#include "stdafx.h"
#include <atlstr.h>//CString
#include <iostream>


#pragma region W2A���÷�
//#include "atlconv.h"
//USES_CONVERSION;
//missing type specifier - int assumed. Note: C++ does not support default-int
//error C2086: 'int _convert' : redefinition
#pragma endregion W2A���÷�

#pragma region afxwinͷ�ļ���������
//#include <afxwin.h>//AfxMessageBxo
//afx.h(24) : fatal error C1189: #error :  Building MFC application with /MD[d] (CRT dll version) requires MFC shared dll version. Please #define _AFXDLL or do not use /MD[d]
#pragma endregion afxwinͷ�ļ���������

using namespace std;

int WideToMuti(char *p, wchar_t *wp)
{
	int nSize = ::WideCharToMultiByte(CP_ACP, 0, wp, -1, NULL, 0, NULL, FALSE);
	::WideCharToMultiByte(CP_ACP, 0, wp, nSize, p, nSize, NULL, FALSE);
	return 0;
}

#pragma region ָ���ʹ��
//int c=30;
//int *copyString(int* p)//local function definitions are illegal
//{
//	int *temp = p;
//	p=&c;
//	return temp;
//}

#pragma endregion ָ���ʹ��

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

//main����
int _tmain(int argc, _TCHAR* argv[])
{

#pragma region va_start��va_endʹ����� 
//'fun' : local function definitions are illegal
	int a=1;
	int b=2;
	int c=3;
	int d=4;
	fun(4,a,b,c,d);

#pragma endregion va_start��va_endʹ����� 


#pragma region ָ���ʹ��
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
	////û�пռ�

	//char p1[128]={0};
	//char p2[128]={0};
	//char p3[128]={0};
	//char *p4 = &p1[0];
	//char *p5 = &p2[0];
	//char *p6 = &p3[0];//char*&��ʹ�÷���,������������õı����
	//cout<<sizeof(p1)<<endl;
	//if(2)
	//{
	//	IncludeCharFunc inFunc("123","456","789");
	//	inFunc.GetChar(p4,p5,p6);
	//}
	//cout<<p1<<endl;
	//cout<<p2<<endl;
	//cout<<p3<<endl;
#pragma endregion ָ���ʹ��


#pragma region CStringʹ��
	//char *pch = "����,�ж�";
	//CString str = CString(pch);
	//CString strL = str.Mid(str.Find(',')+1);
	//int a=10;
#pragma endregion CStringʹ��


#pragma region �����Ŀ��unicode��CString���Զ�ת�����ֽ��ַ���
	//const char *pch = "��ͨ��";
	//wchar_t *pwch = L"��ͨ��";
	//char buf[100]={0};
	////int i=0;
	////while(*p)
	////{
	////	buf[i++]=*p++;
	////}
	////buf[i]=0;
	//
	//DWORD nsize = WideCharToMultiByte(CP_ACP, 0, pwch, -1, NULL, 0, NULL, FALSE);
	//WideCharToMultiByte(CP_ACP, 0, pwch, -1, buf, nsize, NULL, FALSE);//ת����buf����anci
	//CString str="";
	//str=pch;
	////str=buf;
	////str=CString(buf);//CString�Զ�ת��Ϊ���ַ���
	////str.Format("%s", buf);//�����Զ�ת����error C2664: 'void ATL::CStringT<BaseType,StringTraits>::Format(const wchar_t *,...)' : cannot convert parameter 1 from 'const char [3]' to 'const wchar_t *'
	//str.Format(_T("%s"), buf);//Ҫ�����ò���,�����Ļ������unicode�£���ȫ�������������ò���!
		//��������Ҳ���У���ҪCString��buf���ſ��ԣ��ǵģ�����str.Format(_T("%s"), CString(buf));
	//cout<<pwch<<endl;
	//cout<<str.GetBuffer()<<endl;
	//cout<<buf<<endl;
	//str=CString(pwch);//

	//cout<<"buf�Ĵ�С="<<sizeof(buf)<<endl;
	//int a=10;
	/*
	1���������unicode�����¶����char���飬���Զ�ת��Ϊ���ַ���
	2��������������ǵ��õ���dllģ��ģ���ȡ����ֵӦ���Ƕ��ֽڣ���Ҫת����//����֤???
	3��CString��������е��رȣ����������Ŀ�����������ǿ��ַ��Ļ������۴����ַ����Ƕ��ֽڸ���
	�Ĺ��캯������ת���ɿ��ַ���
	*/
#pragma endregion �����Ŀ��unicode��CString���Զ�ת�����ֽ��ַ���


#pragma region �ַ����鵱�ַ���
	//char buf[100] = {0};
	//for (int i=0;i<10;i++)
	//{
	//	buf[i]='a'+i;
	//}
	//int nLenth = strlen(buf);
	//cout<<"nLenth="<<nLenth<<endl;
	//cout<<buf<<endl;
#pragma endregion �ַ����鵱�ַ���


#pragma region �ַ�����ֻ�ܳ�ʼ��һ��
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
#pragma endregion �ַ�����ֻ�ܳ�ʼ��һ��

	while(1);
	return 0;
}

