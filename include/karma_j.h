/*  karma_j.h

    Header for  j_  package.

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

    This include file contains all the definitions and function declarations
  needed to interface to the j_ routines in the Karma library.


    Written by      Richard Gooch   14-OCT-1995

    Last updated by Richard Gooch   31-JAN-1997

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#if !defined(KARMA_J_DEF_H) || defined(MAKEDEPEND)
#  include <karma_j_def.h>
#endif

#ifndef KARMA_J_H
#define KARMA_J_H


#define KJ_REPLACEMENT_POLICY_NEW (unsigned int) 0
#define KJ_REPLACEMENT_POLICY_UPDATE (unsigned int) 1
#define KJ_REPLACEMENT_POLICY_PUT (unsigned int) 2


/*  File:  main.c  */
EXTERN_FUNCTION (KJoinedPairList j_create,
		 ( void *info,
		  int (*key_compare_func) (),
		  void *(*key_copy_func) (),
		  void (*key_destroy_func) () ) );
EXTERN_FUNCTION (void j_destroy, (KJoinedPairList list) );
EXTERN_FUNCTION (void *j_get_info, (KJoinedPairList list) );
EXTERN_FUNCTION (KJoinedPair j_put_pair,
		 (KJoinedPairList list, CONST void *key, uaddr key_length,
		  CONST void *value, uaddr value_length,
		  void *(*value_copy_func) (),
		  void (*value_destroy_func) (),
		  unsigned int replacement_policy, flag front) );
EXTERN_FUNCTION (KJoinedPair j_get_pair,
		 (KJoinedPairList list, CONST void *key, void **value) );
EXTERN_FUNCTION (void j_destroy_pair, (KJoinedPair pair) );
EXTERN_FUNCTION (KJoinedPair *j_get_all_pairs,
		 (KJoinedPairList list, unsigned int *num_pairs) );
EXTERN_FUNCTION (void j_get_pair_info,
		 (KJoinedPair pair, void **key, uaddr *key_length,
		  void **value, uaddr *value_length) );


#endif /*  KARMA_J_H  */
