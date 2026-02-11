#ifndef __AML_PSDK_SAOBJECTEXTENDER_H
#define __AML_PSDK_SAOBJECTEXTENDER_H

#include "../BaseExtender.h"
#include "../Events.h"

struct ObjectExtendersHandler : public ExtendersHandler<CObject>
{
    static void Add(ExtenderInterface<CObject> *extender)
    {
        static_data& data = get_data();
        data.extenders.push_back(extender);
        if (!data.injected)
        {
            Events::initGameStage1Event.after += Allocate;
            Events::objectCtorEvent.before += Constructor;
            Events::objectDtorEvent.after += Destructor;
            data.injected = true;
        }
    }
};

template <typename T>
struct ObjectExtendedData : public ExtenderInterface<CObject>
{
    T **blocks;
    unsigned int numBlocks;

    void AllocateBlocks()
    {
        numBlocks = CPools::ms_pObjectPool->m_nSize;
        blocks = new T*[numBlocks];
        for (unsigned int i = 0; i < numBlocks; i++)
        {
            blocks[i] = NULL;
        }
    }
    void OnConstructor(CObject *object)
    {
        blocks[CPools::ms_pObjectPool->GetIndex(object)] = new T(object);
    }
    void OnDestructor(CObject *object)
    {
        delete blocks[CPools::ms_pObjectPool->GetIndex(object)];
        blocks[CPools::ms_pObjectPool->GetIndex(object)] = NULL;
    }
    
    ObjectExtendedData()
    {
        blocks = NULL;
        ObjectExtendersHandler::Add(this);
    }
    ~ObjectExtendedData()
    {
        for (unsigned int i = 0; i < numBlocks; i++)
        {
            delete blocks[i];
        }
        delete[] blocks;
    }
    T &Get(CObject *object)
    {
        return *blocks[CPools::ms_pObjectPool->GetIndex(object)];
    }
};

#endif // __AML_PSDK_SAOBJECTEXTENDER_H
