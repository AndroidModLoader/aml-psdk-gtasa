#ifndef __AML_PSDK_SATHREADSYNCER_H
#define __AML_PSDK_SATHREADSYNCER_H

#include <aml-psdk/game_sa/Events.h>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>

struct ThreadSyncer
{
    ThreadSyncer()
    {
        Events::gameProcessEvent.after += ProcessMainThreadTasks;
    }

    static inline void ExecInThread(std::function<void()> fn)
    {
        std::thread t(fn);
        t.detach();
    }

    static inline void PushToMain(std::function<void()> fn)
    {
        std::lock_guard<std::mutex> lock(m_queueMainMutex);
        m_queueMainTasks.push(std::move(fn));
    }

    static inline void ProcessMainThreadTasks()
    {
        std::queue<std::function<void()>> local_tasks;
        std::lock_guard<std::mutex> lock(m_queueMainMutex);
        std::swap(m_queueMainTasks, local_tasks);

        while(!local_tasks.empty())
        {
            auto task = std::move(local_tasks.front());
            local_tasks.pop();
            task();
        }
    }

    static inline std::mutex m_queueMainMutex;
    static inline std::queue<std::function<void()>> m_queueMainTasks;
};
inline ThreadSyncer g_ThreadSyncerStub;

#endif // __AML_PSDK_SATHREADSYNCER_H