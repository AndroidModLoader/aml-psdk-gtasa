#ifndef __AML_PSDK_SAFX_H
#define __AML_PSDK_SAFX_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/renderware/RwRGBA.h>

struct FxSystem_c;
struct RwCamera;
struct CVehicle;
struct CEntity;
struct RwMatrix;

enum FxQuality_e : unsigned int
{
    FXQUALITY_LOW,
    FXQUALITY_MEDIUM,
    FXQUALITY_HIGH,
    FXQUALITY_VERY_HIGH
};

DECL_CLASS(Fx_c)
    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN4Fx_c4InitEv, u8);
    DECL_THISCALL_SIMPLE(InitStaticSystems, _ZN4Fx_c17InitStaticSystemsEv, void);
    DECL_THISCALL_SIMPLE(InitEntitySystems, _ZN4Fx_c17InitEntitySystemsEv, void);
    DECL_THISCALL_SIMPLE(Exit, _ZN4Fx_c4ExitEv, void);
    DECL_THISCALL_SIMPLE(ExitEntitySystems, _ZN4Fx_c17ExitEntitySystemsEv, void);
    DECL_THISCALL_SIMPLE(ExitStaticSystems, _ZN4Fx_c17ExitStaticSystemsEv, void);
    DECL_THISCALL_SIMPLE(Reset, _ZN4Fx_c5ResetEv, void);
    DECL_THISCALL_SIMPLE(GetFxQuality, _ZN4Fx_c12GetFxQualityEv, FxQuality_e);
    
    DECL_THISCALL_HEAD(Update, _ZN4Fx_c6UpdateEP8RwCameraf, void, RwCamera *camPtr, float deltaTime)
    DECL_THISCALL_TAIL(Update, camPtr, deltaTime)
    
    DECL_THISCALL_HEAD(Render, _ZN4Fx_c6RenderEP8RwCamerah, void, RwCamera *camPtr, u8 doHeatHaze)
    DECL_THISCALL_TAIL(Render, camPtr, doHeatHaze)
    
    DECL_THISCALL_HEAD(AddBlood, _ZN4Fx_c8AddBloodER7CVectorS1_if, void, CVector &pos, CVector &dir, i32 num, float lightMult)
    DECL_THISCALL_TAIL(AddBlood, pos, dir, num, lightMult)
    
    DECL_THISCALL_HEAD(AddWood, _ZN4Fx_c7AddWoodER7CVectorS1_if, void, CVector &pos, CVector &dir, i32 num, float lightMult)
    DECL_THISCALL_TAIL(AddWood, pos, dir, num, lightMult)
    
    DECL_THISCALL_HEAD(AddSparks, _ZN4Fx_c9AddSparksER7CVectorS1_fiS0_hff, void, CVector &pos, CVector &dir, float speed, i32 num, CVector vecMoveSpeed, u8 useGravity, float sparkSpread, float lifeMult)
    DECL_THISCALL_TAIL(AddSparks, pos, dir, speed, num, vecMoveSpeed, useGravity, sparkSpread, lifeMult)
    
    DECL_THISCALL_HEAD(AddTyreBurst, _ZN4Fx_c12AddTyreBurstER7CVectorS1_, void, CVector &pos, CVector &dir)
    DECL_THISCALL_TAIL(AddTyreBurst, pos, dir)
    
    DECL_THISCALL_HEAD(AddBulletImpact, _ZN4Fx_c15AddBulletImpactER7CVectorS1_iif, void, CVector &pos, CVector &dir, i32 surfaceId, i32 num, float lightMult)
    DECL_THISCALL_TAIL(AddBulletImpact, pos, dir, surfaceId, num, lightMult)
    
    DECL_THISCALL_HEAD(AddPunchImpact, _ZN4Fx_c14AddPunchImpactER7CVectorS1_i, void, CVector &pos, CVector &dir, i32 num)
    DECL_THISCALL_TAIL(AddPunchImpact, pos, dir, num)
    
    DECL_THISCALL_HEAD(AddDebris, _ZN4Fx_c9AddDebrisER7CVectorR6RwRGBAfi, void, CVector &pos, RwRGBA &col, float sizeScale, i32 num)
    DECL_THISCALL_TAIL(AddDebris, pos, col, sizeScale, num)
    
    DECL_THISCALL_HEAD(AddGlass, _ZN4Fx_c8AddGlassER7CVectorR6RwRGBAfi, void, CVector &pos, RwRGBA &col, float sizeScale, i32 num)
    DECL_THISCALL_TAIL(AddGlass, pos, col, sizeScale, num)
    
    DECL_THISCALL_HEAD(AddWheelSpray, _ZN4Fx_c13AddWheelSprayEP8CVehicle7CVectorhhf, void, CVehicle *pVeh, CVector pos, u8 bWheelsSpinning, u8 bInWater, float lightMult)
    DECL_THISCALL_TAIL(AddWheelSpray, pVeh, pos, bWheelsSpinning, bInWater, lightMult)
    
    DECL_THISCALL_HEAD(AddWheelGrass, _ZN4Fx_c13AddWheelGrassEP8CVehicle7CVectorhf, void, CVehicle *pVeh, CVector pos, u8 bWheelsSpinning, float lightMult)
    DECL_THISCALL_TAIL(AddWheelGrass, pVeh, pos, bWheelsSpinning, lightMult)
    
    DECL_THISCALL_HEAD(AddWheelGravel, _ZN4Fx_c14AddWheelGravelEP8CVehicle7CVectorhf, void, CVehicle *pVeh, CVector pos, u8 bWheelsSpinning, float lightMult)
    DECL_THISCALL_TAIL(AddWheelGravel, pVeh, pos, bWheelsSpinning, lightMult)
    
    DECL_THISCALL_HEAD(AddWheelMud, _ZN4Fx_c11AddWheelMudEP8CVehicle7CVectorhf, void, CVehicle *pVeh, CVector pos, u8 bWheelsSpinning, float lightMult)
    DECL_THISCALL_TAIL(AddWheelMud, pVeh, pos, bWheelsSpinning, lightMult)
    
    DECL_THISCALL_HEAD(AddWheelSand, _ZN4Fx_c12AddWheelSandEP8CVehicle7CVectorhf, void, CVehicle *pVeh, CVector pos, u8 bWheelsSpinning, float lightMult)
    DECL_THISCALL_TAIL(AddWheelSand, pVeh, pos, bWheelsSpinning, lightMult)
    
    DECL_THISCALL_HEAD(AddWheelDust, _ZN4Fx_c12AddWheelDustEP8CVehicle7CVectorhf, void, CVehicle *pVeh, CVector pos, u8 bWheelsSpinning, float lightMult)
    DECL_THISCALL_TAIL(AddWheelDust, pVeh, pos, bWheelsSpinning, lightMult)
    
    DECL_THISCALL_HEAD(TriggerWaterHydrant, _ZN4Fx_c19TriggerWaterHydrantER7CVector, void, CVector &pos)
    DECL_THISCALL_TAIL(TriggerWaterHydrant, pos)
    
    DECL_THISCALL_HEAD(TriggerGunshot, _ZN4Fx_c14TriggerGunshotEP7CEntityR7CVectorS3_b, void, CEntity *pEntity, CVector &pos, CVector &dir, bool bDoFlash)
    DECL_THISCALL_TAIL(TriggerGunshot, pEntity, pos, dir, bDoFlash)
    
    DECL_THISCALL_HEAD(CreateMatFromVec, _ZN4Fx_c16CreateMatFromVecEP11RwMatrixTagP7CVectorS3_, void, RwMatrix *resMat, CVector *pos, CVector *dir)
    DECL_THISCALL_TAIL(CreateMatFromVec, resMat, pos, dir)
    
    DECL_THISCALL_HEAD(TriggerTankFire, _ZN4Fx_c15TriggerTankFireER7CVectorS1_, void, CVector &pos, CVector &dir)
    DECL_THISCALL_TAIL(TriggerTankFire, pos, dir)
    
    DECL_THISCALL_HEAD(TriggerWaterSplash, _ZN4Fx_c18TriggerWaterSplashER7CVector, void, CVector &pos)
    DECL_THISCALL_TAIL(TriggerWaterSplash, pos)
    
    DECL_THISCALL_HEAD(TriggerBulletSplash, _ZN4Fx_c19TriggerBulletSplashER7CVector, void, CVector &pos)
    DECL_THISCALL_TAIL(TriggerBulletSplash, pos)
    
    DECL_THISCALL_HEAD(TriggerFootSplash, _ZN4Fx_c17TriggerFootSplashER7CVector, void, CVector &pos)
    DECL_THISCALL_TAIL(TriggerFootSplash, pos)
    
    DECL_THISCALL_HEAD(SetFxQuality, _ZN4Fx_c12SetFxQualityE11FxQuality_e, void, FxQuality_e fxQuality)
    DECL_THISCALL_TAIL(SetFxQuality, fxQuality)
    
    DECL_THISCALL_HEAD(CreateEntityFx, _ZN4Fx_c14CreateEntityFxEP7CEntityPcP5RwV3dP11RwMatrixTag, void, CEntity *pEntity, char *bpName, RwV3d *offsetPos, RwMatrix *parentMat)
    DECL_THISCALL_TAIL(CreateEntityFx, pEntity, bpName, offsetPos, parentMat)
    
    DECL_THISCALL_HEAD(DestroyEntityFx, _ZN4Fx_c15DestroyEntityFxEP7CEntity, void, CEntity *pEntity)
    DECL_THISCALL_TAIL(DestroyEntityFx, pEntity)

    // Member values
    FxSystem_c *m_pPrtBlood;
    FxSystem_c *m_pPrtBoatsplash;
    FxSystem_c *m_pPrtBubble;
    FxSystem_c *m_pPrtCardebris;
    FxSystem_c *m_pPrtCollisionsmoke;
    FxSystem_c *m_pPrtGunshell;
    FxSystem_c *m_pPrtSand;
    FxSystem_c *m_pPrtSand2;
    FxSystem_c *m_pPrtSmoke_huge;
    FxSystem_c *m_pPrtSmokeII3expand;
    FxSystem_c *m_pPrtSpark;
    FxSystem_c *m_pPrtSpark2;
    FxSystem_c *m_pPrtSplash;
    FxSystem_c *m_pPrtWake;
    FxSystem_c *m_pPrtWatersplash;
    FxSystem_c *m_pPrtWheeldirt;
    FxSystem_c *m_pPrtGlass;
    TList_c<ListItem_c> m_entityFxList;
    unsigned int m_nBloodPoolsCount;
    FxQuality_e m_fxQuality;
DECL_CLASS_END()
CHECKSIZE(Fx_c, 0x58, 0xA8);

DECL_OBJECT_PLT_GLOBAL(Fx_c, g_fx, BYBIT(0x67952C, 0x850A68) );

#define g_fx g_fx()

#endif // __AML_PSDK_SAFX_H