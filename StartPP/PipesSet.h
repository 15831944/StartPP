// PipesSet.h: ��������� ������ CPipesSet
//
#include "MySet.h"

#pragma once

// ����������� ��� 31 ������ 2013 �., 22:33

class CPipesSet : public CMySet
{
public:
	CPipesSet(CDatabase* pDatabase = nullptr);
	DECLARE_DYNAMIC(CPipesSet)

	// ������ ����� � ����������

	// ��������� ���� ����� (���� ������������) �������� ����������� ���� ������ 
	// ���� ���� ������ - CStringA ��� ����� ������ ANSI � CStringW ��� ����� 
	// ������ �������. ��� ������ ������������� ���������� ��������� ODBC 
	// ������������ �������� ��������������. ��� ������� ����� �������� ��� ����� �� 
	// ���� CString, � ������� ODBC �������� ��� ����������� ��������������.
	// (����������. ���������� ������������ ������� ODBC ������ 3.5 ��� ����� ������� 
	// ��� ��������� ��� �������, ��� � ���� ��������������).

	float m_DIAM;
	float m_NTOS;
	float m_RTOS;
	CStringA m_NAMA;
	float m_VETR;
	float m_VEIZ;
	float m_VEPR;
	float m_DIIZ;
	float m_RAOT;
	float m_VESA;
	CStringA m_MARI;
	float m_NOTO;
	float m_RATO;
	float m_SEFF;
	float m_KPOD;
	float m_SHTR;
	BOOL m_PODZ;
	float m_IZTO;

	// ���������������
	// ������ ������ ��������������� ����������� �������
	void DoFieldExchange(CFieldExchange* pFX) override; // ��������� RFX

	// ����������
#ifdef _DEBUG
	void AssertValid() const override;
	void Dump(CDumpContext& dc) const override;
#endif
};

