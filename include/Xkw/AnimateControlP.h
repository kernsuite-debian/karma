/*  AnimateControl.h

    Private header for  AnimateControl  widget class.

    Copyright (C) 1994-1999  Richard Gooch

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
    AnimateControl widget.


    Written by      Richard Gooch   8-DEC-1994

    Last updated by Richard Gooch   13-APR-1999

*/

#ifndef AnimateControlP__H
#define AnimateControlP__H

#include <X11/IntrinsicP.h>
#include <X11/ShellP.h>
#include <X11/StringDefs.h>

#include <Xkw/AnimateControl.h>
#include <karma.h>
#include <karma_canvas.h>

typedef struct _AnimateControlPart
{
    /*  Public resources  */
    XtCallbackList newFrameCallback;
    int numFrames;
    int startFrame;
    int endFrame;
    int currentFrame;
    /*  Private resources  */
    KWorldCanvas position_wc;
    int interval_ms;
    int inc_factor;
    int spin_mode;
    int direction;
    flag running_movie;
    flag synchronise;
    flag pin;
    Widget num_frames_lbl;
    Widget start_frame_sld;
    Widget end_frame_sld;
    Widget current_frame_sld;
} AnimateControlPart, *AnimateControlPartPtr;

typedef struct _AnimateControlRec
{
    CorePart core;
    CompositePart composite;
    ShellPart shell;
    WMShellPart wm;
    VendorShellPart vendor;
    TopLevelShellPart topLevel;
    AnimateControlPart animateControl;
} AnimateControlRec, *AnimateControlPtr;

typedef struct _AnimateControlClassPart
{
    int empty;
} AnimateControlClassPart;

typedef struct _AnimateControlClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ShellClassPart shell_class;
    WMShellClassPart wm_shell_class;
    VendorShellClassPart vendor_shell_class;
    TopLevelShellClassPart top_level_shell_class;
    AnimateControlClassPart animate_control_class;
} AnimateControlClassRec, *AnimateControlClassPtr;

extern AnimateControlClassRec animateControlClassRec;

#endif
