
// DlgTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgTest.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
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


// CDlgTestDlg 对话框
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
		//::AfxMessageBox(L"构造函数！");//结论：构造函数->OnInitDialog（）->OnOK->OK返回；
	}
protected:
	void DoDataExchange(CDataExchange* pDX)
	{
		CDHtmlDialog::DoDataExchange(pDX);
	}

	BOOL OnInitDialog()
	{
		CDHtmlDialog::OnInitDialog();

		// 将“关于...”菜单项添加到系统菜单中。

		// IDM_ABOUTBOX 必须在系统命令范围内。
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

		// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
		//  执行此操作
		SetIcon(m_hIcon, TRUE);			// 设置大图标
		SetIcon(m_hIcon, FALSE);		// 设置小图标

		// TODO: 在此添加额外的初始化代码
		//::AfxMessageBox(L"OnInitDialog函数！");

		return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

	// 如果向对话框添加最小化按钮，则需要下面的代码
	//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
	//  这将由框架自动完成。

	void OnPaint()
	{
		if (IsIconic())
		{
			CPaintDC dc(this); // 用于绘制的设备上下文

			SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

			// 使图标在工作区矩形中居中
			int cxIcon = GetSystemMetrics(SM_CXICON);
			int cyIcon = GetSystemMetrics(SM_CYICON);
			CRect rect;
			GetClientRect(&rect);
			int x = (rect.Width() - cxIcon + 1) / 2;
			int y = (rect.Height() - cyIcon + 1) / 2;

			// 绘制图标
			dc.DrawIcon(x, y, m_hIcon);
		}
		else
		{
			CDHtmlDialog::OnPaint();
		}
	}

	//当用户拖动最小化窗口时系统调用此函数取得光标
	//显示。
	HCURSOR OnQueryDragIcon()
	{
		return static_cast<HCURSOR>(m_hIcon);
	}

	HRESULT OnButtonOK(IHTMLElement* /*pElement*/)
	{
		OnOK();
		//::AfxMessageBox(L"OnOK函数！");
		return S_OK;
	}

	HRESULT OnButtonCancel(IHTMLElement* /*pElement*/)
	{
		OnCancel();
		//::AfxMessageBox(L"地啊！");
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
				AfxMessageBox(L"没有权限！");
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
		::AfxMessageBox(L"返回OK后！");
	}
	else
	{
		::AfxMessageBox(L"返回CANCEL后");
	}
	return nRet;
}


