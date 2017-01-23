// StartPP.cpp : ���������� ��������� ������� ��� ����������.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "StartPP.h"
#include "resource.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "StartPPDoc.h"
#include "StartPPView.h"
#include <Odbcinst.h>
#include <locale.h>

extern "C" int __stdcall _imp___vsnprintf(
	char* buffer,
	size_t count,
	const char* format,
	va_list argptr
)
{
	return vsnprintf(buffer, count, format, argptr);
}


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStartPPApp

BEGIN_MESSAGE_MAP(CStartPPApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CStartPPApp::OnAppAbout)
	// ����������� ������� �� ������ � ������� ����������
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// ����������� ������� ��������� ������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
	ON_COMMAND(ID_IMPORT_DBF, &CStartPPApp::OnImportDbf)
	END_MESSAGE_MAP()


// �������� CStartPPApp

CStartPPApp::CStartPPApp()
{
	EnableHtmlHelp();
	m_bHiColorIcons = TRUE;

	// ��������� ���������� ������������
	//m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ���� ���������� ��������� � ���������� ����� Common Language Runtime (/clr):
	//     1) ���� �������������� �������� ��������� ��� ���������� ��������� ������ ���������� ������������.
	//     2) � ����� ������� ��� ���������� ���������� �������� ������ �� System.Windows.Forms.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: �������� ���� ������ �������������� ���������� ������� ����������� ��������������; �������������
	// ������ ��� ������: �����������.�����������.����������.���������������
	//SetAppID(_T("StartPP.AppID.NoVersion"));

	// TODO: �������� ��� ��������,
	// ��������� ���� ������ ��� ������������� � InitInstance
}

// ������������ ������ CStartPPApp

CStartPPApp theApp;


// ������������� CStartPPApp

BOOL CStartPPApp::InitInstance()
{
	setlocale(LC_ALL, "");
	// InitCommonControlsEx() ��������� ��� Windows XP, ���� ��������
	// ���������� ���������� ComCtl32.dll ������ 6 ��� ����� ������� ������ ��� ���������
	// ������ �����������. � ��������� ������ ����� ��������� ���� ��� �������� ������ ����.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �������� ���� �������� ��� ��������� ���� ����� ������� ����������, ������� ���������� ������������
	// � ����� ����������.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// ������������� ��������� OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();
#ifdef _M_AMD64
	BOOL RES = SQLConfigDataSource(nullptr,ODBC_ADD_DSN, _T("Microsoft Access Driver (*.mdb, *.accdb)"),
	                               _T("DSN=DBF\0")
	                               _T("DBQ=C:\\DBF\0")
	                               //_T("Driver=C:\\Windows\\system32\\odbcjt32.dll\0") 
	                               _T("FIL=MS Access\0\0") /* 
					_T("MaxScanRows=20\0\0")*/);

	RES = SQLConfigDataSource(nullptr,ODBC_ADD_DSN, _T("Microsoft Access dBASE Driver (*.dbf, *.ndx, *.mdx)"),
	                          _T("DSN=dBASE Files\0")
	                          _T("DBQ=C:\\DBF\0")
	                          _T("FIL=dBASE IV;\0\0"));

#else
		BOOL RES =SQLConfigDataSource(nullptr,ODBC_ADD_DSN, _T("Microsoft Access Driver (*.mdb)"), 
                   _T("DSN=DBF\0") 
				   _T("DBQ=C:\\DBF\0")
	//_T("Driver=C:\\Windows\\system32\\odbcjt32.dll\0") 
					_T("FIL=MS Access\0\0") /* 
					_T("MaxScanRows=20\0\0")*/);
		ASSERT(RES);
		RES =SQLConfigDataSource(nullptr,ODBC_ADD_DSN, _T("Microsoft dBase Driver (*.dbf)"), 
                   _T("DSN=dBASE Files\0") 
				   _T("DBQ=C:\\DBF\0")
					_T("FIL=dBASE IV;\0\0"));
		ASSERT(RES);


#endif
	//EnableTaskbarInteraction();

	// ��� ������������� �������� ���������� RichEdit ��������� ����� AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ����������� �������������
	// ���� ��� ����������� �� ������������ � ���������� ��������� ������
	// ��������� ������������ �����, ���������� ������� �� ����������
	// ���������� ��������� �������������, ������� �� ���������
	// �������� ������ �������, � ������� �������� ���������
	// TODO: ������� �������� ��� ������ �� ���-������ ����������,
	// �������� �� �������� �����������
	SetRegistryKey(_T("MIP3"));
	LoadStdProfileSettings(4); // ��������� ����������� ��������� INI-����� (������� MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
	                                                                 RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ��������������� ������� ���������� ����������. ������� ����������
	//  ��������� � ���� ���������� ����� �����������, ������ ����� � ���������������
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_StartPPTYPE,
	                                                    RUNTIME_CLASS(CStartPPDoc),
	                                                    RUNTIME_CLASS(CChildFrame), // ������������� �������� ����� MDI
	                                                    RUNTIME_CLASS(CStartPPView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// �������� ������� ���� ����� MDI
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// ��������� ������������� ����������� �������� � ������� �������� ����
	CMFCToolBar::m_bExtCharTranslation = TRUE;

	// �������������� ������ ��������� ������ �� ����������� ������� ��������, DDE, �������� ������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// ������� ���������������, ��������� � ��������� ������. �������� FALSE ����� ����������, ����
	// ���������� ���� �������� � ���������� /RegServer, /Register, /Unregserver ��� /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	RegisterShellFileTypes();
	// ������� ���� ���� ����������������, ������� ���������� � �������� ���
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
	setlocale(LC_ALL, "");
	return TRUE;
}

int CStartPPApp::ExitInstance()
{
	//TODO: ����������� �������������� �������, ������� ����� ���� ���������
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// ����������� ��������� CStartPPApp


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ������ ����������� ����
	enum
	{
		IDD = IDD_ABOUTBOX
	};

protected:
	void DoDataExchange(CDataExchange* pDX) override; // ��������� DDX/DDV

	// ����������
protected:
	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog() override;
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	END_MESSAGE_MAP()

// ������� ���������� ��� ������� �������
void CStartPPApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CStartPPApp ��������� ������� �������� � ����������

void CStartPPApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_TABLE);

	//bNameValid = strName.LoadString(IDS_EXPLORER);
	//ASSERT(bNameValid);
	//GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CStartPPApp::LoadCustomState()
{
}

void CStartPPApp::SaveCustomState()
{
}

// ����������� ��������� CStartPPApp


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	DWORD dwHandle = 0;
	unsigned uiDataSize = 80;

	PWSTR pData = nullptr;
	WCHAR buff[80];
	// Get the version information block size,
	// then use it to allocate a storage buffer.
	CString strExeName = AfxGetApp()->m_pszExeName;
	strExeName += _T(".exe");
	DWORD dwSize = ::GetFileVersionInfoSize(LPCTSTR(strExeName), &dwHandle);
	void* pBuffer = malloc(dwSize);
	if (!pBuffer)
		return TRUE;
	// Get the version information block
	::GetFileVersionInfo(LPCTSTR(strExeName), 0, dwSize, pBuffer);
	//Use the version information block to obtain the file version.
	::VerQueryValue(pBuffer,
	                TEXT("\\StringFileInfo\\041904b0\\FileVersion"),
	                reinterpret_cast<void **>(&pData),
	                &uiDataSize);
	wcsncpy_s(buff, pData, uiDataSize + 1);
	pData = buff;
#ifdef _DEBUG
	wcscat_s(pData, uiDataSize + 1, _T("D"));
#endif
#ifdef _M_AMD64
	wcscat_s(pData, uiDataSize + 5, _T(" x64"));
#endif

	if (pData)
		GetDlgItem(IDC_ABOUT_VER)->SetWindowText(pData);
	free(pBuffer);
	// TODO: Add extra initialization here

	return TRUE; // return TRUE unless you set the focus to a control
}


void CStartPPApp::OnImportDbf()
{
	POSITION pos = m_pDocManager->GetFirstDocTemplatePosition();

	CDocTemplate* pDocTemplate = m_pDocManager->GetNextDocTemplate(pos);
	CStartPPDoc* pDoc = dynamic_cast<CStartPPDoc*>(pDocTemplate->OpenDocumentFile(nullptr));
	pDoc->OnImportDbf();
}

