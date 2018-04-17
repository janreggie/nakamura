///-----------------------------------------------------------------
///
/// @file      nakamuraFrm.cpp
/// @author    JRAV
/// Created:   2018-04-06 3:25:52 PM
/// @section   DESCRIPTION
///            PROJ2EBLFrm class implementation
///
///------------------------------------------------------------------

#include "nakamuraFrm.h"
#include "nakamuraBack.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
#include "Images/PROJ2EBLFrm_WxStaticBitmap1_XPM.xpm"
////Header Include End

//----------------------------------------------------------------------------
// PROJ2EBLFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(PROJ2EBLFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(PROJ2EBLFrm::OnClose)
	EVT_ACTIVATE(PROJ2EBLFrm::PROJ2EBLFrmActivate)
	EVT_MENU(ID_MNU_EXIT_1045, PROJ2EBLFrm::Mnuexit1045Click)
	EVT_MENU(ID_MNU_ABOUT____1046, PROJ2EBLFrm::Mnuabout1046Click)
	EVT_TOGGLEBUTTON(ID_SQUARE,PROJ2EBLFrm::WxToggleButton3Click)
	EVT_TOGGLEBUTTON(ID_TRIANGULAR,PROJ2EBLFrm::WxToggleButton2Click)
	EVT_TOGGLEBUTTON(ID_SINUSOIDAL,PROJ2EBLFrm::WxToggleButton1Click)
	EVT_BUTTON(ID_START,PROJ2EBLFrm::StartClick)
END_EVENT_TABLE()
////Event Table End

PROJ2EBLFrm::PROJ2EBLFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

PROJ2EBLFrm::~PROJ2EBLFrm()
{
}

void PROJ2EBLFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	WxMenuBar1 = new wxMenuBar();
	wxMenu *ID_MNU_FILE_1043_Mnu_Obj = new wxMenu();
	ID_MNU_FILE_1043_Mnu_Obj->Append(ID_MNU_EXIT_1045, _("E&xit\tAlt-x"), _(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_FILE_1043_Mnu_Obj, _("&File"));
	
	wxMenu *ID_MNU_HELP_1044_Mnu_Obj = new wxMenu();
	ID_MNU_HELP_1044_Mnu_Obj->Append(ID_MNU_ABOUT____1046, _("&About...\tF1"), _(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_HELP_1044_Mnu_Obj, _("&Help"));
	SetMenuBar(WxMenuBar1);

	Text_Number = new wxTextCtrl(this, ID_TEXT_NUMBER, _(""), wxPoint(385, 155), wxSize(96, 22), 0, wxTextValidator(wxFILTER_NONE, NULL), _("Text_Number"));

	Number = new wxStaticText(this, ID_NUMBER, _("Number:"), wxPoint(333, 157), wxDefaultSize, 0, _("Number"));

	wxArrayString arrayStringFor_CB_TimeStop;
	arrayStringFor_CB_TimeStop.Add(_("sec"));
	arrayStringFor_CB_TimeStop.Add(_("msec"));
	arrayStringFor_CB_TimeStop.Add(_("usec"));
	arrayStringFor_CB_TimeStop.Add(_("nsec"));
	CB_TimeStop = new wxComboBox(this, ID_CB_TIMESTOP, _(""), wxPoint(485, 128), wxSize(78, 23), arrayStringFor_CB_TimeStop, 0, wxDefaultValidator, _("CB_TimeStop"));

	Text_TimeStop = new wxTextCtrl(this, ID_TEXT_TIMESTOP, _(""), wxPoint(385, 128), wxSize(96, 22), 0, wxTextValidator(wxFILTER_NONE, NULL), _("Text_TimeStop"));

	Stop = new wxStaticText(this, ID_STOP, _("Stop:"), wxPoint(333, 130), wxDefaultSize, 0, _("Stop"));

	wxArrayString arrayStringFor_CB_TimeStart;
	arrayStringFor_CB_TimeStart.Add(_("sec"));
	arrayStringFor_CB_TimeStart.Add(_("msec"));
	arrayStringFor_CB_TimeStart.Add(_("usec"));
	arrayStringFor_CB_TimeStart.Add(_("nsec"));
	CB_TimeStart = new wxComboBox(this, ID_CB_TIMESTART, _(""), wxPoint(485, 99), wxSize(78, 23), arrayStringFor_CB_TimeStart, 0, wxDefaultValidator, _("CB_TimeStart"));

	Text_TimeStart = new wxTextCtrl(this, ID_TEXT_TIMESTART, _(""), wxPoint(385, 100), wxSize(96, 22), 0, wxTextValidator(wxFILTER_NONE, NULL), _("Text_TimeStart"));

	Time_Start = new wxStaticText(this, ID_TIME_START, _("Start:"), wxPoint(333, 103), wxDefaultSize, 0, _("Time_Start"));

	wxArrayString arrayStringFor_CB_IC;
	arrayStringFor_CB_IC.Add(_("mV"));
	arrayStringFor_CB_IC.Add(_("V"));
	arrayStringFor_CB_IC.Add(_("kV"));
	CB_IC = new wxComboBox(this, ID_CB_IC, _(""), wxPoint(190, 244), wxSize(78, 23), arrayStringFor_CB_IC, 0, wxDefaultValidator, _("CB_IC"));

	Text_IC = new wxTextCtrl(this, ID_TEXT_IC, _(""), wxPoint(89, 244), wxSize(96, 22), 0, wxDefaultValidator, _("Text_IC"));

	Text_Phase = new wxTextCtrl(this, ID_TEXT_PHA, _(""), wxPoint(89, 175), wxSize(96, 22), 0, wxDefaultValidator, _("Text_Phase"));

	wxArrayString arrayStringFor_CB_Phase;
	arrayStringFor_CB_Phase.Add(_("deg"));
	arrayStringFor_CB_Phase.Add(_("rad"));
	CB_Phase = new wxComboBox(this, ID_CB_PHASE, _(""), wxPoint(190, 175), wxSize(78, 23), arrayStringFor_CB_Phase, 0, wxDefaultValidator, _("CB_Phase"));

	wxArrayString arrayStringFor_CB_Freq;
	arrayStringFor_CB_Freq.Add(_("Hz"));
	arrayStringFor_CB_Freq.Add(_("rad/sec"));
	CB_Freq = new wxComboBox(this, ID_CB_FREQ, _(""), wxPoint(190, 146), wxSize(78, 23), arrayStringFor_CB_Freq, 0, wxDefaultValidator, _("CB_Freq"));

	Text_Freq = new wxTextCtrl(this, ID_TEXT_FREQ, _(""), wxPoint(90, 147), wxSize(96, 22), 0, wxDefaultValidator, _("Text_Freq"));

	wxArrayString arrayStringFor_CB_Amp;
	arrayStringFor_CB_Amp.Add(_("mV"));
	arrayStringFor_CB_Amp.Add(_("V"));
	arrayStringFor_CB_Amp.Add(_("kV"));
	CB_Amp = new wxComboBox(this, ID_CB_AMP, _(""), wxPoint(190, 116), wxSize(78, 23), arrayStringFor_CB_Amp, 0, wxDefaultValidator, _("CB_Amp"));

	wxArrayString arrayStringFor_CB_Cap;
	arrayStringFor_CB_Cap.Add(_("pF"));
	arrayStringFor_CB_Cap.Add(_("nF"));
	arrayStringFor_CB_Cap.Add(_("uF"));
	arrayStringFor_CB_Cap.Add(_("mF"));
	arrayStringFor_CB_Cap.Add(_("F"));
	CB_Cap = new wxComboBox(this, ID_CB_CAP, _(""), wxPoint(485, 56), wxSize(78, 23), arrayStringFor_CB_Cap, 0, wxDefaultValidator, _("CB_Cap"));

	wxArrayString arrayStringFor_CB_Res;
	arrayStringFor_CB_Res.Add(_("mOhms"));
	arrayStringFor_CB_Res.Add(_("Ohms"));
	arrayStringFor_CB_Res.Add(_("kOhms"));
	arrayStringFor_CB_Res.Add(_("MOhms"));
	arrayStringFor_CB_Res.Add(_("GOhms"));
	arrayStringFor_CB_Res.Add(_("TOhms"));
	CB_Res = new wxComboBox(this, ID_CB_RES, _(""), wxPoint(485, 25), wxSize(78, 23), arrayStringFor_CB_Res, 0, wxDefaultValidator, _("CB_Res"));

	wxBitmap WxStaticBitmap1_BITMAP(PROJ2EBLFrm_WxStaticBitmap1_XPM);
	WxStaticBitmap1 = new wxStaticBitmap(this, ID_WXSTATICBITMAP1, WxStaticBitmap1_BITMAP, wxPoint(316, 193), wxSize(337, 223));
	WxStaticBitmap1->SetBackgroundColour(wxColour(_("WHITE")));

	Square = new wxToggleButton(this, ID_SQUARE, _("Square"), wxPoint(136, 70), wxSize(75, 25), 0, wxDefaultValidator, _("Square"));

	Triangular = new wxToggleButton(this, ID_TRIANGULAR, _("Triangular"), wxPoint(136, 43), wxSize(75, 25), 0, wxDefaultValidator, _("Triangular"));

	Sinusoidal = new wxToggleButton(this, ID_SINUSOIDAL, _("Sinusoidal"), wxPoint(136, 16), wxSize(75, 25), 0, wxDefaultValidator, _("Sinusoidal"));

	Phase = new wxStaticText(this, ID_PHASE, _("Phase:"), wxPoint(26, 179), wxDefaultSize, 0, _("Phase"));

	Frequency = new wxStaticText(this, ID_FREQUENCY, _("Frequency:"), wxPoint(26, 150), wxDefaultSize, 0, _("Frequency"));

	Amplitude = new wxStaticText(this, ID_AMPLITUDE, _("Amplitude:"), wxPoint(26, 118), wxDefaultSize, 0, _("Amplitude"));

	Initial_Condition = new wxStaticText(this, ID_INITIAL_CONDITION, _("Initial Condition (Vc0):"), wxPoint(26, 225), wxDefaultSize, 0, _("Initial_Condition"));

	Capacitance = new wxStaticText(this, ID_CAPACITANCE, _("Capacitance:"), wxPoint(307, 57), wxDefaultSize, 0, _("Capacitance"));

	Resistance = new wxStaticText(this, ID_RESISTANCE, _("Resistance:"), wxPoint(307, 28), wxDefaultSize, 0, _("Resistance"));

	Voltage_Source = new wxStaticText(this, ID_VOLTAGESOURCE, _("Voltage Source(s):"), wxPoint(26, 47), wxDefaultSize, 0, _("Voltage_Source"));

	Start = new wxButton(this, ID_START, _("BEGIN SIMULATION"), wxPoint(25, 275), wxSize(244, 38), 0, wxDefaultValidator, _("Start"));

	Text_amp = new wxTextCtrl(this, ID_TEXT_AMP, _(""), wxPoint(89, 117), wxSize(96, 22), 0, wxDefaultValidator, _("Text_amp"));

	Text_Cap = new wxTextCtrl(this, ID_TEXT_CAP, _(""), wxPoint(385, 56), wxSize(96, 22), 0, wxTextValidator(wxFILTER_NONE, NULL), _("Text_Cap"));

	Text_Res = new wxTextCtrl(this, ID_TEXT_RES, _(""), wxPoint(385, 25), wxSize(96, 22), 0, wxDefaultValidator, _("Text_Res"));

	SetTitle(_("RC Circuit Simulator"));
	SetIcon(wxNullIcon);
	SetSize(8,8,700,484);
	Center();
	
	////GUI Items Creation End
}

void PROJ2EBLFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * PROJ2EBLFrmActivate
 */
void PROJ2EBLFrm::PROJ2EBLFrmActivate(wxActivateEvent& event)
{
	// insert your code here
}

/*
 * WxToggleButton1Click
 */
void PROJ2EBLFrm::WxToggleButton1Click(wxCommandEvent& event)
{
	// insert your code here
	sine = !sine;
}

/*
 * WxToggleButton2Click
 */
void PROJ2EBLFrm::WxToggleButton2Click(wxCommandEvent& event)
{
	// insert your code here
	tria = !tria;
}

/*
 * WxToggleButton3Click
 */
void PROJ2EBLFrm::WxToggleButton3Click(wxCommandEvent& event)
{
	// insert your code here
	squa = !squa;
}

/*
 * Mnuexit1045Click
 */
void PROJ2EBLFrm::Mnuexit1045Click(wxCommandEvent& event)
{
	// insert your code here
	Close(true);
	
}

/*
 * Mnuabout1046Click
 */
void PROJ2EBLFrm::Mnuabout1046Click(wxCommandEvent& event)
{
	// insert your code here
	wxString msg;

  msg.Printf
  (
    _T("This is the About dialog of Project 2.\n")
  );

   

  wxMessageBox(msg, _T("About Project 2"),wxOK | wxICON_INFORMATION, this);
}

/*
 * StartClick
 */
void PROJ2EBLFrm::StartClick(wxCommandEvent& event)
{
	//FIRST, check for proper input
  //declare temporary string to obtain wxString value
	string temp_checker;
	//always reset error to 0 everytime Start is clicked
	error = 0;
	
	//Begin checking for voltage source input
	if (sine && tria) ++error; //sw1 & sw2
	if (sine && squa) ++error; //sw1 & sw3
	if (tria && squa) ++error; //sw2 & sw3
	if (sine && tria && squa) ++error; //no input
	
	//Begin checking for each text input
	temp_checker = Text_Res->GetValue(); //resistance
	ErrorChecker(temp_checker);
	if (Text_Res->IsEmpty()) error++;
  temp_checker = Text_Cap->GetValue(); // capacitance
  ErrorChecker(temp_checker);
 	if (Text_Cap->IsEmpty()) error++;
  temp_checker = Text_amp->GetValue(); //amplitude
  ErrorChecker(temp_checker);
 	if (Text_amp->IsEmpty()) error++;
  temp_checker = Text_Freq->GetValue(); //frequency
  ErrorChecker(temp_checker);
  if (Text_Freq->IsEmpty()) error++;
  temp_checker = Text_Phase->GetValue(); //phase
  ErrorChecker(temp_checker);
  if (Text_Phase->IsEmpty()) error++;
  temp_checker = Text_TimeStart->GetValue(); //time start
  ErrorChecker(temp_checker);
  if (Text_TimeStart->IsEmpty()) error++;
  temp_checker = Text_TimeStop->GetValue(); //time stop
  ErrorChecker(temp_checker);
  if (Text_TimeStop->IsEmpty()) error++;
  temp_checker = Text_Number->GetValue(); //number
  ErrorChecker(temp_checker);
  if (Text_Number->IsEmpty()) error++;
  temp_checker = Text_IC->GetValue(); //initial conditions
  ErrorChecker(temp_checker);
  if (Text_IC->IsEmpty()) error++;

  if (error > 0) //INPUT ERROR
    wxMessageBox(error_msg, _T("Invalid Input"),wxOK 
    | wxICON_INFORMATION, this);
  else //PROCEED WITH SIMULATION
  {
    // Assign voltage source
    if (sine) VSrc = 0;
    else if (squa) VSrc = 1;
    else if (tria) VSrc = 2;
    
    //get values of text fields and assign to the corresponding var
    Text_Res->GetValue().ToDouble(&Res);
    Text_Cap->GetValue().ToDouble(&Cap);
    Text_amp->GetValue().ToDouble(&VAmp);
    Text_Freq->GetValue().ToDouble(&VFre);
    Text_Phase->GetValue().ToDouble(&VPha);
    //Text_Number->GetValue().ToDouble(&TNum); //might not work
    Text_TimeStart->GetValue().ToDouble(&TStart);
    Text_TimeStop->GetValue().ToDouble(&TStop);
    Text_IC->GetValue().ToDouble(&VNu);
    
    //get values of units
    Units_Res = CB_Res->GetValue();
    Units_Cap = CB_Cap->GetValue();
    Units_Amp = CB_Amp->GetValue();
    Units_Freq = CB_Freq->GetValue();
    Units_Pha = CB_Phase->GetValue();
    Units_TStart = CB_TimeStart->GetValue();
    Units_TStop = CB_TimeStop->GetValue();
    Units_IC = CB_IC->GetValue();
    
    //convert values based on units
    //resistance
    if (Units_Res == "mOhms") Res = Res/1000;
    else if (Units_Res == "kOhms") Res = Res*1000;
    else if (Units_Res == "MOhms") Res = Res*1000000;
    
    //capacitance
    if (Units_Cap == "pF") Cap = Cap/1000000000000;
    else if (Units_Cap == "nF") Cap = Cap/1000000000;
    else if (Units_Cap == "uF") Cap = Cap/1000000;
    else if (Units_Cap == "mF") Cap = Cap/1000;
    
    //amplitude & initial conditions
    if (Units_Amp == "mV") VAmp = VAmp/1000;
    else if (Units_Amp == "kV") VAmp = VAmp*1000;
    if (Units_IC == "mV") VNu = VNu/1000;
    else if (Units_IC == "kV") VNu = VNu*1000;
    
    //Frequency
    if (Units_Freq == "Hz") VFre = 2*M_PI*VFre;
    
    //Phase
    if (Units_Pha == "deg") VPha = 2*M_PI*VPha;
    
    //Time start and stop
    if (Units_TStart == "msec") TStart = TStart/1000;
    else if (Units_TStart == "usec") TStart = TStart/1000000;
    else if (Units_TStart == "nsec") TStart = TStart/1000000000;
    
    //writeToTemp();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    wxMessageBox("Simulation Successful", _T("SUCCESS"), wxOK
    | wxICON_INFORMATION, this);
  }
  
}

