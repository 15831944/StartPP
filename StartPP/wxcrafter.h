//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _STARTPP_STARTPP_WXCRAFTER_BASE_CLASSES_H
#define _STARTPP_STARTPP_WXCRAFTER_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/frame.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/docview.h>
#include <wx/docmdi.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/aui/framemanager.h>
#include <wx/aui/dockart.h>
#include <wx/pen.h>
#include <wx/aui/auibar.h>
#include <map>
#include <wx/toolbar.h>
#include <wx/aui/auibook.h>
#include <wx/simplebook.h>
#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/dialog.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/listbox.h>
#include <wx/spinctrl.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>
#include <wx/notebook.h>
#include <wx/statbmp.h>
#include <wx/grid.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif


class MainFrameBaseClass : public wxDocParentFrame
{
public:
    enum {
        wxID_ADD_SCHEM = 10001,
        wxID_ARMAT_TABLE = 10002,
        wxID_COPY_PIPE_PARAMS = 10003,
        wxID_DEL_NODE = 10004,
        wxID_DEL_PIPE = 10005,
        wxID_DISTANCE = 10006,
        wxID_EXPORT_INI = 10007,
        wxID_INVERT_PIPE = 10008,
        wxID_ImportDbf = 10009,
        wxID_MOVE_NODE = 10010,
        wxID_MULT_PIPE = 10011,
        wxID_NEW_NODE = 10012,
        wxID_NEW_PIPE = 10013,
        wxID_PAN = 10014,
        wxID_PIPE_DESC = 10015,
        wxID_PIPE_TABLE = 10016,
        wxID_PROJ = 10017,
        wxID_PROP_ARMAT = 10018,
        wxID_PROP_MERT = 10019,
        wxID_PROP_NAPR = 10020,
        wxID_PROP_OTV_IZ = 10021,
        wxID_PROP_OTV_SV = 10022,
        wxID_PROP_SK = 10023,
        wxID_RECORD_FIRST = 10024,
        wxID_RECORD_LAST = 10025,
        wxID_RECORD_NEXT = 10026,
        wxID_RECORD_PREV = 10027,
        wxID_REDO1 = 10028,
        wxID_RENUM_PIPES = 10029,
        wxID_ROTATE = 10030,
        wxID_SELECT = 10031,
        wxID_SHOW_OGL = 10032,
        wxID_Spusk = 10033,
        wxID_TB_FILTER = 10034,
        wxID_TROINICS_TABLE = 10035,
        wxID_UNDO1 = 10036,
        wxID_VIEW_3DVIEWS_BACK = 10037,
        wxID_VIEW_3DVIEWS_BOTTOM = 10038,
        wxID_VIEW_3DVIEWS_DIMETRY = 10039,
        wxID_VIEW_3DVIEWS_FRONT = 10040,
        wxID_VIEW_3DVIEWS_LEFT = 10041,
        wxID_VIEW_3DVIEWS_NE_ISO = 10042,
        wxID_VIEW_3DVIEWS_NW_ISO = 10043,
        wxID_VIEW_3DVIEWS_RIGHT = 10044,
        wxID_VIEW_3DVIEWS_SE_ISO = 10045,
        wxID_VIEW_3DVIEWS_SW_ISO = 10046,
        wxID_VIEW_3DVIEWS_TOP = 10047,
        wxID_VIEW_APROF = 10048,
        wxID_VIEW_ELEMENTS = 10049,
        wxID_VIEW_NODES = 10050,
        wxID_VIEW_NODE_NUMS = 10051,
        wxID_VIEW_SIZES = 10052,
        wxID_ViewZoomIn = 10053,
        wxID_ViewZoomOut = 10054,
        wxID_ZOOM_ALL = 10055,
        wxID_ZOOM_WIN = 10056,
    };
protected:
    wxMenuBar* m_menuBar;
    wxMenu* m_menuFile;
    wxMenuItem* m_menuItemFileNew;
    wxMenuItem* m_menuItemFileOpen;
    wxMenuItem* m_menuItemFileClose;
    wxMenuItem* m_menuItemFileSave;
    wxMenuItem* m_menuItemSaveAs;
    wxMenuItem* m_menuItemSep1;
    wxMenuItem* m_menuItemFilePipeDesc;
    wxMenu* m_menuDatabases;
    wxMenuItem* m_menuItemPipeTable;
    wxMenuItem* m_menuItemArmatTable;
    wxMenuItem* m_menuItemTroinicsTable;
    wxMenu* m_menuImport;
    wxMenuItem* m_menuItemImportDbf;
    wxMenuItem* m_menuItemImportScheme;
    wxMenu* m_menuExport;
    wxMenuItem* m_menuItemExportIni;
    wxMenuItem* m_menuSep2;
    wxMenuItem* m_menuItemFilePrint;
    wxMenuItem* m_menuItemPrintPreview;
    wxMenuItem* m_menuItemFilePrintSetup;
    wxMenuItem* m_menuItemSep3;
    wxMenuItem* m_menuItemFileExit;
    wxMenu* m_menuEdit;
    wxMenuItem* m_menuItemUndo;
    wxMenuItem* m_menuItemRedo;
    wxMenuItem* m_menuItem228;
    wxMenuItem* m_menuItemCut;
    wxMenuItem* m_menuItemCopy;
    wxMenuItem* m_menuItemPaste;
    wxMenuItem* m_menuItemDel;
    wxMenuItem* m_menuItem238;
    wxMenuItem* m_menuItemSpusk;
    wxMenu* m_menuNode;
    wxMenuItem* m_menuItemPropMert;
    wxMenuItem* m_menuItemPropSk;
    wxMenuItem* m_menuItemPropNapr;
    wxMenuItem* m_menuItem250;
    wxMenuItem* m_menuItemOtvIz;
    wxMenuItem* m_menuItemOtvSv;
    wxMenuItem* m_menuItemArmat;
    wxMenu* m_menuScheme;
    wxMenuItem* m_menuItemNewPipe;
    wxMenuItem* m_menuItemDelPipe;
    wxMenuItem* m_menuItemMultPipe;
    wxMenuItem* m_menuItemNewNode;
    wxMenuItem* m_menuItemCopyPipeParams;
    wxMenuItem* m_menuItem303;
    wxMenuItem* m_menuItemDelNode;
    wxMenuItem* m_menuItemMoveNode;
    wxMenuItem* m_menuItemRenumPipes;
    wxMenu* m_menuRecord;
    wxMenuItem* m_menuItemRecordFirst;
    wxMenuItem* m_menuItemRecordPrevious;
    wxMenuItem* m_menuItemRecordNext;
    wxMenuItem* m_menuItemRecordLast;
    wxMenu* m_menuView;
    wxMenu* m_menuNavigation;
    wxMenuItem* m_menuItemViewZoomWin;
    wxMenuItem* m_menuItemViewPan;
    wxMenuItem* m_menuItemViewRotate;
    wxMenuItem* m_menuItemViewSelect;
    wxMenu* m_menuFilter;
    wxMenuItem* m_menuItemViewNodeNums;
    wxMenuItem* m_menuItemViewSizes;
    wxMenuItem* m_menuItemViewAprof;
    wxMenuItem* m_menuItemViewElements;
    wxMenuItem* m_menuItemViewNodes;
    wxMenuItem* m_menuItem285;
    wxMenuItem* m_menuItem283;
    wxMenu* m_menuHelp;
    wxMenuItem* m_menuItemHelpAbout;
    wxStatusBar* m_statusBar;
    wxAuiManager* m_mgr;
    wxAuiToolBar* m_auibarFilter;
    wxAuiToolBar* m_auibarView;
    std::map<int, wxMenu*> m_dropdownMenus;
    wxMenu* m_menuViewPredef;
    wxMenuItem* m_menuItemViewTop;
    wxMenuItem* m_menuItemViewBottom;
    wxMenuItem* m_menuItemViewLeft;
    wxMenuItem* m_menuItemViewRight;
    wxMenuItem* m_menuItemViewFront;
    wxMenuItem* m_menuItemViewBack;
    wxMenuItem* m_menuItem325;
    wxMenuItem* m_menuItemViewSwIso;
    wxMenuItem* m_menuItemViewSeIso;
    wxMenuItem* m_menuItemViewNeIso;
    wxMenuItem* m_menuItemViewNwIso;
    wxMenuItem* m_menuItem335;
    wxMenuItem* m_menuItemViewDimetry;
    wxAuiToolBar* m_auibarOperations;
    wxAuiNotebook* m_auiBook;
    wxSimplebook* m_simpleBook;
    wxPanel* m_simpleBookPanel;

protected:
    virtual void OnExit(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAbout(wxCommandEvent& event) { event.Skip(); }

public:
    wxMenuBar* GetMenuBar() { return m_menuBar; }
    wxStatusBar* GetStatusBar() { return m_statusBar; }
    wxAuiToolBar* GetAuibarFilter() { return m_auibarFilter; }

    virtual void ShowAuiToolMenu(wxAuiToolBarEvent& event);
    wxAuiToolBar* GetAuibarView() { return m_auibarView; }
    wxAuiToolBar* GetAuibarOperations() { return m_auibarOperations; }
    wxAuiNotebook* GetAuiBook() { return m_auiBook; }
    wxPanel* GetSimpleBookPanel() { return m_simpleBookPanel; }
    wxSimplebook* GetSimpleBook() { return m_simpleBook; }
    wxAuiManager* GetMgr() { return m_mgr; }
    MainFrameBaseClass(wxDocManager *manager, wxFrame *parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Старт Препроцессор"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1900,1200), long style = wxCAPTION|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxCLOSE_BOX);
    virtual ~MainFrameBaseClass();
};


class ImageList : public wxImageList
{
protected:
    // Maintain a map of all bitmaps representd by their name
    std::map<wxString, wxBitmap> m_bitmaps;
    // The requested image resolution (can be one of @2x, @1.5x, @1.25x or an empty string (the default)
    wxString m_resolution;
    int m_imagesWidth;
    int m_imagesHeight;


protected:

public:
    ImageList();
    const wxBitmap& Bitmap(const wxString &name) const {
        if ( !m_bitmaps.count(name + m_resolution) )
            return wxNullBitmap;
        return m_bitmaps.find(name + m_resolution)->second;
    }

    void SetBitmapResolution(const wxString &res = wxEmptyString) {
        m_resolution = res;
    }

    virtual ~ImageList();
};


class CNewPipeBaseDialog : public wxDialog
{
public:
    enum {
        wxID_AFTER_NODE_CHOICE = 10001,
    };
protected:
    wxStaticText* m_staticTextAfterPipe;
    wxChoice* m_choice;
    wxStaticText* m_staticTextStartNode;
    wxTextCtrl* m_textCtrlStartNode;
    wxStaticText* m_staticTextEndNode;
    wxTextCtrl* m_textCtrlEndNode;
    wxStdDialogButtonSizer* m_stdBtnSizer;
    wxButton* m_buttonOk;
    wxButton* m_buttonCancel;

protected:

public:
    wxStaticText* GetStaticTextAfterPipe() { return m_staticTextAfterPipe; }
    wxChoice* GetChoice() { return m_choice; }
    wxStaticText* GetStaticTextStartNode() { return m_staticTextStartNode; }
    wxTextCtrl* GetTextCtrlStartNode() { return m_textCtrlStartNode; }
    wxStaticText* GetStaticTextEndNode() { return m_staticTextEndNode; }
    wxTextCtrl* GetTextCtrlEndNode() { return m_textCtrlEndNode; }
    CNewPipeBaseDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Новый участок"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~CNewPipeBaseDialog();
};


class CDelPipesBaseDialog : public wxDialog
{
public:
    enum {
        wxIDC_LIST1 = 10001,
    };
protected:
    wxListBox* m_listBox;
    wxStdDialogButtonSizer* m_stdBtnSizer;
    wxButton* m_buttonOk;
    wxButton* m_buttonCancel;

protected:

public:
    wxListBox* GetListBox() { return m_listBox; }
    CDelPipesBaseDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Удалить участки"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~CDelPipesBaseDialog();
};


class CMultPipeBaseDialog : public wxDialog
{
public:
    enum {
        wxID_EDIT1 = 10001,
        wxID_EDIT2 = 10002,
        wxID_EDIT3 = 10003,
        wxID_MULT_PIPE_CHOICE = 10004,
    };
protected:
    wxStaticText* m_staticTextMultPipe;
    wxChoice* m_choice;
    wxStaticText* m_staticTextStartNode;
    wxTextCtrl* m_textCtrlStartNode;
    wxStaticText* m_staticTextEndNode;
    wxTextCtrl* m_textCtrlEndNode;
    wxStaticText* m_staticTextNumPipes;
    wxSpinCtrl* m_textCtrlNumPipes;
    wxStdDialogButtonSizer* m_stdBtnSizer;
    wxButton* m_buttonOk13;
    wxButton* m_buttonCancel14;

protected:

public:
    wxStaticText* GetStaticTextMultPipe() { return m_staticTextMultPipe; }
    wxChoice* GetChoice() { return m_choice; }
    wxStaticText* GetStaticTextStartNode() { return m_staticTextStartNode; }
    wxTextCtrl* GetTextCtrlStartNode() { return m_textCtrlStartNode; }
    wxStaticText* GetStaticTextEndNode() { return m_staticTextEndNode; }
    wxTextCtrl* GetTextCtrlEndNode() { return m_textCtrlEndNode; }
    wxStaticText* GetStaticTextNumPipes() { return m_staticTextNumPipes; }
    wxSpinCtrl* GetTextCtrlNumPipes() { return m_textCtrlNumPipes; }
    CMultPipeBaseDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Размножить участок"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~CMultPipeBaseDialog();
};


class CNewNodeBaseDialog : public wxDialog
{
public:
    enum {
        wxID_EDIT1 = 10001,
        wxID_NEW_NODE_CHOICE = 10002,
        wxID_RADIO1 = 10003,
        wxID_RADIO2 = 10004,
    };
protected:
    wxStaticText* m_staticTextPipe;
    wxChoice* m_choice;
    wxStaticText* m_staticTextFirstNode;
    wxTextCtrl* m_textCtrlFirstNode;
    wxRadioButton* m_radioButton1;
    wxStaticText* m_staticText481;
    wxTextCtrl* m_textCtrlLengths;
    wxRadioButton* m_radioButton2;
    wxSpinCtrl* m_textCtrlNumPipes;
    wxStaticText* m_staticText490;
    wxCheckBox* m_checkBoxSkop;
    wxStdDialogButtonSizer* m_stdBtnSizer;
    wxButton* m_buttonOk132;
    wxButton* m_buttonCancel143;

protected:

public:
    wxStaticText* GetStaticTextPipe() { return m_staticTextPipe; }
    wxChoice* GetChoice() { return m_choice; }
    wxStaticText* GetStaticTextFirstNode() { return m_staticTextFirstNode; }
    wxTextCtrl* GetTextCtrlFirstNode() { return m_textCtrlFirstNode; }
    wxRadioButton* GetRadioButton1() { return m_radioButton1; }
    wxStaticText* GetStaticText481() { return m_staticText481; }
    wxTextCtrl* GetTextCtrlLengths() { return m_textCtrlLengths; }
    wxRadioButton* GetRadioButton2() { return m_radioButton2; }
    wxSpinCtrl* GetTextCtrlNumPipes() { return m_textCtrlNumPipes; }
    wxStaticText* GetStaticText490() { return m_staticText490; }
    wxCheckBox* GetCheckBoxSkop() { return m_checkBoxSkop; }
    CNewNodeBaseDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Разбить участок"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~CNewNodeBaseDialog();
};


class CCopyParamsBaseDialog : public wxDialog
{
protected:
    wxStaticText* m_staticText504;
    wxStaticText* m_sPipeName;
    wxListBox* m_lbParams;
    wxStaticText* m_staticText513;
    wxListBox* m_lbPipes;
    wxStdDialogButtonSizer* m_stdBtnSizer;
    wxButton* m_buttonOk;
    wxButton* m_buttonCancel;

protected:

public:
    wxStaticText* GetStaticText504() { return m_staticText504; }
    wxStaticText* GetSPipeName() { return m_sPipeName; }
    wxListBox* GetLbParams() { return m_lbParams; }
    wxStaticText* GetStaticText513() { return m_staticText513; }
    wxListBox* GetLbPipes() { return m_lbPipes; }
    CCopyParamsBaseDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Копирование параметров участка"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~CCopyParamsBaseDialog();
};


class CMoveNodeBaseDialog : public wxDialog
{
protected:
    wxStaticText* m_staticTextNode;
    wxStaticText* m_sNode;
    wxStaticText* m_staticTextDist;
    wxTextCtrl* m_textCtrlDist;
    wxStaticText* m_staticText546;
    wxStdDialogButtonSizer* m_stdBtnSizer;
    wxButton* m_buttonOk5;
    wxButton* m_buttonCancel6;

protected:

public:
    wxStaticText* GetStaticTextNode() { return m_staticTextNode; }
    wxStaticText* GetSNode() { return m_sNode; }
    wxStaticText* GetStaticTextDist() { return m_staticTextDist; }
    wxTextCtrl* GetTextCtrlDist() { return m_textCtrlDist; }
    wxStaticText* GetStaticText546() { return m_staticText546; }
    CMoveNodeBaseDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Передвинуть узел"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~CMoveNodeBaseDialog();
};


class CSpuskBaseDialog : public wxDialog
{
public:
    enum {
        wxIDC_LIST_DIAM = 10001,
    };
protected:
    wxListBox* m_listBoxDiam;
    wxStaticText* m_staticText58412;
    wxTextCtrl* m_textCtrl_h;
    wxStaticText* m_staticText584515;
    wxTextCtrl* m_textCtrl_H1;
    wxStaticText* m_staticText5845818;
    wxTextCtrl* m_textCtrl_H2;
    wxCheckBox* m_checkBoxUhod;
    wxNotebook* m_notebook;
    wxPanel* m_panel567;
    wxStaticBitmap* m_staticBitmap575;
    wxPanel* m_panel569;
    wxStaticBitmap* m_staticBitmap617;
    wxPanel* m_panel579;
    wxStaticBitmap* m_staticBitmap61721;
    wxPanel* m_panel581;
    wxStaticBitmap* m_staticBitmap6172123;
    wxStdDialogButtonSizer* m_stdBtnSizer;
    wxButton* m_buttonOk;
    wxButton* m_buttonCancel;

protected:

public:
    wxListBox* GetListBoxDiam() { return m_listBoxDiam; }
    wxStaticText* GetStaticText58412() { return m_staticText58412; }
    wxTextCtrl* GetTextCtrl_h() { return m_textCtrl_h; }
    wxStaticText* GetStaticText584515() { return m_staticText584515; }
    wxTextCtrl* GetTextCtrl_H1() { return m_textCtrl_H1; }
    wxStaticText* GetStaticText5845818() { return m_staticText5845818; }
    wxTextCtrl* GetTextCtrl_H2() { return m_textCtrl_H2; }
    wxCheckBox* GetCheckBoxUhod() { return m_checkBoxUhod; }
    wxStaticBitmap* GetStaticBitmap575() { return m_staticBitmap575; }
    wxPanel* GetPanel567() { return m_panel567; }
    wxStaticBitmap* GetStaticBitmap617() { return m_staticBitmap617; }
    wxPanel* GetPanel569() { return m_panel569; }
    wxStaticBitmap* GetStaticBitmap61721() { return m_staticBitmap61721; }
    wxPanel* GetPanel579() { return m_panel579; }
    wxStaticBitmap* GetStaticBitmap6172123() { return m_staticBitmap6172123; }
    wxPanel* GetPanel581() { return m_panel581; }
    wxNotebook* GetNotebook() { return m_notebook; }
    CSpuskBaseDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Вставка спускников и ответвлений"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~CSpuskBaseDialog();
};


class CPipesTableBaseDlg : public wxDialog
{
public:
    enum {
        wxID_DEL_LINE = 10001,
    };
protected:
    wxGrid* m_grid;
    wxButton* m_buttonDelLine;
    wxStdDialogButtonSizer* m_stdBtnSizer;
    wxButton* m_buttonOk;
    wxButton* m_buttonCancel;

protected:
    virtual void OnTableDelLine(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateTableDelLine(wxUpdateUIEvent& event) { event.Skip(); }

public:
    wxGrid* GetGrid() { return m_grid; }
    wxButton* GetButtonDelLine() { return m_buttonDelLine; }
    CPipesTableBaseDlg(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Таблица труб"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~CPipesTableBaseDlg();
};


class CAddSchemBaseDialog : public wxDialog
{
public:
    enum {
        wxID_CONNECT_TO_PIPE = 10001,
    };
protected:
    wxStaticText* m_staticTextConnectToPipe;
    wxChoice* m_choice;
    wxStdDialogButtonSizer* m_stdBtnSizer;
    wxButton* m_buttonOk;
    wxButton* m_buttonCancel;

protected:

public:
    wxStaticText* GetStaticTextConnectToPipe() { return m_staticTextConnectToPipe; }
    wxChoice* GetChoice() { return m_choice; }
    CAddSchemBaseDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Вставка схемы"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~CAddSchemBaseDialog();
};


class CDistBaseDialog : public wxDialog
{
protected:
    wxStaticText* m_staticText710;
    wxTextCtrl* m_textCtrlStart;
    wxStaticText* m_staticText714;
    wxTextCtrl* m_textCtrlEnd;
    wxStaticText* m_staticTextAll;
    wxTextCtrl* m_textCtrlDistAll;
    wxStaticText* m_staticTextM;
    wxStaticText* m_staticTextX;
    wxTextCtrl* m_textCtrlDistX;
    wxStaticText* m_staticTextM1;
    wxStaticText* m_staticTextY;
    wxTextCtrl* m_textCtrlDistY;
    wxStaticText* m_staticTextM2;
    wxStaticText* m_staticTextZ;
    wxTextCtrl* m_textCtrlDistZ;
    wxStaticText* m_staticTextM3;
    wxStdDialogButtonSizer* m_stdBtnSizer;
    wxButton* m_buttonOk7;
    wxButton* m_buttonCancel8;

protected:

public:
    wxStaticText* GetStaticText710() { return m_staticText710; }
    wxTextCtrl* GetTextCtrlStart() { return m_textCtrlStart; }
    wxStaticText* GetStaticText714() { return m_staticText714; }
    wxTextCtrl* GetTextCtrlEnd() { return m_textCtrlEnd; }
    wxStaticText* GetStaticTextAll() { return m_staticTextAll; }
    wxTextCtrl* GetTextCtrlDistAll() { return m_textCtrlDistAll; }
    wxStaticText* GetStaticTextM() { return m_staticTextM; }
    wxStaticText* GetStaticTextX() { return m_staticTextX; }
    wxTextCtrl* GetTextCtrlDistX() { return m_textCtrlDistX; }
    wxStaticText* GetStaticTextM1() { return m_staticTextM1; }
    wxStaticText* GetStaticTextY() { return m_staticTextY; }
    wxTextCtrl* GetTextCtrlDistY() { return m_textCtrlDistY; }
    wxStaticText* GetStaticTextM2() { return m_staticTextM2; }
    wxStaticText* GetStaticTextZ() { return m_staticTextZ; }
    wxTextCtrl* GetTextCtrlDistZ() { return m_textCtrlDistZ; }
    wxStaticText* GetStaticTextM3() { return m_staticTextM3; }
    CDistBaseDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Расстояние между узлами"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~CDistBaseDialog();
};

#endif
