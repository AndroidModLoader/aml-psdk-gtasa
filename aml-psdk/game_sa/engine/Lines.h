#ifndef __AML_PSDK_SALINES_H
#define __AML_PSDK_SALINES_H

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS(CLines)
    // Functions
    DECL_FASTCALL_SIMPLE(ImmediateLine2D, _ZN6CLines15ImmediateLine2DEiiiihhhhhhhh, void, int startX, int startY, int endX, int endY, u8 sr, u8 sg, u8 sb, u8 sa, u8 er, u8 eg, u8 eb, u8 ea);
    DECL_FASTCALL_SIMPLE(RenderLineNoClipping, _ZN6CLines20RenderLineNoClippingEffffffjj, void, float startX, float startY, float startZ, float endX, float endY, float endZ, u32 color1, u32 color2);
    DECL_FASTCALL_SIMPLE(RenderLineWithClipping, _ZN6CLines22RenderLineWithClippingEffffffjj, void, float startX, float startY, float startZ, float endX, float endY, float endZ, u32 color1, u32 color2);
DECL_CLASS_END()

#endif // __AML_PSDK_SALINES_H
