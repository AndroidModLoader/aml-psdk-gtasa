#include <mod/amlmod.h>

#include <aml-psdk/game_sa/entity/PlayerPed.h>
#include <aml-psdk/game_sa/extdata/CoronasExtender.h>

MYMOD(net.rusjj.psdkexample.coronas, AML PSDK Example: CoronaExtTest, 1.0, RusJJ)

ON_MOD_LOAD()
{
    Events::gameProcessEvent.before += []()
    {
        CPlayerPed* p = FindPlayerPed(-1);
        if(!p) return;

        int off = 0;

        CoronasExtender::RegisterCorona((uintptr_t)p + 0x1243 + off++, p, 255, 255, 255, 255, CVector(0,0,1),
            0.2f, 100.0f, CORONATYPE_SHINYSTAR, FLARETYPE_NONE, 0, 0, 0, 0.0f, false, 0.0f, false, 1.0f, false, true);

        CoronasExtender::RegisterCorona((uintptr_t)p + 0x1243 + off++, p, 255, 255, 255, 255, CVector(0,0,-1),
            0.2f, 100.0f, CORONATYPE_SHINYSTAR, FLARETYPE_NONE, 0, 0, 0, 0.0f, false, 0.0f, false, 1.0f, false, true);

        CoronasExtender::RegisterCorona((uintptr_t)p + 0x1243 + off++, p, 255, 255, 255, 255, CVector(0,1,0),
            0.2f, 100.0f, CORONATYPE_SHINYSTAR, FLARETYPE_NONE, 0, 0, 0, 0.0f, false, 0.0f, false, 1.0f, false, true);

        CoronasExtender::RegisterCorona((uintptr_t)p + 0x1243 + off++, p, 255, 255, 255, 255, CVector(1,1,0),
            0.2f, 100.0f, CORONATYPE_SHINYSTAR, FLARETYPE_NONE, 0, 0, 0, 0.0f, false, 0.0f, false, 1.0f, false, true);

        CoronasExtender::RegisterCorona((uintptr_t)p + 0x1243 + off++, p, 255, 255, 255, 255, CVector(1,0,0),
            0.2f, 100.0f, CORONATYPE_SHINYSTAR, FLARETYPE_NONE, 0, 0, 0, 0.0f, false, 0.0f, false, 1.0f, false, true);

        CoronasExtender::RegisterCorona((uintptr_t)p + 0x1243 + off++, p, 255, 255, 255, 255, CVector(1,-1,0),
            0.2f, 100.0f, CORONATYPE_SHINYSTAR, FLARETYPE_NONE, 0, 0, 0, 0.0f, false, 0.0f, false, 1.0f, false, true);

        CoronasExtender::RegisterCorona((uintptr_t)p + 0x1243 + off++, p, 255, 255, 255, 255, CVector(0,-1,0),
            0.2f, 100.0f, CORONATYPE_SHINYSTAR, FLARETYPE_NONE, 0, 0, 0, 0.0f, false, 0.0f, false, 1.0f, false, true);

        CoronasExtender::RegisterCorona((uintptr_t)p + 0x1243 + off++, p, 255, 255, 255, 255, CVector(-1,-1,0),
            0.2f, 100.0f, CORONATYPE_SHINYSTAR, FLARETYPE_NONE, 0, 0, 0, 0.0f, false, 0.0f, false, 1.0f, false, true);

        CoronasExtender::RegisterCorona((uintptr_t)p + 0x1243 + off++, p, 255, 255, 255, 255, CVector(-1,0,0),
            0.2f, 100.0f, CORONATYPE_SHINYSTAR, FLARETYPE_NONE, 0, 0, 0, 0.0f, false, 0.0f, false, 1.0f, false, true);

        CoronasExtender::RegisterCorona((uintptr_t)p + 0x1243 + off++, p, 255, 255, 255, 255, CVector(-1,1,0),
            0.2f, 100.0f, CORONATYPE_SHINYSTAR, FLARETYPE_NONE, 0, 0, 0, 0.0f, false, 0.0f, false, 1.0f, false, true);
    };
}