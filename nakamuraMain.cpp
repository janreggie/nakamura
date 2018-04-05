/***************************************************************
 * Name:      nakamuraMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    janreggie, jriaghan, sangjeona ()
 * Created:   2018-04-05
 * Copyright: janreggie, jriaghan, sangjeona ()
 * License:   MIT License
 **************************************************************/

#include "nakamuraMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(nakamuraFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(nakamuraFrame)
const long nakamuraFrame::ID_RADIOBOX1 = wxNewId();
const long nakamuraFrame::ID_RADIOBOX2 = wxNewId();
const long nakamuraFrame::ID_CHECKLISTBOX1 = wxNewId();
const long nakamuraFrame::ID_CHOICE1 = wxNewId();
const long nakamuraFrame::ID_STATICTEXT1 = wxNewId();
const long nakamuraFrame::ID_MENUITEM1 = wxNewId();
const long nakamuraFrame::idMenuAbout = wxNewId();
const long nakamuraFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(nakamuraFrame,wxFrame)
    //(*EventTable(nakamuraFrame)
    //*)
END_EVENT_TABLE()

nakamuraFrame::nakamuraFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(nakamuraFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(432,256));
    wxString __wxRadioBoxChoices_1[3] =
    {
    	_("Deutschland"),
    	_("Österreich"),
    	_("Schweiz")
    };
    RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Which is superior"), wxPoint(16,24), wxDefaultSize, 3, __wxRadioBoxChoices_1, 3, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
    wxString __wxRadioBoxChoices_2[3] =
    {
    	_("lol"),
    	_("lmao"),
    	_("kek")
    };
    RadioBox2 = new wxRadioBox(this, ID_RADIOBOX2, _("Lol"), wxPoint(144,24), wxDefaultSize, 3, __wxRadioBoxChoices_2, 3, 0, wxDefaultValidator, _T("ID_RADIOBOX2"));
    CheckListBox1 = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxPoint(224,32), wxSize(72,80), 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
    CheckListBox1->Append(_("lol"));
    CheckListBox1->Append(_("shit"));
    CheckListBox1->Append(_("fuck"));
    Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(216,152), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->Append(_("Straight Male"));
    Choice1->Append(_("Straight Female"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("I am a"), wxPoint(216,128), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&nakamuraFrame::OnRadioBox1Select);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&nakamuraFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&nakamuraFrame::OnAbout);
    //*)
}

nakamuraFrame::~nakamuraFrame()
{
    //(*Destroy(nakamuraFrame)
    //*)
}

void nakamuraFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void nakamuraFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = "This is a test message.";
    wxMessageBox(msg, _("Nakamura 0.1"));
}

void nakamuraFrame::OnButton1Click(wxCommandEvent& event)
{
}

void nakamuraFrame::OnRadioBox1Select(wxCommandEvent& event)
{
}
