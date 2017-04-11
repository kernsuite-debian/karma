/*  karma_ds_def.h

    Header for  ds_  package. This file ONLY contains the macro definitions

    Copyright (C) 1992-1998  Richard Gooch

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

    This include file contains all the macro definitions for the data
    structure in the Karma library.


    Written by      Richard Gooch   13-SEP-1992

    Last updated by Richard Gooch   24-FEB-1998

*/
#ifndef KARMA_DS_VAL_H
#define KARMA_DS_VAL_H


/*  The following list defines the keyword constants for the various data types
  supported by the general data structure.
*/
#define NONE                    0
#define K_FLOAT                 1
#define K_DOUBLE                2
#define K_BYTE                  3
#define K_INT                   4
#define K_SHORT                 5
/*#define ARRAYP                 6    Obsolete: unpadded, untiled array*/
#define LISTP                   7
#define MULTI_ARRAY             8
#define K_COMPLEX               9
#define K_DCOMPLEX              10
#define K_BCOMPLEX              11
#define K_ICOMPLEX              12
#define K_SCOMPLEX              13
#define K_LONG                  14
#define K_LCOMPLEX              15
#define K_UBYTE                 16
#define K_UINT                  17
#define K_USHORT                18
#define K_ULONG                 19
#define K_UBCOMPLEX             20
#define K_UICOMPLEX             21
#define K_USCOMPLEX             22
#define K_ULCOMPLEX             23
#define K_ARRAY                 24  /*  Padded, tiled array  */
#define K_VSTRING               25  /*  Variable allocation length string  */
#define K_FSTRING               26  /*  Fixed allocation length string     */

#define NUMTYPES                27

#define K_UB_RGB                27  /*  Not generally supported yet        */

/*  These are the return values from the routine  identify_name */
#define IDENT_NOT_FOUND         0  /*  Name not found                  */
#define IDENT_GEN_STRUCT        1  /*  Name of general data structure  */
#define IDENT_DIMENSION         2  /*  Name of dimension               */
#define IDENT_ELEMENT           3  /*  Name of atomic data element     */
#define IDENT_MULTIPLE          4  /*  Name has multiple occurrences   */

/*  These are the bias values to use for the routine  get_coord_num  */
#define SEARCH_BIAS_LOWER       0
#define SEARCH_BIAS_CLOSEST     1
#define SEARCH_BIAS_UPPER       2

/*  These are the conversion specifier values used in  find_single_extremes
    and other places (such as  kplot  and  kimage  )  */

#define CONV_CtoR_REAL          10
#define CONV_CtoR_IMAG          11
#define CONV_CtoR_ABS           12
#define CONV_CtoR_SQUARE_ABS    13
#define CONV_CtoR_PHASE         14
#define CONV_CtoR_CONT_PHASE    15
#define CONV_CtoR_ENVELOPE      16

#define CONV1_REAL              CONV_CtoR_REAL
#define CONV1_IMAG              CONV_CtoR_IMAG
#define CONV1_COMPLEX           2
#define CONV1_ABS               CONV_CtoR_ABS
#define CONV1_SQUARE_ABS        CONV_CtoR_SQUARE_ABS
#define CONV1_PHASE             CONV_CtoR_PHASE
#define CONV1_CONT_PHASE        CONV_CtoR_CONT_PHASE
#define CONV1_ENVELOPE          CONV_CtoR_ENVELOPE
#define NUM_CONV1_ALTERNATIVES  8


/*  These defines are used for the sorting routines  */
#define SORT_UNDEF              0x00
#define SORT_INCREASING         0x01
#define SORT_DECREASING         0x02
#define SORT_RANDOM             0x03


/*  These constants are various magic numbers used for safety  */
#define MAGIC_MULTI_ARRAY       1348278593
#define MAGIC_LIST_HEADER       1578423466


/*  These are the constants for the array pointer memory type  */
#define K_ARRAY_MEM_TYPE_NORMAL 0
#define K_ARRAY_MEM_TYPE_SHM    1
#define K_ARRAY_MEM_TYPE_MMAP   2


#endif /*  KARMA_DS_VAL_H  */
