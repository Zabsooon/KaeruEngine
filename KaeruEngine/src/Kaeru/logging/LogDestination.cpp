#include "LogDestination.h"
#include "Kaeru/logging/LogMessage.h"
#include <cstdio>
#include <exception>
#include <fstream>
#include <iostream>

namespace Kaeru::Logging {

    void ConsoleLogDestination::writeLog(const LogMessage& message) 
    {
        try 
        {
            std::cout << message.getTimeStampReadable()
                << "_[" << message.getLogLevelString() << ":THREAD("
                << message.getThreadId() << ")]:"
                << message.getMessage();

        } catch (std::exception& e) 
        {
            printf("%s", e.what());
        }
    }

    void FileLogDestination::writeLog(const LogMessage& message) 
    {
        std::ofstream file(m_FilePath, std::ios_base::app);

        try 
        {
            if(file.is_open()) 
            {
                file << message.getTimeStampReadable()
                    << "_[" << message.getLogLevelString() << ":THREAD("
                    << message.getThreadId() << ")]:"
                    << message.getMessage();
            }
        } catch (std::exception& e) 
        {
            printf("%s", e.what());
        }
    }
}
