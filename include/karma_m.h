/*  karma_m.h

    Header for  m_  package.

    Copyright (C) 1992-2004  Richard Gooch

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
  needed to interface to the m_ routines in the Karma library.


    Written by      Richard Gooch   12-SEP-1992

    Last updated by Richard Gooch   10-MAY-2004

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif
#ifndef NULL
#  define NULL 0
#endif

#if !defined(KARMA_M_DEF_H) || defined(MAKEDEPEND)
#  include <karma_m_def.h>
#endif

#ifndef KARMA_M_H
#define KARMA_M_H
#  include <sys/types.h>



/*  File: fault.c  */
EXTERN_FUNCTION (flag m_test_access,
		 (void *start, uaddr size, flag write) );


/*  File: main.c  */
EXTERN_FUNCTION (void *m_alloc, (uaddr size) );
EXTERN_FUNCTION (void *m_alloc_no_checks, (uaddr size) );
EXTERN_FUNCTION (void m_free, (void *ptr) );
EXTERN_FUNCTION (void m_free_no_checks, (void *ptr) );
EXTERN_FUNCTION (void m_abort, (char *name, char *reason) );
EXTERN_FUNCTION (unsigned int m_verify_memory_integrity, (flag force) );
EXTERN_FUNCTION (uaddr m_get_total_allocated, () );
EXTERN_FUNCTION (void m_trap_allocations, (uaddr min, uaddr max) );


/*  File: map.c  */
EXTERN_FUNCTION (void *m_map_fd,
		 (int *fd, uaddr size, flag writable, flag update_on_write,
		  flag warn_unsupported) );
EXTERN_FUNCTION (flag m_unmap, (void *addr, uaddr size) );
EXTERN_FUNCTION (flag m_map_test, () );


/*  File: misc.c   */
EXTERN_FUNCTION (void m_clear, (void *ptr, uaddr length) );
EXTERN_FUNCTION (void *m_calloc, (uaddr size) );
EXTERN_FUNCTION (void m_free2, (void *ptr) );
EXTERN_FUNCTION (void m_copy, (void *dest, CONST void *source,
			       uaddr length) );
EXTERN_FUNCTION (void m_copy_blocks, (void *dest, CONST void *source,
				      unsigned int dest_stride,
				      unsigned int source_stride,
				      unsigned int block_size,
				      unsigned int num_blocks) );
EXTERN_FUNCTION (void m_copy_and_swap_blocks,
		 (void *dest, CONST void *source, uaddr dest_stride,
		  uaddr source_stride, uaddr block_size, uaddr num_blocks) );
EXTERN_FUNCTION (void m_fill, (void *dest, uaddr stride,
			       CONST void *source, uaddr size,
			       unsigned int num) );
EXTERN_FUNCTION (flag m_cmp, (CONST void *block1, CONST void *block2,
			      uaddr length) );
EXTERN_FUNCTION (void *m_dup, (CONST void *original, uaddr size) );
EXTERN_FUNCTION (void *m_alloc_scratch, (uaddr size, char *function_name) );
EXTERN_FUNCTION (void m_free_scratch, () );
EXTERN_FUNCTION (void m_free_and_clear_pointer, (void *ptr) );
EXTERN_FUNCTION (void m_error_notify, (char *function_name, char *purpose) );


/*  File: shm.c  */
EXTERN_FUNCTION (flag m_shm_test_if_available, () );
EXTERN_FUNCTION (int m_shm_alloc, (uaddr size, mode_t prot) );
EXTERN_FUNCTION (void m_shm_delete, (int shmid) );
EXTERN_FUNCTION (void *m_shm_attach,
		 (int shmid, flag reattach, flag writable) );
EXTERN_FUNCTION (flag m_shm_detach, (void *addr) );


#endif /*  KARMA_M_H  */
