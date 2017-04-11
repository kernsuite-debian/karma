/*  karma_w.h

    Header for  w_  package.

    Copyright (C) 1995-1999  Richard Gooch

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
  needed to interface to the w_ routines in the Karma library.


    Written by      Richard Gooch   30-DEC-1995

    Last updated by Richard Gooch   8-JAN-1999

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#if !defined(KARMA_W_DEF_H) || defined(MAKEDEPEND)
#  include <karma_w_def.h>
#endif

#ifndef KARMA_W_H
#define KARMA_W_H


#define KWF_PRIORITY_HIGHEST (unsigned int) 0
#define KWF_PRIORITY_HIGH    (unsigned int) 1
#define KWF_PRIORITY_LOWEST  (unsigned int) 2


/*  File:  main.c  */
EXTERN_FUNCTION (flag w_test_supported, () );
EXTERN_FUNCTION (void w_register_support, () );
EXTERN_FUNCTION (void w_unregister_support, () );
EXTERN_FUNCTION (void w_register_notify_func,
		 (void (*func) (void *info), void *info) );
EXTERN_FUNCTION (flag w_work_to_be_done, () );
EXTERN_FUNCTION (flag w_do_work, () );
EXTERN_FUNCTION (KWorkFunc w_register_func,
		 (flag (*func) (void **info), void *info,
		  unsigned int priority) );
EXTERN_FUNCTION (void w_unregister_func, (KWorkFunc wf) );


#endif /*  KARMA_W_H  */
