#ifndef __AML_PSDK_RWRGBA_H
#define __AML_PSDK_RWRGBA_H

#include <aml-psdk/sdk_base.h>
#include "RwVector.h"
#include <aml-psdk/gta_base/RGBA.h>

#define RwRGBA CRGBA

struct RwRGBAReal
{
    RwReal red;
    RwReal green;
    RwReal blue;
    RwReal alpha;
};

#endif // __AML_PSDK_RWRGBA_H
