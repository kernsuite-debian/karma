/*  karma_gls.h

    Header for  gls_  package.

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
  needed to interface to the gls_ routines in the Karma library.


    Written by      Richard Gooch   21-DEC-1996

    Last updated by Richard Gooch   17-APR-2004

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#if !defined(KARMA_C_DEF_H) || defined(MAKEDEPEND)
#  include <karma_c_def.h>
#endif

#if !defined(KARMA_DS_VAL_H) || defined(MAKEDEPEND)
#  include <karma_ds_val.h>
#endif

#ifndef KARMA_GLS_H
#define KARMA_GLS_H


/*  File: interface.c  */
EXTERN_FUNCTION (flag gls_initialise, (int *argc, char **argv) );
EXTERN_FUNCTION (flag gls_test_running, () );
EXTERN_FUNCTION (KCallbackFunc gls_register_glish_event_handler,
		 (flag (*func) (), CONST char *name, void *object) );
EXTERN_FUNCTION (KCallbackFunc gls_register_plain_event_handler,
		 (flag (*func) (), CONST char *name, void *object) );
EXTERN_FUNCTION (void gls_send_plain_event,
		 (CONST char *name, CONST void *data,
		  unsigned int type, unsigned int num_elements,
		  unsigned int num_axes, CONST int *axis_lengths) );


#endif /*  KARMA_GLS_H  */
