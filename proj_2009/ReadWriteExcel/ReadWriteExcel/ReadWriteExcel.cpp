
// ReadWriteExcel.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "ReadWriteExcel.h"
#include "ReadWriteExcelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CReadWriteExcelApp

BEGIN_MESSAGE_MAP(CReadWriteExcelApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CReadWriteExcelApp ����

CReadWriteExcelApp::CReadWriteExcelApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CReadWriteExcelApp ����

CReadWriteExcelApp theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x7884A9A5, 0x2E64, 0x451D, { 0xA4, 0x2, 0xB6, 0x16, 0x94, 0xE, 0xE3, 0x42 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// CReadWriteExcelApp ��ʼ��

BOOL CReadWriteExcelApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	// �����Զ������ػ�ע��/ע�����ص������С�
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Ӧ�ó������� /Embedding �� /Automation ���������ġ�
	//ʹӦ�ó�����Ϊ�Զ������������С�
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// ͨ�� CoRegisterClassObject() ע���๤����
		COleTemplateServer::RegisterAll();
	}
	// Ӧ�ó������� /Unregserver �� /Unregister ���������ġ��Ƴ�
	// ע����е��
	else if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppUnregister)
	{
		COleObjectFactory::UpdateRegistryAll(FALSE);
		AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor);
		return FALSE;
	}
	// Ӧ�ó������Զ�����ʽ������������(�� /Register
	// �� /Regserver)�����ġ�����ע�����������Ϳ⡣
	else
	{
		COleObjectFactory::UpdateRegistryAll();
		AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid);
		if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppRegister)
			return FALSE;
	}

	CReadWriteExcelDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

int CReadWriteExcelApp::ExitInstance()
{
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}
