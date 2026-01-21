#ifndef __AML_PSDK_SAGAME_H
#define __AML_PSDK_SAGAME_H

#include <aml-psdk/renderware/RwMatrix.h>

DECL_CLASS(CGame)
    // Functions
    DECL_FASTCALL_SIMPLE(InitialiseOnceBeforeRW, _ZN5CGame22InitialiseOnceBeforeRWEv, bool);
    DECL_FASTCALL_SIMPLE(ShutdownRenderWare, _ZN5CGame18ShutdownRenderWareEv, void);
    DECL_FASTCALL_SIMPLE(FinalShutdown, _ZN5CGame13FinalShutdownEv, void);
    DECL_FASTCALL_SIMPLE(Initialise, _ZN5CGame10InitialiseEPKc, bool, const char *pDatFile);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN5CGame8ShutdownEv, bool);
    DECL_FASTCALL_SIMPLE(ReInitGameObjectVariables, _ZN5CGame25ReInitGameObjectVariablesEv, void);
    DECL_FASTCALL_SIMPLE(ReloadIPLs, _ZN5CGame10ReloadIPLsEv, void);
    DECL_FASTCALL_SIMPLE(ShutDownForRestart, _ZN5CGame18ShutDownForRestartEv, void);
    DECL_FASTCALL_SIMPLE(TidyUpMemory, _ZN5CGame12TidyUpMemoryEbb, void, bool bMoveTextures, bool bWait);
    DECL_FASTCALL_SIMPLE(InitialiseWhenRestarting, _ZN5CGame24InitialiseWhenRestartingEv, void);
    DECL_FASTCALL_SIMPLE(Process, _ZN5CGame7ProcessEv, void);
    DECL_FASTCALL_SIMPLE(GenerateTempPedAtStartOfNetworkGame, _ZN5CGame35GenerateTempPedAtStartOfNetworkGameEv, void);
    DECL_FASTCALL_SIMPLE(DrasticTidyUpMemory, _ZN5CGame19DrasticTidyUpMemoryEb, void, bool bWait);
    DECL_FASTCALL_SIMPLE(ProcessTidyUpMemory, _ZN5CGame19ProcessTidyUpMemoryEv, void);
    DECL_FASTCALL_SIMPLE(CanSeeOutSideFromCurrArea, _ZN5CGame25CanSeeOutSideFromCurrAreaEv, bool);
    DECL_FASTCALL_SIMPLE(CanSeeWaterFromCurrArea, _ZN5CGame23CanSeeWaterFromCurrAreaEv, bool);
    DECL_FASTCALL_SIMPLE(InitialiseRenderWare, _ZN5CGame20InitialiseRenderWareEv, bool);
    DECL_FASTCALL_SIMPLE(InitialiseEssentialsAfterRW, _ZN5CGame27InitialiseEssentialsAfterRWEv, bool);
    DECL_FASTCALL_SIMPLE(InitialiseCoreDataAfterRW, _ZN5CGame25InitialiseCoreDataAfterRWEv, bool);
    DECL_FASTCALL_SIMPLE(Init1, _ZN5CGame5Init1EPKc, bool, const char *pDatFile);
    DECL_FASTCALL_SIMPLE(Init2, _ZN5CGame5Init2EPKc, bool, const char *pDatFile);
    DECL_FASTCALL_SIMPLE(Init3, _ZN5CGame5Init3EPKc, bool, const char *pDatFile);

    // STATIC Values
    DECL_VALUE_PLT_U8(bMissionPackGame, BYBIT(0x676D14, 0x84BA70));
    DECL_VALUE_PLT_I32(currLevel, BYBIT(0x6770E4, 0x84C200));
    DECL_VALUE_PLT_I32(currArea, BYBIT(0x678C3C, 0x84F8A0));
    DECL_VALUE_PLT_CHAR(aDatFile, BYBIT(0x6793DC, 0x8507D0));
    DECL_OBJECT_PLT(RwMatrix*, m_pWorkingMatrix1, BYBIT(0x6796F0, 0x850DF0));
    DECL_OBJECT_PLT(RwMatrix*, m_pWorkingMatrix2, BYBIT(0x677B40, 0x84D6A0));
DECL_CLASS_END()

#define bMissionPackGame bMissionPackGame()
#define currLevel currLevel()
#define currArea currArea()
#define aDatFile aDatFile()
#define m_pWorkingMatrix1 m_pWorkingMatrix1()
#define m_pWorkingMatrix2 m_pWorkingMatrix2()

DECL_VALUE_PLT_I32_GLOBAL(gGameState, BYBIT(0x679EF8, 0x851E00) );
#define gGameState ( gGameState() )

#endif // __AML_PSDK_SAGAME_H