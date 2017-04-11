/*  DataBrowser.h

    Public header for  DataBrowser  widget class.

    Copyright (C) 2002-2004  Richard Gooch

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    Richard Gooch may be reached by email at  karma-request@atnf.csiro.au
    The postal address is:
      Richard Gooch, c/o ATNF, P. O. Box 76, Epping, N.S.W., 2121, Australia.
*/

/*

    This include file contains the public class declarations for the
    DataBrowser widget.


    Written by      Richard Gooch   23-NOV-2002

    Last updated by Richard Gooch   14-JUL-2004

*/
#ifndef DataBrowser__H
#define DataBrowser__H

#include <X11/Shell.h>

extern WidgetClass dataBrowserWidgetClass;
typedef struct _DataBrowserClassRec *DataBrowserWidgetClass;
typedef struct _DataBrowserRec *DataBrowserWidget;

#define XtIsDataBrowser(w) XtIsSubclass((w), dataBrowserWidgetClass)

#define XkwNpopupFirstDataBrowser         "popupFirstDataBrowser"
#define XkwNcreateAtInit                  "createAtInit"

#define XkwCPopupFirstDataBrowser         "PopupFirstDataBrowser"
#define XkwCCreateAtInit                  "CreateAtInit"


EXTERN_FUNCTION (void XkwDataBrowserPopup,
		 (KDisplayDataBlinkState blinkstate) );
EXTERN_FUNCTION (KDisplayDataBlinkEntry XkwDataBrowserGetAlternate,
		 (KDisplayDataBlinkState bs) );


#endif
