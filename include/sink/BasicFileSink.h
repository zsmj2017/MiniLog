#ifndef MINILOG_BASICFILESINK_H
#define MINILOG_BASICFILESINK_H

#include "SinkBase.h"
#include "details/LogMsg.h"
#include "logger/Logger.h"
#include "logger/LoggerRegister.h"

namespace MiniLog {
    class BasicFileSink final : public SinkBase {
    public:
        explicit BasicFileSink(std::string filename) : filename_(std::move(filename)) {
            // write or create a file
            file_ = fopen(filename_.c_str(), "w");
            if (file_ == nullptr) {
                throw std::runtime_error("Failed to open file " + filename_);
            }
        }

        ~BasicFileSink() override {
            if (file_ != nullptr) {
                fclose(file_);
            }
        }

        void log(const details::LogMsg &message) override {
            fprintf(file_, "%s\n", message.get_str().c_str());
            fflush(file_);// TODO:: now we only support flush every line to file
        }

        void flush() override {
            fflush(file_);
        }

    private:
        std::string filename_;
        FILE *file_;
    };

    std::shared_ptr<Logger> create_file_logger(std::string logger_name, std::string filename) {
        auto sink = std::make_shared<BasicFileSink>(std::move(filename));
        auto fileLogger = std::make_shared<Logger>(logger_name, std::move(sink));
        LoggerRegister::get_instance().register_logger(fileLogger);
        return fileLogger;
    }
}// namespace MiniLog

#endif//MINILOG_BASICFILESINK_H
