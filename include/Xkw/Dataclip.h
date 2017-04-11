/*  Dataclip.h

    Public header for  Dataclip  widget class.

    Copyright (C) 1994-2003  Richard Gooch

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
  Dataclip widget, a graphical widget to select data regions for Xt.


    Written by      Richard Gooch   23-OCT-1994

    Last updated by Richard Gooch   4-OCT-2003

*/
#ifndef DATACLIP__H
#define DATACLIP__H

#include <karma_iarray_def.h>

extern WidgetClass dataclipWidgetClass;
typedef struct _DataclipClassRec *DataclipWidgetClass;
typedef struct _DataclipRec *DataclipWidget;

typedef struct
{
    flag blank_data_outside_regions;
    unsigned int num_regions;
    double *minima;
    double *maxima;
} DataclipRegions;

#define XtIsDataclip(w) XtIsSubclass((w), dataclipWidgetClass)

#define XkwNmaxDataRegions "maxDataRegions"
#define XkwNscaledRegionCallback "scaledRegionCallback"
#define XkwNrawRegionCallback "rawRegionCallback"
#define XkwNshowBlankControl "showBlankControl"
#define XkwNfixedOutputType "fixedOutputType"
#define XkwNautoPopdown "autoPopdown"
#define XkwNverbose "verbose"

#define XkwCMaxDataRegions "MaxDataRegions"
#define XkwCShowBlankControl "ShowBlankControl"
#define XkwCFixedOutputType "FixedOutputType"
#define XkwCAutoPopdown "AutoPopdown"
#define XkwCVerbose "Verbose"


EXTERN_FUNCTION (void XkwDataclipNewArray,
		 (Widget W, iarray array, double min, double max,
		  flag reset_hscale) );
EXTERN_FUNCTION (void XkwDataclipArrayChanged,
		 (Widget W, double min, double max) );
EXTERN_FUNCTION (void XkwDataclipSetRegions,
		 (Widget W, CONST DataclipRegions *regions) );

#endif
