#pragma once
#include "PipePresenter.h"
#include "resource.h"


// ���������� ���� CDistDialog

class CDistDialog : public CDialog
{
	DECLARE_DYNAMIC(CDistDialog)

public:
	CDistDialog(CPipePresenter& pipes, CWnd* pParent = nullptr); // ����������� �����������
	virtual ~CDistDialog();

	// ������ ����������� ����
	enum
	{
		IDD = IDD_DIST
	};

protected:
	CPipePresenter& m_pipes;
	void DoDataExchange(CDataExchange* pDX) override; // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog() override;
	int m_nFrom;
	int m_nTo;
};

