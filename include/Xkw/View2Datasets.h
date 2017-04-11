/*  View2Datasets.h

    Public header for  View2Datasets  widget class.

    Copyright (C) 1997-2000  Richard Gooch

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
  View2Datasets widget.


    Written by      Richard Gooch   22-JAN-1997

    Last updated by Richard Gooch   12-JUL-2000

*/
#ifndef VIEW2DATASETS__H
#define VIEW2DATASETS__H

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

extern WidgetClass view2DatasetsWidgetClass;
typedef struct _View2DatasetsClassRec *View2DatasetsWidgetClass;
typedef struct _View2DatasetsRec *View2DatasetsWidget;

#define XtIsView2Datasets(w) XtIsSubclass((w), view2DatasetsWidgetClass)

#define XkwNcursorCallback "cursorCallback"
#define XkwNcreateAtInit "createAtInit"
#define XkwNwmtitle "wmtitle"
#define XkwNverbose "verbose"

#define XkwCCreateAtInit "CreateAtInit"
#define XkwCWMtitle "WMtitle"
#define XkwCVerbose "Verbose"

typedef struct XkwView2DatasetsCursor  /*  EXPERIMENTAL: subject to change  */
{
    unsigned int set_number;
    Kcoord_3d pixel;    /*  This is in data pixel co-ordinates   */
} *XkwView2DatasetsCallbackData;

EXTERN_FUNCTION (flag XkwView2DatasetsRegisterDataset,
		 (Widget W, iarray pseudo, double min, double max,
		  iarray red, iarray green, iarray blue,
		  unsigned int set_number) );
EXTERN_FUNCTION (void XkwView2DatasetsInvalidatePlane,
		 (Widget W, unsigned int set_number,
		  unsigned int dim_index, unsigned long plane_index) );
EXTERN_FUNCTION (void XkwView2DatasetsInvalidateAll,
		 (Widget W, unsigned int set_number) );
EXTERN_FUNCTION (flag XkwView2DatasetsCanvasEventHandler,
		 (ViewableImage vimage, double x, double y,
		  void *value, unsigned int event_code,
		  void *e_info, void **f_info,
		  double x_lin, double y_lin, unsigned int value_type,
		  double x_im, double y_im, int x_pix, int y_pix) );


#endif
