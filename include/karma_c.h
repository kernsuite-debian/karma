/*  karma_c.h

    Header for  c_  package.

    Copyright (C) 1994-2006  Richard Gooch

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
  needed to interface to the c_ routines in the Karma library.


    Written by      Richard Gooch   27-NOV-1994

    Last updated by Richard Gooch   3-AUG-2006

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#if !defined(KARMA_C_DEF_H) || defined(MAKEDEPEND)
#  include <karma_c_def.h>
#endif

#ifndef KARMA_C_H
#define KARMA_C_H


/*  File:  main.c  */
EXTERN_FUNCTION (KCallbackFunc c_register_callback,
		 (KCallbackList *list, flag (*callback) (),
		  void *object, void *client1_data, flag client1_indirect,
		  void *client2_data, flag client2_indirect,flag quenchable) );
EXTERN_FUNCTION (void c_unregister_callback, (KCallbackFunc callback) );
EXTERN_FUNCTION (flag c_call_callbacks, (KCallbackList list,void *call_data) );
EXTERN_FUNCTION (void c_destroy_list, (KCallbackList list) );
EXTERN_FUNCTION (void c_move_callback, (KCallbackFunc callback, flag last) );
EXTERN_FUNCTION (flag c_list_dispatching, (KCallbackList list) );
EXTERN_FUNCTION (flag c_list_dispatching2, (KCallbackFunc callback) );
EXTERN_FUNCTION (flag c_list_test_empty, (KCallbackList list) );

/*  File:  misc.c  */
EXTERN_FUNCTION (void c_write_null_func, (void **pointer) );
EXTERN_FUNCTION (void c_write_2nulls_func, (void *pointer) );
EXTERN_FUNCTION (void c_unregister_callback2, (KCallbackFunc callback) );


#endif /*  KARMA_C_H  */
