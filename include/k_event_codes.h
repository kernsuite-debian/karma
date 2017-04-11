/*
    Definition of event codes.

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

#ifndef K_EVENT_CODES_H
#define K_EVENT_CODES_H

#define K_CANVAS_EVENT_LEFT_MOUSE_CLICK        0
#define K_CANVAS_EVENT_LEFT_MOUSE_DRAG         1
#define K_CANVAS_EVENT_MIDDLE_MOUSE_CLICK      2
#define K_CANVAS_EVENT_MIDDLE_MOUSE_DRAG       3
#define K_CANVAS_EVENT_RIGHT_MOUSE_CLICK       4
#define K_CANVAS_EVENT_RIGHT_MOUSE_DRAG        5
#define K_CANVAS_EVENT_POINTER_MOVE            6
#define K_CANVAS_EVENT_LEFT_MOUSE_RELEASE      7
#define K_CANVAS_EVENT_MIDDLE_MOUSE_RELEASE    8
#define K_CANVAS_EVENT_RIGHT_MOUSE_RELEASE     9
#define K_CANVAS_EVENT_PLAIN_KEY_PRESS        10
#define K_CANVAS_EVENT_MODIFIED_KEY_PRESS     11
#define K_CANVAS_EVENT_KEYSYM_PRESS           12
#define K_CANVAS_EVENT_POINTER_WARP           13
#define K_CANVAS_EVENT_POINTER_ENTER          14
#define K_CANVAS_EVENT_POINTER_LEAVE          15
#define K_CANVAS_EVENT_MOUSE_BUTTON4_CLICK    16
#define K_CANVAS_EVENT_MOUSE_BUTTON4_DRAG     17
#define K_CANVAS_EVENT_MOUSE_BUTTON4_RELEASE  18
#define K_CANVAS_EVENT_MOUSE_BUTTON5_CLICK    19
#define K_CANVAS_EVENT_MOUSE_BUTTON5_DRAG     20
#define K_CANVAS_EVENT_MOUSE_BUTTON5_RELEASE  21
#define K_CANVAS_EVENT_PLAIN_KEY_RELEASE      22
#define K_CANVAS_EVENT_MODIFIED_KEY_RELEASE   23
#define K_CANVAS_EVENT_KEYSYM_RELEASE         24

#define K_CANVAS_EVENT_UNDEFINED              29999

#define K_CANVAS_EVENT_USER_SPACE             30000


/*  Mask is an unsigned long and immediately follows '\0' terminator in string
    buffer  */
#define K_CANVAS_EVENT_LEFT_MOUSE_MASK        0x01
#define K_CANVAS_EVENT_MIDDLE_MOUSE_MASK      0x02
#define K_CANVAS_EVENT_RIGHT_MOUSE_MASK       0x04
#define K_CANVAS_EVENT_MOUSE_BUTTON4_MASK     0x08
#define K_CANVAS_EVENT_MOUSE_BUTTON5_MASK     0x10
#define K_CANVAS_EVENT_CONTROL_KEY_MASK       0x20
#define K_CANVAS_EVENT_SHIFTED_MASK           0x40  /*  Shift | CapsLock  */


#endif  /*  K_EVENT_CODES_H  */
