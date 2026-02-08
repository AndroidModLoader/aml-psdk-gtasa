#ifndef __AML_PSDK_SAWORLD_H
#define __AML_PSDK_SAWORLD_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/game_sa/base/ColModel.h>
#include <aml-psdk/game_sa/other/PlayerInfo.h>

struct CEntity;
struct CSector;
struct CRepeatSector;
struct CColLine;
struct CPtrList;
struct CBox;
struct CMatrix;
struct CVehicle;
struct CPed;

DECL_CLASS(CWorld)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(ResetLineTestOptions, _ZN6CWorld20ResetLineTestOptionsEv, void);
    DECL_FASTCALL_SIMPLE(Initialise, _ZN6CWorld10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(ShutDown, _ZN6CWorld8ShutDownEv, void);
    DECL_FASTCALL_SIMPLE(Remove, _ZN6CWorld6RemoveEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(ClearForRestart, _ZN6CWorld15ClearForRestartEv, void);
    DECL_FASTCALL_SIMPLE(Add, _ZN6CWorld3AddEP7CEntity, void);
    DECL_FASTCALL_SIMPLE(GetIsLineOfSightClear, _ZN6CWorld21GetIsLineOfSightClearERK7CVectorS2_bbbbbbb, bool,
        CVector const& vecStart, CVector const& vecEnd, bool bCheckBuildings, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects, bool bCheckDummies, bool bSeeThroughStuff, bool bIgnoreSomeObjectsForCamera);
    DECL_FASTCALL_SIMPLE(GetIsLineOfSightSectorClear, _ZN6CWorld27GetIsLineOfSightSectorClearER7CSectorR13CRepeatSectorRK8CColLinebbbbbbb, bool,
        CSector &sector, CRepeatSector &rsector, CColLine const& line, bool bCheckBuildings, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects, bool bCheckDummies, bool bSeeThroughStuff, bool bIgnoreSomeObjectsForCamera);
    DECL_FASTCALL_SIMPLE(ProcessLineOfSight, _ZN6CWorld18ProcessLineOfSightERK7CVectorS2_R9CColPointRP7CEntitybbbbbbbb, bool,
        CVector const& vecStart, CVector const& vecEnd, CColPoint &colPoint, CEntity*& refEntityPtr, bool bCheckBuildings, bool bCheckVehicles, int bCheckPeds, bool bCheckObjects, bool bCheckDummies, bool bSeeThroughStuff, bool bIgnoreSomeObjectsForCamera, bool bShootThroughStuff);
    DECL_FASTCALL_SIMPLE(ProcessLineOfSightSector, _ZN6CWorld24ProcessLineOfSightSectorER7CSectorR13CRepeatSectorRK8CColLineR9CColPointRfRP7CEntitybbbbbbbb, bool,
        CSector &sector, CRepeatSector &rsector, CColLine const& line, CColPoint &colPoint, float &fCollisionRatio, CEntity*& refEntityPtr, bool bCheckBuildings, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects, bool bCheckDummies, bool bSeeThroughStuff, bool bIgnoreSomeObjectsForCamera, bool bShootThroughStuff);
    DECL_FASTCALL_SIMPLE(ProcessLineOfSightSectorList, _ZN6CWorld28ProcessLineOfSightSectorListER8CPtrListRK8CColLineR9CColPointRfRP7CEntitybbb, bool,
        CPtrList &list, CColLine const& line, CColPoint &colPoint, float &fCollisionRatio, CEntity*& refEntityPtr, bool bSeeThroughStuff, bool bIgnoreSomeObjectsForCamera, bool bShootThroughStuff);
    DECL_FASTCALL_SIMPLE(CameraToIgnoreThisObject, _ZN6CWorld24CameraToIgnoreThisObjectEP7CEntity, bool, CEntity *pObject);
    DECL_FASTCALL_SIMPLE(ProcessVerticalLine, _ZN6CWorld19ProcessVerticalLineERK7CVectorfR9CColPointRP7CEntitybbbbbbP15CStoredCollPoly, bool,
        CVector const& vecStart, float zEnd, CColPoint &colPoint, CEntity*& refEntityPtr, bool bCheckBuildings, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects, bool bCheckDummies, bool bSeeThroughStuff, CStoredCollPoly *pStoredPoly);
    DECL_FASTCALL_SIMPLE(ProcessVerticalLineSector, _ZN6CWorld25ProcessVerticalLineSectorER7CSectorR13CRepeatSectorRK8CColLineR9CColPointRP7CEntitybbbbbbP15CStoredCollPoly, bool,
    
        CSector &sector, CRepeatSector &rsector, CColLine const& Line, CColPoint &colPoint, CEntity*& refEntityPtr, bool bCheckBuildings, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects, bool bCheckDummies, bool bSeeThroughStuff, CStoredCollPoly *pStoredPoly);
    DECL_FASTCALL_SIMPLE(ProcessVerticalLine_FillGlobeColPoints, _ZN6CWorld38ProcessVerticalLine_FillGlobeColPointsERK7CVectorfRP7CEntitybbbbbbP15CStoredCollPoly, bool,
        CVector const& vecStart, float zEnd, CEntity*& refEntityPtr, bool bCheckBuildings, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects, bool bCheckDummies, bool bSeeThroughStuff, CStoredCollPoly *pStoredPoly);
    DECL_FASTCALL_SIMPLE(ProcessVerticalLineSector_FillGlobeColPoints, _ZN6CWorld44ProcessVerticalLineSector_FillGlobeColPointsER7CSectorR13CRepeatSectorRK8CColLineRP7CEntitybbbbbbP15CStoredCollPoly, bool,
        CSector &sector, CRepeatSector &rsector, CColLine const& Line, CEntity*& refEntityPtr, bool bCheckBuildings, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects, bool bCheckDummies, bool bSeeThroughStuff, CStoredCollPoly *pStoredPoly);
    DECL_FASTCALL_SIMPLE(ProcessVerticalLineSectorList_FillGlobeColPoints, _ZN6CWorld48ProcessVerticalLineSectorList_FillGlobeColPointsER8CPtrListRK8CColLineRP7CEntitybP15CStoredCollPoly, bool,
        CPtrList &list, CColLine const& Line, CEntity*& refEntityPtr, bool bSeeThroughStuff, CStoredCollPoly *pStoredPoly);
    DECL_FASTCALL_SIMPLE(ProcessVerticalLineSectorList, _ZN6CWorld29ProcessVerticalLineSectorListER8CPtrListRK8CColLineR9CColPointRfRP7CEntitybP15CStoredCollPoly, bool, 
        CPtrList &list, CColLine const& Line, CColPoint &colPoint, float &fCollisionRatio, CEntity*& refEntityPtr, bool bSeeThroughStuff, CStoredCollPoly *pStoredPoly);
    DECL_FASTCALL_SIMPLE(TriggerExplosion, _ZN6CWorld16TriggerExplosionERK7CVectorffP7CEntityS4_bf, void,
        CVector const& vecPosition, float fEffectRadius, float fImpulseMagnitude, CEntity *pExplodingEntity, CEntity *pExplosionOwner, bool BlowUpQuick, float DamagePercentage);
    DECL_FASTCALL_SIMPLE(TriggerExplosionSectorList, _ZN6CWorld26TriggerExplosionSectorListER8CPtrListRK7CVectorffP7CEntityS6_bf, void,
        CPtrList &list, CVector const& vecPosition, float fEffectRadius, float fImpulseMagnitude, CEntity *pExplodingEntity, CEntity *pExplosionOwner, bool BlowUpQuick, float DamagePercentage);
    DECL_FASTCALL_SIMPLE(CastShadow, _ZN6CWorld10CastShadowEffff, void, float xmin, float ymin, float xmax, float ymax);
    DECL_FASTCALL_SIMPLE(CastShadowSectorList, _ZN6CWorld20CastShadowSectorListER8CPtrListffff, void, CPtrList &list, float xmin, float ymin, float xmax, float ymax);
    DECL_FASTCALL_SIMPLE(ProcessForAnimViewer, _ZN6CWorld20ProcessForAnimViewerEv, void);
    DECL_FASTCALL_SIMPLE(Process, _ZN6CWorld7ProcessEv, void);
    DECL_FASTCALL_SIMPLE(RemoveEntityInsteadOfProcessingIt, _ZN6CWorld33RemoveEntityInsteadOfProcessingItEP7CEntity, void, CEntity *pEntityToRemove);
    DECL_FASTCALL_SIMPLE(ProcessAttachedEntities, _ZN6CWorld23ProcessAttachedEntitiesEv, void);
    DECL_FASTCALL_SIMPLE(RemoveFallenPeds, _ZN6CWorld16RemoveFallenPedsEv, void);
    DECL_FASTCALL_SIMPLE(RemoveFallenCars, _ZN6CWorld16RemoveFallenCarsEv, void);
    DECL_FASTCALL_SIMPLE(ProcessPedsAfterPreRender, _ZN6CWorld25ProcessPedsAfterPreRenderEv, void);
    DECL_FASTCALL_SIMPLE(ClearScanCodes, _ZN6CWorld14ClearScanCodesEv, void);
    DECL_FASTCALL_SIMPLE(GetIsLineOfSightSectorListClear, _ZN6CWorld31GetIsLineOfSightSectorListClearER8CPtrListRK8CColLinebb, bool,
        CPtrList &list, CColLine const& line, bool bSeeThroughStuff, bool bIgnoreSomeObjectsForCamera);
    DECL_FASTCALL_SIMPLE(FindObjectsInRange, _ZN6CWorld18FindObjectsInRangeERK7CVectorfbPssPP7CEntitybbbbb, void,
        CVector const& Coors, float Range, bool Dist2D, i16 *pNum, i16 MaxNum, CEntity **ppResults, bool bCheckBuildings, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects, bool bCheckDummies);
    DECL_FASTCALL_SIMPLE(FindObjectsInRangeSectorList, _ZN6CWorld28FindObjectsInRangeSectorListER8CPtrListRK7CVectorfbPssPP7CEntity, void,
        CPtrList &list, CVector const& Coors, float Range, bool Dist2D, i16 *pNum, i16 MaxNum, CEntity **ppResults);
    DECL_FASTCALL_SIMPLE(FindObjectsOfTypeInRange, _ZN6CWorld24FindObjectsOfTypeInRangeEjRK7CVectorfbPssPP7CEntitybbbbb, void,
        u32 ModelIndx, CVector const& Coors, float Range, bool Dist2D, i16 *pNum, i16 MaxNum, CEntity **ppResults, bool bCheckBuildings, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects, bool bCheckDummies);
    DECL_FASTCALL_SIMPLE(FindObjectsOfTypeInRangeSectorList, _ZN6CWorld34FindObjectsOfTypeInRangeSectorListEjR8CPtrListRK7CVectorfbPssPP7CEntity, void,
        u32 ModelIndx, CPtrList &list, CVector const& Coors, float Range, bool Dist2D, i16 *pNum, i16 MaxNum, CEntity **ppResults);
    DECL_FASTCALL_SIMPLE(FindLodOfTypeInRange, _ZN6CWorld20FindLodOfTypeInRangeEjRK7CVectorfbPssPP7CEntity, void,
        u32 ModelIndx, CVector const& Coors, float Range, bool Dist2D, i16 *pNum, i16 MaxNum, CEntity **ppResults);
    DECL_FASTCALL_SIMPLE(FindObjectsKindaColliding, _ZN6CWorld25FindObjectsKindaCollidingERK7CVectorfbPssPP7CEntitybbbbb, void,
        CVector const& Coors, float Range, bool Dist2D, i16 *pNum, i16 MaxNum, CEntity **ppResults, bool bCheckBuildings, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects, bool bCheckDummies);
    DECL_FASTCALL_SIMPLE(FindObjectsKindaCollidingSectorList, _ZN6CWorld35FindObjectsKindaCollidingSectorListER8CPtrListRK7CVectorfbPssPP7CEntity, void,
        CPtrList &list, CVector const& Coors, float Range, bool Dist2D, i16 *pNum, i16 MaxNum, CEntity **ppResults);
    DECL_FASTCALL_SIMPLE(FindObjectsIntersectingCube, _ZN6CWorld27FindObjectsIntersectingCubeERK7CVectorS2_PssPP7CEntitybbbbb, void,
        CVector const& Coors, CVector const& CoorsMax, i16 *pNum, i16 MaxNum, CEntity **ppResults, bool bCheckBuildings, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects, bool bCheckDummies);
    DECL_FASTCALL_SIMPLE(FindObjectsIntersectingCubeSectorList, _ZN6CWorld37FindObjectsIntersectingCubeSectorListER8CPtrListRK7CVectorS4_PssPP7CEntity, void,
        CPtrList &list, CVector const& CoorsMin, CVector const& CoorsMax, i16 *pNum, i16 MaxNum, CEntity **ppResults);
    DECL_FASTCALL_SIMPLE(FindObjectsIntersectingAngledCollisionBox, _ZN6CWorld41FindObjectsIntersectingAngledCollisionBoxERK4CBoxRK7CMatrixRK7CVectorffffPssPP7CEntitybbbbb, void,
        CBox const& Box, CMatrix const& RotationOfBoxMatrix, CVector const& BoxCentre, float MinX, float MinY, float MaxX, float MaxY, i16 *pNum, i16 MaxNum, CEntity **ppResults, bool bCheckBuildings, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects, bool bCheckDummies);
    DECL_FASTCALL_SIMPLE(FindObjectsIntersectingAngledCollisionBoxSectorList, _ZN6CWorld51FindObjectsIntersectingAngledCollisionBoxSectorListER8CPtrListRK4CBoxRK7CMatrixRK7CVectorPssPP7CEntity, void,
        CPtrList &list, CBox const& Box, CMatrix const& RotationOfBoxMatrix, CVector const& BoxCentre, i16 *pNum, i16 MaxNum, CEntity **ppResults);
    DECL_FASTCALL_SIMPLE(FindMissionEntitiesIntersectingCube, _ZN6CWorld35FindMissionEntitiesIntersectingCubeERK7CVectorS2_PssPP7CEntitybbb, void,
        CVector const& CoorsMin, CVector const& CoorsMax, i16 *pNum, i16 MaxNum, CEntity **ppResults, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects);
    DECL_FASTCALL_SIMPLE(FindMissionEntitiesIntersectingCubeSectorList, _ZN6CWorld45FindMissionEntitiesIntersectingCubeSectorListER8CPtrListRK7CVectorS4_PssPP7CEntitybbb, void,
        CPtrList &list, CVector const& CoorsMin, CVector const& CoorsMax, i16 *pNum, i16 MaxNum, CEntity **ppResults, bool EntitiesAreVehicles, bool EntitiesArePeds, bool EntitiesAreObjects);
    DECL_FASTCALL_SIMPLE(FindNearestObjectOfType, _ZN6CWorld23FindNearestObjectOfTypeEiRK7CVectorfbbbbbb, CEntity*,
        i32 ModelIndex, CVector const& Coors, float Range, bool Dist2D, bool bCheckBuildings, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects, bool bCheckDummies);
    DECL_FASTCALL_SIMPLE(FindNearestObjectOfTypeSectorList, _ZN6CWorld33FindNearestObjectOfTypeSectorListEiR8CPtrListRK7CVectorfbPP7CEntityPf, void,
        i32 ModelIndex, CPtrList &list, CVector const& Coors, float Range, bool Dist2D, CEntity **ppResult, float *pNearestDist);
    DECL_FASTCALL_SIMPLE(FindGroundZForCoord, _ZN6CWorld19FindGroundZForCoordEff, float, float x, float y);
    DECL_FASTCALL_SIMPLE(FindGroundZFor3DCoord, _ZN6CWorld21FindGroundZFor3DCoordEfffPbPP7CEntity, float, float x, float y, float z, bool *pBool, CEntity **ppEnt);
    DECL_FASTCALL_SIMPLE(FindRoofZFor3DCoord, _ZN6CWorld19FindRoofZFor3DCoordEfffPb, float, float x, float y, float z, bool *pBool);
    DECL_FASTCALL_SIMPLE(FindLowestZForCoord, _ZN6CWorld19FindLowestZForCoordEff, float, float x, float y);
    DECL_FASTCALL_SIMPLE(RemoveReferencesToDeletedObject, _ZN6CWorld31RemoveReferencesToDeletedObjectEP7CEntity, void, CEntity *pToBeDeletedEntity);
    DECL_FASTCALL_SIMPLE(SetPedsOnFire, _ZN6CWorld13SetPedsOnFireEffffP7CEntity, void, float CenterX, float CenterY, float CenterZ, float Radius, CEntity *pCulprit);
    DECL_FASTCALL_SIMPLE(SetPedsChoking, _ZN6CWorld14SetPedsChokingEffffP7CEntity, void, float CenterX, float CenterY, float CenterZ, float Radius, CEntity *pCulprit);
    DECL_FASTCALL_SIMPLE(SetCarsOnFire, _ZN6CWorld13SetCarsOnFireEffffP7CEntity, void, float CenterX, float CenterY, float CenterZ, float Radius, CEntity *pCulprit);
    DECL_FASTCALL_SIMPLE(SetWorldOnFire, _ZN6CWorld14SetWorldOnFireEffffP7CEntity, void, float CenterX, float CenterY, float CenterZ, float Radius, CEntity *pCulprit);
    DECL_FASTCALL_SIMPLE(TestSphereAgainstWorld, _ZN6CWorld22TestSphereAgainstWorldE7CVectorfP7CEntitybbbbbb, CEntity*,
        CVector Coors, float Radius, CEntity *pException, bool bCheckBuildings, bool bCheckVehicles, bool bCheckPeds, bool bCheckObjects, bool bCheckDummies, bool bCamIgnoreCertainObjects);
    DECL_FASTCALL_SIMPLE(SprayPaintWorld, _ZN6CWorld15SprayPaintWorldER7CVectorS1_fb, int, CVector &vecPos, CVector &vecHitNormal, float fRadius, bool bFadeUp);
    DECL_FASTCALL_SIMPLE(RepositionCertainDynamicObjects, _ZN6CWorld31RepositionCertainDynamicObjectsEv, void);
    DECL_FASTCALL_SIMPLE(RepositionOneObject, _ZN6CWorld19RepositionOneObjectEP7CEntity, void, CEntity *pEntity);
    DECL_FASTCALL_SIMPLE(UseDetonator, _ZN6CWorld12UseDetonatorEP7CEntity, void, CEntity *pUser);
    DECL_FASTCALL_SIMPLE(TestSphereAgainstSectorList, _ZN6CWorld27TestSphereAgainstSectorListER8CPtrList7CVectorfP7CEntityb, CEntity*,
        CPtrList &list, CVector Coors, float Radius, CEntity *pException, bool bCamIgnoreCertainObjects);
    DECL_FASTCALL_SIMPLE(PrintCarChanges, _ZN6CWorld15PrintCarChangesEv, void);
    DECL_FASTCALL_SIMPLE(RemoveStaticObjects, _ZN6CWorld19RemoveStaticObjectsEv, void);
    DECL_FASTCALL_SIMPLE(TestForUnusedModels, _ZN6CWorld19TestForUnusedModelsER8CPtrListPi, void, CPtrList &list, i32 *modelCounts);
    DECL_FASTCALL_SIMPLE(ClearExcitingStuffFromArea, _ZN6CWorld26ClearExcitingStuffFromAreaERK7CVectorfh, void, CVector const& Centre, float Radius, u8 bRemoveProjectiles);
    DECL_FASTCALL_SIMPLE(ExtinguishAllCarFiresInArea, _ZN6CWorld27ExtinguishAllCarFiresInAreaE7CVectorf, void, CVector Centre, float Radius);
    DECL_FASTCALL_SIMPLE(ClearCarsFromArea, _ZN6CWorld17ClearCarsFromAreaEffffff, void, float MinX, float MinY, float MinZ, float MaxX, float MaxY, float MaxZ);
    DECL_FASTCALL_SIMPLE(ClearPedsFromArea, _ZN6CWorld17ClearPedsFromAreaEffffff, void, float MinX, float MinY, float MinZ, float MaxX, float MaxY, float MaxZ);
    DECL_FASTCALL_SIMPLE(SetAllCarsCanBeDamaged, _ZN6CWorld22SetAllCarsCanBeDamagedEb, void, bool bDmgFlag);
    DECL_FASTCALL_SIMPLE(CallOffChaseForArea, _ZN6CWorld19CallOffChaseForAreaEffff, void, float MinX, float MinY, float MaxX, float MaxY);
    DECL_FASTCALL_SIMPLE(CallOffChaseForAreaSectorListVehicles, _ZN6CWorld37CallOffChaseForAreaSectorListVehiclesER8CPtrListffffffff, void,
        CPtrList &list, float MinX, float MinY, float MaxX, float MaxY, float BiggerMinX, float BiggerMinY, float BiggerMaxX, float BiggerMaxY);
    DECL_FASTCALL_SIMPLE(CallOffChaseForAreaSectorListPeds, _ZN6CWorld33CallOffChaseForAreaSectorListPedsER8CPtrListffffffff, void,
        CPtrList &list, float MinX, float MinY, float MaxX, float MaxY, float BiggerMinX, float BiggerMinY, float BiggerMaxX, float BiggerMaxY);
    DECL_FASTCALL_SIMPLE(StopAllLawEnforcersInTheirTracks, _ZN6CWorld32StopAllLawEnforcersInTheirTracksEv, void);
    DECL_FASTCALL_SIMPLE(FindPlayerSlotWithPedPointer, _ZN6CWorld28FindPlayerSlotWithPedPointerEPv, i32, void *pPlayersPed);
    DECL_FASTCALL_SIMPLE(FindPlayerSlotWithRemoteVehiclePointer, _ZN6CWorld38FindPlayerSlotWithRemoteVehiclePointerEPv, i32, void *pRemote);
    DECL_FASTCALL_SIMPLE(FindPlayerSlotWithVehiclePointer, _ZN6CWorld32FindPlayerSlotWithVehiclePointerEP7CEntity, i32, CEntity *pEntity);
    DECL_FASTCALL_SIMPLE(FindUnsuspectingTargetCar, _ZN6CWorld25FindUnsuspectingTargetCarE7CVectorS0_, CVehicle*, CVector Coors, CVector AimTowardsCoors);
    DECL_FASTCALL_SIMPLE(FindUnsuspectingTargetPed, _ZN6CWorld25FindUnsuspectingTargetPedE7CVectorS0_, CPed*, CVector Coors, CVector AimTowardsCoors);
    
    // STATIC members
    DECL_OBJECT_ARRAY_PLT(CPlayerInfo, Players, BYBIT(0x6783C8, 0x84E7A8));
    DECL_VALUE_PLT_U8(PlayerInFocus, BYBIT(0x679B5C, 0x8516D8));
    DECL_VALUE_PLT_U8(bNoMoreCollisionTorque, BYBIT(0x678BB0, 0x84F788));
    DECL_VALUE_PLT_U8(bIncludeDeadPeds, BYBIT(0x675FA8, 0x849FC0));
    DECL_VALUE_PLT_U8(bIncludeCarTyres, BYBIT(0x6765E0, 0x84AC18));
    DECL_VALUE_PLT_U8(bIncludeBikers, BYBIT(0x67620C, 0x84A478));
    DECL_VALUE_PLT_U8(bForceProcessControl, BYBIT(0x6771FC, 0x84C430));
    DECL_VALUE_PLT_U8(bProcessCutsceneOnly, BYBIT(0x678470, 0x84E8F8));
    DECL_VALUE_PLT_U8(bSecondShift, BYBIT(0x678B28, 0x84F678));
    DECL_OBJECT_PLT(CEntity*, pIgnoreEntity, BYBIT(0x676894, 0x84B180));
    DECL_VALUE_PLT_FLT(fWeaponSpreadRate, BYBIT(0x679CF4, 0x851A00));
    DECL_VALUE_PLT_U32(ms_iProcessLineNumCrossings, BYBIT(0x67905C, 0x8500E0));
    DECL_OBJECT_ARRAY_PLT(CSector, ms_aSectors, BYBIT(0x676734, 0x84AEC0));
    DECL_OBJECT_ARRAY_PLT(CRepeatSector, ms_aRepeatSectors, BYBIT(0x6771E4, 0x84C400));
    DECL_OBJECT_ARRAY_PLT(CPtrListSingleLink, ms_aLodPtrLists, BYBIT(0x67738C, 0x84C750));
    DECL_OBJECT_PLT(CPtrListDoubleLink, ms_listMovingEntityPtrs, BYBIT(0x678E98, 0x84FD58));
    DECL_OBJECT_PLT(CPtrListDoubleLink, ms_listObjectsWithControlCode, BYBIT(0x678190, 0x84E338));
    DECL_VALUE_PLT_U16(ms_nCurrentScanCode, BYBIT(0x6766A4, 0x84ADA0));
    DECL_OBJECT_ARRAY_PLT(CColPoint, m_aTempColPts, BYBIT(0x677DE0, 0x84DBE0));
DECL_CLASS_END()

#define PlayerInFocus PlayerInFocus()
#define bNoMoreCollisionTorque bNoMoreCollisionTorque()
#define bIncludeDeadPeds bIncludeDeadPeds()
#define bIncludeCarTyres bIncludeCarTyres()
#define bIncludeBikers bIncludeBikers()
#define bForceProcessControl bForceProcessControl()
#define bProcessCutsceneOnly bProcessCutsceneOnly()
#define bSecondShift bSecondShift()
#define fWeaponSpreadRate fWeaponSpreadRate()
#define ms_iProcessLineNumCrossings ms_iProcessLineNumCrossings()
#define ms_listMovingEntityPtrs ms_listMovingEntityPtrs()
#define ms_listObjectsWithControlCode ms_listObjectsWithControlCode()
#define ms_nCurrentScanCode ms_nCurrentScanCode()

#endif // __AML_PSDK_SAWORLD_H
