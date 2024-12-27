#ifndef MINILOG_MINILOG_H
#define MINILOG_MINILOG_H

#include "details/SourceLoc.h"
#include "logger/LoggerRegister.h"
#include <source_location>

namespace MiniLog {

// TODO::use c++20 feature to get the source location, but function_name contains the return type
// so now temporarily use __func__ to get the function name
#define MINILOG_CALL(...)                                                                \
    MiniLog::log(MiniLog::Detail::SourceLoc{std::source_location::current().file_name(), \
                                            std::source_location::current().line(),      \
                                            __func__},                                   \
                 __VA_ARGS__)
#define MINILOG(...) MINILOG_CALL(__VA_ARGS__)

    template<class T>
    void log(const T &message) {
        auto logger = LoggerRegister::get_instance().get_default_logger();
        logger->log(message);
    }

    template<class T>
    void log(const Detail::SourceLoc &source_loc, const T &message) {
        auto logger = LoggerRegister::get_instance().get_default_logger();
        logger->log(source_loc, message);
    }
}// namespace MiniLog

#endif//MINILOG_MINILOG_H
