#ifndef __AML_PSDK_SAPLAYERPED_H
#define __AML_PSDK_SAPLAYERPED_H

#include "Ped.h"

DECL_CLASS_BASED(CPlayerPed, CPed)
    CPed *m_pPlayerTargettedPed;
    int m_iMouseLockOnRecruitTimer;
DECL_CLASS_END()
CHECKSIZE(CPlayerPed, 0x7AC, 0x998);

DECL_FASTCALL_SIMPLE_GLO(FindPlayerPed, _Z13FindPlayerPedi, CPlayerPed*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerSpeed, _Z15FindPlayerSpeedi, CVector*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(IsPlayerRemotePlane, _Z19IsPlayerRemotePlane, bool);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerEntity, _Z16FindPlayerEntity, CEntity*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerWanted, _Z16FindPlayerWantedi, CWanted*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerCentreOfWorld, _Z23FindPlayerCentreOfWorldi, CVector*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerCentreOfWorld_NoSniperShift, _Z37FindPlayerCentreOfWorld_NoSniperShift, CVector*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerCentreOfWorldForMap, _Z29FindPlayerCentreOfWorldForMapi, CVector, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerHeading, _Z17FindPlayerHeadingi, float, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerHeight, _Z16FindPlayerHeighti, float, int PlayerNum);

#endif // __AML_PSDK_SAPLAYERPED_H
