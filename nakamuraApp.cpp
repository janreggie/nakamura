//---------------------------------------------------------------------------
//
// Name:        nakamuraApp.cpp
// Author:      JRAV
// Created:     2018-04-06 3:25:52 PM
// Description: 
//
//---------------------------------------------------------------------------

#include "nakamuraApp.h"
#include "nakamuraFrm.h"

IMPLEMENT_APP(PROJ2EBLFrmApp)

bool PROJ2EBLFrmApp::OnInit()
{
    PROJ2EBLFrm* frame = new PROJ2EBLFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int PROJ2EBLFrmApp::OnExit()
{
	return 0;
}
