/*  karma_dispdata_def.h

    Header for dispdata_ package.
    This file ONLY contains the object definitions.

    Copyright (C) 2002-2005  Richard Gooch

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

    This include file contains all the definitions for the dispdata_ routines in
    the Karma library.


    Written by      Richard Gooch   10-NOV-2002

    Last updated by Richard Gooch   19-JUL-2005

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#if !defined(KARMA_CANVAS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_canvas_def.h>
#endif

#if !defined(KARMA_KCMAP_DEF_H) || defined(MAKEDEPEND)
#  include <karma_kcmap_def.h>
#endif

#ifndef KARMA_DISPDATA_DEF_H
#define KARMA_DISPDATA_DEF_H


typedef struct displaydata_dataclass_type * KDisplayDataClass;
typedef struct displaydata_dataobject_type * KDisplayDataObject;
typedef struct displaydata_window_type * KDisplayDataWindow;
typedef struct displaydata_blinkstate_type * KDisplayDataBlinkState;
typedef struct displaydata_class_blinkstate_type * KDisplayDataClassBlinkState;
typedef struct displaydata_blinkentry_type * KDisplayDataBlinkEntry;
typedef struct displaydata_private_namelist * KDisplayDataPrivateNameList;
typedef struct
{
    KWorldCanvas main;
    KWorldCanvas magnifier;
    KWorldCanvas panner;
    Kcolourmap renzogram_cmap;
    Kcolourmap hue_intensity_cmap;  /*  For rgb only  */
} KDisplayDataCanvas;


#endif /*  KARMA_DISPDATA_DEF_H  */
