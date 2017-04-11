/*  karma_ext.h

    Header for  ext_  package.

    Copyright (C) 1996-2004  Richard Gooch

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
  needed to interface to the ext_ routines in the Karma library.


    Written by      Richard Gooch   10-OCT-1997

    Last updated by Richard Gooch   18-JUN-2004

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#ifndef KARMA_EXT_H
#define KARMA_EXT_H


/*  File: main.c  */
#ifndef KARMA_EXT_MAIN_C
EXTERN_FUNCTION (flag ext_call,
		 (CONST char *service, CONST char *function,
		  unsigned int max_func, unsigned int *num_ok,
		  flag allow_consumption, ...) );
#endif
EXTERN_FUNCTION (flag ext_add_service,
		 (CONST char *service, CONST char *object,
		  CONST char *search_dirs) );


#endif /*  KARMA_EXT_H  */
