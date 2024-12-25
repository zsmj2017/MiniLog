//
// Created by 刘祥 on 2024/12/24.
//

#ifndef MINILOG_SINK_H
#define MINILOG_SINK_H

#include "details/LogMsg.h"

namespace MiniLog {
    // TODO:: now we only have one sink and make it as a singleton
    class Sink {
    public:
        Sink() = default;

        ~Sink() = default;

        Sink &operator=(const Sink &) = delete;

        Sink(const Sink &) = delete;

        Sink &operator=(Sink &&) = delete;

        Sink(Sink &&) = delete;

    public:
        static Sink &get_instance() {
            static Sink sink;
            return sink;
        }

    public:
        void log(const details::LogMsg &message) {
            fprintf(file_, "%s\n", message.get_str().c_str());
            ::fflush(file_);// flush every line to terminal
        }

    private:
        FILE *file_ = stdout;
    };

}// namespace MiniLog


#endif//MINILOG_SINK_H
