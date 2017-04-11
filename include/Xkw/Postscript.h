/*  PostscriptP.h

    Public header for  Postscript  widget class.

    Copyright (C) 1994-1996  Richard Gooch

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
  Postscript widget.


    Written by      Richard Gooch   26-JUN-1994

    Last updated by Richard Gooch   20-DEC-1996

*/


/*----------------------------------------------------------------------*/
/* This widget implements a page setup control */
/*
 Name		         Class		       RepType         Default Value
 ----		         -----		       -------         -------------
 portraitOrientation     PortraitOrientation   Bool            True
 pageHorizontalOffset    PageHorizontalOffset  Int             10
 pageVerticalOffset      PageVerticalOffset    Int             10
 pageHorizontalSize      PageHorizontalSize    Int             180
 pageVerticalSize        PageVerticalSize      Int             180
 XkwNautoIncrement       AutoIncrement         Bool            FALSE
*/
/*----------------------------------------------------------------------*/

#ifndef POSTSCRIPT__H
#define POSTSCRIPT__H

#include <karma_kwin.h>

extern WidgetClass postscriptWidgetClass;
typedef struct _PostscriptClassRec *PostscriptWidgetClass;
typedef struct _PostscriptRec *PostscriptWidget;

#define XkwNportraitOrientation "portraitOrientation"
#define XkwNpageHorizontalOffset "pageHorizontalOffset"
#define XkwNpageVerticalOffset "pageVerticalOffset"
#define XkwNpageHorizontalSize "pageHorizontalSize"
#define XkwNpageVerticalSize "pageVerticalSize"
#define XkwNautoIncrement "autoIncrement"

#define XkwCPortraitOrientation "PortraitOrientation"
#define XkwCPageHorizontalOffset "PageHorizontalOffset"
#define XkwCPageVerticalOffset "PageVerticalOffset"
#define XkwCPageHorizontalSize "PageHorizontalSize"
#define XkwCPageVerticalSize "PageVerticalSize"
#define XkwCAutoIncrement "AutoIncrement"

#define XtIsPostscript(w) XtIsSubclass((w), postscriptWidgetClass)

EXTERN_FUNCTION (void XkwPostscriptRegisterImageAndName,
		 (Widget w, KPixCanvas image, char *name) );

#endif
