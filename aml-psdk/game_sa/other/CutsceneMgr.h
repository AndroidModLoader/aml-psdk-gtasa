#ifndef __AML_PSDK_SACUTSCENEMGR_H
#define __AML_PSDK_SACUTSCENEMGR_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/anim/AnimBlendAssocGroup.h>

struct CObject;
struct CEntity;
struct CDirectory;

DECL_CLASS(CCutsceneMgr)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN12CCutsceneMgr10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN12CCutsceneMgr8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(LoadAnimationUncompressed, _ZN12CCutsceneMgr25LoadAnimationUncompressedEPKc, void, const char *pAnimName);
    DECL_FASTCALL_SIMPLE(LoadCutsceneData, _ZN12CCutsceneMgr16LoadCutsceneDataEPKc, void, const char *pName);
    DECL_FASTCALL_SIMPLE(BuildCutscenePlayer, _ZN12CCutsceneMgr19BuildCutscenePlayerEv, void);
    DECL_FASTCALL_SIMPLE(DeleteCutsceneData, _ZN12CCutsceneMgr18DeleteCutsceneDataEv, void);
    DECL_FASTCALL_SIMPLE(RemoveCutscenePlayer, _ZN12CCutsceneMgr20RemoveCutscenePlayerEv, void);
    DECL_FASTCALL_SIMPLE(LoadEverythingBecauseCutsceneDeletedAllOfIt, _ZN12CCutsceneMgr43LoadEverythingBecauseCutsceneDeletedAllOfItEv, void);
    DECL_FASTCALL_SIMPLE(RemoveEverythingBecauseCutsceneDoesntFitInMemory, _ZN12CCutsceneMgr48RemoveEverythingBecauseCutsceneDoesntFitInMemoryEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN12CCutsceneMgr6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(IsCutsceneSkipButtonBeingPressed, _ZN12CCutsceneMgr32IsCutsceneSkipButtonBeingPressedEv, bool);
    DECL_FASTCALL_SIMPLE(AppendToNextCutscene, _ZN12CCutsceneMgr20AppendToNextCutsceneEPKcS1_, void, const char *pModelName, const char *pAnimName);
    DECL_FASTCALL_SIMPLE(LoadCutsceneData_preload, _ZN12CCutsceneMgr24LoadCutsceneData_preloadEv, void);
    DECL_FASTCALL_SIMPLE(LoadCutsceneData_postload, _ZN12CCutsceneMgr25LoadCutsceneData_postloadEv, void);
    DECL_FASTCALL_SIMPLE(HideRequestedObjects, _ZN12CCutsceneMgr20HideRequestedObjectsEv, void);
    DECL_FASTCALL_SIMPLE(LoadCutsceneData_loading, _ZN12CCutsceneMgr24LoadCutsceneData_loadingEv, void);
    DECL_FASTCALL_SIMPLE(CreateCutsceneObject, _ZN12CCutsceneMgr20CreateCutsceneObjectEi, CObject*, i32 id);
    DECL_FASTCALL_SIMPLE(SetCutsceneAnim, _ZN12CCutsceneMgr15SetCutsceneAnimEPKcP7CObject, void, const char *pName, CObject *pObject);
    DECL_FASTCALL_SIMPLE(AttachObjectToBone, _ZN12CCutsceneMgr18AttachObjectToBoneEP7CObjectS1_i, void, CObject *pObject, CObject *pParent, i32 boneId);
    DECL_FASTCALL_SIMPLE(LoadCutsceneData_overlay, _ZN12CCutsceneMgr24LoadCutsceneData_overlayEPKc, void, const char *pName);
    DECL_FASTCALL_SIMPLE(DeleteCutsceneData_overlay, _ZN12CCutsceneMgr26DeleteCutsceneData_overlayEv, void);
    DECL_FASTCALL_SIMPLE(SetCutsceneAnimToLoop, _ZN12CCutsceneMgr21SetCutsceneAnimToLoopEPKc, void, const char *pName);
    DECL_FASTCALL_SIMPLE(AttachObjectToFrame, _ZN12CCutsceneMgr19AttachObjectToFrameEP7CObjectP7CEntityPKc, void, CObject *pObject, CEntity *pParent, const char *pName);
    DECL_FASTCALL_SIMPLE(AttachObjectToParent, _ZN12CCutsceneMgr20AttachObjectToParentEP7CObjectP7CEntity, void, CObject *pObject, CEntity *pParent);
    DECL_FASTCALL_SIMPLE(StartCutscene, _ZN12CCutsceneMgr13StartCutsceneEv, void);
    DECL_FASTCALL_SIMPLE(SetupCutsceneToStart, _ZN12CCutsceneMgr20SetupCutsceneToStartEv, void);
    DECL_FASTCALL_SIMPLE(Update_overlay, _ZN12CCutsceneMgr14Update_overlayEv, void);
    DECL_FASTCALL_SIMPLE(GetCutsceneTimeInMilleseconds, _ZN12CCutsceneMgr29GetCutsceneTimeInMillesecondsEv, u32);
    DECL_FASTCALL_SIMPLE(SkipCutscene, _ZN12CCutsceneMgr12SkipCutsceneEv, void);
    DECL_FASTCALL_SIMPLE(FinishCutscene, _ZN12CCutsceneMgr14FinishCutsceneEv, void);
    DECL_FASTCALL_SIMPLE(HasCutsceneFinished, _ZN12CCutsceneMgr19HasCutsceneFinishedEv, bool);

    // STATIC values
    DECL_VALUE_PLT_BOOL(ms_useCutsceneShadows, BYBIT(0x67744C, 0x84C8D0));
    DECL_VALUE_PLT_I32(ms_cutsceneLoadStatus, BYBIT(0x678B54, 0x84F6D0));
    DECL_VALUE_PLT_BOOL(ms_animLoaded, BYBIT(0x677E94, 0x84DD48));
    DECL_VALUE_PLT_BOOL(ms_running, BYBIT(0x679D74, 0x851B00));
    DECL_VALUE_PLT_BOOL(ms_cutsceneProcessing, BYBIT(0x6774B0, 0x84C998));
    DECL_VALUE_PLT_BOOL(ms_useLodMultiplier, BYBIT(0x678560, 0x84EAD8));
    DECL_VALUE_PLT_BOOL(ms_wasCutsceneSkipped, BYBIT(0x677FE0, 0x84DFE0));
    DECL_VALUE_PLT_BOOL(ms_hasFileInfo, BYBIT(0x678A20, 0x84F460));
    DECL_VALUE_PLT_BOOL(IntroTextIsActiveHack, BYBIT(0x678354, 0x84E6C0));
    DECL_OBJECT_PLT(CDirectory*, ms_pCutsceneDir, BYBIT(0x678940, 0x84F2A0));
    DECL_VALUE_PLT_I32(ms_numAppendObjectNames, BYBIT(0x677234, 0x84C4A0));
    DECL_OBJECT_ARRAY_PLT(char, ms_cAppendObjectName, BYBIT(0x679C98, 0x84C4A0));
    DECL_OBJECT_ARRAY_PLT(char, ms_cAppendAnimName, BYBIT(0x678B38, 0x851948));
    DECL_OBJECT_ARRAY_PLT(char, ms_cutsceneName, BYBIT(0x6794B8, 0x850988));
    DECL_OBJECT_PLT(CAnimBlendAssocGroup, ms_cutsceneAssociations, BYBIT(0x676EB4, 0x84BDA8));
    DECL_VALUE_PLT_I32(ms_cutscenePlayStatus, BYBIT(0x679A28, 0x851468));
    DECL_VALUE_PLT_FLT(ms_cutsceneTimer, BYBIT(0x678F30, 0x84FE88));
    DECL_OBJECT_PLT(CVector, ms_cutsceneOffset, BYBIT(0x675F7C, 0x849F68));
    DECL_VALUE_PLT_I32(ms_numCutsceneObjs, BYBIT(0x6791BC, 0x850398));
    DECL_OBJECT_ARRAY_PLT(CObject*, ms_pCutsceneObjects, BYBIT(0x67669C, 0x84AD90));
    DECL_VALUE_PLT_I32(ms_numLoadObjectNames, BYBIT(0x675F6C, 0x849F48));
    DECL_OBJECT_ARRAY_PLT(char, ms_cLoadObjectName, BYBIT(0x676EEC, 0x84BE18));
    DECL_OBJECT_ARRAY_PLT(char, ms_cLoadAnimName, BYBIT(0x679F9C, 0x851F48));
    DECL_OBJECT_ARRAY_PLT(i32, ms_iModelIndex, BYBIT(0x676258, 0x84A510));
    DECL_VALUE_PLT_I32(ms_numTextOutput, BYBIT(0x6795F0, 0x850BF0));
    DECL_VALUE_PLT_I32(ms_currTextOutput, BYBIT(0x678AE4, 0x84F5F0));
    DECL_OBJECT_ARRAY_PLT(char, ms_cTextOutput, BYBIT(0x678F90, 0x84FF48));
    DECL_OBJECT_ARRAY_PLT(i32, ms_iTextStartTime, BYBIT(0x6774A0, 0x84C978));
    DECL_OBJECT_ARRAY_PLT(i32, ms_iTextDuration, BYBIT(0x6765E8, 0x84AC28));
    DECL_OBJECT_ARRAY_PLT(char, ms_aUncompressedCutsceneAnims, BYBIT(0x675FAC, 0x849FC8));
    DECL_VALUE_PLT_I32(ms_numUncompressedCutsceneAnims, BYBIT(0x677260, 0x84C4F8));
    DECL_OBJECT_ARRAY_PLT(i32, ms_iAttachObjectToBone, BYBIT(0x6769D8, 0x84B3F8));
    DECL_OBJECT_ARRAY_PLT(bool, ms_bRepeatObject, BYBIT(0x6778F8, 0x84D218));
    DECL_VALUE_PLT_I32(ms_numAttachObjectToBones, BYBIT(0x677F0C, 0x84DE38));
    DECL_OBJECT_ARRAY_PLT(CEntity*, ms_pHiddenEntities, BYBIT(0x6763C4, 0x84A7E0));
    DECL_VALUE_PLT_I32(ms_iNumHiddenEntities, BYBIT(0x6782C0, 0x84E598));
    //DECL_OBJECT_ARRAY_PLT(CutsceneRemove, ms_crToHideItems, BYBIT(0x, 0x));
    //DECL_OBJECT_ARRAY_PLT(CutscenePEffect, ms_pParticleEffects, BYBIT(0x, 0x));
    DECL_VALUE_PLT_I32(ms_iNumParticleEffects, BYBIT(0x677940, 0x84D2A8));
    DECL_VALUE_PLT_I32(m_PrevExtraColour, BYBIT(0x6774AC, 0x84C990));
    DECL_VALUE_PLT_BOOL(m_PrevExtraColourOn, BYBIT(0x678988, 0x84F330));
    DECL_VALUE_PLT_FLT(m_fPrevPedDensity, BYBIT(0x678558, 0x84EAC8));
    DECL_VALUE_PLT_FLT(m_fPrevCarDensity, BYBIT(0x679358, 0x8506C8));
DECL_CLASS_END()

#define ms_useCutsceneShadows ms_useCutsceneShadows()
#define ms_cutsceneLoadStatus ms_cutsceneLoadStatus()
#define ms_animLoaded ms_animLoaded()
#define ms_running ms_running()
#define ms_cutsceneProcessing ms_cutsceneProcessing()
#define ms_useLodMultiplier ms_useLodMultiplier()
#define ms_wasCutsceneSkipped ms_wasCutsceneSkipped()
#define ms_hasFileInfo ms_hasFileInfo()
#define IntroTextIsActiveHack IntroTextIsActiveHack()
#define ms_pCutsceneDir ms_pCutsceneDir()
#define ms_numAppendObjectNames ms_numAppendObjectNames()
#define ms_cAppendObjectName ms_cAppendObjectName()
#define ms_cAppendAnimName ms_cAppendAnimName()
#define ms_cutsceneName ms_cutsceneName()
#define ms_cutsceneAssociations ms_cutsceneAssociations()
#define ms_cutscenePlayStatus ms_cutscenePlayStatus()
#define ms_cutsceneTimer ms_cutsceneTimer()
#define ms_cutsceneOffset ms_cutsceneOffset()
#define ms_numCutsceneObjs ms_numCutsceneObjs()
#define ms_pCutsceneObjects ms_pCutsceneObjects()
#define ms_numLoadObjectNames ms_numLoadObjectNames()
#define ms_cLoadObjectName ms_cLoadObjectName()
#define ms_cLoadAnimName ms_cLoadAnimName()
#define ms_iModelIndex ms_iModelIndex()
#define ms_numTextOutput ms_numTextOutput()
#define ms_currTextOutput ms_currTextOutput()
#define ms_cTextOutput ms_cTextOutput()
#define ms_iTextStartTime ms_iTextStartTime()
#define ms_iTextDuration ms_iTextDuration()
#define ms_aUncompressedCutsceneAnims ms_aUncompressedCutsceneAnims()
#define ms_numUncompressedCutsceneAnims ms_numUncompressedCutsceneAnims()
#define ms_iAttachObjectToBone ms_iAttachObjectToBone()
#define ms_bRepeatObject ms_bRepeatObject()
#define ms_numAttachObjectToBones ms_numAttachObjectToBones()
#define ms_pHiddenEntities ms_pHiddenEntities()
#define ms_iNumHiddenEntities ms_iNumHiddenEntities()
#define ms_crToHideItems ms_crToHideItems()
#define ms_pParticleEffects ms_pParticleEffects()
#define ms_iNumParticleEffects ms_iNumParticleEffects()
#define m_PrevExtraColour m_PrevExtraColour()
#define m_PrevExtraColourOn m_PrevExtraColourOn()
#define m_fPrevPedDensity m_fPrevPedDensity()
#define m_fPrevCarDensity m_fPrevCarDensity()

#endif // __AML_PSDK_SACUTSCENEMGR_H