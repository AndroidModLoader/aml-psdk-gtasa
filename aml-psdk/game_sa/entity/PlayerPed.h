#ifndef __AML_PSDK_SAPLAYERPED_H
#define __AML_PSDK_SAPLAYERPED_H

#include "Ped.h"

DECL_CLASS_BASED(CPlayerPed, CPed)
    CPed *m_pPlayerTargettedPed;
    int m_iMouseLockOnRecruitTimer;
DECL_CLASS_END()
CHECKSIZE(CPlayerPed, 0x7AC, 0x998);

#endif // __AML_PSDK_SAPLAYERPED_H