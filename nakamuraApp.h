/***************************************************************
 * Name:      nakamuraApp.h
 * Purpose:   Defines Application Class
 * Author:    janreggie, jriaghan, sangjeona ()
 * Created:   2018-04-05
 * Copyright: janreggie, jriaghan, sangjeona ()
 * License:   MIT License
 **************************************************************/

#ifndef NAKAMURAAPP_H
#define NAKAMURAAPP_H

#include <wx/app.h>

class nakamuraApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // NAKAMURAAPP_H
