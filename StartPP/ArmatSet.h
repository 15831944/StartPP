// ArmatSet.h: ��������� ������ CArmatSet
//
#include "MySet.h"

#pragma once

// ����������� ��� 7 ������� 2013 �., 20:42

class CArmatSet : public CMySet
{
public:
	CArmatSet(CDatabase* pDatabase = nullptr);
	DECLARE_DYNAMIC(CArmatSet)

	// ������ ����� � ����������

	// ��������� ���� ����� (���� ������������) �������� ����������� ���� ������ 
	// ���� ���� ������ - CStringA ��� ����� ������ ANSI � CStringW ��� ����� 
	// ������ �������. ��� ������ ������������� ���������� ��������� ODBC 
	// ������������ �������� ��������������. ��� ������� ����� �������� ��� ����� �� 
	// ���� CString, � ������� ODBC �������� ��� ����������� ��������������.
	// (����������. ���������� ������������ ������� ODBC ������ 3.5 ��� ����� ������� 
	// ��� ��������� ��� �������, ��� � ���� ��������������).

	float m_DIAM;
	float m_NOTO;
	float m_RATO;
	float m_RAOT;
	float m_VESA;
	float m_RAOT1;
	float m_VESA1;
	float m_NAG1;
	float m_NAG2;

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

