#pragma once

#include "Pipe.h"
#include "afxwin.h"

// ���������� ���� CMoveNodeDialog

class CMoveNodeDialog : public CDialog
{
	DECLARE_DYNAMIC(CMoveNodeDialog)

public:
	CMoveNodeDialog(CWnd* pParent, CPipes& pipes); // ����������� �����������
	virtual ~CMoveNodeDialog();

	// ������ ����������� ����
	enum
	{
		IDD = IDD_MOVE_NODE
	};

protected:
	void DoDataExchange(CDataExchange* pDX) override; // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CPipes& m_pipes;
	CStatic m_sNode;
	float m_nDist;
	BOOL OnInitDialog() override;
	void OnOK() override;
};

