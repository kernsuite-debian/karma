/*  karma_iarray.h

    Header for  iarray_  package.

    Copyright (C) 1992-2006  Richard Gooch

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
  needed to interface to the iarray_ routines in the Karma library.


    Written by      Richard Gooch   17-NOV-1992

    Last updated by Richard Gooch   14-AUG-2006

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

#if !defined(KARMA_CH_DEF_H) || defined(MAKEDEPEND)
#  include <karma_ch_def.h>
#endif

#if !defined(KARMA_PSW_DEF_H) || defined(MAKEDEPEND)
#  include <karma_psw_def.h>
#endif

#if !defined(KARMA_WCS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_wcs_def.h>
#endif

#if !defined(KARMA_IARRAY_DEF_H) || defined(MAKEDEPEND)
#  include <karma_iarray_def.h>
#endif

#ifndef KARMA_IARRAY_H
#define KARMA_IARRAY_H


#define REGRID_SAMPLE_DATA_COPY                   0
#define REGRID_SAMPLE_BILINEAR_INTERPOLATION      1

#define SCROLL_UNSET                              0
#define SCROLL_FILL_WITH_BLANKS                   1
#define SCROLL_CIRCULAR                           2

#define IARRAY_MOMENT1_ALGORITHM_WEIGHTED_MEAN    0
#define IARRAY_MOMENT1_ALGORITHM_MEDIAN           1
#define IARRAY_NUM_MOMENT_CHOICES                 2
extern char *iarray_moment_algorithm_alternatives[IARRAY_NUM_MOMENT_CHOICES];


/*  Macros  */

#ifdef DEBUG

/*  1-dimensional  */
#define F1(a, x) ( *(float *) iarray_get_element_1D ( (a), K_FLOAT, (x) ) )
#define D1(a, x) ( *(double *) iarray_get_element_1D ( (a), K_DOUBLE, (x) ) )
#define I1(a, x) ( *(signed int *) iarray_get_element_1D ( (a), K_INT, (x) ) )
#define UI1(a, x) ( *(unsigned int *) iarray_get_element_1D ( (a), K_UINT, (x) ) )
#define S1(a, x) ( *(signed short *) iarray_get_element_1D ( (a), K_SHORT, (x) ) )
#define SI1(a, x) ( *(unsigned short *) iarray_get_element_1D ( (a), K_SHORT, (x) ) )
#define B1(a, x) ( *(signed char *) iarray_get_element_1D ( (a), K_BYTE, (x) ) )
#define UB1(a, x) ( *(unsigned char *) iarray_get_element_1D ( (a), K_UBYTE,(x) ) )
#define CF1_ptr(a, x) ( (float *) iarray_get_element_1D ( (a), K_COMPLEX, (x) ) )

/*  2-dimensional  */
#define F2(a, y, x) ( *(float *) iarray_get_element_2D ( (a), K_FLOAT, (y), (x) ) )
#define D2(a, y, x) ( *(double *) iarray_get_element_2D ( (a), K_DOUBLE, (y), (x) ) )
#define I2(a, y, x) ( *(signed int *) iarray_get_element_2D ( (a), K_INT, (y), (x) ) )
#define UI2(a, y, x) ( *(unsigned int *) iarray_get_element_2D ( (a), K_UINT, (y), (x) ) )
#define S2(a, y, x) ( *(signed short *) iarray_get_element_2D ( (a), K_SHORT, (y), (x) ) )
#define US2(a, y, x) ( *(unsigned short *) iarray_get_element_2D ( (a), K_USHORT, (y), (x) ) )
#define B2(a, y, x) ( *(signed char *) iarray_get_element_2D ( (a), K_BYTE, (y), (x) ) )
#define UB2(a, y, x) ( *(unsigned char *) iarray_get_element_2D ( (a), K_UBYTE, (y), (x) ) )
#define CF2_ptr(a, y, x) ( (float *) iarray_get_element_2D ( (a), K_COMPLEX, (y), (x) ) )

/*  3-dimensional  */
#define F3(a, z, y, x) ( *(float *) iarray_get_element_3D ( (a), K_FLOAT, (z), (y), (x) ) )
#define D3(a, z, y, x) ( *(double *) iarray_get_element_3D ( (a), K_DOUBLE, (z), (y), (x) ) )
#define I3(a, z, y, x) ( *(signed int *) iarray_get_element_3D ( (a), K_INT, (z), (y), (x) ) )
#define UI3(a, z, y, x) ( *(unsigned int *) iarray_get_element_3D ( (a), K_UINT, (z), (y), (x) ) )
#define S3(a, z, y, x) ( *(signed short *) iarray_get_element_3D ( (a), K_SHORT, (z), (y), (x) ) )
#define US3(a, z, y, x) ( *(unsigned short *) iarray_get_element_3D ( (a), K_USHORT, (z), (y), (x) ) )
#define B3(a, z, y, x) ( *(signed char *) iarray_get_element_3D ( (a), K_BYTE, (z), (y), (x) ) )
#define UB3(a, z, y, x) ( *(unsigned char *) iarray_get_element_3D ( (a), K_UBYTE, (z), (y), (x) ) )
#define CF3_ptr(a, z, y, x) ( (float *) iarray_get_element_3D ( (a), K_COMPLEX, (z), (y), (x) ) )

/*  4-dimensional  */
#define F4(a, w, z, y, x) ( *(float *) iarray_get_element_4D ( (a), K_FLOAT, (w), (z), (y), (x) ) )
#define D4(a, w, z, y, x) ( *(double *) iarray_get_element_4D ( (a), K_DOUBLE, (w), (z), (y), (x) ) )
#define I4(a, w, z, y, x) ( *(signed int *) iarray_get_element_4D ( (a), K_INT, (w), (z), (y), (x) ) )
#define UI4(a, w, z, y, x) ( *(unsigned int *) iarray_get_element_4D ( (a), K_INT, (w), (z), (y), (x) ) )
#define S4(a, w, z, y, x) ( *(signed short *) iarray_get_element_4D ( (a), K_SHORT, (w), (z), (y), (x) ) )
#define SI4(a, w, z, y, x) ( *(unsigned short *) iarray_get_element_4D ( (a), K_SHORT, (w), (z), (y), (x) ) )
#define B4(a, w, z, y, x) ( *(signed char *) iarray_get_element_4D ( (a), K_BYTE, (w), (z), (y), (x) ) )
#define UB4(a, w, z, y, x) ( *(unsigned char *) iarray_get_element_4D ( (a), K_UBYTE, (w), (z), (y), (x) ) )
#define CF4_ptr(a, w, z, y, x) ( (float *) iarray_get_element_4D ( (a), K_COMPLEX, (w), (z), (y), (x) ) )

#else  /*  !DEBUG  */

/*  1-dimensional  */
#define F1(a, x) ( *(float *) ( (a)->data + (a)->offsets[0][(x)] ) )
#define D1(a, x) ( *(double *) ( (a)->data + (a)->offsets[0][(x)] ) )
#define I1(a, x) ( *(signed int *) ( (a)->data + (a)->offsets[0][(x)] ) )
#define UI1(a, x) ( *(unsigned int *) ( (a)->data + (a)->offsets[0][(x)] ) )
#define S1(a, x) ( *(signed short *) ( (a)->data + (a)->offsets[0][(x)] ) )
#define SI1(a, x) ( *(unsigned short *) ( (a)->data + (a)->offsets[0][(x)] ) )
#define B1(a, x) ( *(signed char *) ( (a)->data + (a)->offsets[0][(x)] ) )
#define UB1(a, x) ( *(unsigned char *) ( (a)->data + (a)->offsets[0][(x)] ) )
#define CF1_ptr(a, x) ( (float *) ( (a)->data + (a)->offsets[0][(x)] ) )

/*  2-dimensional  */
#define F2(a, y, x) ( *(float *) ( (a)->data + (a)->offsets[0][(y)] + (a)->offsets[1][(x)] ) )
#define D2(a, y, x) ( *(double *) ( (a)->data + (a)->offsets[0][(y)] + (a)->offsets[1][(x)] ) )
#define I2(a, y, x) ( *(signed int *) ( (a)->data + (a)->offsets[0][(y)] + (a)->offsets[1][(x)] ) )
#define UI2(a, y, x) ( *(unsigned int *) ( (a)->data + (a)->offsets[0][(y)] + (a)->offsets[1][(x)] ) )
#define S2(a, y, x) ( *(signed short *) ( (a)->data + (a)->offsets[0][(y)] + (a)->offsets[1][(x)] ) )
#define US2(a, y, x) ( *(unsigned short *) ( (a)->data + (a)->offsets[0][(y)] + (a)->offsets[1][(x)] ) )
#define B2(a, y, x) ( *(signed char *) ( (a)->data + (a)->offsets[0][(y)] + (a)->offsets[1][(x)] ) )
#define UB2(a, y, x) ( *(unsigned char *) ( (a)->data + (a)->offsets[0][(y)] + (a)->offsets[1][(x)] ) )
#define CF2_ptr(a, y, x) ( (float *) ( (a)->data + (a)->offsets[0][(y)] + (a)->offsets[1][(x)] ) )

/*  3-dimensional  */
#define F3(a, z, y, x) ( *(float *) ( (a)->data + (a)->offsets[0][(z)] + (a)->offsets[1][(y)] + (a)->offsets[2][(x)] ) )
#define D3(a, z, y, x) ( *(double *) ( (a)->data + (a)->offsets[0][(z)] + (a)->offsets[1][(y)] + (a)->offsets[2][(x)] ) )
#define I3(a, z, y, x) ( *(signed int *) ( (a)->data + (a)->offsets[0][(z)] + (a)->offsets[1][(y)] + (a)->offsets[2][(x)] ) )
#define UI3(a, z, y, x) ( *(unsigned int *) ( (a)->data + (a)->offsets[0][(z)] + (a)->offsets[1][(y)] + (a)->offsets[2][(x)] ) )
#define S3(a, z, y, x) ( *(signed short *) ( (a)->data + (a)->offsets[0][(z)] + (a)->offsets[1][(y)] + (a)->offsets[2][(x)] ) )
#define US3(a, z, y, x) ( *(unsigned short *) ( (a)->data + (a)->offsets[0][(z)] + (a)->offsets[1][(y)] + (a)->offsets[2][(x)] ) )
#define B3(a, z, y, x) ( *(signed char *) ( (a)->data + (a)->offsets[0][(z)] + (a)->offsets[1][(y)] + (a)->offsets[2][(x)] ) )
#define UB3(a, z, y, x) ( *(unsigned char *) ( (a)->data + (a)->offsets[0][(z)] + (a)->offsets[1][(y)] + (a)->offsets[2][(x)] ) )
#define CF3_ptr(a, z, y, x) ( (float *) ( (a)->data + (a)->offsets[0][(z)] + (a)->offsets[1][(y)] + (a)->offsets[2][(x)] ) )

/*  4-dimensional  */
#define F4(a, w, z, y, x) ( *(float *) ( (a)->data + (a)->offsets[0][(w)] + (a)->offsets[1][(z)] + (a)->offsets[2][(y)] + (a)->offsets[3][(x)] ) )
#define D4(a, w, z, y, x) ( *(double *) ( (a)->data + (a)->offsets[0][(w)] + (a)->offsets[1][(z)] + (a)->offsets[2][(y)] + (a)->offsets[3][(x)] ) )
#define I4(a, w, z, y, x) ( *(signed int *) ( (a)->data + (a)->offsets[0][(w)] + (a)->offsets[1][(z)] + (a)->offsets[2][(y)] + (a)->offsets[3][(x)] ) )
#define UI4(a, w, z, y, x) ( *(unsigned int *) ( (a)->data + (a)->offsets[0][(w)] + (a)->offsets[1][(z)] + (a)->offsets[2][(y)] + (a)->offsets[3][(x)] ) )
#define S4(a, w, z, y, x) ( *(signed short *) ( (a)->data + (a)->offsets[0][(w)] + (a)->offsets[1][(z)] + (a)->offsets[2][(y)] + (a)->offsets[3][(x)] ) )
#define SI4(a, w, z, y, x) ( *(unsigned short *) ( (a)->data + (a)->offsets[0][(w)] + (a)->offsets[1][(z)] + (a)->offsets[2][(y)] + (a)->offsets[3][(x)] ) )
#define B4(a, w, z, y, x) ( *(signed char *) ( (a)->data + (a)->offsets[0][(w)] + (a)->offsets[1][(z)] + (a)->offsets[2][(y)] + (a)->offsets[3][(x)] ) )
#define UB4(a, w, z, y, x) ( *(unsigned char *) ( (a)->data + (a)->offsets[0][(w)] + (a)->offsets[1][(z)] + (a)->offsets[2][(y)] + (a)->offsets[3][(x)] ) )
#define CF4_ptr(a, w, z, y, x) ( (float *) ( (a)->data + (a)->offsets[0][(w)] + (a)->offsets[1][(z)] + (a)->offsets[2][(y)] + (a)->offsets[3][(x)] ) )

#endif  /*  DEBUG  */

/*  Common access macros  */

/*  1-dimensional  */
#define CF1_R(a, x) ( *( CF1_ptr (a, x) ) )
#define CF1_I(a, x) ( *(CF1_ptr (a, x) + 1) )

/*  2-dimensional  */
#define CF2_R(a, y, x) ( *( CF2_ptr (a, y, x) ) )
#define CF2_I(a, y, x) ( *(CF2_ptr (a, y, x) + 1) )

/*  3-dimensional  */
#define CF3_R(a, z, y, x) ( *( CF3_ptr (a, z, y, x) ) )
#define CF3_I(a, z, y, x) ( *(CF3_ptr (a, z, y, x) + 1) )

/*  4-dimensional  */
#define CF4_R(a, w, z, y, x) ( *( CF4_ptr (a, w, z, y, x) ) )
#define CF4_I(a, w, z, y, x) ( *(CF4_ptr (a, w, z, y, x) + 1) )


#define iarray_num_dim(a) (CONST unsigned int) (a)->num_dim
#define iarray_type(a) (a)->arr_desc->packet->element_types[(a)->elem_index]
#define iarray_value_name(a) (a)->arr_desc->packet->element_desc[(a)->elem_index]
#define iarray_elem_index(a) (CONST unsigned int) (a)->elem_index
#define iarray_register_destroy_func(a,func,o) c_register_callback (&(a)->destroy_callbacks, (func), (a), (o), FALSE, NULL, FALSE, FALSE)
#define iarray_multi_array(a) (a)->multi_desc
#define iarray_multi_index(a) (a)->array_num
#define iarray_array_desc(a) (a)->arr_desc
#define iarray_arrayp(a) ((array_pointer *) (*(a)->top_packet + ds_get_element_offset ((a)->top_pack_desc, (a)->top_elem_index)))
#define iarray_register_data_change_func(a,func,o) c_register_callback (&iarray_arrayp((a))->change_callbacks, (func), (o), NULL, FALSE, NULL, FALSE, FALSE)


/*  File:  main.c  */
EXTERN_FUNCTION (iarray iarray_read_nD,
		 (CONST char *arrayfile, flag cache, CONST char *arrayname,
		  unsigned int num_dim, CONST char **dim_names,
		  CONST char *elem_name, unsigned int mmap_option) );
EXTERN_FUNCTION (flag iarray_write, (iarray array, CONST char *arrayfile) );
EXTERN_FUNCTION (iarray iarray_create,
		 (unsigned int type, unsigned int num_dim,
		  CONST char **dim_names, CONST unsigned long *dim_lengths,
		  CONST char *elem_name, iarray old_array) );
EXTERN_FUNCTION (iarray iarray_create2,
		 (unsigned int type, unsigned int num_dim,
		  CONST char **dim_names, CONST unsigned long *dim_lengths,
		  CONST char *elem_name, iarray old_array, flag clear) );
EXTERN_FUNCTION (iarray iarray_get_from_multi_array,
		 (multi_array *multi_desc, CONST char *arrayname,
		  unsigned int num_dim, CONST char **dim_names,
		  CONST char *elem_name) );
EXTERN_FUNCTION (iarray iarray_create_from_array_desc,
		 (array_desc *arr_desc, CONST array_pointer *arrayp,
		  unsigned int elem_index) );
EXTERN_FUNCTION (void iarray_dealloc, (iarray array) );
EXTERN_FUNCTION (void iarray_dealloc2, (iarray array) );
EXTERN_FUNCTION (flag iarray_put_named_value,
		 (iarray array, CONST char *name, unsigned int type,
		  double value[2]) );
EXTERN_FUNCTION (flag iarray_put_named_string,
		 (iarray array, CONST char *name, CONST char *string) );
EXTERN_FUNCTION (flag iarray_get_named_value,
		 (iarray array, CONST char *name, unsigned int *type,
		  double value[2]) );
EXTERN_FUNCTION (char *iarray_get_named_string,
		 (iarray array, CONST char *name) );
EXTERN_FUNCTION (char *iarray_get_element_1D, (iarray array,
					       unsigned int type,
					       int x) );
EXTERN_FUNCTION (char *iarray_get_element_2D, (iarray array,
					       unsigned int type,
					       int y,
					       int x) );
EXTERN_FUNCTION (char *iarray_get_element_3D, (iarray array,
					       unsigned int type,
					       int z,
					       int y,
					       int x) );
EXTERN_FUNCTION (char *iarray_get_element_4D,
		 (iarray array, unsigned int type, int z, int y,int x,int w) );
EXTERN_FUNCTION (iarray iarray_get_sub_array_2D,
		 (iarray array, int starty, int startx,
		  unsigned int ylen, unsigned int xlen) );
EXTERN_FUNCTION (iarray iarray_get_2D_slice_from_3D,
		 (iarray cube, unsigned int ydim, unsigned int xdim,
		  unsigned int slice_pos) );
EXTERN_FUNCTION (iarray iarray_get_sub_array_3D,
		 (iarray array, int startz, int starty, int startx,
		  unsigned int zlen, unsigned int ylen, unsigned int xlen) );
EXTERN_FUNCTION (iarray iarray_get_3D_slice_from_4D,
		 (iarray hcube, unsigned int zdim, unsigned int ydim,
		  unsigned int xdim, unsigned int cube_pos) );
EXTERN_FUNCTION (void iarray_remap_torus, (iarray array,
					   unsigned int boundary_width) );
EXTERN_FUNCTION (unsigned long iarray_dim_length, (iarray array,
						   unsigned int index) );
EXTERN_FUNCTION (CONST char *iarray_dim_name,
		 (iarray array, unsigned int index) );
EXTERN_FUNCTION (void iarray_set_world_coords,
		 (iarray array, unsigned int index,
		  double first, double last) );
EXTERN_FUNCTION (void iarray_get_world_coords,
		 (iarray array, unsigned int index,
		  double *first, double *last) );
EXTERN_FUNCTION (dim_desc *iarray_get_dim_desc, (iarray array,
						 unsigned int index) );
EXTERN_FUNCTION (unsigned int iarray_get_restrictions,
		 (iarray array, char ***restr_names, double **restr_values) );
EXTERN_FUNCTION (flag iarray_is_full_array,
		 (iarray array, flag *all_contiguous) );
EXTERN_FUNCTION (flag iarray_copy_data,
		 (iarray output, iarray input, flag magnitude) );
EXTERN_FUNCTION (flag iarray_compare_sizes,
		 (iarray array1, iarray array2, flag message) );
EXTERN_FUNCTION (flag iarray_clear, (iarray array) );
EXTERN_FUNCTION (flag iarray_fill, (iarray array, double value[2]) );
EXTERN_FUNCTION (flag iarray_min_max, (iarray array, unsigned int conv_type,
				       double *min, double *max) );
EXTERN_FUNCTION (flag iarray_scale_and_offset, (iarray out, iarray inp,
						double *scale,
						double *offset,
						flag magnitude) );
EXTERN_FUNCTION (flag iarray_clip_scale_and_offset,
		 (iarray out, iarray inp, double scale, double offset,
		  double lower_clip, double upper_clip, flag blank) );
EXTERN_FUNCTION (flag iarray_add_and_scale,
		 (iarray out, iarray inp1, iarray inp2, double scale[2],
		  flag magnitude) );
EXTERN_FUNCTION (flag iarray_add_and_scale2,
		 (iarray out, iarray inp1, iarray inp2,
		  double scale[2], double offset[2], flag magnitude) );
EXTERN_FUNCTION (flag iarray_sub_and_scale,
		 (iarray out, iarray inp1, iarray inp2, double scale[2],
		  flag magnitude) );
EXTERN_FUNCTION (flag iarray_multiply_divide,
		 (iarray out, iarray inp1, iarray inp2, flag multiply,
		  double scale[2], double offset[2], flag magnitude) );
EXTERN_FUNCTION (flag iarray_compute_histogram,
		 (iarray array, unsigned int conv_type,
		  double min, double max, unsigned long num_bins,
		  unsigned long *histogram_array,
		  unsigned long *histogram_peak,
		  unsigned long *histogram_mode) );
EXTERN_FUNCTION (flag iarray_sum, (iarray array, double sum[2]) );


/*  File: contour.c  */
EXTERN_FUNCTION (void iarray_contour,
		 (iarray array, unsigned int num_levels,
		  CONST double *contour_levels,
		  uaddr structure_size, uaddr *buffer_sizes,
		  double **x0_arr, double **y0_arr,
		  double **x1_arr, double **y1_arr,
		  uaddr *num_segments) );


/*  File:  get.c  */
EXTERN_FUNCTION (flag iarray_get_image_from_multi,
		 (multi_array *multi_desc, iarray *pseudo,
		  iarray *red, iarray *green, iarray *blue,
		  unsigned int *cmap_index) );
EXTERN_FUNCTION (flag iarray_get_movie_from_multi,
		 (multi_array *multi_desc, iarray *pseudo,
		  iarray *red, iarray *green, iarray *blue,
		  unsigned int *cmap_index) );
EXTERN_FUNCTION (flag iarray_get_nD_from_multi,
		 (multi_array *multi_desc, CONST char *name,
		  unsigned int num_dim, iarray *pseudo,
		  iarray *red, iarray *green, iarray *blue,
		  unsigned int *cmap_index) );


/*  File: matrix.c  */
EXTERN_FUNCTION (flag iarray_matrix_multiply,
		 (iarray out, iarray in1, iarray in2, flag thread) );


/*  File: misc.c  */
EXTERN_FUNCTION (unsigned int iarray_dim_index,
		 (iarray array, CONST char *name) );
EXTERN_FUNCTION (flag iarray_get_data_scaling,
		 (iarray array, double *scale, double *offset) );
EXTERN_FUNCTION (flag iarray_set_data_scaling,
		 (iarray array, double scale, double offset) );
EXTERN_FUNCTION (flag iarray_get_data_range,
		 (iarray array, double *minimum, double *maximum) );
EXTERN_FUNCTION (flag iarray_set_data_range,
		 (iarray array, double minimum, double maximum) );
EXTERN_FUNCTION (void iarray_format_value,
		 (iarray array, char string[STRING_LENGTH], double value,
		  double scale, double offset) );
EXTERN_FUNCTION (iarray iarray_create_from_template,
		 (iarray template_arr, unsigned int elem_type,
		  flag copy_world_coords, flag copy_names,
		  flag copy_aux_info) );
EXTERN_FUNCTION (iarray iarray_create_from_template2,
		 (iarray template_arr, unsigned int elem_type,
		  flag copy_world_coords, flag copy_names,
		  flag copy_aux_info, flag clear) );
EXTERN_FUNCTION (double iarray_get_coordinate,
		 (iarray array, unsigned int dim_index, double coord_index) );
EXTERN_FUNCTION (void iarray_set_dim_name,
		 (iarray array, unsigned int index, CONST char *name,
		  flag new_alloc) );
EXTERN_FUNCTION (flag iarray_append_history_string,
		 (iarray array, CONST char *string, flag new_alloc) );
EXTERN_FUNCTION (flag iarray_copy_named_element,
		 (iarray out, iarray in, CONST char *name,
		  flag fail_if_not_found, flag fail_on_duplicate,
		  flag replace) );
EXTERN_FUNCTION (unsigned int iarray_get_fits_axis,
		 (iarray array, unsigned int index) );
EXTERN_FUNCTION (flag iarray_create_and_setup,
		 (iarray *array, multi_array *multi_desc,
		  flag inform, unsigned int num_dim,
		  unsigned int required_type, double *min, double *max,
		  flag discard_zero_range, KwcsAstro *ap) );
EXTERN_FUNCTION (KwcsAstro iarray_get_associated_wcs_astro, (iarray array) );
EXTERN_FUNCTION (void iarray_set_value_name,
		 (iarray array, CONST char *name, flag new_alloc) );
EXTERN_FUNCTION (flag iarray_find_centroid,
		 (iarray array, double *background, flag *inverted,
		  double *xpos, uaddr xradius, double *ypos, uaddr yradius) );
EXTERN_FUNCTION (flag iarray_copy_attached,
		 (iarray output, iarray input, flag fail_on_duplicate,
		  flag replace) );
EXTERN_FUNCTION (flag iarray_compare_grids_2D,
		 (iarray array1, unsigned int hdim1, unsigned int vdim1,
		  iarray array2, unsigned int hdim2, unsigned int vdim2,
		  flag *same) );
EXTERN_FUNCTION (double iarray_get_beam_correction,
		 (iarray array, unsigned int dim1, unsigned int dim2) );
EXTERN_FUNCTION (void iarray_register_data_change,
		 (iarray array, void *call_data) );
EXTERN_FUNCTION (void iarray_get_values,
		 (iarray array, CONST uaddr *coords, double *values,
		  flag *complex, unsigned int num_values) );


/*  File:  moment.c  */
EXTERN_FUNCTION (flag iarray_moment_compute,
		 (iarray mom0, iarray mom1, iarray cube,
		  float lower_clip, float sum_clip,
		  unsigned int moment1_algorithm,
		  unsigned int start_z, unsigned int stop_z,
		  float *mom0_min, float *mom0_max) );
EXTERN_FUNCTION (flag iarray_moment_create,
		 (iarray *mom0, iarray *mom1, iarray cube) );


/*  File:  ps.c  */
EXTERN_FUNCTION (flag iarray_write_mono_ps,
		 (iarray image, PostScriptPage pspage,
		  double xstart, double ystart, double xend, double yend,
		  flag iscale) );
EXTERN_FUNCTION (flag iarray_write_pseudocolour_ps,
		 (iarray image, PostScriptPage pspage,
		  double xstart, double ystart, double xend, double yend,
		  unsigned short *cmap, unsigned int cmap_size) );
EXTERN_FUNCTION (flag iarray_write_rgb_ps,
		 (iarray image_red, iarray image_green, iarray image_blue,
		  PostScriptPage pspage,
		  double xstart, double ystart, double xend, double yend) );


/*  File: regrid.c  */
EXTERN_FUNCTION (flag iarray_regrid_2D,
		 (iarray out_arr, KwcsAstro out_ap,
		  iarray in_arr, KwcsAstro in_ap,
		  unsigned int sample_option, float *min, float *max,
		  flag verbose) );
EXTERN_FUNCTION (flag iarray_regrid_3D,
		 (iarray out_arr, KwcsAstro out_ap,
		  iarray in_arr, KwcsAstro in_ap,
		  unsigned int sample_option, float *min, float *max,
		  flag verbose) );


/*  File: scroll.c  */
EXTERN_FUNCTION (void iarray_scroll,
		 (iarray array, unsigned long num_to_scroll,
		  unsigned int scroll_mode) );


/*  File: transform.c  */
EXTERN_FUNCTION (void iarray_rect_to_polar,
		 (iarray out, iarray in, double centre_x, double centre_y,
		  double radius_major, double radius_minor, double rotation) );
EXTERN_FUNCTION (flag iarray_transform_3D,
		 (iarray out_arr, KwcsAstro out_ap,
		  iarray in_arr, KwcsAstro in_ap,
		  void (*func) (void *info, unsigned long length,
				double *x, double *y, double *z),
		  void *info) );
EXTERN_FUNCTION (flag iarray_untransform_3D,
		 (iarray out_arr, KwcsAstro out_ap,
		  iarray in_arr, KwcsAstro in_ap,
		  void (*func) (void *info, unsigned long length,
				double *x, double *y, double *z),
		  void *info) );


/*  File:  wrappers.c  */
EXTERN_FUNCTION (iarray iarray_create_1D,
		 (unsigned long xlen, unsigned int type) );
EXTERN_FUNCTION (iarray iarray_create_2D,
		 (unsigned long ylen, unsigned long xlen, unsigned int type) );
EXTERN_FUNCTION (iarray iarray_create_3D,
		 (unsigned long zlen, unsigned long ylen, unsigned long xlen,
		  unsigned int type) );
EXTERN_FUNCTION (iarray iarray_create_4D,
		 (unsigned long zlen, unsigned long ylen,
		  unsigned long xlen, unsigned int wlen, unsigned int type) );
EXTERN_FUNCTION (iarray iarray_create_shm,
		 (unsigned int type, unsigned int num_dim,
		  CONST char **dim_names, CONST uaddr *dim_lengths,
		  CONST char *elem_name, flag force) );
EXTERN_FUNCTION (flag iarray_put_double,
		 (iarray array, CONST char *name, double value) );
EXTERN_FUNCTION (flag iarray_put_float,
		 (iarray array, CONST char *name, float value) );
EXTERN_FUNCTION (flag iarray_put_int,
		 (iarray array, CONST char *name, int value) );
EXTERN_FUNCTION (flag iarray_get_double,
		 (iarray array, CONST char *name, double *value,
		  flag abort_on_error) );
EXTERN_FUNCTION (float iarray_get_float, (iarray array, CONST char *name) );
EXTERN_FUNCTION (int iarray_get_int, (iarray array, CONST char *name) );
EXTERN_FUNCTION (flag iarray_fill_double, (iarray array, double value) );
EXTERN_FUNCTION (flag iarray_fill_float, (iarray array, float value) );
EXTERN_FUNCTION (flag iarray_fill_int, (iarray array, int value) );
EXTERN_FUNCTION (flag iarray_min_max_float, (iarray array,
					     float *min, float *max) );
EXTERN_FUNCTION (flag iarray_min_max_int, (iarray array,
					   int *min, int *max) );
EXTERN_FUNCTION (flag iarray_scale_and_offset_float, (iarray out, iarray inp,
						      float scale,
						      float offset) );
EXTERN_FUNCTION (flag iarray_scale_and_offset_int, (iarray out, iarray inp,
						    int scale, int offset) );


#endif /*  KARMA_IARRAY_H  */
