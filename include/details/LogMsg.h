//
// Created by 刘祥 on 2024/12/24.
//

#ifndef MINILOG_LOGMSG_H
#define MINILOG_LOGMSG_H

#include "Common.h"
#include <string_view>

namespace MiniLog {
    namespace details {
        class LogMsg {
        public:
            LogMsg() = default;

            explicit LogMsg(std::string_view payload) : LogMsg(std::chrono::system_clock::now(), payload) {}

            LogMsg(std::chrono::system_clock::time_point log_time, std::string_view payload) : log_time_(log_time),
                                                                                               payload_(payload) {}

            LogMsg(const LogMsg &other) = default;

            LogMsg &operator=(const LogMsg &other) = default;

            LogMsg(LogMsg &&other) noexcept = default;

            LogMsg &operator=(LogMsg &&other) noexcept = default;

        public:
            std::string get_str_msg() const {
                return Detail::str_timestamp(log_time_) + " " + std::string(payload_);
            }

        private:
            std::chrono::system_clock::time_point log_time_;
            std::string_view payload_;
        };
    }// namespace details
}// namespace MiniLog

#endif//MINILOG_LOGMSG_H
