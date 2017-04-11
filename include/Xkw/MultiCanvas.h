/*  MultiCanvas.h

    Public header for  MultiCanvas  widget class.

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

    This include file contains the public class declarations for the
    MultiCanvas widget.


    Written by      Richard Gooch   17-DEC-1994

    Last updated by Richard Gooch   4-JUL-2005

*/
#ifndef MULTICANVAS__H
#define MULTICANVAS__H

#include <X11/Xmu/Converters.h>
#include <Xkw/Canvas.h>

#define XkwCanvasTypePseudoColour      0x01
#define XkwCanvasTypeDirectColour      0x02
#define XkwCanvasTypeTrueColour        0x04
#define XkwCanvasTypeStereo            0x08
#define XkwCanvasTypeBestPseudoColour  0x10


extern WidgetClass multiCanvasWidgetClass;
typedef struct _MultiCanvasClassRec *MultiCanvasWidgetClass;
typedef struct _MultiCanvasRec *MultiCanvasWidget;

#define XtIsMultiCanvas(w) XtIsSubclass((w), multiCanvasWidgetClass)

#define XkwNrequestMask       "requestMask"
#define XkwNallowedMask       "allowedMask"
#define XkwNsplitStereo       "splitStereo"
#define XkwNpseudoXColourMap  "pseudoXColourMap"
#define XkwNverbose           "verbose"

#define XkwCMask              "Mask"
#define XkwCSplitStereo       "SplitStereo"
#define XkwCVerbose           "Verbose"

#endif
