#ifndef MINILOG_LOGGER_H
#define MINILOG_LOGGER_H

#include "Sink.h"
#include "details/LogMsg.h"

namespace MiniLog {
    // TODO:: now we only have one logger and make it as a singleton
    class Logger {
    public:
        Logger() = default;

        ~Logger() = default;

        Logger &operator=(const Logger &) = delete;

        Logger(const Logger &) = delete;

        Logger &operator=(Logger &&) = delete;

        Logger(Logger &&) = delete;

    public:
        static Logger &get_instance() {
            static Logger logger;
            return logger;
        }

    public:
        template<class T>
        void log(const T &message) {
            log_aux(message);
        }

    private:
        // TODO:: now we assume that message is a string-like object
        void log_aux(std::string_view message) {
            auto log_msg = details::LogMsg(message);
            Sink::get_instance().log(log_msg);
        }
    };
}

#endif //MINILOG_LOGGER_H
