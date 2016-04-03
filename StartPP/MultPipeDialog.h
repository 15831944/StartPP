#pragma once
#include "afxwin.h"
#include "Pipe.h"
#include "resource.h"

// ���������� ���� CMultPipeDialog

class CMultPipeDialog : public CDialog
{
	DECLARE_DYNAMIC(CMultPipeDialog)

public:
	CMultPipeDialog(CWnd* pParent, CPipes& pipes); // ����������� �����������
	virtual ~CMultPipeDialog();

	// ������ ����������� ����
	enum
	{
		IDD = IDD_MULT_PIPES
	};

protected:
	void DoDataExchange(CDataExchange* pDX) override; // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
	int m_NAYZ;
	int m_KOYZ;
	int m_nPipes;
	CPipes& m_pipes;
	BOOL OnInitDialog() override;
	void OnOK() override;
	//	void OnLbChange(void);
	afx_msg void OnChangeEdit1();
	afx_msg void OnChangeEdit2();
	afx_msg void OnChangeEdit3();
};

