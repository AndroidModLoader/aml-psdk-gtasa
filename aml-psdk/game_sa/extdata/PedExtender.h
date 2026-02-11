#ifndef __AML_PSDK_SAPEDEXTENDER_H
#define __AML_PSDK_SAPEDEXTENDER_H

#include "../BaseExtender.h"
#include "../Events.h"

struct PedExtendersHandler : public ExtendersHandler<CPed>
{
    static void Add(ExtenderInterface<CPed> *extender)
    {
        static_data& data = get_data();
        data.extenders.push_back(extender);
        if (!data.injected)
        {
            Events::initGameStage1Event.after += Allocate;
            Events::pedCtorEvent.before += Constructor;
            Events::pedDtorEvent.after += Destructor;
            data.injected = true;
        }
    }
};

template <typename T>
struct PedExtendedData : public ExtenderInterface<CPed>
{
    T **blocks;
    unsigned int numBlocks;

    void AllocateBlocks()
    {
        numBlocks = CPools::ms_pPedPool->m_nSize;
        blocks = new T*[numBlocks];
        for (unsigned int i = 0; i < numBlocks; i++)
        {
            blocks[i] = NULL;
        }
    }
    void OnConstructor(CPed *ped)
    {
        blocks[CPools::ms_pPedPool->GetIndex(ped)] = new T(ped);
    }
    void OnDestructor(CPed *ped)
    {
        delete blocks[CPools::ms_pPedPool->GetIndex(ped)];
        blocks[CPools::ms_pPedPool->GetIndex(ped)] = NULL;
    }
    
    PedExtendedData()
    {
        blocks = NULL;
        PedExtendersHandler::Add(this);
    }
    ~PedExtendedData()
    {
        for (unsigned int i = 0; i < numBlocks; i++)
        {
            delete blocks[i];
        }
        delete[] blocks;
    }
    T &Get(CPed *ped)
    {
        return *blocks[CPools::ms_pPedPool->GetIndex(ped)];
    }
};

#endif // __AML_PSDK_SAPEDEXTENDER_H
