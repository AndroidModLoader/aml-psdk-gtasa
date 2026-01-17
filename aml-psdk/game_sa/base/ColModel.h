#ifndef __AML_PSDK_SACOLMODEL_H
#define __AML_PSDK_SACOLMODEL_H

#include <aml-psdk/gta_base/Vector.h>
#include "../enum/SurfaceType.h"

struct CCollisionData;

struct ColData
{
    u8 m_nSurfaceType;
    u8 m_nPieceType;
    u8 m_lighting;
};

struct CBox
{
    CVector m_vecMin;
    CVector m_vecMax;
    CBox()
    {
        m_vecMin = CVector( 1,  1,  1);
        m_vecMax = CVector(-1, -1, -1);
    }
};

struct CColBox : CBox
{
    ColData m_data;
};

struct CSphere
{
    CVector m_vecCentre;
    float m_fRadius;

    inline void Set(float fRadius, const CVector &vecCentre)
    {
        m_vecCentre = vecCentre;
        m_fRadius = fRadius;
    }
    inline bool InSphere(CVector& pos)
    {
        return (pos - m_vecCentre).MagnitudeSqr() <= (SQ(m_fRadius));
    }
};

struct CColSphere : CSphere
{
    ColData m_data;
};

struct CBoundingBox : CBox
{
    CBoundingBox() : CBox() {}
};

DECL_CLASS(CColModel)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CColModel, _ZN9CColModelC2Ev);
    DECL_DTORCALL(CColModel, _ZN9CColModelD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(MakeMultipleAlloc, _ZN9CColModel17MakeMultipleAllocEv, void);
    DECL_THISCALL_SIMPLE(AllocateData, _ZN9CColModel12AllocateDataEv, void);
    DECL_THISCALL_SIMPLE(RemoveCollisionVolumes, _ZN9CColModel22RemoveCollisionVolumesEv, void);
    DECL_THISCALL_SIMPLE(CalculateTrianglePlanes, _ZN9CColModel23CalculateTrianglePlanesEv, void);
    DECL_THISCALL_SIMPLE(RemoveTrianglePlanes, _ZN9CColModel20RemoveTrianglePlanesEv, void);

    DECL_THISCALL_NAMED_HEAD(AllocateData1, AllocateData, _ZN9CColModel12AllocateDataEiiiiib, void, i32 numSpheres, i32 numBoxes, i32 numLines, i32 numVertices, i32 numTriangles, bool bUseDisksNotLines)
    DECL_THISCALL_TAIL(AllocateData1, numSpheres, numBoxes, numLines, numVertices, numTriangles, bUseDisksNotLines)

    DECL_THISCALL_NAMED_HEAD(AllocateData2, AllocateData, _ZN9CColModel12AllocateDataEi, void, i32 size)
    DECL_THISCALL_TAIL(AllocateData2, size)

    // Member values
    CBoundingBox m_boundBox;
    CSphere m_boundSphere;
    unsigned char m_nColSlot;
    union
    {
        struct
        {
            unsigned char m_bHasCollisionVolumes : 1;
            unsigned char m_bIsSingleColDataAlloc : 1;
            unsigned char m_bIsActive : 1;
        };
        unsigned char m_nFlags;
    };
    CCollisionData* m_pColData;
DECL_CLASS_END()
CHECKSIZE(CColModel, 0x30, 0x38);

struct tColLighting
{
    unsigned char day : 4;
    unsigned char night : 4;
};
struct CColPoint
{
    CVector m_vecPoint;
    float field_C;
    CVector m_vecNormal;
    float field_1C;
    unsigned char m_nSurfaceTypeA; // see eSurfaceType
    unsigned char m_nPieceTypeA;
    tColLighting m_nLightingA;
    char _pad;
    unsigned char m_nSurfaceTypeB; // see eSurfaceType
    unsigned char m_nPieceTypeB;
    tColLighting m_nLightingB;
    char _pad2;
    float m_fDepth;
};

struct CStoredCollPoly
{
    CVector      m_aMeshVertices[3];
    bool         m_bIsActual;
    unsigned int m_nLighting;
};

#endif // __AML_PSDK_SACOLMODEL_H