#ifndef __AML_PSDK_SAPOOLS_H
#define __AML_PSDK_SAPOOLS_H

#include <aml-psdk/game_sa/entity/Ped.h>
#include <aml-psdk/game_sa/entity/Automobile.h>
#include <aml-psdk/game_sa/entity/Object.h>
#include <aml-psdk/game_sa/ai/tasks/Task.h>
#include <aml-psdk/game_sa/ai/PedIntelligence.h>

#ifdef GetObject
    #undef GetObject
#endif


union tPoolObjectFlags
{
    struct
    {
        u8 nId : 7;
        bool bEmpty : 1;
    };
    u8 nValue;
    inline u8 IntValue() { return nValue; }
};

template<class A, class B = A>
struct CPool
{
    B                *m_pObjects;
    tPoolObjectFlags *m_byteMap;
    int               m_nSize;
    int               m_nFirstFree;
    bool              m_bOwnsAllocations;
    bool              m_bDealWithNoMemory;

    CPool()
    {
        m_pObjects = NULL;
        m_byteMap = NULL;
        m_nSize = 0;
        m_bOwnsAllocations = false;
    }

    CPool(int nSize, const char* pPoolName = NULL)
    {
        m_pObjects = (B*)(operator new(sizeof(B) * nSize));
        m_byteMap = (tPoolObjectFlags*)(operator new(sizeof(tPoolObjectFlags) *  nSize));
        m_nSize = nSize;
        m_nFirstFree = -1;
        m_bOwnsAllocations = true;
        for (int i = 0; i < nSize; ++i)
        {
            m_byteMap[i].bEmpty = true;
            m_byteMap[i].nId = 0;
        }
    }

    ~CPool()
    {
        Flush();
    }

    inline void Init(int nSize, void* pObjects, void* pInfos)
    {
        m_pObjects = static_cast<B*>(pObjects);
        m_byteMap = static_cast<tPoolObjectFlags*>(pInfos);
        m_nSize = nSize;
        m_nFirstFree = -1;
        m_bOwnsAllocations = false;
        for (int i = 0; i < nSize; ++i)
        {
            m_byteMap[i].bEmpty = true;
            m_byteMap[i].nId = 0;
        }
    }

    inline void Flush()
    {
        if (m_bOwnsAllocations)
        {
            operator delete(m_pObjects);
            operator delete(m_byteMap);
        }
        m_pObjects = NULL;
        m_byteMap = NULL;
        m_nSize = 0;
        m_nFirstFree = 0;
    }

    inline void Clear()
    {
        for (int i = 0; i < m_nSize; i++)
        {
            m_byteMap[i].bEmpty = true;
        }
    }

    inline bool IsFreeSlotAtIndex(int idx)
    {
        return m_byteMap[idx].bEmpty;
    }

    inline int GetIndex(A* pObject)
    {
        return reinterpret_cast<B*>(pObject) - m_pObjects;
    }

    inline A* GetAt(int nIndex)
    {
        return !IsFreeSlotAtIndex(nIndex) ? (A *)&m_pObjects[nIndex] : NULL;
    }

    inline void SetFreeAt(int idx, bool bFree)
    {
        m_byteMap[idx].bEmpty = bFree;
    }

    inline void SetIdAt(int idx, unsigned char id)
    {
        m_byteMap[idx].nId = id;
    }

    inline unsigned char GetIdAt(int idx)
    {
        return m_byteMap[idx].nId;
    }

    inline A* New()
    {
        bool bReachedTop = false;
        do
        {
            if (++m_nFirstFree >= m_nSize)
            {
                if (bReachedTop)
                {
                    m_nFirstFree = -1;
                    return NULL;
                }
                bReachedTop = true;
                m_nFirstFree = 0;
            }
        }
        while (!m_byteMap[m_nFirstFree].bEmpty);

        m_byteMap[m_nFirstFree].bEmpty = false;
        ++m_byteMap[m_nFirstFree].nId;
        return &m_pObjects[m_nFirstFree];
    }

    inline void CreateAtRef(int nRef)
    {
        nRef >>= 8;
        m_byteMap[nRef].bEmpty = false;
        ++m_byteMap[nRef].nId;
        m_nFirstFree = 0;
        while (!m_byteMap[m_nFirstFree].bEmpty)
        {
            ++m_nFirstFree;
        }
    }

    inline A *New(int nRef)
    {
        A *result = &m_pObjects[nRef >> 8];
        CreateAtRef(nRef);
        return result;
    }

    inline void Delete(A* pObject)
    {
        int nIndex = reinterpret_cast<B*>(pObject) - m_pObjects;
        m_byteMap[nIndex].bEmpty = true;
        if (nIndex < m_nFirstFree)
        {
            m_nFirstFree = nIndex;
        }
    }

    inline int GetRef(A* pObject)
    {
        return (GetIndex(pObject) << 8) + m_byteMap[GetIndex(pObject)].IntValue();
    }

    inline A* GetAtRef(int ref)
    {
        int nSlotIndex = ref >> 8;
        return nSlotIndex >= 0 && nSlotIndex < m_nSize && m_byteMap[nSlotIndex].IntValue() == (ref & 0xFF) ? reinterpret_cast<A*>(&m_pObjects[nSlotIndex]) : NULL;
    }

    inline unsigned int GetNoOfUsedSpaces()
    {
        unsigned int counter = 0;
        for (int i = 0; i < m_nSize; ++i)
        {
            if (!IsFreeSlotAtIndex(i)) ++counter;
        }
        return counter;
    }

    inline unsigned int GetNoOfFreeSpaces()
    {
        return m_nSize - GetNoOfUsedSpaces();
    }

    inline unsigned int GetObjectSize()
    {
        return sizeof(B);
    }

    inline bool IsObjectValid(A *obj)
    {
        int slot = GetIndex(obj);
        return slot >= 0 && slot < m_nSize && !IsFreeSlotAtIndex(slot);
    }

    inline int GetSize()
    {
        return m_nSize;
    }
};
CHECKSIZE(CPool<int>, 0x14, 0x20);



typedef CPool<CPed, CCopPed> CPedPool;
typedef CPool<CVehicle, SELBYBIT(CHeli, CPlane)> CVehiclePool;
typedef CPool<CBuilding> CBuildingPool;
typedef CPool<CObject, CCutsceneObject> CObjectPool;
typedef CPool<CDummy> CDummyPool;
typedef CPool<CColModel> CColModelPool;
typedef CPool<CTask, char[BYBIT(128, 168)]> CTaskPool;
typedef CPool<CPedIntelligence> CPedIntelligencePool;
typedef CPool<CPtrNodeSingleLink> CPtrNodeSingleLinkPool;
typedef CPool<CPtrNodeDoubleLink> CPtrNodeDoubleLinkPool;

DECL_CLASS(CPools) // union
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN6CPools10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(ShutDown, _ZN6CPools8ShutDownEv, void);
    DECL_FASTCALL_SIMPLE(GetPedRef, _ZN6CPools9GetPedRefEP4CPed, i32, CPed* ped);
    DECL_FASTCALL_SIMPLE(GetPed, _ZN6CPools6GetPedEi, CPed*, i32 ref);
    DECL_FASTCALL_SIMPLE(GetVehicleRef, _ZN6CPools13GetVehicleRefEP8CVehicle, i32, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(GetVehicle, _ZN6CPools10GetVehicleEi, CVehicle*, i32 ref);
    DECL_FASTCALL_SIMPLE(GetObjectRef, _ZN6CPools12GetObjectRefEP7CObject, i32, CObject* object);
    DECL_FASTCALL_SIMPLE(GetObject, _ZN6CPools9GetObjectEi, CObject*, i32 ref);
    DECL_FASTCALL_SIMPLE(MakeSureSlotInObjectPoolIsEmpty, _ZN6CPools31MakeSureSlotInObjectPoolIsEmptyEi, void, i32 slot);
    DECL_FASTCALL_SIMPLE(SaveVehiclePool, _ZN6CPools15SaveVehiclePoolEv, bool);
    DECL_FASTCALL_SIMPLE(LoadVehiclePool, _ZN6CPools15LoadVehiclePoolEv, bool);
    DECL_FASTCALL_SIMPLE(SaveObjectPool, _ZN6CPools14SaveObjectPoolEv, bool);
    DECL_FASTCALL_SIMPLE(LoadObjectPool, _ZN6CPools14LoadObjectPoolEv, bool);
    DECL_FASTCALL_SIMPLE(Save, _ZN6CPools4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(SavePedPool, _ZN6CPools11SavePedPoolEv, bool);
    DECL_FASTCALL_SIMPLE(SavePedTasks, _ZN6CPools12SavePedTasksEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN6CPools4LoadEv, bool);
    DECL_FASTCALL_SIMPLE(LoadPedPool, _ZN6CPools11LoadPedPoolEv, bool);
    DECL_FASTCALL_SIMPLE(LoadPedTasks, _ZN6CPools12LoadPedTasksEv, bool);

    // STATIC members
    DECL_OBJECT_PLT(CPedPool*, ms_pPedPool, BYBIT(0x676C90, 0x84B968));
    DECL_OBJECT_PLT(CVehiclePool*, ms_pVehiclePool, BYBIT(0x67853C, 0x84EA90));
    DECL_OBJECT_PLT(CBuildingPool*, ms_pBuildingPool, BYBIT(0x678EC8, 0x84FDB8));
    DECL_OBJECT_PLT(CObjectPool*, ms_pObjectPool, BYBIT(0x676BBC, 0x84B7C0));
    DECL_OBJECT_PLT(CDummyPool*, ms_pDummyPool, BYBIT(0x676B28, 0x84B698));
    DECL_OBJECT_PLT(CColModelPool*, ms_pColModelPool, BYBIT(0x678AB8, 0x84F598));
    DECL_OBJECT_PLT(CTaskPool*, ms_pTaskPool, BYBIT(0x676168, 0x84A330));
    DECL_OBJECT_PLT(CPedIntelligencePool*, ms_pPedIntelligencePool, BYBIT(0x6799F0, 0x8513F8));
    DECL_OBJECT_PLT(CPtrNodeSingleLinkPool*, ms_pPtrNodeSingleLinkPool, BYBIT(0x677F14, 0x84DE48));
    DECL_OBJECT_PLT(CPtrNodeDoubleLinkPool*, ms_pPtrNodeDoubleLinkPool, BYBIT(0x67836C, 0x84E6F0));
DECL_CLASS_END()

#define ms_pPedPool ms_pPedPool()
#define ms_pVehiclePool ms_pVehiclePool()
#define ms_pBuildingPool ms_pBuildingPool()
#define ms_pObjectPool ms_pObjectPool()
#define ms_pDummyPool ms_pDummyPool()
#define ms_pColModelPool ms_pColModelPool()
#define ms_pTaskPool ms_pTaskPool()
#define ms_pPedIntelligencePool ms_pPedIntelligencePool()
#define ms_pPtrNodeSingleLinkPool ms_pPtrNodeSingleLinkPool()
#define ms_pPtrNodeDoubleLinkPool ms_pPtrNodeDoubleLinkPool()

#endif // __AML_PSDK_SAPOOLS_H