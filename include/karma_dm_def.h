/*  karma_dm_def.h

    Header for  dm_  package. This file ONLY contains the object definitions

    Copyright (C) 1998-1999  Richard Gooch

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

    This include file contains all the definitions for the dm_ routines in the
    Karma library.


    Written by      Richard Gooch   18-FEB-1998

    Last updated by Richard Gooch   28-JUN-1999

*/

#ifndef KARMA_DM_DEF_H
#define KARMA_DM_DEF_H


typedef struct managed_descriptor_type * KManagedDescriptor;


/*  Event types for varargs  */
#define KARMA_FD_EVENT_END           0
#define KARMA_FD_EVENT_INPUT         1
#define KARMA_FD_EVENT_OUTPUT        2
#define KARMA_FD_EVENT_EXCEPTION     3
#define KARMA_FD_EVENT_CLOSE         4
#define KARMA_FD_EVENT_INODE_WRITE   5


#endif /*  KARMA_DM_DEF_H  */
