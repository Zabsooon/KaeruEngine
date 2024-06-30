#pragma once

#include "LogQueue.h"
#include "LogMessage.h"
#include "LogWorker.h"

namespace Kaeru::Logging {

    class Logger {
    public:
        static Logger* getInstance();

    private:
        Logger();
        ~Logger();

        Logger(const Logger& other) = delete;

    private:
        LogQueue<LogMessage> m_LogQueue;
        LogWorker m_LogWorker;
        static Logger* m_ObjPtr;
    };
}
