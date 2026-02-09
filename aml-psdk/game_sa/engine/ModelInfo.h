#ifndef __AML_PSDK_SAMODELINFO_H
#define __AML_PSDK_SAMODELINFO_H

#include <aml-psdk/game_sa/plugin.h>
#include "../enum/WeaponType.h"

struct CBox;
struct C2dEffect;
struct CColModel;
struct RwObject;
struct RpClump;
struct RpAtomic;
struct CModelInfoAccelerator;
struct CAtomicModelInfo;
struct CDamageAtomicModelInfo;
struct CLodAtomicModelInfo;
struct CTimeModelInfo;
struct CLodTimeModelInfo;
struct CWeaponModelInfo;
struct CClumpModelInfo;
struct CVehicleModelInfo;
struct CPedModelInfo;

enum ModelInfoType : i32
{
    MODEL_INFO_NONE = 0,
    MODEL_INFO_ATOMIC = 1,
    MODEL_INFO_MLO = 2,
    MODEL_INFO_TIME = 3,
    MODEL_INFO_WEAPON = 4,
    MODEL_INFO_CLUMP = 5,
    MODEL_INFO_VEHICLE = 6,
    MODEL_INFO_PED = 7,
    MODEL_INFO_LOD = 8,
    MODEL_INFO_XTRACOMPS = 9
};

struct tTimeInfo
{
    u8  m_nTimeOn;
    u8  m_nTimeOff;
    i16 m_nOtherTimeModel = -1;
};

struct RwObjectNameIdAssocation
{
    char *m_pName;
    unsigned int m_dwHierarchyId;
    unsigned int m_dwFlags;
};

DECL_CLASS_VTABLE(CBaseModelInfo)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CBaseModelInfo, _ZN14CBaseModelInfoC2Ev);
    ~CBaseModelInfo(){}

    // Virtual functions
    virtual CAtomicModelInfo* AsAtomicModelInfoPtr();
    virtual CDamageAtomicModelInfo* AsDamageAtomicModelInfoPtr();
    virtual CLodAtomicModelInfo* AsLodAtomicModelInfoPtr();
    virtual ModelInfoType GetModelType();
    virtual tTimeInfo* GetTimeInfo();
    virtual void Init();
    virtual void Shutdown();
    virtual void DeleteRwObject();
    virtual u32 GetRwModelType();
    virtual RwObject* CreateInstance();
    virtual RwObject* CreateInstance(RwMatrix* matrix);
    virtual void SetAnimFile(const char* filename);
    virtual void ConvertAnimFileIndex();
    virtual i32 GetAnimFileIndex();

    // Member functions
    DECL_THISCALL_SIMPLE(DeleteCollisionModel, _ZN14CBaseModelInfo20DeleteCollisionModelEv, void);
    DECL_THISCALL_SIMPLE(ClearTexDictionary, _ZN14CBaseModelInfo18ClearTexDictionaryEv, void);
    DECL_THISCALL_SIMPLE(AddTexDictionaryRef, _ZN14CBaseModelInfo19AddTexDictionaryRefEv, void);
    DECL_THISCALL_SIMPLE(RemoveTexDictionaryRef, _ZN14CBaseModelInfo22RemoveTexDictionaryRefEv, void);
    DECL_THISCALL_SIMPLE(AddRef, _ZN14CBaseModelInfo6AddRefEv, void);
    DECL_THISCALL_SIMPLE(RemoveRef, _ZN14CBaseModelInfo9RemoveRefEv, void);
    DECL_THISCALL_SIMPLE(Init2dEffects, _ZN14CBaseModelInfo13Init2dEffectsEv, void);

    DECL_THISCALL_HEAD(SetTexDictionary, _ZN14CBaseModelInfo16SetTexDictionaryEPKcS1_, void, const char *pName, const char *dbName)
    DECL_THISCALL_TAIL(SetTexDictionary, pName, dbName)

    DECL_THISCALL_HEAD(SetColModel, _ZN14CBaseModelInfo11SetColModelEP9CColModelb, void, CColModel *pColModel, bool bOwnColModel)
    DECL_THISCALL_TAIL(SetColModel, pColModel, bOwnColModel)

    DECL_THISCALL_HEAD(Get2dEffect, _ZN14CBaseModelInfo11Get2dEffectEi, C2dEffect*, i32 index)
    DECL_THISCALL_TAIL(Get2dEffect, index)

    DECL_THISCALL_HEAD(Add2dEffect, _ZN14CBaseModelInfo11Add2dEffectEP9C2dEffect, void, C2dEffect *pEffect)
    DECL_THISCALL_TAIL(Add2dEffect, pEffect)

    // Member values
    unsigned int   m_nKey;
    char           m_szModelName[22];
    unsigned short m_nRefCount;
    short          m_nTxdIndex;
    unsigned char  m_nAlpha; // 0 - 255
    unsigned char  m_nNum2dEffects;
    short          m_n2dEffectIndex;
    short          m_nObjectInfoIndex;
    union
    {
        unsigned short m_nFlags;
        struct
        {
            unsigned char bHasBeenPreRendered : 1;
            unsigned char bDrawLast : 1;
            unsigned char bAdditiveRender : 1;
            unsigned char bDontWriteZBuffer : 1;
            unsigned char bDontCastShadowsOn : 1;
            unsigned char bDoWeOwnTheColModel : 1;
            unsigned char bIsBackfaceCulled : 1;
            unsigned char bIsLod : 1;
            union
            {
                struct // Atomic flags
                {
                    unsigned char bIsRoad : 1;
                    unsigned char bHasComplexAtomicHierarchy : 1;
                    unsigned char bDontCollideWithFlyer : 1;
                    unsigned char nSpecialType : 4;
                    unsigned char bWetRoadReflection : 1;
                };
                struct // Vehicle flags
                {
                    unsigned char bUsesVehDummy : 1;
                    unsigned char : 1;
                    unsigned char nCarmodId : 5;
                    unsigned char bUseCommonVehicleDictionary : 1;
                };
                struct // Clump flags
                {
                    unsigned char bHasAnimBlend : 1;
                    unsigned char bHasComplexHierarchy : 1;
                    unsigned char bAnimSomething : 1;
                    unsigned char bOwnsCollisionModel : 1;
                    unsigned char : 3;
                    unsigned char bTagDisabled : 1;
                };
            };
        };
    };
    CColModel        *m_pColModel;
    float             m_fDrawDistance;
    union
    {
        RwObject* m_pRwObject;
        RpClump* m_pRwClump;
        RpAtomic* m_pRwAtomic;
    };
DECL_CLASS_END()
CHECKSIZE(CBaseModelInfo, 0x38, 0x48);



DECL_CLASS_BASED(CAtomicModelInfo, CBaseModelInfo)
    // Virtual functions
    virtual void SetAtomic(RpAtomic *pAtomic);

    // Member functions
    DECL_THISCALL_HEAD(SetupVehicleUpgradeFlags, _ZN16CAtomicModelInfo24SetupVehicleUpgradeFlagsEPKc, void, const char *pName)
    DECL_THISCALL_TAIL(SetupVehicleUpgradeFlags, pName)
    
    DECL_THISCALL_HEAD(GetAtomicFromDistance, _ZN16CAtomicModelInfo21GetAtomicFromDistanceEf, RpAtomic*, float dist)
    DECL_THISCALL_TAIL(GetAtomicFromDistance, dist)
DECL_CLASS_END()



DECL_CLASS_BASED(CClumpModelInfo, CBaseModelInfo)
    // Member values
    union
    {
        char        *m_animFileName;
        unsigned int m_dwAnimFileIndex;
    };

    // Virtual functions
    virtual CBox *GetBoundingBox();
    virtual void SetClump(RpClump *clump);

    // Member functions
    DECL_THISCALL_HEAD(SetFrameIds, _ZN15CClumpModelInfo11SetFrameIdsEP24RwObjectNameIdAssocation, void, RwObjectNameIdAssocation *pAssocArray)
    DECL_THISCALL_TAIL(SetFrameIds, pAssocArray)

    // STATIC functions
    DECL_FASTCALL_SIMPLE(SetAtomicRendererCB, _ZN15CClumpModelInfo19SetAtomicRendererCBEP8RpAtomicPv, RpAtomic*, RpAtomic *pAtomic, void *pData);
    DECL_FASTCALL_SIMPLE(FindFrameFromNameCB, _ZN15CClumpModelInfo19FindFrameFromNameCBEP7RwFramePv, RwFrame*, RwFrame *pFrame, void *pData);
    DECL_FASTCALL_SIMPLE(FindFrameFromNameWithoutIdCB, _ZN15CClumpModelInfo28FindFrameFromNameWithoutIdCBEP7RwFramePv, RwFrame*, RwFrame *pFrame, void *pData);
    DECL_FASTCALL_SIMPLE(FindFrameFromIdCB, _ZN15CClumpModelInfo17FindFrameFromIdCBEP7RwFramePv, RwFrame*, RwFrame *pFrame, void *pData);
    DECL_FASTCALL_SIMPLE(FillFrameArrayCB, _ZN15CClumpModelInfo16FillFrameArrayCBEP7RwFramePv, RwFrame*, RwFrame *pFrame, void *pData);
    DECL_FASTCALL_SIMPLE(GetFrameFromId, _ZN15CClumpModelInfo14GetFrameFromIdEP7RpClumpi, RwFrame*, RpClump *pClump, i32 id);
    DECL_FASTCALL_SIMPLE(GetFrameFromName, _ZN15CClumpModelInfo16GetFrameFromNameEP7RpClumpPKc, RwFrame*, RpClump *pClump, const char *pName);
    DECL_FASTCALL_SIMPLE(FillFrameArray, _ZN15CClumpModelInfo14FillFrameArrayEP7RpClumpPP7RwFrame, void, RpClump *pClump, RwFrame **ppFrame);
DECL_CLASS_END()



DECL_CLASS_BASED(CWeaponModelInfo, CClumpModelInfo)
    // Member values
    eWeaponType m_weaponInfo;
DECL_CLASS_END()



DECL_CLASS_BASED(CPedModelInfo, CClumpModelInfo)
    // Member values
    int            m_nAnimType;
    unsigned int   m_nPedType;
    unsigned int   m_nStatType;
    unsigned short m_nCarsCanDriveMask;
    unsigned short m_nPedFlags;
    CColModel     *m_pHitColModel;
    unsigned char  m_nRadio1;
    unsigned char  m_nRadio2;
    unsigned char  m_nRace;
    short          m_nPedAudioType;
    short          m_nVoice1;
    short          m_nVoice2;
    short          m_nVoiceId;
DECL_CLASS_END()



DECL_CLASS_BASED(CDamageAtomicModelInfo, CAtomicModelInfo)
    // Member values
    RpAtomic* m_pDamagedAtomic;

    // STATIC values
    DECL_VALUE_PLT_BOOL(m_bCreateDamagedVersion, BYBIT(0x677244, 0x84C4C0));
DECL_CLASS_END()



DECL_CLASS_BASED(CTimeModelInfo, CAtomicModelInfo)
    // Member values
    tTimeInfo m_timeInfo;
DECL_CLASS_END()



DECL_CLASS(CModelInfo)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN10CModelInfo10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(AddAtomicModel, _ZN10CModelInfo14AddAtomicModelEi, CAtomicModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(ReInit2dEffects, _ZN10CModelInfo15ReInit2dEffectsEv, void);
    DECL_FASTCALL_SIMPLE(ShutDown, _ZN10CModelInfo8ShutDownEv, void);
    DECL_FASTCALL_SIMPLE(GetModelInfo1, _ZN10CModelInfo12GetModelInfoEPKcPi, CBaseModelInfo*, const char *pName, i32 *pIndex);
    DECL_FASTCALL_SIMPLE(GetModelInfoFromHashKey, _ZN10CModelInfo23GetModelInfoFromHashKeyEjPi, CBaseModelInfo*, u32 key, i32 *pIndex);
    DECL_FASTCALL_SIMPLE(GetModelInfoUInt16, _ZN10CModelInfo18GetModelInfoUInt16EPKcPt, CBaseModelInfo*, const char *pName, u16 *pIndex);
    DECL_FASTCALL_SIMPLE(GetModelInfo2, _ZN10CModelInfo12GetModelInfoEPKcii, CBaseModelInfo*, const char *pName, i32 start, i32 end);
    DECL_FASTCALL_SIMPLE(GetModelInfoFast, _ZN10CModelInfo16GetModelInfoFastEP21CModelInfoAcceleratorPKcPi, void, CModelInfoAccelerator *pAccel, const char *pName, i32 *pIndex);
    DECL_FASTCALL_SIMPLE(AddDamageAtomicModel, _ZN10CModelInfo20AddDamageAtomicModelEi, CDamageAtomicModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddLodAtomicModel, _ZN10CModelInfo17AddLodAtomicModelEi, CLodAtomicModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddTimeModel, _ZN10CModelInfo12AddTimeModelEi, CTimeModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddLodTimeModel, _ZN10CModelInfo15AddLodTimeModelEi, CLodTimeModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddWeaponModel, _ZN10CModelInfo14AddWeaponModelEi, CWeaponModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddClumpModel, _ZN10CModelInfo13AddClumpModelEi, CClumpModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddVehicleModel, _ZN10CModelInfo15AddVehicleModelEi, CVehicleModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddPedModel, _ZN10CModelInfo11AddPedModelEi, CPedModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(Get2dEffectStore, _ZN10CModelInfo16Get2dEffectStoreEv, uintptr_t*);
    DECL_FASTCALL_SIMPLE(IsBoatModel, _ZN10CModelInfo11IsBoatModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsCarModel, _ZN10CModelInfo10IsCarModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsTrainModel, _ZN10CModelInfo12IsTrainModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsHeliModel, _ZN10CModelInfo11IsHeliModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsPlaneModel, _ZN10CModelInfo12IsPlaneModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsBikeModel, _ZN10CModelInfo11IsBikeModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsFakePlaneModel, _ZN10CModelInfo16IsFakePlaneModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsMonsterTruckModel, _ZN10CModelInfo19IsMonsterTruckModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsQuadBikeModel, _ZN10CModelInfo15IsQuadBikeModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsBmxModel, _ZN10CModelInfo10IsBmxModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsTrailerModel, _ZN10CModelInfo14IsTrailerModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsVehicleModelType, _ZN10CModelInfo18IsVehicleModelTypeEi, u8, i32 index);

    // Helper functions
    static inline CBaseModelInfo* GetModelInfo(const char *pName, i32 *pIndex)
    {
        return GetModelInfo1(pName, pIndex);
    }
    static inline CBaseModelInfo* GetModelInfo(const char *pName, i32 start, i32 end)
    {
        return GetModelInfo2(pName, start, end);
    }

    // STATIC members
    DECL_OBJECT_ARRAY_PLT(CBaseModelInfo*, ms_modelInfoPtrs, BYBIT(0x6796D4, 0x850DB8));
DECL_CLASS_END()

#define ms_modelInfoPtrs ms_modelInfoPtrs()
#define m_bCreateDamagedVersion m_bCreateDamagedVersion()

#endif // __AML_PSDK_SAMODELINFO_H