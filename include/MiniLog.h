#ifndef MINILOG_MINILOG_H
#define MINILOG_MINILOG_H

#include "Logger.h"
#include "Detail.h"

namespace MiniLog {
    template<class T>
    requires Detail::StringLike<T>
    void log(const T &message) {
        auto &logger = Logger::get_instance();
        logger.log(message);
    }
}

#endif //MINILOG_MINILOG_H
