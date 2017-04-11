/*  Filewin.h

    Public header for  Filewin  widget class.

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

    This include file contains the public class declarations for the Filewin
  widget.


    Written by      Richard Gooch   7-JUL-1993

    Last updated by Richard Gooch   30-OCT-2005

*/
#ifndef FILEWIN__H
#define FILEWIN__H

#if !defined(KARMA_C_DEF_H) || defined(MAKEDEPEND)
#  include <karma_c_def.h>
#endif

#if !defined(KARMA_DIR_H) || defined(MAKEDEPEND)
#  include <karma_dir.h>
#endif

extern WidgetClass filewinWidgetClass;
typedef struct _FilewinClassRec *FilewinWidgetClass;
typedef struct _FilewinRec *FilewinWidget;

#define XtIsFilewin(w) XtIsSubclass((w), filewinWidgetClass)

#define XkwNfileSelectCallback "fileSelectCallback"
#define XkwNdirectoryChangeCallback "directoryChangeCallback"
#define XkwNfilenameTester "filenameTester"
#define XkwNforwardSyntheticEvents "forwardSyntheticEvents"
#define XkwNtrapDirectoryDatasets "trapDirectoryDatasets"
#define XkwNnumLines "numLines"
#define XkwNshowDotsToggleWidget "showDotsToggleWidget"

#define XkwCForwardSyntheticEvents "ForwardSyntheticEvents"
#define XkwCTrapDirectoryDatasets "TrapDirectoryDatasets"
#define XkwCNumLines "NumLines"
#define XkwCShowDotsToggleWidget "ShowDotsToggleWidget"

EXTERN_FUNCTION (void XkwFilewinRescan, (Widget W) );
EXTERN_FUNCTION (char *XkwFilewinCurrentDirectory, (Widget W) );
EXTERN_FUNCTION (KCallbackFunc XkwFilewinRegisterDirCbk,
		 (Widget w,
		  flag (*callback) (Widget w, void *info, CONST char *dirname),
		  void *info) );
EXTERN_FUNCTION (flag XkwFilewinStandardFileTester_nD, (KFileInfo finfo) );
EXTERN_FUNCTION (flag XkwFilewinStandardFileTester_3D, (KFileInfo finfo) );
EXTERN_FUNCTION (flag XkwFilewinChangeDirectory,
		 (Widget W, CONST char *dirname) );


#endif
