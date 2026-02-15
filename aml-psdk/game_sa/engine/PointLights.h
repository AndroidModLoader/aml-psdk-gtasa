#ifndef __AML_PSDK_SAPOINTLIGHTS_H
#define __AML_PSDK_SAPOINTLIGHTS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;

enum ePointLightType : unsigned char
{
    PLTYPE_POINTLIGHT = 0,
    PLTYPE_SPOTLIGHT = 1,
    PLTYPE_DARKLIGHT = 2,
};

struct CPointLight
{
    CVector          m_vecPosn;
    CVector          m_vecDirection;
    float            m_fRange;
    float            m_fColorRed;
    float            m_fColorGreen;
    float            m_fColorBlue;
    CEntity         *m_pEntityToLight;
    ePointLightType  m_nType;
    unsigned char    m_nFogType;
    bool             m_bGenerateShadows;
};
CHECKSIZE(CPointLight, 0x30, 0x38);



DECL_CLASS(CPointLights)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN12CPointLights4InitEv, void);
    DECL_FASTCALL_SIMPLE(AddLight, _ZN12CPointLights8AddLightEh7CVectorS0_ffffhbP7CEntity, void,
        u8 Type, CVector Coors, CVector Dir, float Range, float Red, float Green, float Blue, u8 FogEffect, bool bCastsShadowFromPlayerCarAndPed, CEntity *pArgCastingEntity);
    DECL_FASTCALL_SIMPLE(GenerateLightsAffectingObject, _ZN12CPointLights29GenerateLightsAffectingObjectEPK7CVectorPfP7CEntity, float,
        CVector const* pCoors, float *pPointLightsTotal, CEntity *pEntity);
    DECL_FASTCALL_SIMPLE(GetLightMultiplier, _ZN12CPointLights18GetLightMultiplierEPK7CVector, float, CVector const* pCoors);
    DECL_FASTCALL_SIMPLE(RemoveLightsAffectingObject, _ZN12CPointLights27RemoveLightsAffectingObjectEv, void);
    DECL_FASTCALL_SIMPLE(RenderFogEffect, _ZN12CPointLights15RenderFogEffectEv, void);
    DECL_FASTCALL_SIMPLE(ProcessVerticalLineUsingCache, _ZN12CPointLights29ProcessVerticalLineUsingCacheE7CVectorPf, bool, CVector Coors, float *pResult);

    // STATIC members
    DECL_VALUE_PLT_I32(NumLights, BYBIT(0x6770C8, 0x84C1C8));
    DECL_OBJECT_ARRAY_PLT(CPointLight, aLights, BYBIT(0x676FF8, 0x84C028));
DECL_CLASS_END()

#define NumLights NumLights()
#define aLights aLights()

#endif // __AML_PSDK_SAPOINTLIGHTS_H