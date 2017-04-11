/*  ScrollableList.h

    Public header for  ScrollableList  widget class.

    Copyright (C) 2004  Richard Gooch

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
  ScrollableList widget, a scrollable list widget for Xt.


    Written by      Richard Gooch   7-MAR-2004

    Last updated by Richard Gooch   8-MAR-2004

*/
#ifndef SCROLLABLELIST__H
#define SCROLLABLELIST__H

#include <X11/Xmu/Converters.h>

#if !defined(KARMA_LISTW_DEF_H) || defined(MAKEDEPEND)
#  include <karma_listw_def.h>
#endif

extern WidgetClass scrollableListWidgetClass;
typedef struct _ScrollableListClassRec *ScrollableListWidgetClass;
typedef struct _ScrollableListRec *ScrollableListWidget;

#define XtIsScrollableList(w) XtIsSubclass((w), scrollableListWidgetClass)

#define XkwNlist "list"
#define XkwNcanvas "canvas"
#define XkwNhighlightPixel "highlightPixel"

#define XkwCList "List"
#define XkwCCanvas "Canvas"
#define XkwCHighlightPixel "HighlightPixel"

/*----------------------------------------------------------------------
 * Functions
 *----------------------------------------------------------------------*/


#endif
