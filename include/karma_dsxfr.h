/*  karma_dsxfr.h

    Header for  dsxfr_  package.

    Copyright (C) 1992-1999  Richard Gooch

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
  needed to interface to the dsxfr_ routines in the Karma library.


    Written by      Richard Gooch   19-SEP-1992

    Last updated by Richard Gooch   30-JAN-1999

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#if !defined(KARMA_CONN_DEF_H) || defined(MAKEDEPEND)
#  include <karma_conn_def.h>
#endif

#if !defined(KARMA_DS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_ds_def.h>
#endif

#if !defined(KARMA_CH_DEF_H) || defined(MAKEDEPEND)
#  include <karma_ch_def.h>
#endif

#ifndef KARMA_DSXFR_H
#define KARMA_DSXFR_H


/*  File:   main.c   */
EXTERN_FUNCTION (void dsxfr_register_connection_limits,
		 (int max_incoming, int max_outgoing) );
EXTERN_FUNCTION (flag dsxfr_put_multi, (CONST char *object,
					multi_array *multi_desc) );
EXTERN_FUNCTION (flag dsxfr_send_multi,
		 (Connection connection, CONST multi_array *multi_desc,
		  CONST char *name) );
EXTERN_FUNCTION (multi_array *dsxfr_get_multi, (CONST char *object, flag cache,
						unsigned int mmap_option,
						flag writable) );
EXTERN_FUNCTION (void dsxfr_register_read_func, ( void (*read_func) () ) );
EXTERN_FUNCTION (void dsxfr_register_close_func, ( void (*close_func) () ) );
EXTERN_FUNCTION (flag dsxfr_test_split, (CONST char *filename) );
EXTERN_FUNCTION (multi_array *dsxfr_read_split,
		 (char *filename, flag ascii, flag guess) );


#endif /*  KARMA_DSXFR_H  */
