/*  IntensityPolicy.h

    Private header for  IntensityPolicy  widget class.

    Copyright (C) 1997-2005  Richard Gooch

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

    This include file contains the private class declarations for the
  IntensityPolicy widget.


    Written by      Richard Gooch   8-DEC-1997

    Last updated by Richard Gooch   30-OCT-2005

*/
#ifndef IntensityPolicyP__H
#define IntensityPolicyP__H

#include <X11/IntrinsicP.h>
#include <X11/ShellP.h>
#include <X11/StringDefs.h>

#include <Xkw/IntensityPolicy.h>

typedef struct _IntensityPolicyPart
{
    /*  Public resources  */
    Bool          showIntensityReset;
    XtCallbackList intensityRangeCallback;
    /*  Private resources  */
    flag   auto_refresh;
    flag   in_callback;
    int    iscale_choice;
    double log_cycles;
    Widget intensity_reset_tgl;
    Widget unit_lbl;
    Widget min_txt;
    Widget max_txt;
    Widget min_lbl;
    double last_min;  /*  Value as displayed  */
    double last_max;  /*  Value as displayed  */
    double scale;
    double offset;
    double multiplier;
    double resolution;
    struct canvas_list *first_canvas;
    char   *last_unit;
} IntensityPolicyPart, *IntensityPolicyPartPtr;

typedef struct _IntensityPolicyRec
{
    CorePart core;
    CompositePart composite;
    ShellPart shell;
    WMShellPart wm;
    VendorShellPart vendor;
    TopLevelShellPart topLevel;
    IntensityPolicyPart intensityPolicy;
} IntensityPolicyRec, *IntensityPolicyPtr;

typedef struct _IntensityPolicyClassPart
{
    int empty;
} IntensityPolicyClassPart;

typedef struct _IntensityPolicyClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ShellClassPart shell_class;
    WMShellClassPart wm_shell_class;
    VendorShellClassPart vendor_shell_class;
    TopLevelShellClassPart top_level_shell_class;
    IntensityPolicyClassPart intensityPolicy_class;
} IntensityPolicyClassRec, *IntensityPolicyClassPtr;

extern IntensityPolicyClassRec intensityPolicyClassRec;

#endif
