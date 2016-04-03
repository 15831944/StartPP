// StartPP.h : ������� ���� ��������� ��� ���������� StartPP
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif


// CStartPPApp:
// � ���������� ������� ������ ��. StartPP.cpp
//

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

	void PreLoadState() override;
	void LoadCustomState() override;
	void SaveCustomState() override;

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnImportDbf();
};

extern CStartPPApp theApp;

