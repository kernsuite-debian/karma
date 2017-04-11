/*  karma_kwin.h

    Header for  kwin_  package.

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
  needed to interface to the kwin_ routines in the Karma library.


    Written by      Richard Gooch   16-APR-1993

    Last updated by Richard Gooch   15-NOV-2005

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#if !defined(K_WIN_SCALE_H) || defined(MAKEDEPEND)
#  include <k_win_scale.h>
#endif

#if !defined(KARMA_DS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_ds_def.h>
#endif

#if !defined(KARMA_DS_VAL_H) || defined(MAKEDEPEND)
#  include <karma_ds_val.h>
#endif

#if !defined(KARMA_PSW_DEF_H) || defined(MAKEDEPEND)
#  include <karma_psw_def.h>
#endif

#if !defined(KARMA_KWIN_DEF_H) || defined(MAKEDEPEND)
#  include <karma_kwin_def.h>
#endif

#ifdef X11
#  include <X11/Xlib.h>
#  include <X11/Xutil.h>
#endif
#ifdef OS_VXMVX
#  include <karma_vc.h>
#endif

#if !defined(KARMA_C_DEF_H) || defined(MAKEDEPEND)
#  include <karma_c_def.h>
#endif

#ifndef KARMA_KWIN_H
#define KARMA_KWIN_H


#define KWIN_VISUAL_PSEUDOCOLOUR (unsigned int) 0
#define KWIN_VISUAL_DIRECTCOLOUR (unsigned int) 1
#define KWIN_VISUAL_TRUECOLOUR   (unsigned int) 2
#define KWIN_VISUAL_GRAYSCALE    (unsigned int) 3
#define KWIN_VISUAL_STATICCOLOUR (unsigned int) 4
#define KWIN_VISUAL_STATICGRAY   (unsigned int) 5

#define KWIN_ATT_END                          0
#define KWIN_ATT_VISUAL                       1
#define KWIN_ATT_DEPTH                        2
#define KWIN_ATT_VISIBLE                      3
#define KWIN_ATT_FONT                         4
#define KWIN_ATT_PIX_RED_MASK                 5
#define KWIN_ATT_PIX_GREEN_MASK               6
#define KWIN_ATT_PIX_BLUE_MASK                7
#define KWIN_ATT_IM_RED_MASK                  8
#define KWIN_ATT_IM_GREEN_MASK                9
#define KWIN_ATT_IM_BLUE_MASK                10
#define KWIN_ATT_IM_RED_OFFSET               11
#define KWIN_ATT_IM_GREEN_OFFSET             12
#define KWIN_ATT_IM_BLUE_OFFSET              13
#define KWIN_ATT_LOWER_HANDLE                14
#define KWIN_ATT_USER_PTR                    15
#define KWIN_ATT_LINEWIDTH                   16

/*  Experimental: subject to change without notice  */
#define KWIN_ATT_BACKGROUND_PIXEL           100
#define KWIN_ATT_LINE_DASH                  101
#define KWIN_ATT_MAGNIFY_FUNC               102
#define KWIN_ATT_RESOLUTION                 103
#define KWIN_ATT_SHOW_BINDINGS              104
#define KWIN_ATT_DOUBLE_BUFFER              105
#define KWIN_ATT_TIME_REFRESH               106
#define KWIN_ATT_AUTO_FLUSH_AFTER_REFRESH   107

#define KWIN_STRING_END                       0  /*  End of varargs list     */
#define KWIN_STRING_WIDTH                     1  /*  (int *)                 */
#define KWIN_STRING_HEIGHT                    2  /*  (int *)                 */
#define KWIN_STRING_ASCENT                    3  /*  (int *)                 */
#define KWIN_STRING_DESCENT                   4  /*  (int *)                 */

#define KWIN_XGL_NOT_AVAILABLE                0
#define KWIN_XGL_STEREO_NOT_AVAILABLE         1
#define KWIN_XGL_STEREO_AVAILABLE             2


#define KWIN_EDITOR_CONTEXT_ATT_END           0
#define KWIN_EDITOR_CONTEXT_ATT_MOUSE         1
#define KWIN_EDITOR_CONTEXT_ATT_EDIT_OBJECT   2
#define KWIN_EDITOR_CONTEXT_ATT_PIXEL_VALUE   3
#define KWIN_EDITOR_CONTEXT_ATT_CLEAR_OBJECT  4

#define KWIN_EDIT_OBJECT_NONE                 0
#define KWIN_EDIT_OBJECT_RECTANGLE            1
#define KWIN_EDIT_OBJECT_ELLIPSE              2
#define KWIN_EDIT_OBJECT_CIRCLE               3
#define KWIN_EDIT_OBJECT_ROTATED_CIRCLE       4
#define KWIN_EDIT_OBJECT_POLYGON              5


#define KWIN_PS_ORIENTATION_AUTOMATIC         0
#define KWIN_PS_ORIENTATION_PORTRAIT          1
#define KWIN_PS_ORIENTATION_LANDSCAPE         2
#define KWIN_PS_NUM_ORIENTATION_CHOICES       3
extern char *kwin_ps_orientation_choices[KWIN_PS_NUM_ORIENTATION_CHOICES];


/*  X specific routines  */
#ifdef X11
EXTERN_FUNCTION (KPixCanvas kwin_create_x, (Display *display, Window window,
					    GC gc,
					    int xoff, int yoff,
					    int width, int height) );
EXTERN_FUNCTION (void kwin_set_gc_x, (KPixCanvas canvas, GC gc) );
EXTERN_FUNCTION (Window kwin_x11_get_window, (KPixCanvas canvas) );
EXTERN_FUNCTION (Colormap kwin_x11_get_cmap, (KPixCanvas canvas) );
EXTERN_FUNCTION (void kwin_x11_get_vinfo,
		 (KPixCanvas canvas, XVisualInfo *vinfo) );
EXTERN_FUNCTION (GC kwin_get_gc_x, (KPixCanvas canvas) );

/*  XGL  */
EXTERN_FUNCTION (unsigned int kwin_xgl_test_stereo,
		 (Display *display, Window window) );
EXTERN_FUNCTION (flag kwin_xgl_create_stereo,
		 (Display *display, Window window,
		  int xoff, int yoff, int width, int height,
		  KPixCanvas *mono, KPixCanvas *left, KPixCanvas *right) );

/*  OpenGL  */
EXTERN_FUNCTION (flag kwin_open_gl_test_available, (Display *display) );
EXTERN_FUNCTION (flag kwin_open_gl_test_stereo,
		 (Display *display, XVisualInfo *visinfo) );
EXTERN_FUNCTION (flag kwin_open_gl_create_stereo,
		 (Display *display, Window window,
		  int xoff, int yoff, int width, int height,
		  KPixCanvas *left, KPixCanvas *right) );

#endif  /*  X11  */

/*  VX specific routines  */
#ifdef OS_VXMVX
EXTERN_FUNCTION (KPixCanvas kwin_create_vx,
		 (unsigned int visual, flag right_buf, int xoff, int yoff,
		  int width, int height, unsigned long background) );
#endif  /*  OS_VXMVX  */


/*  Generic routines  */
EXTERN_FUNCTION (KPixCanvas kwin_create_child,
		 (KPixCanvas parent, int xoff, int yoff, int width, int height,
		  flag absorb_events) );
EXTERN_FUNCTION (void kwin_destroy, (KPixCanvas canvas) );
EXTERN_FUNCTION (KCallbackFunc kwin_register_destroy_func,
		 (KPixCanvas canvas, void (*destroy_func) (), void *info) );
EXTERN_FUNCTION (KCallbackFunc kwin_register_precompute_func,
		 (KPixCanvas canvas, void (*refresh_func) (), void *info) );
EXTERN_FUNCTION (KCallbackFunc kwin_register_refresh_func,
		 (KPixCanvas canvas, void (*refresh_func) (), void *info) );
EXTERN_FUNCTION (KCallbackFunc kwin_register_position_event_func,
		 (KPixCanvas canvas, flag (*position_func) (), void *f_info) );
EXTERN_FUNCTION (void kwin_register_bindings,
		 (KPixCanvas canvas, KPixCanvasBinding *bindings, flag copy) );
EXTERN_FUNCTION (flag kwin_resize, (KPixCanvas canvas, flag clear,
				    int xoff, int yoff,
				    int width, int height) );
EXTERN_FUNCTION (flag kwin_refresh_if_visible,
		 (KPixCanvas canvas, flag clear) );
EXTERN_FUNCTION (flag kwin_partial_refresh,
		 (KPixCanvas canvas, unsigned int num_areas,
		  KPixCanvasRefreshArea *areas, flag clear_all) );
EXTERN_FUNCTION (flag kwin_process_position_event, (KPixCanvas canvas,
						    int x, int y, flag clip,
						    unsigned int event_code,
						    void *event_info) );
EXTERN_FUNCTION (void kwin_get_attributes, (KPixCanvas canvas, ...) );
EXTERN_FUNCTION (void kwin_set_attributes, (KPixCanvas canvas, ...) );
EXTERN_FUNCTION (void kwin_associate_object,
		 (KPixCanvas canvas, CONST void *key,
		  CONST void *object, flag replace) );
EXTERN_FUNCTION (void *kwin_get_associated_object,
		 (KPixCanvas canvas, CONST void *key) );


/*  Drawing routines  */
EXTERN_FUNCTION (flag kwin_clear,
		 (KPixCanvas canvas, int x, int y, int width, int height) );
EXTERN_FUNCTION (flag kwin_draw_image, (KPixCanvas canvas,
					array_desc *arr_desc, char *slice,
					unsigned int hdim, unsigned int vdim,
					unsigned int elem_index,
					unsigned int num_pixels,
					unsigned long *pixel_values,
					struct win_scale_type *win_scale,
					KPixCanvasImageCache *cache_ptr) );
EXTERN_FUNCTION (flag kwin_draw_pc_image,
		 (KPixCanvas canvas, int x_off, int y_off,
		  int x_pixels, int y_pixels,
		  CONST char *slice,
		  CONST uaddr *hoffsets, CONST uaddr *voffsets,
		  unsigned int width, unsigned int height,
		  unsigned int type, unsigned int conv_type,
		  unsigned int num_pixels, unsigned long *pixel_values,
		  unsigned long blank_pixel,unsigned long min_sat_pixel,
		  unsigned long max_sat_pixel,
		  double i_min, double i_max,
		  flag (*iscale_func) (), void *iscale_info,
		  KPixCanvasImageCache *cache_ptr) );
EXTERN_FUNCTION (flag kwin_compute_pc_subimage,
		 (KPixCanvas canvas,
		  int x_off, int y_off, int x_pixels, int y_pixels,
		  int cache_width, int cache_height,
		  CONST char *slice,
		  CONST uaddr *hoffsets, CONST uaddr *voffsets,
		  unsigned int image_width, unsigned int image_height,
		  unsigned int type, unsigned int conv_type,
		  unsigned int num_pixels, unsigned long *pixel_values,
		  unsigned long blank_pixel,
		  unsigned long min_sat_pixel, unsigned long max_sat_pixel,
		  double i_min, double i_max,
		  flag (*iscale_func) (), void *iscale_info,
		  KPixCanvasImageCache *cache) );
EXTERN_FUNCTION (flag kwin_draw_rgb_image,
		 (KPixCanvas canvas, int x_off, int y_off,
		  int x_pixels, int y_pixels,
		  CONST unsigned char *red_slice,
		  CONST unsigned char *green_slice,
		  CONST unsigned char *blue_slice,
		  CONST uaddr *hoffsets, CONST uaddr *voffset,
		  unsigned int width, unsigned int height,
		  KPixCanvasImageCache *cache_ptr) );
EXTERN_FUNCTION (flag kwin_compute_rgb_subimage,
		 (KPixCanvas canvas,
		  int x_off, int y_off, int x_pixels, int y_pixels,
		  int cache_width, int cache_height,
		  CONST unsigned char *red_slice,
		  CONST unsigned char *green_slice,
		  CONST unsigned char *blue_slice,
		  CONST uaddr *hoffsets, CONST uaddr *voffsets,
		  unsigned int image_width, unsigned int image_height,
		  KPixCanvasImageCache *cache) );
EXTERN_FUNCTION (flag kwin_draw_cached_image, (KPixCanvasImageCache cache,
					       int x_off, int y_off) );
EXTERN_FUNCTION (flag kwin_draw_cached_subimages,
		 (KPixCanvasImageCache cache, int x_off, int y_off,
		  unsigned int num_areas, KPixCanvasRefreshArea *areas) );
EXTERN_FUNCTION (flag kwin_draw_point, (KPixCanvas canvas,
					double x, double y,
					unsigned long pixel_value) );
EXTERN_FUNCTION (flag kwin_draw_points,
		 (KPixCanvas canvas, double *x_array, double *y_array,
		  unsigned int num_points, unsigned long pixel_value) );
EXTERN_FUNCTION (flag kwin_draw_line,
		 (KPixCanvas canvas,
		  double x0, double y0, double x1, double y1,
		  unsigned long pixel_value) );
EXTERN_FUNCTION (flag kwin_draw_lines,
		 (KPixCanvas canvas, int *x_array, int *y_array,
		  int num_points, unsigned long pixel_value) );
EXTERN_FUNCTION (flag kwin_draw_lines_TRANSITION,
		 (KPixCanvas canvas,
		  CONST double *x_array, CONST double *y_array,
		  int num_points, unsigned long pixel_value) );
EXTERN_FUNCTION (flag kwin_fill_ellipse,
		 (KPixCanvas canvas,double cx, double cy, double rx, double ry,
		  unsigned long pixel_value) );
EXTERN_FUNCTION (flag kwin_fill_polygon, (KPixCanvas canvas,
					  int *point_x, int *point_y,
					  unsigned int num_vertices,
					  unsigned long pixel_value,
					  flag convex) );
EXTERN_FUNCTION (flag kwin_fill_polygon_TRANSITION,
		 (KPixCanvas canvas, double *point_x, double *point_y,
		  unsigned int num_vertices, unsigned long pixel_value,
		  flag convex) );
EXTERN_FUNCTION (flag kwin_draw_string, (KPixCanvas canvas, double x, double y,
					 CONST char *string,
					 unsigned long pixel_value,
					 flag clear_under) );
EXTERN_FUNCTION (flag kwin_draw_rectangle,
		 (KPixCanvas canvas,
		  double x, double y, double width, double height,
		  unsigned long pixel_value) );
EXTERN_FUNCTION (flag kwin_fill_rectangle,
		 (KPixCanvas canvas,
		  double x, double y, double width, double height,
		  unsigned long pixel_value) );
EXTERN_FUNCTION (flag kwin_draw_arc,
		 (KPixCanvas canvas, double cx, double cy,
		  double rx, double ry, double angle1, double angle2,
		  double rotation, unsigned long pixel_value, flag fill) );
EXTERN_FUNCTION (flag kwin_draw_ellipse,
		 (KPixCanvas canvas,double cx, double cy, double rx, double ry,
		  unsigned long pixel_value) );
EXTERN_FUNCTION (flag kwin_draw_ellipses, (KPixCanvas canvas, int *cx, int *cy,
					   int *rx, int *ry, int num_ellipses,
					   unsigned long pixel_value) );
EXTERN_FUNCTION (flag kwin_draw_ellipses_TRANSITION,
		 (KPixCanvas canvas, double *cx, double *cy,
		  double *rx, double *ry, int num_ellipses,
		  unsigned long pixel_value) );
EXTERN_FUNCTION (flag kwin_fill_ellipses, (KPixCanvas canvas, int *cx, int *cy,
					   int *rx, int *ry, int num_ellipses,
					   unsigned long pixel_value) );
EXTERN_FUNCTION (flag kwin_fill_ellipses_TRANSITION,
		 (KPixCanvas canvas, double *cx, double *cy,
		  double *rx, double *ry, int num_ellipses,
		  unsigned long pixel_value) );
EXTERN_FUNCTION (flag kwin_draw_segments, (KPixCanvas canvas,
					   int *x0, int *y0, int *x1, int *y1,
					   int num_segments,
					   unsigned long pixel_value) );
EXTERN_FUNCTION (flag kwin_draw_segments_TRANSITION,
		 (KPixCanvas canvas, double *x0, double *y0,
		  double *x1, double *y1,
		  int num_segments, unsigned long pixel_value) );


/*  Other routines  */
EXTERN_FUNCTION (void kwin_get_size, (KPixCanvas canvas, int *width,
				      int *height) );
EXTERN_FUNCTION (void kwin_free_cache_data, (KPixCanvasImageCache cache) );
EXTERN_FUNCTION (void kwin_set_clip_areas,
		 (KPixCanvas canvas,
		  unsigned int num_areas, KPixCanvasRefreshArea *areas) );
EXTERN_FUNCTION (flag kwin_convert_to_canvas_coord, (KPixCanvas canvas,
						     int xin, int yin,
						     int *xout, int *yout) );
EXTERN_FUNCTION (flag kwin_convert_from_canvas_coord, (KPixCanvas canvas,
						       int xin, int yin,
						       int *xout, int *yout) );
EXTERN_FUNCTION (flag kwin_get_colour,
		 (KPixCanvas canvas, CONST char *colourname,
		  unsigned long *pixel_value, unsigned short *red,
		  unsigned short *green, unsigned short *blue) );
EXTERN_FUNCTION (flag kwin_get_pixel_RGB_values,
		 (KPixCanvas canvas, unsigned long *pixels,
		  unsigned short *reds, unsigned short *greens,
		  unsigned short *blues, unsigned int num_colours) );
EXTERN_FUNCTION (KPixCanvasFont kwin_load_font,
		 (KPixCanvas canvas, CONST char *fontname) );
EXTERN_FUNCTION (flag kwin_get_string_size,
		 (KPixCanvasFont font, CONST char *string, ...) );
EXTERN_FUNCTION (flag kwin_warp_pointer,
		 (KPixCanvas canvas, int x, int y, flag relative,
		  flag discard) );

/*  File: hershey.c  */
EXTERN_FUNCTION (KPixCanvasHersheyString kwin_hershey_get_string,
		 (CONST char *string, double angle, double size,
		  double *width, double *height, double *ascent,
		  double *descent) );
EXTERN_FUNCTION (void kwin_hershey_draw_string,
		 (KPixCanvas canvas, KPixCanvasHersheyString string,
		  double x, double y, double size,unsigned long pixel_value) );


/*  File: editor.c  */
EXTERN_FUNCTION (KPixCanvasEditorContext kwin_editor_create_context,
		 (KPixCanvas canvas, ...) );
EXTERN_FUNCTION (void kwin_editor_destroy_context,
		 (KPixCanvasEditorContext context) );
EXTERN_FUNCTION (KCallbackFunc kwin_editor_register_event_func,
		 (KPixCanvasEditorContext context,
		  flag (*func) (), void *f_info) );
EXTERN_FUNCTION (KCallbackFunc kwin_editor_register_destroy_func,
		 (KPixCanvasEditorContext ctx, void (*func) (), void *info) );
EXTERN_FUNCTION (void kwin_editor_set_attributes,
		 (KPixCanvasEditorContext context, ...) );
EXTERN_FUNCTION (void kwin_editor_get_attributes,
		 (KPixCanvasEditorContext context, ...) );
EXTERN_FUNCTION (KPixCanvas kwin_editor_get_pixcanvas,
		 (KPixCanvasEditorContext context) );


/*  File: memory.c  */
EXTERN_FUNCTION (flag kwin_mem_write_rgb,
		 (KPixCanvas canvas, void *red, void *green, void *blue,
		  uaddr stride, unsigned int width, unsigned int height) );


/*  File: misc.c  */
EXTERN_FUNCTION (flag kwin_get_colour_harder,
		 (KPixCanvas canvas, CONST char *colourname,
		  unsigned long *pixel_value) );


/*  File: ps.c  */
EXTERN_FUNCTION (flag kwin_write_ps, (KPixCanvas canvas,
				      PostScriptPage pspage) );
EXTERN_FUNCTION (void kwin_ps_generate,
		 (KPixCanvas canvas, CONST char *destination, flag queue,
		  double hoffset, double voffset,
		  double hsize, double vsize, unsigned int orientation,
		  flag eps, double thin_linewidth, unsigned int tray,
		  flag preserve_aspect, CONST char *media_size) );


/*  File: queue_event.c  */
EXTERN_FUNCTION (flag kwin_queue_position_event,
		 (KPixCanvas canvas, int x, int y, flag clip,
		  unsigned int event_code, void *event_info) );


#endif /*  KARMA_KWIN_H  */
