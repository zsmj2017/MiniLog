#ifndef MINILOG_SOURCELOC_H
#define MINILOG_SOURCELOC_H

namespace MiniLog {
    namespace Detail {
        struct SourceLoc {
            SourceLoc() = default;

            SourceLoc(const char *filename, size_t line, const char *funcname)
                : filename_{filename},
                  line_{line},
                  funcname_{funcname} {}

            bool empty() const { return line_ == 0; }

            // TODO:: need a formatter to format the source location
            std::string get_str() const {
                return "[" + std::string(filename_) + ":" + std::to_string(line_) + "]" + "(" + std::string(funcname_) + ")";
            }

            const char *filename_{nullptr};
            size_t line_{0};
            const char *funcname_{nullptr};
        };
    }// namespace Detail
}// namespace MiniLog

#endif//MINILOG_SOURCELOC_H
