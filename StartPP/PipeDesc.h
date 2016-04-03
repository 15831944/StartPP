#pragma once
class CPipeDesc
{
public:
	CPipeDesc(void);
	~CPipeDesc(void);
	CString Date; //���� ������� � ������� (��.��.����)
	CString Description; //� ������� �� ������������ �� ����� (������)
	CString NormaDoc; // �������� ������������ ���������
	float TSet; // ����������� ������� (��. �)
	float Tcold; // ����������� ����� ���������� (��. �) 
	int CalcStartComp; // ������� ������� ��������� �������������
	//0 � ������ ��������� ������������� �� ���������, 1 - ���������
	float Tz; // ����������� ������� ��������� ������������� (��. �) 
	float TimeWork; // ��������� ���� ������ ������������ (����) 
	CString Envir; // ����� ��������� ������������ 
	float Ttest; // ����������� ��������� (��.�)  
	CString NormaSpring; // ������� ��� ������� ������ 
	int CondSelSpring; //  ��������� ������������ ��� ������� ������ (��������\�������)
	//0 � ������� 1 - ��������  
	void Serialize(CArchive& ar);
	void WriteIni(CStdioFile& file);
};

