#include <mod/amlmod.h>
#include <mod/logger.h>
#include <mod/config.h>

MYMOD(net.psdk.mymod.guid, AML PSDK Template, 1.0, Author)

// Just a list of all includes to see if they're getting compiled without errors and warnings

#include <aml-psdk/game_sa/base/Timer.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/entity/PlayerPed.h>
#include <aml-psdk/game_sa/entity/Automobile.h>
#include <aml-psdk/game_sa/engine/RunningScript.h>
#include <aml-psdk/game_sa/audio/AudioEngine.h>
#include <aml-psdk/game_sa/engine/Draw.h>
#include <aml-psdk/game_sa/engine/FileMgr.h>
#include <aml-psdk/game_sa/engine/Game.h>
#include <aml-psdk/game_sa/engine/GameLogic.h>
#include <aml-psdk/game_sa/other/PlayerData.h>
#include <aml-psdk/game_sa/ai/PedIntelligence.h>
#include <aml-psdk/game_sa/ai/tasks/Task.h>
#include <aml-psdk/game_sa/entity/Camera.h>

DECL_HOOKv(CCamera__Process, CCamera* self)
{
    CCamera__Process(self);
    logger->Info("Camera! :o");
}

void Test()
{
    AudioEngine.m_pWeaponAudio = 0;

    // Yes, it's not "new" and "delete" but i want to allow usage of virtual funcs. It's faster and way shorter code!
    CTask* newTask = CTask::Instantiate();
    CLASS_CONSTRUCT(CTask, newTask);
    CLASS_DECONSTRUCT(CTask, newTask); // alternatively newTask->MyDestructor() from SimpleVTable or thing below (if we have it)
    //newTask->DeInstantiate();

    // GET_THISCALL_ADDR only works with declared funcs
    // HOOK(CCamera__Process, GetMainLibrarySymbol("_ZN7CCamera7ProcessEv") );
    HOOK(CCamera__Process, GET_THISCALL_ADDR(CCamera, Process) ); // <- this definitely looks better than above :p
}