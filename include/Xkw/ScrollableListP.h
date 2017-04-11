/*  ScrollableListP.h

    Private header for  ScrollableList  widget class.

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

    This include file contains the private class declarations for the
  ScrollableList widget, a scrollable list widget for Xt.


    Written by      Richard Gooch   7-MAR-2004

    Last updated by Richard Gooch   8-MAR-2004

*/
#ifndef ScrollableListP__H
#define ScrollableListP__H

#include <X11/IntrinsicP.h>
#include <X11/Xaw/FormP.h>
#include <X11/StringDefs.h>

#include <Xkw/ScrollableList.h>

typedef struct _ScrollableListPart
{
    /*  Public resources  */
    KListWidget         list;
    KPixCanvas          canvas;
    Pixel               highlightPixel;
    /*  Private resources  */
    Widget              canvas_widget;
    Widget              scrollbar;
} ScrollableListPart, *ScrollableListPartPtr;

typedef struct _ScrollableListRec
{
    CorePart core;
    CompositePart composite;
    ConstraintPart constraint;
    FormPart form;
    ScrollableListPart scrollableList;
} ScrollableListRec, *ScrollableListPtr;

typedef struct _ScrollableListClassPart
{
    int empty;
} ScrollableListClassPart;

typedef struct _ScrollableListClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ConstraintClassPart constraint_class;
    FormClassPart form_class;
    ScrollableListClassPart scrollableList_class;
} ScrollableListClassRec, *ScrollableListClassPtr;

extern ScrollableListClassRec scrollableListClassRec;

typedef struct {int empty;} ScrollableListConstraintsPart;

typedef struct _ScrollableListConstraintsRec
{
    FormConstraintsPart	  form;
    ScrollableListConstraintsPart ScrollableList;
} ScrollableListConstraintsRec, *ScrollableListConstraints;

#endif
