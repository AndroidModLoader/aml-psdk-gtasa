#ifndef __AML_PSDK_SAVEHICLE_H
#define __AML_PSDK_SAVEHICLE_H

#include "Physical.h"
#include "Weapon.h"
#include "../audio/AEAudioEntity.h"
#include "../enum/Handling.h"
#include "../enum/CarMission.h"
#include "../enum/Vehicles.h"

struct CPed;
struct CVehicle;
struct tHandlingData;
struct tFlyingHandlingData;
struct CFire;
struct RwTexture;
struct RwObject;
struct RwFrame;
struct RpMaterial;
struct RpAtomic;
struct CAutomobile;
struct CMonsterTruck;
struct CQuadBike;
struct CHeli;
struct CPlane;
struct CBoat;
struct CTrain;
struct CBike;
struct CBmx;
struct CTrailer;

enum eCarWeapon
{
    CAR_WEAPON_NOT_USED,
    CAR_WEAPON_HEAVY_GUN,
    CAR_WEAPON_FREEFALL_BOMB,
    CAR_WEAPON_LOCK_ON_ROCKET,
    CAR_WEAPON_DOUBLE_ROCKET
};

enum eDoorLock : unsigned int
{
    DOORLOCK_NOT_USED,
    DOORLOCK_UNLOCKED,
    DOORLOCK_LOCKED,
    DOORLOCK_LOCKOUT_PLAYER_ONLY,
    DOORLOCK_LOCKED_PLAYER_INSIDE,
    DOORLOCK_COP_CAR,
    DOORLOCK_FORCE_SHUT_DOORS,
    DOORLOCK_SKIP_SHUT_DOORS
};

enum eVehicleApperance
{
    VEHICLE_APPEARANCE_AUTOMOBILE = 1,
    VEHICLE_APPEARANCE_BIKE,
    VEHICLE_APPEARANCE_HELI,
    VEHICLE_APPEARANCE_BOAT,
    VEHICLE_APPEARANCE_PLANE,
};

enum eVehicleLightsFlags
{
    VEHICLE_LIGHTS_TWIN = 1,
    VEHICLE_LIGHTS_IGNORE_DAMAGE = 4,
    VEHICLE_LIGHTS_DISABLE_FRONT = 16,
    VEHICLE_LIGHTS_DISABLE_REAR = 32
};

enum eVehicleCreatedBy
{
    RANDOM_VEHICLE = 1,
    MISSION_VEHICLE = 2,
    PARKED_VEHICLE = 3,
    PERMANENT_VEHICLE = 4
};

enum eBombState
{
    BOMB_TIMED_NOT_ACTIVATED = 1,
    BOMB_IGNITION = 2,
    BOMB_STICKY = 3,
    BOMB_TIMED_ACTIVATED = 4,
    BOMB_IGNITION_ACTIVATED = 5
};

enum eDoors : int
{
    BONNET = 0x0,
    BOOT = 0x1,
    FRONT_LEFT_DOOR = 0x2,
    FRONT_RIGHT_DOOR = 0x3,
    REAR_LEFT_DOOR = 0x4,
    REAR_RIGHT_DOOR = 0x5,
    MAX_DOORS = 0x6,
};

enum eCarDrivingStyle : char
{
    DRIVINGSTYLE_STOP_FOR_CARS,
    DRIVINGSTYLE_SLOW_DOWN_FOR_CARS,
    DRIVINGSTYLE_AVOID_CARS,
    DRIVINGSTYLE_PLOUGH_THROUGH,
    DRIVINGSTYLE_STOP_FOR_CARS_IGNORE_LIGHTS
};

enum eDoorState : unsigned char
{
    DOOR_NOTHING,
    DOOR_HIT_MAX_END,
    DOOR_HIT_MIN_END,
    DOOR_POP_OPEN,
    DOOR_SLAM_SHUT
};

struct CRideAnimData
{
    unsigned int m_nAnimGroup;
    float        m_fSteerAngle;
    float        m_fAnimLean;
    float        m_fDesiredAnimLean;
    float        m_fAnimLeanFwd;
    float        m_fHandlebarsAngle;
    float        m_fAnimPercentageState;
};

DECL_CLASS(CDoor)
    // Member functions
    DECL_THISCALL_SIMPLE(GetAngleOpenRatio, _ZNK5CDoor17GetAngleOpenRatioEv, float);
    DECL_THISCALL_SIMPLE(IsClosed, _ZNK5CDoor8IsClosedEv, bool);
    DECL_THISCALL_SIMPLE(IsFullyOpen, _ZNK5CDoor11IsFullyOpenEv, bool);

    DECL_THISCALL_HEAD(Process, _ZN5CDoor7ProcessEP8CVehicleR7CVectorS3_S3_, bool, CVehicle *pVehicle, CVector &vecOldMoveSpeed, CVector &vecOldTurnSpeed, CVector &vecOffset)
    DECL_THISCALL_TAIL(Process, pVehicle, vecOldMoveSpeed, vecOldTurnSpeed, vecOffset)

    DECL_THISCALL_HEAD(ProcessImpact, _ZN5CDoor13ProcessImpactEP8CVehicleR7CVectorS3_S3_, bool, CVehicle *pVehicle, CVector &vecOldMoveSpeed, CVector &vecOldTurnSpeed, CVector &vecOffset)
    DECL_THISCALL_TAIL(ProcessImpact, pVehicle, vecOldMoveSpeed, vecOldTurnSpeed, vecOffset)

    DECL_THISCALL_HEAD(Open, _ZN5CDoor4OpenEf, bool, float fAngRatio)
    DECL_THISCALL_TAIL(Open, fAngRatio)

    // Member values
    float         m_fOpenAngle;
    float         m_fClosedAngle;
    short         m_nDirn;
    unsigned char m_nAxis;
    eDoorState m_nDoorState;
    float         m_fAngle;
    float         m_fPrevAngle;
    float         m_fAngVel;
DECL_CLASS_END()

DECL_CLASS(CAutoPilot)
    CNodeAddress         m_currentAddress;
    CNodeAddress         m_startingRouteNode;
    CNodeAddress         m_preStartingRouteNode;
    unsigned int         m_nStartSpeedScaleFactor;
    unsigned int         m_nSpeedScaleFactor;
    CCarPathLinkAddress  m_nCurrentPathNodeInfo;
    CCarPathLinkAddress  m_nNextPathNodeInfo;
    CCarPathLinkAddress  m_nPreviousPathNodeInfo;
    unsigned int         m_nTimeToStartMission;
    unsigned int         m_nTimeSwitchedToRealPhysics;
    char                 _smthPreCurr;
    char                 _smthCurr;
    char                 _smthNext;
    char                 m_nCurrentLane;
    char                 m_nNextLane;
    eCarDrivingStyle     m_nCarDrivingStyle;
    eCarMission          m_nCarMission;
    char                 m_nTempAction;
    unsigned int         m_nTempActionTime;
    unsigned int         _someStartTime;
    char                 m_nReverseType;
    char                 m_nTimesWantToChangeNode;
    float                m_fActualTrafficSpeed;
    float                m_fMaxTrafficSpeed;
    char                 m_nCruiseSpeed;
    char                 m_nSpeedFromNodes;
    float                m_fSpeedMult;
    char                 m_nHooverDistFromTarget;
    char                 heliThrustPower;
    char                 m_nMoveAheadOfTarget;
    union
    {
        unsigned char    m_nCarCtrlFlags;
        struct
        {
            unsigned char SlowingDownForCar : 1;
            unsigned char SlowingDownForPed : 1;
            unsigned char AvoidLevelTransitions : 1;
            unsigned char bAlwaysInFastLane : 1;
            unsigned char bAlwaysInSlowLane : 1;
            unsigned char bWarnTargetEntity : 1;
            unsigned char bDontGoAgainstTraffic : 1;
            unsigned char bLeaveAfterAWhile : 1;
            unsigned char bWaitForValidNodes : 1;
            unsigned char bCarHasToReverseFirst : 1;
        };
    };
    char                 m_nSwitchToStraightLineDistance;
    char                 m_nStraightLineDistance;
    char                 m_nTargetReachedDistance;
    char                 m_nLaneChangeCounter;
    char                 m_nFloatingFrames;
    short                m_nAreaConstrainX[2];
    short                m_nAreaConstrainY[2];
    CVector              m_vecDestinationCoors;
    CNodeAddress         m_aPathFindNodesInfo[8];
    unsigned short       m_nPathFindNodesCount;
    CVehicle            *m_pTargetCar;
    CEntity             *m_pCarWeMakingSlowDownFor;
    char                 m_nRecordingId;
    char                 m_nDiversion;
DECL_CLASS_END()



DECL_CLASS_BASED(CVehicle, CPhysical)
    // Construct/Deconstruct functions
    CVehicle(){}
    DECL_CTORCALL_ARG_HEAD(CVehicle, _ZN8CVehicleC2Eh, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(createdBy)
    DECL_DTORCALL(CVehicle, _ZN8CVehicleD2Ev);
    DECL_NEWCALL(CVehicle, BYBIT(_ZN8CVehiclenwEj, _ZN8CVehiclenwEm) );
    DECL_DLCALL(CVehicle, _ZN8CVehicledlEPv);
    
    // Virtual functions
    virtual void ProcessControlCollisionCheck(bool);
    virtual void ProcessControlInputs(unsigned char);
    virtual void GetComponentWorldPosition(int,CVector &);
    virtual bool IsComponentPresent(int);
    virtual void OpenDoor(CPed *,int,eDoors,float,bool);
    virtual void ProcessOpenDoor(CPed *,unsigned int,unsigned int,unsigned int,float);
    virtual float GetDooorAngleOpenRatio(eDoors);
    virtual bool IsDoorReady(eDoors);
    virtual bool IsDoorFullyOpen(eDoors);
    virtual bool IsDoorClosed(eDoors);
    virtual bool IsDoorMissing(eDoors);
    virtual float GetDooorAngleOpenRatio(unsigned int);
    virtual bool IsDoorReady(unsigned int);
    virtual bool IsDoorFullyOpen(unsigned int);
    virtual bool IsDoorClosed(unsigned int);
    virtual bool IsDoorMissing(unsigned int);
    virtual bool IsOpenTopCar(void);
    virtual void RemoveRefsToVehicle(CEntity *);
    virtual void BlowUpCar(CEntity *,unsigned char);
    virtual void BlowUpCarCutSceneNoExtras(bool,bool,bool,bool);
    virtual bool SetUpWheelColModel(CColModel *);
    virtual bool BurstTyre(unsigned char,bool);
    virtual bool IsRoomForPedToLeaveCar(unsigned int,CVector *);
    virtual void ProcessDrivingAnims(CPed *,unsigned char);
    virtual CRideAnimData* GetRideAnimData(void);
    virtual void SetupSuspensionLines(void);
    virtual CVector AddMovingCollisionSpeed(CVector &);
    virtual void Fix(void);
    virtual void SetupDamageAfterLoad(void);
    virtual void DoBurstAndSoftGroundRatios(void);
    virtual float GetHeightAboveRoad(void);
    virtual void PlayCarHorn(void);
    virtual int GetNumContactWheels(void);
    virtual void VehicleDamage(float,unsigned short,CEntity *,CVector *,CVector *,eWeaponType);
    virtual bool CanPedStepOutCar(bool);
    virtual bool CanPedJumpOutCar(CPed *);
    virtual bool GetTowHitchPos(CVector &,bool,CVehicle*);
    virtual bool GetTowBarPos(CVector &,bool,CVehicle*);
    virtual bool SetTowLink(CVehicle*,bool);
    virtual bool BreakTowLink(void);
    virtual float FindWheelWidth(bool);
    virtual bool Save(void);
    virtual bool Load(void);
    virtual bool ProcessAI(unsigned int &);
    
    // Member functions

    // Helper functions
    inline bool IsVehicleTypeValid()     const { return m_nVehicleClass != -1; }
    inline bool IsAutomobile()           const { return m_nVehicleClass == VEHICLE_AUTOMOBILE; }
    inline bool IsMonsterTruck()         const { return m_nVehicleClass == VEHICLE_MTRUCK; }
    inline bool IsQuad()                 const { return m_nVehicleClass == VEHICLE_QUAD; }
    inline bool IsHeli()                 const { return m_nVehicleClass == VEHICLE_HELI; }
    inline bool IsPlane()                const { return m_nVehicleClass == VEHICLE_PLANE; }
    inline bool IsBoat()                 const { return m_nVehicleClass == VEHICLE_BOAT; }
    inline bool IsTrain()                const { return m_nVehicleClass == VEHICLE_TRAIN; }
    inline bool IsFakeAircraft()         const { return m_nVehicleClass == VEHICLE_FHELI || m_nVehicleClass == VEHICLE_FPLANE; }
    inline bool IsBike()                 const { return m_nVehicleClass == VEHICLE_BIKE; }
    inline bool IsBMX()                  const { return m_nVehicleClass == VEHICLE_BMX; }
    inline bool IsTrailer()              const { return m_nVehicleClass == VEHICLE_TRAILER; }
    inline bool IsSubVehicleTypeValid()  const { return m_nVehicleSubClass != -1; }
    inline bool IsSubAutomobile()        const { return m_nVehicleSubClass == VEHICLE_AUTOMOBILE; }
    inline bool IsSubMonsterTruck()      const { return m_nVehicleSubClass == VEHICLE_MTRUCK; }
    inline bool IsSubQuad()              const { return m_nVehicleSubClass == VEHICLE_QUAD; }
    inline bool IsSubHeli()              const { return m_nVehicleSubClass == VEHICLE_HELI; }
    inline bool IsSubPlane()             const { return m_nVehicleSubClass == VEHICLE_PLANE; }
    inline bool IsSubBoat()              const { return m_nVehicleSubClass == VEHICLE_BOAT; }
    inline bool IsSubTrain()             const { return m_nVehicleSubClass == VEHICLE_TRAIN; }
    inline bool IsSubFakeAircraft()      const { return m_nVehicleSubClass == VEHICLE_FHELI || m_nVehicleSubClass == VEHICLE_FPLANE; }
    inline bool IsSubBike()              const { return m_nVehicleSubClass == VEHICLE_BIKE; }
    inline bool IsSubBMX()               const { return m_nVehicleSubClass == VEHICLE_BMX; }
    inline bool IsSubTrailer()           const { return m_nVehicleSubClass == VEHICLE_TRAILER; }
    inline CAutomobile* AsAutomobile()         { return (CAutomobile*)this; }
    inline CMonsterTruck* AsMonsterTruck()     { return (CMonsterTruck*)this; }
    inline CQuadBike* AsQuadBike()             { return (CQuadBike*)this; }
    inline CHeli* AsHeli()                     { return (CHeli*)this; }
    inline CPlane* AsPlane()                   { return (CPlane*)this; }
    inline CBoat* AsBoat()                     { return (CBoat*)this; }
    inline CTrain* AsTrain()                   { return (CTrain*)this; }
    inline CBike* AsBike()                     { return (CBike*)this; }
    inline CBmx* AsBmx()                       { return (CBmx*)this; }
    inline CTrailer* AsTrailer()               { return (CTrailer*)this; }
    
    // Member values
    CAEVehicleAudioEntity m_vehicleAudio;
    tHandlingData* m_pHandlingData;
    tFlyingHandlingData* m_pFlyingHandlingData;
    union {
        eVehicleHandlingFlags  m_nHandlingFlagsIntValue;
        struct {
            unsigned int b1gBoost : 1;
            unsigned int b2gBoost : 1;
            unsigned int bNpcAntiRoll : 1;
            unsigned int bNpcNeutralHandl : 1;
            unsigned int bNoHandbrake : 1;
            unsigned int bSteerRearwheels : 1;
            unsigned int bHbRearwheelSteer : 1;
            unsigned int bAltSteerOpt : 1;
            unsigned int bWheelFNarrow2 : 1;
            unsigned int bWheelFNarrow : 1;
            unsigned int bWheelFWide : 1;
            unsigned int bWheelFWide2 : 1;
            unsigned int bWheelRNarrow2 : 1;
            unsigned int bWheelRNarrow : 1;
            unsigned int bWheelRWide : 1;
            unsigned int bWheelRWide2 : 1;
            unsigned int bHydraulicGeom : 1;
            unsigned int bHydraulicInst : 1;
            unsigned int bHydraulicNone : 1;
            unsigned int bNosInst : 1;
            unsigned int bOffroadAbility : 1;
            unsigned int bOffroadAbility2 : 1;
            unsigned int bHalogenLights : 1;
            unsigned int bProcRearwheelFirst : 1;
            unsigned int bUseMaxspLimit : 1;
            unsigned int bLowRider : 1;
            unsigned int bStreetRacer : 1;
            unsigned int bUnused1 : 1;
            unsigned int bSwingingChassis : 1;
        } m_nHandlingFlags;
    };
    CAutoPilot    m_autoPilot;
    unsigned char bIsLawEnforcer : 1; // Is this guy chasing the player at the moment
    unsigned char bIsAmbulanceOnDuty : 1; // Ambulance trying to get to an accident
    unsigned char bIsFireTruckOnDuty : 1; // Firetruck trying to get to a fire
    unsigned char bIsLocked : 1; // Is this guy locked by the script (cannot be removed)
    unsigned char bEngineOn : 1; // For sound purposes. Parked cars have their engines switched off (so do destroyed cars)
    unsigned char bIsHandbrakeOn : 1; // How's the handbrake doing ?
    unsigned char bLightsOn : 1; // Are the lights switched on ?
    unsigned char bFreebies : 1; // Any freebies left in this vehicle ?

    unsigned char bIsVan : 1; // Is this vehicle a van (doors at back of vehicle)
    unsigned char bIsBus : 1; // Is this vehicle a bus
    unsigned char bIsBig : 1; // Is this vehicle a bus
    unsigned char bLowVehicle : 1; // Need this for sporty type cars to use low getting-in/out anims
    unsigned char bComedyControls : 1; // Will make the car hard to control (hopefully in a funny way)
    unsigned char bWarnedPeds : 1; // Has scan and warn peds of danger been processed?
    unsigned char bCraneMessageDone : 1; // A crane message has been printed for this car allready
    unsigned char bTakeLessDamage : 1; // This vehicle is stronger (takes about 1/4 of damage)

    unsigned char bIsDamaged : 1; // This vehicle has been damaged and is displaying all its components
    unsigned char bHasBeenOwnedByPlayer : 1;// To work out whether stealing it is a crime
    unsigned char bFadeOut : 1; // Fade vehicle out
    unsigned char bIsBeingCarJacked : 1; // Fade vehicle out
    unsigned char bCreateRoadBlockPeds : 1;// If this vehicle gets close enough we will create peds (coppers or gang members) round it
    unsigned char bCanBeDamaged : 1; // Set to FALSE during cut scenes to avoid explosions
    unsigned char bOccupantsHaveBeenGenerated : 1; // Is true if the occupants have already been generated. (Shouldn't happen again)
    unsigned char bGunSwitchedOff : 1; // Level designers can use this to switch off guns on boats

    unsigned char bVehicleColProcessed : 1;// Has ProcessEntityCollision been processed for this car?
    unsigned char bIsCarParkVehicle : 1; // Car has been created using the special CAR_PARK script command
    unsigned char bHasAlreadyBeenRecorded : 1; // Used for replays
    unsigned char bPartOfConvoy : 1;
    unsigned char bHeliMinimumTilt : 1; // This heli should have almost no tilt really
    unsigned char bAudioChangingGear : 1; // sounds like vehicle is changing gear
    unsigned char bIsDrowning : 1; // is vehicle occupants taking damage in water (i.e. vehicle is dead in water)
    unsigned char bTyresDontBurst : 1; // If this is set the tyres are invincible

    unsigned char bCreatedAsPoliceVehicle : 1;// True if this guy was created as a police vehicle (enforcer, policecar, miamivice car etc)
    unsigned char bRestingOnPhysical : 1; // Dont go static cause car is sitting on a physical object that might get removed
    unsigned char bParking : 1;
    unsigned char bCanPark : 1;
    unsigned char bFireGun : 1; // Does the ai of this vehicle want to fire it's gun?
    unsigned char bDriverLastFrame : 1; // Was there a driver present last frame ?
    unsigned char bNeverUseSmallerRemovalRange : 1;// Some vehicles (like planes) we don't want to remove just behind the camera.
    unsigned char bIsRCVehicle : 1; // Is this a remote controlled (small) vehicle. True whether the player or AI controls it.

    unsigned char bAlwaysSkidMarks : 1; // This vehicle leaves skidmarks regardless of the wheels' states.
    unsigned char bEngineBroken : 1; // Engine doesn't work. Player can get in but the vehicle won't drive
    unsigned char bVehicleCanBeTargetted : 1;// The ped driving this vehicle can be targetted, (for Torenos plane mission)
    unsigned char bPartOfAttackWave : 1; // This car is used in an attack during a gang war
    unsigned char bWinchCanPickMeUp : 1; // This car cannot be picked up by any ropes.
    unsigned char bImpounded : 1; // Has this vehicle been in a police impounding garage
    unsigned char bVehicleCanBeTargettedByHS : 1;// Heat seeking missiles will not target this vehicle.
    unsigned char bSirenOrAlarm : 1; // Set to TRUE if siren or alarm active, else FALSE

    unsigned char bHasGangLeaningOn : 1;
    unsigned char bGangMembersForRoadBlock : 1;// Will generate gang members if NumPedsForRoadBlock > 0
    unsigned char bDoesProvideCover : 1; // If this is false this particular vehicle can not be used to take cover behind.
    unsigned char bMadDriver : 1; // This vehicle is driving like a lunatic
    unsigned char bUpgradedStereo : 1; // This vehicle has an upgraded stereo
    unsigned char bConsideredByPlayer : 1; // This vehicle is considered by the player to enter
    unsigned char bPetrolTankIsWeakPoint : 1;// If false shootong the petrol tank will NOT Blow up the car
    unsigned char bDisableParticles : 1; // Disable particles from this car. Used in garage.

    unsigned char bHasBeenResprayed : 1; // Has been resprayed in a respray garage. Reset after it has been checked.
    unsigned char bUseCarCheats : 1; // If this is true will set the car cheat stuff up in ProcessControl()
    unsigned char bDontSetColourWhenRemapping : 1;// If the texture gets remapped we don't want to change the colour with it.
    
    unsigned int   m_nCreationTime;
    unsigned char  m_nPrimaryColor;
    unsigned char  m_nSecondaryColor;
    unsigned char  m_nTertiaryColor;
    unsigned char  m_nQuaternaryColor;
    char           m_anExtras[2];
    short          m_anUpgrades[15];
    float          m_fWheelScale;
    unsigned short m_nAlarmState;
    short          m_nForcedRandomRouteSeed; // if this is non-zero the random wander gets deterministic
    CPed*          m_pDriver;
    CPed*          m_apPassengers[8];
    unsigned char  m_nNumPassengers;
    unsigned char  m_nNumGettingIn;
    unsigned char  m_nGettingInFlags;
    unsigned char  m_nGettingOutFlags;
    unsigned char  m_nMaxPassengers;
    unsigned char  m_nWindowsOpenFlags; // initialised, but not used?
    unsigned char  m_nNitroBoosts;
    unsigned char  m_nSpecialColModel;
    CEntity       *m_pEntityWeAreOn; // we get it from CWorld::ProcessVerticalLine or ProcessEntityCollision, it's entity under us, 
    //only static entities (buildings or roads)
    CFire         *m_pFire;
    float          m_fSteerAngle;
    float          m_f2ndSteerAngle; // used for steering 2nd set of wheels or elevators etc..
    float          m_fGasPedal;
    float          m_fBreakPedal;
    unsigned char  m_nCreatedBy; // see eVehicleCreatedBy
    
    float          cachedTotalSteer; // MOBILE STUFF.
    
    short          m_nExtendedRemovalRange; // when game wants to delete a vehicle, it gets min(m_wExtendedRemovalRange, 170.0)
    unsigned char  m_nBombOnBoard : 3; // 0 = None
    // 1 = Timed
    // 2 = On ignition
    // 3 = remotely set ?
    // 4 = Timed Bomb has been activated
    // 5 = On ignition has been activated
    unsigned char  m_nOverrideLights : 2; // uses enum NO_CAR_LIGHT_OVERRIDE, FORCE_CAR_LIGHTS_OFF, FORCE_CAR_LIGHTS_ON
    unsigned char  m_nWinchType : 2; // Does this vehicle use a winch?
    unsigned char  m_nGunsCycleIndex : 2; // Cycle through alternate gun hardpoints on planes/helis
    unsigned char  m_nOrdnanceCycleIndex : 2; // Cycle through alternate ordnance hardpoints on planes/helis
    unsigned char  m_nUsedForCover; // Has n number of cops hiding/attempting to hid behind it
    unsigned char  m_nAmmoInClip; // Used to make the guns on boat do a reload (20 by default).
    unsigned char  m_nPacMansCollected; // initialised, but not used?
    unsigned char  m_nPedsPositionForRoadBlock; // 0, 1 or 2
    unsigned char  m_nNumCopsForRoadBlock;
    float          m_fDirtLevel; // Dirt level of vehicle body texture: 0.0f=fully clean, 15.0f=maximum dirt visible
    unsigned char  m_nCurrentGear;
    float          m_fGearChangeCount; // used as parameter for cTransmission::CalculateDriveAcceleration, but doesn't change
    float          m_fWheelSpinForAudio;
    float          m_fHealth; // 1000.0f = full health. 0 -> explode
    CVehicle      *m_pTractor;
    CVehicle      *m_pTrailer;
    
    bool           m_bFireAutoFlare; // MOBILE STUFF.
    
    CPed*          m_pWhoInstalledBombOnMe;
    unsigned int   m_nTimeTillWeNeedThisCar; // game won't try to delete this car while this time won't reach
    unsigned int   m_nGunFiringTime; // last time when gun on vehicle was fired (used on boats)
    unsigned int   m_nTimeWhenBlowedUp; // game will delete vehicle when 60 seconds after this time will expire
    short          m_nCopsInCarTimer; // timer for police car (which is following player) occupants to stay in car. If this timer reachs 
                                      // some value, they will leave a car. The timer increases each frame if player is stopped in car, 
                                      // otherway it resets
    short          m_wBombTimer;     // goes down with each frame
    CPed          *m_pWhoDetonatedMe; // if vehicle was detonated, game copies m_pWhoInstalledBombOnMe here
    float          m_fVehicleFrontGroundZ; // we get these values from CCollision::IsStoredPolyStillValidVerticalLine
    float          m_fVehicleRearGroundZ;  // 
    unsigned char  m_nOilSpills;
    float          m_fLastOilSpillX;
    float          m_fLastOilSpillY;
    eDoorLock      m_eDoorLock;
    unsigned int   m_nProjectileWeaponFiringTime; // manual-aimed projectiles for hunter, lock-on projectile for hydra
    unsigned int   m_nAdditionalProjectileWeaponFiringTime; // manual-aimed projectiles for hydra
    unsigned int   m_nTimeForMinigunFiring; // minigun on hunter
    unsigned char  m_nLastWeaponDamageType; // see eWeaponType, -1 if no damage
    CEntity       *m_pLastDamageEntity;
    char           m_nRadioStation; // not used?
    char           m_nRainHitCount; // initialised, but not used?
    char           m_nSoundIndex; // initialised, but not used?
    char           m_nVehicleWeaponInUse; // see enum eCarWeapon
    unsigned int   m_nHornCounter;
    char           m_nHornPattern; // random id related to siren
    char           m_nNoHornCounter; // car horn related
    char           m_nComedyControlsStatus;
    char           m_nHasslePosId;
    CStoredCollPoly m_FrontCollPoly; // poly which is under front part of car
    CStoredCollPoly m_RearCollPoly; // poly which is under rear part of car
    unsigned char  m_anCollisionLighting[4]; // left front, left rear, right front, right rear
    FxSystem_c    *m_pOverheatParticle;
    FxSystem_c    *m_pFireParticle;
    FxSystem_c    *m_pDustParticle;
    union {
        unsigned char     m_nRenderLightsFlags;
        struct {
            unsigned char m_bRightFront : 1;
            unsigned char m_bLeftFront : 1;
            unsigned char m_bRightRear : 1;
            unsigned char m_bLeftRear : 1;
        } m_renderLights;
    };
    RwTexture     *m_pCustomCarPlate;
    float          m_fSteer;
    unsigned int   m_nVehicleClass; // see enum eVehicleClass
    unsigned int   m_nVehicleSubClass;
    const char    *m_szPreviousRemapTxdName;
    const char    *m_szRemapTxdName;
    RwTexture     *m_pRemapTexture;
DECL_CLASS_END()
CHECKSIZE(CVehicle, 0x5B4, 0x758);

DECL_FASTCALL_SIMPLE_GLO(DestroyVehicleAndDriverAndPassengers, _Z36DestroyVehicleAndDriverAndPassengersP8CVehicle, void, CVehicle* pVehicle);
DECL_FASTCALL_SIMPLE_GLO(IsVehiclePointerValid, _Z21IsVehiclePointerValidP8CVehicle, bool, CVehicle* pVehicle);
DECL_FASTCALL_SIMPLE_GLO(IsVehiclePointerValid_NotInWorld, _Z32IsVehiclePointerValid_NotInWorldP8CVehicle, bool, CVehicle* pVehicle);
DECL_FASTCALL_SIMPLE_GLO(SetVehicleAtomicVisibility, _Z28SetVehicleAtomicVisibilityCBP8RwObjectPv, RwObject*, RwObject* pObject, void* pData);
DECL_FASTCALL_SIMPLE_GLO(SetVehicleAtomicVisibility_RwFrame, _Z28SetVehicleAtomicVisibilityCBP7RwFramePv, RwFrame*, RwFrame* pFrame, void* pData);
DECL_FASTCALL_SIMPLE_GLO(SetCompAlphaCB, _Z14SetCompAlphaCBP10RpMaterialPv, RpMaterial*, RpMaterial* pMaterial, void* pData);
DECL_FASTCALL_SIMPLE_GLO(RemoveUpgradeCB, _Z15RemoveUpgradeCBCBP8RpAtomicPv, RpAtomic*, RpAtomic* pAtomic, void* pData);
DECL_FASTCALL_SIMPLE_GLO(FindUpgradeCB, _Z13FindUpgradeCBCBP8RpAtomicPv, RpAtomic*, RpAtomic* pAtomic, void* pData);

#endif // __AML_PSDK_SAVEHICLE_H
