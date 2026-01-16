#ifndef __AML_PSDK_RWMATRIX_H
#define __AML_PSDK_RWMATRIX_H

#include "RwVector.h"
#include "RwStream.h"

struct rwStreamMatrix
{
    RwV3d right;
    RwV3d up;
    RwV3d at;
    RwV3d pos;
    RwInt32 type;
};
typedef rwStreamMatrix RwMatrixChunkInfo;

enum RwOpCombineType : RwInt32
{
    rwCOMBINEREPLACE = 0x0,
    rwCOMBINEPRECONCAT = 0x1,
    rwCOMBINEPOSTCONCAT = 0x2,
};


struct RwMatrix
{
    RwV3d right;
    u32   flags;
    RwV3d up;
    u32   pad1;
    RwV3d at;
    u32   pad2;
    RwV3d pos;
    u32   pad3;
};

struct RwMatrixTolerance
{
    float Normal;
    float Orthogonal;
    float Identity;
};

struct RQMatrix
{
    union
    {
        float v[16];
        struct
        {
            float f11, f21, f31, f41;
            float f12, f22, f32, f42;
            float f13, f23, f33, f43;
            float f14, f24, f34, f44;
        };
    };
    bool dirty; 
};

inline auto RwMatrixChunkInfoRead = GetMainLibrarySymbol<RwMatrixChunkInfo*(*)(RwStream *stream, RwMatrixChunkInfo *matrixChunkInfo, RwInt32 *bytesRead)>("_Z21RwMatrixChunkInfoReadP8RwStreamP14rwStreamMatrixPi");
inline auto RwMatrixCreate = GetMainLibrarySymbol<RwMatrix*(*)()>("_Z14RwMatrixCreatev");
inline auto RwMatrixDestroy = GetMainLibrarySymbol<RwBool(*)(RwMatrix* matrix)>("_Z15RwMatrixDestroyP11RwMatrixTag");
inline auto RwMatrixInvert = GetMainLibrarySymbol<RwMatrix*(*)(RwMatrix* dst, const RwMatrix* src)>("_Z14RwMatrixInvertP11RwMatrixTagPKS_");
inline auto RwMatrixMultiply = GetMainLibrarySymbol<RwMatrix*(*)(RwMatrix *dst, const RwMatrix *src1, const RwMatrix *src2)>("_Z16RwMatrixMultiplyP11RwMatrixTagPKS_S2_");
inline auto RwMatrixOptimize = GetMainLibrarySymbol<RwMatrix*(*)(RwMatrix *matrix, const RwMatrixTolerance *tolerance)>("_Z16RwMatrixOptimizeP11RwMatrixTagPK17RwMatrixTolerance");
inline auto RwMatrixOrthoNormalize = GetMainLibrarySymbol<RwMatrix*(*)(RwMatrix *dst, const RwMatrix *src)>("_Z22RwMatrixOrthoNormalizeP11RwMatrixTagPKS_");
inline auto RwMatrixQueryRotate = GetMainLibrarySymbol<RwMatrix*(*)(const RwMatrix *matrix, RwV3d *unitAxis, RwReal *angle, RwV3d *center)>("_Z19RwMatrixQueryRotatePK11RwMatrixTagP5RwV3dPfS3_");
inline auto RwMatrixRotate = GetMainLibrarySymbol<RwMatrix*(*)(RwMatrix *matrix, const RwV3d *axis, RwReal angle, RwOpCombineType combineOp)>("_Z14RwMatrixRotateP11RwMatrixTagPK5RwV3df15RwOpCombineType");
inline auto RwMatrixRotateOneMinusCosineSine = GetMainLibrarySymbol<RwMatrix*(*)(RwMatrix *matrix, const RwV3d *unitAxis, RwReal oneMinusCosine, RwReal sine, RwOpCombineType combineOp)>("_Z32RwMatrixRotateOneMinusCosineSineP11RwMatrixTagPK5RwV3dff15RwOpCombineType");
inline auto RwMatrixScale = GetMainLibrarySymbol<RwMatrix*(*)(RwMatrix *matrix, const RwV3d *scale, RwOpCombineType combineOp)>("_Z13RwMatrixScaleP11RwMatrixTagPK5RwV3d15RwOpCombineType");
inline auto RwMatrixSetFreeListCreateParams = GetMainLibrarySymbol<RwMatrix*(*)(RwInt32 blockSize, RwInt32 numBlocksToPrealloc)>("_Z31RwMatrixSetFreeListCreateParamsii");
inline auto RwMatrixStreamGetSize = GetMainLibrarySymbol<RwMatrix*(*)(const RwMatrix *matrix)>("_Z21RwMatrixStreamGetSizePK11RwMatrixTag");
inline auto RwMatrixStreamRead = GetMainLibrarySymbol<RwMatrix*(*)(RwStream *stream, RwMatrix *matrix)>("_Z18RwMatrixStreamReadP8RwStreamP11RwMatrixTag");
inline auto RwMatrixStreamWrite = GetMainLibrarySymbol<RwMatrix*(*)(const RwMatrix *matrix, RwStream *stream)>("_Z19RwMatrixStreamWritePK11RwMatrixTagP8RwStream");
inline auto RwMatrixTransform = GetMainLibrarySymbol<RwMatrix*(*)(RwMatrix *matrix, const RwMatrix *transform, RwOpCombineType combineOp)>("_Z17RwMatrixTransformP11RwMatrixTagPKS_15RwOpCombineType");
inline auto RwMatrixTranslate = GetMainLibrarySymbol<RwMatrix*(*)(RwMatrix *matrix, const RwV3d *translation, RwOpCombineType combineOp)>("_Z17RwMatrixTranslateP11RwMatrixTagPK5RwV3d15RwOpCombineType");
inline auto RwMatrixUpdate = GetMainLibrarySymbol<RwMatrix*(*)(RwMatrix *matrix)>("_Z14RwMatrixUpdateP11RwMatrixTag");
inline auto TestMatrix = GetMainLibrarySymbol<void(*)(RwMatrix *pTempMatrix)>("_Z10TestMatrixP11RwMatrixTag");
inline auto RwEngineGetMatrixTolerances = GetMainLibrarySymbol<RwBool(*)(RwMatrixTolerance *const tolerance)>("_Z27RwEngineGetMatrixTolerancesP17RwMatrixTolerance");
inline auto RwEngineSetMatrixTolerances = GetMainLibrarySymbol<RwBool(*)(const RwMatrixTolerance *const tolerance)>("_Z27RwEngineSetMatrixTolerancesPK17RwMatrixTolerance");

#endif // __AML_PSDK_RWMATRIX_H