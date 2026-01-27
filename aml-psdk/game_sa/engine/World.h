#ifndef __AML_PSDK_SAWORLD_H
#define __AML_PSDK_SAWORLD_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/game_sa/base/ColModel.h>
#include <aml-psdk/game_sa/other/PlayerInfo.h>

DECL_CLASS(CWorld)
    // STATIC functions
    // TODO:
    DECL_FASTCALL_SIMPLE(FindGroundZForCoord, _ZN6CWorld19FindGroundZForCoordEff, float, float x, float y);
    
    // STATIC members
    DECL_OBJECT_ARRAY_PLT(CPlayerInfo, Players, BYBIT(0x6783C8, 0x84E7A8));
    DECL_VALUE_PLT_U8(PlayerInFocus, BYBIT(0x679B5C, 0x8516D8));
    DECL_VALUE_PLT_U8(bNoMoreCollisionTorque, BYBIT(0x678BB0, 0x84F788));
    DECL_VALUE_PLT_U8(bIncludeDeadPeds, BYBIT(0x675FA8, 0x849FC0));
    DECL_VALUE_PLT_U8(bIncludeCarTyres, BYBIT(0x6765E0, 0x84AC18));
    DECL_VALUE_PLT_U8(bIncludeBikers, BYBIT(0x67620C, 0x84A478));
    DECL_VALUE_PLT_U8(bForceProcessControl, BYBIT(0x6771FC, 0x84C430));
    DECL_VALUE_PLT_U8(bProcessCutsceneOnly, BYBIT(0x678470, 0x84E8F8));
    DECL_VALUE_PLT_U8(bSecondShift, BYBIT(0x678B28, 0x84F678));
    DECL_OBJECT_PLT(CEntity*, pIgnoreEntity, BYBIT(0x676894, 0x84B180));
    DECL_VALUE_PLT_FLT(fWeaponSpreadRate, BYBIT(0x679CF4, 0x851A00));
    DECL_VALUE_PLT_U32(ms_iProcessLineNumCrossings, BYBIT(0x67905C, 0x8500E0));
    DECL_OBJECT_ARRAY_PLT(CSector, ms_aSectors, BYBIT(0x676734, 0x84AEC0));
    DECL_OBJECT_ARRAY_PLT(CRepeatSector, ms_aRepeatSectors, BYBIT(0x6771E4, 0x84C400));
    DECL_OBJECT_ARRAY_PLT(CPtrListSingleLink, ms_aLodPtrLists, BYBIT(0x67738C, 0x84C750));
    DECL_OBJECT_PLT(CPtrListDoubleLink, ms_listMovingEntityPtrs, BYBIT(0x678E98, 0x84FD58));
    DECL_OBJECT_PLT(CPtrListDoubleLink, ms_listObjectsWithControlCode, BYBIT(0x678190, 0x84E338));
    DECL_VALUE_PLT_U16(ms_nCurrentScanCode, BYBIT(0x6766A4, 0x84ADA0));
    DECL_OBJECT_ARRAY_PLT(CColPoint, m_aTempColPts, BYBIT(0x677DE0, 0x84DBE0));
DECL_CLASS_END()

#define PlayerInFocus PlayerInFocus()
#define bNoMoreCollisionTorque bNoMoreCollisionTorque()
#define bIncludeDeadPeds bIncludeDeadPeds()
#define bIncludeCarTyres bIncludeCarTyres()
#define bIncludeBikers bIncludeBikers()
#define bForceProcessControl bForceProcessControl()
#define bProcessCutsceneOnly bProcessCutsceneOnly()
#define bSecondShift bSecondShift()
#define fWeaponSpreadRate fWeaponSpreadRate()
#define ms_iProcessLineNumCrossings ms_iProcessLineNumCrossings()
#define ms_listMovingEntityPtrs ms_listMovingEntityPtrs()
#define ms_listObjectsWithControlCode ms_listObjectsWithControlCode()
#define ms_nCurrentScanCode ms_nCurrentScanCode()

#endif // __AML_PSDK_SAWORLD_H
