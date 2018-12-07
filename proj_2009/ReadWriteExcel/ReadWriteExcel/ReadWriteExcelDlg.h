
// ReadWriteExcelDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"

class CReadWriteExcelDlgAutoProxy;


// CReadWriteExcelDlg �Ի���
class CReadWriteExcelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CReadWriteExcelDlg);
	friend class CReadWriteExcelDlgAutoProxy;

// ����
public:
	CReadWriteExcelDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CReadWriteExcelDlg();

// �Ի�������
	enum { IDD = IDD_READWRITEEXCEL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	CReadWriteExcelDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl;
};
