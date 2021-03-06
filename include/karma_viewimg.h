/*  karma_viewimg.h

    Header for  viewimg_  package.

    Copyright (C) 1993-2005  Richard Gooch

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
  needed to interface to the viewimg_ routines in the Karma library.


    Written by      Richard Gooch   18-APR-1993

    Last updated by Richard Gooch   19-JUL-2005

*/

#if !defined(KARMA_VIEWIMG_DEF_H) || defined(MAKEDEPEND)
#  include <karma_viewimg_def.h>
#endif

#if !defined(KARMA_IARRAY_DEF_H) || defined(MAKEDEPEND)
#  include <karma_iarray_def.h>
#endif

#if !defined(KARMA_CANVAS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_canvas_def.h>
#endif

#if !defined(KARMA_IEDIT_H) || defined(MAKEDEPEND)
#  include <karma_iedit.h>
#endif

#if !defined(KARMA_KWIN_DEF_H) || defined(MAKEDEPEND)
#  include <karma_kwin_def.h>
#endif

#if !defined(KARMA_C_DEF_H) || defined(MAKEDEPEND)
#  include <karma_c_def.h>
#endif

#ifndef KARMA_VIEWIMG_H
#define KARMA_VIEWIMG_H


#define VIEWIMG_ATT_END                    0
#define VIEWIMG_ATT_AUTO_X                 1
#define VIEWIMG_ATT_AUTO_Y                 2
#define VIEWIMG_ATT_AUTO_V                 3
#define VIEWIMG_ATT_INT_X                  4
#define VIEWIMG_ATT_INT_Y                  5
#define VIEWIMG_ATT_MAINTAIN_ASPECT        6
#define VIEWIMG_ATT_ALLOW_TRUNCATION       7
#define VIEWIMG_ATT_ENABLE_PANNING         8
#define VIEWIMG_ATT_PAN_CENTRE_X           9
#define VIEWIMG_ATT_PAN_CENTRE_Y          10
#define VIEWIMG_ATT_PAN_MAGNIFICATION     11
#define VIEWIMG_ATT_SHOW_COLOURBAR        12

#define VIEWIMG_ATT_AUTO_WCS             100  /*  Experimental  */
#define VIEWIMG_ATT_FAST_PANNER          101  /*  Experimental  */


#define VIEWIMG_VATT_END                   0
#define VIEWIMG_VATT_TRUECOLOUR            1
#define VIEWIMG_VATT_ARRAY_DESC            2
#define VIEWIMG_VATT_SLICE                 3
#define VIEWIMG_VATT_HDIM                  4
#define VIEWIMG_VATT_VDIM                  5
#define VIEWIMG_VATT_PSEUDO_INDEX          6
#define VIEWIMG_VATT_RED_INDEX             7
#define VIEWIMG_VATT_GREEN_INDEX           8
#define VIEWIMG_VATT_BLUE_INDEX            9
#define VIEWIMG_VATT_MULTI_ARRAY          10
#define VIEWIMG_VATT_DATA_SCALE           11
#define VIEWIMG_VATT_DATA_OFFSET          12
#define VIEWIMG_VATT_VALUE_MIN            13
#define VIEWIMG_VATT_VALUE_MAX            14

#define VIEWIMG_VATT_WCS_ASTRO           100 /*  Experimental                */
#define VIEWIMG_VATT_NUM_RESTRICTIONS    101
#define VIEWIMG_VATT_RESTRICTION_NAMES   102
#define VIEWIMG_VATT_RESTRICTION_VALUES  103
#define VIEWIMG_VATT_CMAP                104


/*  File:   main.c  */
EXTERN_FUNCTION (void viewimg_init, (KWorldCanvas canvas) );
EXTERN_FUNCTION (ViewableImage viewimg_create_restr,
		 (KWorldCanvas canvas, multi_array *multi_desc,
		  array_desc *arr_desc, char *slice,
		  unsigned int hdim, unsigned int vdim,
		  unsigned int elem_index, unsigned num_restr,
		  CONST char **restr_names, CONST double *restr_values) );
EXTERN_FUNCTION (ViewableImage viewimg_create, (KWorldCanvas canvas,
						multi_array *multi_desc,
						array_desc *arr_desc,
						char *slice,
						unsigned int hdim,
						unsigned int vdim,
						unsigned int elem_index) );
EXTERN_FUNCTION (ViewableImage viewimg_create_from_iarray,
		 (KWorldCanvas canvas, iarray array, flag swap) );
EXTERN_FUNCTION (ViewableImage *viewimg_create_sequence,
		 (KWorldCanvas canvas, multi_array *multi_desc,
		  array_desc *arr_desc, char *cube,
		  unsigned int hdim, unsigned int vdim, unsigned int fdim,
		  unsigned int elem_index) );
EXTERN_FUNCTION (ViewableImage *viewimg_create_sequence_from_iarray,
		 (KWorldCanvas canvas, iarray array,
		  unsigned int hdim, unsigned int vdim, unsigned int fdim) );
EXTERN_FUNCTION (ViewableImage viewimg_create_rgb,
		 (KWorldCanvas canvas, multi_array *multi_desc,
		  array_desc *arr_desc, char *slice, unsigned int hdim,
		  unsigned int vdim, unsigned int red_index,
		  unsigned int green_index, unsigned int blue_index,
		  unsigned num_restr, CONST char **restr_names,
		  CONST double *restr_values) );
EXTERN_FUNCTION (ViewableImage viewimg_create_rgb2,
		 (KWorldCanvas canvas, multi_array *multi_desc,
		  array_desc *arr_desc, array_pointer *arrayp, char *slice,
		  unsigned int hdim, unsigned int vdim,
		  unsigned int red_index, unsigned int green_index,
		  unsigned int blue_index, unsigned num_restr,
		  CONST char **restr_names, CONST double *restr_values) );
EXTERN_FUNCTION (ViewableImage *viewimg_create_rgb_sequence,
		 (KWorldCanvas canvas, multi_array *multi_desc,
		  array_desc *arr_desc, char *cube,
		  unsigned int hdim, unsigned int vdim, unsigned int fdim,
		  unsigned int red_index, unsigned int green_index,
		  unsigned int blue_index, unsigned num_restr,
		  CONST char **restr_names, CONST double *restr_values) );
EXTERN_FUNCTION (ViewableImage *viewimg_create_rgb_sequence2,
		 (KWorldCanvas canvas, multi_array *multi_desc,
		  array_desc *arr_desc, array_pointer *arrayp, char *cube,
		  unsigned int hdim, unsigned int vdim, unsigned int fdim,
		  unsigned int red_index, unsigned int green_index,
		  unsigned int blue_index, unsigned num_restr,
		  CONST char **restr_names, CONST double *restr_values) );
EXTERN_FUNCTION (flag viewimg_make_active, (ViewableImage vimage) );
EXTERN_FUNCTION (flag viewimg_set_active,
		 (ViewableImage vimage, flag refresh) );
EXTERN_FUNCTION (void viewimg_control_autoscaling,
		 (KWorldCanvas canvas,
		  flag auto_x, flag auto_y, flag auto_v,
		  flag int_x, flag int_y, flag maintain_aspect_ratio) );
EXTERN_FUNCTION (flag viewimg_register_data_change, (ViewableImage vimage) );
EXTERN_FUNCTION (void viewimg_destroy, (ViewableImage vimage) );
EXTERN_FUNCTION (ViewableImage viewimg_get_active, (KWorldCanvas canvas) );
EXTERN_FUNCTION (flag viewimg_test_active, (ViewableImage vimage) );
EXTERN_FUNCTION (KCallbackFunc viewimg_register_position_event_func,
		 (KWorldCanvas canvas, flag (*func) (),
		  void *f_info) );
#ifndef KARMA_VIEWIMG_MAIN_C
#define viewimg_register_position_event_func(a, b, c) \
viewimg_register_position_event_func(a, ( flag (*) () ) b, c)
#endif
EXTERN_FUNCTION (KCallbackFunc viewimg_register_destroy_func,
		 (ViewableImage vimage, void (*func) (), void *info) );
EXTERN_FUNCTION (flag viewimg_fill_ellipse, (ViewableImage vimage,
					     double centre_x, double centre_y,
					     double radius_x, double radius_y,
					     double value[2]) );
EXTERN_FUNCTION (flag viewimg_fill_polygon, (ViewableImage vimage,
					     edit_coord *coords,
					     unsigned int num_vertices,
					     double value[2]) );
EXTERN_FUNCTION (void viewimg_get_canvas_attributes,
		 (KWorldCanvas canvas, ...) );
EXTERN_FUNCTION (void viewimg_set_canvas_attributes,
		 (KWorldCanvas canvas, ...) );
EXTERN_FUNCTION (void viewimg_get_attributes, (ViewableImage vimage, ...) );
EXTERN_FUNCTION (void viewimg_set_attributes, (ViewableImage vimage, ...) );
EXTERN_FUNCTION (void viewimg_set_array_attributes,
		 (ViewableImage *vimages, unsigned int len, ...) );
EXTERN_FUNCTION (flag viewimg_partial_refresh,
		 (KWorldCanvas canvas,
		  unsigned int num_areas, KPixCanvasRefreshArea *areas) );
EXTERN_FUNCTION (KWorldCanvas viewimg_get_worldcanvas, (ViewableImage vimage));
EXTERN_FUNCTION (void viewimg_zoom,
		 (ViewableImage vimage, double x, double y, flag relative,
		  double zoom) );

/*  File:  edit.c  */
EXTERN_FUNCTION (flag viewimg_draw_edit_list, (ViewableImage vimage,
					       KImageEditList ilist) );
EXTERN_FUNCTION (flag viewimg_draw_edit_object, (ViewableImage vimage,
						 char *object) );

/*  File: drag_n_zoom.c  */
EXTERN_FUNCTION(KPixCanvasEditorContext viewimg_create_drag_and_zoom_interface,
		(KWorldCanvas canvas) );

/*  File: header.c  */
EXTERN_FUNCTION (flag viewimg_header_position_func,
		 (ViewableImage vimage,double x, double y,
		  void *value, unsigned int event_code,
		  void *e_info, void **f_info, double x_lin, double y_lin,
		  unsigned int value_type) );

/*  File: statistics.c  */
EXTERN_FUNCTION (flag viewimg_statistics_position_func,
		 (ViewableImage vimage, double x, double y,
		  void *value, unsigned int event_code,
		  void *e_info, void **f_info, double x_lin, double y_lin,
		  unsigned int value_type,
		  double x_im, double y_im, int x_pix, int y_pix) );
EXTERN_FUNCTION (flag viewimg_statistics_geom_func,
		 (KPixCanvasEditorContext context, KPixCanvas canvas,
		  unsigned int object_type,
		  unsigned int num_coords, CONST int *x, CONST int *y,
		  unsigned int raw_event_code,
		  void *raw_e_info, void **f_info) );
EXTERN_FUNCTION (flag viewimg_statistics_compute,
		 (ViewableImage vimage,
		  double lx0, double ly0, double lx1, double ly1) );

/*  File: track.c  */
EXTERN_FUNCTION (void viewimg_track_compute,
		 (ViewableImage vimage, void *value, unsigned int value_type,
		  double x, double y, double x_im, double y_im,
		  char pix_string[STRING_LENGTH],
		  char world_string[STRING_LENGTH],
		  char extra_string[STRING_LENGTH]) );

/*  File: values.c  */
EXTERN_FUNCTION (flag viewimg_values_position_func,
		 (ViewableImage vimage, double x, double y,
		  void *value, unsigned int event_code,
		  void *e_info, void **f_info, double x_lin, double y_lin,
		  unsigned int value_type,
		  double x_im, double y_im, int x_pix, int y_pix) );
EXTERN_FUNCTION (flag viewimg_values_geom_func,
		 (KPixCanvasEditorContext context, KPixCanvas canvas,
		  unsigned int object_type,
		  unsigned int num_coords, CONST int *x, CONST int *y,
		  unsigned int raw_event_code,
		  void *raw_e_info, void **f_info) );
EXTERN_FUNCTION (flag viewimg_values_display,
		 (ViewableImage vimage, flag scaled, flag force,
		  double lx0, double ly0, double lx1, double ly1) );

/*  File: colourbar.c  */
EXTERN_FUNCTION (KWorldCanvas viewimg_colourbar_create,
		 (KWorldCanvas main_wc) );


#endif /*  KARMA_VIEWIMG_H  */
