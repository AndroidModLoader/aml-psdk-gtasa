#ifndef __AML_PSDK_GTAQUAT_H
#define __AML_PSDK_GTAQUAT_H

#include "Vector.h"
#include <aml-psdk/renderware/RwMatrix.h>

DECL_CLASS(CQuaternion)
    // Member functions
    DECL_THISCALL_HEAD(Set, _ZN11CQuaternion3SetERK11RwMatrixTag, void, RwMatrix &mat)
    DECL_THISCALL_TAIL(Set, mat)

    DECL_THISCALL_NAMED_HEAD(Set1, Set, _ZN11CQuaternion3SetEfff, void, float ax, float ay, float az)
    DECL_THISCALL_TAIL(Set1, ax, ay, az)

    DECL_THISCALL_NAMED_HEAD(Set2, Set, _ZN11CQuaternion3SetEP5RwV3df, void, RwV3d *pVec, float fRotation)
    DECL_THISCALL_TAIL(Set2, pVec, fRotation)

    DECL_THISCALL_HEAD(Get, _ZNK11CQuaternion3GetEP11RwMatrixTag, void, RwMatrix *pmat)
    DECL_THISCALL_TAIL(Get, pmat)

    DECL_THISCALL_NAMED_HEAD(Get1, Get, _ZNK11CQuaternion3GetEPfS0_S0_, void, float *pax, float *pay, float *paz)
    DECL_THISCALL_TAIL(Get1, pax, pay, paz)

    DECL_THISCALL_NAMED_HEAD(Get2, Get, _ZNK11CQuaternion3GetEP5RwV3dPf, void, RwV3d *pVec, float *fRotation)
    DECL_THISCALL_TAIL(Get2, pVec, fRotation)

    DECL_THISCALL_HEAD(Multiply, _ZN11CQuaternion8MultiplyERKS_S1_, void, const CQuaternion &quat1, const CQuaternion &quat2)
    DECL_THISCALL_TAIL(Multiply, quat1, quat2)

    DECL_THISCALL_HEAD(Slerp, _ZN11CQuaternion5SlerpERKS_S1_fff, void, const CQuaternion &quatStart, const CQuaternion &quatEnd, float fTheta, float fOOSinTheta, float fInterpValue)
    DECL_THISCALL_TAIL(Slerp, quatStart, quatEnd, fTheta, fOOSinTheta, fInterpValue)

    DECL_THISCALL_NAMED_HEAD(Slerp1, Slerp, _ZN11CQuaternion5SlerpERKS_S1_f, void, const CQuaternion &quatStart, const CQuaternion &quatEnd, float fInterpValue)
    DECL_THISCALL_TAIL(Slerp1, quatStart, quatEnd, fInterpValue)

    // Helper functions
    inline void Conjugate()
    {
        imag.x = -imag.x;
        imag.y = -imag.y;
        imag.z = -imag.z;
    }
    inline float GetLengthSquared()
    {
        return SQ(real) + imag.MagnitudeSqr();
    }
    inline void Copy(CQuaternion const& from)
    {
        *this = from;
    }
    inline float Dot(CQuaternion const& a)
    {
        return (real * a.real + imag.x * a.imag.x + imag.y * a.imag.y + imag.z * a.imag.z);
    }
    inline void Normalise()
    {
        float norm = GetLengthSquared();
        if(norm == 0.0f)
        {
            real = 1.0;
        }
        else
        {
            float invNormSqrt = 1.0 / sqrtf(norm);
            imag.x = invNormSqrt * imag.x;
            imag.y = invNormSqrt * imag.y;
            imag.z = invNormSqrt * imag.z;
            real = invNormSqrt * real;
        }
    }

    // Member values
    CVector imag;
    float real;
DECL_CLASS_END()

#endif // __AML_PSDK_GTAQUAT_H