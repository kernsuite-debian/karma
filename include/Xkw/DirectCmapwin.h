#ifndef DIRECTCMAPWIN__H
#define DIRECTCMAPWIN__H

#include <X11/Shell.h>
#include <karma_kcmap_def.h>

extern WidgetClass directCmapwinWidgetClass;
typedef struct _DirectCmapwinClassRec *DirectCmapwinWidgetClass;
typedef struct _DirectCmapwinRec *DirectCmapwinWidget;

#define XtIsDirectCmapwin(w) XtIsSubclass((w), directCmapwinWidgetClass)

#define XkwNcolourbarVisual "colourbarVisual"
#define XkwNkarmaColourmap "karmaColourmap"
#define XkwNcolourCallback "colourCallback"
#define XkwNregenerateColourmap "regenerateColourmap"

#define XkwCKarmaColourmap "KarmaColourmap"
#define XkwCRegenerateColourmap "RegenerateColourmap"

void XkwDirectCmapwinSetColourmap (Widget w, CONST char *new_cmap_name);

#endif
