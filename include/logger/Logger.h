#ifndef MINILOG_LOGGER_H
#define MINILOG_LOGGER_H

#include "details/LogMsg.h"
#include "details/SourceLoc.h"
#include "sink/SinkBase.h"

namespace MiniLog {
    class Logger {
    public:// ctor
        Logger(std::string name) : name_(std::move(name)), sinks_() {}

        // Logger with range on sinks
        template<typename It>
        Logger(std::string name, It begin, It end)
            : name_(std::move(name)),
              sinks_(begin, end) {}

        // Logger with single sink -> convert to range
        Logger(std::string name, std::shared_ptr<SinkBase> single_sink)
            : Logger(std::move(name), {std::move(single_sink)}) {}

        Logger(std::string name, std::initializer_list<std::shared_ptr<SinkBase>> sinks)
            : Logger(std::move(name), sinks.begin(), sinks.end()) {}

    public:// copy
        Logger(const Logger &other) : name_(other.name_), sinks_(other.sinks_) {}
        Logger &operator=(const Logger &other) noexcept {
            Logger tmp(other);
            swap(tmp);
            return *this;
        }

    public:// move
        Logger(Logger &&other) noexcept : name_(std::move(other.name_)), sinks_(std::move(other.sinks_)) {}
        Logger &operator=(Logger &&other) noexcept {
            swap(other);
            return *this;
        }

    public:
        void swap(Logger &other) noexcept {
            std::swap(name_, other.name_);
            std::swap(sinks_, other.sinks_);
        }

    public:
        template<class T>
        void log(const T &message) {
            log_aux(Detail::SourceLoc{}, message);
        }

        template<class T>
        void log(const Detail::SourceLoc &source_loc, const T &message) {
            log_aux(source_loc, message);
        }

    private:
        void log_aux(const Detail::SourceLoc &source_loc, std::string_view message) {
            auto log_msg = details::LogMsg(source_loc, message);
            for (auto &sink: sinks_) {
                sink->log(log_msg);
            }
        }

    private:
        std::string name_;
        std::vector<std::shared_ptr<SinkBase>> sinks_;
    };
}// namespace MiniLog

#endif//MINILOG_LOGGER_H
