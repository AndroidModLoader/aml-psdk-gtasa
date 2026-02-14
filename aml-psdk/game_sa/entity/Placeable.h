#ifndef __AML_PSDK_SAPLACEABLE_H
#define __AML_PSDK_SAPLACEABLE_H

#include <aml-psdk/game_sa/plugin.h>
#include "../base/Matrix.h"

DECL_CLASS(CSimpleTransform)
    // Member functions
    DECL_THISCALL_HEAD(UpdateRwMatrix, _ZNK16CSimpleTransform14UpdateRwMatrixEP11RwMatrixTag, void, RwMatrix *pMatrix)
    DECL_THISCALL_TAIL(UpdateRwMatrix, pMatrix)

    DECL_THISCALL_HEAD(UpdateMatrix, _ZNK16CSimpleTransform12UpdateMatrixEP7CMatrix, void, CMatrix *pMatrix)
    DECL_THISCALL_TAIL(UpdateMatrix, pMatrix)

    DECL_THISCALL_HEAD(Invert, _ZN16CSimpleTransform6InvertERKS_, void, const CSimpleTransform& orig)
    DECL_THISCALL_TAIL(Invert, orig)

    // Member values
    CVector m_vPosn;
    float m_fHeading;
DECL_CLASS_END()
CHECKSIZE(CSimpleTransform, 0x10, 0x10);



DECL_CLASS_VTABLE(CPlaceable)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CPlaceable, _ZN10CPlaceableC2Ev);
    //DECL_DTORCALL(CPlaceable, _ZN10CPlaceableD0Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(InitMatrixArray, _ZN10CPlaceable15InitMatrixArrayEv, void);
    DECL_FASTCALL_SIMPLE(ShutdownMatrixArray, _ZN10CPlaceable19ShutdownMatrixArrayEv, void);

    // Member functions
    DECL_THISCALL_SIMPLE(RemoveMatrix, _ZN10CPlaceable12RemoveMatrixEv, void);
    DECL_THISCALL_SIMPLE(AllocateMatrix, _ZN10CPlaceable14AllocateMatrixEv, void);
    DECL_THISCALL_SIMPLE(AllocateStaticMatrix, _ZN10CPlaceable20AllocateStaticMatrixEv, void);
    DECL_THISCALL_SIMPLE(FreeStaticMatrix, _ZN10CPlaceable16FreeStaticMatrixEv, void);

    DECL_THISCALL_HEAD(SetMatrix, _ZN10CPlaceable9SetMatrixERK7CMatrix, void, const CMatrix& mat)
    DECL_THISCALL_TAIL(SetMatrix, mat)

    DECL_THISCALL_HEAD(IsWithinArea, _ZNK10CPlaceable12IsWithinAreaEffff, b8, float x1, float y1, float x2, float y2)
    DECL_THISCALL_TAIL(IsWithinArea, x1, y1, x2, y2)
    
    DECL_THISCALL_NAMED_HEAD(IsWithinArea2, IsWithinArea, _ZNK10CPlaceable12IsWithinAreaEffffff, b8, float x1, float y1, float z1, float x2, float y2, float z2)
    DECL_THISCALL_TAIL(IsWithinArea2, x1, y1, z1, x2, y2, z2)

    // Helper functions
    inline CVector GetRightDirection()
    {
        if(m_matrix) return m_matrix->GetRight();
        return { cosf(m_placement.m_fHeading), sinf(m_placement.m_fHeading), 0.0f };
    }
    inline CVector GetTopDirection()
    {
        if(m_matrix) return m_matrix->GetForward();
        return { -sinf(m_placement.m_fHeading), cosf(m_placement.m_fHeading), 0.0f };
    }
    inline CVector GetAtDirection()
    {
        if(m_matrix) return m_matrix->GetUp();
        return { 0.0f, 0.0f, 1.0f };
    }
    inline void GetOrientation(float& x, float& y, float& z)
    {
        if(!m_matrix)
        {
            z = m_placement.m_fHeading;
            return;
        }
        x = asinf(m_matrix->up.z);
        float cosx = cosf(x);
        float cosy = m_matrix->at.z / cosx;
        float cosz = m_matrix->up.y / cosx;
        y = acosf(cosy);
        z = acosf(cosz);
    }
    inline CVector& GetRight() const { return m_matrix->GetRight(); }
    inline CVector& GetForward() const { return m_matrix->GetForward(); }
    inline CVector& GetUp() const { return m_matrix->GetUp(); }
    inline const CVector& GetPosition() const { return m_matrix ? m_matrix->GetPosition() : m_placement.m_vPosn; }
    inline CVector& GetPosition() { return m_matrix ? m_matrix->GetPosition() : m_placement.m_vPosn; }
    inline CVector2D& GetPosition2D() { return GetPosition(); }
    inline CMatrix* GetMatrix() { return m_matrix; }

    // Member values
    CSimpleTransform m_placement;
    CMatrix *m_matrix;
DECL_CLASS_END()
CHECKSIZE(CPlaceable, 0x18, 0x20);

#endif // __AML_PSDK_SAPLACEABLE_H