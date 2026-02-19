#ifndef __AML_PSDK_SACALLEVENTS_H
#define __AML_PSDK_SACALLEVENTS_H

#include "plugin.h"
#include <aml-psdk/sdk_callevents.h>

struct CCamera;
struct CVehicle;
struct CPed;
struct CObject;
struct MobileMenu;

struct Events
{
    // PC psdk events (they are slightly different from PC. Please keep that in mind!)
    DECL_EVENT_PLT_ARG0_PICK0(void, restartGameEvent, BYBIT(0x674E38, 0x848318));
    DECL_EVENT_PLT_ARG0_PICK0(void, drawingEvent, BYBIT(0x675CC4, 0x849AB0));
    DECL_EVENT_PLT_ARG0_PICK0(void, drawHudEvent, BYBIT(0x6737EC, 0x845EC8));
    DECL_EVENT_PLT_ARG0_PICK0(void, drawAfterFadeEvent, BYBIT(0x673C4C, 0x846618));
    DECL_EVENT_SYM_ARG0_PICK0(void, drawRadarEvent, _ZN4CHud9DrawRadarEv);
    DECL_EVENT_PLT_ARG1_PICK0(void, drawBlipsEvent, BYBIT(0x66E910, 0x83DED0), float, circleSize);
    DECL_EVENT_SYM_ARG1_PICK0(void, drawRadarOverlayEvent, _ZN6CRadar20DrawRadarGangOverlayEb, bool, bFullMap);
    // drawMenuBackgroundEvent
    DECL_EVENT_SYM_ARG0_PICK0(void, initRwEvent, _ZN5CGame20InitialiseRenderWareEv);
    DECL_EVENT_PLT_ARG0_PICK0(void, shutdownRwEvent, BYBIT(0x6756F0, 0x849148));
    DECL_EVENT_SYM_ARG2_PICK1(void, vehicleCtorEvent, _ZN8CVehicleC2Eh, CVehicle*, vehicle, u8, createdBy);
    DECL_EVENT_SYM_ARG1_PICK1(void, vehicleDtorEvent, _ZN8CVehicleD2Ev, CVehicle*, vehicle);
    DECL_EVENT_SYM_ARG2_PICK1(void, pedCtorEvent, _ZN4CPedC2Ej, CPed*, ped, u32, type);
    DECL_EVENT_SYM_ARG1_PICK1(void, pedDtorEvent, _ZN4CPedD2Ev, CPed*, ped);
    DECL_EVENT_SYM_ARG1_PICK1(void, objectCtorEvent, _ZN7CObject4InitEv, CObject*, object);
    DECL_EVENT_SYM_ARG1_PICK1(void, objectDtorEvent, _ZN7CObjectD2Ev, CObject*, object);
    DECL_EVENT_PLT_ARG0_PICK0(void, initPoolsEvent, BYBIT(0x672468, 0x843F18));
    DECL_EVENT_PLT_ARG0_PICK0(void, shutdownPoolsEvent, BYBIT(0x66F218, 0x83EDC0));
    DECL_EVENT_SYM_ARG1_PICK1(void, vehicleRenderEvent, _ZN8CVehicle6RenderEv, CVehicle*, vehicle);
    DECL_EVENT_SYM_ARG1_PICK1(void, pedRenderEvent, _ZN4CPed6RenderEv, CPed*, ped);
    DECL_EVENT_SYM_ARG1_PICK1(void, objectRenderEvent, _ZN7CObject6RenderEv, CObject*, object);
    DECL_EVENT_SYM_ARG2_PICK2(void, vehicleSetModelEvent, _ZN8CVehicle13SetModelIndexEj, CVehicle*, vehicle, int, model);
    DECL_EVENT_SYM_ARG2_PICK2(void, pedSetModelEvent, _ZN4CPed13SetModelIndexEj, CPed*, ped, int, model);
    // d3dResetEvent // ogl analogue
    // d3dLostEvent // do we need this?
    DECL_EVENT_SYM_ARG0_PICK0(void, gameProcessEvent, _ZN5CGame7ProcessEv);
    DECL_EVENT_PLT_ARG0_PICK0(void, initGameEvent, BYBIT(0x6740A4, 0x846D20));
    DECL_EVENT_PLT_ARG0_PICK0(void, reInitGameEvent, BYBIT(0x672014, 0x843810));
    // onPauseAllSounds
    // onResumeAllSounds
    DECL_EVENT_PLT_ARG0_PICK0(void, initScriptsEvent, BYBIT(0x671B14, 0x842FC0));
    DECL_EVENT_PLT_ARG0_PICK0(void, processScriptsEvent, BYBIT(0x673178, 0x845438)); // wrong on PC. bruh...
    DECL_EVENT_PLT_ARG1_PICK0(void, menuDrawingEvent, BYBIT(0x674254, 0x846FE8), MobileMenu*, mobilemenu);
    DECL_EVENT_SYM_ARG0_PICK0(bool, attachRwPluginsEvent, _Z12PluginAttachv);

    // Additional events (aml psdk)
    DECL_EVENT_PLT_ARG1_PICK1(void, processCameraEvent, BYBIT(0x6717BC, 0x8429D8), CCamera*, camera);
    DECL_EVENT_PLT_ARG0_PICK0(void, initWidgetsEvent, BYBIT(0x6734E4, 0x8459D8));
    DECL_EVENT_PLT_ARG0_PICK0(void, updateWidgetsEvent, BYBIT(0x6746E4, 0x847780));
    DECL_EVENT_SYM_ARG1_PICK0(bool, initGameStage1Event, _ZN5CGame5Init1EPKc, const char*, datFile);
    DECL_EVENT_SYM_ARG1_PICK0(bool, initGameStage2Event, _ZN5CGame5Init2EPKc, const char*, datFile);
    DECL_EVENT_SYM_ARG1_PICK0(bool, initGameStage3Event, _ZN5CGame5Init3EPKc, const char*, datFile);
    DECL_EVENT_SYM_ARG1_PICK0(void, menuUpdateEvent, _ZN10MobileMenu6UpdateEv, void*, self);
    DECL_EVENT_SYM_ARG0_PICK0(void, renderEffectsEvent, _Z13RenderEffectsv);
    DECL_EVENT_SYM_ARG0_PICK0(void, renderSpecialEffectsEvent, _ZN10CSpecialFX6RenderEv);
    DECL_EVENT_SYM_ARG0_PICK0(void, renderWeaponEffectsEvent, _ZN14CWeaponEffects6RenderEv);
    DECL_EVENT_SYM_ARG0_PICK0(void, renderCoronasEvent, _ZN8CCoronas6RenderEv);
    DECL_EVENT_SYM_ARG0_PICK0(void, updateCoronasEvent, _ZN8CCoronas6UpdateEv);
    DECL_EVENT_SYM_ARG0_PICK0(void, gameLogicUpdateEvent, _ZN10CGameLogic6UpdateEv);
    DECL_EVENT_SYM_ARG0_PICK0(bool, preinitEngineEvent, _ZN5CGame22InitialiseOnceBeforeRWEv);
    DECL_EVENT_SYM_ARG0_PICK0(int,  initEngineEvent, _Z12RsInitializev);
    DECL_EVENT_SYM_ARG4_PICK4(void, touchScreenEvent, _Z14AND_TouchEventiiii, int, actionType, int, trackNum, int, x, int, y); // !!! NOT THREAD SAFE !!!
};

#endif // __AML_PSDK_SACALLEVENTS_H
