/*  karma_canvas_def.h

    Header for canvas_ package. This file ONLY contains the object definitions

    Copyright (C) 1997-2001  Richard Gooch

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

    This include file contains all the definitions for the canvas_ routines in
    the Karma library.


    Written by      Richard Gooch   9-AUG-1997

    Last updated by Richard Gooch   4-DEC-2001

*/

#ifndef KARMA_CANVAS_DEF_H
#define KARMA_CANVAS_DEF_H


typedef struct worldcanvas_type * KWorldCanvas;

struct _worldcanvas_limit_struct
{
    double left_x;
    double right_x;
    double bottom_y;
    double top_y;
};

typedef struct
{
    struct _worldcanvas_limit_struct soft;
    struct _worldcanvas_limit_struct hard;
} KWorldCanvasLimits;


#endif /*  KARMA_CANVAS_DEF_H  */
