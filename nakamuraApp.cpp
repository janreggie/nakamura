/***************************************************************
 * Name:      nakamuraApp.cpp
 * Purpose:   Code for Application Class
 * Author:    janreggie, jriaghan, sangjeona ()
 * Created:   2018-04-05
 * Copyright: janreggie, jriaghan, sangjeona ()
 * License:   MIT License
 **************************************************************/

#include "nakamuraApp.h"

//(*AppHeaders
#include "nakamuraMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(nakamuraApp);

bool nakamuraApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	nakamuraFrame* Frame = new nakamuraFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
