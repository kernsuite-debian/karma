/*  ImageEditorControl.h

    Private header for  ImageEditorControl  widget class.

    Copyright (C) 1999  Richard Gooch

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
  ImageEditorControl widget.


    Written by      Richard Gooch   9-JUN-1999

    Last updated by Richard Gooch   9-JUN-1999

*/

#ifndef ImageEditorControlP__H
#define ImageEditorControlP__H

#include <X11/IntrinsicP.h>
#include <X11/ShellP.h>
#include <X11/StringDefs.h>

#include <karma_overlay.h>
#include <karma_iedit.h>
#include <Xkw/ImageEditorControl.h>

typedef struct _ImageEditorControlPart
{
    /*  Public resources  */
    int dummy;
    /*  Private resources  */
    KImageEditList elist;
    int object_mode;
    int brush_width;
    Widget value_dlg;
    double prev_x, prev_y;
    struct canvas_list *first_canvas;
} ImageEditorControlPart, *ImageEditorControlPartPtr;

typedef struct _ImageEditorControlRec
{
    CorePart core;
    CompositePart composite;
    ShellPart shell;
    WMShellPart wm;
    VendorShellPart vendor;
    TopLevelShellPart topLevel;
    ImageEditorControlPart imageEditorControl;
} ImageEditorControlRec, *ImageEditorControlPtr;

typedef struct _ImageEditorControlClassPart
{
    int empty;
} ImageEditorControlClassPart;

typedef struct _ImageEditorControlClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ShellClassPart shell_class;
    WMShellClassPart wm_shell_class;
    VendorShellClassPart vendor_shell_class;
    TopLevelShellClassPart top_level_shell_class;
    ImageEditorControlClassPart imageEditorControl_class;
} ImageEditorControlClassRec, *ImageEditorControlClassPtr;

extern ImageEditorControlClassRec imageEditorControlClassRec;

#endif
