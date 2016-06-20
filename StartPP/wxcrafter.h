//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef STARTPP_STARTPP_WXCRAFTER_BASE_CLASSES_H
#define STARTPP_STARTPP_WXCRAFTER_BASE_CLASSES_H

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
#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/glcanvas.h>
#include <wx/simplebook.h>
#include "PropertiesWnd.h"
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
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class MainFrameBaseClass : public wxDocParentFrame
{
public:
    enum {
        wxID_ADD_SCHEM = 10001,
        wxID_COPY_PIPE_PARAMS = 10002,
        wxID_DEL_NODE = 10003,
        wxID_DEL_PIPE = 10004,
        wxID_EXPORT_INI = 10005,
        wxID_INVERT_PIPE = 10006,
        wxID_ImportDbf = 10007,
        wxID_MOVE_NODE = 10008,
        wxID_MULT_PIPE = 10009,
        wxID_NEW_NODE = 10010,
        wxID_NEW_PIPE = 10011,
        wxID_PAN = 10012,
        wxID_PIPE_DESC = 10013,
        wxID_PROJ = 10014,
        wxID_PROP_ARMAT = 10015,
        wxID_PROP_MERT = 10016,
        wxID_PROP_NAPR = 10017,
        wxID_PROP_OTV_IZ = 10018,
        wxID_PROP_OTV_SV = 10019,
        wxID_PROP_SK = 10020,
        wxID_RECORD_LAST = 10021,
        wxID_RENUM_PIPES = 10022,
        wxID_ROTATE = 10023,
        wxID_SELECT = 10024,
        wxID_SHOW_OGL = 10025,
        wxID_Spusk = 10026,
        wxID_TROINICS_TABLE = 10027,
        wxID_VIEW_3DVIEWS_BACK = 10028,
        wxID_VIEW_3DVIEWS_BOTTOM = 10029,
        wxID_VIEW_3DVIEWS_DIMETRY = 10030,
        wxID_VIEW_3DVIEWS_FRONT = 10031,
        wxID_VIEW_3DVIEWS_LEFT = 10032,
        wxID_VIEW_3DVIEWS_NE_ISO = 10033,
        wxID_VIEW_3DVIEWS_NW_ISO = 10034,
        wxID_VIEW_3DVIEWS_RIGHT = 10035,
        wxID_VIEW_3DVIEWS_SE_ISO = 10036,
        wxID_VIEW_3DVIEWS_SW_ISO = 10037,
        wxID_VIEW_3DVIEWS_TOP = 10038,
        wxID_VIEW_APROF = 10039,
        wxID_VIEW_ELEMENTS = 10040,
        wxID_VIEW_NODES = 10041,
        wxID_VIEW_NODE_NUMS = 10042,
        wxID_VIEW_SIZES = 10043,
        wxID_ViewZoomIn = 10044,
        wxID_ViewZoomOut = 10045,
        wxID_ZOOM_ALL = 10046,
        wxID_ZOOM_WIN = 10047,
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
    wxPanel* m_panel;
    wxGLCanvas* m_glPanel;
    wxSimplebook* m_simpleBook;
    wxPanel* m_simpleBookPanel;
    CPropertiesWnd* m_propWnd;

protected:
    virtual void OnImportDbf(wxCommandEvent& event) { event.Skip(); }
    virtual void OnExit(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRecordPrevious(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRecordNext(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAbout(wxCommandEvent& event) { event.Skip(); }

public:
    wxMenuBar* GetMenuBar() { return m_menuBar; }
    wxStatusBar* GetStatusBar() { return m_statusBar; }
    wxAuiToolBar* GetAuibarFilter() { return m_auibarFilter; }

    virtual void ShowAuiToolMenu(wxAuiToolBarEvent& event);
    wxAuiToolBar* GetAuibarView() { return m_auibarView; }
    wxAuiToolBar* GetAuibarOperations() { return m_auibarOperations; }
    wxGLCanvas* GetGlPanel() { return m_glPanel; }
    wxPanel* GetPanel() { return m_panel; }
    wxAuiNotebook* GetAuiBook() { return m_auiBook; }
    CPropertiesWnd* GetPropWnd() { return m_propWnd; }
    wxPanel* GetSimpleBookPanel() { return m_simpleBookPanel; }
    wxSimplebook* GetSimpleBook() { return m_simpleBook; }
    wxAuiManager* GetMgr() { return m_mgr; }
    MainFrameBaseClass(wxDocManager *manager, wxFrame *parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Start Preprocessor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(800,600), long style = wxCAPTION|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxCLOSE_BOX);
    virtual ~MainFrameBaseClass();
};


class ImageList : public wxImageList
{
protected:
    // Maintain a map of all bitmaps representd by their name
    std::map<wxString, wxBitmap> m_bitmaps;


protected:

public:
    ImageList();
    const wxBitmap& Bitmap(const wxString &name) const {
        if ( !m_bitmaps.count(name) )
            return wxNullBitmap;
        return m_bitmaps.find(name)->second;
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

#endif
