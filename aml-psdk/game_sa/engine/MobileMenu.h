#ifndef __AML_PSDK_SAMOBILEMENU_H
#define __AML_PSDK_SAMOBILEMENU_H

#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/RGBA.h>
#include "OS.h"

struct MenuScreen;
struct RwTexture;

DECL_CLASS(MobileMenu)
    // Construct/Deconstruct functions
    DECL_CTORCALL(MobileMenu, _ZN10MobileMenuC2Ev);
    DECL_DTORCALL_PLT(MobileMenu, BYBIT(0x67626C, 0x84A538));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(DrawQuad1, _ZN10MobileMenu8DrawQuadE9CVector2DS0_P5CRGBA, void, CVector2D ul, CVector2D lr, CRGBA *col);
    DECL_FASTCALL_SIMPLE(DrawQuad2, _ZN10MobileMenu8DrawQuadEP9CVector2DP5CRGBA, void, CVector2D *coords, CRGBA *col);
    DECL_FASTCALL_SIMPLE(DrawSprite1, _ZN10MobileMenu10DrawSpriteEP9RwTextureP9CVector2DS3_P5CRGBA, void, RwTexture *texture, CVector2D *coords, CVector2D *uvs, CRGBA *col);
    DECL_FASTCALL_SIMPLE(DrawSprite2, _ZN10MobileMenu10DrawSpriteEP9RwTexture5CRGBA9CVector2DS3_S3_S3_, void, RwTexture *texture, CRGBA col, CVector2D ul, CVector2D lr, CVector2D uv1, CVector2D uv2);
    DECL_FASTCALL_SIMPLE(DrawSprite3, _ZN10MobileMenu10DrawSpriteEP9RwTexture5CRGBA9CVector2DS3_, void, RwTexture *texture, CRGBA col, CVector2D ul, CVector2D lr);
    
    // Member functions
    DECL_THISCALL_SIMPLE(Initialize, _ZN10MobileMenu10InitializeEv, void);
    DECL_THISCALL_SIMPLE(CalcBGUVSize, _ZN10MobileMenu12CalcBGUVSizeEv, CVector2D);
    DECL_THISCALL_SIMPLE(GetRandomBGCoords, _ZN10MobileMenu17GetRandomBGCoordsEv, CVector2D);
    DECL_THISCALL_SIMPLE(Render, _ZN10MobileMenu6RenderEv, void);
    DECL_THISCALL_SIMPLE(PrepareToRender, _ZN10MobileMenu15PrepareToRenderEv, void);
    DECL_THISCALL_SIMPLE(ProcessPending, _ZN10MobileMenu14ProcessPendingEv, void);
    DECL_THISCALL_SIMPLE(PopAllScreens, _ZN10MobileMenu13PopAllScreensEv, void);
    DECL_THISCALL_SIMPLE(Update, _ZN10MobileMenu6UpdateEv, void);
    DECL_THISCALL_SIMPLE(InitForPause, _ZN10MobileMenu12InitForPauseEv, void);
    DECL_THISCALL_SIMPLE(IsMainMenuScreen, _ZN10MobileMenu16IsMainMenuScreenEv, bool);
    DECL_THISCALL_SIMPLE(Exit, _ZN10MobileMenu4ExitEv, void);
    DECL_THISCALL_SIMPLE(Load, _ZN10MobileMenu4LoadEv, void);
    DECL_THISCALL_SIMPLE(Unload, _ZN10MobileMenu6UnloadEv, void);
    DECL_THISCALL_SIMPLE(InitForTitle, _ZN10MobileMenu12InitForTitleEv, void);
    DECL_THISCALL_SIMPLE(InitForDownload, _ZN10MobileMenu15InitForDownloadEv, void);
    DECL_THISCALL_SIMPLE(InitForSignedOut, _ZN10MobileMenu16InitForSignedOutEv, void);
    DECL_THISCALL_SIMPLE(InitForSave, _ZN10MobileMenu11InitForSaveEv, void);
    DECL_THISCALL_SIMPLE(InitForRetry, _ZN10MobileMenu12InitForRetryEv, void);
    DECL_THISCALL_SIMPLE(LoadFailed, _ZN10MobileMenu10LoadFailedEv, void);
    DECL_THISCALL_SIMPLE(SaveFailed, _ZN10MobileMenu10SaveFailedEv, void);
    DECL_THISCALL_SIMPLE(InitForNag, _ZN10MobileMenu10InitForNagEv, void);
    DECL_THISCALL_SIMPLE(InitGameVars, _ZN10MobileMenu12InitGameVarsEv, void);

    DECL_THISCALL_HEAD(UpdateDownload, _ZN10MobileMenu14UpdateDownloadEib, void, int percent, bool done)
    DECL_THISCALL_TAIL(UpdateDownload, percent, done)

    DECL_THISCALL_HEAD(AddScreen, _ZN10MobileMenu9AddScreenEP10MenuScreenb, void, MenuScreen *toAdd, bool immediate)
    DECL_THISCALL_TAIL(AddScreen, toAdd, immediate)

    DECL_THISCALL_HEAD(RemoveTopScreen, _ZN10MobileMenu15RemoveTopScreenEbb, void, bool immediate, bool dontExit)
    DECL_THISCALL_TAIL(RemoveTopScreen, immediate, dontExit)

    DECL_THISCALL_HEAD(ClampBGCoords, _ZN10MobileMenu13ClampBGCoordsER9CVector2D, void, CVector2D &toClamp)
    DECL_THISCALL_TAIL(ClampBGCoords, toClamp)

    // Helper functions
    static inline void DrawQuad(CVector2D ul, CVector2D lr, CRGBA *col)
    {
        DrawQuad1(ul, lr, col);
    }
    static inline void DrawQuad(CVector2D *coords, CRGBA *col)
    {
        DrawQuad2(coords, col);
    }
    static inline void DrawSprite(RwTexture *texture, CVector2D *coords, CVector2D *uvs, CRGBA *col)
    {
        DrawSprite1(texture, coords, uvs, col);
    }
    static inline void DrawSprite(RwTexture *texture, CRGBA col, CVector2D ul, CVector2D lr, CVector2D uv1, CVector2D uv2)
    {
        DrawSprite2(texture, col, ul, lr, uv1, uv2);
    }
    static inline void DrawSprite(RwTexture *texture, CRGBA col, CVector2D ul, CVector2D lr)
    {
        DrawSprite3(texture, col, ul, lr);
    }

    // Member values
    CVector2D bgUVSize;
    CVector2D bgTargetCoords;
    CVector2D bgCurCoords;
    CVector2D bgStartCoords;
    OSArray<MenuScreen *> screenStack;
    MenuScreen *pendingScreen;
    RwTexture *bgTex;
    RwTexture *sliderEmpty;
    RwTexture *sliderFull;
    RwTexture *sliderNub;
    RwTexture *controlsBack;
    RwTexture *controlsBack2;
    int m_nTargetBlipIndex; // blip script handle
    u8 m_bWantToRestart;
    bool m_bWantToLoad;
    int m_nSaveSlot;
    bool m_bOnlyNewGame;
    bool m_bSocialClubLogged;
    float m_fMapZoom;
    float m_fMapBaseX;
    float m_fMapBaseY;
    float m_fMapEndX;
    float m_fMapEndY;
    bool m_bDrawRadarOrMap;
    bool m_bOpenMenuMap; // when game's paused, it opens a big map
    bool m_nPointerMode;
    bool m_bShowMouse;
    CVector2D m_vMousePos[4];
    OSPointerState m_nPointerState[4];
    unsigned int m_nPointerActivateTime[4];
DECL_CLASS_END()
CHECKSIZE(MobileMenu, 0xB0, 0xD0);

DECL_OBJECT_PLT_GLOBAL(MobileMenu, gMobileMenu, BYBIT(0x679CCC, 0x8519B0) );
#define gMobileMenu gMobileMenu()

#endif // __AML_PSDK_SAMOBILEMENU_H