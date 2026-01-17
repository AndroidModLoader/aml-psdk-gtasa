#ifndef __AML_PSDK_SAPHYSICAL_H
#define __AML_PSDK_SAPHYSICAL_H

#include "Entity.h"
#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/gta_base/Quaternion.h>

struct CRealTimeShadow;

DECL_CLASS_BASED(CPhysical, CEntity)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CPhysical, _ZN9CPhysicalC2Ev);
    DECL_DTORCALL(CPhysical, _ZN9CPhysicalD2Ev);

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