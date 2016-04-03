// TroinicsSet.h: ��������� ������ CTroinicsSet
//
#include "MySet.h"

#pragma once

// ����������� ��� 9 ������� 2013 �., 19:49

class CTroinicsSet : public CMySet
{
public:
	CTroinicsSet(CDatabase* pDatabase = nullptr);
	DECLARE_DYNAMIC(CTroinicsSet)

	// ������ ����� � ����������

	// ��������� ���� ����� (���� ������������) �������� ����������� ���� ������ 
	// ���� ���� ������ - CStringA ��� ����� ������ ANSI � CStringW ��� ����� 
	// ������ �������. ��� ������ ������������� ���������� ��������� ODBC 
	// ������������ �������� ��������������. ��� ������� ����� �������� ��� ����� �� 
	// ���� CString, � ������� ODBC �������� ��� ����������� ��������������.
	// (����������. ���������� ������������ ������� ODBC ������ 3.5 ��� ����� ������� 
	// ��� ��������� ��� �������, ��� � ���� ��������������).

	float m_DIAM;
	float m_DIAMSH;
	float m_NTSTM;
	float m_RTSTM;
	float m_NTSTSH;
	float m_RTSTSH;
	float m_WIDTHNAK;
	float m_THINKNAK;
	float m_VES;
	int m_VIS_SHTU;
	int m_KORPUS;

	// ���������������
	// ������ ������ ��������������� ����������� �������
public:
	void DoFieldExchange(CFieldExchange* pFX) override; // ��������� RFX

	// ����������
#ifdef _DEBUG
	void AssertValid() const override;
	void Dump(CDumpContext& dc) const override;
#endif
};

