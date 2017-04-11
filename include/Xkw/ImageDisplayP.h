/*  ImageDisplayP.h

    Private header for  ImageDisplay  widget class.

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

    This include file contains the private class declarations for the
  ImageDisplay widget, an image display (application) widget for Xt.


    Written by      Richard Gooch   18-DEC-1994

    Last updated by Richard Gooch   18-JUL-2005

*/
#ifndef ImageDisplayP__H
#define ImageDisplayP__H

#include <X11/IntrinsicP.h>
#include <X11/Xaw/FormP.h>
#include <X11/StringDefs.h>

#include <Xkw/ImageDisplay.h>
#include <karma_c_def.h>

typedef struct _ImageDisplayPart
{
    /*  Public resources  */
    /*  The main window  */
    KWorldCanvas        pseudoCanvas;
    KWorldCanvas        directCanvas;
    KWorldCanvas        trueCanvas;
    KWorldCanvas        pseudoCanvasLeft;
    KWorldCanvas        pseudoCanvasRight;
    KWorldCanvas        directCanvasLeft;
    KWorldCanvas        directCanvasRight;
    KWorldCanvas        trueCanvasLeft;
    KWorldCanvas        trueCanvasRight;
    KWorldCanvas        visibleCanvas;
    KWorldCanvas        *canvasList;          /*  NULL-terminated  */
    /*  The magnifier window  */
    Widget              magnifier;
    Widget              panner;
    /*  Other public resources  */
    String              imageName;
    Bool                createFilepopup;
    Bool                enableAnimation;
    Bool                showQuitButton;
    Bool                fullscreen;
    int                 cmapSize;
    String              cmapMaster;
    Bool                viewDatasets;
    int                 numDatasets;
    Bool                fastPanner;
    Bool                updateTrackLabels;
    Bool                verbose;
    int                 numTrackLabels;
    XtPointer           datasetNames;
    XtCallbackList      mainRealisedCallback;
    XtCallbackList      afterMainRealisedCallback;
    XtCallbackList      newVisibleCanvasCallback;
    XtCallbackList      newEditorContextCallback;
    Widget              multiCanvas;
    Kcolourmap          pseudoCmap;
    Kcolourmap          renzoPseudoCmap;
    Kcolourmap          renzoTrueCmap;
    Kcolourmap          hueIntensityCmap;
    int                 requestMask;
    int                 allowedMask;
    Colormap            pseudoXColourMap;
    /*  Private resources  */
    Widget              override_shell;
    Widget              cmapwinpopup_psuedo;
    Widget              cmapwinpopup_direct;
    Widget              cmapwinpopup_renzogram;
    Widget              cmapwinpopup_hue_intensity;
    Widget              zoom_policy_popup;
    Widget              intensity_policy_popup;
    Widget              overlay_menu;
    Kcolourmap          direct_cmap;
    unsigned int        num_unrealised;
    Widget              export_menu;
    Widget              image_editor_popup;
    KDisplayDataWindow  dispdata_window;
    KCallbackList       destroy_list;    /*  Called by the Destroy() method  */
    Visual              *truecolour_visual;
} ImageDisplayPart, *ImageDisplayPartPtr;

typedef struct _ImageDisplayRec
{
    CorePart core;
    CompositePart composite;
    ConstraintPart constraint;
    FormPart form;
    ImageDisplayPart imageDisplay;
} ImageDisplayRec, *ImageDisplayPtr;

typedef struct _ImageDisplayClassPart
{
    int empty;
} ImageDisplayClassPart;

typedef struct _ImageDisplayClassRec
{
    CoreClassPart core_class;	
    CompositeClassPart composite_class;
    ConstraintClassPart constraint_class;
    FormClassPart form_class;
    ImageDisplayClassPart imageDisplay_class;
} ImageDisplayClassRec, *ImageDisplayClassPtr;

extern ImageDisplayClassRec imageDisplayClassRec;

typedef struct {int empty;} ImageDisplayConstraintsPart;

typedef struct _ImageDisplayConstraintsRec
{
    FormConstraintsPart	  form;
    ImageDisplayConstraintsPart ImageDisplay;
} ImageDisplayConstraintsRec, *ImageDisplayConstraints;

#endif
