//
// Created by 刘祥 on 2024/12/24.
//

#ifndef MINILOG_COMMON_H
#define MINILOG_COMMON_H

#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>

namespace MiniLog {
    namespace Detail {
        std::string str_timestamp(const std::chrono::system_clock::time_point &time) {
            std::time_t now_time_t = std::chrono::system_clock::to_time_t(time);
            std::tm now_tm = *std::localtime(&now_time_t);
            std::stringstream oss;
            oss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
            return oss.str();
        }
    }
}

#endif //MINILOG_COMMON_H
