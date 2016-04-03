#pragma once
#include <vector>
#include <map>

//enum TLookMode {LOOK_IN,LOOK_OUT};
enum TNodeElement
{
	elNone,
	elMertOp,
	elSkOp,
	elNaprOp,
	elCompOs,
	elCompUg,
	elArmat,
	elOtvodS,
	elOtvodI,
	elOtvodF,
	elDiamChange,
	elRast,
	elSg,
	elGestPd,
	elUprOp,
	elSelect,
	elTroinic
};

class CPipeAndNode;

// ��������� ������� �����
typedef struct
{
	int StrP;
	int EndP; // ����� �������� ����� ������� (-1 - ������� �����������)
	float dx, dy, dz; // ���������. �������
	float Diam; // ������� � ��
	float VIZA; // ������ ������� � �
	float VIZA2;
	float R_Otv; // ������ ������, � ��� ����� ������������ (��. � ���.)

	TNodeElement MNEA; // �������
	TNodeElement MNEO; // �����
	TNodeElement TIDE; // ����������

	bool Drawed, // ����� ��������� � ��������� ���
	     Seen, // ���������� ������

	     Podzem, // ��������� �� �������
	     Podush; // ������� �� �������
	int P_type; // ��� �����
	int INDX;
	int i, j;
	float NaprStr, NaprEnd, NaprDop;
	CPipeAndNode* m_pPnN;
} Pipe;

// ����� ����� � ������

typedef struct
{
public:
	//Pipe_type() : NAMA(_T("") {};
	float Diam;
	CString NAMA;
	float NTOS;
	float VETR;
	float VEIZ;
	float VEPR;
	float RATE;
	float rada;
	bool Podzem;
} Pipe_type; // ��������� ��� ��������� ����� ����


class CPipeAndNode;
class CRotator;

typedef std::multimap<int, Pipe>::iterator pipe_iter;
typedef std::pair<int, Pipe> pipe_pair;
typedef std::multimap<int, pipe_iter>::iterator ret_iter;
typedef std::pair<int, pipe_iter> ret_pair;

class CPipeArrayContext
{
public:
	//TLookMode LookMode;
	//bool LookFirst;
	int PntNum;
	int Idx;
	//int PntSucNum;
	//int RetPntNum;
	//int RetPntSucNum;
	//pipe_iter it_pipe;
	//ret_iter it_ret;
};

typedef struct
{
	int StrP, EndP;
	int x1, y1, x2, y2;
	float dx, dy, dz;
	float Diam;
} Interval_;

class CPipeArray
{
private:
	std::multimap<int, Pipe> pipes;
	// �������� ������ �� ������� - �� ������ �������� ����� ���� ��������� �����
	// ������� ��� �������� ������
	// (����� ���������� �������, �������� � ������ ����)
	std::multimap<int, pipe_iter> Ret;

public:
	// ��� ����� (����� ���������)
	// ������ ����� ����
	std::vector<Interval_> Intervals;
	std::vector<Pipe_type> Pipe_types;
	//int Cur_pipe_type;
	void Rotate(CRotator* Rot);
	bool Pipe_check(const CPipeAndNode* pPnN, int i);
	int Set_pipe_type(const CPipeAndNode* pPnN);
	void copy_pipes(const std::vector<CPipeAndNode>& vec, const CRotator* Rot = nullptr);
	void copy_pipes_1(CPipeArray* PipeArray, CRotator* Rot);

	CPipeArray()
	{
	};

	CPipeArray(CPipeArray* PipeArray, CRotator* Rot)
	{
		*this = *PipeArray;
		Rotate(Rot);
	}

	CPipeArray(const std::vector<CPipeAndNode>& vec)
	{
		copy_pipes(vec);
	}

	inline int OutCount(int NodeNum)
	{
		return int(pipes.count(NodeNum));
	}

	bool HasOut(int NodeNum);
	bool HasOut(CPipeArrayContext cnt);
	bool HasOutNext(CPipeArrayContext cnt);
	Pipe& OutFirst(int NodeNum, CPipeArrayContext& cnt);
	Pipe& OutNext(CPipeArrayContext& cnt);

	inline int InCount(int NodeNum)
	{
		return int(Ret.count(NodeNum));
	}

	bool HasIn(int NodeNum);
	bool HasIn(CPipeArrayContext cnt);
	bool HasInNext(CPipeArrayContext cnt);
	Pipe& InFirst(int NodeNum, CPipeArrayContext& cnt);
	Pipe& InNext(CPipeArrayContext& cnt);

	void _fastcall Init();
	void FindNotDrawn(int& i, bool& Found);
	//void  SetLookMode(int NodeNum, TLookMode lm, CPipeArrayContext & cnt);
	//bool HasNext(CPipeArrayContext & cnt);
	//Pipe &  GetPipe(CPipeArrayContext & cnt);
	bool CheckConnectivity(void);
	void Scan(int nStartP);

	std::multimap<int, Pipe>& GetPipes()
	{
		return pipes;
	}
};

