#include "stdafx.h"
#include <wx/window.h>
#include "PipeGrid.h"
#include <wx/grid.h>
#include "PipeTable.h"
#include "Material.h"
#include "PipesSet.h"
#include "main.h"
#include "MainFrame.h"
#include <algorithm>


BEGIN_EVENT_TABLE(PipeGrid, wxGrid)
	EVT_GRID_SELECT_CELL(PipeGrid::OnGridSelectCell)
	EVT_GRID_RANGE_SELECT(PipeGrid::OnGridRangeSelect)
END_EVENT_TABLE()

PipeGrid::PipeGrid(wxWindow *pWin, wxStandardID id, const wxPoint point, wxSize size, int i) :
		wxGrid(pWin, id, point, size,i), m_bExternalSelection(false), m_pTable(nullptr)
{
}

PipeGrid::~PipeGrid()
{
	SetTable(nullptr);
	wxDELETE(m_pTable);
}

void PipeGrid::SetColFormat()
{
	for (int i = 0; i <= 4;i++)
		SetColFormatFloat(i,-1,3);
	SetColFormatFloat(5,-1,1);
	SetColFormatFloat(6,-1,1);
	SetColFormatFloat(7,-1,1);
	SetColFormatFloat(8,-1,0);
	SetColFormatFloat(9, -1, 0);

	for (int i = 0;i < GetNumberRows();i++)
	{
		MainFrame *frame = wxStaticCast(wxGetApp().GetTopWindow(), MainFrame);
		CStartPPDoc* pDoc = frame->m_pDoc;
		BOOL bPodzem = pDoc->m_pipes.m_vecPnN[i].isPodzem();
		std::vector<float> vecDiams;
		CPipesSet set;
		set.m_strPath = DATA_PATH;
		set.m_strTable = _T("Pipes.dbf"); // set.m_strTable.Format(_T("[Pipes] where %d=PODZ order by DIAM"), int(bPodzem));
		set.Open();
		for (; !set.IsEOF(); set.MoveNext())
		{
			if (bPodzem != set.m_PODZ)
				continue;
			vecDiams.push_back(set.m_DIAM);
		}
		set.Close();
		std::sort(vecDiams.begin(), vecDiams.end());
		wxArrayString ar;
		for (auto x : vecDiams)
			ar.push_back(CString::Format(_T("%g"), x));
		SetCellEditor(i, 9, new wxGridCellChoiceEditor(ar,true));

	}
	for (int i=0;i<GetNumberRows();i++)
    {
         CMaterial setMaterial;
         setMaterial.m_strPath = DATA_PATH;
         setMaterial.m_strTable = _T("Matup.dbf");// _T("[MATUP]  order by NOM");
         setMaterial.Open();
         wxArrayString ar;
         while (!setMaterial.IsEOF())
         {
             ar.Add(CString(setMaterial.m_MAT));
             setMaterial.MoveNext();
         }
	    SetCellEditor(i, 10, new wxGridCellChoiceEditor(ar));
    }
	SetColFormatFloat(11,-1,1);
	SetColFormatFloat(12,-1,2);
	SetColFormatFloat(13,-1,1);
	SetColFormatFloat(14,-1,1);
	SetColFormatFloat(15,-1,1);
	for (int i=16; i<=20;i++)
		SetColFormatFloat(i, -1, 2);
	for (int i=21; i<=25;i++)
		SetColFormatFloat(i, -1, 0);
	for (int i=26; i<=29;i++)
		SetColFormatFloat(i, -1, 2);
	SetColFormatFloat(30,-1,1);
	for (int i=31; i<=33;i++)
		SetColFormatFloat(i, -1, 0);
	SetColFormatBool(34);

}

void PipeGrid::OnGridSelectCell(wxGridEvent& event)
{
	if (!event.Selecting()|| m_bExternalSelection)
		return;
	MainFrame *frame = wxStaticCast(wxGetApp().GetTopWindow(), MainFrame);
	CStartPPDoc* pDoc = frame->m_pDoc;
	pDoc->vecSel.clear();
	frame->m_bDontRefresh = true;
	pDoc->Select(pDoc->m_pipes.m_vecPnN[event.GetRow()].m_NAYZ, pDoc->m_pipes.m_vecPnN[event.GetRow()].m_KOYZ);
	frame->m_bDontRefresh = false;
	event.Skip();
}

void PipeGrid::OnGridRangeSelect(wxGridRangeSelectEvent& event)
{
	if (!event.Selecting()||m_bExternalSelection)
		return;
	MainFrame *frame = wxStaticCast(wxGetApp().GetTopWindow(), MainFrame);
	CStartPPDoc* pDoc = frame->m_pDoc;
	pDoc->vecSel.clear();
	pDoc->m_pipes.m_nIdx = event.GetTopRow();
	for (int i=event.GetTopRow(); i<=event.GetBottomRow();i++)
	{
		const CPipeAndNode &p = pDoc->m_pipes.m_vecPnN[i];
		SelStr s(int(p.m_NAYZ), int(p.m_KOYZ));
		pDoc->vecSel.insert(s);
	}
	frame->m_bDontRefresh = true;
	pDoc->UpdateData(false);
	frame->m_bDontRefresh = false;
}

void PipeGrid::ResetTable()
{
	if (!m_pTable)
		m_pTable = new PipeTable;
	SetTable(m_pTable);
}

void PipeGrid::RefreshGrid(CStartPPDoc *pDoc)
{
	if (unsigned(GetNumberRows())!=pDoc->m_pipes.m_vecPnN.size())
		ResetTable();
	bool bAdd = false;
	BeginSelect();
	for (size_t i = 0;i < pDoc->m_pipes.m_vecPnN.size(); i++)
	{
		CPipeAndNode& p = pDoc->m_pipes.m_vecPnN[i];
		if (pDoc->vecSel.Contains(p.m_NAYZ, p.m_KOYZ))
		{
			if (!bAdd)
				MakeCellVisible(i, GetSelectedCols().size()>0? GetSelectedCols()[0]:0);
			SelectRow(i, bAdd);
			bAdd = true;
		}
	}
	EndSelect();

	ForceRefresh();

}

