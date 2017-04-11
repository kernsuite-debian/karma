/*  FilewinP.h

    Private header for  Filewin  widget class.

    Copyright (C) 1993-2005  Richard Gooch

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

    This include file contains the private class declarations for the Filewin
  widget.


    Written by      Richard Gooch   7-JUL-1993

    Last updated by Richard Gooch   30-OCT-2005

*/
#ifndef FILEWINP__H
#define FILEWINP__H

#include <X11/IntrinsicP.h>
#include <X11/Xaw/FormP.h>
#include <X11/StringDefs.h>

#include <karma_dir.h>

#if !defined(KARMA_C_DEF_H) || defined(MAKEDEPEND)
#  include <karma_c_def.h>
#endif

#include <Xkw/Filewin.h>

typedef struct _FilewinPart
{
    /*  Public resources  */
    XtCallbackList        fileSelectCallback;
    XtCallbackList        directoryChangeCallback;
    flag                  (*accept_file) ();
    Pixel                 foreground;
    int                   numLines;
    Bool                  forwardSyntheticEvents;
    Bool                  trapDirectoryDatasets;
    Widget                filewinWidget;
    Widget                showDotsToggleWidget;
    /*  Private resources  */
    Widget                listwidget;
    char                  **list;
    char                  curdir[MAXPATHLEN];
    char                  orig_dir[MAXPATHLEN];
    KDir                  dir_kdir;
    int                   dir_fd;
    int                   listcount;
    int                   listmax;
    int                   last_loaded;
    KCallbackList         dir_callbacks;
    KCallbackFunc         synthetic_func;
    Widget                text_widget;
} FilewinPart, *FilewinPartPtr;

typedef struct _FilewinRec
{
  CorePart core;
  CompositePart composite;
  ConstraintPart constraint;
  FormPart form;
  FilewinPart filewin;
} FilewinRec, *FilewinPtr;

typedef struct _FilewinClassPart
{
  int empty;
} FilewinClassPart;

typedef struct _FilewinClassRec
{
  CoreClassPart core_class;	
  CompositeClassPart composite_class;
  ConstraintClassPart constraint_class;
  FormClassPart form_class;
  FilewinClassPart filewin_class;
} FilewinClassRec, *FilewinClassPtr;

extern FilewinClassRec filewinClassRec;

typedef struct {int empty;} FilewinConstraintsPart;

typedef struct _FilewinConstraintsRec {
    FormConstraintsPart	  form;
    FilewinConstraintsPart filewin;
} FilewinConstraintsRec, *FilewinConstraints;

#endif
