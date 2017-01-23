// MainFrm.cpp : ���������� ������ CMainFrame
//

#include "stdafx.h"
#include "StartPP.h"

#include "MainFrm.h"
#include "resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame
IMPLEMENT_SERIAL(CProjButton, CMFCToolBarMenuButton, 1)

CProjButton::CProjButton(UINT uiCmdID, HMENU h, LPCTSTR lpszText): CMFCToolBarMenuButton(uiCmdID, h, GetCmdMgr()->GetCmdImage(uiCmdID, FALSE), lpszText)
{
}

CMFCPopupMenu* CProjButton::CreatePopupMenu()
{
	return CMFCToolBarMenuButton::CreatePopupMenu();
}

BOOL CProjButton::IsEmptyMenuAllowed() const
{
	return TRUE;
}

void CProjButton::OnChangeParentWnd(CWnd* pWndParent)
{
	CMFCToolBarMenuButton::OnChangeParentWnd(pWndParent);
	m_bDrawDownArrow = TRUE;
}

BOOL CProjButton::IsExclusive() const
{
	return FALSE;
}

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWndEx)

const int iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWndEx)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	// Global help commands
	ON_COMMAND(ID_HELP_FINDER, &CMDIFrameWndEx::OnHelpFinder)
	ON_COMMAND(ID_HELP, &CMDIFrameWndEx::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, &CMDIFrameWndEx::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, &CMDIFrameWndEx::OnHelpFinder)
	ON_COMMAND(ID_WINDOW_MANAGER, &CMainFrame::OnWindowManager)
	ON_COMMAND(ID_VIEW_CUSTOMIZE, &CMainFrame::OnViewCustomize)
	ON_REGISTERED_MESSAGE(AFX_WM_CREATETOOLBAR, &CMainFrame::OnToolbarCreateNew)
	ON_REGISTERED_MESSAGE(AFX_WM_RESETTOOLBAR, &CMainFrame::OnToolbarReset)
	ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnApplicationLook)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnUpdateApplicationLook)
	ON_WM_SETTINGCHANGE()
	ON_COMMAND(ID_WINDOW_TILE_VERT, &CMainFrame::OnWindowTileVert)
	ON_COMMAND(ID_PROP_MERT, &CMainFrame::OnPropMert)
	ON_UPDATE_COMMAND_UI(ID_PROP_MERT, &CMainFrame::OnUpdatePropMert)
	ON_COMMAND(ID_PROP_SK, &CMainFrame::OnPropSk)
	ON_UPDATE_COMMAND_UI(ID_PROP_SK, &CMainFrame::OnUpdatePropSk)
	ON_COMMAND(ID_PROP_NAPR, &CMainFrame::OnPropNapr)
	ON_UPDATE_COMMAND_UI(ID_PROP_NAPR, &CMainFrame::OnUpdatePropNapr)
	ON_COMMAND(ID_PROP_OTV_IZ, &CMainFrame::OnPropOtvIz)
	ON_UPDATE_COMMAND_UI(ID_PROP_OTV_IZ, &CMainFrame::OnUpdatePropOtvIz)
	ON_COMMAND(ID_PROP_OTV_SV, &CMainFrame::OnPropOtvSv)
	ON_UPDATE_COMMAND_UI(ID_PROP_OTV_SV, &CMainFrame::OnUpdatePropOtvSv)
	ON_COMMAND(ID_PROP_ARM, &CMainFrame::OnPropArm)
	ON_UPDATE_COMMAND_UI(ID_PROP_ARM, &CMainFrame::OnUpdatePropArm)
	ON_UPDATE_COMMAND_UI(ID_IND_FILE_COUNT, &CMainFrame::OnUpdateIndFileCount)
	END_MESSAGE_MAP()


// ��������/����������� CMainFrame

CMainFrame::CMainFrame()
{
	// TODO: �������� ��� ������������� �����
	theApp.m_nAppLook = theApp.GetInt(_T("ApplicationLook"), ID_VIEW_APPLOOK_WINDOWS_7);
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL bNameValid;

	CMDITabInfo mdiTabParams;
	mdiTabParams.m_style = CMFCTabCtrl::STYLE_3D; // ������ ��������� �����...
	mdiTabParams.m_bActiveTabCloseButton = TRUE; // ���������� �������� FALSE, ����� ����������� ������ \"�������\" � ������ ����� ������� �������
	mdiTabParams.m_bTabIcons = FALSE; // ���������� �������� TRUE, ����� �������� ������ ���������� �� �������� MDI
	mdiTabParams.m_bAutoColor = FALSE; // ���������� �������� FALSE, ����� ��������� �������������� ��������� ������ ������� MDI
	mdiTabParams.m_bDocumentMenu = TRUE; // �������� ���� ��������� �� ������ ������� ������� �������
	EnableMDITabbedGroups(TRUE, mdiTabParams);
	RegisterAllMDIChildrenWithTaskbar(FALSE);
	if (!m_wndMenuBar.Create(this))
	{
		TRACE0("�� ������� ������� ������ ����\n");
		return -1; // �� ������� �������
	}

	m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndMenuBar.SetRecentlyUsedMenus(FALSE);

	// �������������� ����������� ������ ���� �� ��������� 
	CMFCPopupMenu::SetForceMenuFocus(FALSE);

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC, CRect(1, 1, 1, 1), IDR_MAINFRAME_256) ||
		!m_wndToolBar.LoadToolBar(theApp.m_bHiColorIcons ? IDR_MAINFRAME_256 : IDR_MAINFRAME))
	{
		TRACE0("�� ������� ������� ������ ������������\n");
		return -1; // �� ������� �������
	}

	if (!m_wndViewToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC, CRect(1, 1, 1, 1), IDR_VIEW_TOOLBAR) ||
		!m_wndViewToolBar.LoadToolBar(IDR_VIEW_TOOLBAR))
	{
		TRACE0("�� ������� ������� ������ ������������\n");
		return -1; // �� ������� �������
	}

	if (!m_wndProjToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC, CRect(1, 1, 1, 1), IDR_TOOLBAR_PROJ) ||
		!m_wndProjToolBar.LoadToolBar(IDR_TOOLBAR_PROJ))
	{
		TRACE0("�� ������� ������� ������ ������������\n");
		return -1; // �� ������� �������
	}
	m_wndProjToolBar.ShowWindow(SW_HIDE);


	if (!m_wndFilterToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC, CRect(1, 1, 1, 1), IDR_FILTER) ||
		!m_wndFilterToolBar.LoadToolBar(IDR_FILTER))
	{
		TRACE0("�� ������� ������� ������ ������������\n");
		return -1; // �� ������� �������
	}
	if (!m_wndOperationsToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC, CRect(1, 1, 1, 1), IDR_OPERATIONS) ||
		!m_wndOperationsToolBar.LoadToolBar(IDR_OPERATIONS))
	{
		TRACE0("�� ������� ������� ������ ������������\n");
		return -1; // �� ������� �������
	}
	if (!m_wndToolsToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC, CRect(1, 1, 1, 1), IDR_TOOLS) ||
		!m_wndToolsToolBar.LoadToolBar(IDR_TOOLS))
	{
		TRACE0("�� ������� ������� ������ ������������\n");
		return -1; // �� ������� �������
	}


	CString strToolBarName;
	bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_STANDARD);
	ASSERT(bNameValid);
	m_wndToolBar.SetWindowText(strToolBarName);

	bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_VIEW);
	ASSERT(bNameValid);
	m_wndViewToolBar.SetWindowText(strToolBarName);

	bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_PROJ);
	ASSERT(bNameValid);
	m_wndProjToolBar.SetWindowText(strToolBarName);

	bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_FILTER);
	ASSERT(bNameValid);
	m_wndFilterToolBar.SetWindowText(strToolBarName);

	bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_OPERATIONS);
	ASSERT(bNameValid);
	m_wndOperationsToolBar.SetWindowText(strToolBarName);

	bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_TOOLS);
	ASSERT(bNameValid);
	m_wndToolsToolBar.SetWindowText(strToolBarName);

	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);
	m_wndToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	m_wndViewToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	m_wndFilterToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	m_wndOperationsToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	m_wndToolsToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);

	// ��������� �������� � ����������������� �������� ������������:
	InitUserToolbars(nullptr, uiFirstUserToolBarId, uiLastUserToolBarId);

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("�� ������� ������� ������ ���������\n");
		return -1; // �� ������� �������
	}
	m_wndStatusBar.SetPaneStyle(1, SBPS_NORMAL);

	CDockingManager::SetDockingMode(DT_SMART);

	m_wndMenuBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndViewToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndFilterToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndOperationsToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolsToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndMenuBar);
	DockPane(&m_wndToolsToolBar);
	DockPaneLeftOf(&m_wndToolBar, &m_wndToolsToolBar);
	DockPaneLeftOf(&m_wndOperationsToolBar, &m_wndToolsToolBar);
	DockPaneLeftOf(&m_wndViewToolBar, &m_wndOperationsToolBar);
	DockPaneLeftOf(&m_wndFilterToolBar, &m_wndViewToolBar);//,IDR_FILTER,&r);

	// �������� ����� ������ ������������ ���� ������ Visual Studio 2005
	// �������� ����� ������ ��������������� ������� ������������ ���� ������ Visual Studio 2005
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// ��������� ����������� �������� ���� (�� ����������� �� �����-���� ����������� ������� ������������):
	CMFCToolBar::AddToolBarForImageCollection(IDR_MENU_IMAGES, theApp.m_bHiColorIcons ? IDB_MENU_IMAGES_24 : 0);

	// ������� ������������ ����
	if (!CreateDockingWindows())
	{
		TRACE0("�� ������� ������� ������������ ����\n");
		return -1;
	}

	//m_wndFileView.EnableDocking(CBRS_ALIGN_ANY);
	//m_wndClassView.EnableDocking(CBRS_ALIGN_ANY);
	//DockPane(&m_wndFileView);
	//CDockablePane* pTabbedBar = nullptr;
	//m_wndClassView.AttachToTabWnd(&m_wndFileView, DM_SHOW, TRUE, &pTabbedBar);
	m_wndPipeTable.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndPipeTable, AFX_IDW_DOCKBAR_BOTTOM);
	m_wndProperties.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndProperties);

	// ���������� ��������� ��������� � ����� �� ������ ����������� ��������
	OnApplicationLook(theApp.m_nAppLook);

	// �������� ���������� ���� ������������ ���������� ������
	EnableWindowsDialog(ID_WINDOW_MANAGER, ID_WINDOW_MANAGER, TRUE);

	// �������� ������� ������ ���� ������� ������������ � ������������ ���� 
	EnablePaneMenu(TRUE, ID_VIEW_CUSTOMIZE, strCustomize, ID_VIEW_TOOLBAR);

	// �������� ������� (Alt+��������������) ��������� ������� ������������
	CMFCToolBar::EnableQuickCustomization();

	if (CMFCToolBar::GetUserImages() == nullptr)
	{
		// ��������� ����������� ���������������� ������� ������������
		if (m_UserImages.Load(_T(".\\UserImages.bmp")))
		{
			CMFCToolBar::SetUserImages(&m_UserImages);
		}
	}

	// �������� �������������� ���� (��������� �������������� �������)
	// TODO: ���������� ���� �������� ������� ���, ����� ������ �������������� ���� ��������� �� ������� ���� ���� �������� �������.
	CList<UINT, UINT> lstBasicCommands;

	lstBasicCommands.AddTail(ID_FILE_NEW);
	lstBasicCommands.AddTail(ID_FILE_OPEN);
	lstBasicCommands.AddTail(ID_FILE_SAVE);
	lstBasicCommands.AddTail(ID_FILE_PRINT);
	lstBasicCommands.AddTail(ID_APP_EXIT);
	lstBasicCommands.AddTail(ID_EDIT_CUT);
	lstBasicCommands.AddTail(ID_EDIT_PASTE);
	lstBasicCommands.AddTail(ID_EDIT_UNDO);
	lstBasicCommands.AddTail(ID_RECORD_NEXT);
	lstBasicCommands.AddTail(ID_RECORD_LAST);
	lstBasicCommands.AddTail(ID_APP_ABOUT);
	lstBasicCommands.AddTail(ID_VIEW_STATUS_BAR);
	lstBasicCommands.AddTail(ID_VIEW_TOOLBAR);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2003);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_VS_2005);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2007_BLUE);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2007_SILVER);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2007_BLACK);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2007_AQUA);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_WINDOWS_7);
	lstBasicCommands.AddTail(ID_SORTING_SORTALPHABETIC);
	lstBasicCommands.AddTail(ID_SORTING_SORTBYTYPE);
	lstBasicCommands.AddTail(ID_SORTING_SORTBYACCESS);
	lstBasicCommands.AddTail(ID_SORTING_GROUPBYTYPE);

	CMFCToolBar::SetBasicCommands(lstBasicCommands);

	// ����������� ������� ����� ��������� � ����� ���������� � ��������� ����. ���
	// �������� �������� ������������� ������ �����, ��� ��� �� ������ ������������ ��� ���������.
	ModifyStyle(0, FWS_PREFIXTITLE);
	//m_wndViewToolBar.RestoreOriginalstate();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CMDIFrameWndEx::PreCreateWindow(cs))
		return FALSE;
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return TRUE;
}

BOOL CMainFrame::CreateDockingWindows()
{
	BOOL bNameValid;

	/*	// ������� ������������� �������
		CString strClassView;
		bNameValid = strClassView.LoadString(IDS_CLASS_VIEW);
		ASSERT(bNameValid);
		if (!m_wndClassView.Create(strClassView, this, CRect(0, 0, 200, 200), TRUE, ID_VIEW_CLASSVIEW, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
		{
			TRACE0("�� ������� ������� ���� \"������������� �������\"\n");
			return FALSE; // �� ������� �������
		}
	
		// ������� ������������� ������
		CString strFileView;
		bNameValid = strFileView.LoadString(IDS_FILE_VIEW);
		ASSERT(bNameValid);
		if (!m_wndFileView.Create(strFileView, this, CRect(0, 0, 200, 200), TRUE, ID_VIEW_FILEVIEW, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT| CBRS_FLOAT_MULTI))
		{
			TRACE0("�� ������� ������� ���� \"������������� ������\"\n");
			return FALSE; // �� ������� �������
		}
	*/
		// ������� ���� ������
		CString strPipeTableWnd;
		bNameValid = strPipeTableWnd.LoadString(IDS_PIPE_TABLE_WND);
		ASSERT(bNameValid);
		if (!m_wndPipeTable.Create(strPipeTableWnd, this, CRect(0, 0, 100, 100), TRUE, ID_VIEW_PIPE_TABLE_WND, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_BOTTOM | CBRS_FLOAT_MULTI))
		{
			TRACE0("�� ������� ������� ���� \"������� ����\"\n");
			return FALSE; // �� ������� �������W
		}

	// ������� ���� �������
	CString strPropertiesWnd;
	bNameValid = strPropertiesWnd.LoadString(IDS_PROPERTIES_WND);
	ASSERT(bNameValid);
	if (!m_wndProperties.Create(strPropertiesWnd, this, CRect(0, 0, 200, 200), TRUE, ID_VIEW_PROPERTIESWND, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
	{
		TRACE0("�� ������� ������� ���� \"��������\"\n");
		return FALSE; // �� ������� �������
	}

	SetDockingWindowIcons(theApp.m_bHiColorIcons);
	return TRUE;
}

void CMainFrame::SetDockingWindowIcons(BOOL bHiColorIcons)
{
	/*
		HICON hFileViewIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_FILE_VIEW_HC : IDI_FILE_VIEW), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
		m_wndFileView.SetIcon(hFileViewIcon, FALSE);
	
		HICON hClassViewIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_CLASS_VIEW_HC : IDI_CLASS_VIEW), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
		m_wndClassView.SetIcon(hClassViewIcon, FALSE);
	
		HICON hOutputBarIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_OUTPUT_WND_HC : IDI_OUTPUT_WND), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
		m_wndOutput.SetIcon(hOutputBarIcon, FALSE);
	*/
	HICON hPropertiesBarIcon = HICON(::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_PROPERTIES_WND_HC : IDI_PROPERTIES_WND), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0));
	m_wndProperties.SetIcon(hPropertiesBarIcon, FALSE);

	UpdateMDITabbedBarsIcons();
}

// ����������� CMainFrame

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWndEx::Dump(dc);
}
#endif //_DEBUG



// ����������� ��������� CMainFrame

void CMainFrame::OnWindowManager()
{
	ShowWindowsDialog();
}

void CMainFrame::OnViewCustomize()
{
	CMFCToolBarsCustomizeDialog* pDlgCust = new CMFCToolBarsCustomizeDialog(this, TRUE /* ����������� ����*/);
	pDlgCust->EnableUserDefinedToolbars();
	pDlgCust->Create();
}

LRESULT CMainFrame::OnToolbarCreateNew(WPARAM wp, LPARAM lp)
{
	LRESULT lres = CMDIFrameWndEx::OnToolbarCreateNew(wp, lp);
	if (lres == 0)
	{
		return 0;
	}

	CMFCToolBar* pUserToolbar = reinterpret_cast<CMFCToolBar*>(lres);
	ASSERT_VALID(pUserToolbar);

	BOOL bNameValid;
	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);

	pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	return lres;
}

void CMainFrame::OnApplicationLook(UINT id)
{
	CWaitCursor wait;

	theApp.m_nAppLook = id;

	switch (theApp.m_nAppLook)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
		CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
		break;

	case ID_VIEW_APPLOOK_OFF_2003:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_VS_2005:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_VS_2008:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_WINDOWS_7:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	default:
		switch (theApp.m_nAppLook)
		{
		case ID_VIEW_APPLOOK_OFF_2007_BLUE:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_BLACK:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_SILVER:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_AQUA:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
			break;
		}

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
		CDockingManager::SetDockingMode(DT_SMART);
	}

	//m_wndOutput.UpdateFonts();
	RedrawWindow(nullptr, nullptr, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

	theApp.WriteInt(_T("ApplicationLook"), theApp.m_nAppLook);
}

void CMainFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}


BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext)
{
	// ������� ����� �� ��������

	if (!CMDIFrameWndEx::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
	{
		return FALSE;
	}


	// �������� ������ ��������� ��� ���� ���������������� ������� ������������
	BOOL bNameValid;
	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);

	for (int i = 0; i < iMaxUserToolbars; i ++)
	{
		CMFCToolBar* pUserToolbar = GetUserToolBarByIndex(i);
		if (pUserToolbar != nullptr)
		{
			pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
		}
	}
	return TRUE;
}


void CMainFrame::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	CMDIFrameWndEx::OnSettingChange(uFlags, lpszSection);
	//m_wndOutput.UpdateFonts();
}

LRESULT CMainFrame::OnToolbarReset(WPARAM wp, LPARAM)
{
	UINT uiToolBarId = UINT(wp);

	switch (uiToolBarId)
	{
	case IDR_VIEW_TOOLBAR:
		{
			CMenu mnuPopup;
			mnuPopup.LoadMenu(IDR_MENU_PROJ);
			CMenu* mnuPopupMenu = mnuPopup.GetSubMenu(0);
			ASSERT(mnuPopupMenu);
			CProjButton bn = CProjButton(ID_VIEW_3DVIEWS_TOP, mnuPopupMenu->m_hMenu, nullptr);
			//bn.SetMenuOnly(TRUE);
			m_wndViewToolBar.ReplaceButton(ID_VIEW_3DVIEWS_TOP, bn);
		}
		break;
	}

	return 0;
}


void CMainFrame::OnDestroy(void)
{
	SaveBarState(_T("Toolbars\\"));
	CMDIFrameWndEx::OnDestroy();
}


void CMainFrame::OnWindowTileVert()
{
	MDITile(MDITILE_VERTICAL);
}


void CMainFrame::OnPropMert()
{
	m_wndProperties.OnPropMert();
}


void CMainFrame::OnUpdatePropMert(CCmdUI* pCmdUI)
{
	m_wndProperties.OnUpdatePropMert(pCmdUI);
}


void CMainFrame::OnPropSk()
{
	m_wndProperties.OnPropSk();
}


void CMainFrame::OnUpdatePropSk(CCmdUI* pCmdUI)
{
	m_wndProperties.OnUpdatePropSk(pCmdUI);
}


void CMainFrame::OnPropNapr()
{
	m_wndProperties.OnPropNapr();
}


void CMainFrame::OnUpdatePropNapr(CCmdUI* pCmdUI)
{
	m_wndProperties.OnUpdatePropNapr(pCmdUI);
}


void CMainFrame::OnPropOtvIz()
{
	m_wndProperties.OnPropOtvIz();
}


void CMainFrame::OnUpdatePropOtvIz(CCmdUI* pCmdUI)
{
	m_wndProperties.OnUpdatePropOtvIz(pCmdUI);
}


void CMainFrame::OnPropOtvSv()
{
	m_wndProperties.OnPropOtvSv();
}


void CMainFrame::OnUpdatePropOtvSv(CCmdUI* pCmdUI)
{
	m_wndProperties.OnUpdatePropOtvSv(pCmdUI);
}


void CMainFrame::OnPropArm()
{
	m_wndProperties.OnPropArm();
}


void CMainFrame::OnUpdatePropArm(CCmdUI* pCmdUI)
{
	m_wndProperties.OnUpdatePropArm(pCmdUI);
}

void CMainFrame::OnUpdateIndFileCount(CCmdUI* pCmdUI)
{
	pCmdUI->Enable();
}

