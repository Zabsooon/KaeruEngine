#include "LogMessage.h"
#include "Kaeru/logging/LogDestination.h"
#include <utility>

namespace Kaeru::Logging {

    LogMessage::LogMessage(std::unique_ptr<ILogDestination>& logDestination,
                LogLevel& logLevel,
                std::string& message)
        : m_LogDestination(std::move(logDestination)), m_LogLevel(logLevel), m_Message(message)
    {
        m_TimeStamp = std::time(nullptr);
        m_ThreadId = std::this_thread::get_id(); // probably shouldn't be set here since worker has other theads that work on it
    }

    LogMessage::LogMessage(std::unique_ptr<ILogDestination>& logDestination,
                            LogLevel& logLevel,
                            std::string& message,
                            std::time_t& timeStamp,
                            std::thread::id& threadId) 
        : m_LogDestination(std::move(logDestination)), m_LogLevel(logLevel), m_Message(message), m_TimeStamp(timeStamp), m_ThreadId(threadId)
    {

    } 

    LogMessage::LogMessage(LogMessage&& logMessage) noexcept
        : m_LogDestination(std::move(logMessage.m_LogDestination)), 
        m_LogLevel(std::move(logMessage.m_LogLevel)),
        m_Message(std::move(logMessage.m_Message)),
        m_ThreadId(std::move(logMessage.m_ThreadId)),
        m_TimeStamp(std::move(logMessage.m_TimeStamp))
    {

    }

    LogMessage& LogMessage::operator=(LogMessage&& other) noexcept
    {
        this->setLogDestination(std::move(other.m_LogDestination));
        this->setLogLevel(std::move(other.m_LogLevel));
        this->setMessage(std::move(other.m_Message));
        this->setThreadId(std::move(other.m_ThreadId));
        this->setTimeStamp(std::move(other.m_TimeStamp));
    }

    ILogDestination* LogMessage::getLogDestination() const 
    {
        return this->m_LogDestination.get();
    }

    LogLevel LogMessage::getLogLevel() const 
    {
        return this->m_LogLevel;
    }

    std::time_t LogMessage::getTimeStamp() const 
    {
        return this->m_TimeStamp;
    }

    char* LogMessage::getTimeStampReadable() const
    {
        return ctime(&m_TimeStamp);
    }

    std::thread::id LogMessage::getThreadId() const 
    {
        return this->m_ThreadId;
    }

    std::string LogMessage::getMessage() const 
    {
        return this->m_Message;
    }

    std::string LogMessage::getLogLevelString() const 
    {
        switch(this->m_LogLevel) 
        {
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

    void LogMessage::setLogDestination(std::unique_ptr<ILogDestination>& logDestination) 
    {
        this->m_LogDestination = std::move(logDestination);
    }

    void LogMessage::setLogLevel(const LogLevel& logLevel) 
    {
        this->m_LogLevel = logLevel;
    }

    void LogMessage::setTimeStamp(const std::time_t& timeStamp) 
    {
        this->m_TimeStamp = timeStamp;
    }

    void LogMessage::setThreadId(const std::thread::id& threadId) 
    {
        this->m_ThreadId = threadId;
    }

    void LogMessage::setMessage(const std::string& message) 
    {
        this->m_Message = message;
    }
}
