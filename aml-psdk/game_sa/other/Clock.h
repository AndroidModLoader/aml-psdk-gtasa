#ifndef __AML_PSDK_SACLOCK_H
#define __AML_PSDK_SACLOCK_H

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS(CClock)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN6CClock10InitialiseEj, void, u32 msPerGameMinute);
    DECL_FASTCALL_SIMPLE(SetGameClock, _ZN6CClock12SetGameClockEhhh, void, u8 hour, u8 min, u8 day);
    DECL_FASTCALL_SIMPLE(NormaliseGameClock, _ZN6CClock18NormaliseGameClockEv, void);
    DECL_FASTCALL_SIMPLE(GetGameClockMinutesUntil, _ZN6CClock24GetGameClockMinutesUntilEhh, u32, u8 hour, u8 min);
    DECL_FASTCALL_SIMPLE(GetIsTimeInRange, _ZN6CClock16GetIsTimeInRangeEhh, bool, u8 startHour, u8 endHour);
    DECL_FASTCALL_SIMPLE(Update, _ZN6CClock6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(StoreClock, _ZN6CClock10StoreClockEv, void);
    DECL_FASTCALL_SIMPLE(RestoreClock, _ZN6CClock12RestoreClockEv, void);
    DECL_FASTCALL_SIMPLE(OffsetClockByADay, _ZN6CClock17OffsetClockByADayEj, void, bool forward);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(u8, daysInMonth, BYBIT(0x676554, 0x84AB00));
    DECL_VALUE_PLT_U32(ms_nMillisecondsPerGameMinute, BYBIT(0x679524, 0x850A58));
    DECL_VALUE_PLT_U32(ms_nLastClockTick, BYBIT(0x677B4C, 0x84D6B8));
    DECL_VALUE_PLT_U8(ms_nGameClockMonths, BYBIT(0x678DA4, 0x84FB70));
    DECL_VALUE_PLT_U8(ms_nGameClockDays, BYBIT(0x678720, 0x84EE68));
    DECL_VALUE_PLT_U8(ms_nGameClockHours, BYBIT(0x679B40, 0x8516A0));
    DECL_VALUE_PLT_U8(ms_nGameClockMinutes, BYBIT(0x676270, 0x84A540));
    DECL_VALUE_PLT_U16(ms_nGameClockSeconds, BYBIT(0x676640, 0x84ACD8));
    DECL_VALUE_PLT_U8(CurrentDay, BYBIT(0x678548, 0x84EAA8));
    DECL_VALUE_PLT_U8(ms_Stored_nGameClockMonths, BYBIT(0x678FF4, 0x850010));
    DECL_VALUE_PLT_U8(ms_Stored_nGameClockDays, BYBIT(0x679F20, 0x851E50));
    DECL_VALUE_PLT_U8(ms_Stored_nGameClockHours, BYBIT(0x678E24, 0x84FC70));
    DECL_VALUE_PLT_U8(ms_Stored_nGameClockMinutes, BYBIT(0x675EF4, 0x849E58));
    DECL_VALUE_PLT_U16(ms_Stored_nGameClockSeconds, BYBIT(0x676BC8, 0x84B7D8));
    DECL_VALUE_PLT_BOOL(bClockHasBeenStored, BYBIT(0x6798A8, 0x851168));
DECL_CLASS_END()

#define daysInMonth daysInMonth()
#define ms_nMillisecondsPerGameMinute ms_nMillisecondsPerGameMinute()
#define ms_nLastClockTick ms_nLastClockTick()
#define ms_nGameClockMonths ms_nGameClockMonths()
#define ms_nGameClockDays ms_nGameClockDays()
#define ms_nGameClockHours ms_nGameClockHours()
#define ms_nGameClockMinutes ms_nGameClockMinutes()
#define ms_nGameClockSeconds ms_nGameClockSeconds()
#define CurrentDay CurrentDay()
#define ms_Stored_nGameClockMonths ms_Stored_nGameClockMonths()
#define ms_Stored_nGameClockDays ms_Stored_nGameClockDays()
#define ms_Stored_nGameClockHours ms_Stored_nGameClockHours()
#define ms_Stored_nGameClockMinutes ms_Stored_nGameClockMinutes()
#define ms_Stored_nGameClockSeconds ms_Stored_nGameClockSeconds()
#define bClockHasBeenStored bClockHasBeenStored()

#endif // __AML_PSDK_SACLOCK_H