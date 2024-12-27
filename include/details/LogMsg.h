#ifndef MINILOG_LOGMSG_H
#define MINILOG_LOGMSG_H

#include "Common.h"
#include "SourceLoc.h"
#include <string_view>


namespace MiniLog::details {
    class LogMsg {
    public:
        LogMsg() = default;

        explicit LogMsg(std::string_view payload) : LogMsg(Detail::SourceLoc{}, std::chrono::system_clock::now(), payload) {}

        LogMsg(Detail::SourceLoc source_loc, std::chrono::system_clock::time_point log_time, std::string_view payload) : source_loc_(source_loc), log_time_(log_time),
                                                                                                                         payload_(payload) {}

        LogMsg(Detail::SourceLoc source_loc, std::string_view payload) : LogMsg(source_loc, std::chrono::system_clock::now(), payload) {}

        LogMsg(const LogMsg &other) = default;

        LogMsg &operator=(const LogMsg &other) = default;

        LogMsg(LogMsg &&other) noexcept = default;

        LogMsg &operator=(LogMsg &&other) noexcept = default;

    public:
        // TODO:: need a formatter to format the log message
        std::string get_str() const {
            if (source_loc_.empty()) {
                return "[" + Detail::str_timestamp(log_time_) + "] " + std::string(payload_);
            } else {
                return "[" + Detail::str_timestamp(log_time_) + "] " + source_loc_.get_str() + " " + std::string(payload_);
            }
        }

    private:
        std::chrono::system_clock::time_point log_time_;
        std::string_view payload_;
        Detail::SourceLoc source_loc_;
    };
}// namespace MiniLog::details


#endif//MINILOG_LOGMSG_H
