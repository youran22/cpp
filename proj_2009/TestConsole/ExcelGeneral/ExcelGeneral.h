
// ExcelGeneral.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CExcelGeneralApp:
// �йش����ʵ�֣������ ExcelGeneral.cpp
//

class CExcelGeneralApp : public CWinAppEx
{
public:
	CExcelGeneralApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CExcelGeneralApp theApp;