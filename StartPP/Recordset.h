#pragma once
#include "wx\object.h"

class CRecordset : public wxObject
{
public:
	int m_nFields;
	enum { dynaset } m_nDefaultType;

	virtual CString GetDefaultConnect();  // ������ ����������� �� ���������
	virtual CString GetDefaultSQL(); // ��� SQL �� ��������� ���  ������ �������
	virtual void DoFieldExchange(CFieldExchange* pFX); // ��������� RFX
	bool Open() { return true; }
	bool IsEOF() { return false; }
	void MoveNext() {}
	void Close() {}
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};