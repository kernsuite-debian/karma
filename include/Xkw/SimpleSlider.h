/*  SimpleSlider.h

    Public header for  SimpleSlider  widget class.

    Copyright (C) 1996-2006  Richard Gooch

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

    This include file contains the public class declarations for the
  SimpleSlider widget.


    Written by      Richard Gooch   4-MAY-1996

    Last updated by Richard Gooch   3-AUG-2006


*/
#ifndef _SimpleSlider_h
#define _SimpleSlider_h

#include <X11/Xmu/Converters.h>
#include <X11/Shell.h>
#include <karma_kwin.h>


extern WidgetClass simpleSliderWidgetClass;
typedef struct _SimpleSliderClassRec	*SimpleSliderWidgetClass;
typedef struct _SimpleSliderRec	*SimpleSliderWidget;

#define XtIsSimpleSlider(w) XtIsSubclass((w), simpleSliderWidgetClass)

#define XkwNvalueChangeCallback "valueChangeCallback"
#define XkwNminimum "minimum"
#define XkwNmaximum "maximum"
#define XkwNwrap "wrap"
#define XkwNdefaultValue "defaultValue"
#define XkwNvaluePtr "valuePtr"
#define XkwNscaledValuePtr "scaledValuePtr"
#define XkwNmodifier "modifier"
#define XkwNshowRange "showRange"
#define XkwNshowValue "showValue"
#define XkwNvalueBesideLabel "valueBesideLabel"
#define XkwNscaledFormat "scaledFormat"
#define XkwNscaledUnit "scaledUnit"
#define XtNdecay "decay"
#define XtNinitialDelay "initialDelay"
#define XtNminimumDelay "minimumDelay"
#define XtNrepeatDelay "repeatDelay"
#define XkwNrealiseCallback "realiseCallback"

#define XkwCMinimum "Minimum"
#define XkwCMaximum "Maximum"
#define XkwCWrap "Wrap"
#define XkwCValuePtr "ValuePtr"
#define XkwCModifier "Modifier"
#define XkwCShowRange "ShowRange"
#define XkwCShowValue "ShowValue"
#define XkwCValueBesideLabel "ValueBesideLabel"
#define XkwCScaledFormat "ScaledFormat"
#define XkwCScaledUnit "ScaledUnit"
#define XtCDecay "Decay"
#define XtCDelay "Delay"
#define XtCMinimumDelay "MinimumDelay"
#define XkwCRealiseCallback "RealiseCallback"

EXTERN_FUNCTION (void XkwSimpleSliderSetScale,
		 (Widget W, double scale, double offset,
		  flag show_raw, flag show_scaled) );

#endif /* _SimpleSlider_h */
