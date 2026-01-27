#ifndef __AML_PSDK_SARADAR_H
#define __AML_PSDK_SARADAR_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/RGBA.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/Rect.h>

struct CEntryExit;
struct CSprite2d;

enum eBlipAppearance
{
    BLIP_FLAG_FRIEND = 0, // It selects BLIP_COLOUR_BLUE. If unset toghether with BLIP_FLAG_THREAT, any color.
    BLIP_FLAG_THREAT  // It selects BLIP_COLOUR_RED. If unset toghether with BLIP_FLAG_FRIEND, any color.
};

enum eBlipType
{
    BLIP_NONE = 0,       // 0
    BLIP_CAR,           // 1
    BLIP_CHAR,          // 2
    BLIP_OBJECT,        // 3
    BLIP_COORD,         // 4 - Checkpoint.
    BLIP_CONTACTPOINT,  // 5 - Sphere.
    BLIP_SPOTLIGHT,     // 6
    BLIP_PICKUP,        // 7
    BLIP_AIRSTRIP       // 8
};

enum eBlipDisplay
{
    BLIP_DISPLAY_NEITHER = 0,// 0
    BLIP_DISPLAY_MARKER_ONLY, // 1
    BLIP_DISPLAY_BLIP_ONLY,   // 2
    BLIP_DISPLAY_BOTH        // 3
};

enum eBlipColour
{
    BLIP_COLOUR_RED = 0,    // 0
    BLIP_COLOUR_GREEN,      // 1
    BLIP_COLOUR_BLUE,       // 2
    BLIP_COLOUR_WHITE,      // 3
    BLIP_COLOUR_YELLOW,     // 4
    BLIP_COLOUR_REDCOPY,    // 5 - What? It was BLIP_COLOUR_PURPLE.
    BLIP_COLOUR_BLUECOPY,   // 6 - Why? It was BLIP_COLOUR_CYAN.
    BLIP_COLOUR_THREAT,     // 7 - If BLIP_FLAG_FRIENDLY is not set (by default) it is BLIP_COLOUR_RED, else BLIP_COLOUR_BLUE.
    BLIP_COLOUR_DESTINATION // 8 - Default color.
};

enum eRadarSprite
{
    RADAR_SPRITE_NONE = 0,      // 0
    RADAR_SPRITE_WHITE,         // 1
    RADAR_SPRITE_CENTRE,        // 2
    RADAR_SPRITE_MAP_HERE,      // 3
    RADAR_SPRITE_NORTH,         // 4
    RADAR_SPRITE_AIRYARD,       // 5
    RADAR_SPRITE_AMMUGUN,       // 6
    RADAR_SPRITE_BARBERS,       // 7
    RADAR_SPRITE_BIGSMOKE,      // 8
    RADAR_SPRITE_BOATYARD,      // 9
    RADAR_SPRITE_BURGERSHOT,    // 10
    RADAR_SPRITE_BULLDOZER,     // 11
    RADAR_SPRITE_CATALINAPINK,  // 12
    RADAR_SPRITE_CESARVIAPANDO, // 13 - What? R* mistype?
    RADAR_SPRITE_CHICKEN,       // 14
    RADAR_SPRITE_CJ,            // 15
    RADAR_SPRITE_CRASH1,        // 16
    RADAR_SPRITE_DINER,         // 17 - Yet another one?
    RADAR_SPRITE_EMMETGUN,      // 18
    RADAR_SPRITE_ENEMYATTACK,   // 19
    RADAR_SPRITE_FIRE,          // 20
    RADAR_SPRITE_GIRLFRIEND,    // 21
    RADAR_SPRITE_HOSTPITAL,     // 22 - Again?
    RADAR_SPRITE_LOGOSYNDICATE, // 23
    RADAR_SPRITE_MADDOG,        // 24
    RADAR_SPRITE_MAFIACASINO,   // 25
    RADAR_SPRITE_MCSTRAP,       // 26
    RADAR_SPRITE_MODGARAGE,     // 27
    RADAR_SPRITE_OGLOC,         // 28
    RADAR_SPRITE_PIZZA,         // 29
    RADAR_SPRITE_POLICE,        // 30
    RADAR_SPRITE_PROPERTYG,     // 31
    RADAR_SPRITE_PROPERTYR,     // 32
    RADAR_SPRITE_RACE,          // 33
    RADAR_SPRITE_RYDER,         // 34
    RADAR_SPRITE_SAVEGAME,      // 35
    RADAR_SPRITE_SCHOOL,        // 36
    RADAR_SPRITE_QMARK,         // 37
    RADAR_SPRITE_SWEET,         // 38
    RADAR_SPRITE_TATTOO,        // 39
    RADAR_SPRITE_THETRUTH,      // 40
    RADAR_SPRITE_WAYPOINT,      // 41
    RADAR_SPRITE_TORENORANCH,   // 42
    RADAR_SPRITE_TRIADS,        // 43
    RADAR_SPRITE_TRIADSCASINO,  // 44
    RADAR_SPRITE_TSHIRT,        // 45
    RADAR_SPRITE_WOOZIE,        // 46
    RADAR_SPRITE_ZERO,          // 47
    RADAR_SPRITE_DATEDISCO,     // 48
    RADAR_SPRITE_DATEDRINK,     // 49
    RADAR_SPRITE_DATEFOOD,      // 50
    RADAR_SPRITE_TRUCK,         // 51
    RADAR_SPRITE_CASH,          // 52
    RADAR_SPRITE_FLAG,          // 53
    RADAR_SPRITE_GYM,           // 54
    RADAR_SPRITE_IMPOUND,       // 55
    RADAR_SPRITE_LIGHT,         // 56
    RADAR_SPRITE_RUNWAY,        // 57
    RADAR_SPRITE_GANGB,         // 58
    RADAR_SPRITE_GANGP,         // 59
    RADAR_SPRITE_GANGY,         // 60
    RADAR_SPRITE_GANGN,         // 61
    RADAR_SPRITE_GANGG,         // 62
    RADAR_SPRITE_SPRAY,          // 63
    RADAR_SPRITE_COUNT,
};

enum eRadarTraceHeight
{
    RADAR_TRACE_LOW = 0,
    RADAR_TRACE_HIGH,
    RADAR_TRACE_NORMAL
};

struct tBlipHandle
{
    unsigned short arrayIndex;
    unsigned short number;
};
struct airstrip_info
{
    float x;
    float y;
    float direction; // angle
    float radius; // length
};
struct tRadarTrace
{
    unsigned int   m_nColour; // see eBlipColour
    unsigned int   m_nEntityHandle;
    CVector        m_vecPos;
    unsigned short m_nCounter;
    float          m_fSphereRadius;
    unsigned short m_nBlipSize;
    CEntryExit       *m_pEntryExit;
    unsigned char  m_nRadarSprite; // see eRadarSprite
    unsigned char  m_bBright : 1; // It makes use of bright colors. Always set.
    unsigned char  m_bInUse : 1; // It is available.
    unsigned char  m_bShortRange : 1; // It doesn't show permanently on the radar.
    unsigned char  m_bFriendly : 1; // It is affected by BLIP_COLOUR_THREAT.   
    unsigned char  m_bBlipRemain : 1; // It has the priority over the entity (it will still appear after the entity's deletion).
    unsigned char  m_bBlipFade : 1; // Possibly a leftover. Always unset (unused).
    unsigned char  m_nCoordBlipAppearance : 2; // see eBlipAppearance
    unsigned char  m_nBlipDisplay : 2; // see eBlipDisplay
    unsigned char  m_nBlipType : 4; // see eBlipType
};
CHECKSIZE(tRadarTrace, 0x28, 0x30);

DECL_CLASS(CRadar)
    // Functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN6CRadar10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(ClearActualBlip, _ZN6CRadar15ClearActualBlipEi, void, int idx);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN6CRadar8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(RemoveRadarSections, _ZN6CRadar19RemoveRadarSectionsEv, void);
    DECL_FASTCALL_SIMPLE(LoadTextures, _ZN6CRadar12LoadTexturesEv, void);
    DECL_FASTCALL_SIMPLE(GetNewUniqueBlipIndex, _ZN6CRadar21GetNewUniqueBlipIndexEi, int, int arrayIdx);
    DECL_FASTCALL_SIMPLE(GetActualBlipArrayIndex, _ZN6CRadar23GetActualBlipArrayIndexEi, int, int idx);
    DECL_FASTCALL_SIMPLE(DrawMap, _ZN6CRadar7DrawMapEv, void);
    DECL_FASTCALL_SIMPLE(CalculateCachedSinCos, _ZN6CRadar21CalculateCachedSinCosEv, void);
    DECL_FASTCALL_SIMPLE(DrawRadarMap, _ZN6CRadar12DrawRadarMapEv, void);
    DECL_FASTCALL_SIMPLE(InitFrontEndMap, _ZN6CRadar15InitFrontEndMapEv, void);
    DECL_FASTCALL_SIMPLE(DrawBlips, _ZN6CRadar9DrawBlipsEf, void, float circleSize);
    DECL_FASTCALL_SIMPLE(SetupAirstripBlips, _ZN6CRadar18SetupAirstripBlipsEv, void);
    DECL_FASTCALL_SIMPLE(TransformRadarPointToScreenSpace, _ZN6CRadar32TransformRadarPointToScreenSpaceER9CVector2DRKS0_, void, CVector2D& screen, CVector2D const &radar);
    DECL_FASTCALL_SIMPLE(TransformRealWorldPointToRadarSpace, _ZN6CRadar35TransformRealWorldPointToRadarSpaceER9CVector2DRKS0_, void, CVector2D& radar, CVector const &world);
    DECL_FASTCALL_SIMPLE(LimitRadarPoint, _ZN6CRadar15LimitRadarPointER9CVector2D, void, CVector2D& radar);
    DECL_FASTCALL_SIMPLE(DrawRadarSprite, _ZN6CRadar15DrawRadarSpriteEtffh, void, u16 id, float x, float y, u8 alpha);
    DECL_FASTCALL_SIMPLE(DisplayThisBlip, _ZN6CRadar15DisplayThisBlipEia, u8, i32 idx, u8 alpha);
    DECL_FASTCALL_SIMPLE(DrawCoordBlip, _ZN6CRadar13DrawCoordBlipEihif, void, i32 idx, u8 sprite, u8 alpha, float circleSize);
    DECL_FASTCALL_SIMPLE(DrawEntityBlip, _ZN6CRadar14DrawEntityBlipEihif, void, i32 idx, u8 sprite, u8 alpha, float circleSize);
    DECL_FASTCALL_SIMPLE(DrawYouAreHereSprite, _ZN6CRadar20DrawYouAreHereSpriteEff, void, float x, float y);
    DECL_FASTCALL_SIMPLE(DrawRotatingRadarSprite, _ZN6CRadar23DrawRotatingRadarSpriteEP9CSprite2dfffff5CRGBA, void, CSprite2d* sprite, float x, float y, float angle, float scale, CRGBA& color);
    DECL_FASTCALL_SIMPLE(GetRadarTraceColour, _ZN6CRadar19GetRadarTraceColourEjhh, u32, u32 colorIdx, u8 bBrightness, u8 bFriend);
    DECL_FASTCALL_SIMPLE(ShowRadarMarker, _ZN6CRadar15ShowRadarMarkerE7CVectorjf, void, CVector pos, u32 color, float scale);
    DECL_FASTCALL_SIMPLE(CalculateBlipAlpha, _ZN6CRadar18CalculateBlipAlphaEf, u8, float alphaMult);
    DECL_FASTCALL_SIMPLE(HasThisBlipBeenRevealed, _ZN6CRadar23HasThisBlipBeenRevealedEi, u8, int idx);
    DECL_FASTCALL_SIMPLE(ShowRadarTraceWithHeight, _ZN6CRadar24ShowRadarTraceWithHeightEffjhhhhh, void, float x, float y, u32 size, u8 r, u8 g, u8 b, u8 a, u8 type); // eRadarTracdeHeight
    DECL_FASTCALL_SIMPLE(AddBlipToLegendList, _ZN6CRadar19AddBlipToLegendListEhi, void, u8 arrowBlip, i32 blipIdx);
    DECL_FASTCALL_SIMPLE(DrawLegend, _ZN6CRadar10DrawLegendEiii, void, int x, int y, int legendListNum);
    DECL_FASTCALL_SIMPLE(SetMapCentreToPlayerCoords, _ZN6CRadar26SetMapCentreToPlayerCoordsEv, void);
    DECL_FASTCALL_SIMPLE(Draw3dMarkers, _ZN6CRadar13Draw3dMarkersEv, void);
    DECL_FASTCALL_SIMPLE(LimitToMap, _ZN6CRadar10LimitToMapEPfS0_, void, float* x, float* y);
    DECL_FASTCALL_SIMPLE(TransformScreenSpaceToRadarPoint, _ZN6CRadar32TransformScreenSpaceToRadarPointER9CVector2DS1_, void, CVector2D& screen, CVector2D& radar);
    DECL_FASTCALL_SIMPLE(TransformRadarPointToRealWorldSpace, _ZN6CRadar35TransformRadarPointToRealWorldSpaceER9CVector2DRKS0_, void, CVector2D& world, CVector2D& radar);
    DECL_FASTCALL_SIMPLE(TransformRealWorldToTexCoordSpace, _ZN6CRadar33TransformRealWorldToTexCoordSpaceER9CVector2DRKS0_ii, void, CVector2D& texCoord, CVector2D const& world, int x, int y);
    DECL_FASTCALL_SIMPLE(SetCoordBlip, _ZN6CRadar12SetCoordBlipE9eBlipType7CVectorj12eBlipDisplayPc, i32, eBlipType type, CVector pos, u32 color, eBlipDisplay displaytype, const char* unused);
    DECL_FASTCALL_SIMPLE(SetShortRangeCoordBlip, _ZN6CRadar22SetShortRangeCoordBlipE9eBlipType7CVectorj12eBlipDisplayPc, i32, eBlipType type, CVector pos, u32 color, eBlipDisplay displaytype, const char* unused);
    DECL_FASTCALL_SIMPLE(SetEntityBlip, _ZN6CRadar13SetEntityBlipE9eBlipTypeij12eBlipDisplayPc, i32, eBlipType type, i32 poolIdx, u32 color, eBlipDisplay displaytype, const char* unused);
    DECL_FASTCALL_SIMPLE(ClearBlipForEntity, _ZN6CRadar18ClearBlipForEntityE9eBlipTypei, void, eBlipType type, i32 poolIdx);
    DECL_FASTCALL_SIMPLE(ClearBlip, _ZN6CRadar9ClearBlipEi, void, i32 idx);
    DECL_FASTCALL_SIMPLE(ChangeBlipColour, _ZN6CRadar16ChangeBlipColourEij, void, i32 idx, u32 color);
    DECL_FASTCALL_SIMPLE(ChangeBlipBrightness, _ZN6CRadar20ChangeBlipBrightnessEii, void, i32 idx, i32 onoff);
    DECL_FASTCALL_SIMPLE(ChangeBlipScale, _ZN6CRadar15ChangeBlipScaleEii, void, i32 idx, i32 scale);
    DECL_FASTCALL_SIMPLE(ChangeBlipDisplay, _ZN6CRadar17ChangeBlipDisplayEi12eBlipDisplay, void, i32 idx, eBlipDisplay displaytype);
    DECL_FASTCALL_SIMPLE(SetBlipSprite, _ZN6CRadar13SetBlipSpriteEii, void, i32 idx, i32 sprite);
    DECL_FASTCALL_SIMPLE(SetBlipAlwaysDisplayInZoom, _ZN6CRadar26SetBlipAlwaysDisplayInZoomEih, void, i32 idx, u8 alwaysDisplay);
    DECL_FASTCALL_SIMPLE(SetBlipFade, _ZN6CRadar11SetBlipFadeEih, void, i32 idx, u8 fade);
    DECL_FASTCALL_SIMPLE(SetCoordBlipAppearance, _ZN6CRadar22SetCoordBlipAppearanceEih, void, i32 idx, u8 appearance);
    DECL_FASTCALL_SIMPLE(SetBlipFriendly, _ZN6CRadar15SetBlipFriendlyEih, void, i32 idx, u8 friendly);
    DECL_FASTCALL_SIMPLE(SetBlipEntryExit, _ZN6CRadar16SetBlipEntryExitEiP10CEntryExit, void, i32 idx, CEntryExit* pEntryExit);
    DECL_FASTCALL_SIMPLE(ShowRadarTrace, _ZN6CRadar14ShowRadarTraceEffjhhhh, void, float x, float y, u32 size, u8 r, u8 g, u8 b, u8 a);
    DECL_FASTCALL_SIMPLE(SetupRadarRect, _ZN6CRadar14SetupRadarRectEii, void, i32 x, i32 y);
    DECL_FASTCALL_SIMPLE(RequestMapSection, _ZN6CRadar17RequestMapSectionEii, void, i32 x, i32 y);
    DECL_FASTCALL_SIMPLE(RemoveMapSection, _ZN6CRadar16RemoveMapSectionEii, void, i32 x, i32 y);
    DECL_FASTCALL_SIMPLE(StreamRadarSections1, _ZN6CRadar19StreamRadarSectionsEii, void, i32 x, i32 y);
    DECL_FASTCALL_SIMPLE(ClipRadarPoly, _ZN6CRadar13ClipRadarPolyEP9CVector2DPKS0_, i32, CVector2D* clipVerts, CVector2D const* verts);
    DECL_FASTCALL_SIMPLE(DrawRadarSections, _ZN6CRadar16DrawRadarSectionsEiii, void, i32 x, i32 y, i32 alpha);
    DECL_FASTCALL_SIMPLE(DrawRadarSectionMap, _ZN6CRadar19DrawRadarSectionMapEii5CRectf, void, i32 x, i32 y, CRect pos, float opacity);
    DECL_FASTCALL_SIMPLE(DrawAreaOnRadar, _ZN6CRadar15DrawAreaOnRadarERK5CRectRK5CRGBAb, void, CRect const& rect, CRGBA const& rgba, bool fullMap);
    DECL_FASTCALL_SIMPLE(DrawRadarGangOverlay, _ZN6CRadar20DrawRadarGangOverlayEb, void, bool fullMap);
    DECL_FASTCALL_SIMPLE(DrawRadarMask, _ZN6CRadar13DrawRadarMaskEv, void);
    DECL_FASTCALL_SIMPLE(StreamRadarSections2, _ZN6CRadar19StreamRadarSectionsERK7CVector, void, CVector const& pos);
    DECL_FASTCALL_SIMPLE(Save, _ZN6CRadar4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN6CRadar4LoadEv, bool);
    
    // Helper functions
    static void StreamRadarSections(i32 x, i32 y)
    {
        StreamRadarSections1(x, y);
    }
    static void StreamRadarSections(CVector const& pos)
    {
        StreamRadarSections2(pos);
    }
    static tRadarTrace& GetBlip(i32 idx)
    {
        return ms_RadarTrace[idx];
    }
    static tRadarTrace& GetBlip(tBlipHandle hndl)
    {
        return ms_RadarTrace[hndl.arrayIndex];
    }
    static tRadarTrace& GetBlipFromHandle(u32 hndl)
    {
        return ms_RadarTrace[(unsigned short)hndl];
    }
    static bool ValidBlipHandle(u32 hndl)
    {
        tRadarTrace& blip = GetBlipFromHandle(hndl);
        return (blip.m_nCounter == (unsigned short)(hndl >> 16) && blip.m_nBlipDisplay);
    }
    
    // STATIC Values
    DECL_OBJECT_ARRAY_PLT(i16, MapLegendList, BYBIT(0x677394, 0x84C760));
    DECL_VALUE_PLT_U16(MapLegendCounter, BYBIT(0x679F14, 0x851E38));
    DECL_OBJECT_ARRAY_PLT(CRGBA, ArrowBlipColour, BYBIT(0x679CD0, 0x8519B8));
    DECL_OBJECT_ARRAY_PLT(tRadarTrace, ms_RadarTrace, BYBIT(0x6773CC, 0x84C7D0));
    DECL_OBJECT_PLT(CVector2D, vec2DRadarOrigin, BYBIT(0x677E44, 0x84DCA8));
    DECL_VALUE_PLT_FLT(m_radarRange, BYBIT(0x676E0C, 0x84BC60));
    DECL_OBJECT_PLT(CRect, m_radarRect, BYBIT(0x677C44, 0x84D8A8));
    DECL_VALUE_PLT_I32(airstrip_blip, BYBIT(0x678D98, 0x84FB58));
    DECL_VALUE_PLT_U8(airstrip_location, BYBIT(0x6760E4, 0x84A238));
    DECL_OBJECT_PLT(CSprite2d, RadarBlipSprites, BYBIT(0x6776F8, 0x84CE18));
DECL_CLASS_END()

#define MapLegendList MapLegendList()
#define MapLegendCounter MapLegendCounter()
#define ArrowBlipColour ArrowBlipColour()
#define ms_RadarTrace ms_RadarTrace()
#define vec2DRadarOrigin vec2DRadarOrigin()
#define m_radarRange m_radarRange()
#define m_radarRect m_radarRect()
#define airstrip_blip airstrip_blip()
#define airstrip_location airstrip_location()
#define RadarBlipSprites RadarBlipSprites()

#endif // __AML_PSDK_SARADAR_H
