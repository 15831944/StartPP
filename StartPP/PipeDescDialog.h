#pragma once
#include "afxwin.h"
#include "afxdtctl.h"

class CPipeDesc;

// ���������� ���� CPipeDescDialog

class CPipeDescDialog : public CDialog
{
	DECLARE_DYNAMIC(CPipeDescDialog)

public:
	CPipeDescDialog(CPipeDesc& rPipeDesc, CWnd* pParent = nullptr); // ����������� �����������
	virtual ~CPipeDescDialog();

	// ������ ����������� ����
	enum
	{
		IDD = IDD_PIPEDESCDIALOG
	};

protected:
	CPipeDesc& m_rPipeDesc;
	void DoDataExchange(CDataExchange* pDX) override; // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog() override;
	CComboBox m_cbNormaDoc;
	CDateTimeCtrl m_ctlDate;
	CComboBox m_cbStrings;
	CComboBox m_cbIsp;
	CComboBox m_cbComp;
	void OnLBIspChange(void);
	afx_msg void OnCbnSelchangeComboStrings();
	CComboBox m_cbStrings2;
	CComboBox m_cbString3;
	afx_msg void OnCbnSelchangeComboComp();
};

