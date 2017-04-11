/*  SimpleProgressMeterP.h

    Private header for  SimpleProgressMeter  widget class.

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

    This include file contains the private class declarations for the
  SimpleProgressMeter widget.


    Written by      Richard Gooch   19-APR-1997

    Last updated by Richard Gooch   26-OCT-2005

*/
#ifndef _SimpleProgressMeterP_h
#define _SimpleProgressMeterP_h

#include <X11/Xaw/SimpleP.h>
#include <Xkw/CanvasP.h>
#include <Xkw/SimpleProgressMeter.h>

typedef struct {
    /* resources */
    Cardinal        maximum;
    Cardinal        value;
    String          label;
    /* private state */
} SimpleProgressMeterPart;

typedef struct
{
    int empty;
} SimpleProgressMeterClassPart;

typedef struct _SimpleProgressMeterClassRec {
    CoreClassPart	   core_class;
    SimpleClassPart        simple_class;
    CanvasClassPart        canvas_class;
    SimpleProgressMeterClassPart  progressMeter_class;
} SimpleProgressMeterClassRec;

extern SimpleProgressMeterClassRec simpleProgressMeterClassRec;

typedef struct _SimpleProgressMeterRec {
    CorePart	core;
    SimplePart  simple;
    CanvasPart  canvas;
    SimpleProgressMeterPart	progressMeter;
} SimpleProgressMeterRec;

#endif /* _SimpleProgressMeterP_h */
