
// DlgTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DlgTest.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
class CAboutDlg : public CDialog
{
	enum { IDD = IDD_ABOUTBOX };
public:
	CAboutDlg() : CDialog(CAboutDlg::IDD)
	{
	}
protected:
	void DoDataExchange(CDataExchange* pDX)
	{
		CDialog::DoDataExchange(pDX);
	}
protected:
	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDlgTestDlg �Ի���
class CDlgTestDlg : public CDHtmlDialog
{
	enum { IDD = IDD_DLGTEST_DIALOG, IDH = IDR_HTML_DLGTEST_DIALOG };

protected:
	HICON m_hIcon;
public:
	CDlgTestDlg(CWnd* pParent =NULL)
		: CDHtmlDialog(IDD, IDH, pParent)
	{
		m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
		//::AfxMessageBox(L"���캯����");//���ۣ����캯��->OnInitDialog����->OnOK->OK���أ�
	}
protected:
	void DoDataExchange(CDataExchange* pDX)
	{
		CDHtmlDialog::DoDataExchange(pDX);
	}

	BOOL OnInitDialog()
	{
		CDHtmlDialog::OnInitDialog();

		// ��������...���˵�����ӵ�ϵͳ�˵��С�

		// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
		ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
		ASSERT(IDM_ABOUTBOX < 0xF000);

		CMenu* pSysMenu = GetSystemMenu(FALSE);
		if (pSysMenu != NULL)
		{
			BOOL bNameValid;
			CString strAboutMenu;
			bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
			ASSERT(bNameValid);
			if (!strAboutMenu.IsEmpty())
			{
				pSysMenu->AppendMenu(MF_SEPARATOR);
				pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
			}
		}

		// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
		//  ִ�д˲���
		SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
		SetIcon(m_hIcon, FALSE);		// ����Сͼ��

		// TODO: �ڴ���Ӷ���ĳ�ʼ������
		//::AfxMessageBox(L"OnInitDialog������");

		return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
	}

	void OnSysCommand(UINT nID, LPARAM lParam)
	{
		if ((nID & 0xFFF0) == IDM_ABOUTBOX)
		{
			CAboutDlg dlgAbout;
			dlgAbout.DoModal();
		}
		else
		{
			CDHtmlDialog::OnSysCommand(nID, lParam);
		}
	}

	// �����Ի��������С����ť������Ҫ����Ĵ���
	//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
	//  �⽫�ɿ���Զ���ɡ�

	void OnPaint()
	{
		if (IsIconic())
		{
			CPaintDC dc(this); // ���ڻ��Ƶ��豸������

			SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

			// ʹͼ���ڹ����������о���
			int cxIcon = GetSystemMetrics(SM_CXICON);
			int cyIcon = GetSystemMetrics(SM_CYICON);
			CRect rect;
			GetClientRect(&rect);
			int x = (rect.Width() - cxIcon + 1) / 2;
			int y = (rect.Height() - cyIcon + 1) / 2;

			// ����ͼ��
			dc.DrawIcon(x, y, m_hIcon);
		}
		else
		{
			CDHtmlDialog::OnPaint();
		}
	}

	//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
	//��ʾ��
	HCURSOR OnQueryDragIcon()
	{
		return static_cast<HCURSOR>(m_hIcon);
	}

	HRESULT OnButtonOK(IHTMLElement* /*pElement*/)
	{
		OnOK();
		//::AfxMessageBox(L"OnOK������");
		return S_OK;
	}

	HRESULT OnButtonCancel(IHTMLElement* /*pElement*/)
	{
		OnCancel();
		//::AfxMessageBox(L"�ذ���");
		return S_OK;
	}

	void OnBnClickedBtnTest()
	{
#pragma region 
		SHELLEXECUTEINFO shInfo;
		//shInfo.hwnd = this->m_hWnd;
		CString strPathName = _T("E:\\gnss\\southgnss_sdk\\win32bin\\CoordSystemTool.exe");
		shInfo.lpVerb = _T("open");
		shInfo.lpFile = strPathName.GetBuffer();
		CString strCmd = _T("");
		shInfo.lpParameters = strCmd.GetBuffer();
		if(ShellExecuteEx(&shInfo))
		{
			int a=10;
		}
		else
		{
			if(ERROR_ACCESS_DENIED == GetLastError())
			{
				AfxMessageBox(L"û��Ȩ�ޣ�");
			}
			int c=10;
		}
#pragma endregion 
	}
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
};
BEGIN_DHTML_EVENT_MAP(CDlgTestDlg)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()

BEGIN_MESSAGE_MAP(CDlgTestDlg, CDHtmlDialog)
	ON_WM_SYSCOMMAND()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_Btn_Test, &CDlgTestDlg::OnBnClickedBtnTest)
END_MESSAGE_MAP()
int dlg_test()
{
	CDlgTestDlg dlg;
	int nRet = 0;
	nRet = dlg.DoModal();
	if(nRet)
	{
		::AfxMessageBox(L"����OK��");
	}
	else
	{
		::AfxMessageBox(L"����CANCEL��");
	}
	return nRet;
}


