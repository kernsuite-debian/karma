/*  FilepopupP.h

    Private header for  Filepopup  widget class.

    Copyright (C) 1993-1994  Patrick Jordan
    Incorporated into Karma by permission.
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

    This include file contains the private class declarations for the Filepopup
  widget.


    Written by      Richard Gooch   9-JUL-1993

    Last updated by Richard Gooch   23-APR-2003

*/
#ifndef FILEPOPUPP__H
#define FILEPOPUPP__H

#include <X11/IntrinsicP.h>
#include <X11/ShellP.h>
#include <X11/StringDefs.h>

#include <karma_dir.h>

#if !defined(KARMA_C_DEF_H) || defined(MAKEDEPEND)
#  include <karma_c_def.h>
#endif

#include <Xkw/Filepopup.h>

typedef struct _FilepopupPart
{
    /*  Public resources  */
    flag                  (*accept_file) ();
    XtCallbackList        fileSelectCallback;
    Bool                  autoPopdown;
    Bool                  loadFiles;
    Bool                  preferFloat;
    String                domainName;
    Widget                boxWidget;
    Widget                filewinWidget;
    /*  Private resources  */
    Widget                filter_tgl;
    Widget                partial_tgl;
    Widget                writable_tgl;
    Widget                load_and_decimate_popup;
    char                  curdir[500];
    int                   listcount;
    int                   listmax;
    Widget                pin_tgl;
    KCallbackFunc         ds_event_callback;
    struct member_struct  *member;
} FilepopupPart, *FilepopupPartPtr;

typedef struct _FilepopupRec
{
    CorePart core;
    CompositePart composite;
    ShellPart shell;
    WMShellPart wm;
    VendorShellPart vendor;
    TopLevelShellPart topLevel;
    FilepopupPart filepopup;
} FilepopupRec, *FilepopupPtr;

typedef struct _FilepopupClassPart
{
    int empty;
} FilepopupClassPart;

typedef struct _FilepopupClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ShellClassPart shell_class;
    WMShellClassPart wm_shell_class;
    VendorShellClassPart vendor_shell_class;
    TopLevelShellClassPart top_level_shell_class;
    FilepopupClassPart filepopup_class;
} FilepopupClassRec, *FilepopupClassPtr;

extern FilepopupClassRec filepopupClassRec;

#endif
