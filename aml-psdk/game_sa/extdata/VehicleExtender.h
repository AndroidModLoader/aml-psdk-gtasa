#ifndef __AML_PSDK_SAVEHICLEEXTENDER_H
#define __AML_PSDK_SAVEHICLEEXTENDER_H

#include "../BaseExtender.h"
#include "../Events.h"

struct VehicleExtendersHandler : public ExtendersHandler<CVehicle>
{
    static void Add(ExtenderInterface<CVehicle> *extender)
    {
        static_data& data = get_data();
        data.extenders.push_back(extender);
        if (!data.injected)
        {
            Events::initGameStage1Event.after += Allocate;
            Events::vehicleCtorEvent.before += Constructor;
            Events::vehicleDtorEvent.after += Destructor;
            data.injected = true;
        }
    }
};

template <typename T>
struct VehicleExtendedData : public ExtenderInterface<CVehicle>
{
    T **blocks;
    unsigned int numBlocks;

    void AllocateBlocks()
    {
        numBlocks = CPools::ms_pVehiclePool->m_nSize;
        blocks = new T*[numBlocks];
        for (unsigned int i = 0; i < numBlocks; i++)
        {
            blocks[i] = NULL;
        }
    }
    void OnConstructor(CVehicle *vehicle)
    {
        blocks[CPools::ms_pVehiclePool->GetIndex(vehicle)] = new T(vehicle);
    }
    void OnDestructor(CVehicle *vehicle)
    {
        delete blocks[CPools::ms_pVehiclePool->GetIndex(vehicle)];
        blocks[CPools::ms_pVehiclePool->GetIndex(vehicle)] = NULL;
    }
    
    VehicleExtendedData()
    {
        blocks = NULL;
        VehicleExtendersHandler::Add(this);
    }
    ~VehicleExtendedData()
    {
        for (unsigned int i = 0; i < numBlocks; i++)
        {
            delete blocks[i];
        }
        delete[] blocks;
    }
    T &Get(CVehicle *vehicle)
    {
        return *blocks[CPools::ms_pVehiclePool->GetIndex(vehicle)];
    }
};

#endif // __AML_PSDK_SAVEHICLEEXTENDER_H
