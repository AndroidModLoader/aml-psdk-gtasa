#ifndef __AML_PSDK_SASTATS_H
#define __AML_PSDK_SASTATS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/GxtChar.h>

struct CBmx;
struct CVehicle;
struct CBike;

enum eStatUpdateState
{
    STAT_UPDATE_DECREASE = 0,
    STAT_UPDATE_INCREASE = 1
};

enum eStatMessageCondition
{
    STATMESSAGE_LESSTHAN = 0,
    STATMESSAGE_MORETHAN = 1
};

enum eStatModAbilities
{
    STAT_MOD_0 = 0,
    STAT_MOD_1 = 1,
    STAT_MOD_2 = 2,
    STAT_MOD_3 = 3,
    STAT_MOD_4 = 4,
    STAT_MOD_5 = 5,
    STAT_MOD_6 = 6,
    STAT_MOD_TIME_CAN_RUN = 7,
    STAT_MOD_AIR_IN_LUNG = 8,
    STAT_MOD_MAX_HEALTH = 9,
    STAT_MOD_10 = 10,
    STAT_MOD_11 = 11,
    STAT_MOD_12 = 12,
    STAT_MOD_13 = 13,
    STAT_MOD_14 = 14,
    STAT_MOD_15 = 15
};

enum eStatsReactions
{
    STAT_INC_CYCLE_STAMINA = 0,
    STAT_INC_SWIM_STAMINA = 1,
    STAT_INC_SPRINT_STAMINA = 2,
    STAT_INC_RUNNING = 3,
    STAT_INC_DRIVING_SKILL = 4,
    STAT_INC_FLYING_SKILL = 5,
    STAT_INC_CYCLE_SKILL = 6,
    STAT_INC_MOTORBIKE_SKILL = 7,
    STAT_INC_BOAT_SKILL = 8,
    STAT_INC_BODY_MUSCLE = 9,
    STAT_INC_BREATH_UNDERWATER = 10,
    STAT_INC_MAX_HEALTH = 11,
    STAT_INC_PISTOL_SKILL = 12,
    STAT_INC_PISTOL_SILENCED_SKILL = 13,
    STAT_INC_DESERT_EAGLE_SKILL = 14,
    STAT_INC_SHOTGUN_SKILL = 15,
    STAT_INC_SAWNOFF_SHOTGUN_SKILL = 16,
    STAT_INC_SPAS12_SHOTGUN_SKILL = 17,
    STAT_INC_MICRO_UZI_SKILL = 18,
    STAT_INC_MP5_SKILL = 19,
    STAT_INC_AK47_SKILL = 20,
    STAT_INC_M4_SKILL = 21,
    STAT_INC_SNIPERRIFLE_SKILL = 22,
    STAT_DEC_FAT = 23,
    STAT_DEC_BODY_MUSCLE = 24,
    STAT_DEC_MAX_HEALTH = 25,
    STAT_EXERCISE_RATE_CYCLE = 26,
    STAT_EXERCISE_RATE_CYCLE_SPRINT = 27,
    STAT_EXERCISE_RATE_SWIM = 28,
    STAT_EXERCISE_RATE_SWIM_SPRINT = 29,
    STAT_EXERCISE_RATE_SPRINT = 30,
    STAT_EXERCISE_RATE_RUN = 31,
    STAT_EXERCISE_RATE_FIGHT = 32,
    STAT_TIMELIMIT_CYCLE_STAMINA = 33,
    STAT_TIMELIMIT_SWIM_STAMINA = 34,
    STAT_TIMELIMIT_SPRINT_STAMINA = 35,
    STAT_TIMELIMIT_RUNNING = 36,
    STAT_TIMELIMIT_DRIVING_SKILL = 37,
    STAT_TIMELIMIT_FLYING_SKILL = 38,
    STAT_TIMELIMIT_CYCLE_SKILL = 39,
    STAT_TIMELIMIT_MOTORBIKE_SKILL = 40,
    STAT_TIMELIMIT_BOAT_SKILL = 41,
    STAT_TIMELIMIT_FAT_ADJUST = 42,
    STAT_TIMELIMIT_FAT_ADJUST_STRENUOUS = 43,
    STAT_TIMELIMIT_BREATH_UNDERWATER = 44,
    STAT_TIMELIMIT_MAX_HEALTH = 45,
    STAT_TIMELIMIT_PISTOL_SKILL = 46,
    STAT_TIMELIMIT_PISTOL_SILENCED_SKILL = 47,
    STAT_TIMELIMIT_DESERT_EAGLE_SKILL = 48,
    STAT_TIMELIMIT_SHOTGUN_SKILL = 49,
    STAT_TIMELIMIT_SAWNOFF_SHOTGUN_SKILL = 50,
    STAT_TIMELIMIT_SPAS12_SHOTGUN_SKILL = 51,
    STAT_TIMELIMIT_MICRO_UZI_SKILL = 52,
    STAT_TIMELIMIT_MP5_SKILL = 53,
    STAT_TIMELIMIT_AK47_SKILL = 54,
    STAT_TIMELIMIT_M4_SKILL = 55,
    STAT_TIMELIMIT_SNIPERRIFLE_SKILL = 56,
    STAT_TIMELIMIT_DEATH_HEALTH = 57,
    STAT_TIMELIMIT_ADD_TO_HEALTH = 58
};

DECL_CLASS(CStats)
    // STATIC values

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN6CStats4InitEv, void);
    DECL_FASTCALL_SIMPLE(CheckForStatsMessage, _ZN6CStats20CheckForStatsMessageEb, void, bool bInitialize);
    DECL_FASTCALL_SIMPLE(SetStatValue, _ZN6CStats12SetStatValueEtf, void, u16 index, float NewValue);
    DECL_FASTCALL_SIMPLE(PopulateFavoriteRadioStationList, _ZN6CStats32PopulateFavoriteRadioStationListEv, u8);
    DECL_FASTCALL_SIMPLE(LoadActionReactionStats, _ZN6CStats23LoadActionReactionStatsEv, void);
    DECL_FASTCALL_SIMPLE(LoadStatUpdateConditions, _ZN6CStats24LoadStatUpdateConditionsEv, void);
    DECL_FASTCALL_SIMPLE(GetStatID, _ZN6CStats9GetStatIDEt, const char*, u16 index);
    DECL_FASTCALL_SIMPLE(GetStatType, _ZN6CStats11GetStatTypeEt, u8, u16 index);
    DECL_FASTCALL_SIMPLE(GetStatValue, _ZN6CStats12GetStatValueEt, float, u16 index);
    DECL_FASTCALL_SIMPLE(ModifyStat, _ZN6CStats10ModifyStatEtf, void, u16 index, float amount);
    DECL_FASTCALL_SIMPLE(IncrementStat, _ZN6CStats13IncrementStatEtf, void, u16 index, float amount);
    DECL_FASTCALL_SIMPLE(DecrementStat, _ZN6CStats13DecrementStatEtf, void, u16 index, float amount);
    DECL_FASTCALL_SIMPLE(IsStatCapped, _ZN6CStats12IsStatCappedEt, u8);
    DECL_FASTCALL_SIMPLE(UpdateStatsAddToHealth, _ZN6CStats22UpdateStatsAddToHealthEj, void, u32 nAdd);
    DECL_FASTCALL_SIMPLE(ProcessReactionStatsOnIncrement, _ZN6CStats31ProcessReactionStatsOnIncrementEh, void, u8 index);
    DECL_FASTCALL_SIMPLE(ProcessReactionStatsOnDecrement, _ZN6CStats31ProcessReactionStatsOnDecrementEh, void, u8 index);
    DECL_FASTCALL_SIMPLE(SetNewRecordStat, _ZN6CStats16SetNewRecordStatEtf, void, u16 index, float NewLevel);
    DECL_FASTCALL_SIMPLE(GetTimesMissionAttempted, _ZN6CStats24GetTimesMissionAttemptedEh, u8, u8 MissionNumber);
    DECL_FASTCALL_SIMPLE(RegisterMissionPassed, _ZN6CStats21RegisterMissionPassedEh, void, u8 MissionNumber);
    DECL_FASTCALL_SIMPLE(RegisterFastestTime, _ZN6CStats19RegisterFastestTimeEii, void, i32 StatIndex, i32 NewTime);
    DECL_FASTCALL_SIMPLE(RegisterBestPosition, _ZN6CStats20RegisterBestPositionEii, void, i32 StatIndex, i32 NewPosition);
    DECL_FASTCALL_SIMPLE(GetFavoriteRadioStationList, _ZN6CStats27GetFavoriteRadioStationListEi, float, i32 station);
    DECL_FASTCALL_SIMPLE(GetFullFavoriteRadioStationList, _ZN6CStats31GetFullFavoriteRadioStationListEv, i32*);
    DECL_FASTCALL_SIMPLE(FindMostFavoriteRadioStation, _ZN6CStats28FindMostFavoriteRadioStationEv, i32);
    DECL_FASTCALL_SIMPLE(FindLeastFavoriteRadioStation, _ZN6CStats29FindLeastFavoriteRadioStationEv, i32);
    DECL_FASTCALL_SIMPLE(FindCriminalRatingString, _ZN6CStats24FindCriminalRatingStringEv, GxtChar*);
    DECL_FASTCALL_SIMPLE(FindCriminalRatingNumber, _ZN6CStats24FindCriminalRatingNumberEv, i32);
    DECL_FASTCALL_SIMPLE(GetPercentageProgress, _ZN6CStats21GetPercentageProgressEv, float);
    DECL_FASTCALL_SIMPLE(ConstructStatLine, _ZN6CStats17ConstructStatLineEih, i32, i32 LineID, u8 CurrentCategory);
    DECL_FASTCALL_SIMPLE(SafeToShowThisStat, _ZN6CStats18SafeToShowThisStatEh, u8, u8 index);
    DECL_FASTCALL_SIMPLE(BuildStatLine, _ZN6CStats13BuildStatLineEPcPviS1_i, void, char *TEXT, void *NumberPtr, i32 bNumberIsFloat, void *NumberPtr2, i32 Type);
    DECL_FASTCALL_SIMPLE(ConvertToMins, _ZN6CStats13ConvertToMinsEi, i32, i32 TimeInSecs);
    DECL_FASTCALL_SIMPLE(ConvertToSecs, _ZN6CStats13ConvertToSecsEi, i32, i32 TimeInSecs);
    DECL_FASTCALL_SIMPLE(CheckForThreshold, _ZN6CStats17CheckForThresholdEPff, u8, float *stored_value, float new_value);
    DECL_FASTCALL_SIMPLE(DisplayScriptStatUpdateMessage, _ZN6CStats30DisplayScriptStatUpdateMessageEhjf, void, u8 IncOrDec, u32 StatIndex, float fValue);
    DECL_FASTCALL_SIMPLE(FindMaxNumberOfGroupMembers, _ZN6CStats27FindMaxNumberOfGroupMembersEv, i32);
    DECL_FASTCALL_SIMPLE(UpdateRespectStat, _ZN6CStats17UpdateRespectStatEh, void, u8 reset);
    DECL_FASTCALL_SIMPLE(UpdateSexAppealStat, _ZN6CStats19UpdateSexAppealStatEv, void);
    DECL_FASTCALL_SIMPLE(UpdateFatAndMuscleStats, _ZN6CStats23UpdateFatAndMuscleStatsEj, void, u32 nExerciseRate);
    DECL_FASTCALL_SIMPLE(UpdateStatsWhenSprinting, _ZN6CStats24UpdateStatsWhenSprintingEv, void);
    DECL_FASTCALL_SIMPLE(UpdateStatsWhenRunning, _ZN6CStats22UpdateStatsWhenRunningEv, void);
    DECL_FASTCALL_SIMPLE(UpdateStatsWhenCycling, _ZN6CStats22UpdateStatsWhenCyclingEbP4CBmx, void, bool bSprinting, CBmx *pBmx);
    DECL_FASTCALL_SIMPLE(UpdateStatsWhenSwimming, _ZN6CStats23UpdateStatsWhenSwimmingEbb, void, bool bUnderWater, bool bSprinting);
    DECL_FASTCALL_SIMPLE(UpdateStatsWhenDriving, _ZN6CStats22UpdateStatsWhenDrivingEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(UpdateStatsWhenFlying, _ZN6CStats21UpdateStatsWhenFlyingEP8CVehicle, void, CVehicle *pVehicle);
    DECL_FASTCALL_SIMPLE(UpdateStatsWhenOnMotorBike, _ZN6CStats26UpdateStatsWhenOnMotorBikeEP5CBike, void, CBike* pBike);
    DECL_FASTCALL_SIMPLE(UpdateStatsWhenWeaponHit, _ZN6CStats24UpdateStatsWhenWeaponHitEi, void, i32 nWeaponHit);
    DECL_FASTCALL_SIMPLE(UpdateStatsWhenFighting, _ZN6CStats23UpdateStatsWhenFightingEv, void);
    DECL_FASTCALL_SIMPLE(UpdateStatsOnRespawn, _ZN6CStats20UpdateStatsOnRespawnEv, void);
    DECL_FASTCALL_SIMPLE(GetFatAndMuscleModifier, _ZN6CStats23GetFatAndMuscleModifierE17eStatModAbilities, float, eStatModAbilities nAbility);
    DECL_FASTCALL_SIMPLE(Save, _ZN6CStats4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN6CStats4LoadEv, bool);
DECL_CLASS_END()

#endif // __AML_PSDK_SASTATS_H