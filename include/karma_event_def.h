/*  karma_event_def.h

    Header for  event_  package. This file ONLY contains the struct definitions

    Copyright (C) 1998  Richard Gooch

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

    This include file contains all the definitions for the event_ routines in
    the Karma library.


    Written by      Richard Gooch   29-MAR-1998

    Last updated by Richard Gooch   13-APR-1998

*/
#ifndef KARMA_EVENT_DEF_H
#define KARMA_EVENT_DEF_H


typedef struct
{
    char defined;
    double x;
    double y;
} KEventSingleCoordinate;

typedef struct
{
    KEventSingleCoordinate screen_pixel;
    KEventSingleCoordinate linear;
    KEventSingleCoordinate world;
    KEventSingleCoordinate image_pixel;
} KEventCoordinate;

typedef struct
{
    unsigned long modifier_mask;
    KEventCoordinate position;
    char *string;
} KEventKeyPress;

typedef struct
{
    unsigned int type;
    union
    {
	KEventCoordinate point;
	KEventKeyPress keypress;
    } data;
} KEvent;


#endif /*  KARMA_EVENT_DEF_H  */
