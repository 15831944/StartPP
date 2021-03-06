// appframe.cpp
// Copyright (c) 2007-2016 by Troels K. All rights reserved.
// License: wxWindows Library Licence, Version 3.1 - see LICENSE.txt

#include "precomp.h"
#include <wx/stdpaths.h>
#include <wx/aboutdlg.h>

#include "wx/ext/docview.h"
#include "appframe.h"
#include "app.h"
#include "../../bool.h"
#include "../../dbf.h"
#include "../../dbf.hpp"
#include "../../dbf_wx.h"
#include "dbfframe.h"
#include "appdoc.h"
#include "dbfart.h"

/////////////////////////////////////////////////////////////////////////////
// MainFrame

wxIMPLEMENT_CLASS(MainFrame, wxDocMDIParentFrame);

MainFrame::MainFrame() : wxDocMDIParentFrame(), m_windowMenuEvtHandler(NULL)
{
}

MainFrame::~MainFrame()
{
    delete m_windowMenuEvtHandler;
}

wxBEGIN_EVENT_TABLE(MainFrame, wxDocMDIParentFrame)
    EVT_MENU(XRCID("example")        , MainFrame::OnOpenExample)
    EVT_MENU(XRCID("statusbar")      , MainFrame::OnStatusBar)
    EVT_MENU(XRCID("toolbar")        , MainFrame::OnToolBar)
    EVT_MENU(XRCID("view_fullscreen"), MainFrame::OnFullscreen)
    EVT_MENU(XRCID("windows")        , MainFrame::OnWindowsDialog)
    EVT_UPDATE_UI(XRCID("view_fullscreen"), MainFrame::OnUpdateFullscreen)
    EVT_UPDATE_UI(XRCID("toolbar")   , MainFrame::OnUpdateToolBar)
    EVT_UPDATE_UI(XRCID("statusbar") , MainFrame::OnUpdateStatusBar)
//  EVT_UPDATE_UI(wxID_HELP          , MainFrame::OnUpdateDisable)
wxEND_EVENT_TABLE()

bool MainFrame::Create(wxDocManager* docManager, const wxString& rtitle, const wxPoint& pos, const wxSize& size)
{
    wxString title = rtitle;
#ifdef _DEBUG
    title.insert(0, wxT("[DEBUG] "));
#endif
    bool ok = base::Create(docManager, NULL, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE | wxVSCROLL | wxHSCROLL);

    if (ok)
    {
        CreateStatusBar()->PushStatusText(_("Ready"));
        SetIcon(wxArtProvider::GetIcon(wxART_APP));
        SetMenuBar(CreateMenuBar());
        SetToolBar(CreateToolBar());
        SetAcceleratorTable(DBFFrame::GetAccelerator().ToArray());
        ::wxFrame_SetInitialPosition(this, pos, size);
        m_windowMenuEvtHandler = new MDIWindowMenuEvtHandler(this);

        wxMenu* windowMenu = GetWindowMenu();
        windowMenu->AppendSeparator();
        windowMenu->Append(XRCID("windows"), _("&Windows..."), _("Windows dialog"));

    #ifdef _DEBUG
        //wxPostMenuCommand(this, XRCID("windows"));
        //wxPostMenuCommand(this, XRCID("struct"));
        //wxPostMenuCommand(this, wxID_PREVIEW);
        //wxPostMenuCommand(this, wxID_NEW);
        wxPostMenuCommand(this, XRCID("example"));
    #endif
    }
    return ok;
}

wxMenuBar* MainFrame::CreateMenuBar() const
{
    wxMenuBar* menubar = wxXmlResource::Get()->LoadMenuBar(wxT("menu_mdi"));
    wxASSERT(menubar);
    wxAcceleratorHelper::SetAccelText(menubar, DBFFrame::GetAccelerator());
    return menubar;
}

void MainFrame::SetMenuBar(wxMenuBar* menubar)
{
    base::SetMenuBar(menubar);
    wxGetApp().GetRecentFileList()->Attach(menubar);
}

typedef struct _wxTOOLBARITEM
{
    int id;
#if (wxVERSION_NUMBER >= 2902)
    const char* id_art;
#else
    const wxChar* id_art;
#endif
    wxString text;
    wxString help;
} wxTOOLBARITEM;

wxToolBar* MainFrame::CreateToolBar()
{
   const wxAcceleratorVector& accel = DBFFrame::GetAccelerator();
   wxToolBar* tb = base::CreateToolBar(wxTB_TEXT | wxBORDER_NONE | wxTB_HORIZONTAL | wxTB_FLAT);

   const wxSize size = tb->GetToolBitmapSize();
   //const wxSize size(tb->GetToolBitmapSize().x, 16);
   //tb->SetToolBitmapSize(size);

   const wxTOOLBARITEM aID[] =
   {
      { wxID_NEW           , NULL               , wxEmptyString, wxEmptyString },
      { wxID_OPEN          , NULL               , wxEmptyString, wxEmptyString },
      { wxID_SAVE          , NULL               , wxEmptyString, wxEmptyString },
      { wxID_SEPARATOR     , NULL               , wxEmptyString, wxEmptyString },
      { wxID_ADD           , NULL               , wxEmptyString, wxEmptyString },
      { XRCID("edit")      , DBF_ART_EDIT       , _("Edit")    , _("Edit") },
      { wxID_DELETE        , NULL               , wxEmptyString, wxEmptyString },
      { wxID_SEPARATOR     , NULL               , wxEmptyString, wxEmptyString },
      { wxID_PRINT         , NULL               , wxEmptyString, wxEmptyString },
      { wxID_PREVIEW       , NULL               , _("Preview") , wxEmptyString },
      { wxID_SEPARATOR     , NULL               , wxEmptyString, wxEmptyString },
      { XRCID("struct")    , wxART_HELP_SIDE_PANEL, _("Structure"), _("Modify Structure") },
      { XRCID("pack")      , wxART_DEL_BOOKMARK , _("Pack")  , _("Pack Database") },
      { wxID_SEPARATOR     , NULL               , wxEmptyString, wxEmptyString },
      { wxID_FIND          , NULL               , wxEmptyString, wxEmptyString },
      { wxID_SEPARATOR     , NULL               , wxEmptyString, wxEmptyString },
      { wxID_ABOUT /*wxID_HELP*/, NULL          , _("Help")    , wxEmptyString },
      { wxID_EXIT          , NULL               , wxEmptyString, wxEmptyString },
      { wxID_SEPARATOR     , NULL               , wxEmptyString, wxEmptyString },
   };
   for (size_t i = 0; i < WXSIZEOF(aID); i++)
   {
      const wxTOOLBARITEM& element = aID[i];
      wxToolBarToolBase* tool = NULL;

      switch (element.id)
      {
         case wxID_SEPARATOR:
            tb->AddSeparator();
            break;
         default:
         {
            const wxArtID art_id = element.id_art ? wxString(element.id_art) : wxID2ArtID(element.id);
            wxBitmap icon = wxArtProvider::GetBitmap(art_id, wxART_TOOLBAR, size);
            wxASSERT(icon.GetWidth() == size.x);
            wxASSERT(icon.GetHeight() == size.y);
            wxString str = element.text.empty() ? wxGetStockLabelEx(element.id, wxSTOCK_PLAINTEXT) : element.text;

            tool = tb->AddTool(element.id, str, icon);
            if (tool)
            {
               str = element.help.empty() ? wxGetStockLabelEx(element.id, wxSTOCK_PLAINTEXT) : element.help;
               str = wxToolBarTool_MakeShortHelp(str, accel, element.id);
               tool->SetShortHelp(str);
            }
            break;
         }
      }
   }
   tb->Realize();
   return tb;
}

//static
void MainFrame::GetVersionInfo(wxAboutDialogInfo* info)
{
    wxVersionInfo vi = wxDBase::GetVersionInfo();

    info->SetName(vi.GetName());
    //info->SetDescription(vi.GetDescription() + wxT("\n\n") + wxStandardPaths::Get().GetExecutablePath());
    info->SetDescription(wxT("\nThis demo program demonstrates the usage of wxDBase\n\n")
       + wxStandardPaths::Get().GetExecutablePath());

    info->SetCopyright(vi.GetCopyright());
    info->SetVersion(wxString::Format(wxT("%d.%d svn r%d"), vi.GetMajor(), vi.GetMinor(), vi.GetMicro()));
    info->AddDeveloper(wxT(DBF_AUTHOR));
    info->SetLicense(wxT("wxWindows"));
    info->SetWebSite(wxT(DBF_WEBSITE));
}

#ifdef __WXMSW__
bool MainFrame::MSWTranslateMessage(WXMSG* msg)
{
    bool processed = false;

#if (wxVERSION_NUMBER < 2900)
    if ( (!processed) && (msg->message == WM_COMMAND))
    {
        switch (msg->wParam)
        {
            //case wxID_CLOSE:
            case wxID_CLOSE_ALL:
                wxPostMenuCommand(m_windowMenuEvtHandler, msg->wParam);
                processed = true;
                break;
            default:
                if ((int)msg->wParam == XRCID("windows"))
                {
                    wxPostMenuCommand(m_windowMenuEvtHandler, msg->wParam);
                    processed = true;
                }
                break;
        }
    }
#endif

    if (!processed)
         processed = base::MSWTranslateMessage(msg);
    return processed;
}
#endif

void MainFrame::OnStatusBar(wxCommandEvent&)
{
   ::wxWindow_Toggle(GetStatusBar());
}

void MainFrame::OnUpdateStatusBar(wxUpdateUIEvent& event)
{
    event.Check(GetStatusBar()->IsShown());
}

void MainFrame::OnToolBar(wxCommandEvent&)
{
    ::wxWindow_Toggle(GetToolBar());
}

void MainFrame::OnUpdateToolBar(wxUpdateUIEvent& event)
{
    event.Check(GetToolBar()->IsShown());
}

void MainFrame::OnFullscreen(wxCommandEvent&)
{
    long style = wxFULLSCREEN_NOBORDER|wxFULLSCREEN_NOCAPTION;

    ::wxFrame_ToggleFullScreen(this, style);
}

void MainFrame::OnUpdateFullscreen (wxUpdateUIEvent& event)
{
    ::wxFrame_OnUpdateFullScreen(this, event);
}

void MainFrame::OnWindowsDialog(wxCommandEvent&)
{
    ::DoModal_Windows(this, wxTrunkDocView::GetDocumentsVector(*m_docManager));
}

void MainFrame::OnOpenExample(wxCommandEvent&)
{
    const wxArrayString as = PUB_DbfExampleVector.GetNames();
    static int index = 0;

//index = 4;
    if (::wxGetSingleChoiceIndex(&index, _("Examples"), wxMessageBoxCaption, as, this))
        wxGetApp().OpenExample(as[index]);
}
