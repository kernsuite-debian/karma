/*  CmapwinpopupP.h

    Private header for  Cmapwinpopup  widget class.

    Copyright (C) 1994-2000  Richard Gooch

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
    Cmapwinpopup widget.


    Written by      Richard Gooch   17-DEC-1994

    Last updated by Richard Gooch   11-JUL-2000

*/
#ifndef CmapwinpopupP__H
#define CmapwinpopupP__H

#include <X11/IntrinsicP.h>
#include <X11/ShellP.h>
#include <X11/StringDefs.h>

#include <karma.h>
#include <Xkw/Cmapwinpopup.h>

typedef struct _CmapwinpopupPart
{
    /*  Public resources  */
    Kcolourmap cmap;
    Visual *colourbarVisual;
    Bool simpleColourbar;
    Bool verbose;
    /*  Private resources  */
    Widget cmapwin;
    Widget save_dialog;
    Widget filepopup;
    flag changing_attributes;
    Widget reverse_tgl;
    Widget invert_tgl;
} CmapwinpopupPart, *CmapwinpopupPartPtr;

typedef struct _CmapwinpopupRec
{
    CorePart core;
    CompositePart composite;
    ShellPart shell;
    WMShellPart wm;
    VendorShellPart vendor;
    TopLevelShellPart topLevel;
    CmapwinpopupPart cmapwinpopup;
} CmapwinpopupRec, *CmapwinpopupPtr;

typedef struct _CmapwinpopupClassPart
{
    int empty;
} CmapwinpopupClassPart;

typedef struct _CmapwinpopupClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ShellClassPart shell_class;
    WMShellClassPart wm_shell_class;
    VendorShellClassPart vendor_shell_class;
    TopLevelShellClassPart top_level_shell_class;
    CmapwinpopupClassPart cmapwinpopup_class;
} CmapwinpopupClassRec, *CmapwinpopupClassPtr;

extern CmapwinpopupClassRec cmapwinpopupClassRec;

#endif
