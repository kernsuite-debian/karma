/*  PannerPopupP.h

    Private header for  PannerPopup  widget class.

    Copyright (C) 1997-1999  Richard Gooch

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
  PannerPopup widget, a simple Panner display widget for
  Xt.


    Written by      Richard Gooch   6-DEC-1997

    Last updated by Richard Gooch   15-AUG-1999

*/
#ifndef PannerPopupP__H
#define PannerPopupP__H

#include <X11/IntrinsicP.h>
#include <X11/ShellP.h>
#include <X11/StringDefs.h>

#include <Xkw/SlaveImageDisplayPopupP.h>
#include <Xkw/PannerPopup.h>

typedef struct _PannerPopupPart
{
    /*  Public resources  */
    int dummy;
    /*  Private resources  */
    struct canvas_list *first_canvas;
    KPixCanvasRefreshArea *areas;
} PannerPopupPart, *PannerPopupPartPtr;

typedef struct _PannerPopupRec
{
    CorePart core;
    CompositePart composite;
    ShellPart shell;
    WMShellPart wm;
    VendorShellPart vendor;
    TopLevelShellPart topLevel;
    SlaveImageDisplayPopupPart slaveImageDisplayPopup;
    PannerPopupPart pannerPopup;
} PannerPopupRec, *PannerPopupPtr;

typedef struct _PannerPopupClassPart
{
    int empty;
} PannerPopupClassPart;

typedef struct _PannerPopupClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ShellClassPart shell_class;
    WMShellClassPart wm_shell_class;
    VendorShellClassPart vendor_shell_class;
    TopLevelShellClassPart top_level_shell_class;
    SlaveImageDisplayPopupClassPart slaveImageDisplayPopup_class;
    PannerPopupClassPart pannerPopup_class;
} PannerPopupClassRec, *PannerPopupClassPtr;

extern PannerPopupClassRec pannerPopupClassRec;

#endif
