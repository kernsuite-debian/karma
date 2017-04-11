/*  ImageDisplay.h

    Public header for  ImageDisplay  widget class.

    Copyright (C) 1994-2005  Richard Gooch

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
  ImageDisplay widget, an image display (application) widget for Xt.


    Written by      Richard Gooch   18-DEC-1994

    Last updated by Richard Gooch   18-JUL-2005

*/
#ifndef IMAGEDISPLAY__H
#define IMAGEDISPLAY__H

#include <X11/Xmu/Converters.h>
#include <karma_canvas.h>
#include <Xkw/Filepopup.h>
#include <Xkw/AnimateControl.h>
#include <Xkw/MultiCanvas.h>

#if !defined(KARMA_DISPDATA_DEF_H) || defined(MAKEDEPEND)
#  include <karma_dispdata_def.h>
#endif

extern WidgetClass imageDisplayWidgetClass;
typedef struct _ImageDisplayClassRec *ImageDisplayWidgetClass;
typedef struct _ImageDisplayRec *ImageDisplayWidget;

#define XtIsImageDisplay(w) XtIsSubclass((w), imageDisplayWidgetClass)

#define XkwNpseudoColourCanvas         "pseudoColourCanvas"
#define XkwNdirectColourCanvas         "directColourCanvas"
#define XkwNtrueColourCanvas           "trueColourCanvas"
#define XkwNpseudoColourLeftCanvas     "pseudoColourLeftCanvas"
#define XkwNpseudoColourRightCanvas    "pseudoColourRightCanvas"
#define XkwNdirectColourLeftCanvas     "directColourLeftCanvas"
#define XkwNdirectColourRightCanvas    "directColourRightCanvas"
#define XkwNtrueColourLeftCanvas       "trueColourLeftCanvas"
#define XkwNtrueColourRightCanvas      "trueColourRightCanvas"
#define XkwNvisibleCanvas              "visibleCanvas"
#define XkwNcanvasList                 "canvasList"
#define XkwNrenzoPseudoCmap            "renzoPseudoCmap"
#define XkwNrenzoTrueCmap              "renzoTrueCmap"
#define XkwNhueIntensityCmap           "hueIntensityCmap"
#define XkwNmagnifier                  "magnifier"
#define XkwNimageName                  "imageName"
#define XkwNcreateFilepopup            "createFilepopup"
#define XkwNenableAnimation            "enableAnimation"
#define XkwNshowQuitButton             "showQuitButton"
#define XkwNcmapSize                   "cmapSize"
#define XkwNcmapMaster                 "cmapMaster"
#define XkwNfullscreen                 "fullscreen"
#define XkwNnumTrackLabels             "numTrackLabels"
#define XkwNviewDatasets               "viewDatasets"
#define XkwNnumDatasets                "numDatasets"
#define XkwNmainRealisedCallback       "mainRealisedCallback"
#define XkwNafterMainRealisedCallback  "afterMainRealisedCallback"
#define XkwNdatasetNames               "datasetNames"
#define XkwNnewVisibleCanvasCallback   "newVisibleCanvasCallback"
#define XkwNpanner                     "panner"
#define XkwNfastPanner                 "fastPanner"
#define XkwNupdateTrackLabels          "updateTrackLabels"
#define XkwNnewEditorContextCallback   "newEditorContextCallback"
#define XkwNmultiCanvas                "multiCanvas"
#define XkwNverbose                    "verbose"

#define XkwCWorldCanvas                "WorldCanvas"
#define XkwCImageName                  "ImageName"
#define XkwCCreateFilepopup            "CreateFilepopup"
#define XkwCEnableAnimation            "EnableAnimation"
#define XkwCShowQuitButton             "ShowQuitButton"
#define XkwCCmapSize                   "CmapSize"
#define XkwCCmapMaster                 "CmapMaster"
#define XkwCFullscreen                 "Fullscreen"
#define XkwCNumTrackLabels             "NumTrackLabels"
#define XkwCViewDatasets               "ViewDatasets"
#define XkwCNumDatasets                "NumDatasets"
#define XkwCDatasetNames               "DatasetNames"
#define XkwCFastPanner                 "FastPanner"
#define XkwCUpdateTrackLabels          "UpdateTrackLabels"
#define XkwCVerbose                    "Verbose"

/*  Keep these consistent with source/lib/karmawidgets/ImageDisplay.h  */
#define XkwNEW_WINDOW_SLAVE_CMAP        0
#define XkwNEW_WINDOW_INDEPENDENT_CMAP  1
#define XkwNEW_WINDOW_24_ONLY           2


/*----------------------------------------------------------------------
 * Functions
 *----------------------------------------------------------------------*/

EXTERN_FUNCTION (void XkwImageDisplayRefresh, (Widget W, flag clear) );
EXTERN_FUNCTION (KDisplayDataWindow XkwImageDisplayGetWindow, (Widget W) );
EXTERN_FUNCTION (void XkwImageDisplaySetSmoothCallback,
		 (Widget w, XtPointer client_data, XtPointer call_data) );
EXTERN_FUNCTION (void XkwImageDisplayCheckObsolete, (int argc, char **argv) );
EXTERN_FUNCTION (Widget XkwImageDisplayCreateWindow,
		 (Widget w, unsigned int window_type) );


#endif
