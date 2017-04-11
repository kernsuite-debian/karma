/*  DataclipP.h

    Private header for  Dataclip  widget class.

    Copyright (C) 1994-2003  Richard Gooch

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

    This include file contains the private class declarations for the
  Dataclip widget, a graphical widget to select data regions for Xt.


    Written by      Richard Gooch   23-OCT-1994

    Last updated by Richard Gooch   3-OCT-2003

*/
#ifndef DataclipP__H
#define DataclipP__H

#include <X11/IntrinsicP.h>
#include <X11/ShellP.h>
#include <X11/StringDefs.h>

#include <karma_canvas_def.h>
#include <karma_kwin_def.h>

#include <Xkw/Dataclip.h>

struct raw_hist_struct
{
    unsigned long *array;
    unsigned int  length;
    unsigned int  buf_length;
    unsigned long index_of_peak;
};

struct dpy_hist_struct
{
    double        *array;
    unsigned int  length;
    unsigned int  buf_length;
    unsigned long index_of_peak;
};

struct raw_data_struct
{
    double        min_raw;
    double        max_raw;
    double        min_scaled;
    double        max_scaled;
};

struct decimated_data_struct
{
    float         *array;
    unsigned int  length;
    unsigned int  buf_len;
    double        min_raw;
    double        max_raw;
    double        min_scaled;
    double        max_scaled;
    flag          valid;
};

typedef struct _DataclipPart
{
    /*  Public resources  */
    XtCallbackList                 scaledRegionCallback;
    XtCallbackList                 rawRegionCallback;
    int                            maxRegions;
    int                            pad;
    Bool                           verbose;
    Bool                           showBlankControl;
    Cardinal                       fixedOutputType;
    Bool                           autoPopdown;
    /*  Private resources: must start on a  double  boundary  */
    struct raw_data_struct         bigset;
    struct decimated_data_struct   subset;      /*  "Fast and loose" sample  */
    double                         curr_min;             /*  Scaled  */
    double                         curr_max;             /*  Scaled  */
    double                         left_pos;             /*  Scaled  */
    double                         *minima;              /*  Scaled  */
    double                         *maxima;              /*  Scaled  */
    iarray                         array;
    unsigned int                   num_regions;
    KPixCanvas                     pixcanvas;
    KWorldCanvas                   worldcanvas;
    KCallbackFunc                  iarr_destroy_callback;
    struct raw_hist_struct         raw_histogram;
    struct dpy_hist_struct         display_histogram;
    flag                           immediate_apply;
    flag                           last_was_left;
    flag                           blank_data;
    Widget                         min_label;
    Widget                         max_label;
    Widget                         lower_label;
    Widget                         upper_label;
    Widget                         cursor_x_label;
    Widget                         cursor_y_label;
    Widget                         dialog;
    Widget                         cnv;
    Widget                         subset_tgl;
    flag                           popped_up;
    unsigned int                   output_type;
    flag                           reset_canvas_scale;
    int                            mode;              /*  Join, steps, etc.  */
} DataclipPart, *DataclipPartPtr;

typedef struct _DataclipRec
{
    CorePart core;
    CompositePart composite;
    ShellPart shell;
    WMShellPart wm;
    VendorShellPart vendor;
    TopLevelShellPart topLevel;
    DataclipPart dataclip;
} DataclipRec, *DataclipPtr;

typedef struct _DataclipClassPart
{
    unsigned int type_index_to_type[NUMTYPES];
    char *type_names[NUMTYPES];
    unsigned int num_types;
} DataclipClassPart;

typedef struct _DataclipClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ShellClassPart shell_class;
    WMShellClassPart wm_shell_class;
    VendorShellClassPart vendor_shell_class;
    TopLevelShellClassPart top_level_shell_class;
    DataclipClassPart dataclip_class;
} DataclipClassRec, *DataclipClassPtr;

extern DataclipClassRec dataclipClassRec;

#endif
