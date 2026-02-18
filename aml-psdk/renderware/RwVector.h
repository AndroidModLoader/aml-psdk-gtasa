#ifndef __AML_PSDK_RWVECTOR_H
#define __AML_PSDK_RWVECTOR_H

#include <aml-psdk/gta_base/Vector.h>
#include "RwBase.h"

#define RwV2d CVector2D
#define RwV3d CVector

union RQVector
{
    float v[4];
    struct { float x, y, z, w; };
    struct { float r, g, b, a; };

    inline RQVector operator*(float f)
    {
        RQVector result;
        result.x = this->x * f;
        result.y = this->y * f;
        result.z = this->z * f;
        result.w = this->w * f;
        return result;
    }
    inline RQVector operator*=(float f)
    {
        this->x *= f;
        this->y *= f;
        this->z *= f;
        this->w *= f;
        return *this;
    }
};

#endif // __AML_PSDK_RWVECTOR_H