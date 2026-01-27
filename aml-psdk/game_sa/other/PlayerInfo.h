#ifndef __AML_PSDK_SAPLAYERINFO_H
#define __AML_PSDK_SAPLAYERINFO_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include "PlayerData.h"

struct CPlayerPed;
struct CVehicle;
struct RwTexture;

enum ePlayerState
{
    PLAYERSTATE_PLAYING,
    PLAYERSTATE_HASDIED,
    PLAYERSTATE_HASBEENARRESTED,
    PLAYERSTATE_FAILEDMISSION,
    PLAYERSTATE_LEFTGAME
};

DECL_CLASS(CPlayerInfo)
    // Member functions
    DECL_THISCALL_SIMPLE(Clear, _ZN11CPlayerInfo5ClearEv, void);
    DECL_THISCALL_SIMPLE(WorkOutEnergyFromHunger, _ZN11CPlayerInfo23WorkOutEnergyFromHungerEv, void);
    DECL_THISCALL_SIMPLE(GivePlayerParachute, _ZN11CPlayerInfo19GivePlayerParachuteEv, void);
    DECL_THISCALL_SIMPLE(IsPlayerInRemoteMode, _ZN11CPlayerInfo20IsPlayerInRemoteModeEv, bool);
    DECL_THISCALL_SIMPLE(GetSpeed, _ZN11CPlayerInfo8GetSpeedEv, CVector);
    DECL_THISCALL_SIMPLE(GetPos, _ZN11CPlayerInfo6GetPosEv, CVector);
    DECL_THISCALL_SIMPLE(IsRestartingAfterDeath, _ZN11CPlayerInfo22IsRestartingAfterDeathEv, u8);
    DECL_THISCALL_SIMPLE(IsRestartingAfterArrest, _ZN11CPlayerInfo23IsRestartingAfterArrestEv, u8);
    DECL_THISCALL_SIMPLE(IsRestartingAfterMissionFailed, _ZN11CPlayerInfo30IsRestartingAfterMissionFailedEv, u8);
    DECL_THISCALL_SIMPLE(KillPlayer, _ZN11CPlayerInfo10KillPlayerEv, void);
    DECL_THISCALL_SIMPLE(ArrestPlayer, _ZN11CPlayerInfo12ArrestPlayerEv, void);
    DECL_THISCALL_SIMPLE(PlayerFailedCriticalMission, _ZN11CPlayerInfo27PlayerFailedCriticalMissionEv, void);
    DECL_THISCALL_SIMPLE(LoadPlayerSkin, _ZN11CPlayerInfo14LoadPlayerSkinEv, void);
    DECL_THISCALL_SIMPLE(DeletePlayerSkin, _ZN11CPlayerInfo16DeletePlayerSkinEv, void);
    DECL_THISCALL_SIMPLE(Save, _ZN11CPlayerInfo4SaveEv, bool);
    DECL_THISCALL_SIMPLE(Load, _ZN11CPlayerInfo4LoadEv, bool);

    // Member values
    CPlayerPed *m_pPed;                           // Pointer to the player ped (should always be set)
    CPlayerData m_PlayerData;               // instance of player variables
    CVehicle *m_pRemoteVehicle;             // Pointer to vehicle player is driving remotely at the moment.(NULL if on foot)
    CVehicle *m_pSpecCar;                   // which car is using the special collision model
    int m_nMoney;                           // Points for this player
    int m_nDisplayMoney;                    // Points as they would be displayed
    unsigned int m_nCollectablesPickedUp;   // How many bags of sugar do we have
    unsigned int m_nTotalNumCollectables;   // How many bags of sugar are there to be had in the game
    unsigned int m_nLastBumpPlayerCarTimer; // Keeps track of when the last ped bumped into the player car
    unsigned int m_nTaxiTimer;              // Keeps track of how long the player has been in a taxi with a passenger (in msecs)
    unsigned int m_nVehicleTimeCounter;     // keeps track of how long player has been in car for driving skill
    bool m_bTaxiTimerScore;                 // If TRUE then add 1 to score for each second that the player is driving a taxi
    bool m_bTryingToExitCar;                // if player holds exit car button, want to trigger getout once car slowed enough with a passenger
    CVehicle *m_pLastTargetVehicle;         // Last vehicle player tried to enter.
    unsigned char m_nPlayerState;           // see ePlayerState
    bool m_bAfterRemoteVehicleExplosion;
    bool m_bCreateRemoteVehicleExplosion;
    bool m_bFadeAfterRemoteVehicleExplosion;
    unsigned int m_nTimeOfRemoteVehicleExplosion;
    unsigned int m_nLastTimeEnergyLost;      // To make numbers flash on the HUD;
    unsigned int m_nLastTimeArmourLost;
    unsigned int m_nLastTimeBigGunFired;    // Tank guns etc
    unsigned int m_nTimesUpsideDownInARow;  // Make car blow up if car upside down
    unsigned int m_nTimesStuckInARow;       // Make car blow up if player cannot get out.
    unsigned int m_nCarTwoWheelCounter;     // how long has player's car been on two wheels
    float m_fCarTwoWheelDist;               // Make car blow up if player cannot get out.
    unsigned int m_nCarLess3WheelCounter;   // how long has player's car been on less than 3 wheels
    unsigned int m_nBikeRearWheelCounter;   // how long has player's bike been on rear wheel only
    float m_fBikeRearWheelDist;
    unsigned int m_nBikeFrontWheelCounter;  // how long has player's bike been on front wheel only
    float m_fBikeFrontWheelDist;
    unsigned int m_nTempBufferCounter;      // so wheels can leave the ground for a few frames without stopping above counters
    unsigned int m_nBestCarTwoWheelsTimeMs;
    float m_fBestCarTwoWheelsDistM;
    unsigned int m_nBestBikeWheelieTimeMs;
    float m_fBestBikeWheelieDistM;
    unsigned int m_nBestBikeStoppieTimeMs;
    float m_fBestBikeStoppieDistM;
    unsigned short m_nCarDensityForCurrentZone;
    float m_fRoadDensityAroundPlayer;       // 1.0f for an average city.
    unsigned int m_nTimeOfLastCarExplosionCaused;
    unsigned int m_nExplosionMultiplier;
    unsigned int m_nHavocCaused;            // A counter going up when the player does bad stuff.
    unsigned short m_nNumHoursDidntEat;
    float m_fCurrentChaseValue;             // How 'ill' is the chase at the moment
    bool m_bDoesNotGetTired;
    bool m_bFastReload;
    bool m_bFireProof;
    unsigned char m_nMaxHealth;
    unsigned char m_nMaxArmour;
    bool m_bGetOutOfJailFree;               // Player doesn't lose money/weapons next time arrested
    bool m_bGetOutOfHospitalFree;           // Player doesn't lose money next time patched up at hospital
    bool m_bCanDoDriveBy;
    unsigned char m_nBustedAudioStatus;
    unsigned short m_nLastBustMessageNumber;
    unsigned int m_nCrosshairActivated;
    CVector2D m_vecCrosshairTarget;         // -1 ... 1 on screen
    bool m_bGetObject; // something weird on mobile (with typo in the name)
    char m_szSkinName[32];
    RwTexture *m_pSkinTexture;
    bool m_bParachuteReferenced;
    unsigned int m_nRequireParachuteTimer;
DECL_CLASS_END()
CHECKSIZE(CPlayerInfo, 0x194, 0x1D8);

#endif // __AML_PSDK_SAPLAYERINFO_H
