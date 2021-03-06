/*  karma_cf.h

    Header for  cf_  package.

    Copyright (C) 1993-2004  Richard Gooch

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
  needed to interface to the cf_ routines in the Karma library.


    Written by      Richard Gooch   23-FEB-1993

    Last updated by Richard Gooch   6-MAR-2004

*/
#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#ifndef KARMA_CF_H
#define KARMA_CF_H


typedef struct
{
    unsigned int patternlength;
    char pattern[256][3];
} stripchart;

typedef struct
{
    float red;
    float green;
    float blue;
} Colour_struct;


/*  File:  misc1.c  */
EXTERN_FUNCTION (void cf_greyscale1,
		 (unsigned int num_cells,
		  unsigned short *reds, unsigned short *greens,
		  unsigned short *blues, unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_greyscale2,
		 (unsigned int num_cells,
		  unsigned short *reds, unsigned short *greens,
		  unsigned short *blues, unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_greyscale3,
		 (unsigned int num_cells,
		  unsigned short *reds, unsigned short *greens,
		  unsigned short *blues, unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_rainbow1, (unsigned int num_cells,
				    unsigned short *reds,
				    unsigned short *greens,
				    unsigned short *blues,
				    unsigned int stride,
				    double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_rainbow2, (unsigned int num_cells,
				    unsigned short *reds,
				    unsigned short *greens,
				    unsigned short *blues,
				    unsigned int stride,
				    double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_rainbow3, (unsigned int num_cells,
				    unsigned short *reds,
				    unsigned short *greens,
				    unsigned short *blues,
				    unsigned int stride,
				    double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_cyclic1, (unsigned int num_cells,
				   unsigned short *reds,
				   unsigned short *greens,
				   unsigned short *blues,
				   unsigned int stride,
				   double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_stripchart, (unsigned int num_cells,
				      unsigned short *reds,
				      unsigned short *greens,
				      unsigned short *blues,
				      unsigned int stride,
				      double x, double y, void *chart) );
EXTERN_FUNCTION (void cf_random_grey, (unsigned int num_cells,
				       unsigned short *reds,
				       unsigned short *greens,
				       unsigned short *blues,
				       unsigned int stride,
				       double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_random_pseudocolour, (unsigned int num_cells,
					       unsigned short *reds,
					       unsigned short *greens,
					       unsigned short *blues,
					       unsigned int stride,
					       double x, double y,
					       void *var_param) );
EXTERN_FUNCTION (void cf_velocity_compensating_tones,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_compressed_colourmap_3r2g2b,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_background,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_heat,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_isophot,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_mono,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_mousse,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_rainbow,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_random,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_rgb,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_smooth,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_staircase,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_ronekers,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_mirp,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_mandelbrot,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride,
		  double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_rgb2,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride, double x, double y, void *var_param) );

/*  File: misc8.c  */
EXTERN_FUNCTION (void cf_fire,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride, double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_spring,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride, double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_sea,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride, double x, double y, void *var_param) );

/*  File: misc9.c  */
EXTERN_FUNCTION (void cf_sunbow,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride, double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_mutant,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride, double x, double y, void *var_param) );
EXTERN_FUNCTION (void cf_aberration,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride, double x, double y, void *var_param) );

/*  File: support.c  */
EXTERN_FUNCTION (void cf_colour_table,
		 (unsigned int num_cells, unsigned short *reds,
		  unsigned short *greens, unsigned short *blues,
		  unsigned int stride, double x, double y,
		  CONST Colour_struct *lut, unsigned int lut_size) );

#endif /*  KARMA_CF_H  */
