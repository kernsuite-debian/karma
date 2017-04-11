/*  ContourSimpleControl.h

    Private header for  ContourSimpleControl  widget class.

    Copyright (C) 1998-2001  Richard Gooch

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
  ContourSimpleControl widget.


    Written by      Richard Gooch   16-SEP-1998

    Last updated by Richard Gooch   7-MAY-2001

*/

#ifndef ContourSimpleControlP__H
#define ContourSimpleControlP__H

#include <X11/IntrinsicP.h>
#include <X11/ShellP.h>
#include <X11/StringDefs.h>

#include <Xkw/ContourSimpleControl.h>

typedef struct _ContourSimpleControlPart
{
    /*  Public resources  */
    iarray array;
    /*  Private resources  */
    struct canvas_list *first_canvas;
    Widget levels_dlg;
    Widget negative_colour_dlg;
    Widget positive_colour_dlg;
    Widget display_tgl;
    double contour_neg_width;
    double contour_pos_width;
} ContourSimpleControlPart, *ContourSimpleControlPartPtr;

typedef struct _ContourSimpleControlRec
{
    CorePart core;
    CompositePart composite;
    ShellPart shell;
    WMShellPart wm;
    VendorShellPart vendor;
    TopLevelShellPart topLevel;
    ContourSimpleControlPart contourSimpleControl;
} ContourSimpleControlRec, *ContourSimpleControlPtr;

typedef struct _ContourSimpleControlClassPart
{
    int empty;
} ContourSimpleControlClassPart;

typedef struct _ContourSimpleControlClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ShellClassPart shell_class;
    WMShellClassPart wm_shell_class;
    VendorShellClassPart vendor_shell_class;
    TopLevelShellClassPart top_level_shell_class;
    ContourSimpleControlClassPart contourSimpleControl_class;
} ContourSimpleControlClassRec, *ContourSimpleControlClassPtr;

extern ContourSimpleControlClassRec contourSimpleControlClassRec;

#endif
