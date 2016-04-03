#pragma once
#include "afxwin.h"
#include "Pipe.h"
#include "resource.h"


// ���������� ���� CNewPipeDialog

class CNewPipeDialog : public CDialog
{
	DECLARE_DYNAMIC(CNewPipeDialog)

public:
	CNewPipeDialog(CWnd* pParent, CPipes& pipes); // ����������� �����������
	virtual ~CNewPipeDialog();

	// ������ ����������� ����
	enum
	{
		IDD = IDD_NEW_PIPE
	};

protected:
	void DoDataExchange(CDataExchange* pDX) override; // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
	int m_nNAYZ;
	int m_nKOYZ;
	CPipes& m_pipes;
	BOOL OnInitDialog() override;
	void OnLbChange(void);
	void OnOK() override;
};

