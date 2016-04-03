#pragma once
#include "afxwin.h"
#include "StartPPDoc.h"
#include "resource.h"

// ���������� ���� CDelPipesDialog

class CDelPipesDialog : public CDialog
{
	DECLARE_DYNAMIC(CDelPipesDialog)

public:
	CDelPipesDialog(CWnd* pParent, CStartPPDoc* pDoc); // ����������� �����������
	virtual ~CDelPipesDialog();

	// ������ ����������� ����
	enum
	{
		IDD = IDD_DEL_PIPES
	};

protected:
	void DoDataExchange(CDataExchange* pDX) override; // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CStartPPDoc* m_pDoc;
	CListBox m_listbox;
	BOOL OnInitDialog() override;
	afx_msg  void OnLbnSelchangeList1();
	void OnOK() override;
};

