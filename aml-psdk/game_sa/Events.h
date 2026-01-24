#include "plugin.h"
#include <aml-psdk/sdk_callevents.h>

struct CCamera;

struct Events
{
    // PC psdk events
    DECL_EVENT_PLT_ARG0(void, restartGameEvent, BYBIT(0x674E38, 0x848318));
    DECL_EVENT_PLT_ARG0(void, drawingEvent, BYBIT(0x675CC4, 0x849AB0));
    DECL_EVENT_PLT_ARG0(void, drawHudEvent, BYBIT(0x6737EC, 0x845EC8));
    DECL_EVENT_PLT_ARG0(void, drawAfterFadeEvent, BYBIT(0x673C4C, 0x846618));
    DECL_EVENT_SYM_ARG0(void, drawRadarEvent, _ZN4CHud9DrawRadarEv);
    //DECL_EVENT_PLT_ARG0(void, drawBlipsEvent, BYBIT(0x66E910, 0x83DED0)); // arg0 float
    //DECL_EVENT_SYM_ARG0(void, drawRadarOverlayEvent, _ZN6CRadar20DrawRadarGangOverlayEb); // arg0 bool
    // drawMenuBackgroundEvent
    DECL_EVENT_SYM_ARG0(void, initRwEvent, _ZN5CGame20InitialiseRenderWareEv);
    DECL_EVENT_PLT_ARG0(void, shutdownRwEvent, BYBIT(0x6756F0, 0x849148));
    // vehicleCtorEvent
    // vehicleDtorEvent
    // pedCtorEvent
    // pedDtorEvent
    // objectCtorEvent
    // objectDtorEvent
    DECL_EVENT_PLT_ARG0(void, initPoolsEvent, BYBIT(0x672468, 0x843F18));
    DECL_EVENT_PLT_ARG0(void, shutdownPoolsEvent, BYBIT(0x66F218, 0x83EDC0));
    // vehicleRenderEvent
    // pedRenderEvent
    // objectRenderEvent
    // vehicleSetModelEvent
    // pedSetModelEvent
    // d3dResetEvent // ogl analogue
    // d3dLostEvent // do we need this?
    DECL_EVENT_SYM_ARG0(void, gameProcessEvent, _ZN5CGame7ProcessEv);
    DECL_EVENT_PLT_ARG0(void, initGameEvent, BYBIT(0x6740A4, 0x846D20));
    DECL_EVENT_PLT_ARG0(void, reInitGameEvent, BYBIT(0x672014, 0x843810));
    // onPauseAllSounds
    // onResumeAllSounds
    DECL_EVENT_PLT_ARG0(void, initScriptsEvent, BYBIT(0x671B14, 0x842FC0));
    DECL_EVENT_PLT_ARG0(void, processScriptsEvent, BYBIT(0x673178, 0x845438)); // wrong on PC. bruh...
    // menuDrawingEvent
    DECL_EVENT_SYM_ARG0(bool, attachRwPluginsEvent, _Z12PluginAttachv);

    // Additional events
    DECL_EVENT_PLT_ARG1(void, processCamera, BYBIT(0x6717BC, 0x8429D8), CCamera*, camera);
};