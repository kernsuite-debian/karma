/*  karma_wcs.h

    Header for  wcs_  package.

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
  needed to interface to the wcs_ routines in the Karma library.


    Written by      Richard Gooch   29-MAY-1996

    Last updated by Richard Gooch   5-JUL-2005

*/

#if !defined(KARMA_DS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_ds_def.h>
#endif

#if !defined(KARMA_WCS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_wcs_def.h>
#endif

#ifndef KARMA_WCS_H
#define KARMA_WCS_H


/*  Spherical format types (experimental: subject to change without notice)  */
#define WCS_SPHERICAL_DEFAULT          0 /*  Automatic selection             */
#define WCS_SPHERICAL_DECIMAL          1 /*  Decimal format                  */
#define WCS_SPHERICAL_DMS_DMS          2 /*  DMS for longitude and latitude  */
#define WCS_SPHERICAL_HMS_DMS          3 /*  Longitude: HMS, latitude: DMS   */
#define WCS_NUM_SPHERICAL_FORMAT_CHOICES  4
extern char *wcs_spherical_format_choices[WCS_NUM_SPHERICAL_FORMAT_CHOICES];


/*  Generic routines  */
EXTERN_FUNCTION (KwcsAstro wcs_astro_get_associated,
		 (multi_array *multi_desc, unsigned int index) );
EXTERN_FUNCTION (KwcsAstro wcs_astro_setup,
		 (CONST packet_desc *pack_desc, CONST char *packet) );
EXTERN_FUNCTION (void wcs_astro_destroy, (KwcsAstro ap) );
EXTERN_FUNCTION (flag wcs_astro_test_radec, (KwcsAstro ap) );
EXTERN_FUNCTION (flag wcs_astro_test_velocity, (KwcsAstro ap) );
EXTERN_FUNCTION (flag wcs_astro_test_if_ra,
		 (KwcsAstro ap, CONST char *axis_name) );
EXTERN_FUNCTION (flag wcs_astro_test_if_dec,
		 (KwcsAstro ap, CONST char *axis_name) );
EXTERN_FUNCTION (flag wcs_astro_test_if_glon,
		 (KwcsAstro ap, CONST char *axis_name) );
EXTERN_FUNCTION (flag wcs_astro_test_if_glat,
		 (KwcsAstro ap, CONST char *axis_name) );
EXTERN_FUNCTION (flag wcs_astro_test_if_lon,
		 (KwcsAstro ap, CONST char *axis_name) );
EXTERN_FUNCTION (flag wcs_astro_test_if_lat,
		 (KwcsAstro ap, CONST char *axis_name) );
EXTERN_FUNCTION (flag wcs_astro_test_if_velocity,
		 (KwcsAstro ap, CONST char *axis_name) );
EXTERN_FUNCTION (flag wcs_astro_transform,
		 (KwcsAstro ap, flag thread, unsigned int num_coords,
		  double *ra, flag ra_to_linear,
		  double *dec, flag dec_to_linear,
		  double *vel, flag vel_to_linear,
		  unsigned int num_restr, CONST char **restr_names,
		  CONST double *restr_values) );
EXTERN_FUNCTION (flag wcs_astro_transform3,
		 (KwcsAstro ap, flag thread, unsigned int num_coords,
		  CONST char *name0, double *coords0, flag to_lin0,
		  CONST char *name1, double *coords1, flag to_lin1,
		  CONST char *name2, double *coords2, flag to_lin2,
		  unsigned int num_restr, CONST char **restr_names,
		  CONST double *restr_values) );
EXTERN_FUNCTION (flag wcs_astro_breakdown_hms,
		 (int *hours, int *minutes,
		  double *seconds, int *whole_seconds,
		  double *subseconds, double input, double offset) );
EXTERN_FUNCTION (void wcs_astro_format_hms, (char *string, double hours) );
EXTERN_FUNCTION (flag wcs_astro_breakdown_dms,
		 (flag *negative, int *degrees, int *minutes,
		  double *seconds, int *whole_seconds,
		  double *subseconds, double input, double offset) );
EXTERN_FUNCTION (void wcs_astro_format_dms, (char *string, double deg) );
EXTERN_FUNCTION (void wcs_astro_format_vel,
		 (KwcsAstro ap, char *string, double vel) );
EXTERN_FUNCTION (void wcs_astro_breakdown_time,
		 (unsigned int *year, unsigned int *month,
		  unsigned int *day_of_month, unsigned int *day_of_year,
		  unsigned int *hours, unsigned int *minutes,
		  double *seconds, unsigned int *whole_seconds,
		  double *subseconds, double time_val) );
EXTERN_FUNCTION (void wcs_astro_format_time, (char *string, double time_val) );
EXTERN_FUNCTION (void wcs_astro_format,
		 (KwcsAstro ap, unsigned int sperical_format,
		  CONST char *dim_name, char string[STRING_LENGTH],
		  double value) );
EXTERN_FUNCTION (void wcs_astro_format_all,
		 (KwcsAstro ap, unsigned int sperical_format,
		  char coord_string[STRING_LENGTH],
		  CONST char *name0, double coord0,
		  CONST char *name1, double coord1,
		  CONST char *name2, double coord2,
		  unsigned int num_restr, CONST char **restr_names,
		  CONST double *restr_values,
		  char other_string[STRING_LENGTH]) );
EXTERN_FUNCTION (flag wcs_astro_get_preferred_units,
		 (char new_units[STRING_LENGTH],char format_str[STRING_LENGTH],
		  double *scale, CONST char *old_units) );
EXTERN_FUNCTION (unsigned int wcs_astro_get_equinox, (KwcsAstro ap) );
EXTERN_FUNCTION (double wcs_astro_get_reference,
		 (KwcsAstro ap, CONST char *name, flag linear) );
EXTERN_FUNCTION (double wcs_astro_get_increment,
		 (KwcsAstro ap, CONST char *name) );
EXTERN_FUNCTION (void wcs_astro_update_location,
		 (KwcsAstro ap, unsigned int axis_number,
		  CONST packet_desc *pack_desc, CONST char *packet) );
EXTERN_FUNCTION (flag wcs_astro_compare_axes,
		 (KwcsAstro ap1, CONST char *name1,
		  KwcsAstro ap2, CONST char *name2) );
EXTERN_FUNCTION (flag wcs_astro_has_chromatic_aberration, (KwcsAstro ap) );


/*  File: misc.c  */
EXTERN_FUNCTION (flag wcs_compare_grids_2D,
		 (KwcsAstro ap1, CONST dim_desc *hd1, CONST dim_desc *vd1,
		  unsigned int num_restr1, CONST char **restr_names1,
		  CONST double *restr_values1,
		  KwcsAstro ap2, CONST dim_desc *hd2, CONST dim_desc *vd2,
		  unsigned int num_restr2, CONST char **restr_names2,
		  CONST double *restr_values2,
		  flag *same) );


#endif /*  KARMA_WCS_H  */
