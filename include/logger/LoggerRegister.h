#ifndef MINILOG_LOGGERREGISTER_H
#define MINILOG_LOGGERREGISTER_H

#include "Logger.h"
#include "sink/StdCoutSink.h"
#include <unordered_map>

namespace MiniLog {
    // Singleton class to register all the loggers
    class LoggerRegister {
    public:
        LoggerRegister(const LoggerRegister &) = delete;

        LoggerRegister &operator=(const LoggerRegister &) = delete;

        LoggerRegister(LoggerRegister &&) = delete;

        LoggerRegister &operator=(LoggerRegister &&) = delete;

    private:
        LoggerRegister() {
            constexpr auto kDefaultLoggerName = "default_logger";
            default_logger_ = std::make_shared<Logger>(kDefaultLoggerName, std::make_shared<StdCoutSink>());
            loggers_[kDefaultLoggerName] = default_logger_;
        }
        ~LoggerRegister() = default;

    public:
        static LoggerRegister &get_instance() {
            static LoggerRegister loggerRegister;
            return loggerRegister;
        }

    public:
        void register_logger(std::shared_ptr<Logger> logger) {
            if (loggers_.find(logger->name()) == loggers_.end()) {
                loggers_[logger->name()] = std::move(logger);
            } else {
                throw std::runtime_error("Logger with name " + logger->name() + " already exists");
            }
        }
        std::shared_ptr<Logger> get_logger(const std::string &name) {
            auto it = loggers_.find(name);
            if (it != loggers_.end()) {
                return it->second;
            } else {
                return nullptr;
            }
        }

    public:
        std::shared_ptr<Logger> get_default_logger() {
            return default_logger_;
        }

    private:
        std::unordered_map<std::string, std::shared_ptr<Logger>> loggers_;
        std::shared_ptr<Logger> default_logger_;
    };
}// namespace MiniLog

#endif//MINILOG_LOGGERREGISTER_H
