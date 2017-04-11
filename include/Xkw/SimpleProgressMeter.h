/*  SimpleProgressMeter.h

    Public header for  SimpleProgressMeter  widget class.

    Copyright (C) 1997-2005  Richard Gooch

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
  SimpleProgressMeter widget.


    Written by      Richard Gooch   19-APR-1997

    Last updated by Richard Gooch   26-OCT-2005

*/

#ifndef _SimpleProgressMeter_h
#define _SimpleProgressMeter_h

#include <X11/Xmu/Converters.h>
#include <X11/StringDefs.h>
#include <X11/Shell.h>
#include <karma_kwin.h>

/* Resources:

 Name		           Class		RepType		Default Value
 ----		           -----		-------		-------------
 XkwNminimum               Minimum              Cardinal        0
 XtNvalue                  Value                Cardinal        0
 XtNlabel                  Label                String          NULL

*/

extern WidgetClass simpleProgressMeterWidgetClass;
typedef struct _SimpleProgressMeterClassRec   *SimpleProgressMeterWidgetClass;
typedef struct _SimpleProgressMeterRec	*SimpleProgressMeterWidget;

#define XtIsSimpleProgressMeter(w) XtIsSubclass((w), simpleProgressMeterWidgetClass)

#define XkwNmaximum "maximum"

#define XkwCMaximum "Maximum"

#endif /* _SimpleProgressMeter_h */
