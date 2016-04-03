// MFCApplication1Set.h: ��������� ������ CStartPPSet
//

#include "PipeAndNode.h"

#pragma once

// ����������� ��� 1 ������� 2012 �., 18:46


class CStartPPSet : public CRecordset, public CPipeAndNode
{
public:
	CStartPPSet(CDatabase* pDatabase = nullptr);
	DECLARE_DYNAMIC(CStartPPSet)

	// ������ ����� � ����������

	// ��������� ���� ����� (���� ������������) �������� ����������� ���� ������ 
	// ���� ���� ������ - CStringA ��� ����� ������ ANSI � CStringW ��� ����� 
	// ������ �������. ��� ������ ������������� ���������� ��������� ODBC 
	// ������������ �������� ��������������. ��� ������� ����� �������� ��� ����� �� 
	// ���� CString, � ������� ODBC �������� ��� ����������� ��������������.
	// (����������. ���������� ������������ ������� ODBC ������ 3.5 ��� ����� ������� 
	// ��� ��������� ��� �������, ��� � ���� ��������������).

	// ���������������
	// ������ ������ ��������������� ����������� �������
public:
	CString m_strPath;
	CString m_strTable;
	CString GetDefaultConnect() override; // ������ ����������� �� ���������

	CString GetDefaultSQL() override; // ��� SQL �� ��������� ���  ������ �������
	void DoFieldExchange(CFieldExchange* pFX) override; // ��������� RFX

	// ����������
#ifdef _DEBUG
	void AssertValid() const override;
	void Dump(CDumpContext& dc) const override;
#endif
	void SetOldSet(bool bOldSet)
	{
		m_bOldSet = bOldSet;
		m_nFields = m_bOldSet ? 58 : 67;
	}

protected:
	bool m_bOldSet;
};

