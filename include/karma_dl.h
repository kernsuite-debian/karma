/*  karma_dl.h

    Header for  dl_  package.

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
  needed to interface to the dl_ routines in the Karma library.


    Written by      Richard Gooch   25-DEC-1996

    Last updated by Richard Gooch   25-APR-2004

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#ifndef KARMA_DL_H
#define KARMA_DL_H


/*  File: main.c  */
EXTERN_FUNCTION (void *dl_load_object, (CONST char *name, CONST char *dirs,
					char failed_object[STRING_LENGTH]) );
EXTERN_FUNCTION (void *dl_load_one_object,
		 (CONST char *object, CONST char *search_dirs, flag global) );
EXTERN_FUNCTION (void *dl_symbol, (void *handle, CONST char *symbol) );
EXTERN_FUNCTION (int dl_close, (void *handle) );


#endif /*  KARMA_DL_H  */
