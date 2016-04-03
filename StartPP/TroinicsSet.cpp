// TroinicsSet.cpp : ���������� ������ CTroinicsSet
//

#include "stdafx.h"
#include "TroinicsSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� CTroinicsSet

// ����������� ��� 9 ������� 2013 �., 19:49

IMPLEMENT_DYNAMIC(CTroinicsSet, CMySet)

CTroinicsSet::CTroinicsSet(CDatabase* pdb)
	: CMySet(pdb)
{
	m_DIAM = 0.0;
	m_DIAMSH = 0.0;
	m_NTSTM = 0.0;
	m_RTSTM = 0.0;
	m_NTSTSH = 0.0;
	m_RTSTSH = 0.0;
	m_WIDTHNAK = 0.0;
	m_THINKNAK = 0.0;
	m_VES = 0.0;
	m_VIS_SHTU = 0;
	m_KORPUS = 0;
	m_nFields = 11;
	m_nDefaultType = dynaset;
}


void CTroinicsSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
	// ����� �������, ��� RFX_Text() � RFX_Int(), ������� �� ���� 
	// ���������� �����, � �� �� ���� ���� � ���� ������.
	// ODBC ��������� ������� ������������� ������������� �������� ������� � ������� ����
	RFX_Single(pFX, _T("[DIAM]"), m_DIAM);
	RFX_Single(pFX, _T("[DIAMSH]"), m_DIAMSH);
	RFX_Single(pFX, _T("[NTSTM]"), m_NTSTM);
	RFX_Single(pFX, _T("[RTSTM]"), m_RTSTM);
	RFX_Single(pFX, _T("[NTSTSH]"), m_NTSTSH);
	RFX_Single(pFX, _T("[RTSTSH]"), m_RTSTSH);
	RFX_Single(pFX, _T("[WIDTHNAK]"), m_WIDTHNAK);
	RFX_Single(pFX, _T("[THINKNAK]"), m_THINKNAK);
	RFX_Single(pFX, _T("[VES]"), m_VES);
	RFX_Int(pFX, _T("[VIS_SHTU]"), m_VIS_SHTU);
	RFX_Int(pFX, _T("[KORPUS]"), m_KORPUS);
}

/////////////////////////////////////////////////////////////////////////////
// CTroinicsSet �����������

#ifdef _DEBUG
void CTroinicsSet::AssertValid() const
{
	CMySet::AssertValid();
}

void CTroinicsSet::Dump(CDumpContext& dc) const
{
	CMySet::Dump(dc);
}
#endif //_DEBUG


