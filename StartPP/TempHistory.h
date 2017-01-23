#pragma once
#include <vector>

struct STempHistRec
{
	float Temp; // ������������� ����������� 
	int Sequency; // ������� ����� �� ������
	int Period; // ������ ����� 0-����, 1-������, 2-�����, 3-��� 
};

class CTempHistory
{
public:
	CTempHistory(void);
	~CTempHistory(void);
	float Tmax; // ���������� ����������� � ������������
	std::vector<STempHistRec> m_vecRec;
	void Add(float Temp, int Sequency, int Period);

	void WriteIni(CStdioFile& file);
};

