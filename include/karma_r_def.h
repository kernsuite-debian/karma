/*  karma_r_def.h

    Header for  r_  package. This file ONLY contains the object definitions

    Copyright (C) 1998  Richard Gooch

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

    This include file contains all the definitions for the r_ routines in the
    Karma library.


    Written by      Richard Gooch   12-FEB-1998

    Last updated by Richard Gooch   12-DEC-1998

*/

#ifndef KARMA_R_DEF_H
#define KARMA_R_DEF_H


struct karma_traffic_parameters
{
    unsigned char traffic_class;
    int rate_min;    /*  Minimum transfer rate, bytes per second             */
    int rate_typ;    /*  Typical transfer rate, bytes per second             */
    int rate_max;    /*  Maximum transfer rate, bytes per second             */
    int sdu_max;     /*  Maximum service Data Unit (datagram size), bytes    */
    int dv_max;      /*  Maximum delay variation per byte, nanoseconds       */
};

struct karma_qos
{
    struct karma_traffic_parameters tx;
    struct karma_traffic_parameters rx;
};


#endif /*  KARMA_R_DEF_H  */
