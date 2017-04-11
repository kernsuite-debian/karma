#ifndef SIMPLECOLOURBAR__H
#define SIMPLECOLOURBAR__H

#include <karma_kcmap_def.h>

extern WidgetClass simpleColourbarWidgetClass;
typedef struct _SimpleColourbarClassRec *SimpleColourbarWidgetClass;
typedef struct _SimpleColourbarRec *SimpleColourbarWidget;

#define XtIsSimpleColourbar(w) XtIsSubclass((w), simpleColourbarWidgetClass)

#define XkwNkarmaColourmap "karmaColourmap"
#define XkwNmaskRed "maskRed"
#define XkwNmaskGreen "maskGreen"
#define XkwNmaskBlue "maskBlue"

#define XkwCKarmaColourmap "KarmaColourmap"
#define XkwCMaskColour "MaskColour"

#endif
