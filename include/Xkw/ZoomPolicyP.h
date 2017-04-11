/*  ZoomPolicy.h

    Private header for  ZoomPolicy  widget class.

    Copyright (C) 1996-2005  Richard Gooch

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
  ZoomPolicy widget.


    Written by      Richard Gooch   12-MAY-1996

    Last updated by Richard Gooch   30-OCT-2005

*/
#ifndef ZoomPolicyP__H
#define ZoomPolicyP__H

#include <X11/IntrinsicP.h>
#include <X11/ShellP.h>
#include <X11/StringDefs.h>

#include <Xkw/ZoomPolicy.h>

typedef struct _ZoomPolicyPart
{
    /*  Public resources  */
    Bool          showMiddleZoom;
    Bool          showRightZoom;
    /*  Private resources  */
    flag   auto_refresh;
    int    magnify_choice;
    struct canvas_list *first_canvas;
} ZoomPolicyPart, *ZoomPolicyPartPtr;

typedef struct _ZoomPolicyRec
{
    CorePart core;
    CompositePart composite;
    ShellPart shell;
    WMShellPart wm;
    VendorShellPart vendor;
    TopLevelShellPart topLevel;
    ZoomPolicyPart zoomPolicy;
} ZoomPolicyRec, *ZoomPolicyPtr;

typedef struct _ZoomPolicyClassPart
{
    int empty;
} ZoomPolicyClassPart;

typedef struct _ZoomPolicyClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ShellClassPart shell_class;
    WMShellClassPart wm_shell_class;
    VendorShellClassPart vendor_shell_class;
    TopLevelShellClassPart top_level_shell_class;
    ZoomPolicyClassPart zoomPolicy_class;
} ZoomPolicyClassRec, *ZoomPolicyClassPtr;

extern ZoomPolicyClassRec zoomPolicyClassRec;

#endif
