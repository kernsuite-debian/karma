/*  karma_vectmap.h

    Header for  vectmap_  package.

    Copyright (C) 2004  Richard Gooch

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
  needed to interface to the vectmap_ routines in the Karma library.


    Written by      Richard Gooch   19-AUG-2004

    Last updated by Richard Gooch   19-AUG-2004

*/

#if !defined(KARMA_VECTMAP_DEF_H) || defined(MAKEDEPEND)
#  include <karma_vectmap_def.h>
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

#ifndef KARMA_VECTMAP_H
#define KARMA_VECTMAP_H


#define VECTMAP_CANVAS_ATT_END               0
#define VECTMAP_CANVAS_ATT_COLOURNAME        1


/*  File:  main.c  */
EXTERN_FUNCTION (void vectmap_init, (KWorldCanvas canvas, ...) );
EXTERN_FUNCTION (KVectorFieldGroup vectmap_create_group, () );
EXTERN_FUNCTION (void vectmap_destroy_group, (KVectorFieldGroup group) );
EXTERN_FUNCTION (KVectorField vectmap_create_restr,
		 (multi_array *multi_desc, array_desc *arr_desc, char *slice,
		  unsigned int hdim, unsigned int vdim,
		  unsigned int elem_index, unsigned int num_restr,
		  char **restr_names, double *restr_values,
		  KVectorFieldGroup group) );
EXTERN_FUNCTION (KVectorField vectmap_create_from_iarray,
		 (iarray array, flag swap, KVectorFieldGroup group) );
EXTERN_FUNCTION (KVectorField *vectmap_create_sequence,
		 (multi_array *multi_desc, array_desc *arr_desc, char *cube,
		  unsigned int hdim, unsigned int vdim, unsigned int fdim,
		  unsigned int elem_index, KVectorFieldGroup group) );
EXTERN_FUNCTION (KVectorField *vectmap_create_sequence_from_iarray,
		 (iarray array,
		  unsigned int hdim, unsigned int vdim, unsigned int fdim,
		  KVectorFieldGroup group) );
EXTERN_FUNCTION (void vectmap_destroy, (KVectorField cimage) );
EXTERN_FUNCTION (flag vectmap_set_active,
		 (KViewableVectmapImage vcimage, flag active,
		  flag force_refresh, flag refresh_if_changed) );
EXTERN_FUNCTION (flag vectmap_set_all_inactive,
		 (KViewableVectmapImageGroup group, flag refresh_if_changed) );
EXTERN_FUNCTION (flag vectmap_register_data_change, (KVectorField cimage) );
EXTERN_FUNCTION (void vectmap_set_canvas_attributes,
		 (KWorldCanvas canvas, ...) );
EXTERN_FUNCTION (void vectmap_set_levels,
		 (KVectorField cimage, unsigned int num_levels,
		  CONST double *vectmap_levels) );
EXTERN_FUNCTION (void vectmap_set_group_levels,
		 (KVectorFieldGroup group, unsigned int num_levels,
		  CONST double *vectmap_levels) );
EXTERN_FUNCTION (void vectmap_set_level_styles,
		 (KViewableVectmapImage vcimage,
		  CONST unsigned long *vectmap_pixels, CONST flag *dash,
		  CONST double *linewidths) );
EXTERN_FUNCTION (void vectmap_set_group_level_styles,
		 (KViewableVectmapImageGroup group,
		  CONST unsigned long *vectmap_pixels, CONST flag *dash,
		  CONST double *linewidths) );
EXTERN_FUNCTION (KWorldCanvas vectmap_get_worldcanvas,
		 (KViewableVectmapImage vcimage) );


#endif /*  KARMA_VECTMAP_H  */
