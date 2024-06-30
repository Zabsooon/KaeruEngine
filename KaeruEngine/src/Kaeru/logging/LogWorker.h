#pragma once

#include "LogQueue.h"
#include "LogMessage.h"
#include <atomic>
#include <thread>
#include <vector>

namespace Kaeru::Logging {

    class LogWorker {
    public:
        LogWorker(size_t threadCount, LogQueue<LogMessage>& logQueue);
        ~LogWorker();

        void startWorkers();
        void stopWorkers();

    private:

        void workerFunction();

    private:
        LogQueue<LogMessage>& m_LogQueue;
        std::vector<std::thread> m_Workers;
        std::atomic<bool> m_Stop;
    };
}
