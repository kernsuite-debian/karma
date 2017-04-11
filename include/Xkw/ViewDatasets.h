/*  ViewDatasets.h

    Public header for  ViewDatasets  widget class.

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
  ViewDatasets widget.


    Written by      Richard Gooch   5-DEC-2002

    Last updated by Richard Gooch   20-JUN-2004

*/
#ifndef VIEWDATASETS__H
#define VIEWDATASETS__H

#include <X11/Xmu/Converters.h>

#if !defined(KARMA_VRENDER_DEF_H) || defined(MAKEDEPEND)
#  include <karma_vrender_def.h>
#endif

#if !defined(KARMA_VIEWIMG_DEF_H) || defined(MAKEDEPEND)
#  include <karma_viewimg_def.h>
#endif

#if !defined(KARMA_IARRAY_DEF_H) || defined(MAKEDEPEND)
#  include <karma_iarray_def.h>
#endif

extern WidgetClass viewDatasetsWidgetClass;
typedef struct _ViewDatasetsClassRec *ViewDatasetsWidgetClass;
typedef struct _ViewDatasetsRec *ViewDatasetsWidget;

#define XtIsViewDatasets(w) XtIsSubclass((w), viewDatasetsWidgetClass)

#define XkwNcursorCallback "cursorCallback"
#define XkwNwmtitle "wmtitle"
#define XkwNverbose "verbose"

#define XkwCWMtitle "WMtitle"
#define XkwCVerbose "Verbose"

typedef struct XkwViewDatasetsCursor  /*  EXPERIMENTAL: subject to change  */
{
    unsigned int set_number;
    Kcoord_3d pixel;    /*  This is in data pixel co-ordinates   */
} *XkwViewDatasetsCallbackData;

typedef struct  /*  EXPERIMENTAL: subject to change  */
{
    Widget image_display;
    CONST char *inp_xname;
    CONST char *inp_yname;
    CONST char *inp_zname;
    CONST char *out_xname;
    CONST char *out_yname;
    CONST char *out_zname;
    double x;
    double y;
    double z;
} XkwViewDatasetsCoordConvertData;


#endif
