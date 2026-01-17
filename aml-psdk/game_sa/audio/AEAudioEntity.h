#ifndef __AML_PSDK_SAAEAUDIOENTITY_H
#define __AML_PSDK_SAAEAUDIOENTITY_H

#include <aml-psdk/sdk_base.h>

struct CEntity;
struct CAEAudioEntity;
struct CPed;

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

struct CAESound
{
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
};
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

#endif // __AML_PSDK_SAAEAUDIOENTITY_H