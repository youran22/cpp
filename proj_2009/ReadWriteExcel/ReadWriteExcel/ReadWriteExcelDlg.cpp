
// ReadWriteExcelDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ReadWriteExcel.h"
#include "ReadWriteExcelDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include "Application.h"
#include "Workbooks.h"
#include "Workbook.h"
#include "Worksheets.h"
#include "Worksheet.h"
#include "Range.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CReadWriteExcelDlg �Ի���




IMPLEMENT_DYNAMIC(CReadWriteExcelDlg, CDialogEx);

CReadWriteExcelDlg::CReadWriteExcelDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CReadWriteExcelDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CReadWriteExcelDlg::~CReadWriteExcelDlg()
{
	// ����öԻ������Զ���������
	//  ���˴���ָ��öԻ���ĺ���ָ������Ϊ NULL���Ա�
	//  �˴���֪���öԻ����ѱ�ɾ����
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CReadWriteExcelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CReadWriteExcelDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CReadWriteExcelDlg ��Ϣ�������

BOOL CReadWriteExcelDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	m_ListCtrl.SetExtendedStyle(LVS_REPORT | LVS_EX_FULLROWSELECT);

	CApplication ExcelApp;
	CWorkbooks books;
	CWorkbook book;
	CWorksheets sheets;
	CWorksheet sheet;
	CRange range;
	LPDISPATCH lpDisp = NULL;

	//����Excel ������(����Excel)
	if(!ExcelApp.CreateDispatch(_T("Excel.Application"),NULL))
	{
		AfxMessageBox(_T("����Excel������ʧ��!"));
		return -1;
	}

	/*�жϵ�ǰExcel�İ汾*/
	CString strExcelVersion = ExcelApp.get_Version();
	int iStart = 0;
	strExcelVersion = strExcelVersion.Tokenize(_T("."), iStart);
	if (_T("11") == strExcelVersion)
	{
		AfxMessageBox(_T("��ǰExcel�İ汾��2003��"));
	}
	else if (_T("12") == strExcelVersion)
	{
		AfxMessageBox(_T("��ǰExcel�İ汾��2007��"));
	}
	else
	{
		AfxMessageBox(_T("��ǰExcel�İ汾�������汾��"));
	}

	ExcelApp.put_Visible(TRUE);
	ExcelApp.put_UserControl(FALSE);

	/*�õ�����������*/
	books.AttachDispatch(ExcelApp.get_Workbooks());

	/*��һ�����������粻���ڣ�������һ��������*/
	CString strBookPath = _T("C:\\tmp.xls");
	try
	{
		/*��һ��������*/
		lpDisp = books.Open(strBookPath, 
			vtMissing, vtMissing, vtMissing, vtMissing, vtMissing,
			vtMissing, vtMissing, vtMissing, vtMissing, vtMissing, 
			vtMissing, vtMissing, vtMissing, vtMissing);
		book.AttachDispatch(lpDisp);
	}
	catch(...)
	{
		/*����һ���µĹ�����*/
		lpDisp = books.Add(vtMissing);
		book.AttachDispatch(lpDisp);
	}
	

	/*�õ��������е�Sheet������*/
	sheets.AttachDispatch(book.get_Sheets());

	/*��һ��Sheet���粻���ڣ�������һ��Sheet*/
	CString strSheetName = _T("NewSheet");
	try
	{
		/*��һ�����е�Sheet*/
		lpDisp = sheets.get_Item(_variant_t(strSheetName));
		sheet.AttachDispatch(lpDisp);
	}
	catch(...)
	{
		/*����һ���µ�Sheet*/
		lpDisp = sheets.Add(vtMissing, vtMissing, _variant_t((long)1), vtMissing);
		sheet.AttachDispatch(lpDisp);
		sheet.put_Name(strSheetName);
	}

	system("pause");

	/*��Sheet��д������Ԫ��,��ģΪ10*10 */
	lpDisp = sheet.get_Range(_variant_t("A1"), _variant_t("J10"));
	range.AttachDispatch(lpDisp);

	VARTYPE vt = VT_I4; /*����Ԫ�ص����ͣ�long*/
	SAFEARRAYBOUND sabWrite[2]; /*���ڶ��������ά�����±����ʼֵ*/
	sabWrite[0].cElements = 10;
	sabWrite[0].lLbound = 0;
	sabWrite[1].cElements = 10;
	sabWrite[1].lLbound = 0;

	COleSafeArray olesaWrite;
	olesaWrite.Create(vt, sizeof(sabWrite)/sizeof(SAFEARRAYBOUND), sabWrite);

	/*ͨ��ָ�������ָ�����Զ�ά�����Ԫ�ؽ��м�Ӹ�ֵ*/
	long (*pArray)[2] = NULL;
	olesaWrite.AccessData((void **)&pArray);
	memset(pArray, 0, sabWrite[0].cElements * sabWrite[1].cElements * sizeof(long));

	/*�ͷ�ָ�������ָ��*/
	olesaWrite.UnaccessData();
	pArray = NULL;

	/*�Զ�ά�����Ԫ�ؽ��������ֵ*/
	long index[2] = {0, 0};
	long lFirstLBound = 0;
	long lFirstUBound = 0;
	long lSecondLBound = 0;
	long lSecondUBound = 0;
	olesaWrite.GetLBound(1, &lFirstLBound);
	olesaWrite.GetUBound(1, &lFirstUBound);
	olesaWrite.GetLBound(2, &lSecondLBound);
	olesaWrite.GetUBound(2, &lSecondUBound);
	for (long i = lFirstLBound; i <= lFirstUBound; i++)
	{
		index[0] = i;
		for (long j = lSecondLBound; j <= lSecondUBound; j++)
		{
			index[1] = j;
			long lElement = i * sabWrite[1].cElements + j; 
			olesaWrite.PutElement(index, &lElement);
		}
	}

	/*��ColesaWritefeArray����ת��ΪVARIANT,��д�뵽Excel�����*/
	VARIANT varWrite = (VARIANT)olesaWrite;
	range.put_Value2(varWrite);

	system("pause");

	/*�����ļ��ĺ�׺��ѡ�񱣴��ļ��ĸ�ʽ*/
 	CString strSaveAsName = _T("C:\\new.xlsx");
	CString strSuffix = strSaveAsName.Mid(strSaveAsName.ReverseFind(_T('.')));
	XlFileFormat NewFileFormat = xlOpenXMLWorkbook;
	if (0 == strSuffix.CompareNoCase(_T(".xls")))
	{
		NewFileFormat = xlExcel8;
	}
	book.SaveAs(_variant_t(strSaveAsName), _variant_t((long)NewFileFormat), vtMissing, vtMissing, vtMissing, 
		vtMissing, 0, vtMissing, vtMissing, vtMissing, 
		vtMissing, vtMissing);

	system("pause");

	/*��ȡExcel���еĶ����Ԫ���ֵ����listctrl����ʾ*/
	VARIANT varRead = range.get_Value2();
	COleSafeArray olesaRead(varRead);

	VARIANT varItem;
	CString strItem;
	lFirstLBound = 0;
	lFirstUBound = 0;
	lSecondLBound = 0;
	lSecondUBound = 0;
	olesaRead.GetLBound(1, &lFirstLBound);
	olesaRead.GetUBound(1, &lFirstUBound);
	olesaRead.GetLBound(2, &lSecondLBound);
	olesaRead.GetUBound(2, &lSecondUBound);
	memset(index, 0, 2 * sizeof(long));
	m_ListCtrl.InsertColumn(0, _T(""), 0, 100);
	for (long j = lSecondLBound; j<= lSecondUBound; j++)
	{
		CString strColName = _T("");
		strColName.Format(_T("%d"), j);
		m_ListCtrl.InsertColumn(j, strColName, 0, 100);
	}
	for (long i = lFirstLBound; i <= lFirstUBound; i++)
	{
		CString strRowName = _T("");
		strRowName.Format(_T("%d"), i);
		m_ListCtrl.InsertItem(i-1, strRowName);

		index[0] = i;
		for (long j = lSecondLBound; j <= lSecondUBound; j++)
		{
			index[1] = j;
			olesaRead.GetElement(index, &varItem);

			switch (varItem.vt)
			{
			case VT_R8:
				{
					strItem.Format(_T("%d"), (int)varItem.dblVal);
				}

			case VT_BSTR:
				{
					strItem = varItem.bstrVal;
				}

			case VT_I4:
				{
					strItem.Format(_T("%ld"), (int)varItem.lVal);
				}

			default:
				{

				}
			}

			m_ListCtrl.SetItemText(i-1, j, strItem);
		}
	}



	/*�ͷ���Դ*/
	sheet.ReleaseDispatch();
	sheets.ReleaseDispatch();
	book.ReleaseDispatch();
	books.ReleaseDispatch();
	ExcelApp.Quit();
	ExcelApp.ReleaseDispatch();
	
// 	/*�˳�������ʾ�Ի���*/
// 	exit(0);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CReadWriteExcelDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CReadWriteExcelDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CReadWriteExcelDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ���û��ر� UI ʱ������������Ա���������ĳ��
//  �������Զ�����������Ӧ�˳�����Щ
//  ��Ϣ�������ȷ����������: �����������ʹ�ã�
//  ������ UI�������ڹرնԻ���ʱ��
//  �Ի�����Ȼ�ᱣ�������

void CReadWriteExcelDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CReadWriteExcelDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CReadWriteExcelDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CReadWriteExcelDlg::CanExit()
{
	// �����������Ա�����������Զ���
	//  �������Իᱣ�ִ�Ӧ�ó���
	//  ʹ�Ի���������������� UI ����������
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

