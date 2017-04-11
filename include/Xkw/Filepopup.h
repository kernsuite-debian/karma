/*  Filepopup.h

    Public header for  Filepopup  widget class.

    Copyright (C) 1993-1994  Patrick Jordan
    Incorporated into Karma by permission.
    Copyright (C) 1994-2003  Richard Gooch

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

    This include file contains the public class declarations for the Filepopup
  widget.


    Written by      Richard Gooch   7-JUL-1993

    Last updated by Richard Gooch   24-JAN-2003

*/
#ifndef FILEPOPUP__H
#define FILEPOPUP__H

#include <X11/Shell.h>
#if !defined(KARMA_DIR_H) || defined(MAKEDEPEND)
#  include <karma_dir.h>
#endif

extern WidgetClass filepopupWidgetClass;
typedef struct _FilepopupClassRec *FilepopupWidgetClass;
typedef struct _FilepopupRec *FilepopupWidget;

#define XtIsFilepopup(w) XtIsSubclass((w), filepopupWidgetClass)

#define XkwNautoPopdown "autoPopdown"
#define XkwNfileSelectCallback "fileSelectCallback"
#define XkwNfilenameTester "filenameTester"
#define XkwNloadFiles "loadFiles"
#define XkwNpreferFloat "preferFloat"
#define XkwNdomainName "domainName"
#define XkwNboxWidget "boxWidget"
#define XkwNfilewinWidget "filewinWidget"

#define XkwCAutoPopdown "AutoPopdown"
#define XkwCLoadFiles "LoadFiles"
#define XkwCPreferFloat "PreferFloat"
#define XkwCDomainName "DomainName"
#define XkwCBoxWidget "BoxWidget"
#define XkwCFilewinWidget "FilewinWidget"

EXTERN_FUNCTION (void XkwFilepopupPopupCallback,
		 (Widget w, XtPointer client_data, XtPointer call_data) );

#endif
