/*  karma_scatplt.h

    Header for  scatplt_  package.

    Copyright (C) 2001-2002  Richard Gooch

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

    This include file contains all the definitions and function declarations
  needed to interface to the scatplt_ routines in the Karma library.


    Written by      Richard Gooch   23-NOV-2001

    Last updated by Richard Gooch   13-DEC-2002

*/

#if !defined(KARMA_SCATPLT_DEF_H) || defined(MAKEDEPEND)
#  include <karma_scatplt_def.h>
#endif

#if !defined(KARMA_IARRAY_DEF_H) || defined(MAKEDEPEND)
#  include <karma_iarray_def.h>
#endif

#if !defined(KARMA_CANVAS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_canvas_def.h>
#endif

#if !defined(KARMA_WCS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_wcs_def.h>
#endif

#if !defined(KARMA_C_DEF_H) || defined(MAKEDEPEND)
#  include <karma_c_def.h>
#endif

#ifndef KARMA_SCATPLT_H
#define KARMA_SCATPLT_H


#define SCATPLT_CANVAS_ATT_END               0
#define SCATPLT_CANVAS_ATT_COLOURNAME        1


#define SCATPLT_CIMAGE_ATT_END             0
#define SCATPLT_CIMAGE_ATT_ACTIVE          1
#define SCATPLT_CIMAGE_ATT_COLOURNAME      2


/*  File:  main.c  */
EXTERN_FUNCTION (void scatplt_init, (KWorldCanvas canvas, ...) );
EXTERN_FUNCTION (KScatterPlot scatplt_create,
		 (KWorldCanvas canvas, unsigned int num_points,
		  CONST double *x, CONST double *y, uaddr key) );
EXTERN_FUNCTION (flag scatplt_set_active,
		 (KScatterPlot plot, flag active, flag force_refresh,
		  flag refresh_if_changed, flag exclusive, uaddr key) );
EXTERN_FUNCTION (flag scatplt_set_all_inactive,
		 (KWorldCanvas canvas, flag force_refresh,
		  flag refresh_if_changed, uaddr key) );
EXTERN_FUNCTION (void scatplt_destroy, (KScatterPlot plot) );
EXTERN_FUNCTION (void scatplt_set_canvas_attributes,
		 (KWorldCanvas canvas, ...) );
EXTERN_FUNCTION (void scatplt_set_attributes, (KScatterPlot cimage, ...) );
EXTERN_FUNCTION (KCallbackFunc scatplt_register_destroy_func,
		 (KScatterPlot plot, void (*func) (), void *info) );
EXTERN_FUNCTION (KWorldCanvas scatplt_get_worldcanvas, (KScatterPlot plot) );
EXTERN_FUNCTION (flag scatplt_find_closest,
		 (KScatterPlot plot, double xin, double yin,
		  double *xout, double *yout, uaddr *index,
		  flag subpixel, double search_radius) );
EXTERN_FUNCTION (flag scatplt_find_closest_all,
		 (KWorldCanvas canvas, double xin, double yin,
		  double *xout, double *yout, uaddr *index, KScatterPlot *plot,
		  flag subpixel, double search_radius) );


/*  File:  misc.c  */
EXTERN_FUNCTION (KScatterPlot scatplt_create_vv,
		 (KWorldCanvas canvas,
		  CONST char *array1, CONST array_desc *arr_desc1,
		  unsigned int xdim1, unsigned int ydim1,
		  unsigned int type1,
		  double scale1, double offset1, KwcsAstro ap1,
		  unsigned int num_restr1, CONST char **restr_names1,
		  CONST double *restr_values1,
		  double *min1, double *max1,
		  uaddr xstart, uaddr xlen,
		  uaddr ystart, uaddr ylen,
		  CONST char *array2,CONST array_desc *arr_desc2,
		  unsigned int xdim2, unsigned int ydim2,
		  unsigned int type2,
		  double scale2, double offset2, KwcsAstro ap2,
		  unsigned int num_restr2, CONST char **restr_names2,
		  CONST double *restr_values2,
		  double *min2, double *max2) );
EXTERN_FUNCTION (void scatplt_create_smart_cursor,
		 (KWorldCanvas canvas, double search_radius,
		  flag (*func) (), void *info) );


#endif /*  KARMA_SCATPLT_H  */
