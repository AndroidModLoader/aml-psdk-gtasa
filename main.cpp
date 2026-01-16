#include <aml-psdk/sdk_base.h>
#include <mod/logger.h>
#include <mod/config.h>

#include <aml-psdk/game/base/Timer.h>
#include <aml-psdk/game/base/Vector.h>

MYMODCFG(net.psdk.mymod.guid, AML PSDK Template, 1.0, Author)
//MYMOD(net.psdk.mymod.guid, AML PSDK Template NoConfig, 1.0, Author)
//NEEDGAME(net.psdk.mygame)
//BEGIN_DEPLIST()
//    ADD_DEPENDENCY_VER(net.psdk.aml, 1.0)
//END_DEPLIST()

DECL_HOOKv(CTimer__Update)
{
    CTimer__Update();
    CTimer::m_snTimeInMilliseconds += 5;
    logger->Info("CTimer__Update: %u", CTimer::m_snTimeInMilliseconds.Get());
    CTimer::m_snTimeInMilliseconds -= 5;
}

ON_MOD_LOAD()
{
    logger->SetTag("PSDK Template");
    
    HOOK(CTimer__Update, CTimer::Update);
}