#pragma once

class CMySet : public CRecordset
{
public:
	CMySet(CDatabase* pDatabase = nullptr);
	DECLARE_DYNAMIC(CMySet)

	CString m_strPath;
	CString m_strTable;
	CString GetDefaultConnect() override; // ������ ����������� �� ���������

	CString GetDefaultSQL() override; // ��� SQL �� ��������� ���  ������ �������

	// ����������
#ifdef _DEBUG
	void AssertValid() const override;
	void Dump(CDumpContext& dc) const override;
#endif
};

