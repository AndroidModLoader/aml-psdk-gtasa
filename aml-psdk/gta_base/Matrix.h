#ifndef __AML_PSDK_SAMATRIX_H
#define __AML_PSDK_SAMATRIX_H

#include "Vector.h"
#include <aml-psdk/renderware/RwMatrix.h>

struct CMatrix
{
    CVector   right;
    u32       flags;
    CVector   up;
    u32       pad1;
    CVector   at;
    u32       pad2;
    CVector   pos;
    u32       pad3;

    RwMatrix* m_pAttachMatrix;
    bool      m_bOwnsAttachedMatrix;

    inline CMatrix()
    {
        m_pAttachMatrix = NULL;
        m_bOwnsAttachedMatrix = false;
    }

    inline CVector& GetRight() { return right; }
    inline const CVector& GetRight() const { return right; }

    inline CVector& GetForward() { return up; }
    inline const CVector& GetForward() const { return up; }

    inline CVector& GetUp() { return at; }
    inline const CVector& GetUp() const { return at; }

    inline CVector& GetPosition() { return pos; }
    inline const CVector& GetPosition() const { return pos; }
};

#endif // __AML_PSDK_SAMATRIX_H