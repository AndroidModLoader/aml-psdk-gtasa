#ifndef __AML_PSDK_SATIMER_H
#define __AML_PSDK_SATIMER_H

#include <aml-psdk/game_sa/plugin.h>

struct CTimer
{
    // Functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN6CTimer10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN6CTimer8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN6CTimer6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(UpdateVariables, _ZN6CTimer15UpdateVariablesEf, void);
    DECL_FASTCALL_SIMPLE(Suspend, _ZN6CTimer7SuspendEv, void);
    DECL_FASTCALL_SIMPLE(Resume, _ZN6CTimer6ResumeEv, void);
    DECL_FASTCALL_SIMPLE(GetCyclesPerMillisecond, _ZN6CTimer23GetCyclesPerMillisecondEv, u32);
    DECL_FASTCALL_SIMPLE(GetCyclesPerFrame, _ZN6CTimer17GetCyclesPerFrameEv, u32);
    DECL_FASTCALL_SIMPLE(GetCurrentTimeInCycles, _ZN6CTimer22GetCurrentTimeInCyclesEv, u32);
    DECL_FASTCALL_SIMPLE(Stop, _ZN6CTimer4StopEv, void);
    DECL_FASTCALL_SIMPLE(GetIsSlowMotionActive, _ZN6CTimer21GetIsSlowMotionActiveEv, bool);
    DECL_FASTCALL_SIMPLE(StartUserPause, _ZN6CTimer14StartUserPauseEv, void);
    DECL_FASTCALL_SIMPLE(EndUserPause, _ZN6CTimer12EndUserPauseEv, void);

    // STATIC values
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

    // Helper functions
    static inline u32 GetTimeMS()
    {
        return m_snTimeInMilliseconds;
    }
    static inline u32 GetTimeInMS()
    {
        return m_snTimeInMilliseconds;
    }
    static inline float GetTimeScale()
    {
        return ms_fTimeScale;
    }
    static inline float GetTimeStep()
    {
        return ms_fTimeStep;
    }
    static inline float GetTimeStepFix()
    {
        return GetTimeStep() / (50.0f / 30.0f);
    }
    static inline float GetTimeStepInvFix()
    {
        return (50.0f / 30.0f) / GetTimeStep();
    }
    static inline float GetTimeStepInSeconds()
    {
        return GetTimeStep() / 50.0f;
    }
    static inline bool IsPaused()
    {
        return ( m_UserPause() || m_CodePause() );
    }
};

#define m_snTimeInMilliseconds m_snTimeInMilliseconds()
#define m_snTimeInMillisecondsNonClipped m_snTimeInMillisecondsNonClipped()
#define m_snTimeInMillisecondsPauseMode m_snTimeInMillisecondsPauseMode()
#define m_snPreviousTimeInMilliseconds m_snPreviousTimeInMilliseconds()
#define m_snPPreviousTimeInMilliseconds m_snPPreviousTimeInMilliseconds()
#define m_snPPPreviousTimeInMilliseconds m_snPPPreviousTimeInMilliseconds()
#define m_snPPPPreviousTimeInMilliseconds m_snPPPPreviousTimeInMilliseconds()
#define m_snPreviousTimeInMillisecondsNonClipped m_snPreviousTimeInMillisecondsNonClipped()
#define ms_fTimeScale ms_fTimeScale()
#define ms_fSlowMotionScale ms_fSlowMotionScale()
#define ms_fTimeStep ms_fTimeStep()
#define ms_fTimeStepNonClipped ms_fTimeStepNonClipped()
#define ms_fOldTimeStep ms_fOldTimeStep()
#define game_FPS game_FPS()
#define m_FrameCounter m_FrameCounter()
#define m_UserPause m_UserPause()
#define m_CodePause m_CodePause()
#define bSlowMotionActive bSlowMotionActive()
#define bSkipProcessThisFrame bSkipProcessThisFrame()

#endif // __AML_PSDK_SATIMER_H
