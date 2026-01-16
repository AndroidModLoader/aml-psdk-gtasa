#ifndef __AML_PSDK_SAPLACEABLE_H
#define __AML_PSDK_SAPLACEABLE_H

#include <aml-psdk/gta_base/Matrix.h>

struct CSimpleTransform
{
    CVector m_vPosn;
    float m_fHeading;

    // TODO: thiscalls
};

struct CPlaceable : SimpleVTable
{
    static inline auto InitMatrixArray = GetMainLibrarySymbol<void(*)()>("_ZN10CPlaceable15InitMatrixArrayEv");
    static inline auto ShutdownMatrixArray = GetMainLibrarySymbol<void(*)()>("_ZN10CPlaceable19ShutdownMatrixArrayEv");

    CSimpleTransform m_placement;
    CMatrix *m_matrix;

    // TODO: thiscalls
};

#endif // __AML_PSDK_SAPLACEABLE_H