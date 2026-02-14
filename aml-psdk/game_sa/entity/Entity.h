#ifndef __AML_PSDK_SAENTITY_H
#define __AML_PSDK_SAENTITY_H

#include "Placeable.h"
#include <aml-psdk/gta_base/Rect.h>
#include "../base/ColModel.h"
#include "../engine/2dEffect.h"

struct RwObject;
struct RpClump;
struct RpAtomic;
struct CPhysical;
struct CReference;
struct CPed;
struct CBuilding;
struct CDummy;
struct CVehicle;
struct CObject;

enum eEntityType : u8
{
    ENTITY_TYPE_NOTHING = 0,
    ENTITY_TYPE_BUILDING,
    ENTITY_TYPE_VEHICLE,
    ENTITY_TYPE_PED,
    ENTITY_TYPE_OBJECT,
    ENTITY_TYPE_DUMMY,
    ENTITY_TYPE_NOTINPOOLS
};

enum eEntityStatus : u8
{
    STATUS_PLAYER = 0,
    STATUS_PLAYER_PLAYBACKFROMBUFFER,
    STATUS_SIMPLE,
    STATUS_PHYSICS,
    STATUS_ABANDONED,
    STATUS_WRECKED,
    STATUS_TRAIN_MOVING,
    STATUS_TRAIN_NOT_MOVING,
    STATUS_PLAYER_REMOTE,
    STATUS_PLAYER_DISABLED,
    STATUS_TRAILER,
    STATUS_SIMPLE_TRAILER,
    STATUS_GHOST,
};

DECL_CLASS_BASED(CEntity, CPlaceable)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CEntity, _ZN7CEntityC2Ev);
    DECL_DTORCALL(CEntity, _ZN7CEntityD2Ev);

    // Virtual functions
    virtual int Add();
    virtual int Add(CRect&);
    virtual int Remove();
    virtual void SetIsStatic(bool isStatic);
    virtual void SetModelIndex(int modelIdx);
    virtual void SetModelIndexNoCreate(int modelIdx);
    virtual RwObject* CreateRwObject();
    virtual void DeleteRwObject();
    virtual CRect GetBoundRect();
    virtual void ProcessControl();
    virtual void ProcessCollision();
    virtual void ProcessShift();
    virtual bool TestCollision(bool applySpeed);
    virtual void Teleport(CVector destination, bool resetRotation = false);
    virtual void SpecialEntityPreCollisionStuff(CPhysical *pPhysical,bool bDoingShift,bool &bSkipTestEntirely,bool &bSkipCol,bool &bForceBuildingCol,bool &bForceSoftCol);
    virtual uint8_t SpecialEntityCalcCollisionSteps(bool& bProcessCollisionBeforeSettingTimeStep, bool& bDoPreCheckAtHalfSpeed);
    virtual void PreRender();                                                                                     
    virtual void Render();                                                                                            
    virtual bool SetupLighting();                                                                                
    virtual void RemoveLighting(bool bRemove);                                                               
    virtual void FlagToDestroyWhenNextProcessed();

    // Member functions
    DECL_THISCALL_SIMPLE(HasPreRenderEffects, _ZN7CEntity19HasPreRenderEffectsEv, bool);
    DECL_THISCALL_SIMPLE(CreateEffects, _ZN7CEntity13CreateEffectsEv, void);
    DECL_THISCALL_SIMPLE(DestroyEffects, _ZN7CEntity14DestroyEffectsEv, void);
    //DECL_THISCALL_SIMPLE(CreateRwObject, _ZN7CEntity14CreateRwObjectEv, void); // virtual
    DECL_THISCALL_SIMPLE(DetachFromRwObject, _ZN7CEntity18DetachFromRwObjectEv, void);
    //DECL_THISCALL_SIMPLE(DeleteRwObject, _ZN7CEntity14DeleteRwObjectEv, void); // virtual
    //DECL_THISCALL_SIMPLE(GetBoundRect, _ZNK7CEntity12GetBoundRectEv, CRect); // virtual
    DECL_THISCALL_SIMPLE(GetBoundCentre, _ZNK7CEntity14GetBoundCentreEv, CVector);
    DECL_THISCALL_SIMPLE(UpdateRwFrame, _ZN7CEntity13UpdateRwFrameEv, void);
    DECL_THISCALL_SIMPLE(UpdateRpHAnim, _ZN7CEntity13UpdateRpHAnimEv, void);
    DECL_THISCALL_SIMPLE(UpdateAnim, _ZN7CEntity10UpdateAnimEv, void);
    DECL_THISCALL_SIMPLE(GetIsOnScreen, _ZN7CEntity13GetIsOnScreenEv, bool);
    DECL_THISCALL_SIMPLE(DoesNotCollideWithFlyers, _ZN7CEntity24DoesNotCollideWithFlyersEv, bool);
    //DECL_THISCALL_SIMPLE(PreRender, _ZN7CEntity9PreRenderEv, void); // virtual
    DECL_THISCALL_SIMPLE(ModifyMatrixForTreeInWind, _ZN7CEntity25ModifyMatrixForTreeInWindEv, void);
    DECL_THISCALL_SIMPLE(ModifyMatrixForCrane, _ZN7CEntity20ModifyMatrixForCraneEv, void);
    DECL_THISCALL_SIMPLE(PreRenderForGlassWindow, _ZN7CEntity23PreRenderForGlassWindowEv, void);
    DECL_THISCALL_SIMPLE(BuildWindSockMatrix, _ZN7CEntity19BuildWindSockMatrixEv, void);
    DECL_THISCALL_SIMPLE(RenderEffects, _ZN7CEntity13RenderEffectsEv, void);
    //DECL_THISCALL_SIMPLE(Render, _ZN7CEntity6RenderEv, void); // virtual
    DECL_THISCALL_SIMPLE(IsVisible, _ZN7CEntity9IsVisibleEv, bool);
    DECL_THISCALL_SIMPLE(GetIsBoundingBoxOnScreen, _ZN7CEntity24GetIsBoundingBoxOnScreenEv, bool);
    //DECL_THISCALL_SIMPLE(Add, _ZN7CEntity3AddEv, void); // virtual
    //DECL_THISCALL_SIMPLE(Remove, _ZN7CEntity6RemoveEv, void); // virtual
    DECL_THISCALL_SIMPLE(GetDistanceFromCentreOfMassToBaseOfModel, _ZN7CEntity40GetDistanceFromCentreOfMassToBaseOfModelEv, float);
    DECL_THISCALL_SIMPLE(GetColModel, _ZN7CEntity11GetColModelEv, CColModel*);
    DECL_THISCALL_SIMPLE(SetupBigBuilding, _ZN7CEntity16SetupBigBuildingEv, void);
    DECL_THISCALL_SIMPLE(ModifyMatrixForBannerInWind, _ZN7CEntity27ModifyMatrixForBannerInWindEv, void);
    DECL_THISCALL_SIMPLE(PruneReferences, _ZN7CEntity15PruneReferencesEv, void);
    DECL_THISCALL_SIMPLE(ResolveReferences, _ZN7CEntity17ResolveReferencesEv, void);
    //DECL_THISCALL_SIMPLE(SetupLighting, _ZN7CEntity13SetupLightingEv, bool); // virtual
    DECL_THISCALL_SIMPLE(ProcessLightsForEntity, _ZN7CEntity22ProcessLightsForEntityEv, void);
    DECL_THISCALL_SIMPLE(RemoveEscalatorsForEntity, _ZN7CEntity25RemoveEscalatorsForEntityEv, void);
    DECL_THISCALL_SIMPLE(IsEntityOccluded, _ZN7CEntity16IsEntityOccludedEv, bool);

    DECL_THISCALL_HEAD(AttachToRwObject, _ZN7CEntity16AttachToRwObjectEP8RwObjectb, void, RwObject *pObj, bool bUpdateMatrix)
    DECL_THISCALL_TAIL(AttachToRwObject, pObj, bUpdateMatrix)

    DECL_THISCALL_NAMED_HEAD(GetBoundCentre2, GetBoundCentre, _ZNK7CEntity14GetBoundCentreER7CVector, void, CVector &centre)
    DECL_THISCALL_TAIL(GetBoundCentre2, centre)

    DECL_THISCALL_HEAD(GetIsTouching, _ZNK7CEntity13GetIsTouchingEPS_, bool, CEntity *pEntity)
    DECL_THISCALL_TAIL(GetIsTouching, pEntity)

    DECL_THISCALL_NAMED_HEAD(GetIsTouching2, GetIsTouching, _ZNK7CEntity13GetIsTouchingERK7CVectorf, bool, const CVector &centre, float radius)
    DECL_THISCALL_TAIL(GetIsTouching2, centre, radius)

    DECL_THISCALL_HEAD(LivesInThisNonOverlapSector, _ZN7CEntity27LivesInThisNonOverlapSectorEii, bool, i32 x, i32 y)
    DECL_THISCALL_TAIL(LivesInThisNonOverlapSector, x, y)

    DECL_THISCALL_HEAD(SetRwObjectAlpha, _ZN7CEntity16SetRwObjectAlphaEi, void, i32 nAlpha)
    DECL_THISCALL_TAIL(SetRwObjectAlpha, nAlpha)

    DECL_THISCALL_HEAD(FindTriggerPointCoors, _ZN7CEntity21FindTriggerPointCoorsEi, CVector, i32 ArgIndex)
    DECL_THISCALL_TAIL(FindTriggerPointCoors, ArgIndex)

    DECL_THISCALL_HEAD(CalculateBBProjection, _ZN7CEntity21CalculateBBProjectionEP7CVectorS1_S1_S1_, void, CVector *pPoint1, CVector *pPoint2, CVector *pPoint3, CVector *pPoint4)
    DECL_THISCALL_TAIL(CalculateBBProjection, pPoint1, pPoint2, pPoint3, pPoint4)

    DECL_THISCALL_HEAD(GetRandom2dEffect, _ZN7CEntity17GetRandom2dEffectEih, C2dEffect*, i32 effectType, b8 mustBeFree)
    DECL_THISCALL_TAIL(GetRandom2dEffect, effectType, mustBeFree)

    DECL_THISCALL_HEAD(RegisterReference, _ZN7CEntity17RegisterReferenceEPPS_, void, CEntity **ppAddress)
    DECL_THISCALL_TAIL(RegisterReference, ppAddress)

    DECL_THISCALL_HEAD(CleanUpOldReference, _ZN7CEntity19CleanUpOldReferenceEPPS_, void, CEntity **ppAddress)
    DECL_THISCALL_TAIL(CleanUpOldReference, ppAddress)

    // Helper functions
    inline unsigned char GetInterior() { return m_nInterior; }
    inline bool IsVehicle() const { return m_nType == ENTITY_TYPE_VEHICLE; }
    inline bool IsPed() const { return m_nType == ENTITY_TYPE_PED; }
    inline bool IsBuilding() const { return m_nType == ENTITY_TYPE_BUILDING; }
    inline bool IsObject() const { return m_nType == ENTITY_TYPE_OBJECT; }
    inline bool IsDummy() const { return m_nType == ENTITY_TYPE_DUMMY; }
    inline CVehicle* AsVehicle() { return (CVehicle*)this; }
    inline CPed* AsPed() { return (CPed*)this; }
    inline CBuilding* AsBuilding() { return (CBuilding*)this; }
    inline CObject* AsObject() { return (CObject*)this; }
    inline CDummy* AsDummy() { return (CDummy*)this; }

    // Member values
    union
    {
        RwObject *m_pRwObject;
        RpClump *m_pRwClump;
        RpAtomic *m_pRwAtomic;
    };
    unsigned int bUsesCollision : 1;           // does entity use collision
    unsigned int bCollisionProcessed : 1;  // has object been processed by a ProcessEntityCollision function
    unsigned int bIsStatic : 1;                // is entity static
    unsigned int bHasContacted : 1;            // has entity processed some contact forces
    unsigned int bIsStuck : 1;             // is entity stuck
    unsigned int bIsInSafePosition : 1;        // is entity in a collision free safe position
    unsigned int bWasPostponed : 1;            // was entity control processing postponed
    unsigned int bIsVisible : 1;               //is the entity visible
 
    unsigned int bIsBIGBuilding : 1;           // Set if this entity is a big building
    unsigned int bRenderDamaged : 1;           // use damaged LOD models for objects with applicable damage
    unsigned int bStreamingDontDelete : 1; // Dont let the streaming remove this 
    unsigned int bRemoveFromWorld : 1;     // remove this entity next time it should be processed
    unsigned int bHasHitWall : 1;              // has collided with a building (changes subsequent collisions)
    unsigned int bImBeingRendered : 1;     // don't delete me because I'm being rendered
    unsigned int bDrawLast :1;             // draw object last
    unsigned int bDistanceFade :1;         // Fade entity because it is far away
 
    unsigned int bDontCastShadowsOn : 1;       // Dont cast shadows on this object
    unsigned int bOffscreen : 1;               // offscreen flag. This can only be trusted when it is set to true
    unsigned int bIsStaticWaitingForCollision : 1; // this is used by script created entities - they are static until the collision is loaded below them
    unsigned int bDontStream : 1;              // tell the streaming not to stream me
    unsigned int bUnderwater : 1;              // this object is underwater change drawing order
    unsigned int bHasPreRenderEffects : 1; // Object has a prerender effects attached to it
    unsigned int bIsTempBuilding : 1;          // whether or not the building is temporary (i.e. can be created and deleted more than once)
    unsigned int bDontUpdateHierarchy : 1; // Don't update the aniamtion hierarchy this frame
 
    unsigned int bHasRoadsignText : 1;     // entity is roadsign and has some 2deffect text stuff to be rendered
    unsigned int bDisplayedSuperLowLOD : 1;
    unsigned int bIsProcObject : 1;            // set object has been generate by procedural object generator
    unsigned int bBackfaceCulled : 1;          // has backface culling on
    unsigned int bLightObject : 1;         // light object with directional lights
    unsigned int bUnimportantStream : 1;       // set that this object is unimportant, if streaming is having problems
    unsigned int bTunnel : 1;          // Is this model part of a tunnel
    unsigned int bTunnelTransition : 1;        // This model should be rendered from within and outside of the tunnel

    B32MACRO(u32 CEntity_gap;) // Need a gap here. For some reason.
    unsigned short m_nRandomSeed;
    unsigned short m_nModelIndex;
    B64MACRO(u32 CEntity_gap1;) // Need a gap here. For some reason.
    CReference *m_pReferences;
    void *m_pStreamingLink;
    short m_nScanCode;
    char m_nIplIndex;
    union
    {
        unsigned char m_nInterior;
        unsigned char m_nAreaCode;
    };
    B64MACRO(u32 CEntity_gap2;) // Need a gap here. For some reason.
    union
    {
        int m_nLodIndex; // -1 - without LOD model
        CEntity *m_pLod;
    };
    unsigned char m_nNumLodChildren;
    unsigned char m_nNumLodChildrenRendered;
    union
    {
        i8 m_nTypeStatus;
        struct {
            unsigned char m_nType : 3;
            unsigned char m_nStatus : 5;
        };
    };
DECL_CLASS_END()
CHECKSIZE(CEntity, 0x3C, 0x60);

DECL_CLASS_BASED(CDummy, CEntity)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CDummy, _ZN6CDummyC2Ev);
    DECL_DTORCALL(CDummy, _ZN6CDummyD2Ev);
    DECL_NEWCALL(CDummy, BYBIT(_ZN6CDummynwEj, _ZN6CDummynwEm) );
    DECL_DLCALL(CDummy, _ZN6CDummydlEPv);
DECL_CLASS_END()

DECL_CLASS_BASED(CDummyObject, CDummy)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CDummyObject, _ZN12CDummyObjectC2Ev);
    DECL_DTORCALL(CDummyObject, _ZN12CDummyObjectD2Ev);
    DECL_NEWCALL(CDummyObject, BYBIT(_ZN12CDummyObjectnwEj, _ZN12CDummyObjectnwEm) );
    DECL_DLCALL(CDummyObject, _ZN12CDummyObjectdlEPv);
    
    // Member functions

    DECL_THISCALL_SIMPLE(CreateObject, _ZN12CDummyObject12CreateObjectEv, CObject*);
    
    DECL_THISCALL_HEAD(UpdateFromObject, _ZN12CDummyObject16UpdateFromObjectEP7CObject, void, CObject* pObject)
    DECL_THISCALL_TAIL(UpdateFromObject, pObject)
DECL_CLASS_END()

DECL_CLASS_BASED(CBuilding, CEntity)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CBuilding, _ZN9CBuildingC2Ev);
    DECL_NEWCALL(CBuilding, BYBIT(_ZN9CBuildingnwEj, _ZN9CBuildingnwEm) );
    DECL_DLCALL(CBuilding, _ZN9CBuildingdlEPv);
    
    // Member functions
    DECL_THISCALL_HEAD(ReplaceWithNewModel, _ZN9CBuilding19ReplaceWithNewModelEi, void, int index)
    DECL_THISCALL_TAIL(ReplaceWithNewModel, index)
DECL_CLASS_END()

DECL_CLASS_BASED(CAnimatedBuilding, CBuilding)
    // has overloaded virtual functions
DECL_CLASS_END()

DECL_FASTCALL_SIMPLE_GLO(IsBuildingPointerValid, _Z22IsBuildingPointerValidP9CBuilding, bool, CBuilding* pBuilding);


#endif // __AML_PSDK_SAENTITY_H
