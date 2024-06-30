#include "LogMessage.h"
#include "Kaeru/logging/LogDestination.h"
#include <utility>

namespace Kaeru::Logging {

    ILogDestination* LogMessage::getLogDestination() const {
        return this->m_LogDestination.get();
    }

    LogLevel LogMessage::getLogLevel() const {
        return this->m_LogLevel;
    }

    std::time_t LogMessage::getTimeStamp() const {
        return this->m_TimeStamp;
    }

    std::thread::id LogMessage::getThreadId() const {
        return this->m_ThreadId;
    }

    std::string LogMessage::getMessage() const {
        return this->m_Message;
    }

    std::string LogMessage::getLogLevelString() const {
        switch(this->m_LogLevel) {
            case LogLevel::FATAL:
                return "FATAL";
                break;
            case LogLevel::ERROR:
                return "ERROR";
                break;
            case LogLevel::WARN:
                return "WARN";
                break;
            case LogLevel::INFO:
                return "INFO";
                break;
            case LogLevel::DEBUG:
                return "DEBUG";
                break;
            case LogLevel::TRACE:
                return "TRACE";
                break;
            default:
                return "UNKNOWN";
                break;
        }
    }

    void LogMessage::setLogDestination(std::unique_ptr<ILogDestination>& logDestination) {
        this->m_LogDestination = std::move(logDestination);
    }

    void LogMessage::setLogLevel(const LogLevel& logLevel) {
        this->m_LogLevel = logLevel;
    }

    void LogMessage::setTimeStamp(const std::time_t& timeStamp) {
        this->m_TimeStamp = timeStamp;
    }

    void LogMessage::setThreadId(const std::thread::id& threadId) {
        this->m_ThreadId = threadId;
    }

    void LogMessage::setMessage(const std::string& message) {
        this->m_Message = message;
    }
}
