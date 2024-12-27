#ifndef MINILOG_COMMON_H
#define MINILOG_COMMON_H

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>


namespace MiniLog::Detail {
    std::string str_timestamp(const std::chrono::system_clock::time_point &time) {
        std::time_t now_time_t = std::chrono::system_clock::to_time_t(time);
        std::tm now_tm = *std::localtime(&now_time_t);
        std::stringstream oss;
        oss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }
}// namespace MiniLog::Detail


#endif//MINILOG_COMMON_H
