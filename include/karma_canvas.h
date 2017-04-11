/*  karma_canvas.h

    Header for  canvas_  package.

    Copyright (C) 1993-2006  Richard Gooch

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
  needed to interface to the canvas_ routines in the Karma library.


    Written by      Richard Gooch   17-APR-1993

    Last updated by Richard Gooch   6-AUG-2006

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#if !defined(K_WIN_SCALE_H) || defined(MAKEDEPEND)
#  include <k_win_scale.h>
#endif

#if !defined(KARMA_CANVAS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_canvas_def.h>
#endif

#if !defined(KARMA_IEDIT_H) || defined(MAKEDEPEND)
#  include <karma_iedit.h>
#endif

#if !defined(KARMA_KCMAP_DEF_H) || defined(MAKEDEPEND)
#  include <karma_kcmap_def.h>
#endif

#if !defined(KARMA_KWIN_DEF_H) || defined(MAKEDEPEND)
#  include <karma_kwin_def.h>
#endif

#if !defined(KARMA_WCS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_wcs_def.h>
#endif

#if !defined(KARMA_C_DEF_H) || defined(MAKEDEPEND)
#  include <karma_c_def.h>
#endif

#ifndef KARMA_CANVAS_H
#define KARMA_CANVAS_H


/*  Canvas attributes  */
#define CANVAS_ATT_END                0   /*  End of varargs list            */
#define CANVAS_ATT_X_OFFSET           1   /*  (int)                          */
#define CANVAS_ATT_Y_OFFSET           2   /*  (int)                          */
#define CANVAS_ATT_X_PIXELS           3   /*  (int)                          */
#define CANVAS_ATT_Y_PIXELS           4   /*  (int)                          */
#define CANVAS_ATT_BLANK_PIXEL        5   /*  (unsigned long)                */
#define CANVAS_ATT_MIN_SAT_PIXEL      6   /*  (unsigned long)                */
#define CANVAS_ATT_MAX_SAT_PIXEL      7   /*  (unsigned long)                */
#define CANVAS_ATT_LEFT_X             8   /*  (double)                       */
#define CANVAS_ATT_RIGHT_X            9   /*  (double)                       */
#define CANVAS_ATT_BOTTOM_Y           10  /*  (double)                       */
#define CANVAS_ATT_TOP_Y              11  /*  (double)                       */
#define CANVAS_ATT_VALUE_MIN          12  /*  (double)                       */
#define CANVAS_ATT_VALUE_MAX          13  /*  (double)                       */
#define CANVAS_ATT_ISCALE_FUNC        14  /*  ( flag (*) () )                */
#define CANVAS_ATT_ISCALE_FREE_FUNC   15  /*  ( (void (*) () )               */
#define CANVAS_ATT_ISCALE_INFO        16  /*  (void *)                       */
#define CANVAS_ATT_AUTO_MIN_SAT       17  /*  (flag)                         */
#define CANVAS_ATT_AUTO_MAX_SAT       18  /*  (flag)                         */

#define CANVAS_ATT_AUTO_BLANK        100 /*  Experimental                    */
#define CANVAS_ATT_WCS_ASTRO         101 /*  Experimental                    */
#define CANVAS_ATT_SPHERICAL_FORMAT  102 /*  Experimental                    */
#define CANVAS_ATT_NEW_CMAP          103 /*  Experimental                    */

#ifndef NEW_WIN_SCALE
#  define CANVAS_ATT_X_MIN            CANVAS_ATT_LEFT_X
#  define CANVAS_ATT_X_MAX            CANVAS_ATT_RIGHT_X
#  define CANVAS_ATT_Y_MIN            CANVAS_ATT_BOTTOM_Y
#  define CANVAS_ATT_Y_MAX            CANVAS_ATT_TOP_Y
#endif

/*  Dressing parameters (experimental: subject to change without notice)  */
#define KCD_ATT_END             0
#define KCD_ATT_DISPLAY         1            /*  (flag)            */
#define KCD_ATT_TOP_TICKS       2            /*  (flag)            */
#define KCD_ATT_BOTTOM_TICKS    3            /*  (flag)            */
#define KCD_ATT_LEFT_TICKS      4            /*  (flag)            */
#define KCD_ATT_RIGHT_TICKS     5            /*  (flag)            */
#define KCD_ATT_INTERNAL_TICKS  6            /*  (flag)            */
#define KCD_ATT_GRID_COLOUR     7            /*  (char *)          */
#define KCD_ATT_SCALE_COLOUR    8            /*  (char *)          */
#define KCD_ATT_HLABEL          9            /*  (char *)          */
#define KCD_ATT_VLABEL          10           /*  (char *)          */
#define KCD_ATT_LABEL_COLOUR    11           /*  (char *)          */
#define KCD_ATT_TITLE           12           /*  (char *)          */
#define KCD_ATT_TITLE_COLOUR    13           /*  (char *)          */
#define KCD_ATT_SHOW_LABELS     14           /*  (flag)            */
#define KCD_ATT_SHOW_SCALE      15           /*  (flag)            */
#define KCD_ATT_GRID            16           /*  (flag)            */
#define KCD_ATT_FONT_SCALE      17           /*  (double)          */
#define KCD_ATT_RIGHT_SCALE     18           /*  (flag)            */
#define KCD_ATT_MAJOR_PIXELS    19           /*  (unsigned int)    */
#define KCD_ATT_MINOR_PIXELS    20           /*  (unsigned int)    */

/*  Backwards-compatible  */
#define KCD_END     KCD_ATT_END
#define KCD_DISPLAY KCD_ATT_DISPLAY


/*  File:  canvas.c  */
EXTERN_FUNCTION (KWorldCanvas canvas_create,
		 (KPixCanvas pixcanvas, Kcolourmap cmap,
		  struct win_scale_type *win_scale) );
EXTERN_FUNCTION (void canvas_destroy, (KWorldCanvas canvas) );
EXTERN_FUNCTION (KCallbackFunc canvas_register_precompute_func,
		 (KWorldCanvas canvas, void (*refresh_func) (), void *info) );
EXTERN_FUNCTION (KCallbackFunc canvas_register_refresh_func,
		 (KWorldCanvas canvas, void (*refresh_func) (), void *info) );
EXTERN_FUNCTION (void canvas_register_size_control_func,
		 (KWorldCanvas canvas, void (*size_control_func) (),
		  void *info) );
EXTERN_FUNCTION (KCallbackFunc canvas_register_legend_reservation_func,
		 (KWorldCanvas canvas, void (*func) (), void *info) );
EXTERN_FUNCTION (KCallbackFunc canvas_register_position_event_func,
		 (KWorldCanvas canvas, flag (*position_func) (),
		  void *f_info) );
EXTERN_FUNCTION (KCallbackFunc canvas_register_destroy_func,
		 (KWorldCanvas canvas, flag wc_only,
		  void (*func) (), void *info) );
EXTERN_FUNCTION (void canvas_get_attributes, (KWorldCanvas canvas, ...) );
EXTERN_FUNCTION (void canvas_get_size, (KWorldCanvas canvas,
					int *width, int *height,
					struct win_scale_type *win_scale) );
EXTERN_FUNCTION (flag canvas_set_attributes, (KWorldCanvas canvas, ...) );
EXTERN_FUNCTION (flag canvas_resize, (KWorldCanvas canvas,
				      struct win_scale_type *win_scale,
				      flag always_clear) );
EXTERN_FUNCTION (flag canvas_refresh_if_visible,
		 (KWorldCanvas canvas, flag always_clear) );
EXTERN_FUNCTION (flag canvas_specify,
		 (KWorldCanvas canvas, CONST char *xlabel, CONST char *ylabel,
		  unsigned int num_restr, CONST char **restr_names,
		  CONST double *restr_values) );
EXTERN_FUNCTION (void canvas_get_specification,
		 (KWorldCanvas canvas, char **xlabel, char **ylabel,
		  unsigned int *num_restr, char ***restr_names,
		  double **restr_values) );
EXTERN_FUNCTION (void canvas_convert_to_canvas_coords,
		 (KWorldCanvas canvas, flag clip, unsigned int num_coords,
		  CONST double *xin, CONST double *yin,
		  double *xout_lin, double *yout_lin,
		  double *xout, double *yout) );
EXTERN_FUNCTION (flag canvas_convert_to_canvas_coord,
		 (KWorldCanvas canvas, double xin, double yin,
		  double *xout, double *yout) );
EXTERN_FUNCTION (void canvas_convert_from_canvas_coords,
		 (KWorldCanvas canvas, flag clip, flag linear,
		  unsigned int num_coords,
		  CONST double *xin, CONST double *yin,
		  double *xout, double *yout) );
EXTERN_FUNCTION (flag canvas_convert_from_canvas_coord,
		 (KWorldCanvas canvas, double xin, double yin,
		  int *xout, int *yout) );
EXTERN_FUNCTION (void canvas_register_coords_convert_func,
		 (KWorldCanvas canvas, flag (*coord_convert_func) (),
		  void *info) );
EXTERN_FUNCTION (void canvas_register_d_convert_func,
		 (KWorldCanvas canvas, flag (*coord_convert_func) (),
		  void *info) );
EXTERN_FUNCTION (void canvas_register_convert_func,
		 (KWorldCanvas canvas, flag (*coord_convert_func) (),
		  void *info) );
EXTERN_FUNCTION (void canvas_coords_transform,
		 (KWorldCanvas canvas, unsigned int num_coords,
		  double *x, flag x_to_linear, double *y, flag y_to_linear) );
EXTERN_FUNCTION (flag canvas_coord_transform,
		 (KWorldCanvas canvas, double *x, double *y, flag to_linear) );
EXTERN_FUNCTION (void canvas_register_transforms_func,
		 (KWorldCanvas canvas, void (*coord_transform_func) (),
		  void *info) );
EXTERN_FUNCTION (void canvas_register_transforms_free_func,
		 ( KWorldCanvas canvas, void (*func) () ) );
EXTERN_FUNCTION (void canvas_register_transform_func,
		 (KWorldCanvas canvas, void (*coord_transform_func) (),
		  void *info) );
EXTERN_FUNCTION (KPixCanvas canvas_get_pixcanvas, (KWorldCanvas canvas) );
EXTERN_FUNCTION (flag canvas_get_colour,
		 (KWorldCanvas canvas, CONST char *colourname,
		  unsigned long *pixel_value, unsigned short *red,
		  unsigned short *green, unsigned short *blue) );
EXTERN_FUNCTION (flag canvas_set_dressing, (KWorldCanvas canvas, ...) );
EXTERN_FUNCTION (void canvas_get_dressing, (KWorldCanvas canvas, ...) );
EXTERN_FUNCTION (void canvas_sequence_dressing_refresh, (KWorldCanvas canvas));
EXTERN_FUNCTION (void canvas_draw_dressing, (KWorldCanvas canvas) );
EXTERN_FUNCTION (Kcolourmap canvas_get_cmap, (KWorldCanvas canvas) );
EXTERN_FUNCTION (flag canvas_warp_pointer,
		 (KWorldCanvas canvas, double x, double y, flag linear,
		  flag discard) );
EXTERN_FUNCTION (flag canvas_test_for_boundary,
		 (KWorldCanvas canvas, unsigned int num_coords,
		  CONST double *x, CONST double *y) );
EXTERN_FUNCTION (void canvas_get_margins,
		 (KWorldCanvas canvas, int *left_margin, int *right_margin,
		  int *bottom_margin, int *top_margin) );
EXTERN_FUNCTION (void canvas_associate_object,
		 (KWorldCanvas canvas, CONST void *key,
		  CONST void *object, flag replace) );
EXTERN_FUNCTION (void *canvas_get_associated_object,
		 (KWorldCanvas canvas, CONST void *key) );


/*  Drawing routines  */
EXTERN_FUNCTION (flag canvas_draw_image, (KWorldCanvas canvas,
					  array_desc *arr_desc, char *slice,
					  unsigned int hdim, unsigned int vdim,
					  unsigned int elem_index,
					  KPixCanvasImageCache *cache_ptr) );
EXTERN_FUNCTION (flag canvas_compute_pc_image,
		 (KWorldCanvas canvas, array_desc *arr_desc,
		  char *slice, unsigned int hdim, unsigned int vdim,
		  unsigned int elem_index, KPixCanvasImageCache *cache) );
EXTERN_FUNCTION (flag canvas_draw_rgb_image,
		 (KWorldCanvas canvas, array_desc *arr_desc, CONST char *slice,
		  unsigned int hdim, unsigned int vdim,
		  unsigned int red_index, unsigned int green_index,
		  unsigned int blue_index, KPixCanvasImageCache *cache_ptr) );
EXTERN_FUNCTION (flag canvas_compute_rgb_image,
		 (KWorldCanvas canvas, array_desc *arr_desc,
		  CONST char *slice, unsigned int hdim, unsigned int vdim,
		  unsigned int red_index, unsigned int green_index,
		  unsigned int blue_index, KPixCanvasImageCache *cache) );
EXTERN_FUNCTION (void canvas_draw_point, (KWorldCanvas canvas,
					  double x, double y,
					  double value[2]) );
EXTERN_FUNCTION (void canvas_draw_point_p, (KWorldCanvas canvas,
					    double x, double y,
					    unsigned long pixel_value) );
EXTERN_FUNCTION (void canvas_draw_line, (KWorldCanvas canvas,
					  double x0, double y0,
					  double x1, double y1,
					  double value[2]) );
EXTERN_FUNCTION (void canvas_draw_line_p, (KWorldCanvas canvas,
					   double x0, double y0,
					   double x1, double y1,
					   unsigned long pixel_value) );
EXTERN_FUNCTION (flag canvas_draw_arc,
		 (KWorldCanvas canvas, double centre_x, double centre_y,
		  double radius_x, double radius_y,
		  double angle1, double angle2, double rotation,
		  double value[2], flag fill) );
EXTERN_FUNCTION (flag canvas_draw_arc_p,
		 (KWorldCanvas canvas, double centre_x, double centre_y,
		  double radius_x, double radius_y,
		  double angle1, double angle2, double rotation,
		  unsigned long pixel_value, flag fill) );
EXTERN_FUNCTION (void canvas_draw_ellipse, (KWorldCanvas canvas,
					    double centre_x, double centre_y,
					    double radius_x, double radius_y,
					    double value[2]) );
EXTERN_FUNCTION (void canvas_draw_ellipse_p, (KWorldCanvas canvas,
					      double centre_x, double centre_y,
					      double radius_x, double radius_y,
					      unsigned long pixel_value) );
EXTERN_FUNCTION (void canvas_fill_ellipse, (KWorldCanvas canvas,
					    double centre_x, double centre_y,
					    double radius_x, double radius_y,
					    double value[2]) );
EXTERN_FUNCTION (void canvas_fill_ellipse_p, (KWorldCanvas canvas,
					      double centre_x, double centre_y,
					      double radius_x, double radius_y,
					      unsigned long pixel_value) );
EXTERN_FUNCTION (void canvas_convert_ellipse_coords,
		 (KWorldCanvas canvas, flag to_world, flag linear,
		  double *centre_x, double *centre_y,
		  double *radius_x, double *radius_y, double *rotation) );
EXTERN_FUNCTION (flag canvas_fill_polygon, (KWorldCanvas canvas,
					    edit_coord *coords,
					    unsigned int num_vertices,
					    double value[2], flag convex) );
EXTERN_FUNCTION (void canvas_draw_rectangle, (KWorldCanvas canvas,
					      double x, double y,
					      double width, double height,
					      double value[2]) );
EXTERN_FUNCTION (void canvas_draw_rectangle_p, (KWorldCanvas canvas,
						double x, double y,
						double width, double height,
						unsigned long pixel_value) );
EXTERN_FUNCTION (void canvas_fill_rectangle, (KWorldCanvas canvas,
					      double x, double y,
					      double width, double height,
					      double value[2]) );
EXTERN_FUNCTION (void canvas_fill_rectangle_p, (KWorldCanvas canvas,
						double x, double y,
						double width, double height,
						unsigned long pixel_value) );
EXTERN_FUNCTION (void canvas_draw_lines,
		 (KWorldCanvas canvas,
		  CONST double *x_array, CONST double *y_array,
		  int num_points, double value[2]) );
EXTERN_FUNCTION (void canvas_draw_lines_p,
		 (KWorldCanvas canvas,
		  CONST double *x_array, CONST double *y_array,
		  int num_points, unsigned long pixel_value) );
EXTERN_FUNCTION (void canvas_draw_segments,
		 (KWorldCanvas canvas, CONST double *x0, CONST double *y0,
		  CONST double *x1, CONST double *y1,
		  int num_segments, double value[2]) );
EXTERN_FUNCTION (void canvas_draw_segments_p,
		 (KWorldCanvas canvas, CONST double *x0, CONST double *y0,
		  CONST double *x1, CONST double *y1,
		  int num_segments, unsigned long pixel_value) );


/*  Image editing related functions  */
/*  File:  canvas_edit.c  */
EXTERN_FUNCTION (flag canvas_draw_edit_list, (KWorldCanvas canvas,
					      KImageEditList ilist) );
EXTERN_FUNCTION (flag canvas_draw_edit_object, (KWorldCanvas canvas,
						char *object) );


/*  File:  cnv_stroke.c  */
EXTERN_FUNCTION (flag canvas_create_stroke_instruction,
		 (KWorldCanvas canvas, double x0, double y0,
		  double x1, double y1, unsigned int brush_width,
		  double value[2], KImageEditList ilist) );


/*  File:  canvas_misc.c  */
EXTERN_FUNCTION (void canvas_init_win_scale,
		 (struct win_scale_type *win_scale,
		  unsigned int magic_number) );
EXTERN_FUNCTION (void canvas_use_log_scale,
		 (KWorldCanvas canvas, flag x_log, flag y_log) );
EXTERN_FUNCTION (void canvas_use_astro_transform,
		 (KWorldCanvas canvas, KwcsAstro ap) );
EXTERN_FUNCTION (void canvas_track_compute,
		 (KWorldCanvas canvas,
		  double x, double y, double x_lin, double y_lin,
		  char world_string[STRING_LENGTH],
		  char extra_string[STRING_LENGTH]) );
EXTERN_FUNCTION (void canvas_draw_circle_marker,
		 (KWorldCanvas canvas, KPixCanvasRefreshArea *area,
		  double x, double y) );
EXTERN_FUNCTION (void canvas_draw_line_marker,
		 (KWorldCanvas canvas, KPixCanvasRefreshArea *area,
		  double lpos, flag pos_is_vertical) );


/*  File:  canvas_zoom.c  */
EXTERN_FUNCTION (KCallbackFunc canvas_zoom_handle_keys,
		 (KWorldCanvas canvas, CONST KWorldCanvasLimits *limits) );
EXTERN_FUNCTION (KPixCanvasEditorContext canvas_zoom_handle_mouse,
		 (KWorldCanvas canvas, CONST KWorldCanvasLimits *limits) );
EXTERN_FUNCTION (flag canvas_zoom,
		 (KWorldCanvas canvas,CONST KWorldCanvasLimits *limits,
		  char action, double x, double y) );


#endif /*  KARMA_CANVAS_H  */
