#ifndef MINILOG_LOGGER_H
#define MINILOG_LOGGER_H

#include "Sink.h"
#include "Detail.h"

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
        requires Detail::StringLike<T>
        void log(const T &message) {
            auto &sink = Sink::get_instance();
            sink.log(message);
        }
    };
}

#endif //MINILOG_LOGGER_H
