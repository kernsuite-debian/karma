/*  karma_graph1d.h

    Header for  graph1d_  package.

    Copyright (C) 2000-2004  Richard Gooch

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
  needed to interface to the graph1d_ routines in the Karma library.


    Written by      Richard Gooch   15-JUN-2000

    Last updated by Richard Gooch   21-MAY-2004

*/

#if !defined(KARMA_GRAPH1D_DEF_H) || defined(MAKEDEPEND)
#  include <karma_graph1d_def.h>
#endif

#if !defined(KARMA_CANVAS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_canvas_def.h>
#endif

#if !defined(KARMA_IARRAY_DEF_H) || defined(MAKEDEPEND)
#  include <karma_iarray_def.h>
#endif

#if !defined(KARMA_CH_DEF_H) || defined(MAKEDEPEND)
#  include <karma_ch_def.h>
#endif

#if !defined(KARMA_C_DEF_H) || defined(MAKEDEPEND)
#  include <karma_c_def.h>
#endif

#ifndef KARMA_GRAPH1D_H
#define KARMA_GRAPH1D_H


#define GRAPH1D_DRAW_STYLE_LINES             0
#define GRAPH1D_DRAW_STYLE_STEPS             1
#define GRAPH1D_DRAW_STYLE_CROSSES           2
#define GRAPH1D_NUM_DRAW_STYLES              3
#define GRAPH1D_DRAW_STYLE_DEFAULT           3  /*  Not user-selectable  */
extern char *graph1d_draw_style_choices[GRAPH1D_NUM_DRAW_STYLES];

#define GRAPH1D_CANVAS_ATT_END               0
#define GRAPH1D_CANVAS_ATT_DRAW_STYLE        1
#define GRAPH1D_CANVAS_ATT_SMOOTH_MODE       2
#define GRAPH1D_CANVAS_ATT_LEFT_X            3
#define GRAPH1D_CANVAS_ATT_RIGHT_X           4
#define GRAPH1D_CANVAS_ATT_BOTTOM_Y          5
#define GRAPH1D_CANVAS_ATT_TOP_Y             6
#define GRAPH1D_CANVAS_ATT_MINIMUM_Y         7
#define GRAPH1D_CANVAS_ATT_MAXIMUM_Y         8
#define GRAPH1D_CANVAS_ATT_AUTO_Y            9
#define GRAPH1D_CANVAS_ATT_SHOW_HLINE       10
#define GRAPH1D_CANVAS_ATT_SHOW_VLINE       11

#define GRAPH1D_SMOOTH_MODE_NONE             0
#define GRAPH1D_SMOOTH_MODE_HANNING_3        1
#define GRAPH1D_SMOOTH_MODE_HANNING_5        2
#define GRAPH1D_SMOOTH_MODE_HANNING_7        3
#define GRAPH1D_SMOOTH_MODE_HANNING_9        4
#define GRAPH1D_SMOOTH_MODE_UNIFORM_3        5
#define GRAPH1D_SMOOTH_MODE_UNIFORM_5        6
#define GRAPH1D_SMOOTH_MODE_UNIFORM_7        7
#define GRAPH1D_SMOOTH_MODE_UNIFORM_9        8
#define GRAPH1D_NUM_SMOOTH_MODES             9
extern char *graph1d_smooth_mode_choices[GRAPH1D_NUM_SMOOTH_MODES];

#define GRAPH1D_VGRAPH_ATT_END               0
#define GRAPH1D_VGRAPH_ATT_DRAW_STYLE        1
#define GRAPH1D_VGRAPH_ATT_DARK_COLOUR       2
#define GRAPH1D_VGRAPH_ATT_LIGHT_COLOUR      3
#define GRAPH1D_VGRAPH_ATT_USE_COLOURMAP     4
#define GRAPH1D_VGRAPH_ATT_SCALE             5
#define GRAPH1D_VGRAPH_ATT_OFFSET            6
#define GRAPH1D_VGRAPH_ATT_HLINE_Y           7
#define GRAPH1D_VGRAPH_ATT_VLINE_X           8


/*  File:  main.c  */
EXTERN_FUNCTION (void graph1d_init, (KWorldCanvas canvas) );
EXTERN_FUNCTION (void graph1d_set_canvas_attributes, (KWorldCanvas, ...) );
EXTERN_FUNCTION (flag graph1d_test_if_zoomed_horizontally,
		 (KWorldCanvas canvas) );
EXTERN_FUNCTION (void graph1d_unzoom,
		 (KWorldCanvas canvas, flag horizontal, flag vertical,
		  flag auto_v) );
EXTERN_FUNCTION (void graph1d_refresh_if_needed, (KWorldCanvas canvas) );
EXTERN_FUNCTION (KViewableGraph graph1d_create,
		 (KWorldCanvas canvas, unsigned int num_points,
		  double **x, double **y, uaddr key, ...) );
EXTERN_FUNCTION (void graph1d_set_vgraph_attributes,
		 (KViewableGraph vgraph, ...) );
EXTERN_FUNCTION (flag graph1d_set_active,
		 (KViewableGraph vgraph, flag active,flag force_refresh,
		  flag refresh_if_changed, flag exclusive, uaddr key) );
EXTERN_FUNCTION (flag graph1d_set_all_inactive,
		 (KWorldCanvas canvas, flag force_refresh,
		  flag refresh_if_changed, uaddr key) );
EXTERN_FUNCTION (void graph1d_destroy, (KViewableGraph vgraph) );
EXTERN_FUNCTION (KCallbackFunc graph1d_register_destroy_func,
		 (KViewableGraph vgraph, void (*func) (), void *info) );
EXTERN_FUNCTION (KWorldCanvas graph1d_get_worldcanvas,
		 (KViewableGraph vgraph) );
EXTERN_FUNCTION (void graph1d_change_draw_order,
		 (KViewableGraph vgraph, KViewableGraph position,
		  flag before) );
EXTERN_FUNCTION (KViewableGraph graph1d_get_last, (KWorldCanvas canvas) );
EXTERN_FUNCTION (flag graph1d_allocate_coords,
		 (KViewableGraph vgraph, unsigned int num_coords,
		  double **x, double **y) );
EXTERN_FUNCTION (void graph1d_set_size,
		 (KViewableGraph vgraph, unsigned int num_points) );
EXTERN_FUNCTION (unsigned int graph1d_get_size,
		 (KViewableGraph vgraph, double **x, double **y) );
EXTERN_FUNCTION (flag graph1d_save_ascii,
		 (KViewableGraph vgraph, Channel channel) );


/*  File:  orthogonal.c  */
EXTERN_FUNCTION (KOrthogonalProfile graph1d_orthogonal_create,
		 (KWorldCanvas canvas, iarray array, KViewableGraph *vgraph) );
EXTERN_FUNCTION (void graph1d_orthogonal_destroy,
		 (KOrthogonalProfile profile) );
EXTERN_FUNCTION (KCallbackFunc graph1d_orthogonal_register_destroy_func,
		 (KOrthogonalProfile profile, void (*func) (), void *info) );
EXTERN_FUNCTION (void graph1d_orthogonal_invalidate,
		 (KOrthogonalProfile profile) );
EXTERN_FUNCTION (void graph1d_orthogonal_show_trace,
		 (KOrthogonalProfile profile, CONST unsigned int *dim_indices,
		  flag correct_aberration,
		  CONST uaddr *coord_indices, uaddr refpos) );
EXTERN_FUNCTION (void graph1d_orthogonal_show_traces,
		 (KOrthogonalProfile profile, CONST unsigned int *dim_indices,
		  flag correct_aberration,
		  flag sum, float global_weight, unsigned int num_traces,
		  CONST uaddr *coord_indices, uaddr refpos,
		  CONST float *weights) );
EXTERN_FUNCTION (void graph1d_orthogonal_show_boxed_trace,
		 (KOrthogonalProfile profile, CONST unsigned int *dim_indices,
		  flag sum, CONST uaddr *start_indices,
		  CONST uaddr *stop_indices, uaddr refpos) );
EXTERN_FUNCTION (void graph1d_orthogonal_configure_canvas,
		 (KOrthogonalProfile profile) );
EXTERN_FUNCTION (void graph1d_orthogonal_save,
		 (KWorldCanvas canvas, CONST char *filename) );
EXTERN_FUNCTION (flag graph1d_orthogonal_track_compute,
		 (KWorldCanvas canvas, double x, double y, double x_lin,
		  char x_string[STRING_LENGTH],char y_string[STRING_LENGTH]) );


#endif /*  KARMA_GRAPH1D_H  */
