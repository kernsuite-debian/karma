/*  DressingControl.h

    Private header for  DressingControl  widget class.

    Copyright (C) 1997-2004  Richard Gooch

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
  DressingControl widget.


    Written by      Richard Gooch   15-FEB-1997

    Last updated by Richard Gooch   1-APR-2004

*/
#ifndef DressingControlP__H
#define DressingControlP__H

#include <X11/IntrinsicP.h>
#include <X11/ShellP.h>
#include <X11/StringDefs.h>

#include <Xkw/DressingControl.h>

typedef struct _DressingControlPart
{
    /*  Public resources  */
    int                 dummy;
    /*  Private resources  */
    flag                auto_refresh;
    Widget              background_colour_txt;
    Widget              label_colour_txt;
    Widget              grid_colour_txt;
    Widget              change_cmap_tgl;
    struct canvas_list  *first_canvas;
    double              font_scale;
} DressingControlPart, *DressingControlPartPtr;

typedef struct _DressingControlRec
{
    CorePart core;
    CompositePart composite;
    ShellPart shell;
    WMShellPart wm;
    VendorShellPart vendor;
    TopLevelShellPart topLevel;
    DressingControlPart dressingControl;
} DressingControlRec, *DressingControlPtr;

typedef struct _DressingControlClassPart
{
    int empty;
} DressingControlClassPart;

typedef struct _DressingControlClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ShellClassPart shell_class;
    WMShellClassPart wm_shell_class;
    VendorShellClassPart vendor_shell_class;
    TopLevelShellClassPart top_level_shell_class;
    DressingControlClassPart dressingControl_class;
} DressingControlClassRec, *DressingControlClassPtr;

extern DressingControlClassRec dressingControlClassRec;

#endif
