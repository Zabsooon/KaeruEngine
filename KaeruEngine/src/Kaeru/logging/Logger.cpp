#include "Logger.h"
#include <utility> 

namespace Kaeru::Logging {

    Logger* Logger::getInstance() 
    {
        if(Logger::m_ObjPtr == nullptr)
            return new Logger();
        else
            return m_ObjPtr;
    }

    Logger::Logger()
        : m_LogWorker(10, m_LogQueue) 
    {

    }

    Logger::~Logger() 
    {

    }

    template<typename... Types>
    void Logger::log(LogLevel& logLevel, Types&... args) 
    {
        LogMessage logMessage(std::unique_ptr<ILogDestination>(new ILogDestination()), logLevel, args);
        this->m_LogQueue.push(logMessage);
    }

    void Logger::log(LogMessage&& logMessage) 
    {
        this->m_LogQueue.push(std::move(logMessage));
    }
}
