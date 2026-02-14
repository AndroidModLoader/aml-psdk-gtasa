#ifndef __AML_PSDK_SAFXSYSTEM_H
#define __AML_PSDK_SAFXSYSTEM_H

#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/game_sa/audio/AEAudioEntity.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/renderware/RwMatrix.h>

struct Particle_c;
struct FxPrtMult_c;
struct FxSystemBP_c;
struct FxBox_c;
struct CEntity;
struct FxSphere_c;
struct FxPrim_c;

enum eFxSystemKillStatus : u8
{
    FX_NOT_KILLED = 0,
    FX_PLAY_AND_KILL = 1,
    FX_KILLED = 2
};

enum eFxSystemPlayStatus : u8
{
    FX_PLAYING = 0,
    FX_STOPPED = 1
};

typedef void (*particleCB)(Particle_c *, int, void **);

DECL_CLASS_BASED(FxSystem_c, ListItem_c)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(UpdateBoundingBoxCB, _ZN10FxSystem_c19UpdateBoundingBoxCBEP10Particle_ciPPv, void, Particle_c *prtPtr, i32 type, void **userPtr);

    // Member functions
    DECL_THISCALL_SIMPLE(Play, _ZN10FxSystem_c4PlayEv, void);
    DECL_THISCALL_SIMPLE(Pause, _ZN10FxSystem_c5PauseEv, void);
    DECL_THISCALL_SIMPLE(Stop, _ZN10FxSystem_c4StopEv, void);
    DECL_THISCALL_SIMPLE(PlayAndKill, _ZN10FxSystem_c11PlayAndKillEv, void);
    DECL_THISCALL_SIMPLE(Kill, _ZN10FxSystem_c4KillEv, void);
    DECL_THISCALL_SIMPLE(Exit, _ZN10FxSystem_c4ExitEv, void);
    DECL_THISCALL_SIMPLE(IsVisible, _ZN10FxSystem_c9IsVisibleEv, u8);
    DECL_THISCALL_SIMPLE(CopyParentMatrix, _ZN10FxSystem_c16CopyParentMatrixEv, void);
    DECL_THISCALL_SIMPLE(GetPlayStatus, _ZN10FxSystem_c13GetPlayStatusEv, int);
    DECL_THISCALL_SIMPLE(ResetBoundingSphere, _ZN10FxSystem_c19ResetBoundingSphereEv, void);
    
    DECL_THISCALL_HEAD(AttachToBone, _ZN10FxSystem_c12AttachToBoneEP7CEntityi, void, CEntity *pEntity, i32 boneTag)
    DECL_THISCALL_TAIL(AttachToBone, pEntity, boneTag)
    
    DECL_THISCALL_NAMED_HEAD(AddParticle1, AddParticle, _ZN10FxSystem_c11AddParticleEP5RwV3dS1_fP11FxPrtMult_cfffh, void, RwV3d *pos, RwV3d *vel, float timeSince, FxPrtMult_c *fxMults, float zRot, float lightMult, float lightMultLimit, u8 createLocal)
    DECL_THISCALL_TAIL(AddParticle1, pos, vel, timeSince, fxMults, zRot, lightMult, lightMultLimit, createLocal)
    
    DECL_THISCALL_NAMED_HEAD(AddParticle2, AddParticle, _ZN10FxSystem_c11AddParticleEP11RwMatrixTagP5RwV3dfP11FxPrtMult_cfffh, void, RwMatrix *mat, RwV3d *vel, float timeSince, FxPrtMult_c *fxMults, float zRot, float lightMult, float lightMultLimit, u8 createLocal)
    DECL_THISCALL_TAIL(AddParticle2, mat, vel, timeSince, fxMults, zRot, lightMult, lightMultLimit, createLocal)
    
    DECL_THISCALL_HEAD(EnablePrim, _ZN10FxSystem_c10EnablePrimEih, void, i32 primId, u8 on)
    DECL_THISCALL_TAIL(EnablePrim, primId, on)
    
    DECL_THISCALL_HEAD(SetMatrix, _ZN10FxSystem_c9SetMatrixEP11RwMatrixTag, void, RwMatrix *mat)
    DECL_THISCALL_TAIL(SetMatrix, mat)
    
    DECL_THISCALL_HEAD(SetOffsetPos, _ZN10FxSystem_c12SetOffsetPosEP5RwV3d, void, RwV3d *pos)
    DECL_THISCALL_TAIL(SetOffsetPos, pos)
    
    DECL_THISCALL_HEAD(AddOffsetPos, _ZN10FxSystem_c12AddOffsetPosEP5RwV3d, void, RwV3d *pos)
    DECL_THISCALL_TAIL(AddOffsetPos, pos)
    
    DECL_THISCALL_HEAD(SetConstTime, _ZN10FxSystem_c12SetConstTimeEhf, void, u8 on, float time)
    DECL_THISCALL_TAIL(SetConstTime, on, time)
    
    DECL_THISCALL_HEAD(SetRateMult, _ZN10FxSystem_c11SetRateMultEf, void, float rateMult)
    DECL_THISCALL_TAIL(SetRateMult, rateMult)
    
    DECL_THISCALL_HEAD(SetTimeMult, _ZN10FxSystem_c11SetTimeMultEf, void, float timeMult)
    DECL_THISCALL_TAIL(SetTimeMult, timeMult)
    
    DECL_THISCALL_HEAD(SetVelAdd, _ZN10FxSystem_c9SetVelAddEP5RwV3d, void, RwV3d *vel)
    DECL_THISCALL_TAIL(SetVelAdd, vel)
    
    DECL_THISCALL_HEAD(Init, _ZN10FxSystem_c4InitEP12FxSystemBP_cP11RwMatrixTagS3_, u8, FxSystemBP_c *fxSysBPPtr, RwMatrix *offsetMat, RwMatrix *parentMat)
    DECL_THISCALL_TAIL(Init, fxSysBPPtr, offsetMat, parentMat)
    
    DECL_THISCALL_HEAD(GetBoundingSphereWld, _ZN10FxSystem_c20GetBoundingSphereWldEP10FxSphere_c, u8, FxSphere_c *bSphere)
    DECL_THISCALL_TAIL(GetBoundingSphereWld, bSphere)
    
    DECL_THISCALL_HEAD(Update, _ZN10FxSystem_c6UpdateEP8RwCameraf, u8, RwCamera *camPtr, float deltaTime)
    DECL_THISCALL_TAIL(Update, camPtr, deltaTime)
    
    DECL_THISCALL_HEAD(GetCompositeMatrix, _ZN10FxSystem_c18GetCompositeMatrixEP11RwMatrixTag, void, RwMatrix *compMat)
    DECL_THISCALL_TAIL(GetCompositeMatrix, compMat)
    
    DECL_THISCALL_HEAD(DoFxAudio, _ZN10FxSystem_c9DoFxAudioE7CVector, void, CVector fxPos)
    DECL_THISCALL_TAIL(DoFxAudio, fxPos)
    
    DECL_THISCALL_HEAD(SetLocalParticles, _ZN10FxSystem_c17SetLocalParticlesEh, void, u8 on)
    DECL_THISCALL_TAIL(SetLocalParticles, on)
    
    DECL_THISCALL_HEAD(ForAllParticles, _ZN10FxSystem_c15ForAllParticlesEPFvP10Particle_ciPPvES2_, void, particleCB cback, void *userPtr)
    DECL_THISCALL_TAIL(ForAllParticles, cback, userPtr)
    
    DECL_THISCALL_HEAD(GetBoundingBox, _ZN10FxSystem_c14GetBoundingBoxEP7FxBox_c, void, FxBox_c *bBox)
    DECL_THISCALL_TAIL(GetBoundingBox, bBox)
    
    DECL_THISCALL_HEAD(GetBoundingSphereLcl, _ZN10FxSystem_c20GetBoundingSphereLclEP10FxSphere_c, u8, FxSphere_c *bSphere)
    DECL_THISCALL_TAIL(GetBoundingSphereLcl, bSphere)
    
    DECL_THISCALL_HEAD(SetBoundingSphere, _ZN10FxSystem_c17SetBoundingSphereEP10FxSphere_c, void, FxSphere_c *bSphere)
    DECL_THISCALL_TAIL(SetBoundingSphere, bSphere)
    
    DECL_THISCALL_HEAD(SetZTestEnable, _ZN10FxSystem_c14SetZTestEnableEh, u8, u8 on)
    DECL_THISCALL_TAIL(SetZTestEnable, on)
    
    DECL_THISCALL_HEAD(SetMustCreatePrts, _ZN10FxSystem_c17SetMustCreatePrtsEh, void, u8 on)
    DECL_THISCALL_TAIL(SetMustCreatePrts, on)

    // Helper functions
    inline CAEFireAudioEntity* GetFireAudio() { return &m_fireAudio; }

    // Member values
    void              *m_pBlueprint;
    RwMatrix          *m_pParentMatrix;
    CEntity           *m_pEntity; // mobile stuff
    RwMatrix           m_localMatrix;
    unsigned char      m_nPlayStatus; // see eFxSystemPlayStatus
    unsigned char      m_nKillStatus; // see eFxSystemKillStatus
    unsigned char      m_bConstTimeSet;
    float              m_fCurrentProgress;
    float              m_fCameraDistance;
    unsigned short     m_nConstTime;
    unsigned short     m_nRateMult;
    unsigned short     m_nTimeMult;
    struct
    {
        unsigned char  bOwnedParentMatrix: 1;
        unsigned char  bLocalParticles : 1;
        unsigned char  bZTestEnabled : 1;
        unsigned char  bDontCreateParticles : 1;
        unsigned char  bPreviouslyCulled : 1;
        unsigned char  bMustCreatePtrs : 1;
    } m_nFlags;
    float              m_fLoopInterval;
    CVector            m_vecVelAdd;
    FxSphere_c        *m_pBounding;
    FxPrim_c         **m_pPrimsPtrList;
    CAEFireAudioEntity m_fireAudio;
DECL_CLASS_END()
CHECKSIZE(FxSystem_c, 0x108, 0x148);

#endif // __AML_PSDK_SAFXSYSTEM_H