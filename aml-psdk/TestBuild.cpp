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

void Test()
{
    AudioEngine.m_pWeaponAudio = 0;
}