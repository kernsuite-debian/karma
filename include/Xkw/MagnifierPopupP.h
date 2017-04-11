/*  MagnifierPopupP.h

    Private header for  MagnifierPopup  widget class.

    Copyright (C) 1997-1998  Richard Gooch

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
  MagnifierPopup widget, a simple Magnifier display widget for
  Xt.


    Written by      Richard Gooch   7-DEC-1997

    Last updated by Richard Gooch   22-FEB-1998

*/
#ifndef MagnifierPopupP__H
#define MagnifierPopupP__H

#include <X11/IntrinsicP.h>
#include <X11/ShellP.h>
#include <X11/StringDefs.h>

#include <Xkw/SlaveImageDisplayPopupP.h>
#include <Xkw/MagnifierPopup.h>

typedef struct _MagnifierPopupPart
{
    /*  Public resources  */
    Bool showCrosshair;
    /*  Private resources  */
    double x_lin;
    double y_lin;
    struct canvas_list *first_canvas;
} MagnifierPopupPart, *MagnifierPopupPartPtr;

typedef struct _MagnifierPopupRec
{
    CorePart core;
    CompositePart composite;
    ShellPart shell;
    WMShellPart wm;
    VendorShellPart vendor;
    TopLevelShellPart topLevel;
    SlaveImageDisplayPopupPart slaveImageDisplayPopup;
    MagnifierPopupPart magnifierPopup;
} MagnifierPopupRec, *MagnifierPopupPtr;

typedef struct _MagnifierPopupClassPart
{
    int empty;
} MagnifierPopupClassPart;

typedef struct _MagnifierPopupClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ShellClassPart shell_class;
    WMShellClassPart wm_shell_class;
    VendorShellClassPart vendor_shell_class;
    TopLevelShellClassPart top_level_shell_class;
    SlaveImageDisplayPopupClassPart slaveImageDisplayPopup_class;
    MagnifierPopupClassPart magnifierPopup_class;
} MagnifierPopupClassRec, *MagnifierPopupClassPtr;

extern MagnifierPopupClassRec magnifierPopupClassRec;

#endif
