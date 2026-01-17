#ifndef __AML_PSDK_SAWEAPON_H
#define __AML_PSDK_SAWEAPON_H

#include <aml-psdk/sdk_base.h>
#include "../enum/WeaponType.h"

struct FxSystem_c;

DECL_CLASS(CWeapon)
    eWeaponType m_eWeaponType;
    eWeaponState m_nState;
    unsigned int m_nAmmoInClip;
    unsigned int m_nAmmoTotal;
    unsigned int m_nTimeForNextShot;
    char m_bFirstPersonWeaponModeSelected;
    char m_bNoModel;
    FxSystem_c *m_pFxSystem;
DECL_CLASS_END()
CHECKSIZE(CWeapon, 0x1C, 0x20);

#endif // __AML_PSDK_SAWEAPON_H