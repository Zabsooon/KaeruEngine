#pragma once

#include <mutex>
#include <condition_variable>
#include <queue>

namespace Kaeru::Logging {

    template<typename T>
    class LogQueue 
    {
    public:
        LogQueue();
        ~LogQueue();

        void push(T value);
        T pop();
        bool empty();
        void shutdown();

    private:
        std::queue<T> m_Queue;
        std::mutex m_Mtx;
        std::condition_variable m_Cv;
        bool m_Done;
    };
}
