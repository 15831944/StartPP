// StartPP.h : ������� ���� ��������� ��� ���������� StartPP
//
#pragma once

// CStartPPApp:
// � ���������� ������� ������ ��. StartPP.cpp
//

class CWinAppEx
{
public:
	virtual BOOL InitInstance() { return TRUE; };
	virtual int ExitInstance() { return 0; };

};

class CStartPPApp : public CWinAppEx
{
public:
	CStartPPApp();


	// ���������������
public:
	BOOL InitInstance() override;
	int ExitInstance() override;

	// ����������
	UINT m_nAppLook;
	BOOL m_bHiColorIcons;
	/*
	void PreLoadState() override;
	void LoadCustomState() override;
	void SaveCustomState() override;
	*/
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnImportDbf();
};

extern CStartPPApp theApp;

