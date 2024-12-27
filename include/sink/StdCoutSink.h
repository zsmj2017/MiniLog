#ifndef MINILOG_STDCOUTSINK_H
#define MINILOG_STDCOUTSINK_H

#include "SinkBase.h"
#include "details/LogMsg.h"

namespace MiniLog {
    class StdCoutSink : public SinkBase {
    public:
        void log(const details::LogMsg &message) override {
            fprintf(file_, "%s\n", message.get_str().c_str());
            fflush(file_);// flush every line to terminal
        }

        void flush() override {
            fflush(file_);
        }

    private:
        FILE *file_ = stdout;
    };

}// namespace MiniLog


#endif//MINILOG_STDCOUTSINK_H
