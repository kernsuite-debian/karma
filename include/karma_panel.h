/*  karma_panel.h

    Header for  panel_  package.

    Copyright (C) 1993-2002  Richard Gooch

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
  needed to interface to the panel_ routines in the Karma library.


    Written by      Richard Gooch   1-OCT-1993

    Last updated by Richard Gooch   22-DEC-2002

*/
#ifndef FILE
#  include <stdio.h>
#endif

#if !defined(KARMA_H) || defined(MAKEDEPEND)
#  include <karma.h>
#endif

#if !defined(KARMA_DS_DEF_H) || defined(MAKEDEPEND)
#  include <karma_ds_def.h>
#endif

#if !defined(KARMA_DS_VAL_H) || defined(MAKEDEPEND)
#  include <karma_ds_val.h>
#endif

#if !defined(KARMA_C_DEF_H) || defined(MAKEDEPEND)
#  include <karma_c_def.h>
#endif

#ifndef KARMA_PANEL_H
#define KARMA_PANEL_H



typedef struct controlpanel_type * KControlPanel;
typedef struct panelitem_type * KPanelItem;


/*  Panel item attribute definitions  */
#define PIA_END                0
#define PIA_NUM_CHOICE_STRINGS 31001
#define PIA_CHOICE_STRINGS     31002
#define PIA_ARRAY_LENGTH       31003
#define PIA_ARRAY_MIN_LENGTH   31004
#define PIA_ARRAY_MAX_LENGTH   31005
#define PIA_CHOICE_COMMENTS    31006
#define PIA_MIN_VALUE          31007
#define PIA_MAX_VALUE          31008
#define PIA_TOP_OF_PANEL       31009

/*  Extra panel item type definitions  */
#define PIT_FUNCTION     30000  /*  value_ptr: ( void (*) (char *) )  */
#define PIT_EXIT_FORM    30001  /*  value_ptr: unused                 */
#define PIT_FLAG         30002  /*  value_ptr: (flag *)               */
#define PIT_CHOICE_INDEX 30003  /*  value_ptr: (unsigned int *)       */
/*                                  required: PIA_NUM_CHOICE_STRINGS  */
/*                                            PIA_CHOICE_STRINGS      */
#define PIT_GROUP        30004  /*  value_ptr: KControlPanel          */


/*  File:   panel.c   */
EXTERN_FUNCTION (KControlPanel panel_create, (flag blank) );
EXTERN_FUNCTION (KControlPanel panel_create_group, () );
EXTERN_FUNCTION (KPanelItem panel_add_item,
		 (KControlPanel panel, char *name, char *comment,
		  unsigned int type, void *value_ptr, ...) );
EXTERN_FUNCTION (void panel_push_onto_stack, (KControlPanel panel) );
EXTERN_FUNCTION (void panel_pop_from_stack, () );
EXTERN_FUNCTION (flag panel_process_command_with_stack,
		 (CONST char *cmd, flag (*unknown_func) (), FILE *fp) );
EXTERN_FUNCTION (flag panel_put_history_with_stack,
		 (multi_array *multi_desc, flag module_header) );
EXTERN_FUNCTION (void panel_set_extra_comment_string,
		 (KControlPanel panel, CONST char *string) );
EXTERN_FUNCTION (KCallbackFunc panel_item_register_callback,
		 (KPanelItem item, void (*func) (), void *info) );


#endif /*  KARMA_PANEL_H  */
