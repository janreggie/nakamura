//---------------------------------------------------------------------------
//
// Name:        nakamuraApp.h
// Author:      JRAV
// Created:     2018-04-06 3:25:52 PM
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __PROJ2EBLFRMApp_h__
#define __PROJ2EBLFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class PROJ2EBLFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
