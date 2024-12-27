//
// Created by 刘祥 on 2024/12/24.
//

#ifndef MINILOG_STDCOUTSINK_H
#define MINILOG_STDCOUTSINK_H

#include "details/LogMsg.h"

namespace MiniLog {
    class StdCoutSink {
    public:
        void log(const details::LogMsg &message) {
            fprintf(file_, "%s\n", message.get_str().c_str());
            fflush(file_);// flush every line to terminal
        }

    private:
        FILE *file_ = stdout;
    };

}// namespace MiniLog


#endif//MINILOG_STDCOUTSINK_H
