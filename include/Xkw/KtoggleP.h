/*
 * $XConsortium: KtoggleP.h,v 1.8 91/06/20 16:15:51 converse Exp $
 *
 * Copyright 1989 Massachusetts Institute of Technology
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of M.I.T. not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  M.I.T. makes no representations about the
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.
 * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN 
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/* 
 * KtoggleP.h - Private definitions for Ktoggle widget
 * 
 * Author: Chris D. Peterson
 *         MIT X Consortium
 *         kit@expo.lcs.mit.edu
 *  
 * Date:   January 12, 1989
 *
 * 
 * Post factum editor : Greg Baker
 *                      CSIRO Radiophysics
 *                      gbaker@rp.csiro.au
 */

#ifndef _XawKtoggleP_h
#define _XawKtoggleP_h

#include <Xkw/Ktoggle.h>
#include <X11/Xaw/CommandP.h>

/***********************************************************************
 *
 * Ktoggle Widget Private Data
 *
 ***********************************************************************/

#define streq(a, b) ( strcmp((a), (b)) == 0 )

typedef struct _RadioGroup {
  struct _RadioGroup *prev, *next; /* Pointers to other elements in group. */
  Widget widget;		  /* Widget corrosponding to this element. */
} RadioGroup;

/************************************
 *
 *  Class structure
 *
 ***********************************/

   /* New fields for the Ktoggle widget class record */
typedef struct _KtoggleClass  {
    XtActionProc Set;
    XtActionProc Unset;
    XtPointer extension;
} KtoggleClassPart;

   /* Full class record declaration */
typedef struct _KtoggleClassRec {
    CoreClassPart	core_class;
    SimpleClassPart	simple_class;
    LabelClassPart	label_class;
    CommandClassPart	command_class;
    KtoggleClassPart     ktoggle_class;
} KtoggleClassRec;

extern KtoggleClassRec ktoggleClassRecF;
extern KtoggleClassRec ktoggleClassRecT;

/***************************************
 *
 *  Instance (widget) structure 
 *
 **************************************/

    /* New fields for the Ktoggle widget record */
typedef struct
{
    /* resources */
    Widget      widget;
    XtPointer   radio_data;
    Bool        CrossesOn;
    Bool        yes;
    Bool        callCallbacksOnSet;

    /* private data */
    RadioGroup * radio_group;
    Pixmap Tick,Cross,Neither;
} KtogglePart;

   /* Full widget declaration */
typedef struct _KtoggleRec {
    CorePart         core;
    SimplePart	     simple;
    LabelPart	     label;
    CommandPart	     command;
    KtogglePart       ktoggle;
} KtoggleRec;

#endif /* _XawKtoggleP_h */


