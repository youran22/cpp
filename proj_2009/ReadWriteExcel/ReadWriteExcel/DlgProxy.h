
// DlgProxy.h: ͷ�ļ�
//

#pragma once

class CReadWriteExcelDlg;


// CReadWriteExcelDlgAutoProxy ����Ŀ��

class CReadWriteExcelDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CReadWriteExcelDlgAutoProxy)

	CReadWriteExcelDlgAutoProxy();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��

// ����
public:
	CReadWriteExcelDlg* m_pDialog;

// ����
public:

// ��д
	public:
	virtual void OnFinalRelease();

// ʵ��
protected:
	virtual ~CReadWriteExcelDlgAutoProxy();

	// ���ɵ���Ϣӳ�亯��

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CReadWriteExcelDlgAutoProxy)

	// ���ɵ� OLE ����ӳ�亯��

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

