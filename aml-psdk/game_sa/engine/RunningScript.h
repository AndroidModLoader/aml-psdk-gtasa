#ifndef __AML_PSDK_SARUNNINGSCRIPT_H
#define __AML_PSDK_SARUNNINGSCRIPT_H

#include <aml-psdk/game_sa/plugin.h>

struct CPed;
struct CTask;

enum eScriptParameterType
{
    SCRIPTPARAM_END_OF_ARGUMENTS,
    SCRIPTPARAM_STATIC_INT_32BITS,
    SCRIPTPARAM_GLOBAL_NUMBER_VARIABLE,
    SCRIPTPARAM_LOCAL_NUMBER_VARIABLE,
    SCRIPTPARAM_STATIC_INT_8BITS,
    SCRIPTPARAM_STATIC_INT_16BITS,
    SCRIPTPARAM_STATIC_FLOAT,
    SCRIPTPARAM_GLOBAL_NUMBER_ARRAY,
    SCRIPTPARAM_LOCAL_NUMBER_ARRAY,
    SCRIPTPARAM_STATIC_SHORT_STRING,
    SCRIPTPARAM_GLOBAL_SHORT_STRING_VARIABLE,
    SCRIPTPARAM_LOCAL_SHORT_STRING_VARIABLE,
    SCRIPTPARAM_GLOBAL_SHORT_STRING_ARRAY,
    SCRIPTPARAM_LOCAL_SHORT_STRING_ARRAY,
    SCRIPTPARAM_STATIC_PASCAL_STRING,
    SCRIPTPARAM_STATIC_LONG_STRING,
    SCRIPTPARAM_GLOBAL_LONG_STRING_VARIABLE,
    SCRIPTPARAM_LOCAL_LONG_STRING_VARIABLE,
    SCRIPTPARAM_GLOBAL_LONG_STRING_ARRAY,
    SCRIPTPARAM_LOCAL_LONG_STRING_ARRAY,
};

enum eButtonID
{
    BUTTON_LEFT_STICK_X,
    BUTTON_LEFT_STICK_Y,
    BUTTON_RIGHT_STICK_X,
    BUTTON_RIGHT_STICK_Y,
    BUTTON_LEFT_SHOULDER1,
    BUTTON_LEFT_SHOULDER2,
    BUTTON_RIGHT_SHOULDER1,
    BUTTON_RIGHT_SHOULDER2,
    BUTTON_DPAD_UP,
    BUTTON_DPAD_DOWN,
    BUTTON_DPAD_LEFT,
    BUTTON_DPAD_RIGHT,
    BUTTON_START,
    BUTTON_SELECT,
    BUTTON_SQUARE,
    BUTTON_TRIANGLE,
    BUTTON_CROSS,
    BUTTON_CIRCLE,
    BUTTON_LEFTSHOCK,
    BUTTON_RIGHTSHOCK,
};

union tScriptParam
{
    unsigned int uParam;
    int iParam;
    float fParam;
    B32MACRO( void *pParam; ) // only possible on 32-bit version.
    B32MACRO( char *szParam; ) // only possible on 32-bit version.
};

DECL_CLASS(CRunningScript)
    // Member functions
    DECL_THISCALL_SIMPLE(CanAllowMissionReplay, _ZN14CRunningScript21CanAllowMissionReplayEv, bool);
    DECL_THISCALL_SIMPLE(CollectNextParameterWithoutIncreasingPC, _ZN14CRunningScript39CollectNextParameterWithoutIncreasingPCEv, int);
    DECL_THISCALL_SIMPLE(GetIndexOfGlobalVariable, _ZN14CRunningScript24GetIndexOfGlobalVariableEv, u16);
    DECL_THISCALL_SIMPLE(Init, _ZN14CRunningScript4InitEv, void);
    DECL_THISCALL_SIMPLE(ShutdownThisScript, _ZN14CRunningScript18ShutdownThisScriptEv, void);
    DECL_THISCALL_SIMPLE(Process, _ZN14CRunningScript7ProcessEv, u8);
    DECL_THISCALL_SIMPLE(ProcessOneCommand, _ZN14CRunningScript17ProcessOneCommandEv, i8);
    DECL_THISCALL_SIMPLE(DoDeatharrestCheck, _ZN14CRunningScript18DoDeatharrestCheckEv, void);

    DECL_THISCALL_HEAD(GetPointerToLocalVariable, _ZN14CRunningScript25GetPointerToLocalVariableEj, void*, u32 VarIndex)
    DECL_THISCALL_TAIL(GetPointerToLocalVariable, VarIndex)

    DECL_THISCALL_HEAD(GetPointerToLocalArrayElement, _ZN14CRunningScript29GetPointerToLocalArrayElementEjth, void*, u32 BaseAddress, u16 ElementNumber, u8 SizeOfEachElement)
    DECL_THISCALL_TAIL(GetPointerToLocalArrayElement, BaseAddress, ElementNumber, SizeOfEachElement)

    DECL_THISCALL_HEAD(ReadArrayInformation, _ZN14CRunningScript20ReadArrayInformationEiPtPi, void, i32 bUpdatePC, u16 *pReturnArrayBaseAddress, i32 *pReturnArrayIndex)
    DECL_THISCALL_TAIL(ReadArrayInformation, bUpdatePC, pReturnArrayBaseAddress, pReturnArrayIndex)

    DECL_THISCALL_HEAD(ReadTextLabelFromScript, _ZN14CRunningScript23ReadTextLabelFromScriptEPch, void, char *pStringToFill, u8 MaxStringLength)
    DECL_THISCALL_TAIL(ReadTextLabelFromScript, pStringToFill, MaxStringLength)

    DECL_THISCALL_HEAD(CollectParameters, _ZN14CRunningScript17CollectParametersEs, void, i16 number)
    DECL_THISCALL_TAIL(CollectParameters, number)

    DECL_THISCALL_HEAD(StoreParameters, _ZN14CRunningScript15StoreParametersEs, void, i16 number)
    DECL_THISCALL_TAIL(StoreParameters, number)

    DECL_THISCALL_HEAD(ReadParametersForNewlyStartedScript, _ZN14CRunningScript35ReadParametersForNewlyStartedScriptEPS_, void, CRunningScript *pNewScript)
    DECL_THISCALL_TAIL(ReadParametersForNewlyStartedScript, pNewScript)

    DECL_THISCALL_HEAD(GetPointerToScriptVariable, _ZN14CRunningScript26GetPointerToScriptVariableEh, tScriptParam*, unsigned char variableType)
    DECL_THISCALL_TAIL(GetPointerToScriptVariable, variableType)

    DECL_THISCALL_HEAD(AddScriptToList, _ZN14CRunningScript15AddScriptToListEPPS_, void, CRunningScript **ppList)
    DECL_THISCALL_TAIL(AddScriptToList, ppList)

    DECL_THISCALL_HEAD(RemoveScriptFromList, _ZN14CRunningScript20RemoveScriptFromListEPPS_, void, CRunningScript **ppList)
    DECL_THISCALL_TAIL(RemoveScriptFromList, ppList)

    DECL_THISCALL_HEAD(IsPedDead, _ZN14CRunningScript9IsPedDeadEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(IsPedDead, pPed)

    DECL_THISCALL_HEAD(GivePedScriptedTask, _ZN14CRunningScript19GivePedScriptedTaskEiP5CTaski, void, i32 iPedID, CTask *pTask, i32 CurrCommand)
    DECL_THISCALL_TAIL(GivePedScriptedTask, iPedID, pTask, CurrCommand)

    DECL_THISCALL_HEAD(UpdatePC, _ZN14CRunningScript8UpdatePCEi, void, i32 newPC)
    DECL_THISCALL_TAIL(UpdatePC, newPC)

    DECL_THISCALL_HEAD(GetCorrectPedModelIndexForEmergencyServiceType, _ZN14CRunningScript46GetCorrectPedModelIndexForEmergencyServiceTypeEiPi, void, i32 PedType, i32 *pPedModelIndex)
    DECL_THISCALL_TAIL(GetCorrectPedModelIndexForEmergencyServiceType, PedType, pPedModelIndex)

    DECL_THISCALL_HEAD(SetCharCoordinates, _ZN14CRunningScript18SetCharCoordinatesEP4CPedfffbb, void, CPed *pPed, float NewX, float NewY, float NewZ, bool bWarpGang, bool bOffset)
    DECL_THISCALL_TAIL(SetCharCoordinates, pPed, NewX, NewY, NewZ, bWarpGang, bOffset)

    DECL_THISCALL_HEAD(ScriptTaskPickUpObject, _ZN14CRunningScript22ScriptTaskPickUpObjectEi, void, i32 CurrCommand)
    DECL_THISCALL_TAIL(ScriptTaskPickUpObject, CurrCommand)

    DECL_THISCALL_HEAD(PlayAnimScriptCommand, _ZN14CRunningScript21PlayAnimScriptCommandEi, void, i32 CurrCommand)
    DECL_THISCALL_TAIL(PlayAnimScriptCommand, CurrCommand)

    DECL_THISCALL_HEAD(UpdateCompareFlag, _ZN14CRunningScript17UpdateCompareFlagEh, void, u8 result)
    DECL_THISCALL_TAIL(UpdateCompareFlag, result)

    DECL_THISCALL_HEAD(LocateCharCommand, _ZN14CRunningScript17LocateCharCommandEi, void, i32 CurrCommand)
    DECL_THISCALL_TAIL(LocateCharCommand, CurrCommand)

    DECL_THISCALL_HEAD(LocateCharCharCommand, _ZN14CRunningScript21LocateCharCharCommandEi, void, i32 CurrCommand)
    DECL_THISCALL_TAIL(LocateCharCharCommand, CurrCommand)

    DECL_THISCALL_HEAD(LocateCharCarCommand, _ZN14CRunningScript20LocateCharCarCommandEi, void, i32 CurrCommand)
    DECL_THISCALL_TAIL(LocateCharCarCommand, CurrCommand)

    DECL_THISCALL_HEAD(LocateCharObjectCommand, _ZN14CRunningScript23LocateCharObjectCommandEi, void, i32 CurrCommand)
    DECL_THISCALL_TAIL(LocateCharObjectCommand, CurrCommand)

    DECL_THISCALL_HEAD(LocateCarCommand, _ZN14CRunningScript16LocateCarCommandEi, void, i32 CurrCommand)
    DECL_THISCALL_TAIL(LocateCarCommand, CurrCommand)

    DECL_THISCALL_HEAD(LocateObjectCommand, _ZN14CRunningScript19LocateObjectCommandEi, void, i32 CurrCommand)
    DECL_THISCALL_TAIL(LocateObjectCommand, CurrCommand)

    DECL_THISCALL_HEAD(CharInAngledAreaCheckCommand, _ZN14CRunningScript28CharInAngledAreaCheckCommandEi, void, i32 CurrCommand)
    DECL_THISCALL_TAIL(CharInAngledAreaCheckCommand, CurrCommand)

    DECL_THISCALL_HEAD(ObjectInAngledAreaCheckCommand, _ZN14CRunningScript30ObjectInAngledAreaCheckCommandEi, void, i32 CurrCommand)
    DECL_THISCALL_TAIL(ObjectInAngledAreaCheckCommand, CurrCommand)

    DECL_THISCALL_HEAD(FlameInAngledAreaCheckCommand, _ZN14CRunningScript29FlameInAngledAreaCheckCommandEi, void, i32 CurrCommand)
    DECL_THISCALL_TAIL(FlameInAngledAreaCheckCommand, CurrCommand)

    DECL_THISCALL_HEAD(CharInAreaCheckCommand, _ZN14CRunningScript22CharInAreaCheckCommandEi, void, i32 CurrCommand)
    DECL_THISCALL_TAIL(CharInAreaCheckCommand, CurrCommand)

    DECL_THISCALL_HEAD(CarInAreaCheckCommand, _ZN14CRunningScript21CarInAreaCheckCommandEi, void, i32 CurrCommand)
    DECL_THISCALL_TAIL(CarInAreaCheckCommand, CurrCommand)

    DECL_THISCALL_HEAD(ObjectInAreaCheckCommand, _ZN14CRunningScript24ObjectInAreaCheckCommandEi, void, i32 CurrCommand)
    DECL_THISCALL_TAIL(ObjectInAreaCheckCommand, CurrCommand)

    DECL_THISCALL_HEAD(GetPadState, _ZN14CRunningScript11GetPadStateEtt, i16, u16 PadNumber, u16 ButtonNumber)
    DECL_THISCALL_TAIL(GetPadState, PadNumber, ButtonNumber)

    DECL_THISCALL_HEAD(ThisIsAValidRandomCop, _ZN14CRunningScript21ThisIsAValidRandomCopEjiiiii, bool, u32 PedModelIndex, i32 CopFlag, i32 SwatFlag, i32 FBIFlag, i32 ArmyFlag, i32 MiamiViceFlag)
    DECL_THISCALL_TAIL(ThisIsAValidRandomCop, PedModelIndex, CopFlag, SwatFlag, FBIFlag, ArmyFlag, MiamiViceFlag)

    DECL_THISCALL_HEAD(ThisIsAValidRandomPed, _ZN14CRunningScript21ThisIsAValidRandomPedEjiii, bool, u32 PedType, i32 CivilianFlag, i32 GangFlag, i32 CriminalFlag)
    DECL_THISCALL_TAIL(ThisIsAValidRandomPed, PedType, CivilianFlag, GangFlag, CriminalFlag)

    DECL_THISCALL_HEAD(ProcessCommands0To99, _ZN14CRunningScript20ProcessCommands0To99Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands0To99, commandID)

    DECL_THISCALL_HEAD(ProcessCommands100To199, _ZN14CRunningScript23ProcessCommands100To199Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands100To199, commandID)

    DECL_THISCALL_HEAD(ProcessCommands200To299, _ZN14CRunningScript23ProcessCommands200To299Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands200To299, commandID)

    DECL_THISCALL_HEAD(ProcessCommands300To399, _ZN14CRunningScript23ProcessCommands300To399Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands300To399, commandID)

    DECL_THISCALL_HEAD(ProcessCommands400To499, _ZN14CRunningScript23ProcessCommands400To499Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands400To499, commandID)

    DECL_THISCALL_HEAD(ProcessCommands500To599, _ZN14CRunningScript23ProcessCommands500To599Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands500To599, commandID)

    DECL_THISCALL_HEAD(ProcessCommands600To699, _ZN14CRunningScript23ProcessCommands600To699Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands600To699, commandID)

    DECL_THISCALL_HEAD(ProcessCommands700To799, _ZN14CRunningScript23ProcessCommands700To799Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands700To799, commandID)

    DECL_THISCALL_HEAD(ProcessCommands800To899, _ZN14CRunningScript23ProcessCommands800To899Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands800To899, commandID)

    DECL_THISCALL_HEAD(ProcessCommands900To999, _ZN14CRunningScript23ProcessCommands900To999Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands900To999, commandID)

    DECL_THISCALL_HEAD(ProcessCommands1000To1099, _ZN14CRunningScript25ProcessCommands1000To1099Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands1000To1099, commandID)

    DECL_THISCALL_HEAD(ProcessCommands1100To1199, _ZN14CRunningScript25ProcessCommands1100To1199Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands1100To1199, commandID)

    DECL_THISCALL_HEAD(ProcessCommands1200To1299, _ZN14CRunningScript25ProcessCommands1200To1299Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands1200To1299, commandID)

    DECL_THISCALL_HEAD(ProcessCommands1300To1399, _ZN14CRunningScript25ProcessCommands1300To1399Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands1300To1399, commandID)

    DECL_THISCALL_HEAD(ProcessCommands1400To1499, _ZN14CRunningScript25ProcessCommands1400To1499Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands1400To1499, commandID)

    DECL_THISCALL_HEAD(ProcessCommands1500To1599, _ZN14CRunningScript25ProcessCommands1500To1599Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands1500To1599, commandID)

    DECL_THISCALL_HEAD(ProcessCommands1600To1699, _ZN14CRunningScript25ProcessCommands1600To1699Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands1600To1699, commandID)

    DECL_THISCALL_HEAD(ProcessCommands1700To1799, _ZN14CRunningScript25ProcessCommands1700To1799Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands1700To1799, commandID)

    DECL_THISCALL_HEAD(ProcessCommands1800To1899, _ZN14CRunningScript25ProcessCommands1800To1899Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands1800To1899, commandID)

    DECL_THISCALL_HEAD(ProcessCommands1900To1999, _ZN14CRunningScript25ProcessCommands1900To1999Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands1900To1999, commandID)

    DECL_THISCALL_HEAD(ProcessCommands2000To2099, _ZN14CRunningScript25ProcessCommands2000To2099Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands2000To2099, commandID)

    DECL_THISCALL_HEAD(ProcessCommands2100To2199, _ZN14CRunningScript25ProcessCommands2100To2199Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands2100To2199, commandID)

    DECL_THISCALL_HEAD(ProcessCommands2200To2299, _ZN14CRunningScript25ProcessCommands2200To2299Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands2200To2299, commandID)

    DECL_THISCALL_HEAD(ProcessCommands2300To2399, _ZN14CRunningScript25ProcessCommands2300To2399Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands2300To2399, commandID)

    DECL_THISCALL_HEAD(ProcessCommands2400To2499, _ZN14CRunningScript25ProcessCommands2400To2499Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands2400To2499, commandID)

    DECL_THISCALL_HEAD(ProcessCommands2500To2599, _ZN14CRunningScript25ProcessCommands2500To2599Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands2500To2599, commandID)

    DECL_THISCALL_HEAD(ProcessCommands2600To2699, _ZN14CRunningScript25ProcessCommands2600To2699Ei, i8, int commandID)
    DECL_THISCALL_TAIL(ProcessCommands2600To2699, commandID)

    // Member values
    CRunningScript *m_pNext;
    CRunningScript *m_pPrev;
    char            m_szName[8];
    unsigned char  *m_pBaseIP;
    unsigned char  *m_pCurrentIP;
    unsigned char  *m_apStack[8];
    unsigned short  m_nSP;
    tScriptParam    m_aLocalVars[40];
    int             m_anTimers[2];
    bool            m_bIsActive;
    bool            m_bCondResult;
    bool            m_bUseMissionCleanup;
    bool            m_bIsExternal;
    bool            m_bTextBlockOverride;
    char            m_nScriptBrainType; // missing on PC
    int             m_nWakeTime;
    unsigned short  m_nLogicalOp;
    bool            m_bNotFlag;
    bool            m_bWastedBustedCheck;
    bool            m_bWastedOrBusted;
    int             m_pSceneSkipIP; // not a pointer!
    bool            m_bIsMission;
DECL_CLASS_END()
CHECKSIZE(CRunningScript, 0x100, 0x130);

#endif // __AML_PSDK_SARUNNINGSCRIPT_H