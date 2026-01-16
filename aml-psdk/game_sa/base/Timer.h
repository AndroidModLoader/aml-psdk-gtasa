#ifndef __AML_PSDK_SATIMER_H
#define __AML_PSDK_SATIMER_H

#include <aml-psdk/sdk_base.h>

struct CTimer
{
    static inline auto Initialise = GetMainLibrarySymbol<void(*)()>("_ZN6CTimer10InitialiseEv");
    static inline auto Shutdown = GetMainLibrarySymbol<void(*)()>("_ZN6CTimer8ShutdownEv");
    static inline auto Update = GetMainLibrarySymbol<void(*)()>("_ZN6CTimer6UpdateEv");
    static inline auto UpdateVariables = GetMainLibrarySymbol<void(*)(float)>("_ZN6CTimer15UpdateVariablesEf");
    static inline auto Suspend = GetMainLibrarySymbol<void(*)()>("_ZN6CTimer7SuspendEv");
    static inline auto Resume = GetMainLibrarySymbol<void(*)()>("_ZN6CTimer6ResumeEv");
    static inline auto GetCyclesPerMillisecond = GetMainLibrarySymbol<u32(*)()>("_ZN6CTimer23GetCyclesPerMillisecondEv");
    static inline auto GetCyclesPerFrame = GetMainLibrarySymbol<u32(*)()>("_ZN6CTimer17GetCyclesPerFrameEv");
    static inline auto GetCurrentTimeInCycles = GetMainLibrarySymbol<u32(*)()>("_ZN6CTimer22GetCurrentTimeInCyclesEv");
    static inline auto Stop = GetMainLibrarySymbol<void(*)()>("_ZN6CTimer4StopEv");
    static inline auto GetIsSlowMotionActive = GetMainLibrarySymbol<bool(*)()>("_ZN6CTimer21GetIsSlowMotionActiveEv");
    static inline auto StartUserPause = GetMainLibrarySymbol<void(*)()>("_ZN6CTimer14StartUserPauseEv");
    static inline auto EndUserPause = GetMainLibrarySymbol<void(*)()>("_ZN6CTimer12EndUserPauseEv");

    DECL_VALUE_PLT_U32(m_snTimeInMilliseconds, BYBIT(0x676FFC, 0x84C030));
    DECL_VALUE_PLT_U32(m_snTimeInMillisecondsNonClipped, BYBIT(0x679DBC, 0x851B90));
    DECL_VALUE_PLT_U32(m_snTimeInMillisecondsPauseMode, BYBIT(0x677A2C, 0x84D480));
    DECL_VALUE_PLT_U32(m_snPreviousTimeInMilliseconds, BYBIT(0x6779AC, 0x84D388));
    DECL_VALUE_PLT_U32(m_snPPreviousTimeInMilliseconds, BYBIT(0x679D3C, 0x851A90));
    DECL_VALUE_PLT_U32(m_snPPPreviousTimeInMilliseconds, BYBIT(0x677DF8, 0x84DC10));
    DECL_VALUE_PLT_U32(m_snPPPPreviousTimeInMilliseconds, BYBIT(0x6794A4, 0x850960));
    DECL_VALUE_PLT_U32(m_snPreviousTimeInMillisecondsNonClipped, BYBIT(0x677600, 0x84CC30));
    DECL_VALUE_PLT_FLT(ms_fTimeScale, BYBIT(0x6768A8, 0x84B1A8));
    DECL_VALUE_PLT_FLT(ms_fSlowMotionScale, BYBIT(0x676B24, 0x84B690));
    DECL_VALUE_PLT_FLT(ms_fTimeStep, BYBIT(0x677714, 0x84CE50));
    DECL_VALUE_PLT_FLT(ms_fTimeStepNonClipped, BYBIT(0x6799B4, 0x851380));
    DECL_VALUE_PLT_FLT(ms_fOldTimeStep, BYBIT(0x676C08, 0x84B858));
    DECL_VALUE_PLT_FLT(game_FPS, BYBIT(0x67767C, 0x84CD28));
    DECL_VALUE_PLT_U32(m_FrameCounter, BYBIT(0x678930, 0x84F280));

    DECL_VALUE_PLT_BOOL(m_UserPause, BYBIT(0x6776B0, 0x84CD90));
    DECL_VALUE_PLT_BOOL(m_CodePause, BYBIT(0x6794C4, 0x8509A0));
    DECL_VALUE_PLT_BOOL(bSlowMotionActive, BYBIT(0x6786A0, 0x84ED68));
    DECL_VALUE_PLT_BOOL(bSkipProcessThisFrame, BYBIT(0x679250, 0x8504B8));

    inline u32 GetTimeMS()
    {
        return m_snTimeInMilliseconds;
    }
    inline float GetTimeScale()
    {
        return ms_fTimeScale;
    }
    inline float GetTimeStep()
    {
        return ms_fTimeStep;
    }
};

#endif // __AML_PSDK_SATIMER_H