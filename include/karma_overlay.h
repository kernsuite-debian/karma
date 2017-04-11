/*  karma_overlay.h

    Header for  overlay_  package.

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
  needed to interface to the overlay_ routines in the Karma library.


    Written by      Richard Gooch   2-DEC-1993

    Last updated by Richard Gooch   16-JUL-2005

*/

#if !defined(KARMA_OVERLAY_DEF_H) || defined(MAKEDEPEND)
#  include <karma_overlay_def.h>
#endif

#if !defined(KARMA_CANVAS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_canvas_def.h>
#endif

#if !defined(KARMA_IARRAY_DEF_H) || defined(MAKEDEPEND)
#  include <karma_iarray_def.h>
#endif

#if !defined(KARMA_KWIN_DEF_H) || defined(MAKEDEPEND)
#  include <karma_kwin_def.h>
#endif

#ifndef KARMA_OVERLAY_H
#define KARMA_OVERLAY_H


#define OVERLAY_CANVAS_ATT_END                       0
#define OVERLAY_CANVAS_ATT_CROP                      1


#define OVERLAY_ATT_END                              0


#define OVERLAY_COORD_PIXEL                          0
#define OVERLAY_COORD_RELATIVE                       1
#define OVERLAY_COORD_WORLD                          2
#define OVERLAY_COORD_LAST                           3
#define OVERLAY_COORD_LINEAR                         4


#define OVERLAY_EDITOR_CONTEXT_ATT_END               0
#define OVERLAY_EDITOR_CONTEXT_ATT_EDIT_MODE         1
#define OVERLAY_EDITOR_CONTEXT_ATT_FIRST_COORD_TYPE  2
#define OVERLAY_EDITOR_CONTEXT_ATT_OTHER_COORD_TYPE  3
#define OVERLAY_EDITOR_CONTEXT_ATT_COLOUR            4


/*  File:  main.c  */
EXTERN_FUNCTION (KOverlayList overlay_va_create_list,
		 (void *info, CONST char *name, ...) );
EXTERN_FUNCTION (void overlay_destroy_list, (KOverlayList olist) );
EXTERN_FUNCTION (void overlay_prepare_for_slavery, (KOverlayList olist) );
EXTERN_FUNCTION (void overlay_specify_iarray_2d, (KOverlayList olist,
						  iarray array) );
EXTERN_FUNCTION (void overlay_specify_canvas, (KOverlayList olist,
					       KWorldCanvas canvas) );
EXTERN_FUNCTION (KViewableOverlayList overlay_create_viewable,
		 (KOverlayList olist, KWorldCanvas canvas) );
EXTERN_FUNCTION (flag overlay_set_active,
		 (KViewableOverlayList vlist, flag active,
		  flag force_refresh, flag refresh_if_changed,
		  flag exclusive, uaddr key) );
EXTERN_FUNCTION (flag overlay_set_all_inactive,
		 (KWorldCanvas canvas, flag force_refresh,
		  flag refresh_if_changed, uaddr key) );
EXTERN_FUNCTION (void overlay_destroy_viewable, (KViewableOverlayList vlist) );
EXTERN_FUNCTION (flag overlay_redraw_on_canvas,
		 (KOverlayList olist, KWorldCanvas canvas) );
EXTERN_FUNCTION (void overlay_set_canvas_attributes,
		 (KWorldCanvas canvas, ...) );

/*  Drawing functions  */
EXTERN_FUNCTION (unsigned int overlay_line,
		 (KOverlayList olist, unsigned int type0, double x0, double y0,
		  unsigned int type1, double x1, double y1,
		  CONST char *colourname) );
EXTERN_FUNCTION (unsigned int overlay_lines,
		 (KOverlayList olist, unsigned int num_coords,
		  unsigned int *types, double *x_arr, double *y_arr,
		  CONST char *colourname) );
EXTERN_FUNCTION (unsigned int overlay_text,
		 (KOverlayList olist, char *string,
		  unsigned int type, double x, double y,
		  CONST char *colourname, char *fontname, flag clear_under) );
EXTERN_FUNCTION (unsigned int overlay_ellipse,
		 (KOverlayList olist, unsigned int ctype, double cx, double cy,
		  unsigned int rtype, double rx, double ry,
		  CONST char *colourname, flag filled) );
EXTERN_FUNCTION (unsigned int overlay_arc,
		 (KOverlayList olist, unsigned int ctype, double cx, double cy,
		  unsigned int rtype, double rx, double ry,
		  double rotation, CONST char *colourname, flag filled) );
EXTERN_FUNCTION (unsigned int overlay_filled_polygon,
		 (KOverlayList olist, unsigned int num_coords,
		  unsigned int *types, double *x_arr, double *y_arr,
		  CONST char *colourname) );
EXTERN_FUNCTION (unsigned int overlay_vector,
		 (KOverlayList olist, unsigned int stype, double sx, double sy,
		  unsigned int dtype, double dx, double dy,
		  CONST char *colourname) );
EXTERN_FUNCTION (unsigned int overlay_ellipses,
		 (KOverlayList olist, unsigned int num_ellipses,
		  unsigned int *ctypes, double *cx, double *cy,
		  unsigned int *rtypes, double *rx, double *ry,
		  CONST char *colourname, flag filled) );
EXTERN_FUNCTION (unsigned int overlay_segments,
		 (KOverlayList olist, unsigned int num_segments,
		  unsigned int *types0, double *x0, double *y0,
		  unsigned int *types1, double *x1, double *y1,
		  CONST char *colourname) );
EXTERN_FUNCTION (unsigned int overlay_vectors,
		 (KOverlayList olist, unsigned int num_vectors,
		  unsigned int *stypes, double *sx, double *sy,
		  unsigned int *dtypes, double *dx, double *dy,
		  CONST char *colourname) );

/*  Instruction manipulation functions  */
EXTERN_FUNCTION (flag overlay_remove_objects, (KOverlayList olist,
					       unsigned int num_objects) );
EXTERN_FUNCTION (flag overlay_remove_object,
		 (KOverlayList olist, unsigned int id_in_list,
		  unsigned int list_id) );
EXTERN_FUNCTION (flag overlay_move_object,
		 (KOverlayList olist, unsigned int id_in_list,
		  unsigned int list_id, double dx, double dy) );
EXTERN_FUNCTION (unsigned int overlay_get_num_coords,
		 (KOverlayList olist, unsigned int id_in_list,
		  unsigned int list_id) );
EXTERN_FUNCTION (flag overlay_get_coords,
		 (KOverlayList olist, unsigned int id_in_list,
		  unsigned int list_id, double *x, double *y,
		  unsigned int *types) );

/*  Miscellaneous functions  */
EXTERN_FUNCTION (flag overlay_have_token, (KOverlayList olist) );
EXTERN_FUNCTION (flag overlay_release_token, (KOverlayList olist) );
EXTERN_FUNCTION (flag overlay_read_karma,
		 (KOverlayList olist, CONST char *filename) );
EXTERN_FUNCTION (flag overlay_write_karma,
		 (KOverlayList olist, CONST char *filename) );

/*  Obsolete functions  */
EXTERN_FUNCTION (KOverlayList overlay_create_list, (void *info) );
EXTERN_FUNCTION (flag overlay_associate_display_canvas,
		 (KOverlayList olist, KWorldCanvas canvas) );
EXTERN_FUNCTION (flag overlay_unassociate_display_canvas,
		 (KOverlayList olist, KWorldCanvas canvas) );


/*  File: read_ascii.c  */
EXTERN_FUNCTION (flag overlay_read_ascii,
		 (KOverlayList olist, CONST char *filename) );


/*  File: editor.c  */
EXTERN_FUNCTION (KOverlayListEditorContext overlay_editor_create_context,
		 (KOverlayList olist, ...) );
EXTERN_FUNCTION (void overlay_editor_destroy_context,
		 (KOverlayListEditorContext context) );
EXTERN_FUNCTION (void overlay_editor_bind,
		 (KOverlayListEditorContext context,
		  KWorldCanvas canvas, KPixCanvasEditorContext pix_ctx) );
EXTERN_FUNCTION (void overlay_editor_set_attributes,
		 (KOverlayListEditorContext context, ...) );
EXTERN_FUNCTION (void overlay_editor_get_attributes,
		 (KOverlayListEditorContext context, ...) );
EXTERN_FUNCTION (void overlay_editor_set_pixcontext_attributes,
		 (KOverlayListEditorContext context, ...) );


#endif /*  KARMA_OVERLAY_H  */
