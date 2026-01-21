#ifndef __AML_PSDK_SA2DEFFECT_H
#define __AML_PSDK_SA2DEFFECT_H

#include <aml-psdk/renderware/RwVector.h>
#include <aml-psdk/renderware/RwRGBA.h>

struct RwTexture;
struct RpAtomic;

enum e2dEffectType
{
    EFFECT_LIGHT = 0,
    EFFECT_PARTICLE,
    EFFECT_ATTRACTOR = 3,
    EFFECT_SUN_GLARE,
    EFFECT_FURNITUR,
    EFFECT_ENEX,
    EFFECT_ROADSIGN,
    EFFECT_SLOTMACHINE_WHEEL,
    EFFECT_COVER_POINT,
    EFFECT_ESCALATOR,
};

enum ePedAttractorType
{
    PED_ATTRACTOR_ATM            = 0, // Ped uses ATM(at day time only)
    PED_ATTRACTOR_SEAT           = 1, // Ped sits(at day time only)
    PED_ATTRACTOR_STOP           = 2, // Ped stands(at day time only)
    PED_ATTRACTOR_PIZZA          = 3, // Ped stands for few seconds
    PED_ATTRACTOR_SHELTER        = 4, // Ped goes away after spawning, but stands if weather is rainy
    PED_ATTRACTOR_TRIGGER_SCRIPT = 5, // Launches an external script
    PED_ATTRACTOR_LOOK_AT        = 6, // Ped looks at object, then goes away
    PED_ATTRACTOR_SCRIPTED       = 7, // This type is not valid
    PED_ATTRACTOR_PARK           = 8, // Ped lays(at day time only, ped goes away after 6 PM)
    PED_ATTRACTOR_STEP           = 9  // Ped sits on steps
};

struct tEffectLight
{
    RwRGBA m_color;
    float m_fCoronaFarClip;
    float m_fPointlightRange;
    float m_fCoronaSize;
    float m_fShadowSize;
    unsigned short m_nFlags;
    unsigned char m_nCoronaFlashType;
    bool m_bCoronaEnableReflection;
    unsigned char m_nCoronaFlareType;
    unsigned char m_nShadowColorMultiplier;
    char m_nShadowZDistance;
    char offsetX;
    char offsetY;
    char offsetZ;
    RwTexture *m_pCoronaTex;
    RwTexture *m_pShadowTex;
};

struct tEffectParticle
{
    char m_szName[24];
};

struct tEffectPedAttractor
{
    RwV3d m_vecQueueDir;
    RwV3d m_vecUseDir;
    RwV3d m_vecForwardDir;
    unsigned char m_nAttractorType; // see ePedAttractorType
    unsigned char m_nPedExistingProbability;
    unsigned char m_nLookAt;
    unsigned char m_nFlags;
    char m_szScriptName[8];
};

struct tEffectEnEx
{
    float m_fEnterAngle;
    RwV2d m_vecSize;
    RwV3d m_vecExitPosn;
    float m_fExitAngle;
    short m_nInteriorId;
    unsigned char m_nFlags1;
    unsigned char m_nSkyColor;
    char m_szInteriorName[8];
    unsigned char m_nTimeOn;
    unsigned char m_nTimeOff;
    unsigned char m_nFlags2;
};

struct tEffectRoadsign
{
    RwV2d m_vecSize;
    float m_afRotation[3];
    union
    {
        unsigned short m_nFlags;
        struct
        {
            unsigned short nNumLines : 2;
            unsigned short nNumLetters : 2;
            unsigned short nPaletteID : 2;
        };
    };
    char *m_pText;
    RpAtomic *m_pAtomic;
};

struct tEffectCoverPoint
{
    RwV2d m_vecDirection;
    unsigned char m_nType;
};

struct tEffectEscalator
{
    RwV3d m_vecBottom;
    RwV3d m_vecTop;
    RwV3d m_vecEnd;
    unsigned char m_nDirection;
};

struct tEffectInterior
{
    unsigned char m_nType;
    char m_nGroup;
    unsigned char m_nWidth;
    unsigned char m_nDepth;
    unsigned char m_nHeight;
    char m_nDoor;
    char m_nLeftDoor[2];
    char m_nRightDoor[2];
    char m_nTDoor[2];
    char m_nLeftWindow[2];
    char m_nRightWindow[2];
    char m_nTWindow[2];
    char m_noGoLeft[3];
    char m_noGoBottom[3];
    char m_noGoWidth[3];
    char m_noGoDepth[3];
    unsigned char m_seed;
    unsigned char m_status;
    float m_rot;
};

struct tEffectTrigger
{
    int m_nIndex;
};

DECL_CLASS(C2dEffect)
    // Member values
    CVector m_vecPosn;
    unsigned int m_nType; // see e2dEffectType
    union
    {
        tEffectLight light;
        tEffectParticle particle;
        tEffectPedAttractor pedAttractor;
        tEffectInterior interior;
        tEffectEnEx enEx;
        tEffectRoadsign roadsign;
        tEffectTrigger trigger;
        tEffectCoverPoint coverPoint;
        tEffectEscalator escalator;
    };
DECL_CLASS_END()
CHECKSIZE(C2dEffect, 0x40, 0x40);

#endif // __AML_PSDK_SA2DEFFECT_H