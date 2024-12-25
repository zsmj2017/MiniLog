#ifndef MINILOG_LOGGER_H
#define MINILOG_LOGGER_H

#include "Sink.h"
#include "details/LogMsg.h"
#include "details/SourceLoc.h"

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
            log_aux(Detail::SourceLoc{}, message);
        }

        template<class T>
        void log(const Detail::SourceLoc &source_loc, const T &message) {
            log_aux(source_loc, message);
        }

    private:
        // TODO:: now we assume that message is a string-like object
        void log_aux(const Detail::SourceLoc &source_loc, std::string_view message) {
            auto log_msg = details::LogMsg(source_loc, message);
            Sink::get_instance().log(log_msg);
        }
    };
}// namespace MiniLog

#endif//MINILOG_LOGGER_H
