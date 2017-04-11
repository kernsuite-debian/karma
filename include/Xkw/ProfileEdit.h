/*  ProfileEditP.h

    Public header for  ProfileEdit  widget class.

    Copyright (C) 1997  Richard Gooch

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

    This include file contains the public class declarations for the
  ProfileEdit widget, a simple profile editor widget for Xt.


    Written by      Richard Gooch   28-FEB-1997

    Last updated by Richard Gooch   3-MAR-1997

*/

/*----------------------------------------------------------------------*/
/* This code provides a profile editing widget for Xt. */
/**/
/*
 Name		         Class		   RepType         Default Value
 ----		         -----		   -------         -------------
 iarray                  Iarray            Pointer         NULL
 XkwNworldCanvas         WorldCanvas       Pointer         NULL
 verbose                 Verbose           Bool            False
 XtNCallback             Callback          Callback        NULL

*/    
/*----------------------------------------------------------------------*/

#ifndef ProfileEdit__H
#define ProfileEdit__H

#include <X11/Xmu/Converters.h>

extern WidgetClass profileEditWidgetClass;
typedef struct _ProfileEditClassRec *ProfileEditWidgetClass;
typedef struct _ProfileEditRec *ProfileEditWidget;

#define XtIsProfileEdit(w) XtIsSubclass((w), profileEditWidgetClass)

#define XkwNiarray "iarray"
#define XkwNworldCanvas "worldCanvas"
#define XkwNverbose "verbose"

#define XkwCIarray "Iarray"
#define XkwCWorldCanvas "WorldCanvas"
#define XkwCVerbose "Verbose"


#endif
