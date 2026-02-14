#ifndef __AML_PSDK_SAFXMANAGER_H
#define __AML_PSDK_SAFXMANAGER_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/base/FxPrimitives.h>
#include <aml-psdk/renderware/RwRGBA.h>

struct RwCamera;
struct FxSystem_c;
struct FxEmitterPrt_c;
struct RwMatrix;
struct FxSystemBP_c;

DECL_CLASS(FxMemoryPool_c)
    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN14FxMemoryPool_c4InitEv, u8);
    DECL_THISCALL_SIMPLE(Exit, _ZN14FxMemoryPool_c4ExitEv, void);
    DECL_THISCALL_SIMPLE(Reset, _ZN14FxMemoryPool_c5ResetEv, void);
    DECL_THISCALL_SIMPLE(Optimise, _ZN14FxMemoryPool_c8OptimiseEv, void);
    
    DECL_THISCALL_HEAD(GetMem, _ZN14FxMemoryPool_c6GetMemEii, char*, i32 numBytes, i32 alignment)
    DECL_THISCALL_TAIL(GetMem, numBytes, alignment)

    // Member values
    char *data;
    unsigned int size;
    unsigned int position;
DECL_CLASS_END()

DECL_CLASS(FxManager_c)
    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN11FxManager_c4InitEv, u8);
    DECL_THISCALL_SIMPLE(Exit, _ZN11FxManager_c4ExitEv, void);
    DECL_THISCALL_SIMPLE(DestroyAllFxSystems, _ZN11FxManager_c19DestroyAllFxSystemsEv, void);
    DECL_THISCALL_SIMPLE(GetFrustumInfo, _ZN11FxManager_c14GetFrustumInfoEv, FxFrustumInfo_c*);
    DECL_THISCALL_SIMPLE(UnloadFxProject, _ZN11FxManager_c15UnloadFxProjectEv, void);
    DECL_THISCALL_SIMPLE(FxRwMatrixCreate, _ZN11FxManager_c16FxRwMatrixCreateEv, RwMatrix*);
    DECL_THISCALL_SIMPLE(FreeUpParticle, _ZN11FxManager_c14FreeUpParticleEv, void);
    
    DECL_THISCALL_HEAD(CalcFrustumInfo, _ZN11FxManager_c15CalcFrustumInfoEP8RwCamera, void, RwCamera *camPtr)
    DECL_THISCALL_TAIL(CalcFrustumInfo, camPtr)
    
    DECL_THISCALL_HEAD(Update, _ZN11FxManager_c6UpdateEP8RwCameraf, void, RwCamera *camPtr, float deltaTime)
    DECL_THISCALL_TAIL(Update, camPtr, deltaTime)
    
    DECL_THISCALL_HEAD(DestroyFxSystem, _ZN11FxManager_c15DestroyFxSystemEP10FxSystem_c, void, FxSystem_c *fxSysPtr)
    DECL_THISCALL_TAIL(DestroyFxSystem, fxSysPtr)
    
    DECL_THISCALL_HEAD(Render, _ZN11FxManager_c6RenderEP8RwCamerah, void, RwCamera *camPtr, u8 doHeatHaze)
    DECL_THISCALL_TAIL(Render, camPtr, doHeatHaze)
    
    DECL_THISCALL_NAMED_HEAD(CreateFxSystem1, CreateFxSystem, _ZN11FxManager_c14CreateFxSystemEPcP11RwMatrixTagS2_h, FxSystem_c*, char *bpName, RwMatrix *offsetMat, RwMatrix *parentMat, u8 forceCreation)
    DECL_THISCALL_TAIL(CreateFxSystem1, bpName, offsetMat, parentMat, forceCreation)
    
    DECL_THISCALL_NAMED_HEAD(CreateFxSystem2, CreateFxSystem, _ZN11FxManager_c14CreateFxSystemEP12FxSystemBP_cP11RwMatrixTagS3_h, FxSystem_c*, FxSystemBP_c *fxSysBPPtr, RwMatrix *offsetMat, RwMatrix *parentMat, u8 forceCreation)
    DECL_THISCALL_TAIL(CreateFxSystem2, fxSysBPPtr, offsetMat, parentMat, forceCreation)
    
    DECL_THISCALL_HEAD(FindFxSystem, _ZN11FxManager_c14FindFxSystemBPEPc, void, char *name)
    DECL_THISCALL_TAIL(FindFxSystem, name)
    
    DECL_THISCALL_NAMED_HEAD(CreateFxSystem3, CreateFxSystem, _ZN11FxManager_c14CreateFxSystemEPcP5RwV3dP11RwMatrixTagh, FxSystem_c*, char *bpName, RwV3d *offsetPos, RwMatrix *parentMat, u8 forceCreation)
    DECL_THISCALL_TAIL(CreateFxSystem3, bpName, offsetPos, parentMat, forceCreation)
    
    DECL_THISCALL_NAMED_HEAD(CreateFxSystem4, CreateFxSystem, _ZN11FxManager_c14CreateFxSystemEP12FxSystemBP_cP5RwV3dP11RwMatrixTagh, FxSystem_c*, FxSystemBP_c *fxSysBPPtr, RwV3d *offsetPos, RwMatrix *parentMat, u8 forceCreation)
    DECL_THISCALL_TAIL(CreateFxSystem4, fxSysBPPtr, offsetPos, parentMat, forceCreation)
    
    DECL_THISCALL_HEAD(ShouldCreate, _ZN11FxManager_c12ShouldCreateEP12FxSystemBP_cP11RwMatrixTagS3_h, u8, FxSystemBP_c *fxSysBPPtr, RwMatrix *offsetMat, RwMatrix *parentMat, u8 forceCreation)
    DECL_THISCALL_TAIL(ShouldCreate, fxSysBPPtr, offsetMat, parentMat, forceCreation)
    
    DECL_THISCALL_HEAD(FxRwMatrixDestroy, _ZN11FxManager_c17FxRwMatrixDestroyEP11RwMatrixTag, void, RwMatrix *pTempMatrix)
    DECL_THISCALL_TAIL(FxRwMatrixDestroy, pTempMatrix)
    
    DECL_THISCALL_HEAD(ReturnParticle, _ZN11FxManager_c14ReturnParticleEP14FxEmitterPrt_c, void, FxEmitterPrt_c *prtPtr)
    DECL_THISCALL_TAIL(ReturnParticle, prtPtr)
    
    DECL_THISCALL_HEAD(GetParticle, _ZN11FxManager_c11GetParticleEa, Particle_c*, i8 primType)
    DECL_THISCALL_TAIL(GetParticle, primType)
    
    DECL_THISCALL_HEAD(SetWindData, _ZN11FxManager_c11SetWindDataEP5RwV3dPf, void, RwV3d *dir, float *strength)
    DECL_THISCALL_TAIL(SetWindData, dir, strength)
    
    DECL_THISCALL_HEAD(LoadFxProject, _ZN11FxManager_c13LoadFxProjectEPc, u8, char *filename)
    DECL_THISCALL_TAIL(LoadFxProject, filename)
    
    DECL_THISCALL_HEAD(LoadFxSystemBP, BYBIT(_ZN11FxManager_c14LoadFxSystemBPEPcj ,_ZN11FxManager_c14LoadFxSystemBPEPcy), void, char *filename, FILESTREAM fileId)
    DECL_THISCALL_TAIL(LoadFxSystemBP, filename, fileId)

    // Member values
    TList_c<FxSystemBP_c>   m_fxSystemBPList;
    TList_c<FxSystem_c>     m_fxSystemList;
    FxEmitterPrt_c         *m_pFxEmitters;
    TList_c<FxEmitterPrt_c> m_fxEmitterPrtList;
    int                     m_nFxTxdIndex;
    RwV3d                  *m_pWindDir;
    float                  *m_pfWindSpeed;
    FxFrustumInfo_c         m_frustum;
    unsigned int            m_nCurrentMatrix;
    RwMatrix               *m_apMatrices[8];
    FxMemoryPool_c          m_pool;
    unsigned char           m_bFoundHeatHazeInfo;
DECL_CLASS_END()
CHECKSIZE(FxManager_c, 0xBC, 0x118);

DECL_OBJECT_PLT_GLOBAL(FxManager_c, g_fxMan, BYBIT(0x677020, 0x84C078) );

#define g_fxMan g_fxMan()

#endif // __AML_PSDK_SAFXMANAGER_H