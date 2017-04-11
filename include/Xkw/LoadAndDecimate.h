/*  LoadAndDecimate.h

    Public header for  LoadAndDecimate  widget class.

    Copyright (C) 1997  Richard Gooch

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
    LoadAndDecimate widget.


    Written by      Richard Gooch   20-APR-1997

    Last updated by Richard Gooch   13-MAY-1997

*/

#ifndef LoadAndDecimate__H
#define LoadAndDecimate__H

#include <X11/Xmu/Converters.h>
#include <karma_canvas.h>

extern WidgetClass loadAndDecimateWidgetClass;
typedef struct _LoadAndDecimateClassRec *LoadAndDecimateWidgetClass;
typedef struct _LoadAndDecimateRec *LoadAndDecimateWidget;

#define XtIsLoadAndDecimate(w) XtIsSubclass((w), loadAndDecimateWidgetClass)

#define XkwNverbose "verbose"

#define XkwCVerbose "Verbose"

EXTERN_FUNCTION (void XkwLoadAndDecimateGetCube,
		 (Widget W, CONST char *filename, CONST char *domain_name) );


#endif
