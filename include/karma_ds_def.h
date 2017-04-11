/*  karma_ds_struct.h

    Header for  ds_  package. This file ONLY contains the structure definitions

    Copyright (C) 1992-2003  Richard Gooch

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

    This include file contains all the structure definitions for the data
    structure in the Karma library.


    Written by      Richard Gooch   13-SEP-1992

    Updated by      Richard Gooch   12-MAY-1998

    Updated by      Richard Gooch   6-FEB-2003: Added <<free>> to list_header.

    Last updated by Richard Gooch   11-AUG-2003: Added <<change_callbacks>> to
  array_pointer.

*/

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#if !defined(KARMA_C_DEF_H) || defined(MAKEDEPEND)
#  include <karma_c_def.h>
#endif

#if !defined(KARMA_J_DEF_H) || defined(MAKEDEPEND)
#  include <karma_j_def.h>
#endif

#ifndef KARMA_DS_DEF_H
#define KARMA_DS_DEF_H


typedef struct _array_pointer
{
    char *array;               /* A pointer to the array data                */
    void (*free)               /* The function to call to free the data      */
	 (void *info, struct _array_pointer *arrayp);
    void *info;                /* The pointer to pass to the free function   */
    KCallbackList change_callbacks;/* Callback list called upon data change  */
    unsigned char mem_type;    /* Memory type (eg. K_ARRAY_MEM_TYPE_NORMAL)  */
    union
    {
	struct
	{
	    int shmid;         /* The shared memory segment ID               */
	    void *base;        /* The address where the segment was attached */
	} shm;
	struct
	{
	    int fd;            /* File descriptor of mapped region           */
	    uaddr size;        /* Size of mapped region                      */
	    void *base;        /* The address where the region was mapped    */
	} mmap;
    } u;
} array_pointer;


/*  This is the header structure defining a data packet. There may be any
    number of data elements of varying types in a data packet.
*/
typedef struct
{
    unsigned int num_elements;  /*  The number of data elements in a
                                    data packet                         */
    unsigned int *element_types;/*  An array specifying the data type
                                    of each data element                */
    char **element_desc;        /*  An array of string pointers         */
} packet_desc;

/*  This is the history structure  */
typedef struct _history
{
    char *string;
    struct _history *next;
} history;

/*  This is the header structure which points to a number of independent,
    but somehow associated, general data structures.
*/
typedef struct
{
    unsigned int num_arrays;        /*  Number of multi-dimensional arrays  */
    char **array_names;             /*  An array of string pointers (NULL
					if only one array)                  */
    packet_desc **headers;          /*  An array of pointers to
                                        multi-dimensional array headers     */
    char **data;                    /*  An array of pointers to the data    */
    history *first_hist;            /*  Pointer to first history entry      */
    history *last_hist;             /*  Pointer to last history entry       */
    KCallbackList destroy_callbacks;/*  Callback list called upon dealloc   */
    unsigned int attachments;       /*Counter of attachments: 0 == deleteable*/
    unsigned int magic_number;      /*  Magic number                        */
    KJoinedPairList jlist;          /*  PRIVATE                             */
    KJoinedPairList *jlists;        /*  PRIVATE                             */
} multi_array;



/*  This is the header structure defining a single dimension.
*/
typedef struct
{
    char *name;             /*  Name of the dimension                    */
    unsigned long length;   /*  Number of dimension co-ordinates         */
    double first_coord;     /*  First co-ordinate                        */
    double last_coord;      /*  Last co-ordinate                         */
    double minimum;         /*  OBSOLETE: will be removed in Karma v2.0  */
    double maximum;         /*  OBSOLETE: will be removed in Karma v2.0  */
    double *coordinates;    /*  Array of dimension co-ordinates          */
} dim_desc;


/*  This is the header structure defining a multi-dimensional array of
    (possibly) tiled data packets.
*/
typedef struct
{
    unsigned int num_dimensions;    /*  Number of dimensions in this array   */
    dim_desc **dimensions;          /*  An array of pointers to
                                        dimension descriptors                */
    unsigned int num_levels;        /*  Number of levels of tiling
					0 corresponds to a plain array       */
    unsigned int **tile_lengths;    /*  Pointer to array of tile length arrays,
					one tile length array per dimension  */
    uaddr *lengths;                 /*  Pointer to array of lengths of lowest
					array (tile)                         */
    uaddr **offsets;                /*  Pointer to array of offset arrays,
					one offset array per dimension       */
    packet_desc *packet;            /*  A pointer to a header to describe
                                        the data types to be stored          */
    flag padded;                    /*  PRIVATE: don't touch                 */
} array_desc;


/*  This structure is one entry in a linked list. Athough the entries in the
    list (the  list_entry  items) might be contiguous, the actual data
    is not.
*/
typedef struct _list_entry
{
    struct _list_entry *prev;    /*  Pointer to the previous entry in the
				     linked list                             */
    struct _list_entry *next;    /*  Pointer to the next entry in the
				     linked list                             */
    char *data;                  /*  Pointer to the data                     */
} list_entry;


/*  This structure defines the entry into a linked list of data packets.
    The list has  .length  entries.
    The list divided into 2 sections: a block of contiguous data followed
    (logically) by a number of fragmented (doubly linked) list entries.
    There are NO  list_entry  structures for the contiguous section, the list
    structure is implied.
    If  .contiguous_length  is greater than 0, then there are that many data
    packets which are contiguous in memory.
    The start of the contiguous data is pointed to by  .contiguous_data
    The first fragmented list entry is pointed to by  .first_frag_entry
    The last fragmented list entry is pointed to by  .last_frag_entry
*/
typedef struct
{
    unsigned int magic;
    unsigned long length;           /*  Number of entries in the linked list */
    unsigned int contiguous_length; /*  Number of contiguous entries at start
					of list                              */
    unsigned int sort_type;         /*  Sorting type of this list            */
    unsigned int sort_elem_num;     /*  Number of the element sorted by      */
    char *contiguous_data;          /*  Pointer to start of contiguous data
					NULL if no contiguous data           */
    list_entry *first_frag_entry;   /*  Pointer to the start of the fragmented
					list                                 */
    list_entry *last_frag_entry;    /*  Pointer to the end of the fragmented
					list                                 */
    void (*free) (void *info);      /*  Optional function to call on dealloc */
    void *info;                     /*  The pointer to pass to <<free>>      */
} list_header;

/*  This structure is used for the drawing routines.  */
typedef struct
{
    double abscissa;
    double ordinate;
} edit_coord;

/*  This is the Karma Fixed String structure.  */
typedef struct
{
    char *string;                   /*  Pointer to the string characters     */
    unsigned int max_len;           /*  Size of the string buffer            */
} FString;



/*          How it all ties in together.

    The individual data arrays listed in the structure  multi_array  have two
    entries each in the structure. One entry points to the data for that array
    structure, and the other points to a header specifying the data packet to
    be stored in the data field.

    A data packet is a collection of data elements, which may have an umlimited
    number of elements and varying types of data elements.

    Data elements fall into two categories: named and unnamed.
    A named element may be atomic (C data: numeric) such as float, double, int,
    char, complex, dcomplex etc., or a non-atomic type such as a variable or
    fixed string. All named elements are not recursive.
    An unnamed element recursively points to a sub-structure, such as a pointer
    to an array or a linked list.

    The  packet_desc  is a descriptor for a data packet. It contains the
    number of data elements, their respective types and a descriptor for each
    data element.
    For named data elements, the descriptor is a character string naming the
    data element.
    For an array data element, the desciptor is an array descriptor of type
    array_desc  .
    For a linked list data element, the descriptor is a linked list descriptor
    which is a  packet_desc  which describes the data packets to be stored in
    the linked list.

    The array descriptor contains information on the number of dimensions in
    the array, an array of pointers to dimension descriptors (type
    dim_desc  ) for the dimensions and a descriptor for the data packets
    which will be stored at each point in the array.
    The array descriptor also contains (optional) tiling information.

    The dimension descriptor (type  dim_desc  ) contains the name of the
    dimension, the length of the dimension (number of dimension co-ordinates),
    the minimum and maximum co-ordinates, and an (optional) array of dimension
    co-ordinates.
    If the co-ordinates are regularly spaced, the array pointer will be NULL,
    in order to save space (as the co-ordinates may be computed), else the
    co-ordinates will be present.
    A NULL pointer indicates regularly spaced co-ordinates.

    A data packet is stored in memory in a contiguous block, with the data
    element numbered zero occuring in lower memory.

    A data element which is a pointer to an array points to the first data
    packet of that multi-dimensional array. The array is indexed least
    significantly (minumum change in memory address) by the last dimension
    specified in the list in the relevant  array_desc  header.
    An array of data packets is stored contiguously in memory.

    A data element which is a pointer to a linked list is a pointer to a
    linked list header (type  list_header  ). Note that the length of each
    linked list in a data packet need not be the same. Also, each instantiation
    of the list may have a different length.
    Neither are the list packets necessarily all contiguous or all
    non-contiguous.
    The sorting order of the linked list is given in it's header, as well as
    the number of the element in the data packets (defined in the linked list
    descriptor) the list is sorted by. If the list is not sorted (value
    SORT_RANDOM), the element number should be set to the number of elements in
    the data packets of the linked list. The sorting order is preserved during
    the saving and loading phases.
*/


#endif /*  KARMA_DS_DEF_H  */
