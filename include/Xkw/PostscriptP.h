/*  PostscriptP.h

    Private header for  Postscript  widget class.

    Copyright (C) 1994-2005  Richard Gooch

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
  Postscript widget.


    Written by      Richard Gooch   26-JUN-1994

    Last updated by Richard Gooch   30-OCT-2005

*/
#ifndef PostscriptP__H
#define PostscriptP__H

#include <X11/IntrinsicP.h>
#include <X11/ShellP.h>
#include <X11/StringDefs.h>
#include <karma_kcmap_def.h>
#include <karma_kwin_def.h>

#include <Xkw/Postscript.h>

typedef struct _PostscriptPart
{
    /*  Public resources  */
    int             hoffset;
    int             voffset;
    int             hsize;
    int             vsize;
    XtCallbackList  callback;
    /*  Special resources (changed by XkwPostscriptRegisterImageAndName)  */
    KPixCanvas      pixcanvas;
    /*  Private resources  */
    Widget          aspect_tgl;
    Widget          name_txt;
    Widget          queue_txt;
    Widget          lock_tgl;
    Widget          auto_increment_tgl;
    int             tray;
    int             media_size;
    int             orientation;
    unsigned int    instance_number;
    double          linewidth;
    KCallbackFunc   ds_event_callback;
} PostscriptPart, *PostscriptPartPtr;

typedef struct _PostscriptRec
{
  CorePart core;
  CompositePart composite;
  ShellPart shell;
  WMShellPart wm;
  VendorShellPart vendor;
  TopLevelShellPart topLevel;
  PostscriptPart postscript;
} PostscriptRec, *PostscriptPtr;

typedef struct _PostscriptClassPart
{
  int empty;
} PostscriptClassPart;

typedef struct _PostscriptClassRec
{
  CoreClassPart core_class;	
  CompositeClassPart composite_class;
  ShellClassPart shell_class;
  WMShellClassPart wm_shell_class;
  VendorShellClassPart vendor_shell_class;
  TopLevelShellClassPart top_level_shell_class;
  PostscriptClassPart postscript_class;
} PostscriptClassRec, *PostscriptClassPtr;

extern PostscriptClassRec postscriptClassRec;

#endif
