#pragma once
#include "Pipe.h"
#include "afxwin.h"

// ���������� ���� CCopyParamsDialog

class CCopyParamsDialog : public CDialog
{
	DECLARE_DYNAMIC(CCopyParamsDialog)

public:
	CCopyParamsDialog(CWnd* pParent, CPipes& pipes); // ����������� �����������
	virtual ~CCopyParamsDialog();

	// ������ ����������� ����
	enum
	{
		IDD = IDD_COPY_PARAMS
	};

protected:
	void DoDataExchange(CDataExchange* pDX) override; // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CPipes m_pipes;
	afx_msg void OnLbnSelchangeParams();
	BOOL OnInitDialog() override;
	void OnOK() override;
	CListBox m_lbParams;
	CListBox m_lbPipes;
	afx_msg void OnStnClickedPipeName();
	CStatic m_sPipeName;
};

