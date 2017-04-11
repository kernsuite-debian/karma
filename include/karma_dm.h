/*  karma_dm.h

    Header for  dm_  package.

    Copyright (C) 1995-2000  Richard Gooch

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
  needed to interface to the dm_ routines in the Karma library.


    Written by      Richard Gooch   3-OCT-1995

    Last updated by Richard Gooch   7-OCT-2000

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#if !defined(KARMA_DM_DEF_H) || defined(MAKEDEPEND)
#  include <karma_dm_def.h>
#endif

#include <stdarg.h>

#ifndef KARMA_DM_H
#define KARMA_DM_H


/*  File: interface.c  */
EXTERN_FUNCTION (void dm_register_managers,
		 ( KManagedDescriptor (*manage_func) (int fd, void *info,
						      flag auto_close,
						      va_list argp),
		   void *(*unmanage_func) (int fd, KManagedDescriptor md) ) );
EXTERN_FUNCTION (flag dm_test_if_setup, () );
EXTERN_FUNCTION (KManagedDescriptor dm_manage,
		 (int fd, void *info, flag auto_close, ...) );
EXTERN_FUNCTION (void *dm_unmanage, (int fd, KManagedDescriptor md) );

/*  File: native.c  */
EXTERN_FUNCTION (void dm_native_setup, () );
EXTERN_FUNCTION (void dm_native_poll, (long timeout) );
EXTERN_FUNCTION (void dm_native_clear_activity_counter, () );
EXTERN_FUNCTION (unsigned long dm_native_get_activity_count, () );
EXTERN_FUNCTION (void dm_native_clear_idle_timer, () );
EXTERN_FUNCTION (unsigned long dm_native_get_idle_time, () );
EXTERN_FUNCTION (flag dm_native_wait_input, (int fd, int timeout) );
EXTERN_FUNCTION (KManagedDescriptor dm_native_manage,
		 (int fd, void *info, flag auto_close, va_list argp) );
EXTERN_FUNCTION (void *dm_native_unmanage,
		 (int fd, KManagedDescriptor entry) );


#endif /*  KARMA_DM_H  */
