/*  SlaveImageDisplayPopup.h

    Public header for  SlaveImageDisplayPopup  widget class.

    Copyright (C) 1997-2000  Richard Gooch

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
  SlaveImageDisplayPopup widget, an image display (application) widget for Xt.


    Written by      Richard Gooch   6-DEC-1997

    Last updated by Richard Gooch   12-MAY-2000

*/
#ifndef SLAVEIMAGEDISPLAYPOPUP__H
#define SLAVEIMAGEDISPLAYPOPUP__H

#include <X11/Xmu/Converters.h>
#include <karma_canvas.h>

extern WidgetClass slaveImageDisplayPopupWidgetClass;
typedef struct _SlaveImageDisplayPopupClassRec *SlaveImageDisplayPopupWidgetClass;
typedef struct _SlaveImageDisplayPopupRec *SlaveImageDisplayPopupWidget;

#define XtIsSlaveImageDisplayPopup(w) XtIsSubclass((w), slaveImageDisplayPopupWidgetClass)

#define XkwNpseudoColourCanvas "pseudoColourCanvas"
#define XkwNdirectColourCanvas "directColourCanvas"
#define XkwNtrueColourCanvas "trueColourCanvas"
#define XkwNpseudoColourLeftCanvas "pseudoColourLeftCanvas"
#define XkwNpseudoColourRightCanvas "pseudoColourRightCanvas"
#define XkwNdirectColourLeftCanvas "directColourLeftCanvas"
#define XkwNdirectColourRightCanvas "directColourRightCanvas"
#define XkwNtrueColourLeftCanvas "trueColourLeftCanvas"
#define XkwNtrueColourRightCanvas "trueColourRightCanvas"
#define XkwNvisibleCanvas "visibleCanvas"
#define XkwNcanvasList "canvasList"
#define XkwNfastPanner "fastPanner"
#define XkwNenablePanning "enablePanning"
#define XkwNrealisedCallback "realisedCallback"
#define XkwNverbose "verbose"

#define XkwCWorldCanvas "WorldCanvas"
#define XkwCFastPanner "FastPanner"
#define XkwCEnablePanning "EnablePanning"
#define XkwCRealisedCallback "RealisedCallback"
#define XkwCVerbose "Verbose"


EXTERN_FUNCTION (void XkwSlaveImageDisplayPopupRefresh,
		 (Widget W, flag clear) );


#endif
