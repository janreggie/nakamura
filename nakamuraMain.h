/***************************************************************
 * Name:      nakamuraMain.h
 * Purpose:   Defines Application Frame
 * Author:    janreggie, jriaghan, sangjeona
 * Created:   2018-04-05
 * Copyright: janreggie, jriaghan, sangjeona
 * License:   MIT License
 **************************************************************/

#ifndef NAKAMURAMAIN_H
#define NAKAMURAMAIN_H

//(*Headers(nakamuraFrame)
#include <wx/checklst.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/radiobox.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)

class nakamuraFrame: public wxFrame
{
    public:

        nakamuraFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~nakamuraFrame();

    private:

        //(*Handlers(nakamuraFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnRadioBox1Select(wxCommandEvent& event);
        //*)

        //(*Identifiers(nakamuraFrame)
        static const long ID_RADIOBOX1;
        static const long ID_RADIOBOX2;
        static const long ID_CHECKLISTBOX1;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT1;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(nakamuraFrame)
        wxCheckListBox* CheckListBox1;
        wxChoice* Choice1;
        wxRadioBox* RadioBox1;
        wxRadioBox* RadioBox2;
        wxStaticText* StaticText1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // NAKAMURAMAIN_H
