#ifndef __AML_PSDK_SAPED_H
#define __AML_PSDK_SAPED_H

#include "Physical.h"
#include "Weapon.h"
#include "../enum/PedEnums.h"
#include "../audio/AEAudioEntity.h"

struct CPed;
struct CPedIntelligence;
struct CPlayerData;
struct AnimBlendFrameData;
struct RwFrame;
struct CAccident;
struct CPedStat;
struct CObject;
struct CFire;
struct CCoverPoint;
struct CEntryExit;
struct CVehicle;
struct CWanted;
struct CTaskSimpleHoldEntity;

struct CPedAcquaintance
{
    unsigned int m_nRespect;
    unsigned int m_nLike;
    unsigned int m_nIgnore;
    unsigned int m_nDislike;
    unsigned int m_nHate;
};

struct LimbOrientation
{
    float m_fYaw;
    float m_fPitch;
};

struct LimbMovementInfo 
{
    float maxYaw, minYaw;
    float yawD;
    float maxPitch, minPitch;
    float pitchD;
};

enum eCopType : unsigned int
{
    COP_TYPE_CITYCOP = 0,
    COP_TYPE_LAPDM1,
    COP_TYPE_SWAT1,
    COP_TYPE_SWAT2,
    COP_TYPE_FBI,
    COP_TYPE_ARMY,
    COP_TYPE_MIAMIVICE,
    COP_TYPE_CSHER
};



DECL_CLASS(CPedIK)
    CPed *m_pPed;
    LimbOrientation m_TorsoOrien;
    float m_fSlopePitch;
    float m_fSlopePitchLimitMult;
    float m_fSlopeRoll;
    float m_fBodyRoll;
    union
    {
        unsigned int m_nFlags;
        struct
        {
            unsigned int bGunReachedTarget : 1;
            unsigned int bTorsoUsed : 1;
            unsigned int bUseArm : 1;
            unsigned int bSlopePitch : 1;
        };
    };
DECL_CLASS_END()
CHECKSIZE(CPedIK, 0x20, 0x28);

DECL_CLASS_BASED(CPed, CPhysical)
    // Construct/Deconstruct functions
    CPed(){}
    DECL_CTORCALL_ARG_HEAD(CPed, _ZN4CPedC2Ej, u32 pedType)
    DECL_CTORCALL_ARG_TAIL(pedType)
    DECL_DTORCALL(CPed, _ZN4CPedD2Ev);
    DECL_NEWCALL(CPed, BYBIT(_ZN4CPednwEj, _ZN4CPednwEm) );
    DECL_DLCALL(CPed, _ZN4CPeddlEPv);

    // Virtual functions
    virtual void SetMoveAnim();
    virtual bool Save();
    virtual bool Load();

    // Helper functions
    inline float GetHealth()
    {
        return m_fHealth;
    }
    inline float GetMaxHealth()
    {
        return m_fMaxHealth;
    }
    inline bool IsMaxHealth()
    {
        return (GetHealth() >= GetMaxHealth());
    }
    inline void SetHealth(float hp)
    {
        m_fHealth = hp;
    }
    inline void AddHealth(float hp)
    {
        SetHealth(GetHealth() + hp);
    }
    inline void SetHealthSafe(float hp)
    {
        if(hp < 0.0f) m_fHealth = 0.0f;
        else if(hp > GetMaxHealth()) m_fHealth = GetMaxHealth();
        else m_fHealth = hp;
    }
    inline void AddHealthSafe(float hp)
    {
        SetHealthSafe(GetHealth() + hp);
    }

    // Member functions
    DECL_THISCALL_SIMPLE(PedIsInvolvedInConversation, _ZN4CPed27PedIsInvolvedInConversationEv, bool);
    DECL_THISCALL_SIMPLE(PedCanPickUpPickUp, _ZN4CPed18PedCanPickUpPickUpEv, bool);
    DECL_THISCALL_SIMPLE(CreateDeadPedMoney, _ZN4CPed18CreateDeadPedMoneyEv, void);
    DECL_THISCALL_SIMPLE(CreateDeadPedWeaponPickups, _ZN4CPed26CreateDeadPedWeaponPickupsEv, void);
    DECL_THISCALL_SIMPLE(IsPlayer, _ZNK4CPed8IsPlayerEv, bool);
    DECL_THISCALL_SIMPLE(ReleaseCoverPoint, _ZN4CPed17ReleaseCoverPointEv, void);
    DECL_THISCALL_SIMPLE(ClearWeapons, _ZN4CPed12ClearWeaponsEv, void);
    DECL_THISCALL_SIMPLE(UpdateStatLeavingVehicle, _ZN4CPed24UpdateStatLeavingVehicleEv, void);
    DECL_THISCALL_SIMPLE(Initialise, _ZN4CPed10InitialiseEv, void);
    DECL_THISCALL_SIMPLE(SetPedDefaultDecisionMaker, _ZN4CPed26SetPedDefaultDecisionMakerEv, void);
    DECL_THISCALL_SIMPLE(CanUseTorsoWhenLooking, _ZN4CPed22CanUseTorsoWhenLookingEv, bool);
    DECL_THISCALL_SIMPLE(Update, _ZN4CPed6UpdateEv, void);
    DECL_THISCALL_SIMPLE(PositionAnyPedOutOfCollision, _ZN4CPed28PositionAnyPedOutOfCollisionEv, bool);
    DECL_THISCALL_SIMPLE(ClearAimFlag, _ZN4CPed12ClearAimFlagEv, void);
    DECL_THISCALL_SIMPLE(ClearLookFlag, _ZN4CPed13ClearLookFlagEv, void);
    DECL_THISCALL_SIMPLE(StopNonPartialAnims, _ZN4CPed19StopNonPartialAnimsEv, void);
    DECL_THISCALL_SIMPLE(RestartNonPartialAnims, _ZN4CPed22RestartNonPartialAnimsEv, void);
    DECL_THISCALL_SIMPLE(ClearLook, _ZN4CPed9ClearLookEv, void);
    DECL_THISCALL_SIMPLE(GetWeaponSkill, _ZN4CPed14GetWeaponSkillEv, i8);
    DECL_THISCALL_SIMPLE(CanWeRunAndFireWithWeapon, _ZN4CPed25CanWeRunAndFireWithWeaponEv, bool);
    DECL_THISCALL_SIMPLE(CalculateNewVelocity, _ZN4CPed20CalculateNewVelocityEv, void);
    DECL_THISCALL_SIMPLE(IsPedInControl, _ZN4CPed14IsPedInControlEv, bool);
    DECL_THISCALL_SIMPLE(UpdatePosition, _ZN4CPed14UpdatePositionEv, void);
    DECL_THISCALL_SIMPLE(CalculateNewOrientation, _ZN4CPed23CalculateNewOrientationEv, void);
    DECL_THISCALL_SIMPLE(ClearAll, _ZN4CPed8ClearAllEv, void);
    DECL_THISCALL_SIMPLE(ProcessBuoyancy, _ZN4CPed15ProcessBuoyancyEv, void);
    DECL_THISCALL_SIMPLE(RequestDelayedWeapon, _ZN4CPed20RequestDelayedWeaponEv, void);
    DECL_THISCALL_SIMPLE(PlayFootSteps, _ZN4CPed13PlayFootStepsEv, void);
    DECL_THISCALL_SIMPLE(IsAlive, _ZNK4CPed7IsAliveEv, bool);
    DECL_THISCALL_SIMPLE(IsPedShootable, _ZN4CPed14IsPedShootableEv, bool);
    DECL_THISCALL_SIMPLE(UseGroundColModel, _ZN4CPed17UseGroundColModelEv, bool);
    DECL_THISCALL_SIMPLE(CanSetPedState, _ZN4CPed14CanSetPedStateEv, bool);
    DECL_THISCALL_SIMPLE(CanBeArrested, _ZN4CPed13CanBeArrestedEv, bool);
    DECL_THISCALL_SIMPLE(CanStrafeOrMouseControl, _ZN4CPed23CanStrafeOrMouseControlEv, bool);
    DECL_THISCALL_SIMPLE(CanBeDeleted, _ZN4CPed12CanBeDeletedEv, u8);
    DECL_THISCALL_SIMPLE(CanBeDeletedEvenInVehicle, _ZN4CPed25CanBeDeletedEvenInVehicleEv, u8);
    DECL_THISCALL_SIMPLE(RemoveGogglesModel, _ZN4CPed18RemoveGogglesModelEv, void);
    DECL_THISCALL_SIMPLE(PutOnGoggles, _ZN4CPed12PutOnGogglesEv, void);
    DECL_THISCALL_SIMPLE(TakeOffGoggles, _ZN4CPed14TakeOffGogglesEv, void);
    DECL_THISCALL_SIMPLE(ReplaceWeaponWhenExitingVehicle, _ZN4CPed31ReplaceWeaponWhenExitingVehicleEv, void);
    DECL_THISCALL_SIMPLE(RemoveWeaponForScriptedCutscene, _ZN4CPed31RemoveWeaponForScriptedCutsceneEv, void);
    DECL_THISCALL_SIMPLE(ReplaceWeaponForScriptedCutscene, _ZN4CPed32ReplaceWeaponForScriptedCutsceneEv, void);
    DECL_THISCALL_SIMPLE(ResetGunFlashAlpha, _ZN4CPed18ResetGunFlashAlphaEv, void);
    DECL_THISCALL_SIMPLE(GetBikeRidingSkill, _ZN4CPed18GetBikeRidingSkillEv, float);
    DECL_THISCALL_SIMPLE(PreRenderAfterTest, _ZN4CPed18PreRenderAfterTestEv, void);
    DECL_THISCALL_SIMPLE(SetIdle, _ZN4CPed7SetIdleEv, void);
    DECL_THISCALL_SIMPLE(Look, _ZN4CPed4LookEv, void);
    DECL_THISCALL_SIMPLE(TurnBody, _ZN4CPed8TurnBodyEv, bool);
    DECL_THISCALL_SIMPLE(IsPointerValid, _ZN4CPed14IsPointerValidEv, bool);
    DECL_THISCALL_SIMPLE(SetPedPositionInCar, _ZN4CPed19SetPedPositionInCarEv, void);
    DECL_THISCALL_SIMPLE(RestoreHeadingRate, _ZN4CPed18RestoreHeadingRateEv, void);
    DECL_THISCALL_SIMPLE(SetRadioStation, _ZN4CPed15SetRadioStationEv, void);
    DECL_THISCALL_SIMPLE(PositionAttachedPed, _ZN4CPed19PositionAttachedPedEv, void);
    DECL_THISCALL_SIMPLE(DettachPedFromEntity, _ZN4CPed20DettachPedFromEntityEv, void);
    DECL_THISCALL_SIMPLE(Dress, _ZN4CPed5DressEv, void);
    DECL_THISCALL_SIMPLE(UpdateStatEnteringVehicle, _ZN4CPed25UpdateStatEnteringVehicleEv, void);
    DECL_THISCALL_SIMPLE(GetHoldingTask, _ZN4CPed14GetHoldingTaskEv, CTaskSimpleHoldEntity*);
    DECL_THISCALL_SIMPLE(GetEntityThatThisPedIsHolding, _ZN4CPed29GetEntityThatThisPedIsHoldingEv, CEntity*);
    DECL_THISCALL_SIMPLE(CanThrowEntityThatThisPedIsHolding, _ZN4CPed34CanThrowEntityThatThisPedIsHoldingEv, u8);
    DECL_THISCALL_SIMPLE(GiveWeaponAtStartOfFight, _ZN4CPed24GiveWeaponAtStartOfFightEv, void);
    DECL_THISCALL_SIMPLE(GiveWeaponWhenJoiningGang, _ZN4CPed25GiveWeaponWhenJoiningGangEv, void);
    DECL_THISCALL_SIMPLE(IsPlayingHandSignal, _ZN4CPed19IsPlayingHandSignalEv, u8);
    DECL_THISCALL_SIMPLE(StopPlayingHandSignal, _ZN4CPed21StopPlayingHandSignalEv, void);
    DECL_THISCALL_SIMPLE(GetWalkAnimSpeed, _ZN4CPed16GetWalkAnimSpeedEv, float);
    DECL_THISCALL_SIMPLE(UseFreeAimMagnetize, _ZN4CPed19UseFreeAimMagnetizeEv, bool);
    DECL_THISCALL_SIMPLE(GetPedStateString, _ZN4CPed17GetPedStateStringEv, const char*);
    DECL_THISCALL_SIMPLE(GetPedTalking, _ZN4CPed13GetPedTalkingEv, u8);
    DECL_THISCALL_SIMPLE(EnablePedSpeech, _ZN4CPed15EnablePedSpeechEv, void);
    DECL_THISCALL_SIMPLE(EnablePedSpeechForScriptSpeech, _ZN4CPed30EnablePedSpeechForScriptSpeechEv, void);
    DECL_THISCALL_SIMPLE(CanPedHoldConversation, _ZN4CPed22CanPedHoldConversationEv, u8);
    DECL_THISCALL_SIMPLE(DeadPedMakesTyresBloody, _ZN4CPed23DeadPedMakesTyresBloodyEv, void);

    // Member values
    CAEPedAudioEntity           m_pedAudio;
    CAEPedSpeechAudioEntity     m_pedSpeech;
    CAEPedWeaponAudioEntity     m_weaponAudio;
    CPedIntelligence*           m_pIntelligence;
    CPlayerData*                m_pPlayerData;
    unsigned char               m_nCreatedBy; // see ePedCreatedBy
    ePedState                   m_ePedState;
    int                         m_nMoveState; // see eMoveState
    CStoredCollPoly             m_storedCollPoly;
    float                       m_fDistTravelledSinceLastHeightCheck;

    unsigned int bIsStanding : 1; // is ped standing on something
    unsigned int bWasStanding : 1; // was ped standing on something
    unsigned int bIsLooking : 1; // is ped looking at something or in a direction
    unsigned int bIsRestoringLook : 1; // is ped restoring head postion from a look
    unsigned int bIsAimingGun : 1; // is ped aiming gun
    unsigned int bIsRestoringGun : 1; // is ped moving gun back to default posn
    unsigned int bCanPointGunAtTarget : 1; // can ped point gun at target
    unsigned int bIsTalking : 1; // is ped talking(see Chat())

    unsigned int bInVehicle : 1; // is in a vehicle
    unsigned int bIsInTheAir : 1; // is in the air
    unsigned int bIsLanding : 1; // is landing after being in the air
    unsigned int bHitSomethingLastFrame : 1; // has been in a collision last fram
    unsigned int bIsNearCar : 1; // has been in a collision last fram
    unsigned int bRenderPedInCar : 1; // has been in a collision last fram
    unsigned int bUpdateAnimHeading : 1; // update ped heading due to heading change during anim sequence
    unsigned int bRemoveHead : 1; // waiting on AntiSpazTimer to remove head

    unsigned int bFiringWeapon : 1; // is pulling trigger
    unsigned int bHasACamera : 1; // does ped possess a camera to document accidents
    unsigned int bPedIsBleeding : 1; // Ped loses a lot of blood if true
    unsigned int bStopAndShoot : 1; // Ped cannot reach target to attack with fist, need to use gun
    unsigned int bIsPedDieAnimPlaying : 1; // is ped die animation finished so can dead now
    unsigned int bStayInSamePlace : 1; // when set, ped stays put
    unsigned int bKindaStayInSamePlace : 1; // when set, ped doesn't seek out opponent or cover large distances. Will still shuffle and look for cover
    unsigned int bBeingChasedByPolice : 1; // use nodes for routefind

    unsigned int bNotAllowedToDuck : 1; // Is this ped allowed to duck at all?
    unsigned int bCrouchWhenShooting : 1; // duck behind cars etc
    unsigned int bIsDucking : 1; // duck behind cars etc
    unsigned int bGetUpAnimStarted : 1; // don't want to play getup anim if under something
    unsigned int bDoBloodyFootprints : 1; // unsigned int bIsLeader :1;
    unsigned int bDontDragMeOutCar : 1;
    unsigned int bStillOnValidPoly : 1; // set if the polygon the ped is on is still valid for collision
    unsigned int bAllowMedicsToReviveMe : 1;

    unsigned int bResetWalkAnims : 1;
    unsigned int bOnBoat : 1; // flee but only using nodes
    unsigned int bBusJacked : 1; // flee but only using nodes
    unsigned int bFadeOut : 1; // set if you want ped to fade out
    unsigned int bKnockedUpIntoAir : 1; // has ped been knocked up into the air by a car collision
    unsigned int bHitSteepSlope : 1; // has ped collided/is standing on a steep slope (surface type)
    unsigned int bCullExtraFarAway : 1; // special ped only gets culled if it's extra far away (for roadblocks)
    unsigned int bTryingToReachDryLand : 1; // has ped just exited boat and trying to get to dry land

    unsigned int bCollidedWithMyVehicle : 1;
    unsigned int bRichFromMugging : 1; // ped has lots of cash cause they've been mugging people
    unsigned int bChrisCriminal : 1; // Is a criminal as killed during Chris' police mission (should be counted as such)
    unsigned int bShakeFist : 1; // test shake hand at look entity
    unsigned int bNoCriticalHits : 1; // ped cannot be killed by a single bullet
    unsigned int bHasAlreadyBeenRecorded : 1; // Used for replays
    unsigned int bUpdateMatricesRequired : 1; // if PedIK has altered bones so matrices need updated this frame
    unsigned int bFleeWhenStanding : 1; //

    unsigned int bMiamiViceCop : 1;  //
    unsigned int bMoneyHasBeenGivenByScript : 1; //
    unsigned int bHasBeenPhotographed : 1;  //
    unsigned int bIsDrowning : 1;
    unsigned int bDrownsInWater : 1;
    unsigned int bHeadStuckInCollision : 1;
    unsigned int bDeadPedInFrontOfCar : 1;
    unsigned int bStayInCarOnJack : 1;

    unsigned int bDontFight : 1;
    unsigned int bDoomAim : 1;
    unsigned int bCanBeShotInVehicle : 1;
    unsigned int bPushedAlongByCar : 1; // ped is getting pushed along by car collision (so don't take damage from horz velocity)
    unsigned int bNeverEverTargetThisPed : 1;
    unsigned int bThisPedIsATargetPriority : 1;
    unsigned int bCrouchWhenScared : 1;
    unsigned int bKnockedOffBike : 1;

    unsigned int bDonePositionOutOfCollision : 1;
    unsigned int bDontRender : 1;
    unsigned int bHasBeenAddedToPopulation : 1;
    unsigned int bHasJustLeftCar : 1;
    unsigned int bIsInDisguise : 1;
    unsigned int bDoesntListenToPlayerGroupCommands : 1;
    unsigned int bIsBeingArrested : 1;
    unsigned int bHasJustSoughtCover : 1;

    unsigned int bKilledByStealth : 1;
    unsigned int bDoesntDropWeaponsWhenDead : 1;
    unsigned int bCalledPreRender : 1;
    unsigned int bBloodPuddleCreated : 1; // Has a static puddle of blood been created yet
    unsigned int bPartOfAttackWave : 1;
    unsigned int bClearRadarBlipOnDeath : 1;
    unsigned int bNeverLeavesGroup : 1; // flag that we want to test 3 extra spheres on col model
    unsigned int bTestForBlockedPositions : 1; // this sets these indicator flags for various posisions on the front of the ped

    unsigned int bRightArmBlocked : 1;
    unsigned int bLeftArmBlocked : 1;
    unsigned int bDuckRightArmBlocked : 1;
    unsigned int bMidriffBlockedForJump : 1;
    unsigned int bFallenDown : 1;
    unsigned int bUseAttractorInstantly : 1;
    unsigned int bDontAcceptIKLookAts : 1;
    unsigned int bHasAScriptBrain : 1;

    unsigned int bWaitingForScriptBrainToLoad : 1;
    unsigned int bHasGroupDriveTask : 1;
    unsigned int bCanExitCar : 1;
    unsigned int CantBeKnockedOffBike : 2; // 0=Default(harder for mission peds) 1=Never 2=Always normal(also for mission peds)
    unsigned int bHasBeenRendered : 1;
    unsigned int bIsCached : 1;
    unsigned int bPushOtherPeds : 1; // GETS RESET EVERY FRAME - SET IN TASK: want to push other peds around (eg. leader of a group or ped trying to get in a car)

    unsigned int bHasBulletProofVest : 1;
    unsigned int bUsingMobilePhone : 1;
    unsigned int bUpperBodyDamageAnimsOnly : 1;
    unsigned int bStuckUnderCar : 1;
    unsigned int bKeepTasksAfterCleanUp : 1; // If true ped will carry on with task even after cleanup
    unsigned int bIsDyingStuck : 1;
    unsigned int bIgnoreHeightCheckOnGotoPointTask : 1; // set when walking round buildings, reset when task quits
    unsigned int bForceDieInCar : 1;

    unsigned int bCheckColAboveHead : 1;
    unsigned int bIgnoreWeaponRange : 1;
    unsigned int bDruggedUp : 1;
    unsigned int bWantedByPolice : 1; // if this is set, the cops will always go after this ped when they are doing a KillCriminal task
    unsigned int bSignalAfterKill : 1;
    unsigned int bCanClimbOntoBoat : 1;
    unsigned int bPedHitWallLastFrame : 1; // useful to store this so that AI knows (normal will still be available)
    unsigned int bIgnoreHeightDifferenceFollowingNodes : 1;

    unsigned int bMoveAnimSpeedHasBeenSetByTask : 1;
    unsigned int bGetOutUpsideDownCar : 1;
    unsigned int bJustGotOffTrain : 1;
    unsigned int bDeathPickupsPersist : 1;
    unsigned int bTestForShotInVehicle : 1;

    AnimBlendFrameData *m_apBones[19];
    unsigned int        m_nAnimGroup;
    CVector2D           m_vecAnimMovingShiftLocal;
    CPedAcquaintance    m_acquaintance;
    RwObject           *m_pWeaponObject;
    RwFrame            *m_pGunflashObject;
    RwObject           *m_pGogglesObject;
    unsigned char      *m_pGogglesState;
    short               m_nWeaponGunflashAlphaMP1;
    short               m_nGunFlashBlendOutRate;
    short               m_nWeaponGunflashAlphaMP2;
    short               m_nGunFlashBlendOutRate2;
    CPedIK              m_pedIK;
    unsigned int        m_nAntiSpazTimer;
    eMoveState          m_eMoveStateAnim;
    eMoveState          m_eStoredMoveState;
    float               m_fHealth;
    float               m_fMaxHealth;
    float               m_fArmour;
    int                 m_nTimeTillWeNeedThisPed;
    CVector2D           m_vecAnimMovingShift;
    float               m_fCurrentRotation;
    float               m_fAimingRotation;
    float               m_fHeadingChangeRate;
    float               m_fHeadingChangeRateAccel;
    CPhysical          *m_pGroundPhysical;
    CVector             m_vecGroundOffset;
    CVector             m_vecGroundNormal;
    CEntity            *m_pContactEntity;
    float               m_fHitHeadHeight;
    CVehicle           *m_pVehicle;
    CVehicle           *m_pAccidentVehicle;
    CAccident          *m_pAccident;
    int                 m_nPedType;
    CPedStat           *m_pStats;
    CWeapon             m_aWeapons[13];
    eWeaponType         m_nSavedWeapon;
    eWeaponType         m_nDelayedWeapon;
    unsigned int        m_nDelayedWeaponAmmo;
    unsigned char       m_nSelectedWepSlot;
    unsigned char       m_nWeaponShootingRate;
    unsigned char       m_nWeaponAccuracy;
    CObject            *m_pTargetedObject;
    CEntity            *m_pEntMagnetizeTarget;
    CVector             m_vecWeaponPrevPos;
    char                m_nWeaponSkill;
    char                m_nFightingStyle; // see eFightingStyle
    char                m_nAllowedAttackMoves;
    CFire              *m_pFire;
    float               m_fFireDamageMultiplier;
    CEntity            *m_pLookingAtEntity;
    float               m_fLookingDirection;
    int                 m_nWeaponModelId;
    uint32_t            m_nUnconsciousTimer;
    int                 m_nLookingTime;
    uint32_t            m_nAttackTimer;
    int                 m_nDeathTime;
    char                m_nBodypartToRemove;
    short               m_nMoneyCount;
    float               m_wobble;
    float               m_wobbleSpeed;
    char                m_nLastWeaponDamage;
    CEntity            *m_pLastEntityDamage;
    uint32_t            m_nLastDamagedTime;
    CVector             m_vecTurretOffset;
    short               m_nTurretPosnMode;
    float               m_fTurretAngleA;
    float               m_fTurretAngleB;
    int                 m_nTurretAmmo;
    CCoverPoint        *m_pCoverPoint;
    CEntryExit         *m_pEnex;
    float               m_fRemovalDistMultiplier;
    short               m_nSpecialModelIndex;
    uint32_t            m_nLastTalkSfx;
DECL_CLASS_END()
CHECKSIZE(CPed, 0x7A4, 0x988);



DECL_CLASS_BASED(CCopPed, CPed)
    // Construct/Deconstruct functions
    CCopPed(){}
    DECL_CTORCALL_ARG_HEAD(CCopPed, _ZN7CCopPedC2E8eCopType, eCopType CopType)
    DECL_CTORCALL_ARG_TAIL(CopType)
    DECL_DTORCALL(CCopPed, _ZN7CCopPedD2Ev)

    // Member functions
    DECL_THISCALL_SIMPLE(ClearCriminalsToKill, _ZN7CCopPed20ClearCriminalsToKillEv, void);

    DECL_THISCALL_HEAD(SetPartner, _ZN7CCopPed10SetPartnerEPS_, void, CCopPed *pPed)
    DECL_THISCALL_TAIL(SetPartner, pPed)

    DECL_THISCALL_HEAD(AddCriminalToKill, _ZN7CCopPed17AddCriminalToKillEP4CPed, i32, CPed *pCriminal)
    DECL_THISCALL_TAIL(AddCriminalToKill, pCriminal)

    DECL_THISCALL_HEAD(RemoveCriminalToKill, _ZN7CCopPed20RemoveCriminalToKillEP4CPedi, void, CPed *pCriminal, i32 i)
    DECL_THISCALL_TAIL(RemoveCriminalToKill, pCriminal, i)

    // Member values
    bool           m_bRoadBlockCop;
    bool           m_bRemoveIfNonVisible;
    eCopType       m_copType;
    int            m_nStuckCounter;
    CCopPed       *m_pCopPartner;
    CPed          *m_apCriminalsToKill[5];
    bool           m_bIAmDriver;
DECL_CLASS_END()



DECL_FASTCALL_SIMPLE_GLO(IsPedPointerValid, _Z17IsPedPointerValidP4CPed, bool, CPed* pPed);
DECL_FASTCALL_SIMPLE_GLO(IsPedPointerValid_NotInWorld, _Z28IsPedPointerValid_NotInWorldP4CPed, bool, CPed* pPed);
DECL_FASTCALL_SIMPLE_GLO(LOSBlockedBetweenPeds, _Z21LOSBlockedBetweenPedsP7CEntityS0_, bool, CEntity* pPed1, CEntity* pPed2);
DECL_FASTCALL_SIMPLE_GLO(SetPedAtomicVisibilityCB, _Z24SetPedAtomicVisibilityCBP8RwObjectPv, RwObject*, RwObject* pObject, void* pData);
DECL_FASTCALL_SIMPLE_GLO(RecurseFrameChildrenVisibilityCB, _Z32RecurseFrameChildrenVisibilityCBP7RwFramePv, RwFrame*, RwFrame* pFrame, void* pData);

#endif // __AML_PSDK_SAPED_H
