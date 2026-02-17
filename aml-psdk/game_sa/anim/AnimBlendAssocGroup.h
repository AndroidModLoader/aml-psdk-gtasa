#ifndef __AML_PSDK_SAANIMBLENDASSOCGROUP_H
#define __AML_PSDK_SAANIMBLENDASSOCGROUP_H

#include <aml-psdk/game_sa/plugin.h>

struct CAnimBlock;
struct CAnimBlendStaticAssociation;

DECL_CLASS(CAnimBlendAssocGroup)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAnimBlendAssocGroup, _ZN20CAnimBlendAssocGroupC2Ev);
    DECL_DTORCALL(CAnimBlendAssocGroup, _ZN20CAnimBlendAssocGroupD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(DestroyAssociations, _ZN20CAnimBlendAssocGroup19DestroyAssociationsEv, void);

    DECL_THISCALL_NAMED_HEAD(CreateAssociations1, CreateAssociations, _ZN20CAnimBlendAssocGroup18CreateAssociationsEPKc, void, const char *pAnimBlockName)
    DECL_THISCALL_TAIL(CreateAssociations1, pAnimBlockName)

    DECL_THISCALL_NAMED_HEAD(CreateAssociations2, CreateAssociations, _ZN20CAnimBlendAssocGroup18CreateAssociationsEPKcS1_S1_i, void,
        const char *pAnimBlockName, const char *pAnimNames, const char *pModelNames, i32 iElementSize)
    DECL_THISCALL_TAIL(CreateAssociations2, pAnimBlockName, pAnimNames, pModelNames, iElementSize)

    DECL_THISCALL_NAMED_HEAD(CreateAssociations3, CreateAssociations, _ZN20CAnimBlendAssocGroup18CreateAssociationsEPKcP7RpClump, void,
        const char *pAnimBlockName, RpClump *pClump)
    DECL_THISCALL_TAIL(CreateAssociations3, pAnimBlockName, pClump)

    DECL_THISCALL_NAMED_HEAD(CreateAssociations4, CreateAssociations, _ZN20CAnimBlendAssocGroup18CreateAssociationsEPKcP7RpClumpPS1_i, void,
        const char *pAnimBlockName, RpClump *pClump, const char **ppRequiredAnims, i32 num)
    DECL_THISCALL_TAIL(CreateAssociations4, pAnimBlockName, pClump, ppRequiredAnims, num)

    DECL_THISCALL_HEAD(InitEmptyAssociations, _ZN20CAnimBlendAssocGroup21InitEmptyAssociationsEP7RpClump, void, RpClump *pClump)
    DECL_THISCALL_TAIL(InitEmptyAssociations, pClump)

    DECL_THISCALL_NAMED_HEAD(GetAnimation1, GetAnimation, _ZN20CAnimBlendAssocGroup12GetAnimationEPKc, CAnimBlendStaticAssociation*, const char *pName)
    DECL_THISCALL_TAIL(GetAnimation1, pName)

    DECL_THISCALL_NAMED_HEAD(GetAnimation2, GetAnimation, _ZN20CAnimBlendAssocGroup12GetAnimationEj, CAnimBlendStaticAssociation*, u32 id)
    DECL_THISCALL_TAIL(GetAnimation2, id)   

    DECL_THISCALL_NAMED_HEAD(CopyAnimation1, CopyAnimation, _ZN20CAnimBlendAssocGroup13CopyAnimationEPKc, CAnimBlendAssocGroup*, const char *pName)
    DECL_THISCALL_TAIL(CopyAnimation1, pName)

    DECL_THISCALL_NAMED_HEAD(CopyAnimation2, CopyAnimation, _ZN5CText12GetUpperCaseEt, CAnimBlendAssocGroup*, u32 id)
    DECL_THISCALL_TAIL(CopyAnimation2, id)

    DECL_THISCALL_HEAD(GetAnimationId, _ZN20CAnimBlendAssocGroup14GetAnimationIdEPKc, u32, const char *pName)
    DECL_THISCALL_TAIL(GetAnimationId, pName)

    // Member values
    CAnimBlock                  *m_pAnimBlock;
    CAnimBlendStaticAssociation *m_pAssociations;
    unsigned int                 m_nNumAnimations;
    int                          m_nIdOffset;
    int                          m_nGroupID;
DECL_CLASS_END()

#endif // __AML_PSDK_SAANIMBLENDASSOCGROUP_H