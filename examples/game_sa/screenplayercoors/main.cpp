#include <mod/amlmod.h>

#include <aml-psdk/game_sa/Events.h>
#include <aml-psdk/game_sa/entity/PlayerPed.h>
#include <aml-psdk/game_sa/engine/Font.h>

MYMOD(net.rusjj.psdkexample.screenplayercoors, AML PSDK Example: Screen PlayerCoors, 1.0, RusJJ)

ON_MOD_LOAD()
{
    Events::drawHudEvent += []()
    {
        CPlayerPed* player = FindPlayerPed(-1);
        if(!player) return;

        char strText[64];
        CRGBA dropcolor(0, 0, 0, 255);
        CVector pos = player->GetPosition();
        float angle = (player->m_fCurrentRotation / M_PI) * 180.0f;
        if(angle < 0) angle += 360.0f;
        snprintf(strText, sizeof(strText), "%.2f %.2f %.2f ANGLE %.2f AREA %d", pos.x, pos.y, pos.z, angle, player->GetInterior());

        CFont::SetScale(2.1f);
        CFont::SetWrapx(1000000.0f);
        CFont::SetJustify(0);
        CFont::SetEdge(1);
        CFont::SetFontStyle(FO_FONT_STYLE_STANDARD);
        CFont::SetOrientation(ALIGN_LEFT);
        CFont::SetProportional(0);
        CFont::SetDropColor(dropcolor);
        CFont::PrintString(120.0f, 0.0f, strText);
        CFont::RenderFontBuffer();
    };
}