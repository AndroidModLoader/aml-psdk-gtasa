#ifndef __AML_PSDK_SAAUTOMOBILE_H
#define __AML_PSDK_SAAUTOMOBILE_H

#include "Vehicle.h"

struct FxSystem_c;

enum eDamageState
{
    DAMSTATE_OK = 0,
    DAMSTATE_OPENED = 1,
    DAMSTATE_DAMAGED = 2,
    DAMSTATE_OPENED_DAMAGED = 3,
    DAMSTATE_NOTPRESENT = 4
};

enum tComponent
{
    COMPONENT_WHEEL_LF = 1,
    COMPONENT_WHEEL_RF = 2,
    COMPONENT_WHEEL_LR = 3,
    COMPONENT_WHEEL_RR = 4,
    COMPONENT_BONNET = 5,
    COMPONENT_BOOT = 6,
    COMPONENT_DOOR_LF = 7,
    COMPONENT_DOOR_RF = 8,
    COMPONENT_DOOR_LR = 9,
    COMPONENT_DOOR_RR = 10,
    COMPONENT_WING_LF = 11,
    COMPONENT_WING_RF = 12,
    COMPONENT_WING_LR = 13,
    COMPONENT_WING_RR = 14,
    COMPONENT_WINDSCREEN = 15,
    COMPONENT_BUMP_FRONT = 16,
    COMPONENT_BUMP_REAR = 17
};

enum tComponentGroup
{
    COMPGROUP_PANEL = 0,
    COMPGROUP_WHEEL = 1,
    COMPGROUP_DOOR = 2,
    COMPGROUP_BONNET = 3,
    COMPGROUP_BOOT = 4,
    COMPGROUP_LIGHT = 5,
    COMPGROUP_NA = 6
};

enum eWheels
{
    WHEEL_FRONT_LEFT = 0,
    WHEEL_REAR_LEFT = 1,
    WHEEL_FRONT_RIGHT = 2,
    WHEEL_REAR_RIGHT = 3
};

enum ePanels
{
    WING_FRONT_LEFT = 0,
    WING_FRONT_RIGHT = 1,
    WING_REAR_LEFT = 2,
    WING_REAR_RIGHT = 3,
    WINDSCREEN = 4,
    BUMP_FRONT = 5,
    BUMP_REAR = 6
};

enum eLights
{
    LIGHT_FRONT_LEFT = 0,
    LIGHT_FRONT_RIGHT = 1,
    LIGHT_REAR_RIGHT = 2,
    LIGHT_REAR_LEFT = 3
};

enum eCarNodes
{
    CAR_NODE_NONE = 0,
    CAR_CHASSIS = 1,
    CAR_WHEEL_RF = 2,
    CAR_WHEEL_RM = 3,
    CAR_WHEEL_RB = 4,
    CAR_WHEEL_LF = 5,
    CAR_WHEEL_LM = 6,
    CAR_WHEEL_LB = 7,
    CAR_DOOR_RF = 8,
    CAR_DOOR_RR = 9,
    CAR_DOOR_LF = 10,
    CAR_DOOR_LR = 11,
    CAR_BUMP_FRONT = 12,
    CAR_BUMP_REAR = 13,
    CAR_WING_RF = 14,
    CAR_WING_LF = 15,
    CAR_BONNET = 16,
    CAR_BOOT = 17,
    CAR_WINDSCREEN = 18,
    CAR_EXHAUST = 19,
    CAR_MISC_A = 20,
    CAR_MISC_B = 21,
    CAR_MISC_C = 22,
    CAR_MISC_D = 23,
    CAR_MISC_E = 24,
    CAR_NUM_NODES
};

struct CBouncingPanel
{
    unsigned short m_nFrameId;
    unsigned short m_nAxis;
    float          m_fAngleLimit;
    CVector        m_vecRotation;
    CVector        m_vecPos;
};

DECL_CLASS(CDamageManager)
    float m_fWheelDamageEffect;
    unsigned char m_nEngineStatus;
    union
    {
        unsigned char m_anWheelsStatus[4];
        struct
        {
            unsigned char m_nRightRearWheelsStatus;
            unsigned char m_nRightFrontWheelsStatus;
            unsigned char m_nLeftRearWheelsStatus;
            unsigned char m_nLeftFrontWheelsStatus;
        };
    };
    union
    {
        unsigned char m_anDoorsStatus[6];
        struct
        {
            unsigned char m_nBonnetStatus;
            unsigned char m_nBootStatus;
            unsigned char m_nLeftFrontDoorStatus;
            unsigned char m_nRightFrontDoorStatus;
            unsigned char m_nLeftRearDoorStatus;
            unsigned char m_nRightRearDoorStatus;
        };
    };
    union
    {
        unsigned int m_nLightsStatus;
        struct
        {
            unsigned int m_nLeftFrontLightStatus : 2;
            unsigned int m_nRightFrontLightStatus : 2;
            unsigned int m_nRightRearLightStatus : 2;
            unsigned int m_nLeftRearLightStatus : 2;
        };
    };
    unsigned int m_nPanelsStatus;
DECL_CLASS_END()



DECL_CLASS_BASED(CAutomobile, CVehicle)
    // Construct/Deconstruct functions
    CAutomobile(){}
    DECL_CTORCALL_ARG_HEAD(CAutomobile, _ZN11CAutomobileC2Eihh, int modelIdx, u8 createdBy, u8 suspensionLines)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy, suspensionLines)
    DECL_DTORCALL(CAutomobile, _ZN11CAutomobileD2Ev);

    // Virtual functions
    virtual void ResetSuspension(void);
    virtual void ProcessFlyingCarStuff(void);
    virtual void DoHoverSuspensionRatios(void);
    virtual void ProcessSuspension(void);
    
    // Member values
    CDamageManager m_damageManager;
    CDoor m_doors[6];
    RwFrame *m_aCarNodes[CAR_NUM_NODES];
    CBouncingPanel m_panels[3];
    CDoor m_swingingChassis;
    CColPoint m_wheelColPoint[4];
    float wheelsDistancesToGround1[4];
    float wheelsDistancesToGround2[4];
    float wheelsCounts[4];
    float m_fBrakeCount;
    float m_fEngineRevs;
    float m_fEngineForce;
    int m_aSkidmarkType[4]; // see eSkidmarkType
    bool m_bBloodyWheel[4];
    bool m_bMoreSkidmarks[4];
    float m_fWheelRotation[4];
    float m_fSuspensionHeights[4];
    float m_fWheelSpeed[4];
    float m_fWheelLongtitudeSlip[4];
    union
    {
        char taxiAvaliable;
        char m_nAutomobileFlags;
        struct
        {
            unsigned char bTaxiLight : 1;
            unsigned char bShouldNotChangeColour : 1;
            unsigned char bWaterTight : 1;
            unsigned char bDoesNotGetDamageUpsideDown : 1;
            unsigned char bCanBeVisiblyDamaged : 1;
            unsigned char bTankExplodesCars : 1;
            unsigned char bIsBoggedDownInSand : 1;
            unsigned char bIsMonsterTruck : 1;
        };
    };
    short m_nBrakesOn;
    short m_wMiscComponentAngle;
    short m_wVoodooSuspension;
    int m_dwBusDoorTimerEnd;
    int m_dwBusDoorTimerStart;
    float wheelOffsetZ[4];
    int lineLength[4];
    float m_fFrontHeightAboveRoad;
    float m_fRearHeightAboveRoad;
    float m_fCarTraction;
    float m_fNitroValue;
    float m_fRotation;
    float m_fRotationBalance; // used in CHeli::TestSniperCollision
    float m_fMoveDirection;
    CVector m_vecOldMoveSpeed;
    CVector m_vecOldTurnSpeed;
    float m_aDoorRotation[6];
    float m_fBurningTimer; // starts when vehicle health is lower than 250.0, car blows up when it hits 5000.0
    CEntity *m_pWheelCollisionEntity[4];
    CVector m_vWheelCollisionPos[4];
    CEntity* m_pAttacker;
    float m_fTransformPos;
    short m_nTransformState;
    float m_fBasePositions[4];
    float m_fLeftDoorDrivebyOpen;
    float m_fRightDoorDrivebyOpen;
    float m_fDoomVerticalRotation;
    float m_fDoomHorizontalRotation;
    float m_fForcedOrientation;
    float m_fUpDownLightAngle[2];
    unsigned char m_nNumContactWheels;
    unsigned char m_nWheelsOnGround;
    unsigned char m_nWheelsOnGroundPrev;
    float m_fGasPedalAudioRevs;
    unsigned int m_aWheelState[4]; // enum tWheelState
    void *pNitroParticle[2];
    unsigned char m_nHarvesterTimer;
    unsigned char m_nBlownEngineStatus;
    float m_fHeliDustRatio;
DECL_CLASS_END()
CHECKSIZE(CAutomobile, 0x99C, 0xBC8);



enum eMonsterTruckNodes
{
    MONSTER_NODE_NONE = 0,
    MONSTER_CHASSIS = 1,
    MONSTER_WHEEL_RF = 2,
    MONSTER_WHEEL_RM = 3,
    MONSTER_WHEEL_RB = 4,
    MONSTER_WHEEL_LF = 5,
    MONSTER_WHEEL_LM = 6,
    MONSTER_WHEEL_LB = 7,
    MONSTER_DOOR_RF = 8,
    MONSTER_DOOR_RR = 9,
    MONSTER_DOOR_LF = 10,
    MONSTER_DOOR_LR = 11,
    MONSTER_BUMP_FRONT = 12,
    MONSTER_BUMP_REAR = 13,
    MONSTER_WING_RF = 14,
    MONSTER_WING_LF = 15,
    MONSTER_BONNET = 16,
    MONSTER_BOOT = 17,
    MONSTER_WINDSCREEN = 18,
    MONSTER_TRANSMISSION_F = 19,
    MONSTER_TRANSMISSION_R = 20,
    MONSTER_LOADBAY = 21,
    MONSTER_MISC_A = 22,
    MONSTER_NUM_NODES
};
DECL_CLASS_BASED(CMonsterTruck, CAutomobile)
    // Construct/Deconstruct functions
    CMonsterTruck(){}
    DECL_CTORCALL_ARG_HEAD(CMonsterTruck, _ZN13CMonsterTruckC2Eih, int modelIdx, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy)
    DECL_DTORCALL(CMonsterTruck, _ZN13CMonsterTruckD2Ev);

    // Member values
    float m_fTyreCompression[4];
    float m_fWheelRadius;
DECL_CLASS_END()



enum eTrailerNodes
{
    TRAILER_NODE_NONE = 0,
    TRAILER_CHASSIS = 1,
    TRAILER_WHEEL_RF = 2,
    TRAILER_WHEEL_RM = 3,
    TRAILER_WHEEL_RB = 4,
    TRAILER_WHEEL_LF = 5,
    TRAILER_WHEEL_LM = 6,
    TRAILER_WHEEL_LB = 7,
    TRAILER_DOOR_RF = 8,
    TRAILER_DOOR_RR = 9,
    TRAILER_DOOR_LF = 10,
    TRAILER_DOOR_LR = 11,
    TRAILER_BUMP_FRONT = 12,
    TRAILER_BUMP_REAR = 13,
    TRAILER_WING_RF = 14,
    TRAILER_WING_LF = 15,
    TRAILER_BONNET = 16,
    TRAILER_BOOT = 17,
    TRAILER_WINDSCREEN = 18,
    TRAILER_EXHAUST = 19,
    TRAILER_MISC_A = 20,
    TRAILER_MISC_B = 21,
    TRAILER_MISC_C = 22,
    TRAILER_NUM_NODES
};
DECL_CLASS_BASED(CTrailer, CAutomobile)
    // Construct/Deconstruct functions
    CTrailer(){}
    DECL_CTORCALL_ARG_HEAD(CTrailer, _ZN8CTrailerC2Eih, int modelIdx, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy)
    DECL_DTORCALL(CTrailer, _ZN8CTrailerD2Ev);

    // Member values
    CColPoint m_aSupportCols[2];
    float m_fSupportRatios[2];
    float m_fSupportStartZ;
    float m_fSupportExtension;
    float m_fSupportMinRatio;
DECL_CLASS_END()



enum eQuadBikeNodes
{
    QUAD_NODE_NONE = 0,
    QUAD_CHASSIS = 1,
    QUAD_WHEEL_RF = 2,
    QUAD_WHEEL_RM = 3,
    QUAD_WHEEL_RB = 4,
    QUAD_WHEEL_LF = 5,
    QUAD_WHEEL_LM = 6,
    QUAD_WHEEL_LB = 7,
    QUAD_DOOR_RF = 8,
    QUAD_DOOR_RR = 9,
    QUAD_DOOR_LF = 10,
    QUAD_DOOR_LR = 11,
    QUAD_BODY_FRONT = 12,
    QUAD_BODY_REAR = 13,
    QUAD_SUSPENSION_RF = 14,
    QUAD_SUSPENSION_LF = 15,
    QUAD_REAR_AXLE = 16,
    QUAD_HANDLEBARS = 17,
    QUAD_MISC_A = 18,
    QUAD_MISC_B = 19,
    QUAD_NUM_NODES
};
DECL_CLASS_BASED(CQuadBike, CAutomobile)
    // Construct/Deconstruct functions
    CQuadBike(){}
    DECL_CTORCALL_ARG_HEAD(CQuadBike, _ZN9CQuadBikeC2Eih, int modelIdx, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy)
    DECL_DTORCALL(CQuadBike, _ZN9CQuadBikeD2Ev);

    // Member values
    void          *m_pHandling;
    CRideAnimData  m_rideAnimData;
    float          m_fLeftArmSwing;
    float          m_fForkYOff;
    float          m_fForkZOff;
    float          m_fSteerAngleTan;
    union
    {
        unsigned char m_nQuadFlags;
        unsigned char m_bWheelieForCamera : 1;
    };
DECL_CLASS_END()



enum eHeliNodes
{
    HELI_NODE_NONE = 0,
    HELI_CHASSIS = 1,
    HELI_WHEEL_RF = 2,
    HELI_WHEEL_RM = 3,
    HELI_WHEEL_RB = 4,
    HELI_WHEEL_LF = 5,
    HELI_WHEEL_LM = 6,
    HELI_WHEEL_LB = 7,
    HELI_DOOR_RF = 8,
    HELI_DOOR_RR = 9,
    HELI_DOOR_LF = 10,
    HELI_DOOR_LR = 11,
    HELI_STATIC_ROTOR = 12,
    HELI_MOVING_ROTOR = 13,
    HELI_STATIC_ROTOR2 = 14,
    HELI_MOVING_ROTOR2 = 15,
    HELI_RUDDER = 16,
    HELI_ELEVATORS = 17,
    HELI_MISC_A = 18,
    HELI_MISC_B = 19,
    HELI_MISC_C = 20,
    HELI_MISC_D = 21,
    HELI_NUM_NODES
};

struct tHeliLight
{
    CVector m_vecOrigin;
    CVector m_vecTarget;
    float m_fTargetRadius;
    float m_fPower;
    int m_nCoronaIndex;
    bool m_bClipIfColliding;
    bool m_bDrawShadow;
    CVector m_vecEllipseCentre;
    CVector m_vecEllipseForward;
    CVector m_vecEllipseSide;
};

DECL_CLASS_BASED(CHeli, CAutomobile)
    // Construct/Deconstruct functions
    CHeli(){}
    DECL_CTORCALL_ARG_HEAD(CHeli, _ZN5CHeliC2Eih, int modelIdx, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy)
    DECL_DTORCALL(CHeli, _ZN5CHeliD2Ev);

    // Member values
    union
    {
        char            m_nHeliFlags;
        struct
        {
            char        m_bStopFlyingForAWhileFlag : 1;
            char        m_bUseSearchLightOnTarget : 1;
            char        m_bWarnTarger : 1;
        };
    };
    float               m_fLeftRightSkid;
    float               m_fSteeringUpDown;
    float               m_fSteeringLeftRight;
    float               m_fAccelerationBreakStatus;
    float               m_fEngineSpeed;
    float               m_fRotorZ;
    float               m_fSecondRotorZ;
    float               m_fMaxAltitude;
    float               m_fDesiredHeight;
    float               m_fMinAltitude;
    float               m_fFlightDirection;
    bool                m_bStopFlyingForAWhile;
    char                m_nNumSwatOccupants;
    char                m_anSwatIDs[4];
    float               m_afOldSearchLightX[6];
    float               m_afOldSearchLightY[6];
    u32                 m_nLastSearchLightSample;
    CVector             m_vecSearchLightTarget;
    float               m_fSearchLightIntensity;
    u32                 m_nLastTimeSearchLightWasTooFarAwayToShoot;
    u32                 m_nNextTalkTimer;
    FxSystem_c        **m_ppGunflashFx;
    char                m_nFiringMultiplier;
    bool                m_bSearchLightEnabled;
    float               m_fCrashAndBurnTurnSpeed;
DECL_CLASS_END()
CHECKSIZE(CHeli, 0xA2C, 0xC60);



enum ePlaneNodes
{
    PLANE_NODE_NONE = 0,
    PLANE_CHASSIS = 1,
    PLANE_WHEEL_RF = 2,
    PLANE_WHEEL_RM = 3,
    PLANE_WHEEL_RB = 4,
    PLANE_WHEEL_LF = 5,
    PLANE_WHEEL_LM = 6,
    PLANE_WHEEL_LB = 7,
    PLANE_DOOR_RF = 8,
    PLANE_DOOR_RR = 9,
    PLANE_DOOR_LF = 10,
    PLANE_DOOR_LR = 11,
    PLANE_STATIC_PROP = 12,
    PLANE_MOVING_PROP = 13,
    PLANE_STATIC_PROP2 = 14,
    PLANE_MOVING_PROP2 = 15,
    PLANE_RUDDER = 16,
    PLANE_ELEVATOR_L = 17,
    PLANE_ELEVATOR_R = 18,
    PLANE_AILERON_L = 19,
    PLANE_AILERON_R = 20,
    PLANE_GEAR_L = 21,
    PLANE_GEAR_R = 22,
    PLANE_MISC_A = 23,
    PLANE_MISC_B = 24,
    PLANE_NUM_NODES
};

DECL_CLASS_BASED(CPlane, CAutomobile)
    // Construct/Deconstruct functions
    CPlane(){}
    DECL_CTORCALL_ARG_HEAD(CPlane, _ZN6CPlaneC2Eih, int modelIdx, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy)
    DECL_DTORCALL(CPlane, _ZN6CPlaneD2Ev);

    // Member values
    float           m_fYawControl;
    float           m_fPitchControl;
    float           m_fRollControl;
    float           m_fThrottleControl;
    float           m_fScriptThrottleControl;
    float           m_fPreviousRoll;
    uint32_t        m_nStallCounter;
    float           m_fTakeOffDirection;
    float           m_fLowestFlightHeight;
    float           m_fDesiredHeight;
    float           m_fMinHeightAboveTerrain;
    float           m_fFlightDirection;
    float           m_fFlightDirectionAvoidingTerrain;
    float           m_fOldTilt;
    uint32_t        m_nStartedFlyingTime;
    float           m_fEngineSpeed;
    float           m_fPropellerAngle;
    float           m_fLandingGearStatus;
    uint32_t        m_nDamageControlWaveCounter;
    FxSystem_c    **m_pGunParticles;
    uint8_t         m_nFiringMultiplier;
    uint32_t        m_FireMissilePressedTime;
    CEntity        *m_pLastMissileTarget;
    uint32_t        m_nLastHSMissileLOSTime : 31;
    uint32_t        m_bLastHSMissileLOS : 1;
    FxSystem_c     *m_apJettrusParticles[4];
    FxSystem_c     *m_pSmokeParticle;
    int32_t         m_nSmokeTimer;
    bool            m_bSmokeEjectorEnabled;
DECL_CLASS_END()
CHECKSIZE(CPlane, 0xA18, 0xC68);

#endif // __AML_PSDK_SAAUTOMOBILE_H
