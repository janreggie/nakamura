///-----------------------------------------------------------------
///
/// @file      nakamuraFrm.h
/// @author    JRAV
/// Created:   2018-04-06 3:25:52 PM
/// @section   DESCRIPTION
///            PROJ2EBLFrm class declaration
///
///------------------------------------------------------------------

#ifndef __PROJ2EBLFRM_H__
#define __PROJ2EBLFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/menu.h>
#include <wx/combobox.h>
#include <wx/statbmp.h>
#include <wx/tglbtn.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/textctrl.h>
////Header Include End

////Dialog Style Start
#undef PROJ2EBLFrm_STYLE
#define PROJ2EBLFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class PROJ2EBLFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		PROJ2EBLFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("PROJ2EBL"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = PROJ2EBLFrm_STYLE);
		virtual ~PROJ2EBLFrm();
		void WxButton2Click(wxCommandEvent& event);
		void WxButton4Click(wxCommandEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		void PROJ2EBLFrmActivate(wxActivateEvent& event);
		void WxToggleButton1Click(wxCommandEvent& event);
		void WxToggleButton2Click(wxCommandEvent& event);
		void WxToggleButton3Click(wxCommandEvent& event);
		void Mnuexit1045Click(wxCommandEvent& event);
		void WxEdit1Updated(wxCommandEvent& event);
		void Mnuabout1046Click(wxCommandEvent& event);
		void WxRadioBox1Click(wxCommandEvent& event);
		void WxComboBox1Selected(wxCommandEvent& event );
		void UnitsUpdated(wxCommandEvent& event );
		void WxEdit4Updated(wxCommandEvent& event);
		void WxEdit2Updated(wxCommandEvent& event);
		void WxEdit1Updated0(wxCommandEvent& event);
		void WxEdit13Enter(wxCommandEvent& event);
		void WxPanel1UpdateUI(wxUpdateUIEvent& event);
		void StartClick(wxCommandEvent& event);
		void Text_ResUpdated(wxCommandEvent& event);
		void Text_ResEnter(wxCommandEvent& event);
		void Text_ResUpdateUI(wxUpdateUIEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *Start;
		wxComboBox *CB_TimeStop;
		wxComboBox *CB_TimeStart;
		wxComboBox *CB_IC;
		wxComboBox *CB_Phase;
		wxComboBox *CB_Freq;
		wxComboBox *CB_Amp;
		wxComboBox *CB_Cap;
		wxComboBox *CB_Res;
    wxMenuBar *WxMenuBar1;
		wxStaticBitmap *WxStaticBitmap1;
		wxStaticText *Number;
		wxStaticText *Stop;
		wxStaticText *Time_Start;
		wxStaticText *Phase;
		wxStaticText *Frequency;
		wxStaticText *Amplitude;
		wxStaticText *Initial_Condition;
		wxStaticText *Capacitance;
		wxStaticText *Resistance;
		wxStaticText *Voltage_Source;
		wxTextCtrl *Text_amp;
		wxTextCtrl *Text_Cap;
		wxTextCtrl *Text_Res;
		wxTextCtrl *Text_Freq;
		wxTextCtrl *Text_IC;
		wxTextCtrl *Text_Phase;
		wxTextCtrl *Text_Number;
		wxTextCtrl *Text_TimeStop;
		wxTextCtrl *Text_TimeStart;
		wxToggleButton *Square;
		wxToggleButton *Triangular;
		wxToggleButton *Sinusoidal;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_MNU_FILE_1043 = 1043,
			ID_MNU_EXIT_1045 = 1045,
			ID_MNU_HELP_1044 = 1044,
			ID_MNU_ABOUT____1046 = 1046,
			
			ID_TEXT_NUMBER = 1065,
			ID_NUMBER = 1064,
			ID_CB_TIMESTOP = 1063,
			ID_TEXT_TIMESTOP = 1062,
			ID_STOP = 1061,
			ID_CB_TIMESTART = 1060,
			ID_TEXT_TIMESTART = 1059,
			ID_TIME_START = 1058,
			ID_CB_IC = 1057,
			ID_TEXT_IC = 1055,
			ID_TEXT_PHA = 1054,
			ID_CB_PHASE = 1053,
			ID_CB_FREQ = 1052,
			ID_TEXT_FREQ = 1051,
			ID_CB_AMP = 1050,
			ID_CB_CAP = 1049,
			ID_CB_RES = 1048,
			ID_WXSTATICBITMAP1 = 1041,
			ID_SQUARE = 1040,
			ID_TRIANGULAR = 1038,
			ID_SINUSOIDAL = 1037,
			ID_PHASE = 1036,
			ID_FREQUENCY = 1035,
			ID_AMPLITUDE = 1034,
			ID_INITIAL_CONDITION = 1033,
			ID_CAPACITANCE = 1032,
			ID_RESISTANCE = 1031,
			ID_VOLTAGESOURCE = 1030,
			ID_START = 1028,
			ID_TEXT_AMP = 1017,
			ID_TEXT_CAP = 1016,
			ID_TEXT_RES = 1015,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
