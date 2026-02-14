#ifndef __AML_PSDK_SAAEAUDIOENTITY_H
#define __AML_PSDK_SAAEAUDIOENTITY_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;
struct CAEAudioEntity;
struct CPed;
struct FxSystem_c;

enum eSoundEnvironment : unsigned short
{
    SOUND_FRONT_END = 1,
    SOUND_UNCANCELLABLE = 2,
    SOUND_REQUEST_UPDATES = 4,
    SOUND_PLAY_PHYSICALLY = 8,
    SOUND_UNPAUSABLE = 16,
    SOUND_START_PERCENTAGE = 32,
    SOUND_MUSIC_MASTERED = 64,
    SOUND_LIFESPAN_TIED_TO_PHYSICAL_ENTITY = 128,
    SOUND_UNDUCKABLE = 256,
    SOUND_UNCOMPRESSABLE = 512,
    SOUND_ROLLED_OFF = 1024,
    SOUND_SMOOTH_DUCKING = 2048,
    SOUND_FORCED_FRONT = 4096
};

enum eAudioPedType
{
    PED_TYPE_GEN = 0,
    PED_TYPE_EMG = 1,
    PED_TYPE_PLAYER = 2,
    PED_TYPE_GANG = 3,
    PED_TYPE_GFD = 4,
    PED_TYPE_SPC = 5
};

DECL_CLASS(CAESound)
    // Construct/Deconstruct functions
    CAESound(){}
    DECL_CTORCALL_ARG_HEAD(CAESound, _ZN8CAESoundC2EssP14CAEAudioEntity7CVectorffffhtf, i16 BankSlotID, i16 SoundID, CAEAudioEntity *pAudioEntity,
                                                                                        CVector Position, float Volume, float RollOffFactor, float RelativeFrequency,
                                                                                        float Doppler, u8 FrameDelay, u16 Environment, float FrequencyVariance)
    DECL_CTORCALL_ARG_TAIL(BankSlotID, SoundID, pAudioEntity, Position, Volume, RollOffFactor, RelativeFrequency, Doppler, FrameDelay, Environment, FrequencyVariance)
    DECL_DTORCALL(CAESound, _ZN8CAESoundD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(UnregisterWithPhysicalEntity, _ZN8CAESound28UnregisterWithPhysicalEntityEv, void);
    DECL_THISCALL_SIMPLE(NewVPSLentry, _ZN8CAESound12NewVPSLentryEv, void);
    DECL_THISCALL_SIMPLE(CalculateFrequency, _ZN8CAESound18CalculateFrequencyEv, void);
    DECL_THISCALL_SIMPLE(GetLifespanTiedToPhysicalEntity, _ZN8CAESound31GetLifespanTiedToPhysicalEntityEv, u16);
    DECL_THISCALL_SIMPLE(StopSound, _ZN8CAESound9StopSoundEv, void);
    DECL_THISCALL_SIMPLE(GetRequestUpdates, _ZN8CAESound17GetRequestUpdatesEv, u16);
    DECL_THISCALL_SIMPLE(UpdateFrequency, _ZN8CAESound15UpdateFrequencyEv, void);
    DECL_THISCALL_SIMPLE(StopSoundAndForget, _ZN8CAESound18StopSoundAndForgetEv, void);
    DECL_THISCALL_SIMPLE(GetUncancellable, _ZN8CAESound16GetUncancellableEv, u16);
    DECL_THISCALL_SIMPLE(GetFrontEnd, _ZN8CAESound11GetFrontEndEv, u16);
    DECL_THISCALL_SIMPLE(GetUnpausable, _ZN8CAESound13GetUnpausableEv, u16);
    DECL_THISCALL_SIMPLE(GetPlayPhysically, _ZN8CAESound17GetPlayPhysicallyEv, u16);
    DECL_THISCALL_SIMPLE(GetStartPercentage, _ZN8CAESound18GetStartPercentageEv, u16);
    DECL_THISCALL_SIMPLE(GetMusicMastered, _ZN8CAESound16GetMusicMasteredEv, u16);
    DECL_THISCALL_SIMPLE(GetUnduckable, _ZN8CAESound13GetUnduckableEv, u16);
    DECL_THISCALL_SIMPLE(GetUncompressable, _ZN8CAESound17GetUncompressableEv, u16);
    DECL_THISCALL_SIMPLE(GetRolledOff, _ZN8CAESound12GetRolledOffEv, u16);
    DECL_THISCALL_SIMPLE(GetSmoothDucking, _ZN8CAESound16GetSmoothDuckingEv, u16);
    DECL_THISCALL_SIMPLE(GetForcedFront, _ZN8CAESound14GetForcedFrontEv, u16);
    DECL_THISCALL_SIMPLE(SoundHasFinished, _ZN8CAESound16SoundHasFinishedEv, void);
    DECL_THISCALL_SIMPLE(CalculateVolume, _ZN8CAESound15CalculateVolumeEv, void);
    DECL_THISCALL_SIMPLE(GetRelativePlaybackFrequencyWithDoppler, _ZN8CAESound39GetRelativePlaybackFrequencyWithDopplerEv, float);
    DECL_THISCALL_SIMPLE(GetSlowMoFrequencyScalingFactor, _ZN8CAESound31GetSlowMoFrequencyScalingFactorEv, float);

    DECL_THISCALL_HEAD(Initialise, _ZN8CAESound10InitialiseEssP14CAEAudioEntity7CVectorffffhtfs, void, i16 BankSlotID, i16 SoundID, CAEAudioEntity *pAudioEntity,
                                                                                        CVector Position, float Volume, float RollOffFactor, float RelativeFrequency,
                                                                                        float Doppler, u8 FrameDelay, u16 Environment, float FrequencyVariance, i16 PlayTime)
    DECL_THISCALL_TAIL(Initialise, BankSlotID, SoundID, pAudioEntity, Position, Volume, RollOffFactor, RelativeFrequency, Doppler, FrameDelay, Environment, FrequencyVariance, PlayTime)

    DECL_THISCALL_HEAD(UpdateParameters, _ZN8CAESound16UpdateParametersEs, void, i16 PlayTime)
    DECL_THISCALL_TAIL(UpdateParameters, PlayTime)

    DECL_THISCALL_HEAD(RegisterWithPhysicalEntity, _ZN8CAESound26RegisterWithPhysicalEntityEP7CEntity, void, CEntity *pPhysicalEntity)
    DECL_THISCALL_TAIL(RegisterWithPhysicalEntity, pPhysicalEntity)

    DECL_THISCALL_HEAD(SetIndividualEnvironment, _ZN8CAESound24SetIndividualEnvironmentEtt, void, u16 environment, u16 tf)
    DECL_THISCALL_TAIL(SetIndividualEnvironment, environment, tf)

    DECL_THISCALL_HEAD(UpdatePlayTime, _ZN8CAESound14UpdatePlayTimeEsss, void, i16 VirtualChannelSoundLength, i16 VirtualChannelSoundLoopStartTime, i16 TimeElapsed)
    DECL_THISCALL_TAIL(UpdatePlayTime, VirtualChannelSoundLength, VirtualChannelSoundLoopStartTime, TimeElapsed)

    DECL_THISCALL_HEAD(GetRelativePosition, _ZN8CAESound19GetRelativePositionEP7CVector, void, CVector *pRelativePosition)
    DECL_THISCALL_TAIL(GetRelativePosition, pRelativePosition)

    // Member values
    short                 m_nBankSlotId;
    short                 m_nSoundIdInSlot;
    CAEAudioEntity       *m_pBaseAudio;
    CEntity              *m_pPhysicalEntity;
    unsigned int          m_nEvent;
    float                 m_fMaxVolume;
    float                 m_fVolume;
    float                 m_fSoundDistance;
    float                 m_fSpeed;
    float                 m_FrequencyVariance;
    CVector               m_vecCurrPosn;
    CVector               m_vecPrevPosn;
    unsigned int          m_nLastFrameUpdate;
    unsigned int          m_nCurrTimeUpdate;
    unsigned int          m_nPrevTimeUpdate;
    float                 m_fCurrCamDist;
    float                 m_fPrevCamDist;
    float                 m_fTimeScale;
    char                  m_FrameDelay;
    union
    {
        unsigned short m_nEnvironmentFlags;
        struct
        {
            unsigned short m_bFrontEnd : 1;
            unsigned short m_bUncancellable : 1;
            unsigned short m_bRequestUpdates : 1;
            unsigned short m_bPlayPhysically : 1;
            unsigned short m_bUnpausable : 1;
            unsigned short m_bStartPercentage : 1;
            unsigned short m_bMusicMastered : 1;
            unsigned short m_bLifespanTiedToPhysicalEntity : 1;
            unsigned short m_bUndackable : 1;
            unsigned short m_bUncompressable : 1;
            unsigned short m_bRolledOff : 1;
            unsigned short m_bSmoothDucking : 1;
            unsigned short m_bForcedFront : 1;
        };
    };
    unsigned short        m_nIsUsed;
    unsigned short        m_bAudioHardwareAware;
    short                 m_nCurrentPlayPosition;
    short                 m_bPhysicallyPlaying;
    float                 m_fFinalVolume;
    float                 m_fFrequency;
    short                 m_nPlayingState;
    float                 m_fSoundHeadRoom;
    short                 m_nSoundLength;
DECL_CLASS_END()
CHECKSIZE(CAESound, 0x74, 0x80);



DECL_CLASS_VTABLE(CAEAudioEntity)
    CEntity *m_pEntity;
    CAESound m_tempSound;
    virtual void UpdateParameters(CAESound *pSound, short PlayPosition);
DECL_CLASS_END()
CHECKSIZE(CAEAudioEntity, 0x7C, 0x90);



DECL_CLASS_BASED(CAETwinLoopSoundEntity, CAEAudioEntity)
    short           m_nBankSlotId;
    short           m_nSoundType[2];
    CAEAudioEntity *m_pBaseAudio;
    short           m_bIsInitialised;
    short           m_nFirstLength;
    short           m_nSecondLength;
    short           m_nPlayTimeMin;
    short           m_nPlayTimeMax;
    unsigned int    m_nTimeToSwapSounds;
    bool            m_bPlayingFirstSound;
    short           m_anStartingPlayPercentage[2];
    CAESound       *m_apSounds[2];
DECL_CLASS_END()
CHECKSIZE(CAETwinLoopSoundEntity, 0xA8, 0xC8);



DECL_CLASS_BASED(CAEPedAudioEntity, CAEAudioEntity)
    bool m_bInitialised;
    short m_nLastSwimSplashSoundId;
    int m_nLastSwimWakeTriggerTimeMs;
    float m_fCurrentJetPackThrustVolume;
    float m_fCurrentJetPackGasVolume;
    float m_fCurrentJetPackRoarVolume;
    float m_fCurrentJetPackRoarFrequency;
    CPed *m_pPed;
    char m_bJetpackOn;
    CAESound *m_pJetPackThrustSound;
    CAESound *m_pJetPackGasSound;
    CAESound *m_pJetPackRoarSound;
    CAETwinLoopSoundEntity TwinLoopSoundEntity;
    CAESound *m_pWindRushSound;
    float m_fCurrentWindRushVolume;
    float m_fCurrentShirtFlapVolume;
DECL_CLASS_END()
CHECKSIZE(CAEPedAudioEntity, 0x15C, 0x1A8);



DECL_CLASS_BASED(CAEPedSpeechAudioEntity, CAEAudioEntity)
    CAESound* m_aSounds[5];
    bool m_bInitialised;
    short m_nVoiceType; // see eAudioPedType
    short m_nVoiceID;
    short m_nVoiceGender;
    bool m_bTalking;
    bool m_bEnableVocalType;
    bool m_bMuted;
    char m_nVocalEnableFlag;
    bool m_bFrontEnd;
    bool m_bForceAudible;
    CAESound *m_pSound;
    short m_nSoundId;
    short m_nBankId;
    short m_nPedSpeechSlotIndex;
    float m_fVoiceVolume;
    short m_nCurrentPhraseId;
    int m_NextTimeCanSayPain[19];
DECL_CLASS_END()
CHECKSIZE(CAEPedSpeechAudioEntity, 0x100, 0x130);



DECL_CLASS_BASED(CAEWeaponAudioEntity, CAEAudioEntity)
    bool m_bPlayedMiniGunFireSound;
    bool m_bMiniGunFireActive;
    char m_nLastWeaponPlaneFrequencyIndex;
    char m_nState;
    char m_nChainsawSoundState;
    int m_dwFlameThrowerLastPlayedTime;
    int m_dwSpraycanLastPlayedTime;
    int m_dwExtinguisherLastPlayedTime;
    int m_dwMiniGunFireSoundPlayedTime;
    int m_dwTimeChainsaw;
    int m_dwTimeLastFired;
    CAESound *m_pSounds;
DECL_CLASS_END()
CHECKSIZE(CAEWeaponAudioEntity, 0xA0, 0xB8);



DECL_CLASS_BASED(CAEPedWeaponAudioEntity, CAEWeaponAudioEntity)
    bool m_bActive;
    CPed* m_pPed;
DECL_CLASS_END()
CHECKSIZE(CAEPedWeaponAudioEntity, 0xA8, 0xC8);



enum eVehicleSoundType : char
{
    VEHICLE_SOUND_CAR = 0x0,
    VEHICLE_SOUND_MOTORCYCLE = 0x1,
    VEHICLE_SOUND_BICYCLE = 0x2,
    VEHICLE_SOUND_BOAT = 0x3,
    VEHICLE_SOUND_HELI = 0x4,
    VEHICLE_SOUND_PLANE = 0x5,
    VEHICLE_SOUND_NON_VEH = 0x6,
    VEHICLE_SOUND_USED_BY_NONE_VEH = 0x7,
    VEHICLE_SOUND_TRAIN = 0x8,
    VEHICLE_SOUND_TRAILER = 0x9,
    VEHICLE_SOUND_SPECIAL = 0xA,
};

enum eRadioType : char
{
    RADIO_CIVILIAN = 0x0,
    RADIO_SPECIAL = 0x1,
    RADIO_UNKNOWN = 0x2,
    RADIO_EMERGENCY = 0x3,
    RADIO_DISABLED = 0xFF,
};

enum eRadioID : char
{
    RADIO_PLAYBACK_FM=1,
    RADIO_K_ROSE,
    RADIO_K_DST,     
    RADIO_BOUNCE_FM,
    RADIO_SF_UR,
    RADIO_LOS_SANTOS,
    RADIO_RADIO_X,
    RADIO_CSR_103_9,
    RADIO_K_JAH_WEST,
    RADIO_MASTER_SOUNDS_98_3,
    RADIO_WCTR,
    RADIO_USER_TRACKS,
    RADIO_NONE
};

struct tVehicleAudioSettings
{
    eVehicleSoundType  m_nVehicleSoundType;
    short m_nEngineOnSoundBankId;
    short m_nEngineOffSoundBankId;
    char  m_nBassSetting;   // m_nStereo
    float m_fBassEq;
    float m_fEnginePitch;
    char  m_bHornTon;   // sfx id
    float m_fHornHigh;
    char  m_nDoorSound;
    char m_nEngineUpgrade;
    eRadioID m_nRadioID;
    eRadioType m_nRadioType;
    char vehTypeForAudio;
    float m_fHornVolumeDelta;
};

struct tVehicleSound
{
    unsigned int  m_nIndex;
    CAESound     *m_pSound;
};

DECL_CLASS_BASED(CAEVehicleAudioEntity, CAEAudioEntity)
    short                   m_nStallCounter;
    tVehicleAudioSettings   m_settings;
    bool                    m_bEnabled;
    bool                    m_bPlayerDriver;
    bool                    m_bPlayerPassenger;
    bool                    m_bVehicleRadioPaused;
    bool                    m_bSoundsStopped;
    char                    m_nEngineState;
    char                    m_nAudioGear;
    float                   m_CrzCount;
    bool                    m_bInhibitAccForLowSpeed;
    short                   m_nRainDropCounter;
    short                   m_nStalledCounter;
    unsigned int            m_nSwapStalledTime;
    bool                    m_bSilentStalled;
    bool                    m_bDisableHeliEngineSounds;
    bool                    m_bHornOn;
    bool                    m_bSirenOrAlarmPlaying;
    bool                    m_bHornPlaying;
    float                   m_fSirenVolume;
    bool                    m_bModelWithSiren;
    unsigned int            m_nBoatHitWaveLastPlayedTime;
    unsigned int            m_nTimeToInhibitAcc;
    unsigned int            m_nTimeToInhibitCrz;
    float                   m_fGeneralVehicleSoundVolume;
    short                   m_nEngineDecelerateSoundBankId;
    short                   m_nEngineAccelerateSoundBankId;
    short                   m_nEngineBankSlotId;
    tVehicleSound           m_aEngineSounds[12];
    unsigned int            m_TimeLastServiced;
    short                   m_ACPlayPositionThisFrame;
    short                   m_ACPlayPositionLastFrame;
    short                   m_FramesAgoACLooped;
    short                   m_ACPlayPercentWhenStopped;
    unsigned int            m_TimeACStopped;
    short                   m_ACPlayPositionWhenStopped;
    short                   m_nSkidSoundType;
    CAESound               *m_pSurfaceSound;
    short                   m_nRoadNoiseSoundType;
    CAESound               *m_pRoadNoiseSound;
    short                   m_nFlatTyreSoundType;
    CAESound               *m_pFlatTyreSound;
    short                   m_nReverseGearSoundType;
    CAESound               *m_pReverseGearSound;
    short                   m_nHornSoundType;
    CAESound               *m_pHornTonSound;
    CAESound               *m_pSirenSound;
    CAESound               *m_pPoliceSirenSound;
    CAETwinLoopSoundEntity  m_skidSound;
    float                   m_CurrentRotorFrequency;
    float                   m_CurrentDummyEngineVolume;
    float                   m_CurrenytDummyEngineFrequency;
    float                   m_fMovingPartSmoothedSpeed;
    float                   m_fFadeIn;
    float                   m_fFadeOut;
    bool                    m_bNitroSoundPresent;
    float                   m_CurrentNitroRadio;
DECL_CLASS_END()
CHECKSIZE(CAEVehicleAudioEntity, 0x24C, 0x310);



DECL_CLASS_BASED(CAEWeatherAudioEntity, CAEAudioEntity)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(StaticReset, _ZN21CAEWeatherAudioEntity11StaticResetEv, void);

    // Member functions
    DECL_THISCALL_SIMPLE(Service, _ZN21CAEWeatherAudioEntity7ServiceEv, void);

    DECL_THISCALL_HEAD(AddAudioEvent, _ZN21CAEWeatherAudioEntity13AddAudioEventEi, void, int AudioEvent)
    DECL_THISCALL_TAIL(AddAudioEvent, AudioEvent)

    // Member values
    i8 m_nLastThunderFrequencyIndex;
DECL_CLASS_END()



DECL_CLASS_BASED(CAEFireAudioEntity, CAEAudioEntity)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(StaticInitialise, _ZN18CAEFireAudioEntity16StaticInitialiseEv, void);

    // Member functions
    DECL_THISCALL_SIMPLE(Terminate, _ZN18CAEFireAudioEntity9TerminateEv, void);

    DECL_THISCALL_HEAD(Initialise, _ZN18CAEFireAudioEntity10InitialiseEP10FxSystem_c, void, FxSystem_c *pParent)
    DECL_THISCALL_TAIL(Initialise, pParent)

    DECL_THISCALL_HEAD(AddAudioEvent, _ZN18CAEFireAudioEntity13AddAudioEventEiR7CVector, void, int AudioEvent, CVector &vPosition)
    DECL_THISCALL_TAIL(AddAudioEvent, AudioEvent, vPosition)

    DECL_THISCALL_HEAD(PlayWaterSounds, _ZN18CAEFireAudioEntity15PlayWaterSoundsEiR7CVector, void, int AudioEvent, CVector &vPosition)
    DECL_THISCALL_TAIL(PlayWaterSounds, AudioEvent, vPosition)

    DECL_THISCALL_HEAD(PlayFireSounds, _ZN18CAEFireAudioEntity14PlayFireSoundsEiR7CVector, void, int AudioEvent, CVector &vPosition)
    DECL_THISCALL_TAIL(PlayFireSounds, AudioEvent, vPosition)

    // Member values
    CAESound   *m_pFireSound;
    CAESound   *m_pFireSound2;
    FxSystem_c *m_pParentEffectSystem;
DECL_CLASS_END()

#endif // __AML_PSDK_SAAEAUDIOENTITY_H
