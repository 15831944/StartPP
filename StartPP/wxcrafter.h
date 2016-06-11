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
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/aui/framemanager.h>
#include <wx/aui/dockart.h>
#include <wx/aui/auibook.h>
#include <wx/panel.h>
#include <wx/imaglist.h>
#include "StartPPView.h"
#include <wx/pen.h>
#include <wx/aui/auibar.h>
#include <map>
#include <wx/toolbar.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class MainFrameBaseClass : public wxFrame
{
public:
    enum {
        wxID_ImportDbf = 10001,
        wxID_View3D = 10002,
        wxID_ViewPan = 10003,
        wxID_ViewRotate = 10004,
        wxID_ViewSelect = 10005,
        wxID_ViewTop = 10006,
        wxID_ViewZoomIn = 10007,
        wxID_ViewZoomOut = 10008,
        wxID_ViewZoomWindow = 10009,
        wxID_ZoomAll = 10010,
    };
protected:
    wxMenuBar* m_menuBar;
    wxMenu* m_menuFile;
    wxMenuItem* m_menuItemImportDbf;
    wxMenuItem* m_menuItemFileExit;
    wxMenu* m_menuRecord;
    wxMenuItem* m_menuItemRecordPrevious;
    wxMenuItem* m_menuItemRecordNext;
    wxMenu* m_menuHelp;
    wxMenuItem* m_menuItemHelpAbout;
    wxStatusBar* m_statusBar;
    wxAuiManager* m_mgr;
    wxAuiNotebook* m_auiBook;
    wxPanel* m_panel;
    CStartPPView* m_view;
    wxAuiToolBar* m_auibarFilter;
    wxAuiToolBar* m_auibarView;
    std::map<int, wxMenu*> m_dropdownMenus;
    wxMenu* m_menuViewPredef;
    wxMenuItem* m_menuItemViewTop;

protected:
    virtual void OnImportDbf(wxCommandEvent& event) { event.Skip(); }
    virtual void OnExit(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRecordPrevious(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRecordNext(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAbout(wxCommandEvent& event) { event.Skip(); }

public:
    wxMenuBar* GetMenuBar() { return m_menuBar; }
    wxStatusBar* GetStatusBar() { return m_statusBar; }
    CStartPPView* GetView() { return m_view; }
    wxPanel* GetPanel() { return m_panel; }
    wxAuiNotebook* GetAuiBook() { return m_auiBook; }
    wxAuiToolBar* GetAuibarFilter() { return m_auibarFilter; }

    virtual void ShowAuiToolMenu(wxAuiToolBarEvent& event);
    wxAuiToolBar* GetAuibarView() { return m_auibarView; }
    wxAuiManager* GetMgr() { return m_mgr; }
    MainFrameBaseClass(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Start Preprocessor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(800,600), long style = wxCAPTION|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxCLOSE_BOX);
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

#endif
