#ifndef __AML_PSDK_SABASEEXTENDER_H
#define __AML_PSDK_SABASEEXTENDER_H

#include "plugin.h"

// https://github.com/DK22Pac/plugin-sdk/blob/master/shared/Extender.h

template <typename T>
struct ExtenderInterface
{
    virtual void AllocateBlocks() = 0;
    virtual void OnConstructor(T *object) = 0;
    virtual void OnDestructor(T *object) = 0;
};

template <typename T>
struct ExtendersHandler
{
    struct static_data
    {
        std::vector <ExtenderInterface<T> *> extenders;
        bool injected;
    };

    static inline static_data& get_data()
    {
        // Has to be constructed at some point, so it is allocated at first call
        // of this function.
        static static_data data;
        return data;
    }

    static void Allocate()
    {
        static_data& data = get_data();
        for (auto &i : data.extenders)
        {
            i->AllocateBlocks();
        }
    }

    static void Constructor(T *object)
    {
        static_data& data = get_data();
        for (auto &i : data.extenders)
        {
            i->OnConstructor(object);
        }
    }

    static void Destructor(T *object)
    {
        static_data& data = get_data();
        for (auto &i : data.extenders)
        {
            i->OnDestructor(object);
        }
    }
};

#endif // __AML_PSDK_SABASEEXTENDER_H