#ifndef __AML_PSDK_SAGAMELOGIC_H
#define __AML_PSDK_SAGAMELOGIC_H

#include <aml-psdk/renderware/RwMatrix.h>

struct CPlayerPed;
struct CPed;
struct CVehicle;
struct CWeapon;

DECL_CLASS(CGameLogic)
    // Functions
    DECL_FASTCALL_SIMPLE(InitAtStartOfGame, _ZN10CGameLogic17InitAtStartOfGameEv, void);
    DECL_FASTCALL_SIMPLE(ResetStuffUponResurrection, _ZN10CGameLogic26ResetStuffUponResurrectionEv, void);
    DECL_FASTCALL_SIMPLE(PassTime, _ZN10CGameLogic8PassTimeEj, void, u32 GameMinutes);
    DECL_FASTCALL_SIMPLE(RestorePlayerStuffDuringResurrection, _ZN10CGameLogic36RestorePlayerStuffDuringResurrectionEP10CPlayerPed7CVectorf, void, CPlayerPed *pPlayerPed, CVector NewCoors, float NewHeading);
    DECL_FASTCALL_SIMPLE(SortOutStreamingAndMemory, _ZN10CGameLogic25SortOutStreamingAndMemoryERK7CVectorf, void, CVector const &posn, float heading);
    DECL_FASTCALL_SIMPLE(Update, _ZN10CGameLogic6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(SetPlayerWantedLevelForForbiddenTerritories, _ZN10CGameLogic43SetPlayerWantedLevelForForbiddenTerritoriesEb, void, bool enable);
    DECL_FASTCALL_SIMPLE(IsCoopGameGoingOn, _ZN10CGameLogic17IsCoopGameGoingOnEv, bool);
    DECL_FASTCALL_SIMPLE(UpdateSkip, _ZN10CGameLogic10UpdateSkipEv, void);
    DECL_FASTCALL_SIMPLE(RestorePedsWeapons, _ZN10CGameLogic18RestorePedsWeaponsEP4CPed, void, CPed* pPed);
    DECL_FASTCALL_SIMPLE(Remove2ndPlayerIfPresent, _ZN10CGameLogic24Remove2ndPlayerIfPresentEv, void);
    DECL_FASTCALL_SIMPLE(StopPlayerMovingFromDirection, _ZN10CGameLogic29StopPlayerMovingFromDirectionEi7CVector, void, i32 Player, CVector VecToOther);
    DECL_FASTCALL_SIMPLE(ForceDeathRestart, _ZN10CGameLogic17ForceDeathRestartEv, void);
    DECL_FASTCALL_SIMPLE(IsPlayerAllowedToGoInThisDirection, _ZN10CGameLogic34IsPlayerAllowedToGoInThisDirectionEP10CPlayerPed7CVectorf, bool, CPlayerPed *pPlayerPed, CVector Dir, float fExtraDist);
    DECL_FASTCALL_SIMPLE(IsPlayerUse2PlayerControls, _ZN10CGameLogic26IsPlayerUse2PlayerControlsEP10CPlayerPed, bool, CPlayerPed *pPlayerPed);
    DECL_FASTCALL_SIMPLE(IsScriptCoopGameGoingOn, _ZN10CGameLogic23IsScriptCoopGameGoingOnEv, bool);
    DECL_FASTCALL_SIMPLE(Disable2ndControllerForDebug, _ZN10CGameLogic28Disable2ndControllerForDebugEv, bool);
    DECL_FASTCALL_SIMPLE(ClearSkip, _ZN10CGameLogic9ClearSkipEb, void, bool bLeaveAfterMission);
    DECL_FASTCALL_SIMPLE(SetUpSkip, _ZN10CGameLogic9SetUpSkipE7CVectorfbP8CVehicleb, void, CVector DestCoors, float DestOrientation, bool bAfterMission, CVehicle *pSpecificVehicle, bool bScriptToFinish);
    DECL_FASTCALL_SIMPLE(SkipCanBeActivated, _ZN10CGameLogic18SkipCanBeActivatedEv, bool);
    DECL_FASTCALL_SIMPLE(IsSkipWaitingForScriptToFadeIn, _ZN10CGameLogic30IsSkipWaitingForScriptToFadeInEv, bool);
    DECL_FASTCALL_SIMPLE(IsPointWithinLineArea, _ZN10CGameLogic21IsPointWithinLineAreaEP7CVectoriS0_, bool, CVector *pPointArray, i32 NumPoints, CVector TestPoint);
    DECL_FASTCALL_SIMPLE(CalcDistanceToForbiddenTrainCrossing, _ZN10CGameLogic36CalcDistanceToForbiddenTrainCrossingE7CVectorS0_bPS0_, float, CVector Point, CVector Forward, bool bIgnoreSpeed, CVector *pVecToBarrier);
    DECL_FASTCALL_SIMPLE(FindCityClosestToPoint, _ZN10CGameLogic22FindCityClosestToPointE7CVector, i32);
    DECL_FASTCALL_SIMPLE(LaRiotsActiveHere, _ZN10CGameLogic17LaRiotsActiveHereEv, bool);
    DECL_FASTCALL_SIMPLE(DoWeaponStuffAtStartOf2PlayerGame, _ZN10CGameLogic33DoWeaponStuffAtStartOf2PlayerGameEb, void, bool bGivePlayer2Weapons);
    DECL_FASTCALL_SIMPLE(StorePedsWeapons, _ZN10CGameLogic16StorePedsWeaponsEP4CPed, void, CPed *pPed);
    DECL_FASTCALL_SIMPLE(Save, _ZN10CGameLogic4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN10CGameLogic4LoadEv, bool);

    // STATIC Values
    DECL_VALUE_PLT_BOOL(bPenaltyForDeathApplies, BYBIT(0x6784DC, 0x84E9D0));
    DECL_VALUE_PLT_BOOL(bPenaltyForArrestApplies, BYBIT(0x676294, 0x84A588));
    DECL_VALUE_PLT_BOOL(bLimitPlayerDistance, BYBIT(0x678864, 0x84F0E8));
    DECL_VALUE_PLT_BOOL(MaxPlayerDistance, BYBIT(0x679A60, 0x8514E0));
    DECL_VALUE_PLT_U32(n2PlayerPedInFocus, BYBIT(0x677DF0, 0x84DC00));
    DECL_VALUE_PLT_U8(ActivePlayers, BYBIT(0x679208, 0x850430));
    DECL_VALUE_PLT_U8(GameState, BYBIT(0x676008, 0x84A080));
    DECL_VALUE_PLT_U32(TimeOfLastEvent, BYBIT(0x6789E4, 0x84F3E8));
    DECL_VALUE_PLT_BOOL(bScriptCoopGameGoingOn, BYBIT(0x676EE8, 0x84BE10));
    DECL_OBJECT_PLT(CVector, SkipDestination, BYBIT(0x67944C, 0x8508B0));
    DECL_VALUE_PLT_FLT(SkipDestinationOrientation, BYBIT(0x677A90, 0x84D548));
    DECL_VALUE_PLT_I32(SkipState, BYBIT(0x676ED0, 0x84BDE0));
    DECL_VALUE_PLT_U32(SkipTimer, BYBIT(0x678634, 0x84EC90));
    DECL_OBJECT_PLT(CVehicle*, SkipVehicle, BYBIT(0x6776C8, 0x84CDC0));
    DECL_VALUE_PLT_BOOL(SkipToBeFinishedByScript, BYBIT(0x67752C, 0x84CA90));
    DECL_VALUE_PLT_I32(NumAfterDeathStartPoints, BYBIT(0x675ED8, 0x849E20));
    DECL_OBJECT_PLT(CVector*, AfterDeathStartPoints, BYBIT(0x6789B0, 0x84F380));
    DECL_OBJECT_PLT(float*, AfterDeathStartPointOrientations, BYBIT(0x6764B4, 0x84A9C0));
    DECL_VALUE_PLT_BOOL(bPlayersCannotTargetEachother, BYBIT(0x678A90, 0x84F548));
    DECL_VALUE_PLT_BOOL(bPlayersCanBeInSeparateCars, BYBIT(0x676874, 0x84B140));
    DECL_OBJECT_PLT(CVector, vec2PlayerStartLocation, BYBIT(0x678D70, 0x84FB08));
    DECL_VALUE_PLT_FLT(f2PlayerStartHeading, BYBIT(0x67804C, 0x84E0B8));
    DECL_VALUE_PLT_U32(nPrintFocusHelpTimer, BYBIT(0x678F84, 0x84FF30));
    DECL_VALUE_PLT_U32(nPrintFocusHelpCounter, BYBIT(0x678E9C, 0x84FD60));
    DECL_OBJECT_PLT(CWeapon*, SavedWeaponSlots, BYBIT(0x676864, 0x84B120));
DECL_CLASS_END()

#define bPenaltyForDeathApplies bPenaltyForDeathApplies()
#define bPenaltyForArrestApplies bPenaltyForArrestApplies()
#define bLimitPlayerDistance bLimitPlayerDistance()
#define MaxPlayerDistance MaxPlayerDistance()
#define n2PlayerPedInFocus n2PlayerPedInFocus()
#define ActivePlayers ActivePlayers()
#define GameState GameState()
#define TimeOfLastEvent TimeOfLastEvent()
#define bScriptCoopGameGoingOn bScriptCoopGameGoingOn()
#define SkipDestination SkipDestination()
#define SkipDestinationOrientation SkipDestinationOrientation()
#define SkipState SkipState()
#define SkipTimer SkipTimer()
#define SkipVehicle SkipVehicle()
#define SkipToBeFinishedByScript SkipToBeFinishedByScript()
#define NumAfterDeathStartPoints NumAfterDeathStartPoints()
#define AfterDeathStartPoints AfterDeathStartPoints()
#define AfterDeathStartPointOrientations AfterDeathStartPointOrientations()
#define bPlayersCannotTargetEachother bPlayersCannotTargetEachother()
#define bPlayersCanBeInSeparateCars bPlayersCanBeInSeparateCars()
#define vec2PlayerStartLocation vec2PlayerStartLocation()
#define f2PlayerStartHeading f2PlayerStartHeading()
#define nPrintFocusHelpTimer nPrintFocusHelpTimer()
#define nPrintFocusHelpCounter nPrintFocusHelpCounter()
#define SavedWeaponSlots SavedWeaponSlots()

#endif // __AML_PSDK_SAGAMELOGIC_H