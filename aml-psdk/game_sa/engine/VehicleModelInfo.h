#ifndef __AML_PSDK_SAVEHICLEMODELINFO_H
#define __AML_PSDK_SAVEHICLEMODELINFO_H

#include "ModelInfo.h"
#include "../enum/Vehicles.h"
#include "../base/Quaternion.h"

struct RpMaterial;
struct CAnimBlock;

struct UpgradePosnDesc
{
    CVector m_vPosition;
    CQuaternion m_qRotation;
    int m_nParentComponentId;
};

DECL_CLASS_BASED(CVehicleModelInfo, CClumpModelInfo)
    // Member values
    RpMaterial      *m_pPlateMaterial;
    char             m_szPlateText[9];
    unsigned char    m_nPlateType;
    char             m_szGameName[10];
    unsigned int     m_nVehicleType;
    float            m_fWheelSizeFront;
    float            m_fWheelSizeRear;
    short            m_nWheelModelIndex;
    unsigned short   m_nHandlingId;
    unsigned char    m_nNumDoors;
    unsigned char    m_nVehicleClass; // see eVehicleClass
    unsigned char    m_nFlags;
    unsigned char    m_nWheelUpgradeClass;
    unsigned char    m_nTimesUsed;
    unsigned short   m_nFrq;
    union
    {
        unsigned int m_nCompRules;
        struct
        {
            unsigned int nExtraA_comp1 : 4;
            unsigned int nExtraA_comp2 : 4;
            unsigned int nExtraA_comp3 : 4;
            unsigned int nExtraA_rule  : 4;
            unsigned int nExtraB_comp1 : 4;
            unsigned int nExtraB_comp2 : 4;
            unsigned int nExtraB_comp3 : 4;
            unsigned int nExtraB_rule  : 4;
        } m_nCompRulesBits;
    };
    float               m_fBikeSteerAngle;

    struct CVehicleStructure
    {
        CVector         m_avDummyPos[15];
        UpgradePosnDesc m_aUpgrades[18];
        RpAtomic       *m_apExtras[6];
        RpAtomic       *m_apExtrasLOD[6];
        unsigned char   m_nNumExtras;
        unsigned int    m_nMaskComponentsDamagable;

        // STATIC member
        //static CPool<CVehicleModelInfo> *&m_pInfoPool; // TODO:
    } *m_pVehicleStruct;

    RpMaterial         *m_firstColour[49];
    RpMaterial         *m_secondColour[33];
    RpMaterial         *m_thirdColour[17];
    RpMaterial         *m_fourthColour[17];
    RpMaterial         *m_apDirtMaterials[64];
    unsigned char       m_anPrimaryColors[8];
    unsigned char       m_anSecondaryColors[8];
    unsigned char       m_anTertiaryColors[8];
    unsigned char       m_anQuaternaryColors[8];
    unsigned char       m_nNumColorVariations;
    unsigned char       m_nLastColorVariation;
    unsigned char       m_nCurrentPrimaryColor;
    unsigned char       m_nCurrentSecondaryColor;
    unsigned char       m_nCurrentTertiaryColor;
    unsigned char       m_nCurrentQuaternaryColor;
    short               m_anUpgrades[18];
    const char         *m_anRemaps[4]; // Not TXDs on mobile
    CAnimBlock         *m_pAnimBlock;
DECL_CLASS_END()
CHECKSIZE(CVehicleModelInfo, 0x3A8, 0x6B0);

#endif // __AML_PSDK_SAVEHICLEMODELINFO_H