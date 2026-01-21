#ifndef __AML_PSDK_SADRAW_H
#define __AML_PSDK_SADRAW_H

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS(CDraw)
    // Functions
    DECL_FASTCALL_SIMPLE(SetFOV, _ZN5CDraw6SetFOVEfb, void, float fFOV, bool isCinematic);
    DECL_FASTCALL_SIMPLE(CalculateAspectRatio, _ZN5CDraw20CalculateAspectRatioEv, float);

    // STATIC Values
    DECL_VALUE_PLT_FLT(ms_fFOV, BYBIT(0x676B7C, 0x84B740));
    DECL_VALUE_PLT_FLT(ms_fNearClipZ, BYBIT(0x676188, 0x84A370));
    DECL_VALUE_PLT_FLT(ms_fFarClipZ, BYBIT(0x6779A4, 0x84D378));
    DECL_VALUE_PLT_FLT(ms_fLODDistance, BYBIT(0x679514, 0x850A38));
    DECL_VALUE_PLT_FLT(ms_fAspectRatio, BYBIT(0x6784C8, 0x84E9A8));
    DECL_VALUE_PLT_U8(FadeRed, BYBIT(0x677594, 0x84CB68));
    DECL_VALUE_PLT_U8(FadeGreen, BYBIT(0x677478, 0x84C928));
    DECL_VALUE_PLT_U8(FadeBlue, BYBIT(0x678B5C, 0x84F6E0));
    DECL_VALUE_PLT_U8(FadeValue, BYBIT(0x677E0C, 0x84DC38));
DECL_CLASS_END()

#define ms_fFOV ms_fFOV()
#define ms_fNearClipZ ms_fNearClipZ()
#define ms_fFarClipZ ms_fFarClipZ()
#define ms_fLODDistance ms_fLODDistance()
#define ms_fAspectRatio ms_fAspectRatio()
#define FadeRed FadeRed()
#define FadeGreen FadeGreen()
#define FadeBlue FadeBlue()
#define FadeValue FadeValue()

#endif // __AML_PSDK_SADRAW_H