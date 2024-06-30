#pragma once

#include <string>

namespace Kaeru::Logging {

    class LogMessage;

    class ILogDestination {
    public:
        virtual void writeLog(const LogMessage&) = 0;
    };

    class ConsoleLogDestination : public ILogDestination {
    public:
        void writeLog(const LogMessage&) override;
    };

    class FileLogDestination : public ILogDestination {
    public:
        void writeLog(const LogMessage&) override;

        void setFilePath(const std::string& filePath);
        std::string& getFilePath() const;
    private:
        std::string m_FilePath;
    };
}
