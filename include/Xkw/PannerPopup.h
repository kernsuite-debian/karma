/*  PannerPopup.h

    Public header for  PannerPopup  widget class.

    Copyright (C) 1997-1998  Richard Gooch

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
  PannerPopup widget, an image display (application) widget for Xt.


    Written by      Richard Gooch   6-DEC-1997

    Last updated by Richard Gooch   22-FEB-1998

*/
#ifndef PANNERPOPUP__H
#define PANNERPOPUP__H

#include <X11/Xmu/Converters.h>
#include <karma_canvas.h>
#include <Xkw/SlaveImageDisplayPopup.h>


extern WidgetClass pannerPopupWidgetClass;
typedef struct _PannerPopupClassRec *PannerPopupWidgetClass;
typedef struct _PannerPopupRec *PannerPopupWidget;

#define XtIsPannerPopup(w) XtIsSubclass((w), pannerPopupWidgetClass)


EXTERN_FUNCTION (void XkwPannerPopupAddCanvas,
		 (Widget W, KWorldCanvas canvas) );


#endif
