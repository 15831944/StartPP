// ChildFrm.h : ��������� ������ CChildFrame
//

#pragma once

class CChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

	// ��������
public:

	// ��������
public:

	// ���������������
	BOOL PreCreateWindow(CREATESTRUCT& cs) override;

	// ����������
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	void AssertValid() const override;
	void Dump(CDumpContext& dc) const override;
#endif

	// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
};

