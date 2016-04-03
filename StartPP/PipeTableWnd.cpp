// PipeTableWnd.cpp: ���� ����������
//

#include "stdafx.h"
#include "PipeTableWnd.h"


// CPipeTableWnd

IMPLEMENT_DYNAMIC(CPipeTableWnd, CDockablePane)

CPipeTableWnd::CPipeTableWnd()
{

}

CPipeTableWnd::~CPipeTableWnd()
{
}


BEGIN_MESSAGE_MAP(CPipeTableWnd, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// ����������� ��������� CPipeTableWnd




int CPipeTableWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;
	CRect rectDummy(0, 0, 100, 200);
	if (!m_wndGrid.Create(rectDummy, this, 1000))
	{
		TRACE0("�� ������� ������� ���� ������� \n");
		return -1; // �� ������� �������
	}

	// TODO:  �������� ������������������ ��� ��������

	return 0;
}


void CPipeTableWnd::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	CRect rectClient;
	GetClientRect(rectClient);
	m_wndGrid.SetWindowPos(nullptr, rectClient.top, rectClient.left, rectClient.Width(), rectClient.Height(), SWP_NOACTIVATE | SWP_NOZORDER);
}


void CPipeTableWnd::DoDataExchange(CDataExchange* pDX, CStartPPDoc* pDoc)
{
	// TODO: �������� ������������������ ��� ��� ����� �������� ������

	CDockablePane::DoDataExchange(pDX);
}
