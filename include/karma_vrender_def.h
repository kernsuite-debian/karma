/*  karma_vrender_def.h

    Header for  <vrender>  package. This file ONLY contains the object
    definitions.

    Copyright (C) 1995-1997  Richard Gooch

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

    This include file contains all the definitions for the vrender_ routines
    in the Karma library.


    Written by      Richard Gooch   24-DEC-1995

    Last updated by Richard Gooch   25-MAY-1997

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#ifndef KARMA_VRENDER_DEF_H
#define KARMA_VRENDER_DEF_H


typedef struct vrendercontext_type * KVolumeRenderContext;

typedef struct
{
    double x;
    double y;
    double z;
} Kdcoord_3d;

typedef struct
{
    float x;
    float y;
    float z;
} Kcoord_3d;

typedef struct
{
    float x;
    float y;
} Kcoord_2d;

typedef struct
{
    Kcoord_3d position;
    Kcoord_3d focus;
    Kcoord_3d vertical;
} view_specification;

typedef struct
{
    unsigned long command;
    unsigned long length;
    CONST char *message;
} KVolumeRenderMessage;


#endif /*  KARMA_VRENDER_DEF_H  */
