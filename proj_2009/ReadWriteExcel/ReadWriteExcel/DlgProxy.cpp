
// DlgProxy.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ReadWriteExcel.h"
#include "DlgProxy.h"
#include "ReadWriteExcelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CReadWriteExcelDlgAutoProxy

IMPLEMENT_DYNCREATE(CReadWriteExcelDlgAutoProxy, CCmdTarget)

CReadWriteExcelDlgAutoProxy::CReadWriteExcelDlgAutoProxy()
{
	EnableAutomation();
	
	// ΪʹӦ�ó������Զ��������ڻ״̬ʱһֱ���� 
	//	���У����캯������ AfxOleLockApp��
	AfxOleLockApp();

	// ͨ��Ӧ�ó����������ָ��
	//  �����ʶԻ������ô�����ڲ�ָ��
	//  ָ��Ի��򣬲����öԻ���ĺ���ָ��ָ��
	//  �ô���
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CReadWriteExcelDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CReadWriteExcelDlg)))
		{
			m_pDialog = reinterpret_cast<CReadWriteExcelDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CReadWriteExcelDlgAutoProxy::~CReadWriteExcelDlgAutoProxy()
{
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	// 	������������ AfxOleUnlockApp��
	//  ���������������⣬�⻹���������Ի���
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CReadWriteExcelDlgAutoProxy::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CReadWriteExcelDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CReadWriteExcelDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ע��: ��������˶� IID_IReadWriteExcel ��֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {AF2A28C6-8ECD-4D30-9DAA-1A7C0EBA8D1C}
static const IID IID_IReadWriteExcel =
{ 0xAF2A28C6, 0x8ECD, 0x4D30, { 0x9D, 0xAA, 0x1A, 0x7C, 0xE, 0xBA, 0x8D, 0x1C } };

BEGIN_INTERFACE_MAP(CReadWriteExcelDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CReadWriteExcelDlgAutoProxy, IID_IReadWriteExcel, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 ���ڴ���Ŀ�� StdAfx.h �ж���
// {B2359DC3-377F-45D3-AF2A-77278B400702}
IMPLEMENT_OLECREATE2(CReadWriteExcelDlgAutoProxy, "ReadWriteExcel.Application", 0xb2359dc3, 0x377f, 0x45d3, 0xaf, 0x2a, 0x77, 0x27, 0x8b, 0x40, 0x7, 0x2)


// CReadWriteExcelDlgAutoProxy ��Ϣ�������
