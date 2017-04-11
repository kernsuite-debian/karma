/*  karma_kwin_def.h

    Header for  kwin_  package. This file ONLY contains the object definitions

    Copyright (C) 1997-2002  Richard Gooch

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

    This include file contains all the definitions for the kwin_ package in the
    Karma library.


    Written by      Richard Gooch   10-AUG-1997

    Last updated by Richard Gooch   9-DEC-2002

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#ifndef KARMA_KWIN_DEF_H
#define KARMA_KWIN_DEF_H


typedef struct pixcanvas_type * KPixCanvas;
typedef struct cache_data_type * KPixCanvasImageCache;
typedef struct pixfont_type * KPixCanvasFont;

typedef struct  /*  Experimental structure  */
{
    int startx;
    int endx;
    int starty;
    int endy;
    flag clear;
    flag geom_clear;
} KPixCanvasRefreshArea;

typedef struct kwin_editor_type * KPixCanvasEditorContext;
typedef struct  /*  Experimental structure  */
{
    CONST char *binding;
    CONST char *purpose;
} KPixCanvasBinding;

typedef struct hershey_string_type * KPixCanvasHersheyString;


#endif /*  KARMA_KWIN_DEF_H  */
