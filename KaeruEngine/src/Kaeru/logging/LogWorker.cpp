#include "LogWorker.h"

namespace Kaeru::Logging {

    LogWorker::LogWorker(size_t threadCount, LogQueue<LogMessage>& logQueue)
        : m_Stop(false), m_LogQueue(logQueue) 
        {
            m_Workers.reserve(threadCount);
            for(int i = 0; i < threadCount; ++i) {
                m_Workers.emplace_back(&LogWorker::workerFunction, this);
            }
        }

    LogWorker::~LogWorker() 
    {
        stopWorkers();
        for(auto& worker : m_Workers) {
            if(worker.joinable()) {
                worker.join();
            }
        }
    }

    void LogWorker::stopWorkers() 
    {
        m_Stop = true;
        m_LogQueue.shutdown();
    }

    void LogWorker::workerFunction() 
    {
        if(!m_Stop) {
            LogMessage message = this->m_LogQueue.pop();
            message.setThreadId(std::this_thread::get_id());
            message.getLogDestination()->writeLog(message);
        }
    }
}
