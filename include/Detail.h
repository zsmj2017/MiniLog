//
// Created by 刘祥 on 2024/12/24.
//

#ifndef MINILOG_DETAIL_H
#define MINILOG_DETAIL_H

#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>

namespace MiniLog {
    namespace Detail {
        template<class T>
        concept StringLike = std::is_convertible_v<T, std::string_view>;

        std::string get_current_time() {
            auto now = std::chrono::system_clock::now();
            std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
            std::tm now_tm = *std::localtime(&now_time_t);
            std::stringstream oss;
            oss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
            return oss.str();
        }
    }
}

#endif //MINILOG_DETAIL_H
