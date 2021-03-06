/*  OverlayMenu.h

    Public header for  OverlayMenu  widget class.

    Copyright (C) 1997-2002  Richard Gooch

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
    OverlayMenu widget, an overlay menu widget for Xt.


    Written by      Richard Gooch   18-JUL-1997

    Last updated by Richard Gooch   11-DEC-2002

*/
#ifndef OVERLAYMENU__H
#define OVERLAYMENU__H

#include <X11/StringDefs.h>
#include <X11/Xaw/MenuButton.h>
#include <karma_canvas.h>

extern WidgetClass overlayMenuWidgetClass;
typedef struct _OverlayMenuClassRec *OverlayMenuWidgetClass;
typedef struct _OverlayMenuRec *OverlayMenuWidget;

#define XtIsOverlayMenu(w) XtIsSubclass((w), overlayMenuWidgetClass)

#define XkwNcreateAtInit "createAtInit"
#define XkwNuseDataBrowser "useDataBrowser"

#define XkwCCreateAtInit "CreateAtInit"
#define XkwCUseDataBrowser "UseDataBrowser"


EXTERN_FUNCTION (void XkwOverlayMenuAddCanvas,
		 (Widget W, KWorldCanvas canvas) );


#endif
