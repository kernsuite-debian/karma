/*  karma_contour.h

    Header for  contour_  package.

    Copyright (C) 1996-2004  Richard Gooch

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
  needed to interface to the contour_ routines in the Karma library.


    Written by      Richard Gooch   20-JUL-1996

    Last updated by Richard Gooch   2-MAY-2004

*/

#if !defined(KARMA_CONTOUR_DEF_H) || defined(MAKEDEPEND)
#  include <karma_contour_def.h>
#endif

#if !defined(KARMA_IARRAY_DEF_H) || defined(MAKEDEPEND)
#  include <karma_iarray_def.h>
#endif

#if !defined(KARMA_CANVAS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_canvas_def.h>
#endif

#if !defined(KARMA_C_DEF_H) || defined(MAKEDEPEND)
#  include <karma_c_def.h>
#endif

#ifndef KARMA_CONTOUR_H
#define KARMA_CONTOUR_H


#define CONTOUR_CANVAS_ATT_END               0
#define CONTOUR_CANVAS_ATT_COLOURNAME        1


/*  File:  main.c  */
EXTERN_FUNCTION (void contour_init, (KWorldCanvas canvas, ...) );
EXTERN_FUNCTION (KContourImageGroup contour_create_group, () );
EXTERN_FUNCTION (void contour_destroy_group, (KContourImageGroup group) );
EXTERN_FUNCTION (KContourImage contour_create_restr,
		 (multi_array *multi_desc, array_desc *arr_desc, char *slice,
		  unsigned int hdim, unsigned int vdim,
		  unsigned int elem_index, unsigned int num_restr,
		  char **restr_names, double *restr_values,
		  KContourImageGroup group) );
EXTERN_FUNCTION (KContourImage contour_create_from_iarray,
		 (iarray array, flag swap, KContourImageGroup group) );
EXTERN_FUNCTION (KContourImage *contour_create_sequence,
		 (multi_array *multi_desc, array_desc *arr_desc, char *cube,
		  unsigned int hdim, unsigned int vdim, unsigned int fdim,
		  unsigned int elem_index, KContourImageGroup group) );
EXTERN_FUNCTION (KContourImage *contour_create_sequence_from_iarray,
		 (iarray array,
		  unsigned int hdim, unsigned int vdim, unsigned int fdim,
		  KContourImageGroup group) );
EXTERN_FUNCTION (void contour_destroy, (KContourImage cimage) );
EXTERN_FUNCTION (KViewableContourImageGroup contour_create_viewable_group,() );
EXTERN_FUNCTION (void contour_destroy_viewable_group,
		 (KViewableContourImageGroup group) );
EXTERN_FUNCTION (KViewableContourImage contour_create_viewable,
		 (KContourImage cimage, KWorldCanvas canvas,
		  KViewableContourImageGroup group) );
EXTERN_FUNCTION (KViewableContourImage *contour_create_viewable_sequence,
		 (KContourImage *cimages, unsigned int num,
		  KWorldCanvas canvas, KViewableContourImageGroup group) );
EXTERN_FUNCTION (void contour_destroy_viewable,
		 (KViewableContourImage vcimage) );
EXTERN_FUNCTION (flag contour_set_active,
		 (KViewableContourImage vcimage, flag active,
		  flag force_refresh, flag refresh_if_changed) );
EXTERN_FUNCTION (flag contour_set_all_inactive,
		 (KViewableContourImageGroup group, flag refresh_if_changed) );
EXTERN_FUNCTION (flag contour_register_data_change, (KContourImage cimage) );
EXTERN_FUNCTION (void contour_set_canvas_attributes,
		 (KWorldCanvas canvas, ...) );
EXTERN_FUNCTION (void contour_set_levels,
		 (KContourImage cimage, unsigned int num_levels,
		  CONST double *contour_levels) );
EXTERN_FUNCTION (void contour_set_group_levels,
		 (KContourImageGroup group, unsigned int num_levels,
		  CONST double *contour_levels) );
EXTERN_FUNCTION (void contour_set_level_styles,
		 (KViewableContourImage vcimage,
		  CONST unsigned long *contour_pixels, CONST flag *dash,
		  CONST double *linewidths) );
EXTERN_FUNCTION (void contour_set_group_level_styles,
		 (KViewableContourImageGroup group,
		  CONST unsigned long *contour_pixels, CONST flag *dash,
		  CONST double *linewidths) );
EXTERN_FUNCTION (KWorldCanvas contour_get_worldcanvas,
		 (KViewableContourImage vcimage) );

/*  File:  misc.c  */
EXTERN_FUNCTION (unsigned int contour_parse_levels,
		 (double *contour_levels,
		  unsigned int max_levels, CONST char *string,
		  double min, double max) );
EXTERN_FUNCTION (void contour_unscale_levels,
		 (double *contour_levels, flag *dash,
		  double *linewidths, unsigned int num_levels,
		  double scale, double offset,
		  double neg_width, double pos_width) );


#endif /*  KARMA_CONTOUR_H  */
