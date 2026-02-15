#ifndef __AML_PSDK_SASHADOWS_H
#define __AML_PSDK_SASHADOWS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct RwTexture;
struct CRealTimeShadow;
struct CVehicle;
struct CPhysical;

enum eShadowType
{
    SHADOW_DEFAULT = 1,
    SHADOW_ADDITIVE = 2,
    SHADOW_INVCOLOR = 3,
    SHADOW_OIL_1 = 4,
    SHADOW_OIL_2 = 5,
    SHADOW_OIL_3 = 6,
    SHADOW_OIL_4 = 7,
    SHADOW_OIL_5 = 8
};

enum eShadowTextureType
{
    SHADOWTEX_CAR = 1,
    SHADOWTEX_PED = 2,
    SHADOWTEX_EXPLOSION = 3,
    SHADOWTEX_HELI = 4,
    SHADOWTEX_HEADLIGHTS = 5,
    SHADOWTEX_BLOOD = 6
};

enum VEH_SHD_TYPE
{
    VEH_SHD_CAR = 0,
    VEH_SHD_BIKE = 1,
    VEH_SHD_HELI = 2,
    VEH_SHD_PLANE = 3,
    VEH_SHD_RC = 4,
    VEH_SHD_BIG_PLANE = 5 // AT400; ANDROM
};

struct CPolyBunch
{
    CVector             m_avecPosn[7];
    CPolyBunch         *m_pNext;
    unsigned short      m_wNumVerts;
    char                m_aU[7];
    char                m_aV[7];
};

struct CRegisteredShadow
{
    CVector             m_vecPosn;
    float               m_fFrontX;
    float               m_fFrontY;
    float               m_fSideX;
    float               m_fSideY;
    float               m_fZDistance;
    float               m_fScale;
    RwTexture          *m_pTexture;
    CRealTimeShadow    *m_pRTShadow;
    unsigned short      m_nIntensity;
    unsigned char       m_nType;
    unsigned char       m_nRed;
    unsigned char       m_nGreen;
    unsigned char       m_nBlue;
    struct
    {
        unsigned char   bDrawOnWater : 1;
        unsigned char   bIgnoreMapObjects : 1;
        unsigned char   bDrawOnBuildings : 1;
    } m_nFlags;
};
CHECKSIZE(CRegisteredShadow, 0x34, 0x40);

struct CPermanentShadow
{
    CVector             m_vecPosn;
    float               m_fFrontX;
    float               m_fFrontY;
    float               m_fSideX;
    float               m_fSideY;
    float               m_fZDistance;
    float               m_fScale;
    unsigned int        m_nTimeCreated;
    unsigned int        m_nTimeDuration;
    RwTexture          *m_pTexture;
    unsigned short      m_nIntensity;
    unsigned char       m_nType;
    unsigned char       m_nRed;
    unsigned char       m_nGreen;
    unsigned char       m_nBlue;
    struct
    {
        unsigned char   bDrawOnWater : 1;
        unsigned char   bIgnoreMapObjects : 1;
        unsigned char   bDrawOnBuildings : 1;
    } m_nFlags;
};
CHECKSIZE(CPermanentShadow, 0x38, 0x40);

DECL_CLASS(CStaticShadow)
    // Member functions
    DECL_THISCALL_SIMPLE(Free, _ZN13CStaticShadow4FreeEv, void);

    // Member values
    uintptr_t       m_nId;
    CPolyBunch     *m_pPolyBunch;
    unsigned int    m_nTimeCreated;
    CVector         m_vecPosn;
    float           m_fFrontX;
    float           m_fFrontY;
    float           m_fSideX;
    float           m_fSideY;
    float           m_fZDistance;
    float           m_fScale;
    RwTexture      *m_pTexture;
    unsigned short  m_nIntensity;
    unsigned char   m_nType;
    unsigned char   m_nRed;
    unsigned char   m_nGreen;
    unsigned char   m_nBlue;
    char            m_bJustCreated;
    char            m_bRendered;
    char            m_bTemporaryShadow; // delete after 5000ms
    union {
        struct {
            unsigned char m_nDayIntensity : 4;
            unsigned char m_nNightIntensity : 4;
        };
        unsigned char m_nDayNightIntensity;
    };
DECL_CLASS_END()
CHECKSIZE(CStaticShadow, 0x40, 0x50);



DECL_CLASS(CShadows)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN8CShadows4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN8CShadows8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(AddPermanentShadow, _ZN8CShadows18AddPermanentShadowEhP9RwTextureP7CVectorffffshhhfjf, void,
        u8 Type, RwTexture *pTexture, CVector *pCoors, float ForwardX, float ForwardY, float SideX, float SideY, i16 Brightness, u8 Red, u8 Green, u8 Blue, float ShadowDepth, u32 Duration, float TextureScale);
    DECL_FASTCALL_SIMPLE(StoreStaticShadow, BYBIT(_ZN8CShadows17StoreStaticShadowEjhP9RwTextureP7CVectorffffshhhfffbf, _ZN8CShadows17StoreStaticShadowEyhP9RwTextureP7CVectorffffshhhfffbf), bool,
        uintptr_t ID, u8 Type, RwTexture *pTexture, CVector *pCoors, float ForwardX, float ForwardY, float SideX, float SideY, i16 Brightness,
        u8 Red, u8 Green, u8 Blue, float ShadowDepth, float TextureScale, float MaxDist, bool bFromTree, float Margin);
    DECL_FASTCALL_SIMPLE(GeneratePolysForStaticShadow, _ZN8CShadows28GeneratePolysForStaticShadowEs, void, i16 ShadowNum);
    DECL_FASTCALL_SIMPLE(StoreShadowToBeRendered1, _ZN8CShadows23StoreShadowToBeRenderedEhP7CVectorffffshhh, void,
        u8 Type, CVector *pCoors, float ForwardX, float ForwardY, float SideX, float SideY, i16 Brightness, u8 Red, u8 Green, u8 Blue);
    DECL_FASTCALL_SIMPLE(StoreShadowToBeRendered2, _ZN8CShadows23StoreShadowToBeRenderedEhP9RwTextureP7CVectorffffshhhfbfP15CRealTimeShadowb, void,
        u8 Type, RwTexture *pTexture, CVector *pCoors, float ForwardX, float ForwardY, float SideX, float SideY, i16 Brightness,
        u8 Red, u8 Green, u8 Blue, float ShadowDepth, bool OnWater, float TextureScale, CRealTimeShadow *pRealTimeShadow, bool bIsPlayer);
    DECL_FASTCALL_SIMPLE(StoreShadowForVehicle, _ZN8CShadows21StoreShadowForVehicleEP8CVehicle12VEH_SHD_TYPE, void, CVehicle *pVehicle, VEH_SHD_TYPE VehicleShadowType);
    DECL_FASTCALL_SIMPLE(StoreCarLightShadow, _ZN8CShadows19StoreCarLightShadowEP8CVehicleiP9RwTextureP7CVectorffffhhhf, void,
        CVehicle *pCar, i32 ID, RwTexture *pTexture, CVector *pShadowPos, float ForwardX, float ForwardY, float SideX, float SideY, u8 Red, u8 Green, u8 Blue, float Radius);
    DECL_FASTCALL_SIMPLE(StoreShadowForPedObject, _ZN8CShadows23StoreShadowForPedObjectEP7CEntityffffff, void,
        CEntity *pPed, float ShadowDisplacementX, float ShadowDisplacementY, float ShadowFrontX, float ShadowFrontY, float ShadowSideX, float ShadowSideY);
    DECL_FASTCALL_SIMPLE(StoreRealTimeShadow, _ZN8CShadows19StoreRealTimeShadowEP9CPhysicalffffff, bool,
        CPhysical *pPhysical, float ShadowDisplacementX, float ShadowDisplacementY, float ShadowFrontX, float ShadowFrontY, float ShadowSideX, float ShadowSideY);
    DECL_FASTCALL_SIMPLE(CalcPedShadowValues, _ZN8CShadows19CalcPedShadowValuesE7CVectorPfS1_S1_S1_S1_S1_, void,
        CVector UnitVecToLight, float *pShadowFrontX, float *pShadowFrontY, float *pShadowSideX, float *pShadowSideY, float *pShadowDisplacementX, float *pShadowDisplacementY);
    DECL_FASTCALL_SIMPLE(StoreShadowForTree, _ZN8CShadows18StoreShadowForTreeEP7CEntity, void); // NOP
    DECL_FASTCALL_SIMPLE(StoreShadowForPole, _ZN8CShadows18StoreShadowForPoleEP7CEntityfffffj, void,
        CEntity *pPole, float OffsetX, float OffsetY, float ShiftUp, float Length, float Width, u32 Number);
    DECL_FASTCALL_SIMPLE(SetRenderModeForShadowType, _ZN8CShadows26SetRenderModeForShadowTypeEh, void, u8 ShadowType);
    DECL_FASTCALL_SIMPLE(RenderStoredShadows, _ZN8CShadows19RenderStoredShadowsEb, void, bool renderAdditive);
    DECL_FASTCALL_SIMPLE(CastRealTimeShadowSectorList, _ZN8CShadows28CastRealTimeShadowSectorListER8CPtrListffffP7CVectorffffshhhffPP10CPolyBunchP15CRealTimeShadowPh, void,
        CPtrList &list, float XMin, float YMin, float XMax, float YMax, CVector *pShadowPos, float ForwardX, float ForwardY, float SideX, float SideY, i16 Brightness,
        u8 Red, u8 Green, u8 Blue, float ShadowDepth, float TextureScale, CPolyBunch **ppBunch, CRealTimeShadow *pRealTimeShadow, u8 *lightingMult);
    DECL_FASTCALL_SIMPLE(CastPlayerShadowSectorList, _ZN8CShadows26CastPlayerShadowSectorListER8CPtrListffffP7CVectorffffshhhffPP10CPolyBunchPhi, void,
        CPtrList &list, float XMin, float YMin, float XMax, float YMax, CVector *pShadowPos, float ForwardX, float ForwardY, float SideX, float SideY, i16 Brightness,
        u8 Red, u8 Green, u8 Blue, float ShadowDepth, float TextureScale, CPolyBunch **ppBunch, u8 *lightingMult, i32 ShadowType);
    DECL_FASTCALL_SIMPLE(CastShadowSectorList, _ZN8CShadows20CastShadowSectorListER8CPtrListffffP7CVectorffffshhhffPP10CPolyBunchPhi, void,
        CPtrList &list, float XMin, float YMin, float XMax, float YMax, CVector *pShadowPos, float ForwardX, float ForwardY, float SideX, float SideY, i16 Brightness,
        u8 Red, u8 Green, u8 Blue, float ShadowDepth, float TextureScale, CPolyBunch **ppBunch, u8 *lightingMult, i32 ShadowType);
    DECL_FASTCALL_SIMPLE(RenderStaticShadows, _ZN8CShadows19RenderStaticShadowsEb, void, bool renderAdditive);
    DECL_FASTCALL_SIMPLE(AffectColourWithLighting, _ZN8CShadows24AffectColourWithLightingEhhhhhPhS0_S0_, void,
        u8 shadowType, u8 lightingMult, u8 origR, u8 origG, u8 origB, u8 *r, u8 *g, u8 *b);
    DECL_FASTCALL_SIMPLE(CastShadowEntityXY, _ZN8CShadows18CastShadowEntityXYEP7CEntityffffP7CVectorffffshhhffPP10CPolyBunchPhi, void,
        CEntity *pEntity, float XMin, float YMin, float XMax, float YMax, CVector *pShadowPos, float ForwardX, float ForwardY, float SideX, float SideY, i16 Brightness,
        u8 Red, u8 Green, u8 Blue, float ShadowDepth, float TextureScale, CPolyBunch **ppBunch, u8 *lightingMult, i32 ShadowType);
    DECL_FASTCALL_SIMPLE(UpdateStaticShadows, _ZN8CShadows19UpdateStaticShadowsEv, void);
    DECL_FASTCALL_SIMPLE(UpdatePermanentShadows, _ZN8CShadows22UpdatePermanentShadowsEv, void);
    DECL_FASTCALL_SIMPLE(RemoveOilInArea, _ZN8CShadows15RemoveOilInAreaEffff, void, float MinX, float MaxX, float MinY, float MaxY);
    DECL_FASTCALL_SIMPLE(GunShotSetsOilOnFire, _ZN8CShadows20GunShotSetsOilOnFireEPK7CVectorS2_, void, CVector const *pShotStart, CVector const *pShotEnd);
    DECL_FASTCALL_SIMPLE(PrintDebugPoly, _ZN8CShadows14PrintDebugPolyEP7CVectorS1_S1_, void); // NOP
    DECL_FASTCALL_SIMPLE(RenderExtraPlayerShadows, _ZN8CShadows24RenderExtraPlayerShadowsEv, void);
    DECL_FASTCALL_SIMPLE(TidyUpShadows, _ZN8CShadows13TidyUpShadowsEv, void);
    DECL_FASTCALL_SIMPLE(RenderIndicatorShadow, BYBIT(_ZN8CShadows21RenderIndicatorShadowEjhP9RwTextureP7CVectorffffs, _ZN8CShadows21RenderIndicatorShadowEyhP9RwTextureP7CVectorffffs), void,
        uintptr_t ID, u8 Type, RwTexture *pTexture, CVector *pCoors, float ForwardX, float ForwardY, float SideX, float SideY, i16 Brightness);
    DECL_FASTCALL_SIMPLE_PLT(CastShadowEntityXYZ, BYBIT(0x5BE010 + 1, 0x6E26E4), void,
        CEntity *pEntity, CVector *pShadowPos, float ForwardX, float ForwardY, float SideX, float SideY, i16 Brightness,
        u8 Red, u8 Green, u8 Blue, float ShadowDepth, float TextureScale, CPolyBunch **ppBunch, CRealTimeShadow *pRealTimeShadow, u8 *lightingMult);

    // Helper functions
    static inline void StoreShadowToBeRendered(u8 Type, CVector *pCoors, float ForwardX, float ForwardY, float SideX, float SideY, i16 Brightness, u8 Red, u8 Green, u8 Blue)
    {
        StoreShadowToBeRendered1(Type, pCoors, ForwardX, ForwardY, SideX, SideY, Brightness, Red, Green, Blue);
    }
    static inline void StoreShadowToBeRendered(u8 Type, RwTexture *pTexture, CVector *pCoors, float ForwardX, float ForwardY, float SideX, float SideY, i16 Brightness,
        u8 Red, u8 Green, u8 Blue, float ShadowDepth, bool OnWater, float TextureScale, CRealTimeShadow *pRealTimeShadow, bool bIsPlayer)
    {
        StoreShadowToBeRendered2(Type, pTexture, pCoors, ForwardX, ForwardY, SideX, SideY, Brightness, Red, Green, Blue, ShadowDepth, OnWater, TextureScale, pRealTimeShadow, bIsPlayer);
    }

    // STATIC members
    DECL_VALUE_PLT_U16(ShadowsStoredToBeRendered, BYBIT(0x679918, 0x851250));
    DECL_OBJECT_ARRAY_PLT(CRegisteredShadow, asShadowsStored, BYBIT(0x677BEC, 0x84D7F8));
    DECL_OBJECT_ARRAY_PLT(CPolyBunch, aPolyBunches, BYBIT(0x678F8C, 0x84FF40));
    DECL_OBJECT_ARRAY_PLT(CStaticShadow, aStaticShadows, BYBIT(0x6798EC, 0x8511F8));
    DECL_OBJECT_PLT(CPolyBunch*, pEmptyBunchList, BYBIT(0x676F44, 0x84BEC8));
    DECL_OBJECT_ARRAY_PLT(CPermanentShadow, aPermanentShadows, BYBIT(0x679FE4, 0x851FD8));
DECL_CLASS_END()

#define ShadowsStoredToBeRendered ShadowsStoredToBeRendered()
#define asShadowsStored asShadowsStored()
#define aPolyBunches aPolyBunches()
#define aStaticShadows aStaticShadows()
#define pEmptyBunchList pEmptyBunchList()
#define aPermanentShadows aPermanentShadows()

#endif // __AML_PSDK_SASHADOWS_H