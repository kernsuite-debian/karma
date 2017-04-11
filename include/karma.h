/*
    Various definitions for Karma.

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


/*-----------------------------------------------------------*
 *     This file contains some useful macros, definitions    *
 *     and functions that no program should be without       *
 *     (at least in my opinion :-)                           *
 *-----------------------------------------------------------*/

#ifndef KARMA_H
#define KARMA_H

/*-----------------------------------------------------------*
 *     Logical variables and definitions                     *
 *-----------------------------------------------------------*/

typedef int flag;

#ifdef TRUE
#  undef TRUE
#endif
#define TRUE 1
#ifdef FALSE
#  undef FALSE
#endif
#define FALSE 0

/*-----------------------------------------------------------*
 *     Integer types same size as pointers                   *
 *-----------------------------------------------------------*/

typedef long iaddr;
typedef unsigned long uaddr;

/*-----------------------------------------------------------*
 *     Definition of NULL                                    *
 *-----------------------------------------------------------*/

#ifndef NULL
#  define NULL (void *)0
#endif

/*-----------------------------------------------------------*
 *     PI Definitions                                        *
 *-----------------------------------------------------------*/

#ifndef PI
#  define PI 3.14159265358979323846
#endif
#define PI_ON_2 (PI * 0.5)
#define TWO_PI (PI * 2.0)
#define PION180 (PI / 180.0)
#define TWOPI TWO_PI

/*-----------------------------------------------------------*
 *   Some other numerical definitions                        *
 *-----------------------------------------------------------*/

#define TOOBIG  1.0e30
#define DOUBLE_IS_VALID(val) (val < TOOBIG)
#define DOUBLE_IS_BLANK(val) (!(val < TOOBIG))

/*-----------------------------------------------------------*
 *  Some useful lengths                                      *
 *-----------------------------------------------------------*/

#define STRING_LENGTH 255
#define K_SIZE 1024
#define M_SIZE 1048576
#define SPACE_LENGTH 21
#define TABWIDTH 8
#define PAGE_LENGTH 60

/*-----------------------------------------------------------*
 *  Other handy macros                                       *
 *-----------------------------------------------------------*/

#define swap(a,b,t)  {t = a; a = b; b = t;}

/*-----------------------------------------------------------*
 *  These are the standard return values (returned by  exit) *
 *-----------------------------------------------------------*/

#define RV_OK                    0
#define RV_BAD_PARAM             1
#define RV_MISSING_PARAM         2
#define RV_TOO_MANY_PARAM        3
#define RV_BAD_OPTION            4
#define RV_FILE_NOT_FOUND        5
#define RV_CANNOT_OPEN           6
#define RV_READ_ERROR            7
#define RV_WRITE_ERROR           8
#define RV_MEM_ERROR             9
#define RV_SYS_ERROR             10
#define RV_BAD_DATA              11
#define RV_PROGRAM_BUG           12
#define RV_BAD_FILE_TYPE         13
#define RV_CONTROL_C             14
#define RV_ABORT                 15
#define RV_UNKNOWN_FORMAT        16
#define RV_EXECUTABLE_NOT_FOUND  17
#define RV_UNDEF_ERROR           1023

/*-----------------------------------------------------------*
 *     Wait for keypress                                     *
 *-----------------------------------------------------------*/

#define PAUSE do{char i[20];gets(i);}while(0)


/*-----------------------------------------------------------*
 *     Test macro for  flag  type                            *
 *-----------------------------------------------------------*/

#define FLAG_VERIFY(bool) if ( (bool != TRUE) && (bool != FALSE) ) \
                          {fprintf (stderr, "%s: Bad flag value: %d\n",\
				    function_name, bool); \
			   fprintf (stderr, "Aborting.%c\n", BEL);  \
			   abort ();  \
		          }

/*-----------------------------------------------------------*
 *     Define some ASCII values                              *
 *-----------------------------------------------------------*/

#define BEL 7
#define BS 8
#define HT 9
#define LF 10
#define VT 11
#define FF 12
#define CR 13
#define ESC 27
#define DEL 127

/*----------------------------------------------------------*
 *   Convenience macro for accessing syserror(errno)        *
 *----------------------------------------------------------*/

/*  I do all this trickery so that when compiling under the Karma environment,
    the test is always correct. If not compiling under Karma, the test can
    falsely succeed for Solaris if not using gcc. The false positive is not
    dangerous in this context, however.
    All this has to be done because SunOS is broken: the strerror(3) function
    is not available.
*/
#ifndef ERRSTRING
#  if defined(OS_SunOS) || (defined(sun) && !defined(__svr4__) && !defined(OS_Solaris))
extern char *sys_errlist[];
#    define STRERROR(en) sys_errlist[(en)]
#    define ERRSTRING sys_errlist[errno]
#  else
#    define STRERROR(en) strerror((en))
#    define ERRSTRING strerror (errno)
#  endif
#endif

/*----------------------------------------------------------*
 *   Define EXTERN_FUNCTION and CONST                       *
 *----------------------------------------------------------*/
#ifndef EXTERN_FUNCTION
#  ifdef __cplusplus
#    define EXTERN_FUNCTION( rtn, args ) extern "C" { rtn args; }
#    define CONST const
#  else
#    ifdef c_plusplus
#      define EXTERN_FUNCTION( rtn, args ) rtn args
#      define CONST const
#    else
#      if defined(__STDC__) || defined(__stdc__)
#        define EXTERN_FUNCTION( rtn, args ) extern rtn args
#        define CONST const
#      else
#        define EXTERN_FUNCTION( rtn, args ) extern rtn()
#        define CONST
#      endif
#    endif
#  endif
#endif

/*---------------------------------------------------------*
 *   Define STATIC_FUNTION (C only)                        *
 *---------------------------------------------------------*/
#ifndef STATIC_FUNCTION
#  ifdef __cplusplus
#    define STATIC_FUNCTION( rtn, args ) extern "C" { static rtn args; }
#  else
#    ifdef c_plusplus
#      define STATIC_FUNCTION( rtn, args ) static rtn args
#    else
#      if defined(__STDC__) || defined(__stdc__)
#        define STATIC_FUNCTION( rtn, args ) static rtn args
#      else
#        define STATIC_FUNCTION( rtn, args ) static rtn()
#      endif
#    endif
#  endif
#endif

/*-----------------------------------------------------------*
 *     Multi-threading macros                                *
 *-----------------------------------------------------------*/
#ifdef OS_Solaris
#  ifndef _REENTRANT
    !!!! ERROR !!! *** _REENTRANT not defined for Solaris 2 ****
#  endif
#endif
#ifdef OS_IRIX5
#  ifndef _SGI_MP_SOURCE
    !!!! ERROR !!! *** _SGI_MP_SOURCE not defined for IRIX ****
#  endif
#endif

/*-----------------------------------------------------------*/

#endif  /*  KARMA_H  */
