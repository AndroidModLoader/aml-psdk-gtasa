#ifndef __AML_PSDK_SAWEAPONINFO_H
#define __AML_PSDK_SAWEAPONINFO_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/enum/WeaponType.h>

enum eWeaponSkill
{
    WEAPSKILL_POOR = 0,
    WEAPSKILL_STD,
    WEAPSKILL_PRO,
    WEAPSKILL_COP
};

enum eWeaponFire : unsigned int
{
    WEAPON_FIRE_MELEE = 0,
    WEAPON_FIRE_INSTANT_HIT,
    WEAPON_FIRE_PROJECTILE,
    WEAPON_FIRE_AREA_EFFECT,
    WEAPON_FIRE_CAMERA,
    WEAPON_FIRE_USE
};

DECL_CLASS(CWeaponInfo)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN11CWeaponInfo10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(LoadWeaponData, _ZN11CWeaponInfo14LoadWeaponDataEv, void);
    DECL_FASTCALL_SIMPLE(FindWeaponFireType, _ZN11CWeaponInfo18FindWeaponFireTypeEPKc, i32, const char *pString);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN11CWeaponInfo8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(GetWeaponInfo, _ZN11CWeaponInfo13GetWeaponInfoE11eWeaponTypea, CWeaponInfo*, eWeaponType WeaponType, i8 nSkillLevel);
    DECL_FASTCALL_SIMPLE(GetSkillStatIndex, _ZN11CWeaponInfo17GetSkillStatIndexE11eWeaponType, i32, eWeaponType WeaponType);
    DECL_FASTCALL_SIMPLE(FindWeaponType, _ZN11CWeaponInfo14FindWeaponTypeEPKc, eWeaponType, const char *pString);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(const char*, ms_aWeaponNames, BYBIT(0x677E10, 0x84DC40) );

    // Member functions
    DECL_THISCALL_SIMPLE(GetTargetHeadRange, _ZN11CWeaponInfo18GetTargetHeadRangeEv, float);
    DECL_THISCALL_SIMPLE(GetWeaponReloadTime, _ZN11CWeaponInfo19GetWeaponReloadTimeEv, i32);

    // Member values
    unsigned int   m_nWeaponFire;  // see eWeaponFire
    float          m_fTargetRange; // max targeting range
    float          m_fWeaponRange; // absolute gun range / default melee attack range
    int            m_nModelId;     // modelinfo id
    int            m_nModelId2;    // second modelinfo id
    unsigned int   m_nSlot;
    struct {
        unsigned int bCanAim : 1;
        unsigned int bAimWithArm : 1;
        unsigned int b1stPerson : 1;
        unsigned int bOnlyFreeAim : 1;
        unsigned int bMoveAim : 1; // can move when aiming
        unsigned int bMoveFire : 1; // can move when firing
        unsigned int b06 : 1; // this bitfield is not used
        unsigned int b07 : 1; // this bitfield is not used
        unsigned int bThrow : 1;
        unsigned int bHeavy : 1; // can't run fast with this weapon
        unsigned int bContinuosFire : 1;
        unsigned int bTwinPistol : 1;
        unsigned int bReload : 1; // this weapon can be reloaded
        unsigned int bCrouchFire : 1; // can reload when crouching
        unsigned int bReload2Start : 1; // reload directly after firing
        unsigned int bLongReload : 1;
        unsigned int bSlowdown : 1;
        unsigned int bRandSpeed : 1;
        unsigned int bExpands : 1;
    } m_nFlags;
    unsigned int   m_nAnimToPlay; // instead of storing pointers directly to anims, use anim association groups
    unsigned short m_nAmmoClip; // ammo in one clip
    unsigned short m_nDamage; // damage inflicted per hit
    CVector        m_vecFireOffset; // offset from weapon origin to projectile starting point
    unsigned int   m_nSkillLevel; // what's the skill level of this weapontype
    unsigned int   m_nReqStatLevel; // what stat level is required for this skill level
    float          m_fAccuracy; // modify accuracy of weapon
    float          m_fMoveSpeed; // how fast can move with weapon
    float          m_fAnimLoopStart; // start of animation loop
    float          m_fAnimLoopEnd; // end of animation loop
    float          m_nAnimLoopFire; // time in animation when weapon should be fired // ATTENTION! IT IS FLOAT, NOT UNSIGNED INT
    float          m_nAnimLoop2Start; // start of animation2 loop // ATTENTION! IT IS FLOAT, NOT UNSIGNED INT
    float          m_nAnimLoop2End; // end of animation2 loop // ATTENTION! IT IS FLOAT, NOT UNSIGNED INT
    float          m_nAnimLoop2Fire; // time in animation2 when weapon should be fired // ATTENTION! IT IS FLOAT, NOT UNSIGNED INT
    float          m_fBreakoutTime; // time after which player can break out of attack and run off
    float          m_fSpeed; // speed of projectile
    float          m_fRadius; // radius affected
    float          m_fLifespan; // time taken for shot to dissipate
    float          m_fSpread; // angle inside which shots are created
    unsigned short m_nAimOffsetIndex; // index into array of aiming offsets
    unsigned char  m_nBaseCombo; // base combo for this melee weapon
    unsigned char  m_nNumCombos; // how many further combos are available
DECL_CLASS_END()

DECL_OBJECT_ARRAY_PLT_GLOBAL(CWeaponInfo, aWeaponInfo, BYBIT(0x678ED0, 0x84FDC8) );

#define aWeaponInfo aWeaponInfo()
#define ms_aWeaponNames ms_aWeaponNames()

#endif // __AML_PSDK_SAWEAPONINFO_H