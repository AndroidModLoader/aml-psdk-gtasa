#ifndef __AML_PSDK_SAOPCODECALLER_H
#define __AML_PSDK_SAOPCODECALLER_H

#include <aml-psdk/game_sa/engine/RunningScript.h>
#include "OpcodeCallerIDs.h"

struct ZeroArg {};

struct OpcodeCaller
{
    OpcodeCaller()
    {
        memset(&g_Script, 0, sizeof(g_Script));
        strcpy(g_Script.m_szName, "amlpsdk");
        g_Script.m_pBaseIP = g_Script.m_pCurrentIP = g_ScriptBuffer;
        
        // CRunningScript::Init
        g_Script.m_nScriptBrainType = -1;
        g_Script.m_bWastedBustedCheck = true;
    }

    static inline void PushVarToBuffer(ZeroArg)
    {
        g_ScriptBuffer[g_nBufferPos++] = 0x00;
    }
    static inline void PushVarToBuffer(int v)
    {
        g_ScriptBuffer[g_nBufferPos] = 0x01;
        memcpy(&g_ScriptBuffer[++g_nBufferPos], &v, 4);
        g_nBufferPos += 4;
    }
    static inline void PushVarToBuffer(float v)
    {
        g_ScriptBuffer[g_nBufferPos] = 0x06;
        memcpy(&g_ScriptBuffer[++g_nBufferPos], &v, 4);
        g_nBufferPos += 4;
    }
    static inline void PushVarToBuffer(double v)
    {
        float flt = (float)v;
        g_ScriptBuffer[g_nBufferPos] = 0x06;
        memcpy(&g_ScriptBuffer[++g_nBufferPos], &flt, 4);
        g_nBufferPos += 4;
    }
    static inline void PushVarToBuffer(const char* s)
    {
        unsigned char aLen = strlen(s);
        g_ScriptBuffer[g_nBufferPos] = 0x0E;
        g_ScriptBuffer[++g_nBufferPos] = aLen;
        memcpy(&g_ScriptBuffer[++g_nBufferPos], s, aLen);
        g_nBufferPos += aLen;
    }
    static inline void PushVarToBuffer(int *v)
    {
        g_ScriptBuffer[g_nBufferPos] = 0x03;
        g_ScriptVarPointers[g_nVarsCount] = (uint32_t*)v;
        g_Script.m_aLocalVars[g_nVarsCount].uParam = *(uint32_t*)v;
        memcpy(&g_ScriptBuffer[++g_nBufferPos], &g_nVarsCount, 2);
        g_nBufferPos += 2;
        ++g_nVarsCount;
    }
    static inline void PushVarToBuffer(unsigned int *v)
    {
        g_ScriptBuffer[g_nBufferPos] = 0x03;
        g_ScriptVarPointers[g_nVarsCount] = (uint32_t*)v;
        g_Script.m_aLocalVars[g_nVarsCount].uParam = *(uint32_t*)v;
        memcpy(&g_ScriptBuffer[++g_nBufferPos], &g_nVarsCount, 2);
        g_nBufferPos += 2;
        ++g_nVarsCount;
    }
    static inline void PushVarToBuffer(float *v)
    {
        g_ScriptBuffer[g_nBufferPos] = 0x03;
        g_ScriptVarPointers[g_nVarsCount] = (uint32_t*)v;
        g_Script.m_aLocalVars[g_nVarsCount].uParam = *(uint32_t*)v;
        memcpy(&g_ScriptBuffer[++g_nBufferPos], &g_nVarsCount, 2);
        g_nBufferPos += 2;
        ++g_nVarsCount;
    }

    static inline CRunningScript g_Script { 0 };
    static inline uint8_t g_ScriptBuffer[512] { 0 };
    static inline u32* g_ScriptVarPointers[40] { NULL };
    static inline uint16_t g_nBufferPos = 0;
    static inline uint8_t g_nVarsCount = 0;
};
inline OpcodeCaller g_OpcodeCallerStub;

template <typename T>
inline void PushVars(T arg)
{
    OpcodeCaller::PushVarToBuffer(arg);
}
template <typename A1, typename... Args>
inline void PushVars(A1 arg, Args... args)
{
    PushVars(arg);
    PushVars(args...);
}

template<typename... ArgTypes>
inline bool CommandByID(uint16_t opcode, ArgTypes... args)
{
    memcpy(OpcodeCaller::g_ScriptBuffer, &opcode, 2);
    OpcodeCaller::g_nBufferPos = 2;
    OpcodeCaller::g_nVarsCount = 0;
    PushVars(args...);

    OpcodeCaller::g_Script.ProcessOneCommand();
    if(OpcodeCaller::g_nVarsCount)
    {
        for(int i = 0; i < OpcodeCaller::g_nVarsCount; ++i)
        {
            *OpcodeCaller::g_ScriptVarPointers[i] = OpcodeCaller::g_Script.m_aLocalVars[i].uParam;
        }
    }
    return OpcodeCaller::g_Script.m_bCondResult;
}

template <uint16_t CommandID, typename... ArgTypes>
inline bool Command(ArgTypes... arguments)
{
    return CommandByID(CommandID, arguments...);
}

template <uint16_t CommandID>
inline bool Command()
{
    const uint16_t opcode = CommandID;
    memcpy(OpcodeCaller::g_ScriptBuffer, &opcode, 2);
    OpcodeCaller::g_Script.ProcessOneCommand();
    return OpcodeCaller::g_Script.m_bCondResult;
}

#endif // __AML_PSDK_SAOPCODECALLER_H