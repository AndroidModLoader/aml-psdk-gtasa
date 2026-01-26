#ifndef __AML_PSDK_SACAM_H
#define __AML_PSDK_SACAM_H

#include <aml-psdk/gta_base/Vector.h>
#include "../enum/Camera.h"

struct CEntity;
struct CVehicle;
struct CPed;
struct CColSphere;

DECL_CLASS(CCam)
    CCam(){}

    // Member functions
    DECL_THISCALL_SIMPLE(Using3rdPersonMouseCam, _ZN4CCam22Using3rdPersonMouseCamEv, bool);
    DECL_THISCALL_SIMPLE(ProcessPedsDeadBaby, _ZN4CCam19ProcessPedsDeadBabyEv, void);
    DECL_THISCALL_SIMPLE(Process_Cam_TwoPlayer, _ZN4CCam21Process_Cam_TwoPlayerEv, void);
    DECL_THISCALL_SIMPLE(Process_Cam_TwoPlayer_InCarAndShooting, _ZN4CCam38Process_Cam_TwoPlayer_InCarAndShootingEv, void);
    DECL_THISCALL_SIMPLE(Process_Cam_TwoPlayer_Separate_Cars, _ZN4CCam35Process_Cam_TwoPlayer_Separate_CarsEv, void);
    DECL_THISCALL_SIMPLE(Process_Cam_TwoPlayer_Separate_Cars_TopDown, _ZN4CCam43Process_Cam_TwoPlayer_Separate_Cars_TopDownEv, void);
    DECL_THISCALL_SIMPLE(ProcessArrestCamOne, _ZN4CCam19ProcessArrestCamOneEv, bool);
    DECL_THISCALL_SIMPLE(Process_AttachedCam, _ZN4CCam19Process_AttachedCamEv, void);
    DECL_THISCALL_SIMPLE(LookBehind, _ZN4CCam10LookBehindEv, bool);
    DECL_THISCALL_SIMPLE(GetVectorsReadyForRW, _ZN4CCam20GetVectorsReadyForRWEv, void);
    DECL_THISCALL_SIMPLE(GetWeaponFirstPersonOn, _ZN4CCam22GetWeaponFirstPersonOnEv, bool);
    DECL_THISCALL_SIMPLE(Init, _ZN4CCam4InitEv, void);
    DECL_THISCALL_SIMPLE(LookLeft, _ZN4CCam8LookLeftEv, bool);
    DECL_THISCALL_SIMPLE(CacheLastSettingsDWCineyCam, _ZN4CCam27CacheLastSettingsDWCineyCamEv, void);
    DECL_THISCALL_SIMPLE(ProcessArrestCamTwo, _ZN4CCam19ProcessArrestCamTwoEv, bool);
    
    DECL_THISCALL_HEAD(Process_FollowCar_SA, _ZN4CCam20Process_FollowCar_SAERK7CVectorfffb, void, CVector const &ThisCamsTarget, float TargetOrientation, float SpeedVar, float SpeedVarDesired, bool bScriptSetAngles)
    DECL_THISCALL_TAIL(Process_FollowCar_SA, ThisCamsTarget, TargetOrientation, SpeedVar, SpeedVarDesired, bScriptSetAngles)
    
    DECL_THISCALL_HEAD(Process_FollowPedWithMouse, _ZN4CCam26Process_FollowPedWithMouseERK7CVectorfff, void, CVector const &ThisCamsTarget, float TargetOrientation, float SpeedVar, float SpeedVarDesired)
    DECL_THISCALL_TAIL(Process_FollowPedWithMouse, ThisCamsTarget, TargetOrientation, SpeedVar, SpeedVarDesired)
    
    DECL_THISCALL_HEAD(Process_FollowPed_SA, _ZN4CCam20Process_FollowPed_SAERK7CVectorfffb, void, CVector const &ThisCamsTarget, float TargetOrientation, float SpeedVar, float SpeedVarDesired, bool bScriptSetAngles)
    DECL_THISCALL_TAIL(Process_FollowPed_SA, ThisCamsTarget, TargetOrientation, SpeedVar, SpeedVarDesired, bScriptSetAngles)
    
    DECL_THISCALL_HEAD(Process_M16_1stPerson, _ZN4CCam21Process_M16_1stPersonERK7CVectorfff, void, CVector const &ThisCamsTarget, float TargetOrientation, float SpeedVar, float SpeedVarDesired)
    DECL_THISCALL_TAIL(Process_M16_1stPerson, ThisCamsTarget, TargetOrientation, SpeedVar, SpeedVarDesired)
    
    DECL_THISCALL_HEAD(Process_Rocket, _ZN4CCam14Process_RocketERK7CVectorfffb, void, CVector const &ThisCamsTarget, float TargetOrientation, float SpeedVar, float SpeedVarDesired, bool bHeatSeeking)
    DECL_THISCALL_TAIL(Process_Rocket, ThisCamsTarget, TargetOrientation, SpeedVar, SpeedVarDesired, bHeatSeeking)
    
    DECL_THISCALL_HEAD(Process_AimWeapon, _ZN4CCam17Process_AimWeaponERK7CVectorfff, void, CVector const &ThisCamsTarget, float TargetOrientation, float SpeedVar, float SpeedVarDesired)
    DECL_THISCALL_TAIL(Process_AimWeapon, ThisCamsTarget, TargetOrientation, SpeedVar, SpeedVarDesired)
    
    DECL_THISCALL_HEAD(Process_WheelCam, _ZN4CCam16Process_WheelCamERK7CVectorfff, bool, CVector const &ThisCamsTarget, float TargetOrientation, float SpeedVar, float SpeedVarDesired)
    DECL_THISCALL_TAIL(Process_WheelCam, ThisCamsTarget, TargetOrientation, SpeedVar, SpeedVarDesired)
    
    DECL_THISCALL_HEAD(Process_Fixed, _ZN4CCam13Process_FixedERK7CVectorfff, void, CVector const &ThisCamsTarget, float TargetOrientation, float SpeedVar, float SpeedVarDesired)
    DECL_THISCALL_TAIL(Process_Fixed, ThisCamsTarget, TargetOrientation, SpeedVar, SpeedVarDesired)
    
    DECL_THISCALL_HEAD(Process_SpecialFixedForSyphon, _ZN4CCam29Process_SpecialFixedForSyphonERK7CVectorfff, void, CVector const &ThisCamsTarget, float TargetOrientation, float SpeedVar, float SpeedVarDesired)
    DECL_THISCALL_TAIL(Process_SpecialFixedForSyphon, ThisCamsTarget, TargetOrientation, SpeedVar, SpeedVarDesired)
    
    DECL_THISCALL_HEAD(Process_1stPerson, _ZN4CCam17Process_1stPersonERK7CVectorfff, void, CVector const &ThisCamsTarget, float TargetOrientation, float SpeedVar, float SpeedVarDesired)
    DECL_THISCALL_TAIL(Process_1stPerson, ThisCamsTarget, TargetOrientation, SpeedVar, SpeedVarDesired)
    
    DECL_THISCALL_HEAD(Process_Editor, _ZN4CCam14Process_EditorERK7CVectorfff, void, CVector const &ThisCamsTarget, float TargetOrientation, float SpeedVar, float SpeedVarDesired)
    DECL_THISCALL_TAIL(Process_Editor, ThisCamsTarget, TargetOrientation, SpeedVar, SpeedVarDesired)
    
    DECL_THISCALL_HEAD(Process_1rstPersonPedOnPC, _ZN4CCam25Process_1rstPersonPedOnPCERK7CVectorfff, void, CVector const &ThisCamsTarget, float TargetOrientation, float SpeedVar, float SpeedVarDesired)
    DECL_THISCALL_TAIL(Process_1rstPersonPedOnPC, ThisCamsTarget, TargetOrientation, SpeedVar, SpeedVarDesired)
    
    DECL_THISCALL_HEAD(Process_DW_HeliChaseCam, _ZN4CCam23Process_DW_HeliChaseCamEb, bool, bool bCheckValid)
    DECL_THISCALL_TAIL(Process_DW_HeliChaseCam, bCheckValid)
    
    DECL_THISCALL_HEAD(Process_DW_CamManCam, _ZN4CCam20Process_DW_CamManCamEb, bool, bool bCheckValid)
    DECL_THISCALL_TAIL(Process_DW_CamManCam, bCheckValid)
    
    DECL_THISCALL_HEAD(Process_DW_BirdyCam, _ZN4CCam19Process_DW_BirdyCamEb, bool, bool bCheckValid)
    DECL_THISCALL_TAIL(Process_DW_BirdyCam, bCheckValid)
    
    DECL_THISCALL_HEAD(Process_DW_PlaneSpotterCam, _ZN4CCam26Process_DW_PlaneSpotterCamEb, bool, bool bCheckValid)
    DECL_THISCALL_TAIL(Process_DW_PlaneSpotterCam, bCheckValid)
    
    DECL_THISCALL_HEAD(Process_DW_DogFightCam, _ZN4CCam22Process_DW_DogFightCamEb, bool, bool bCheckValid)
    DECL_THISCALL_TAIL(Process_DW_DogFightCam, bCheckValid)
    
    DECL_THISCALL_HEAD(Process_DW_FishCam, _ZN4CCam18Process_DW_FishCamEb, bool, bool bCheckValid)
    DECL_THISCALL_TAIL(Process_DW_FishCam, bCheckValid)
    
    DECL_THISCALL_HEAD(Process_DW_PlaneCam1, _ZN4CCam20Process_DW_PlaneCam1Eb, bool, bool bCheckValid)
    DECL_THISCALL_TAIL(Process_DW_PlaneCam1, bCheckValid)
    
    DECL_THISCALL_HEAD(Process_DW_PlaneCam2, _ZN4CCam20Process_DW_PlaneCam2Eb, bool, bool bCheckValid)
    DECL_THISCALL_TAIL(Process_DW_PlaneCam2, bCheckValid)
    
    DECL_THISCALL_HEAD(Process_DW_PlaneCam3, _ZN4CCam20Process_DW_PlaneCam3Eb, bool, bool bCheckValid)
    DECL_THISCALL_TAIL(Process_DW_PlaneCam3, bCheckValid)
    
    DECL_THISCALL_HEAD(KeepTrackOfTheSpeed, _ZN4CCam19KeepTrackOfTheSpeedERK7CVectorS2_S2_RKfS4_S4_, void, CVector const &TheSource, CVector const &TheTargetToLookAt, CVector const &TheUpVector, float const &TrueAlpha, float const &TrueBeta, float const &TheFOV)
    DECL_THISCALL_TAIL(KeepTrackOfTheSpeed, TheSource, TheTargetToLookAt, TheUpVector, TrueAlpha, TrueBeta, TheFOV)
    
    DECL_THISCALL_HEAD(LookRight, _ZN4CCam9LookRightEb, void, bool bIsRight)
    DECL_THISCALL_TAIL(LookRight, bIsRight)
    
    DECL_THISCALL_HEAD(GetBoatLook_L_R_HeightOffset, _ZN4CCam28GetBoatLook_L_R_HeightOffsetERf, bool, float &HeightOffset)
    DECL_THISCALL_TAIL(GetBoatLook_L_R_HeightOffset, HeightOffset)
    
    DECL_THISCALL_HEAD(ProcessDWBustedCam, _ZN4CCam19ProcessDWBustedCam1EP4CPedb, bool, CPed *pHandyCopPointer, bool bIsFirstTime)
    DECL_THISCALL_TAIL(ProcessDWBustedCam, pHandyCopPointer, bIsFirstTime)
    
    DECL_THISCALL_HEAD(GetLookOverShoulderPos, _ZN4CCam22GetLookOverShoulderPosEP7CEntityP4CPedR7CVectorS5_, bool, CEntity *pTargetEntity, CPed *pCopPed, CVector &vecTarget, CVector &vecSource)
    DECL_THISCALL_TAIL(GetLookOverShoulderPos, pTargetEntity, pCopPed, vecTarget, vecSource)
    
    DECL_THISCALL_HEAD(GetLookAlongGroundPos, _ZN4CCam21GetLookAlongGroundPosEP7CEntityP4CPedR7CVectorS5_, bool, CEntity *pTargetEntity, CPed *pCopPed, CVector &vecTarget, CVector &vecSource)
    DECL_THISCALL_TAIL(GetLookAlongGroundPos, pTargetEntity, pCopPed, vecTarget, vecSource)
    
    DECL_THISCALL_HEAD(GetLookFromLampPostPos, _ZN4CCam22GetLookFromLampPostPosEP7CEntityP4CPedR7CVectorS5_, bool, CEntity *pTargetEntity, CPed *pCopPed, CVector &vecTarget, CVector &vecSource)
    DECL_THISCALL_TAIL(GetLookFromLampPostPos, pTargetEntity, pCopPed, vecTarget, vecSource)
    
    DECL_THISCALL_HEAD(Process_Cam_TwoPlayer_CalcSource, _ZN4CCam32Process_Cam_TwoPlayer_CalcSourceEfP7CVectorS1_S1_, void, float Beta, CVector *pSource, CVector *pLookAt, CVector *pTarget)
    DECL_THISCALL_TAIL(Process_Cam_TwoPlayer_CalcSource, Beta, pSource, pLookAt, pTarget)
    
    DECL_THISCALL_HEAD(Process_Cam_TwoPlayer_TestLOSs, _ZN4CCam30Process_Cam_TwoPlayer_TestLOSsE7CVector, bool, CVector TempSource)
    DECL_THISCALL_TAIL(Process_Cam_TwoPlayer_TestLOSs, TempSource)
    
    DECL_THISCALL_HEAD(RotCamIfInFrontCar, _ZN4CCam18RotCamIfInFrontCarERK7CVectorf, bool, CVector const &TargetCoors, float TargetOrientation)
    DECL_THISCALL_TAIL(RotCamIfInFrontCar, TargetCoors, TargetOrientation)
    
    DECL_THISCALL_HEAD(Get_TwoPlayer_AimVector, _ZN4CCam23Get_TwoPlayer_AimVectorER7CVector, CEntity*, CVector &vecFront)
    DECL_THISCALL_TAIL(Get_TwoPlayer_AimVector, vecFront)
    
    DECL_THISCALL_HEAD(DoCamBump, _ZN4CCam9DoCamBumpEff, void, float fBumpHorz, float fBumpVert)
    DECL_THISCALL_TAIL(DoCamBump, fBumpHorz, fBumpVert)
    
    DECL_THISCALL_HEAD(GetCoreDataForDWCineyCamMode, _ZN4CCam28GetCoreDataForDWCineyCamModeEPP7CEntityPP8CVehicleP7CVectorS7_S7_S7_S7_S7_PfS7_S8_P10CColSphere, void,
                       CEntity **pEntity, CVehicle **pVehicle, CVector *dst, CVector *src, CVector *targetUp, CVector *targetRight, CVector *targetForward, 
                       CVector *targetMotion, float *targetVel, CVector *targetAngMotion, float *targetAngVel, CColSphere *sph)
    DECL_THISCALL_TAIL(GetCoreDataForDWCineyCamMode, pEntity, pVehicle, dst, src, targetUp, targetRight, targetForward, targetMotion, targetVel, targetAngMotion, targetAngVel, sph)
    
    DECL_THISCALL_HEAD(Finalise_DW_CineyCams, _ZN4CCam21Finalise_DW_CineyCamsEP7CVectorS1_ffff, void, CVector *pSrc, CVector *pDst, float roll, float fov, float nearClip, float degreeShake)
    DECL_THISCALL_TAIL(Finalise_DW_CineyCams, pSrc, pDst, roll, fov, nearClip, degreeShake)
    
    DECL_THISCALL_HEAD(IsTimeToExitThisDWCineyCamMode, _ZN4CCam30IsTimeToExitThisDWCineyCamModeEiP7CVectorS1_fb, bool, i32 camId, CVector *pSrc, CVector *pDst, float t, bool bLineOfSightCheck)
    DECL_THISCALL_TAIL(IsTimeToExitThisDWCineyCamMode, camId, pSrc, pDst, t, bLineOfSightCheck)
    
    DECL_THISCALL_HEAD(Process_FlyBy, _ZN4CCam13Process_FlyByERK7CVectorfff, void, CVector const &ThisCamsTarget, float TargetOrientation, float SpeedVar, float SpeedVarDesired)
    DECL_THISCALL_TAIL(Process_FlyBy, ThisCamsTarget, TargetOrientation, SpeedVar, SpeedVarDesired)

    // Member values
    bool          m_bBelowMinDist;
    bool          m_bBehindPlayerDesired;
    bool          m_bCamLookingAtVector;
    bool          m_bCollisionChecksOn;
    bool          m_bFixingBeta;
    bool          m_bTheHeightFixerVehicleIsATrain;
    bool          m_bLookBehindCamWasInFront;
    bool          m_bLookingBehind;
    bool          m_bLookingLeft;
    bool          m_bLookingRight;
    bool          m_bResetStatics;
    bool          m_bResetKeyboardStatics;
    bool          m_bRotating;
    eCamMode      m_nMode;
    unsigned int  m_nFinishTime;
    unsigned int  m_nDoCollisionChecksOnFrameNum;
    unsigned int  m_nDoCollisionCheckEveryNumOfFrames;
    unsigned int  m_nFrameNumWereAt;
    unsigned int  m_nDirectionWasLooking;
    float         m_fSyphonModeTargetZOffSet;
    float         m_fAlphaSpeedOverOneFrame;
    float         m_fBetaSpeedOverOneFrame;
    float         m_fCamBufferedHeight;
    float         m_fCamBufferedHeightSpeed;
    float         m_fCloseInPedHeightOffset;
    float         m_fCloseInPedHeightOffsetSpeed;
    float         m_fCloseInCarHeightOffset;
    float         m_fCloseInCarHeightOffsetSpeed;
    float         m_fDimensionOfHighestNearCar;
    float         m_fDistanceBeforeChanges;
    float         m_fFovSpeedOverOneFrame;
    float         m_fMinDistAwayFromCamWhenInterPolating;
    float         m_fPedBetweenCameraHeightOffset;
    float         m_fPlayerInFrontSyphonAngleOffSet;
    float         m_fRadiusForDead;
    float         m_fRealGroundDist;
    float         m_fTimeElapsedFloat;
    float         m_fTilt;
    float         m_fTiltSpeed;
    float         m_fTransitionBeta;
    float         m_fTrueBeta;
    float         m_fTrueAlpha;
    float         m_fInitialPlayerOrientation;
    float         m_fVerticalAngle;
    float         m_fAlphaSpeed;
    float         m_fFOV;
    float         m_fFOVSpeed;
    float         m_fHorizontalAngle;
    float         m_fBetaSpeed;
    float         m_fDistance;
    float         m_fDistanceSpeed;
    float         m_fCaMinDistance;
    float         m_fCaMaxDistance;
    float         m_fSpeedVar;
    float         m_fCameraHeightMultiplier;
    float         m_fTargetZoomGroundOne;
    float         m_fTargetZoomGroundTwo;
    float         m_fTargetZoomGroundThree;
    float         m_fTargetZoomOneZExtra;
    float         m_fTargetZoomTwoZExtra;
    float         m_fTargetZoomTwoInteriorZExtra;
    float         m_fTargetZoomThreeZExtra;
    float         m_fTargetZoomZCloseIn;
    float         m_fMinRealGroundDist;
    float         m_fTargetCloseInDist;
    float         m_fBeta_Targeting;
    float         m_fX_Targetting;
    float         m_fY_Targetting;
    i32           m_pCarWeAreFocussingOn;
    float         m_pCarWeAreFocussingOnI;
    float         m_fCamBumpedHorz;
    float         m_fCamBumpedVert;
    i32           m_nCamBumpedTime;
    CVector       m_vecSourceSpeedOverOneFrame;
    CVector       m_vecTargetSpeedOverOneFrame;
    CVector       m_vecUpOverOneFrame;
    CVector       m_vecTargetCoorsForFudgeInter;
    CVector       m_vecCamFixedModeVector;
    CVector       m_vecCamFixedModeSource;
    CVector       m_vecCamFixedModeUpOffSet;
    CVector       m_vecLastAboveWaterCamPosition;
    CVector       m_vecBufferedPlayerBodyOffset;
    CVector       m_vecFront;
    CVector       m_vecSource;
    CVector       m_vecSourceBeforeLookBehind;
    CVector       m_vecUp;
    CVector       m_avecPreviousVectors[2];
    CVector       m_avecTargetHistoryPos[4];
    unsigned int  m_anTargetHistoryTime[4];
    unsigned int  m_nCurrentHistoryPoints;
    CEntity      *m_pCamTargetEntity;
    float         m_fCameraDistance;
    float         m_fIdealAlpha;
    float         m_fPlayerVelocity;
    CVehicle     *m_pLastCarEntered;
    CPed         *m_pLastPedLookedAt;
    bool          m_bFirstPersonRunAboutActive;
DECL_CLASS_END()
CHECKSIZE(CCam, 0x210, 0x228);

#endif // __AML_PSDK_SACAM_H
