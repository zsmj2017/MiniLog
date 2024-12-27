#ifndef MINILOG_SINKBASE_H
#define MINILOG_SINKBASE_H

#include "details/LogMsg.h"

namespace MiniLog {
    class SinkBase {
    public:
        SinkBase() = default;

        virtual ~SinkBase() = default;
        // All sink should not be copied or moved
        SinkBase(const SinkBase &) = delete;

        SinkBase &operator=(const SinkBase &) = delete;

        SinkBase(SinkBase &&) = delete;

        SinkBase &operator=(SinkBase &&) = delete;

    public:
        virtual void log(const details::LogMsg &msg) = 0;

        virtual void flush() = 0;
    };
}// namespace MiniLog

#endif//MINILOG_SINKBASE_H
