#ifndef __AML_PSDK_SACORONAS_H
#define __AML_PSDK_SACORONAS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/RGBA.h>

struct CEntity;
struct RwTexture;

enum eCoronaType
{
    CORONATYPE_SHINYSTAR,
    CORONATYPE_HEADLIGHT,
    CORONATYPE_MOON,
    CORONATYPE_REFLECTION,
    CORONATYPE_HEADLIGHTLINE,
    CORONATYPE_HEX,
    CORONATYPE_CIRCLE,
    CORONATYPE_RING,
    CORONATYPE_STREAK,
    CORONATYPE_TORUS,
    CORONATYPE_NONE
};

enum eCoronaFlareType : unsigned char
{
    FLARETYPE_NONE,
    FLARETYPE_SUN,
    FLARETYPE_HEADLIGHTS
};



struct CFlareDefinition
{
    float Position;
    float Size;
    short RedMult;
    short GreenMult;
    short BlueMult;
    short IntensityMult;
    short Sprite;
};

DECL_CLASS(CRegisteredCorona)
    // Member functions
    DECL_THISCALL_SIMPLE(Update, _ZN17CRegisteredCorona6UpdateEv, void);

    // Member values
    CVector          m_vPosn;
    uintptr_t        m_dwId;                    // Should be unique for each corona. Address or something
    RwTexture       *m_pTexture;                // Pointer to the actual texture to be rendered
    float            m_fSize; 
    float            m_fAngle;                  // left from III&VC
    float            m_fFarClip;                // How far away this corona stays visible
    float            m_fNearClip;               // How far away is the z value pulled towards camera.
    float            m_fHeightAboveGround; 
    float            m_fFadeSpeed;              // The speed the corona fades in and out
    CRGBA            m_Color;
    unsigned char    m_nFadeState;              // Intensity that lags behind the given intenisty and fades out if the LOS is blocked
    unsigned char    m_bRegisteredThisFrame;    // Has this corona been registered by game code this frame
    eCoronaFlareType m_nFlareType;
    unsigned char    m_bUsesReflection;    
    unsigned char    m_bCheckObstacles : 1;     // Do we check the LOS or do we render at the right Z value -> bLOSCheck
    unsigned char    m_bOffScreen : 1;          // Set by the rendering code to be used by the update code
    unsigned char    m_bJustCreated;            // If this corona has been created this frame we won't delete it (It hasn't had the time to get its OffScreen cleared)
    unsigned char    m_bFlashWhileFading : 1;   // Does the corona fade out when closer to cam
    unsigned char    m_bOnlyFromBelow : 1;      // This corona is only visible if the camera is below it
    unsigned char    m_bReflectionDelay : 1;    // this corona Has Valid Height Above Ground
    unsigned char    m_bDrawWithWhiteCore : 1;  // This corona rendered with a small white core.
    unsigned char    m_bAttached : 1;           // This corona is attached to an entity.
    CEntity         *m_pAttachedTo;
DECL_CLASS_END()
CHECKSIZE(CRegisteredCorona, 0x3C, 0x50);

DECL_CLASS(CCoronas)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Update, _ZN8CCoronas6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN8CCoronas6RenderEv, void);
    DECL_FASTCALL_SIMPLE(RenderReflections, _ZN8CCoronas17RenderReflectionsEv, void);
    DECL_FASTCALL_SIMPLE(RenderOutGeometryBufferForReflections, _ZN8CCoronas37RenderOutGeometryBufferForReflectionsEv, void);
    DECL_FASTCALL_SIMPLE(RenderSunReflection, _ZN8CCoronas19RenderSunReflectionEv, void);
    DECL_FASTCALL_SIMPLE(Init, _ZN8CCoronas4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN8CCoronas8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(RegisterCorona1, BYBIT(_ZN8CCoronas14RegisterCoronaEjP7CEntityhhhhRK7CVectorffhhhhhfbfbfbb ,_ZN8CCoronas14RegisterCoronaEyP7CEntityhhhhRK7CVectorffhhhhhfbfbfbb), void,
        uintptr_t ID, CEntity *pAttachedToEntity, u8 R, u8 G, u8 B, u8 Intensity, CVector const& Coors, float Size, float Range, eCoronaType CoronaType, eCoronaFlareType FlareType,
        u8 ReflType, u8 LOSCheck, u8 UsesTrails, float fNormalAngle, bool bNeonFade, float ArgPullTowardsCam, bool bFullBrightAtStart, float FadeSpeed, bool bOnlyFromBelow, bool bWhiteCore);
    DECL_FASTCALL_SIMPLE(RegisterCorona2, BYBIT(_ZN8CCoronas14RegisterCoronaEjP7CEntityhhhhRK7CVectorffP9RwTexturehhhhfbfbfbb ,_ZN8CCoronas14RegisterCoronaEyP7CEntityhhhhRK7CVectorffP9RwTexturehhhhfbfbfbb), void,
        uintptr_t ID, CEntity *pAttachedToEntity, u8 R, u8 G, u8 B, u8 Intensity, CVector const& Coors, float Size, float Range, RwTexture *pCoronaTex, eCoronaFlareType FlareType,
        u8 ReflType, u8 LOSCheck, u8 UsesTrails, float fNormalAngle, bool bNeonFade, float ArgPullTowardsCam, bool bFullBrightAtStart, float FadeSpeed, bool bOnlyFromBelow, bool bWhiteCore);
    DECL_FASTCALL_SIMPLE(UpdateCoronaCoors, _ZN8CCoronas17UpdateCoronaCoorsEjRK7CVectorff, void, CVector const& Coors, float Range, float fNormalAngle);
    DECL_FASTCALL_SIMPLE(DoSunAndMoon, _ZN8CCoronas12DoSunAndMoonEv, void);

    // Helper functions
    static inline void RegisterCorona(uintptr_t ID, CEntity *pAttachedToEntity, u8 R, u8 G, u8 B, u8 Intensity, CVector const& Coors, float Size,
        float Range, eCoronaType CoronaType, eCoronaFlareType FlareType, u8 ReflType, u8 LOSCheck, u8 UsesTrails, float fNormalAngle,
        bool bNeonFade, float ArgPullTowardsCam, bool bFullBrightAtStart, float FadeSpeed, bool bOnlyFromBelow, bool bWhiteCore)
    {
        RegisterCorona1(ID, pAttachedToEntity, R, G, B, Intensity, Coors, Size, Range, CoronaType, FlareType, ReflType, LOSCheck,
            UsesTrails, fNormalAngle, bNeonFade, ArgPullTowardsCam, bFullBrightAtStart, FadeSpeed, bOnlyFromBelow, bWhiteCore);
    }
    static inline void RegisterCorona(uintptr_t ID, CEntity *pAttachedToEntity, u8 R, u8 G, u8 B, u8 Intensity, CVector const& Coors, float Size,
        float Range, RwTexture *pCoronaTex, eCoronaFlareType FlareType, u8 ReflType, u8 LOSCheck, u8 UsesTrails, float fNormalAngle,
        bool bNeonFade, float ArgPullTowardsCam, bool bFullBrightAtStart, float FadeSpeed, bool bOnlyFromBelow, bool bWhiteCore)
    {
        RegisterCorona2(ID, pAttachedToEntity, R, G, B, Intensity, Coors, Size, Range, pCoronaTex, FlareType, ReflType, LOSCheck,
            UsesTrails, fNormalAngle, bNeonFade, ArgPullTowardsCam, bFullBrightAtStart, FadeSpeed, bOnlyFromBelow, bWhiteCore);
    }

    // STATIC values
    DECL_VALUE_PLT_FLT(LightsMult, BYBIT(0x678B94, 0x84F750) );
    DECL_VALUE_PLT_FLT(ScreenMult, BYBIT(0x6786A8, 0x84ED78) );
    DECL_VALUE_PLT_U32(MoonSize, BYBIT(0x675F78, 0x849F60) );
    DECL_VALUE_PLT_FLT(SunScreenX, BYBIT(0x679A84, 0x851528) );
    DECL_VALUE_PLT_FLT(SunScreenY, BYBIT(0x67978C, 0x850F20) );
    DECL_VALUE_PLT_BOOL(SunBlockedByClouds, BYBIT(0x679F44, 0x851E90) );
    DECL_VALUE_PLT_I32(bChangeBrightnessImmediately, BYBIT(0x6787FC, 0x84F020) );
    DECL_VALUE_PLT_I32(NumCoronas, BYBIT(0x676890, 0x84B178) );
    DECL_OBJECT_ARRAY_PLT(CRegisteredCorona, aCoronas, BYBIT(0x676C44, 0x84B8D0) );
DECL_CLASS_END()

DECL_OBJECT_ARRAY_PLT_GLOBAL(RwTexture*, gpCoronaTexture, BYBIT(0x679F7C, 0x851F08) );
DECL_OBJECT_ARRAY_PLT_GLOBAL(CFlareDefinition, SunFlareDef, BYBIT(0x676920, 0x84B290) );
DECL_OBJECT_ARRAY_PLT_GLOBAL(CFlareDefinition, HeadLightsFlareDef, BYBIT(0x6794C8, 0x8509A8) );

#define LightsMult LightsMult()
#define ScreenMult ScreenMult()
#define MoonSize MoonSize()
#define SunScreenX SunScreenX()
#define SunScreenY SunScreenY()
#define SunBlockedByClouds SunBlockedByClouds()
#define bChangeBrightnessImmediately bChangeBrightnessImmediately()
#define NumCoronas NumCoronas()
#define aCoronas aCoronas()
#define gpCoronaTexture gpCoronaTexture()
#define SunFlareDef SunFlareDef()
#define HeadLightsFlareDef HeadLightsFlareDef()

#endif // __AML_PSDK_SACORONAS_H