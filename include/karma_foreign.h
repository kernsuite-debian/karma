/*  karma_foreign.h

    Header for  foreign_  package.

    Copyright (C) 1996-2005  Richard Gooch

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
  needed to interface to the foreign_ routines in the Karma library.


    Written by      Richard Gooch   15-APR-1995

    Last updated by Richard Gooch   24-DEC-2005

*/

#include <sys/types.h>

#if !defined(KARMA_IARRAY_DEF_H) || defined(MAKEDEPEND)
#  include <karma_iarray_def.h>
#endif

#if !defined(KARMA_WCS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_wcs_def.h>
#endif

#if !defined(KARMA_DS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_ds_def.h>
#endif

#if !defined(KARMA_CH_DEF_H) || defined(MAKEDEPEND)
#  include <karma_ch_def.h>
#endif

#ifndef KARMA_FOREIGN_H
#define KARMA_FOREIGN_H

typedef struct aips1_data_context_type * KAIPS1DataContext;
typedef struct drao_data_context_type * KDRAODataContext;
typedef struct miriad_data_context_type * KMiriadDataContext;
typedef struct gildas_data_context_type * KGILDASDataContext;


#define FA_PPM_WRITE_END                     0


#define FA_PPM_READ_END                      0
#define FA_PPM_READ_BINARY                   1


#define FA_PGM_READ_END                      0
#define FA_PGM_READ_BINARY                   1


#define FA_FITS_READ_HEADER_END              0
#define FA_FITS_READ_HEADER_ALLOW_TRUNC      1
#define FA_FITS_READ_HEADER_SIMPLE           2
#define FA_FITS_READ_HEADER_PARTIAL          3
#define FA_FITS_READ_HEADER_DATA_BYTES       4

#define FA_FITS_READ_DATA_END                0
#define FA_FITS_READ_DATA_NUM_BLANKS         1
#define FA_FITS_READ_DATA_SKIP_BLOCKS        2
#define FA_FITS_READ_DATA_ASCII              3

#define FA_FITS_READ_END                     0
#define FA_FITS_READ_NUM_BLANKS              1
#define FA_FITS_READ_MMAP_OPTION             2
#define FA_FITS_READ_WRITABLE                3
#define FA_FITS_READ_SIMPLE                  4
#define FA_FITS_READ_SKIP_DATA               5
#define FA_FITS_READ_PARTIAL                 6


#define FA_FITS_GENERATE_HEADER_END          0


#define FA_FITS_WRITE_END                    0

#define FA_FITS_WRITE_DATA_END               0


#define FA_MIRIAD_READ_HEADER_END            0

#define FA_MIRIAD_READ_DATA_END              0
#define FA_MIRIAD_READ_DATA_NUM_BLANKS       1
#define FA_MIRIAD_READ_DATA_NUM_MASKED       2
#define FA_MIRIAD_READ_DATA_SKIP_BLOCKS      3

#define FA_MIRIAD_READ_END                   0
#define FA_MIRIAD_READ_NUM_BLANKS            1
#define FA_MIRIAD_READ_MMAP_OPTION           2
#define FA_MIRIAD_READ_WRITABLE              3


#define FA_MIRIAD_WRITE_END                  0
#define FA_MIRIAD_WRITE_EXTRA_HISTORY        1


#define FA_GIPSY_READ_HEADER_END             0
#define FA_GIPSY_READ_HEADER_PARTIAL         1
#define FA_GIPSY_READ_HEADER_DATA_BYTES      2

#define FA_GIPSY_READ_DATA_END               0
#define FA_GIPSY_READ_DATA_NUM_BLANKS        1
#define FA_GIPSY_READ_DATA_SKIP_BLOCKS       2

#define FA_GIPSY_READ_END                    0
#define FA_GIPSY_READ_NUM_BLANKS             1
#define FA_GIPSY_READ_PARTIAL                2


#define FA_GIPSY_WRITE_END                   0


#define FA_GIPSY_WRITE_HEADER_END            0


#define FA_GIPSY_WRITE_DATA_END              0


#define FA_GUESS_READ_END                    0
#define FA_GUESS_READ_FITS_TO_FLOAT          1
#define FA_GUESS_READ_PARTIAL                2


#define FA_GUESS_WRITE_END                   0


#define FA_SUNRAS_READ_END                   0


#define FA_SUNRAS_WRITE_END                  0
#define FA_SUNRAS_WRITE_NO_IMAGE             1


#define FA_IDF_READ_HEADER_END               0

#define FA_IDF_READ_DATA_END                 0
#define FA_IDF_READ_DATA_NUM_BLANKS          1
#define FA_IDF_READ_DATA_SKIP_BLOCKS         2

#define FA_IDF_READ_END                      0
#define FA_IDF_READ_NUM_BLANKS               1


#define FA_DRAO_READ_HEADER_END              0
#define FA_DRAO_READ_HEADER_PARTIAL          1

#define FA_DRAO_READ_END                     0
#define FA_DRAO_READ_PARTIAL                 1


#define FOREIGN_FILE_FORMAT_KARMA            0
#define FOREIGN_FILE_FORMAT_UNKNOWN          1
#define FOREIGN_FILE_FORMAT_PPM              2
#define FOREIGN_FILE_FORMAT_FITS             3
#define FOREIGN_FILE_FORMAT_SUNRAS           4
#define FOREIGN_FILE_FORMAT_MIRIAD           5
#define FOREIGN_FILE_FORMAT_GIPSY            6
#define FOREIGN_FILE_FORMAT_PGM              7
#define FOREIGN_FILE_FORMAT_DRAO             8
#define FOREIGN_FILE_FORMAT_AIPS1            9
#define FOREIGN_FILE_FORMAT_PNM             10
#define FOREIGN_FILE_FORMAT_FILTER_KARMA    11
#define FOREIGN_FILE_FORMAT_FILTER_FITS     12
#define FOREIGN_FILE_FORMAT_FILTER_PNM      13
#define FOREIGN_FILE_FORMAT_EMPTY_FITS      14
#define FOREIGN_FILE_FORMAT_SIMPLE_FITS     15
#define FOREIGN_FILE_FORMAT_IDF             16
#define FOREIGN_FILE_FORMAT_GILDAS          17


/*  File:  aips1_read.c  */
EXTERN_FUNCTION (CONST char *foreign_aips1_read_dataset_names,
		 (CONST char *dirname, unsigned int *num_datasets) );
EXTERN_FUNCTION (multi_array *foreign_aips1_read, (CONST char *setname) );
EXTERN_FUNCTION (multi_array *foreign_aips1_read_header,
		 (CONST char *setname, flag data_alloc,
		  KAIPS1DataContext *context) );
EXTERN_FUNCTION (flag foreign_aips1_read_data,
		 (KAIPS1DataContext context, char *data, uaddr num_values) );
EXTERN_FUNCTION (flag foreign_aips1_read_history,
		 (KAIPS1DataContext context, multi_array *multi_desc) );
EXTERN_FUNCTION (void foreign_aips1_close_data_context,
		 (KAIPS1DataContext context) );

/*  File:  aips2_read.c  */
EXTERN_FUNCTION (flag foreign_aips2_test,
		 (CONST char *dirname, flag test_dir) );
EXTERN_FUNCTION (pid_t foreign_aips2_run,
		 (CONST char *filename, int stdout_fd, int close_fd,
		  int *waitflags) );

/*  File:  drao_read.c  */
EXTERN_FUNCTION (CONST char *foreign_drao_read_dataset_names,
		 (CONST char *dirname, unsigned int *num_datasets,
		  unsigned int *max_width) );
EXTERN_FUNCTION (multi_array *foreign_drao_read,
		 (CONST char *setname, flag convert_int_to_float, ...) );
EXTERN_FUNCTION (multi_array *foreign_drao_read_header,
		 (CONST char *setname, flag data_alloc,
		  flag convert_int_to_float, KDRAODataContext *context, ...) );
EXTERN_FUNCTION (flag foreign_drao_read_data,
		 (KDRAODataContext context, char *data, uaddr num_values) );
EXTERN_FUNCTION (void foreign_drao_rewind_data_context,
		 (KDRAODataContext context) );
EXTERN_FUNCTION (void foreign_drao_close_data_context,
		 (KDRAODataContext context) );

/*  File:  filter.c  */
EXTERN_FUNCTION (unsigned int foreign_filter_get_format,
		 (CONST char *filename) );
EXTERN_FUNCTION (flag foreign_filter_test_directory_dataset,
		 (CONST char *dirname) );
EXTERN_FUNCTION (Channel foreign_filter_get_channel, (CONST char *filename) );
EXTERN_FUNCTION (multi_array *foreign_filter_read, (CONST char *filename) );
EXTERN_FUNCTION (flag foreign_filter_register,
		 (CONST char *extension, CONST char *converter_prog,
		  pid_t (*run) (CONST char *filename, int stdout_fd,
				int close_fd, int *waitflags),
		  CONST char *tester_prog,
		  flag (*tester_func) (CONST char *dirname, flag test_dir),
		  unsigned int output_type, CONST char *name) );

/*  File:  fits_read.c   */
EXTERN_FUNCTION (multi_array *foreign_fits_read_header,
		 (Channel channel, flag data_alloc, flag convert_int_to_float,
		  flag sanitise, ...) );
EXTERN_FUNCTION (multi_array *foreign_fits_read,
		 (CONST char *filename, flag convert_int_to_float,
		  flag sanitise, ...) );
EXTERN_FUNCTION (flag foreign_fits_read_data,
		 (Channel channel, multi_array *multi_desc, char *data,
		  uaddr num_values, ...) );
EXTERN_FUNCTION (void foreign_fits_copy_special,
		 (multi_array *new, CONST multi_array *old) );

/*  File:  fits_write.c  */
EXTERN_FUNCTION (flag foreign_fits_write,
		 (Channel channel, multi_array *multi_desc, ...) );
EXTERN_FUNCTION (flag foreign_fits_write_iarray,
		 (Channel channel, iarray array, ...) );
EXTERN_FUNCTION (flag foreign_fits_write_header,
		 (Channel channel, CONST multi_array *multi_desc,
		  CONST history *first_hist) );
EXTERN_FUNCTION (flag foreign_fits_write_data,
		 (Channel channel, multi_array *multi_desc,
		  CONST packet_desc *header_pack_desc,
		  CONST char *header_packet,
		  char *data, uaddr num_values, ...) );
EXTERN_FUNCTION (flag foreign_fits_write_padding, (Channel channel) );
EXTERN_FUNCTION (flag foreign_fits_generate_header,
		 (multi_array **out_multi_desc,
		  CONST multi_array *multi_desc, ...) );

/*  File:  gildas_read.c  */
EXTERN_FUNCTION (multi_array *foreign_gildas_read,
		 (CONST char *setname, unsigned int mmap_option,
		  flag writable) );
EXTERN_FUNCTION (multi_array *foreign_gildas_read_header,
		 (CONST char *setname, flag data_alloc,
		  unsigned int mmap_option, flag writable,
		  KGILDASDataContext *context) );
EXTERN_FUNCTION (flag foreign_gildas_read_data,
		 (KGILDASDataContext context, char *data, uaddr num_values) );
EXTERN_FUNCTION (void foreign_gildas_close_data_context,
		 (KGILDASDataContext context) );

/*  File:  gipsy_read.c  */
EXTERN_FUNCTION (flag foreign_gipsy_test, (CONST char *filename) );
EXTERN_FUNCTION (multi_array *foreign_gipsy_read_header,
		 (Channel channel, flag data_alloc, flag sanitise, ...) );
EXTERN_FUNCTION (flag foreign_gipsy_read_data,
		 (Channel channel, multi_array *multi_desc,
		  char *data, uaddr num_values, ...) );
EXTERN_FUNCTION (multi_array *foreign_gipsy_read,
		 (CONST char *filename, flag sanitise, ...) );

/*  File:  gipsy_write.c  */
EXTERN_FUNCTION (flag foreign_gipsy_write,
		 (CONST char *basename, multi_array *multi_desc, ...) );
EXTERN_FUNCTION (flag foreign_gipsy_write_iarray,
		 (CONST char *basename, iarray array, ...) );
EXTERN_FUNCTION (flag foreign_gipsy_write_header,
		 (Channel channel, CONST packet_desc *header_pack_desc,
		  CONST char *header_packet, ...) );
EXTERN_FUNCTION (flag foreign_gipsy_write_data,
		 (Channel channel, CONST multi_array *multi_desc,
		  CONST packet_desc *header_pack_desc,
		  CONST char *header_packet,
		  char *data, uaddr num_values, ...) );

/*  File:  guess_read.c  */
EXTERN_FUNCTION (multi_array *foreign_guess_and_read,
		 (CONST char *filename, unsigned int mmap_option,
		  flag writable, unsigned int *ftype, ...) );
EXTERN_FUNCTION (flag foreign_read_and_setup,
		 (CONST char *filename, unsigned int mmap_option,
		  flag writable, unsigned int *ftype, flag inform,
		  unsigned int num_dim,
		  unsigned int preferred_type, flag force_type,
		  iarray *array, double *min, double *max,
		  flag discard_zero_range, KwcsAstro *ap) );

/*  File:  guess_write.c  */
EXTERN_FUNCTION (flag foreign_guess_write,
		 (CONST char *filename, multi_array *multi_desc, ...) );

/*  File:  idf_read.c  */
EXTERN_FUNCTION (flag foreign_idf_test, (CONST char *filename) );
EXTERN_FUNCTION (multi_array *foreign_idf_read_header,
		 (Channel channel, flag data_alloc, flag sanitise, ...) );
EXTERN_FUNCTION (flag foreign_idf_read_data,
		 (Channel channel, multi_array *multi_desc,
		  char *data, uaddr num_values, ...) );
EXTERN_FUNCTION (multi_array *foreign_idf_read,
		 (CONST char *filename, flag sanitise, ...) );

/*  File:  miriad_read.c  */
EXTERN_FUNCTION (flag foreign_miriad_test2,
		 (CONST char *dirname, flag test_dir) );
EXTERN_FUNCTION (flag foreign_miriad_test, (CONST char *dirname) );
EXTERN_FUNCTION (multi_array *foreign_miriad_read_header,
		 (Channel channel, flag data_alloc, flag sanitise, ...) );
EXTERN_FUNCTION (multi_array *foreign_miriad_read_header2,
		 (CONST char *dirname, flag data_alloc, flag sanitise, ...) );
EXTERN_FUNCTION (multi_array *foreign_miriad_read,
		 (CONST char *dirname, flag sanitise, ...) );
EXTERN_FUNCTION (KMiriadDataContext foreign_miriad_create_data_context,
		 (CONST char *dirname, unsigned int mmap_option,
		  flag writable) );
EXTERN_FUNCTION (flag foreign_miriad_read_data,
		 (KMiriadDataContext context, multi_array *multi_desc,
		  char *data, uaddr num_values, ...) );
EXTERN_FUNCTION (void foreign_miriad_close_data_context,
		 (KMiriadDataContext context) );
EXTERN_FUNCTION (flag foreign_miriad_read_history,
		 (CONST char *dirname, multi_array *multi_desc) );
EXTERN_FUNCTION (double foreign_miriad_get_units_scale,
		 (CONST char *keyword) );
EXTERN_FUNCTION (unsigned int foreign_miriad_read_get_alignment_padding,
		 (uaddr position, uaddr size) );

/*  File:  miriad_write.c  */
EXTERN_FUNCTION (flag foreign_miriad_write,
		 (CONST char *dirname, multi_array *multi_desc, ...) );
EXTERN_FUNCTION (flag foreign_miriad_write_iarray,
		 (CONST char *dirname, iarray array, ...) );
EXTERN_FUNCTION (flag foreign_miriad_write_header_entry,
		 (Channel channel, CONST char *name, unsigned int type,
		  unsigned int num_values, CONST char *data) );

/*  File:  misc.c  */
EXTERN_FUNCTION (unsigned int foreign_guess_format_from_filename,
		 (CONST char *filename) );

/*  File:  pgm_read.c   */
EXTERN_FUNCTION (multi_array *foreign_pgm_read, (Channel channel, ...) );

/*  File: pnm_read.c  */
EXTERN_FUNCTION (unsigned int foreign_pnm_read_type,
		 (Channel channel, flag *binary) );
EXTERN_FUNCTION (multi_array *foreign_pnm_read, (Channel channel) );
EXTERN_FUNCTION (multi_array *foreign_pnm_read2,
		 (CONST char *filename, unsigned int mmap_option,
		  flag writable) );

/*  File:  ppm_read.c   */
EXTERN_FUNCTION (multi_array *foreign_ppm_read, (Channel channel, ...) );

/*  File:   ppm_write.c   */
EXTERN_FUNCTION (flag foreign_ppm_write,
		 (Channel channel, multi_array *multi_desc,flag binary, ...) );
EXTERN_FUNCTION (flag foreign_ppm_write_pseudo,
		 (Channel channel, flag binary,
		  CONST char *image, unsigned int type,
		  uaddr *hoffsets, uaddr *voffsets,
		  unsigned int inp_width, unsigned int inp_height,
		  unsigned int out_width, unsigned int out_height,
		  CONST unsigned short *cmap_reds,
		  CONST unsigned short *cmap_greens,
		  CONST unsigned short *cmap_blues,
		  unsigned int cmap_size, unsigned int min_sat_index,
		  unsigned int max_sat_index, unsigned int blank_index,
		  unsigned int cmap_stride,
		  double i_min, double i_max,
		  flag (*iscale_func) (), void *iscale_info) );
EXTERN_FUNCTION (flag foreign_ppm_write_rgb,
		 (Channel channel, flag binary,
		  CONST unsigned char *image_red,
		  CONST unsigned char *image_green,
		  CONST unsigned char *image_blue,
		  uaddr *hoffsets, uaddr *voffsets,
		  unsigned int inp_width, unsigned int inp_height,
		  unsigned int out_width, unsigned int out_height,
		  CONST unsigned short *cmap_red,
		  CONST unsigned short *cmap_green,
		  CONST unsigned short *cmap_blue,
		  unsigned int cmap_stride) );

/*  File:  sunras_read.c   */
EXTERN_FUNCTION (multi_array *foreign_sunras_read, (Channel channel, ...) );

/*  File:  sunras_write.c   */
EXTERN_FUNCTION (flag foreign_sunras_write,
		 (Channel channel, multi_array *multi_desc, ...) );
EXTERN_FUNCTION (flag foreign_sunras_write_pseudo,
		 (Channel channel, CONST char *image, unsigned int type,
		  uaddr *hoffsets, uaddr *voffsets,
		  unsigned int width, unsigned int height,
		  CONST unsigned short *cmap_reds,
		  CONST unsigned short *cmap_greens,
		  CONST unsigned short *cmap_blues,
		  unsigned int cmap_size, unsigned int cmap_stride,
		  double i_min, double i_max) );
EXTERN_FUNCTION (flag foreign_sunras_write_rgb,
		 (Channel channel, CONST unsigned char *image_red,
		  CONST unsigned char *image_green,
		  CONST unsigned char *image_blue,
		  uaddr *hoffsets, uaddr *voffsets,
		  unsigned int width, unsigned int height,
		  CONST unsigned short *cmap_red,
		  CONST unsigned short *cmap_green,
		  CONST unsigned short *cmap_blue, unsigned int cmap_stride) );


#endif /*  KARMA_FOREIGN_H  */
