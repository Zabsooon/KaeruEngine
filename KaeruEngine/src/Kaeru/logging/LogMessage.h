#pragma once

#include "LogDestination.h"

#include <ctime>
#include <thread>
#include <string>

namespace Kaeru::Logging {

    enum class LogLevel {
        FATAL = 0,
        ERROR,
        WARN,
        INFO,
        DEBUG,
        TRACE
    };

    class LogMessage {
    public:
        LogMessage();
        ~LogMessage();

        ILogDestination* getLogDestination() const;
        LogLevel getLogLevel() const;
        std::time_t getTimeStamp() const;
        std::thread::id getThreadId() const;
        std::string getMessage() const;

        std::string getLogLevelString() const;

        void setLogDestination(std::unique_ptr<ILogDestination>& logDestination);
        void setLogLevel(const LogLevel& logLevel);
        void setTimeStamp(const std::time_t& timeStamp);
        void setThreadId(const std::thread::id& threadId);
        void setMessage(const std::string& message);


    private:
        std::unique_ptr<ILogDestination> m_LogDestination;
        LogLevel m_LogLevel;
        std::time_t m_TimeStamp;
        std::thread::id m_ThreadId;
        std::string m_Message;
    };
}
