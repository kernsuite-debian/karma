/*  SlaveImageDisplayPopupP.h

    Private header for  SlaveImageDisplayPopup  widget class.

    Copyright (C) 1997-2000  Richard Gooch

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
  SlaveImageDisplayPopup widget, a simple slaveImageDisplay display widget for
  Xt.


    Written by      Richard Gooch   6-DEC-1997

    Last updated by Richard Gooch   12-MAY-2000

*/
#ifndef SlaveImageDisplayPopupP__H
#define SlaveImageDisplayPopupP__H

#include <X11/IntrinsicP.h>
#include <X11/ShellP.h>
#include <X11/StringDefs.h>

#include <Xkw/SlaveImageDisplayPopup.h>

typedef struct _SlaveImageDisplayPopupPart
{
    /*  Public resources  */
    KWorldCanvas   pseudoCanvas;
    KWorldCanvas   directCanvas;
    KWorldCanvas   trueCanvas;
    KWorldCanvas   pseudoCanvasLeft;
    KWorldCanvas   pseudoCanvasRight;
    KWorldCanvas   directCanvasLeft;
    KWorldCanvas   directCanvasRight;
    KWorldCanvas   trueCanvasLeft;
    KWorldCanvas   trueCanvasRight;
    KWorldCanvas   visibleCanvas;
    KWorldCanvas   *canvasList;
    Bool           fastPanner;
    Bool           enablePanning;
    Bool           verbose;
    XtCallbackList realisedCallback;
    /*  Private resources  */
    Widget         close_btn;
    Widget         top_form;
} SlaveImageDisplayPopupPart, *SlaveImageDisplayPopupPartPtr;

typedef struct _SlaveImageDisplayPopupRec
{
    CorePart core;
    CompositePart composite;
    ShellPart shell;
    WMShellPart wm;
    VendorShellPart vendor;
    TopLevelShellPart topLevel;
    SlaveImageDisplayPopupPart slaveImageDisplayPopup;
} SlaveImageDisplayPopupRec, *SlaveImageDisplayPopupPtr;

typedef struct _SlaveImageDisplayPopupClassPart
{
    int empty;
} SlaveImageDisplayPopupClassPart;

typedef struct _SlaveImageDisplayPopupClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ShellClassPart shell_class;
    WMShellClassPart wm_shell_class;
    VendorShellClassPart vendor_shell_class;
    TopLevelShellClassPart top_level_shell_class;
    SlaveImageDisplayPopupClassPart slaveImageDisplayPopup_class;
} SlaveImageDisplayPopupClassRec, *SlaveImageDisplayPopupClassPtr;

extern SlaveImageDisplayPopupClassRec slaveImageDisplayPopupClassRec;

#endif
