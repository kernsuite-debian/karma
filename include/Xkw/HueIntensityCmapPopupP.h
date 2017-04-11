/*  HueIntensityCmapPopupP.h

    Private header for  HueIntensityCmapPopup  widget class.

    Copyright (C) 2005  Richard Gooch

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
    HueIntensityCmapPopup widget.


    Written by      Richard Gooch   18-JUL-2005

    Last updated by Richard Gooch   19-JUL-2005

*/
#ifndef HueIntensityCmapPopupP__H
#define HueIntensityCmapPopupP__H

#include <X11/IntrinsicP.h>
#include <X11/ShellP.h>
#include <X11/StringDefs.h>
#include <Xkw/HueIntensityCmapPopup.h>
#include <karma_kwin_def.h>

typedef struct _HueIntensityCmapPopupPart
{
    /*  Public resources  */
    Kcolourmap      kcmap;
    /*  Private resources  */
    double          start_hue;
    double          stop_hue;
    double          min_intensity;
    double          saturation;
    Widget          cnvs;
    KPixCanvas      pixcanvas;
} HueIntensityCmapPopupPart, *HueIntensityCmapPopupPartPtr;

typedef struct _HueIntensityCmapPopupRec
{
    CorePart core;
    CompositePart composite;
    ShellPart shell;
    WMShellPart wm;
    VendorShellPart vendor;
    TopLevelShellPart topLevel;
    HueIntensityCmapPopupPart hueIntensityCmapPopup;
} HueIntensityCmapPopupRec, *HueIntensityCmapPopupPtr;

typedef struct _HueIntensityCmapPopupClassPart
{
    int empty;
} HueIntensityCmapPopupClassPart;

typedef struct _HueIntensityCmapPopupClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ShellClassPart shell_class;
    WMShellClassPart wm_shell_class;
    VendorShellClassPart vendor_shell_class;
    TopLevelShellClassPart top_level_shell_class;
    HueIntensityCmapPopupClassPart hueIntensityCmapPopup_class;
} HueIntensityCmapPopupClassRec, *HueIntensityCmapPopupClassPtr;

extern HueIntensityCmapPopupClassRec hueIntensityCmapPopupClassRec;

#endif
