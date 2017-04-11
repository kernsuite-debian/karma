/*  os.h

    Header for platform and Operating System dependent definitions.

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

    This header file contains various compile-time definitions which determine
    how the Karma library should interface to the operating system. This
    file should NOT be included by non-library code, as it is subject to change
    without notice.


    Written by      Richard Gooch   20-MAY-1992

    Last updated by Richard Gooch   14-MAY-2004


*/

/*                          BASIC ASSUMPTIONS

    All platforms have 8 bit bytes.

    The C type  char  and  unsigned char  are one byte on all platforms.

    All platforms have signed and unsigned long integers which are at least
    4 bytes.

    The size of all pointers is the same.
*/
#ifndef _POSIX_VERSION
#  include <unistd.h>  /*  Needed for POSIX feature tests  */
#endif


/*  If  OS_SUPPORTED  is defined, then this Operating System has been supported
    in the Karma library. If it is not defined, compilation will stop in this
    file.
*/
#undef OS_SUPPORTED


/*  If  MACHINE_SUPPORTED  is defined, then this machine type (i.e. CPU type)
    has been supported in the Karma library. If it is not defined, compilation
    will stop in this file.
*/
#undef MACHINE_SUPPORTED


/*  If  MACHINE_BIG_ENDIAN  is defined, this means that host data is big
    endian.
*/
#undef MACHINE_BIG_ENDIAN


/*  If  MACHINE_LITTLE_ENDIAN  is defined, this means that host data is little
    endian.
*/
#undef MACHINE_LITTLE_ENDIAN


/*  If  HAS_IEEE  is defined, this means that floating point numbers are stored
    in IEEE format and that:
    the C  float  data type is 32 bits (24 bit exponent)
    the C  double  data type is 64 bits (53 bit exponent)
*/
#undef HAS_IEEE


/*  If CAN_ZERO_CLEAR  is defined, writing values of (char) 0 will zero all
    data types.
*/
#undef CAN_ZERO_CLEAR


/*  The  Kword16s  and  Kword16u  macros are 16 bit integer types. If these do
    not exist, the platform does not support a 16 bit integer type.
*/
#undef Kword16s
#undef Kword16u


/*  The  Kword32s  and  Kword32u  macros are 32 bit integer types. If these do
    not exist, the platform does not support a 32 bit integer type.
*/
#undef Kword32s
#undef Kword32u


/*  The  Kword64s  and  Kword64u  macros are 64 bit integer types. If these do
    not exist, the platform does not support a 64 bit integer type.
*/
#undef Kword64s
#undef Kword64u


/*  If  RETYPE_NEEDED  is defined, then some of the host C integer data
    types are smaller than their corresponding network sizes, and hence must
    be retyped so as not to change the size when converting between host and
    network data formats.
    Note that no retyping is required for machines which have larger data types
    than the network data types.
*/
#undef RETYPE_NEEDED


/*  If  CAN_FORK  is defined, then the operating system allows forking of new
    processes.
*/
#undef CAN_FORK


/*  If  CAN_VFORK  is defined, then the operating system allows vforking of new
    processes.
*/
#undef CAN_VFORK


/*  If  HAS_SIGNALS  is defined, then the operating system allows sending of
    signals.
*/
#undef HAS_SIGNALS


/*  If  HAS_GETRUSAGE  is defined, then the operating system has the
    getrusage(2)  system call.
*/
#undef HAS_GETRUSAGE


/*  If  HAS_TIMES  is defined, then the operating system has the
    times(2)  system call.
*/
#undef HAS_TIMES


/*  If HAS_SOCKETS  is defined, then the operating system has socket support.
*/
#undef HAS_SOCKETS


/*  If HAS_POLL  is defined, then the operating system has the poll(2) system
    call.
*/
#undef HAS_POLL


/*  If  HAS_TERMCAP  is defined, then the operating system has the  termcap
    library.
*/
#undef HAS_TERMCAP


/*  If  HAS_SYSV_SHARED_MEMORY  is defined, then the operating system supports
    the System V shared memory calls.
*/
#undef HAS_SYSV_SHARED_MEMORY


/*  If  NEED_ALIGNED_DATA  is defined, then misaligned data accesses will
    cause a segmentation fault: hence special code is required to avoid this.
    NOTE: this need NOT apply to platforms where the operating system fixes up
    misaligned data accesses (such as the Dec MipsStations), however, for
    efficiency reasons, it may be preferable to treat such platforms as needing
    special code (besides, Ultrix spits out annoying messages otherwise).
*/
#undef NEED_ALIGNED_DATA


/*  The  IS_ALIGNED  macro is always defined, and may be used to determine if a
    data value pointer is aligned to the specified word boundary. This does not
    indicate whether or not the platform requires aligned data accesses.
    Usage:  IS_ALIGNED (char *ptr, size)  evaluates true if aligned.
*/
#undef IS_ALIGNED


/*  The  SAFE_ALIGNMENT  macro is always defined, and may be used to determine
    if a data value pointer needs to be aligned prior to usage.
    Usage: SAFE_ALIGNMENT (char *ptr, size) evaluates false if alignment needed
*/
#undef SAFE_ALIGNMENT


/*  If  NEEDS_MISALIGN_COMPILE  is defined, then misaligned data accesses will
    cause a segmentation fault unless the code has been specially compiled to
    get around this problem.
    NOTE: this does NOT apply to platforms where the operating system fixes up
    misaligned data accesses (such as the Dec MipsStations).
    THIS WILL SOON BE REMOVED: use NEED_ALIGNED_DATA instead.
*/
#undef NEEDS_MISALIGN_COMPILE


/*  If  HAS_ON_EXIT  is defined, then the platform supports the on_exit(3)
    function (which allows the application to register a function which is
    called when exit(3) is called.
*/
#undef HAS_ON_EXIT


/*  If  HAS_ATEXIT  is defined, then the platform supports the atexit(3)
    function (which allows the application to register a function which is
    called when exit(3) is called.
*/
#undef HAS_ATEXIT


/*  If  HAS_INTERNATIONALISATION  is defined, then the platform has the
    Internationalisation extensions (ie. LC_TYPE, etc).
*/
#undef HAS_INTERNATIONALISATION


/*  If  HAS_COMMUNICATIONS_EMULATION  is defined, then the platform has
    emulation support for interprocess communication.
*/
#undef HAS_COMMUNICATIONS_EMULATION


/*  If  HAS_ENVIRON  is defined, then the platform has an environment defined.
    Otherwise, the environment is emulated with the  r_getenv  and r_setenv
    routines.
*/
#undef HAS_ENVIRON


/*  If  HAS_MMAP  is defined, then the platform supports a flavour of mmap(2)
*/
#undef HAS_MMAP


/*  If  HAS_MADVISE  is defined, then the platform supports a flavour of
    madvise(2)
*/
#undef HAS_MADVISE


/*  If  HAS_WAIT3  is defined, then the platform supports the wait3(2)  system
    call, with complete  rusage  support.
*/
#undef HAS_WAIT3


/*  If  HAS_ITIMER  is defined, then the platform supports the setitimer(2)
    system call.
*/
#undef HAS_ITIMER


/*  If  HAS_DL  is defined, then the operating system has the  dl (dynamic
    linking) library.
*/
#undef HAS_DL


/*  If  HAS_ATM  is defined, then the operating system has ATM socket support
    (Asynchronous Transfer Mechanism).
    This is not undefined because it may need to be passed in via compiler
    switches.
*/


/*  If  CAN_PASS_FD  is defined, then the operating system can pass file
    descriptors over connection.
*/
#undef CAN_PASS_FD


/*  If  HAS_SYSV_FD_PASSING  is defined, then the operating system has SysV
    support for passing file descriptors over Unix sockets.
*/
#undef HAS_SYSV_FD_PASSING


/*  If  HAS_OLDBSD_FD_PASSING  is defined, then the operating system has the
    old BSD support for passing file descriptors over Unix sockets.
*/
#undef HAS_OLDBSD_FD_PASSING


/*  If  HAS_NEWBSD_FD_PASSING  is defined, then the operating system has the
    old BSD support for passing file descriptors over Unix sockets.
*/
#undef HAS_NEWBSD_FD_PASSING


/*  POSIX  */
#ifdef _POSIX_VERSION
#  define CAN_FORK
#  define CAN_VFORK
#  define HAS_SIGNALS
#  define HAS_TIMES
#  define HAS_ALARM
#endif

#if defined(_POSIX_MAPPED_FILES) || defined(_POSIX_SHARED_MEMORY_OBJECTS)
#  define HAS_MMAP
#endif

/*****************************************************************************
 *  Operating system section                                                 *
 *****************************************************************************/

/*  Sun Slowaris 2  */
#ifdef OS_Solaris
#  define OS_SUPPORTED
#  define HAS_GETRUSAGE
#  define HAS_SOCKETS
#  define HAS_POLL
#  define HAS_TERMCAP
#  define HAS_SYSV_SHARED_MEMORY
#  define HAS_INTERNATIONALISATION
#  define HAS_ENVIRON
#  define HAS_MADVISE
#  define HAS_ATEXIT
#  define HAS_ITIMER
#  define HAS_DL
#  define HAS_SYSV_FD_PASSING
#endif  /*  OS_Solaris  */

/*  Sun SunOS 4.x  */
#ifdef OS_SunOS
#  define OS_SUPPORTED
#  define HAS_GETRUSAGE
#  define HAS_SOCKETS
#  define HAS_POLL
#  define HAS_TERMCAP
#  define HAS_SYSV_SHARED_MEMORY
#  define HAS_INTERNATIONALISATION
#  define HAS_ENVIRON
#  define HAS_MMAP  /*  They have a really old version of POSIX  */
#  define HAS_ON_EXIT
#  define HAS_WAIT3
#  define HAS_ITIMER
#  define HAS_DL
#endif  /*  OS_SunOS  */

/*  Convex ConvexOS  */
#ifdef OS_ConvexOS
#  define OS_SUPPORTED
#  define HAS_GETRUSAGE
#  define HAS_SOCKETS
#  define HAS_TERMCAP
#  define HAS_ATEXIT
#  define HAS_INTERNATIONALISATION
#  define HAS_ENVIRON
#  define HAS_MMAP  /*  No idea if they do POSIX feature tests properly  */
#  define HAS_WAIT3
#  define HAS_ITIMER
#endif  /*  OS_ConvexOS  */

/*  IBM AIX  */
#ifdef OS_AIX
#  define OS_SUPPORTED
#  define HAS_GETRUSAGE
#  define HAS_SOCKETS
#  define HAS_TERMCAP
/*#  define HAS_SYSV_SHARED_MEMORY*/  /*  Disabled because of missing Xshm  */
#  define HAS_ATEXIT
#  define HAS_INTERNATIONALISATION
#  define HAS_ENVIRON
#  define HAS_WAIT3
#  define HAS_ITIMER
#endif  /*  OS_AIX  */

/*  Vicom VX/ MVX system for a Sun Sparc Station  */
#ifdef OS_VXMVX
#  define OS_SUPPORTED
#  define HAS_COMMUNICATIONS_EMULATION
#endif  /*  OS_VXMVX  */

/*  SGI IRIX  */
#if defined(OS_IRIX5) || defined(OS_IRIX6)
#  define OS_IRIX
#  define OS_SUPPORTED
#  define HAS_GETRUSAGE
#  define HAS_SOCKETS
#  define HAS_POLL
#  define HAS_TERMCAP
#  define HAS_SYSV_SHARED_MEMORY
#  define HAS_ATEXIT
#  define HAS_INTERNATIONALISATION
#  define HAS_ENVIRON
#  define HAS_WAIT3
#  define HAS_ITIMER
#  define HAS_DL
#  define HAS_OLDBSD_FD_PASSING
#endif  /*  OS_IRIX  */

/*  HP HP-UX  */
#ifdef OS_HPUX
#  define OS_SUPPORTED
#  define HAS_SOCKETS
#  define HAS_TERMCAP
/*#  define HAS_SYSV_SHARED_MEMORY*/  /*  No Xshm in standard HPUX library  */
#  define HAS_ATEXIT
#  define HAS_INTERNATIONALISATION
#  define HAS_ENVIRON
#  define HAS_ITIMER
#endif  /*  OS_HPUX  */


/*  DEC ULTRIX  */
#ifdef OS_ULTRIX
#  define OS_SUPPORTED
#  define HAS_SIGNALS
#  define HAS_GETRUSAGE
#  define HAS_SOCKETS
#  define HAS_TERMCAP
#  define HAS_SYSV_SHARED_MEMORY
#  define HAS_ATEXIT
#  define HAS_INTERNATIONALISATION
#  define HAS_ENVIRON
/*#  define HAS_MMAP  Ultrix mmap(2) does not seem to support regular files! */
#  define HAS_WAIT3
#  define HAS_ITIMER
#endif  /*  OS_ULTRIX  */

/*  World Linux  */
#ifdef OS_Linux
#  define OS_SUPPORTED
#  define HAS_GETRUSAGE
#  define HAS_SOCKETS
#  define HAS_POLL
#  define HAS_TERMCAP
#  define HAS_SYSV_SHARED_MEMORY
#  define HAS_ON_EXIT
#  define HAS_INTERNATIONALISATION
#  define HAS_ENVIRON
#  define HAS_WAIT3
#  define HAS_ITIMER
#  define HAS_DL
#  define HAS_ATM
#  define HAS_NEWBSD_FD_PASSING
#endif  /*  OS_Linux  */

/*  IBM PC with 80386 processor running in full, 32 bit 386 mode under
    MS-DOS  */
#ifdef OS_MSDOS
#  define OS_SUPPORTED
#  define HAS_ENVIRON
#endif  /*  OS_MSDOS  */

/*  Phantom machine  */
#ifdef phantom_machine
#  define OS_SUPPORTED
#  define MACHINE_SUPPORTED
#  define HAS_ENVIRON
#endif

/*  Cray UNICOS  */
#ifdef OS_UNICOS
#  define OS_SUPPORTED
#  define HAS_SIGNALS
#  define HAS_SOCKETS
#  define HAS_TERMCAP
/*#  define HAS_SYSV_SHARED_MEMORY*/
#  define HAS_INTERNATIONALISATION
#  define HAS_ENVIRON
#  define HAS_ATEXIT
#endif  /*  OS_UNICOS  */

/*  Digital OSF/1 (aka. Digital Unix)  */
#ifdef OS_OSF1
#  define OS_SUPPORTED
#  define HAS_GETRUSAGE
#  define HAS_SOCKETS
#  define HAS_POLL
#  define HAS_TERMCAP
#  define HAS_SYSV_SHARED_MEMORY
#  define HAS_ATEXIT
#  define HAS_INTERNATIONALISATION
#  define HAS_ENVIRON
#  define HAS_WAIT3
#  define HAS_ITIMER
#  define HAS_DL
#endif  /*  OS_OSF1  */

/*  Darwin (FreeBSD for Macintosh)  */
#ifdef OS_Darwin
#  define OS_SUPPORTED
#  define HAS_GETRUSAGE
#  define HAS_SOCKETS
#  define HAS_TERMCAP
#  define HAS_SYSV_SHARED_MEMORY
#  define HAS_MMAP    /*  They don't do POSIX feature declarations properly  */
#  define HAS_ATEXIT
#  define HAS_INTERNATIONALISATION
#  define HAS_ENVIRON
#  define HAS_WAIT3
#  define HAS_ITIMER
#  define HAS_DL
#  define HAS_NEWBSD_FD_PASSING
#endif  /*  OS_Darwin  */

/*  The OS should be supported by now  */
#ifndef OS_SUPPORTED
/*  OS has not been supported  */
    !!!! ERROR !!! *** Operating System not supported ****
#endif


/*****************************************************************************
 *  Machine section                                                          *
 *****************************************************************************/

/*  Sun Sparc  */
#ifdef MACHINE_sparc
#  define MACHINE_SUPPORTED
#  define MACHINE_BIG_ENDIAN
#  define HAS_IEEE
#  define CAN_ZERO_CLEAR
#  define Kword16s short
#  define Kword16u unsigned short
#  define Kword32s int
#  define Kword32u unsigned int
#  define NEED_ALIGNED_DATA
#  define IS_ALIGNED(ptr,size) ((uaddr) ptr % size == 0)
#endif

/*  Convex C2  */
#ifdef MACHINE_c2
#define MACHINE_SUPPORTED
#define MACHINE_BIG_ENDIAN
#define HAS_IEEE
#define CAN_ZERO_CLEAR
#define Kword16s short
#define Kword16u unsigned short
#define Kword32s int
#define Kword32u unsigned int
#define IS_ALIGNED(ptr,size) ((uaddr) ptr % size == 0)
#endif

/*  IBM RS/6000  */
#ifdef MACHINE_rs6000
#define MACHINE_SUPPORTED
#define MACHINE_BIG_ENDIAN
#define HAS_IEEE
#define CAN_ZERO_CLEAR
#define Kword16s short
#define Kword16u unsigned short
#define Kword32s int
#define Kword32u unsigned int
#define IS_ALIGNED(ptr,size) ((uaddr) ptr % size == 0)
#endif

/*  MIPS/SGI mips  */
#if defined(MACHINE_mips1) || defined(MACHINE_mips2) || defined(MACHINE_mips3) || defined(MACHINE_mips4)
#  define MACHINE_SUPPORTED
#  define MACHINE_BIG_ENDIAN
#  define HAS_IEEE
#  define CAN_ZERO_CLEAR
#  define Kword16s short
#  define Kword16u unsigned short
#  define Kword32s int
#  define Kword32u unsigned int
#  if defined(MACHINE_mips4)
#    define Kword64s long
#    define Kword64u unsigned long
#  endif
#  define NEED_ALIGNED_DATA
#  define IS_ALIGNED(ptr,size) ((uaddr) ptr % size == 0)
#endif

/*  HP PA-RISC  */
#ifdef MACHINE_hp9000
#define MACHINE_SUPPORTED
#define MACHINE_BIG_ENDIAN
#define HAS_IEEE
#define CAN_ZERO_CLEAR
#define Kword16s short
#define Kword16u unsigned short
#define Kword32s int
#define Kword32u unsigned int
#define NEED_ALIGNED_DATA
#define IS_ALIGNED(ptr,size) ((uaddr) ptr % size == 0)
#endif

/*  Intel ia32 and above  */
#if defined(MACHINE_i386) || defined(MACHINE_i486) || defined(MACHINE_amd64)
#  define MACHINE_SUPPORTED
#  define MACHINE_LITTLE_ENDIAN
#  define HAS_IEEE
#  define CAN_ZERO_CLEAR
#  define Kword16s short
#  define Kword16u unsigned short
#  define Kword32s int
#  define Kword32u unsigned int
#  if defined(MACHINE_amd64)
#    define Kword64s long
#    define Kword64u unsigned long
#  endif
#  define IS_ALIGNED(ptr,size) ((uaddr) ptr % size == 0)
#endif

/*  Cray Parallel Virtual Processor  */
#ifdef MACHINE_crayPVP
#  define MACHINE_SUPPORTED
#  define MACHINE_LITTLE_ENDIAN
#  define CAN_ZERO_CLEAR
#  define Kword64s long
#  define Kword64u unsigned long
#  define NEED_ALIGNED_DATA
#  define IS_ALIGNED(ptr,size) 1
#endif

/*  Digital Alpha  */
#ifdef MACHINE_alpha
#define MACHINE_SUPPORTED
#define MACHINE_LITTLE_ENDIAN
#define HAS_IEEE
#define CAN_ZERO_CLEAR
#define Kword16s short
#define Kword16u unsigned short
#define Kword32s int
#define Kword32u unsigned int
#define Kword64s long
#define Kword64u unsigned long
#define NEED_ALIGNED_DATA
#define IS_ALIGNED(ptr,size) ((uaddr) ptr % size == 0)
#endif

/*  Intel i860  */
#ifdef MACHINE_i860
#define MACHINE_SUPPORTED
#define MACHINE_BIG_ENDIAN
#define HAS_IEEE
#define CAN_ZERO_CLEAR
#define Kword16s short
#define Kword16u unsigned short
#define Kword32s int
#define Kword32u unsigned int
#define IS_ALIGNED(ptr,size) ((uaddr) ptr % size == 0)
#endif

/*  PowerPC  */
#ifdef MACHINE_powerpc
#  define MACHINE_SUPPORTED
#  define MACHINE_BIG_ENDIAN
#  define HAS_IEEE
#  define CAN_ZERO_CLEAR
#  define Kword16s short
#  define Kword16u unsigned short
#  define Kword32s int
#  define Kword32u unsigned int
#  define IS_ALIGNED(ptr,size) ((uaddr) ptr % size == 0)
#endif

/*  The machine should be supported by now  */
#ifndef MACHINE_SUPPORTED
/*  Machine has not been supported  */
    !!!! ERROR !!! *** Machine (CPU type) not supported ****
#endif
/*  IS_ALIGNED should be defined by now  */
#ifndef IS_ALIGNED
    !!!! ERROR !!! *** IS_ALIGNED macro not defined ****
#endif

#ifdef NEED_ALIGNED_DATA
#  define SAFE_ALIGNMENT(ptr,size) (IS_ALIGNED(ptr,size))
#else
#  define SAFE_ALIGNMENT(ptr,size) 1  /*  TRUE: is always safe  */
#endif


#define NET_FLOAT_SIZE 4
#define NET_DOUBLE_SIZE 8

#if __STDC__ == 1
#  define NET_UINT_MAX 4294967295u
#  define NET_INT_MAX (int) 2147483647
#  define NET_INT_MIN (int) -2147483648
#  define NET_USHORT_MAX (unsigned short) 65535
#  define NET_SHORT_MAX (short) 32767
#  define NET_SHORT_MIN (short) -32768
#else
#  define NET_UINT_MAX (unsigned int) 4294967295
#  define NET_INT_MAX (int) 2147483647
#  define NET_INT_MIN (int) -2147483648
#  define NET_USHORT_MAX (unsigned short) 65535
#  define NET_SHORT_MAX (short) 32767
#  define NET_SHORT_MIN (short) -32768
#endif

#if defined(HAS_SYSV_FD_PASSING) || defined(HAS_OLDBSD_FD_PASSING) || \
    defined(HAS_NEWBSD_FD_PASSING)
#  define CAN_PASS_FD
#endif
