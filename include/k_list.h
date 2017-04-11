/*
    Macros for list manipulation.

    Copyright (C) 2002-2004  Richard Gooch

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

    Written by      Richard Gooch   27-MAY-2002

    Last updated by Richard Gooch   30-APR-2004

*/

#ifndef K_LIST_H
#define K_LIST_H

#define KLIST_APPEND(list,entry) \
    KLIST_APPEND2((list)->first,(list)->last,entry)

#define KLIST_APPEND2(first,last,entry) \
{ \
    (entry)->prev = (last); \
    (entry)->next = NULL; \
    if ((first) == NULL) (first) = entry; \
    else (last)->next = (entry); \
    (last) = (entry); \
}

#define KLIST_APPEND3(list,chain,entry) \
    KLIST_APPEND4((list)->first,(list)->last,chain,entry)

#define KLIST_APPEND4(first,last,chain,entry) \
{ \
    (entry)->chain.prev = (last); \
    (entry)->chain.next = NULL; \
    if ((first) == NULL) (first) = entry; \
    else (last)->chain.next = (entry); \
    (last) = (entry); \
}

#define KLIST_PREPEND(list,entry) \
    KLIST_PREPEND2((list)->first,(list)->last,entry)

#define KLIST_PREPEND2(first,last,entry) \
{ \
    (entry)->prev = NULL; \
    (entry)->next = (first); \
    if ((first) == NULL) (last) = (entry); \
    else (first)->prev = (entry); \
    (first) = (entry); \
}

#define KLIST_INSERT(list,before,entry) \
    KLIST_INSERT2((list)->first,(list)->last,before,entry)

#define KLIST_INSERT2(first,last,before,entry) \
{ \
    if ( ((before) == (first)) || ((before) == NULL) ) \
    {   /*  Add to start of list  */ \
	KLIST_PREPEND2 ((first), (last), (entry)); \
    } \
    else \
    {   /*  Add somewhere inside list  */ \
	(entry)->prev = (before)->prev; \
	(entry)->next = (before); \
	(before)->prev->next = (entry); \
	(before)->prev = (entry); \
    } \
}

#define KLIST_REMOVE(list,entry) \
    KLIST_REMOVE2((list)->first,(list)->last,entry)

#define KLIST_REMOVE2(first,last,entry) \
{ \
    if ((entry)->prev == NULL) (first) = (entry)->next; \
    else (entry)->prev->next = (entry)->next; \
    if ((entry)->next == NULL) (last) = (entry)->prev; \
    else (entry)->next->prev = (entry)->prev; \
}

#define KLIST_REMOVE3(list,chain,entry) \
    KLIST_REMOVE4((list)->first,(list)->last,chain,entry)

#define KLIST_REMOVE4(first,last,chain,entry) \
{ \
    if ((entry)->chain.prev == NULL) (first) = (entry)->chain.next; \
    else (entry)->chain.prev->chain.next = (entry)->chain.next; \
    if ((entry)->chain.next == NULL) (last) = (entry)->chain.prev; \
    else (entry)->chain.next->chain.prev = (entry)->chain.prev; \
}

#endif  /*  K_LIST_H  */
