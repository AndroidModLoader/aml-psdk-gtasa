#ifndef __AML_PSDK_SAPHYSICAL_H
#define __AML_PSDK_SAPHYSICAL_H

#include "Entity.h"
#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/gta_base/Quaternion.h>
#include "../enum/WeaponType.h"

struct CRealTimeShadow;
struct RtQuat;

DECL_CLASS_BASED(CPhysical, CEntity)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CPhysical, _ZN9CPhysicalC2Ev);
    DECL_DTORCALL(CPhysical, _ZN9CPhysicalD2Ev);

    // Static functions
    DECL_FASTCALL_SIMPLE(PlacePhysicalRelativeToOtherPhysical, _ZN9CPhysical36PlacePhysicalRelativeToOtherPhysicalEPS_S0_7CVector, void, CPhysical* physical1, CPhysical* physical2, CVector offset);

    // Member functions
    DECL_THISCALL_SIMPLE(RemoveAndAdd, _ZN9CPhysical12RemoveAndAddEv, void);
    DECL_THISCALL_SIMPLE(AddToMovingList, _ZN9CPhysical15AddToMovingListEv, void);
    DECL_THISCALL_SIMPLE(RemoveFromMovingList, _ZN9CPhysical20RemoveFromMovingListEv, void);
    DECL_THISCALL_SIMPLE(ApplyMoveSpeed, _ZN9CPhysical14ApplyMoveSpeedEv, void);
    DECL_THISCALL_SIMPLE(ApplyTurnSpeed, _ZN9CPhysical14ApplyTurnSpeedEv, void);
    DECL_THISCALL_SIMPLE(ApplySpeed, _ZN9CPhysical10ApplySpeedEv, void);
    DECL_THISCALL_SIMPLE(UnsetIsInSafePosition, _ZN9CPhysical21UnsetIsInSafePositionEv, void);
    DECL_THISCALL_SIMPLE(ApplyGravity, _ZN9CPhysical12ApplyGravityEv, void);
    DECL_THISCALL_SIMPLE(ApplyFriction, _ZN9CPhysical13ApplyFrictionEv, void);
    DECL_THISCALL_SIMPLE(ApplyAirResistance, _ZN9CPhysical18ApplyAirResistanceEv, void);
    DECL_THISCALL_SIMPLE(SkipPhysics, _ZN9CPhysical11SkipPhysicsEv, void);
    DECL_THISCALL_SIMPLE(CheckCollision_SimpleCar, _ZN9CPhysical24CheckCollision_SimpleCarEv, bool);
    DECL_THISCALL_SIMPLE(CheckCollision, _ZN9CPhysical14CheckCollisionEv, bool);
    DECL_THISCALL_SIMPLE(GetHasCollidedWithAnyObject, _ZN9CPhysical27GetHasCollidedWithAnyObjectEv, void);
    DECL_THISCALL_SIMPLE(PositionAttachedEntity, _ZN9CPhysical22PositionAttachedEntityEv, void);
    DECL_THISCALL_SIMPLE(DettachAutoAttachedEntity, _ZN9CPhysical25DettachAutoAttachedEntityEv, void);
    DECL_THISCALL_SIMPLE(GetLightingTotal, _ZNK9CPhysical16GetLightingTotalEv, float);

    DECL_THISCALL_HEAD(SetDamagedPieceRecord, _ZN9CPhysical21SetDamagedPieceRecordEfP7CEntityR9CColPointf, void, float fImpulseMagnitude, CEntity *pEntity, CColPoint &colPoint, float fReverseNormal)
    DECL_THISCALL_TAIL(SetDamagedPieceRecord, fImpulseMagnitude, pEntity, colPoint, fReverseNormal)

    DECL_THISCALL_HEAD(ApplyMoveForce, _ZN9CPhysical14ApplyMoveForceE7CVector, void, CVector vecForce)
    DECL_THISCALL_TAIL(ApplyMoveForce, vecForce)

    DECL_THISCALL_HEAD(ApplyTurnForce, _ZN9CPhysical14ApplyTurnForceE7CVectorS0_, void, CVector vecForce, CVector vecOffset)
    DECL_THISCALL_TAIL(ApplyTurnForce, vecForce, vecOffset)

    DECL_THISCALL_HEAD(ApplyForce, _ZN9CPhysical10ApplyForceE7CVectorS0_b, void, CVector vecForce, CVector vecOffset, bool bValidTorque)
    DECL_THISCALL_TAIL(ApplyForce, vecForce, vecOffset, bValidTorque)

    DECL_THISCALL_HEAD(GetSpeed, _ZN9CPhysical8GetSpeedE7CVector, CVector, CVector vecOffset)
    DECL_THISCALL_TAIL(GetSpeed, vecOffset)

    DECL_THISCALL_NAMED_HEAD(ApplyFriction1, ApplyFriction, _ZN9CPhysical13ApplyFrictionEfR9CColPoint, bool, float fAdhesiveLimit, CColPoint &colPoint)
    DECL_THISCALL_TAIL(ApplyFriction1, fAdhesiveLimit, colPoint)

    DECL_THISCALL_HEAD(ApplyFrictionMoveForce, _ZN9CPhysical22ApplyFrictionMoveForceE7CVector, void, CVector vecForce)
    DECL_THISCALL_TAIL(ApplyFrictionMoveForce, vecForce)

    DECL_THISCALL_HEAD(ApplyFrictionTurnForce, _ZN9CPhysical22ApplyFrictionTurnForceE7CVectorS0_, void, CVector vecForce, CVector vecOffset)
    DECL_THISCALL_TAIL(ApplyFrictionTurnForce, vecForce, vecOffset)

    DECL_THISCALL_HEAD(ApplyFrictionForce, _ZN9CPhysical18ApplyFrictionForceE7CVectorS0_, void, CVector vecForce, CVector vecOffset)
    DECL_THISCALL_TAIL(ApplyFrictionForce, vecForce, vecOffset)

    DECL_THISCALL_HEAD(ProcessCollisionSectorList, _ZN9CPhysical26ProcessCollisionSectorListEii, void, i32 x, i32 y)
    DECL_THISCALL_TAIL(ProcessCollisionSectorList, x, y)

    DECL_THISCALL_HEAD(ProcessCollisionSectorList_SimpleCar, _ZN9CPhysical36ProcessCollisionSectorList_SimpleCarEP13CRepeatSector, bool, CRepeatSector *pSectorList)
    DECL_THISCALL_TAIL(ProcessCollisionSectorList_SimpleCar, pSectorList)

    DECL_THISCALL_HEAD(ProcessShiftSectorList, _ZN9CPhysical22ProcessShiftSectorListEii, void, i32 x, i32 y)
    DECL_THISCALL_TAIL(ProcessShiftSectorList, x, y)

    DECL_THISCALL_HEAD(TestCollision, _ZN9CPhysical13TestCollisionEb, bool, bool bApplySpeed)
    DECL_THISCALL_TAIL(TestCollision, bApplySpeed)

    DECL_THISCALL_HEAD(AddCollisionRecord, _ZN9CPhysical18AddCollisionRecordEP7CEntity, void, CEntity *pEntity)
    DECL_THISCALL_TAIL(AddCollisionRecord, pEntity)

    DECL_THISCALL_HEAD(GetHasCollidedWith, _ZN9CPhysical18GetHasCollidedWithEP7CEntity, bool, CEntity *pEntity)
    DECL_THISCALL_TAIL(GetHasCollidedWith, pEntity)

    DECL_THISCALL_HEAD(ApplyCollision, _ZN9CPhysical14ApplyCollisionEP7CEntityR9CColPointRf, bool, CEntity *pEntity, CColPoint &colPoint, float &fImpulseMagnitude)
    DECL_THISCALL_TAIL(ApplyCollision, pEntity, colPoint, fImpulseMagnitude)

    DECL_THISCALL_NAMED_HEAD(ApplyCollision1, ApplyCollision, _ZN9CPhysical14ApplyCollisionEPS_R9CColPointRfS3_, bool, CPhysical *pPhysical, CColPoint &colPoint, float &fImpulseMagnitudeA, float &fImpulseMagnitudeB)
    DECL_THISCALL_TAIL(ApplyCollision1, pPhysical, colPoint, fImpulseMagnitudeA, fImpulseMagnitudeB)

    DECL_THISCALL_HEAD(ApplyCollisionAlt, _ZN9CPhysical17ApplyCollisionAltEP7CEntityR9CColPointRfR7CVectorS6_, bool, CEntity *pEntity, CColPoint &colPoint, float &fImpulseMagnitude, CVector &vecMoveInc, CVector &vecTurnInc)
    DECL_THISCALL_TAIL(ApplyCollisionAlt, pEntity, colPoint, fImpulseMagnitude, vecMoveInc, vecTurnInc)

    DECL_THISCALL_HEAD(ApplySoftCollision, _ZN9CPhysical18ApplySoftCollisionEP7CEntityR9CColPointRf, bool, CEntity *pEntity, CColPoint *colPoint, float *fImpulseMagnitude)
    DECL_THISCALL_TAIL(ApplySoftCollision, pEntity, colPoint, fImpulseMagnitude)

    DECL_THISCALL_NAMED_HEAD(ApplySoftCollision1, ApplySoftCollision, _ZN9CPhysical18ApplySoftCollisionEPS_R9CColPointRfS3_, bool, CPhysical *pPhysical, CColPoint *colPoint, float *fImpulseMagnitudeA, float *fImpulseMagnitudeB)
    DECL_THISCALL_TAIL(ApplySoftCollision1, pPhysical, colPoint, fImpulseMagnitudeA, fImpulseMagnitudeB)

    DECL_THISCALL_HEAD(ApplySpringCollision, _ZN9CPhysical20ApplySpringCollisionEfR7CVectorS1_ffRf, bool, float fSpringStrength, CVector &vecDirection, CVector &vecOffset, float fCompressionRatio, float fSuspensionBias, float &fImpulseMagnitude)
    DECL_THISCALL_TAIL(ApplySpringCollision, fSpringStrength, vecDirection, vecOffset, fCompressionRatio, fSuspensionBias, fImpulseMagnitude)

    DECL_THISCALL_HEAD(ApplySpringCollisionAlt, _ZN9CPhysical23ApplySpringCollisionAltEfR7CVectorS1_ffS1_Rf, bool, float fSpringStrength, CVector &vecDirection, CVector &vecOffset, float fCompressionRatio, float fSuspensionBias, CVector &vecColNormal, float &fImpulseMagnitude)
    DECL_THISCALL_TAIL(ApplySpringCollisionAlt, fSpringStrength, vecDirection, vecOffset, fCompressionRatio, fSuspensionBias, vecColNormal, fImpulseMagnitude)

    DECL_THISCALL_HEAD(ApplySpringDampening, _ZN9CPhysical20ApplySpringDampeningEffR7CVectorS1_S1_, bool, float fDampeningScalar, float fSpringForce, CVector &vecDirection, CVector &vecOffset, CVector &vecSpeed)
    DECL_THISCALL_TAIL(ApplySpringDampening, fDampeningScalar, fSpringForce, vecDirection, vecOffset, vecSpeed)

    DECL_THISCALL_HEAD(ApplySpringDampeningOld, _ZN9CPhysical23ApplySpringDampeningOldEffR7CVectorS1_S1_, bool, float fDampeningScalar, float fSpringForce, CVector &vecDirection, CVector &vecOffset, CVector &vecSpeed)
    DECL_THISCALL_TAIL(ApplySpringDampeningOld, fDampeningScalar, fSpringForce, vecDirection, vecOffset, vecSpeed)

    DECL_THISCALL_NAMED_HEAD(ApplyFriction2, ApplyFriction, _ZN9CPhysical13ApplyFrictionEPS_fR9CColPoint, bool, CPhysical *pPhysical, float fAdhesiveLimit, CColPoint &colPoint)
    DECL_THISCALL_TAIL(ApplyFriction2, pPhysical, fAdhesiveLimit, colPoint)

    DECL_THISCALL_HEAD(RemoveRefsToEntity, _ZN9CPhysical18RemoveRefsToEntityEP7CEntity, int, CEntity *pEntity)
    DECL_THISCALL_TAIL(RemoveRefsToEntity, pEntity)

    DECL_THISCALL_HEAD(ApplyScriptCollision, _ZN9CPhysical20ApplyScriptCollisionE7CVectorffPS0_, float, CVector vecColNormal, float fElasticity, float fAdhesiveLimit, CVector *pVecColPos)
    DECL_THISCALL_TAIL(ApplyScriptCollision, vecColNormal, fElasticity, fAdhesiveLimit, pVecColPos)

    DECL_THISCALL_HEAD(AttachEntityToEntity, _ZN9CPhysical20AttachEntityToEntityEP7CEntity7CVectorS2_, CEntity*, CEntity *pEnt, CVector vecPos, CVector vecTilt)
    DECL_THISCALL_TAIL(AttachEntityToEntity, pEnt, vecPos, vecTilt)

    DECL_THISCALL_NAMED_HEAD(AttachEntityToEntity1, AttachEntityToEntity, _ZN9CPhysical20AttachEntityToEntityEP7CEntityP7CVectorP6RtQuat, CEntity*, CEntity *pEnt, CVector *pVecPos, RtQuat *pQuat)
    DECL_THISCALL_TAIL(AttachEntityToEntity1, pEnt, pVecPos, pQuat)

    DECL_THISCALL_HEAD(DettachEntityFromEntity, _ZN9CPhysical23DettachEntityFromEntityEfffb, void, float height, float direction, float strength, bool bMakeSpin)
    DECL_THISCALL_TAIL(DettachEntityFromEntity, height, direction, strength, bMakeSpin)

    DECL_THISCALL_HEAD(GetLightingFromCol, _ZNK9CPhysical18GetLightingFromColEb, float, bool bLightForRender)
    DECL_THISCALL_TAIL(GetLightingFromCol, bLightForRender)

    DECL_THISCALL_HEAD(CanPhysicalBeDamaged, _ZN9CPhysical20CanPhysicalBeDamagedE11eWeaponTypePh, b8, eWeaponType WeaponUsed, unsigned char *pBeingShotAt)
    DECL_THISCALL_TAIL(CanPhysicalBeDamaged, WeaponUsed, pBeingShotAt)

    // Virtual functions
    virtual int ProcessEntityCollision(CEntity* entity, CColPoint* colPoint);

    // Helper functions
    inline float GetSpeedUnits() { return m_vecMoveSpeed.Magnitude(); }
    inline float GetSpeedKmh() { return 200.0f * GetSpeedUnits(); }
    
    // Member values
    float m_fPrevDistFromCam;
    unsigned int m_nLastCollisionTime;

    unsigned int bMakeMassTwiceAsBig : 1;
    unsigned int bApplyGravity : 1;
    unsigned int bDisableCollisionForce : 1;
    unsigned int bCollidable : 1;
    unsigned int bDisableTurnForce : 1;
    unsigned int bDisableMoveForce : 1;
    unsigned int bInfiniteMass : 1;
    unsigned int bDisableZ : 1;

    unsigned int bSubmergedInWater : 1;
    unsigned int bOnSolidSurface : 1;
    unsigned int bBroken : 1;
    unsigned int bProcessCollisionEvenIfStationary : 1;
    unsigned int bSkipLineCol : 1;
    unsigned int bDontApplySpeed : 1;
    unsigned int bDontLoadCollision : 1;
    unsigned int bProcessingShift : 1;

    unsigned int bForceHitReturnFalse : 1;
    unsigned int bDisableSimpleCollision : 1;
    unsigned int bBulletProof : 1;
    unsigned int bFireProof : 1;
    unsigned int bCollisionProof : 1;
    unsigned int bMeleeProof : 1;
    unsigned int bInvulnerable : 1;
    unsigned int bExplosionProof : 1;

    unsigned int bDontCollideWithFlyers : 1;
    unsigned int bAttachedToEntity : 1;
    unsigned int bAddMovingCollisionSpeed : 1;
    unsigned int bTouchingWater : 1;
    unsigned int bCanBeCollidedWith : 1;
    unsigned int bDestroyed : 1;
    unsigned int bDoorHitEndStop : 1;
    unsigned int bCarriedByRope : 1;

    CVector          m_vecMoveSpeed;
    CVector          m_vecTurnSpeed;
    CVector          m_vecFrictionMoveSpeed;
    CVector          m_vecFrictionTurnSpeed;
    CVector          m_vecForce;
    CVector          m_vecTorque;
    float            m_fMass;
    float            m_fTurnMass;
    float            m_fVelocityFrequency;
    float            m_fAirResistance;
    float            m_fElasticity;
    float            m_fBuoyancyConstant;
    CVector          m_vecCentreOfMass;
    union
    {
        void        *m_pCollisionList;
        CEntryInfoList m_listEntryInfo;
    };
    union
    {
        void        *m_pMovingList;
        CPtrNodeDoubleLink *m_pMovingListNode;
    };
    unsigned char    m_nNumOfStaticFrames;
    unsigned char    m_nNumEntitiesCollided;
    unsigned char    m_nContactSurface;
    CEntity         *m_apCollidedEntities[6];
    float            m_fMovingSpeed;
    float            m_fDamageIntensity;
    CEntity         *m_pDamageEntity;
    CVector          m_vecLastCollisionImpactVelocity;
    CVector          m_vecLastCollisionPosn;
    unsigned short   m_nPieceType;

    CPhysical       *m_pAttachedTo;
    CVector          m_vecAttachOffset;
    CVector          m_vecAttachedEntityPosn;
    CQuaternion      m_qAttachedEntityRotation;
    CEntity         *m_pEntityIgnoredCollision;
    float            m_fContactSurfaceBrightness;
    float            m_fDynamicLighting;
    CRealTimeShadow *m_pShadowData;
DECL_CLASS_END()
CHECKSIZE(CPhysical, 0x13C, 0x198);

#endif // __AML_PSDK_SAPHYSICAL_H