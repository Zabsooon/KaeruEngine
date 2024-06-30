#include "Logger.h"

namespace Kaeru::Logging {

    Logger* Logger::getInstance() {
        if(Logger::m_ObjPtr == nullptr)
            return new Logger();
        else
            return m_ObjPtr;
    }

    Logger::Logger() {

    }

    Logger::~Logger() {

    }
}
