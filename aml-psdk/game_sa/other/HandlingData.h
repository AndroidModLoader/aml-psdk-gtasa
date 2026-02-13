#ifndef __AML_PSDK_SAHANDLINGDATA_H
#define __AML_PSDK_SAHANDLINGDATA_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include "../enum/Handling.h"



struct tTransmissionGear
{
    float m_fMaxVelocity;
    float m_fChangeUpVelocity;
    float m_fChangeDownVelocity;
};

DECL_CLASS(cTransmission)
    // Construct/Deconstruct functions
    DECL_CTORCALL(cTransmission, _ZN13cTransmissionC2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(InitGearRatios, _ZN13cTransmission14InitGearRatiosEv, void);
    
    DECL_THISCALL_HEAD(CalculateDriveAcceleration, _ZN13cTransmission26CalculateDriveAccelerationERKfRhRfS1_PfS4_hh, float,
        float const &fThrottleSetting, u8 &nCurrentGear, float &fGearChangeCount, float const &v, float *pEngineRevs, float *pEngineForce, u8 nDriveWheelsOnGround, u8 cheat)
    DECL_THISCALL_TAIL(CalculateDriveAcceleration, fThrottleSetting, nCurrentGear, fGearChangeCount, v, pEngineRevs, pEngineForce, nDriveWheelsOnGround, cheat)
    
    DECL_THISCALL_HEAD(CalculateGearForSimpleCar, _ZN13cTransmission25CalculateGearForSimpleCarEfRh, void, float CurrentVel, u8 &nCurrentGear)
    DECL_THISCALL_TAIL(CalculateGearForSimpleCar, CurrentVel, nCurrentGear)

    // Member values
    tTransmissionGear m_aGears[6];
    unsigned char     m_nDriveType; // F/R/4
    unsigned char     m_nEngineType; // P/D/E
    unsigned char     m_nNumberOfGears; // 1 to 6
    unsigned int      m_nHandlingFlags;
    float             m_fEngineAcceleration; // 0.1 to 10.0
    float             m_fEngineInertia; // 0.0 to 50.0
    float             m_fMaxGearVelocity; // 5.0 to 150.0
    float             m_fMaxFlatVelocity;
    float             m_fMinGearVelocity;
    float             m_fCurrentSpeed;
DECL_CLASS_END()



struct tHandlingData
{
    int           m_nVehicleId;
    float         m_fMass; // 1.0 to 50000.0
    float         m_fOneOverMass;
    float         m_fTurnMass;
    float         m_fDragMult;
    CVector       m_vecCentreOfMass; // x, y, z - 1.0 to 50000.0
    unsigned char m_nPercentSubmerged; // 10 to 120 (> 100% vehicle sinks)
    float         m_fBuoyancyConstant;
    float         m_fTractionMultiplier; // 0.5 to 2.0
    cTransmission m_transmissionData;
    float         m_fBrakeDeceleration; // 0.1 to 10.0
    float         m_fBrakeBias; // 0.0 > x > 1.0
    char          m_bABS; // 0/1
    float         m_fSteeringLock; // 10.0 to 40.0
    float         m_fTractionLoss;
    float         m_fTractionBias;
    float         m_fSuspensionForceLevel; // not [L/M/H]
    float         m_fSuspensionDampingLevel; // not [L/M/H]
    float         m_fSuspensionHighSpdComDamp; // often zero - 200.0 or more for bouncy vehicles
    float         m_fSuspensionUpperLimit;
    float         m_fSuspensionLowerLimit;
    float         m_fSuspensionBiasBetweenFrontAndRear;
    float         m_fSuspensionAntiDiveMultiplier;
    float         m_fCollisionDamageMultiplier; // 0.2 to 5.0
    union
    {
        eVehicleHandlingModelFlags m_nModelFlags;
        struct
        {
            unsigned int m_bIsVan : 1;
            unsigned int m_bIsBus : 1;
            unsigned int m_bIsLow : 1;
            unsigned int m_bIsBig : 1;
            unsigned int m_bReverseBonnet : 1;
            unsigned int m_bHangingBoot : 1;
            unsigned int m_bTailgateBoot : 1;
            unsigned int m_bNoswingBoot : 1;
            unsigned int m_bNoDoors : 1;
            unsigned int m_bTandemSeats : 1;
            unsigned int m_bSitInBoat : 1;
            unsigned int m_bConvertible : 1;
            unsigned int m_bNoExhaust : 1;
            unsigned int m_bDoubleExhaust : 1;
            unsigned int m_bNo1fpsLookBehind : 1;
            unsigned int m_bForceDoorCheck : 1;
            unsigned int m_bAxleFNotlit : 1;
            unsigned int m_bAxleFSolid : 1;
            unsigned int m_bAxleFMcpherson : 1;
            unsigned int m_bAxleFReverse : 1;
            unsigned int m_bAxleRNotlit : 1;
            unsigned int m_bAxleRSolid : 1;
            unsigned int m_bAxleRMcpherson : 1;
            unsigned int m_bAxleRReverse : 1;
            unsigned int m_bIsBike : 1;
            unsigned int m_bIsHeli : 1;
            unsigned int m_bIsPlane : 1;
            unsigned int m_bIsBoat : 1;
            unsigned int m_bBouncePanels : 1;
            unsigned int m_bDoubleRwheels : 1;
            unsigned int m_bForceGroundClearance : 1;
            unsigned int m_bIsHatchback : 1;
        };
    };
    union
    {
        eVehicleHandlingFlags m_nHandlingFlags;
        struct
        {
            unsigned int m_b1gBoost : 1;
            unsigned int m_b2gBoost : 1;
            unsigned int m_bNpcAntiRoll : 1;
            unsigned int m_bNpcNeutralHandl : 1;
            unsigned int m_bNoHandbrake : 1;
            unsigned int m_bSteerRearwheels : 1;
            unsigned int m_bHbRearwheelSteer : 1;
            unsigned int m_bAltSteerOpt : 1;
            unsigned int m_bWheelFNarrow2 : 1;
            unsigned int m_bWheelFNarrow : 1;
            unsigned int m_bWheelFWide : 1;
            unsigned int m_bWheelFWide2 : 1;
            unsigned int m_bWheelRNarrow2 : 1;
            unsigned int m_bWheelRNarrow : 1;
            unsigned int m_bWheelRWide : 1;
            unsigned int m_bWheelRWide2 : 1;
            unsigned int m_bHydraulicGeom : 1;
            unsigned int m_bHydraulicInst : 1;
            unsigned int m_bHydraulicNone : 1;
            unsigned int m_bNosInst : 1;
            unsigned int m_bOffroadAbility : 1;
            unsigned int m_bOffroadAbility2 : 1;
            unsigned int m_bHalogenLights : 1;
            unsigned int m_bProcRearwheelFirst : 1;
            unsigned int m_bUseMaxspLimit : 1;
            unsigned int m_bLowRider : 1;
            unsigned int m_bStreetRacer : 1;
            unsigned int m_bUnused1 : 1;
            unsigned int m_bSwingingChassis : 1;
        };
    };
    float              m_fSeatOffsetDistance; // // ped seat position offset towards centre of car
    unsigned int       m_nMonetaryValue; // 1 to 100000
    eVehicleLightsSize m_nFrontLights;
    eVehicleLightsSize m_nRearLights;
    unsigned char      m_nAnimGroup;
};

struct tBikeHandlingData
{
    int m_nVehicleId;
    float m_fLeanFwdCOM;
    float m_fLeanFwdForce;
    float m_fLeanBakCOM;
    float m_fLeanBakForce;
    float m_fMaxLean;
    float m_fFullAnimLean;
    float m_fDesLean;
    float m_fSpeedSteer;
    float m_fSlipSteer;
    float m_fNoPlayerCOMz;
    float m_fWheelieAng;
    float m_fStoppieAng;
    float m_fWheelieSteer;
    float m_fWheelieStabMult;
    float m_fStoppieStabMult;
};

struct tFlyingHandlingData
{
    int m_nVehicleId;
    float m_fThrust;
    float m_fThrustFallOff;
    float m_fYaw;
    float m_fYawStab;
    float m_fSideSlip;
    float m_fRoll;
    float m_fRollStab;
    float m_fPitch;
    float m_fPitchStab;
    float m_fFormLift;
    float m_fAttackLift;
    float m_fGearUpR;
    float m_fGearDownL;
    float m_fWindMult;
    float m_fMoveRes;
    CVector m_vecTurnRes;
    CVector m_vecSpeedRes;
};

struct tBoatHandlingData
{
    int m_nVehicleId;
    float m_fThrustY;
    float m_fThrustZ;
    float m_fThrustAppZ;
    float m_fAqPlaneForce;
    float m_fAqPlaneLimit;
    float m_fAqPlaneOffset;
    float m_fWaveAudioMult;
    float m_fLookLRBehindCamHeight;
    CVector m_vecMoveRes;
    CVector m_vecTurnRes;
};



DECL_CLASS(cHandlingDataMgr)
    // Construct/Deconstruct functions
    DECL_CTORCALL(cHandlingDataMgr, _ZN16cHandlingDataMgrC2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN16cHandlingDataMgr10InitialiseEv, void);
    DECL_THISCALL_SIMPLE(LoadHandlingData, _ZN16cHandlingDataMgr16LoadHandlingDataEv, void);
    
    DECL_THISCALL_HEAD(FindExactWord, _ZN16cHandlingDataMgr13FindExactWordEPcS0_ii, int, char *szLine, char *szArray, int nWidth, int nMaxCount)
    DECL_THISCALL_TAIL(FindExactWord, szLine, szArray, nWidth, nMaxCount)
    
    DECL_THISCALL_HEAD(GetHandlingId, _ZN16cHandlingDataMgr13GetHandlingIdEPKc, int, const char *pName)
    DECL_THISCALL_TAIL(GetHandlingId, pName)
    
    DECL_THISCALL_HEAD(ConvertDataToWorldUnits, _ZN16cHandlingDataMgr23ConvertDataToWorldUnitsEP13tHandlingData, void, tHandlingData *pHand)
    DECL_THISCALL_TAIL(ConvertDataToWorldUnits, pHand)
    
    DECL_THISCALL_HEAD(ConvertDataToGameUnits, _ZN16cHandlingDataMgr22ConvertDataToGameUnitsEP13tHandlingData, void, tHandlingData *pHand)
    DECL_THISCALL_TAIL(ConvertDataToGameUnits, pHand)
    
    DECL_THISCALL_HEAD(ConvertBikeDataToWorldUnits, _ZN16cHandlingDataMgr27ConvertBikeDataToWorldUnitsEP17tBikeHandlingData, void, tBikeHandlingData *pBikeHand)
    DECL_THISCALL_TAIL(ConvertBikeDataToWorldUnits, pBikeHand)
    
    DECL_THISCALL_HEAD(ConvertBikeDataToGameUnits, _ZN16cHandlingDataMgr26ConvertBikeDataToGameUnitsEP17tBikeHandlingData, void, tBikeHandlingData *pBikeHand)
    DECL_THISCALL_TAIL(ConvertBikeDataToGameUnits, pBikeHand)
    
    DECL_THISCALL_HEAD(GetFlyingPointer, _ZN16cHandlingDataMgr16GetFlyingPointerEh, tFlyingHandlingData*, u8 plane)
    DECL_THISCALL_TAIL(GetFlyingPointer, plane)
    
    DECL_THISCALL_HEAD(GetBoatPointer, _ZN16cHandlingDataMgr14GetBoatPointerEh, tBoatHandlingData*, u8 boat)
    DECL_THISCALL_TAIL(GetBoatPointer, boat)

    // Member values
    float               m_fCoefficientOfRestitution;
    float               m_fWheelFriction;
    float               m_aResistanceTable[3];
    tHandlingData       m_aVehicleHandling[210];
    tBikeHandlingData   m_aBikeHandling[13];
    tFlyingHandlingData m_aFlyingHandling[24];
    tBoatHandlingData   m_aBoatHandling[12];
DECL_CLASS_END()
CHECKSIZE(cHandlingDataMgr, 0xC624, 0xC624);

DECL_OBJECT_PLT_GLOBAL(cHandlingDataMgr, mod_HandlingManager, BYBIT(0x6777C8, 0x84CFB8) );

#define mod_HandlingManager mod_HandlingManager()

#endif // __AML_PSDK_SAHANDLINGDATA_H