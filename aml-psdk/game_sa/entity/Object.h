#ifndef __AML_PSDK_SAOBJECT_H
#define __AML_PSDK_SAOBJECT_H

#include "Physical.h"

struct CObjectInfo;
struct CFire;
struct RwTexture;
struct CPed;
struct RwFrame;

enum eObjectType : unsigned char
{
    OBJECT_UNKNOWN,
    OBJECT_MISSION = 2,
    OBJECT_TEMPORARY = 3,
    OBJECT_MISSION2 = 6
};

DECL_CLASS_BASED(CObject, CPhysical)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CObject, _ZN7CObjectC2Ej);
    DECL_DTORCALL(CObject, _ZN7CObjectD2Ev);
    DECL_NEWCALL(CObject, BYBIT(_ZN7CObjectnwEj, _ZN7CObjectnwEm) );
    DECL_DLCALL(CObject, _ZN7CObjectdlEPv);

    // Member values
    void           *m_pControlCodeList;
    unsigned char   m_nObjectType; // see enum eObjectType
    unsigned char   m_nBonusValue;
    unsigned short  m_wCostValue;
    struct
    {
        unsigned int bIsPickup : 1;
        unsigned int bNoPickupEffects : 1;
        unsigned int bPickupPropertyForSale : 1;
        unsigned int bPickupInShopOutOfStock : 1;
        unsigned int bGlassBroken : 1;
        unsigned int bGlassBrokenAltogether : 1;
        unsigned int bIsExploded : 1;
        unsigned int bParentIsACar : 1;

        unsigned int bIsLampPost : 1;
        unsigned int bIsTargatable : 1;
        unsigned int bIsBroken : 1;
        unsigned int bTrainCrossEnabled : 1;
        unsigned int bIsPhotographed : 1;
        unsigned int bIsLiftable : 1;
        unsigned int bIsDoorMoving : 1;
        unsigned int bbIsDoorOpen : 1;

        unsigned int bHasNoModel : 1;
        unsigned int bIsScaled : 1;
        unsigned int bCanBeAttachedToMagnet : 1;
        unsigned int bLandedOnMovingCol : 1;
        unsigned int ScriptBrainStatus : 2;
        unsigned int bFadingIn : 1; // works only for objects with type 2 (OBJECT_MISSION)
        unsigned int bAffectedByColBrightness : 1;

        unsigned int bEnableDisabledAttractors : 1;
        unsigned int bDoNotRender : 1;
        unsigned int bFadingIn2 : 1; // not exists?
        unsigned int b28 : 1;
        unsigned int b29 : 1;
        unsigned int b30 : 1;
        unsigned int b31 : 1;
        unsigned int b32 : 1;
    } m_nObjectFlags;
    
    unsigned char   m_nColDamageEffect;
    unsigned char   m_nStoredColDamageEffect;
    char KeepieUppyCounter;
    char            m_nGarageDoorGarageIndex;
    unsigned char   m_nLastWeaponDamage;
    unsigned char   m_nDayBrightness : 4;
    unsigned char   m_nNightBrightness : 4;
    short           m_nRefModelIndex;
    unsigned char   m_nCarColor[4]; // this is used for detached car parts
    int             m_dwRemovalTime; // time when this object must be deleted
    float           m_fHealth;
    float           m_fDoorStartAngle; // this is used for door objects
    float           m_fScale;
    B64MACRO(__attribute__((packed)) __attribute__((aligned(1)))) CObjectInfo    *m_pObjectInfo;
    B64MACRO(__attribute__((packed)) __attribute__((aligned(1)))) CFire     *m_pFire; // CFire *
    short           m_wScriptTriggerIndex;
    const char* m_szRemapTxdName; // this is different from PC. there was "m_wRemapTxd"
    RwTexture      *m_pRemapTexture; // this is used for detached car parts
    CDummyObject   *m_pDummyObject; // used for dynamic objects like garage doors, train crossings etc.
    int             m_dwBurnTime; // time when particles must be stopped
    float           m_fBurnDamage;
DECL_CLASS_END()
CHECKSIZE(CObject, 0x184, 0x1F8);

DECL_CLASS_BASED(CHandObject, CObject)
    CPed       *m_pPed;
    unsigned int m_nBoneIndex;
    RwTexture   *m_pTexture;
    bool         m_bUpdatedMatricesArray;
DECL_CLASS_END()

DECL_CLASS_BASED(CCutsceneObject, CObject)
    union
    {
        RwFrame *m_pAttachTo;
        unsigned int m_nAttachBone; // this one if m_pAttachmentObject != 0
    };
    CObject *m_pAttachmentObject;
    CVector m_vWorldPosition;
    CVector m_vForce;
DECL_CLASS_END()

DECL_FASTCALL_SIMPLE_GLO(IsObjectPointerValid, _Z20IsObjectPointerValidP7CObject, bool, CObject* pObject);
DECL_FASTCALL_SIMPLE_GLO(IsObjectPointerValid_NotInWorld, _Z31IsObjectPointerValid_NotInWorldP7CObject, bool, CObject* pObject);

#endif // __AML_PSDK_SAOBJECT_H
