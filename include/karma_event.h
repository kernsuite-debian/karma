/*  karma_event.h

    Header for  event_  package.

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

    This include file contains all the definitions and function declarations
  needed to interface to the event_ routines in the Karma library.


    Written by      Richard Gooch   29-MAR-1998

    Last updated by Richard Gooch   12-AUG-1998

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#if !defined(KARMA_EVENT_DEF_H) || defined(MAKEDEPEND)
#  include <karma_event_def.h>
#endif

#if !defined(KARMA_CONN_DEF_H) || defined(MAKEDEPEND)
#  include <karma_conn_def.h>
#endif

#if !defined(KARMA_C_DEF_H) || defined(MAKEDEPEND)
#  include <karma_c_def.h>
#endif

#ifndef KARMA_EVENT_H
#define KARMA_EVENT_H


/*  Event masks  */
#define K_EVENT_MASK_MOUSE_CLICK    0x01
#define K_EVENT_MASK_MOUSE_RELEASE  0x02
#define K_EVENT_MASK_MOUSE_DRAG     0x04
#define K_EVENT_MASK_POINTER_MOVE   0x08
#define K_EVENT_MASK_KEYPRESS       0x10
#define K_EVENT_MASK_POINTER_WARP   0x20


/*  File: main.c  */
EXTERN_FUNCTION (void event_initialise, () );
EXTERN_FUNCTION (void event_dispatch, (KEvent event) );
EXTERN_FUNCTION (KCallbackFunc event_register_event_func,
		 (flag (*func) (), void *f_info) );
EXTERN_FUNCTION (flag event_set_mask,
		 (unsigned long mask, long num_events,
		  Connection connection) );
EXTERN_FUNCTION (flag event_wait, (unsigned long mask, Connection connection,
				   KEvent *event) );


#endif /*  KARMA_EVENT_H  */
