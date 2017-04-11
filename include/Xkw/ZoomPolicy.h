/*  ZoomPolicy.h

    Public header for  ZoomPolicy  widget class.

    Copyright (C) 1996-2005  Richard Gooch

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

    This include file contains the public class declarations for the ZoomPolicy
  widget.


    Written by      Richard Gooch   12-MAY-1996

    Last updated by Richard Gooch   30-OCT-2005

*/
#ifndef ZOOMPOLICY__H
#define ZOOMPOLICY__H

#include <X11/Xmu/Converters.h>
#include <karma_canvas.h>

extern WidgetClass zoomPolicyWidgetClass;
typedef struct _ZoomPolicyClassRec *ZoomPolicyWidgetClass;
typedef struct _ZoomPolicyRec *ZoomPolicyWidget;

#define XtIsZoomPolicy(w) XtIsSubclass((w), zoomPolicyWidgetClass)

#define XkwNshowMiddleZoom "showMiddleZoom"
#define XkwNshowRightZoom "showRightZoom"

#define XkwCShowMiddleZoom "ShowMiddleZoom"
#define XkwCShowRightZoom "ShowRightZoom"


EXTERN_FUNCTION (void XkwZoomPolicyAddCanvas, (Widget W,KWorldCanvas canvas) );


#endif
