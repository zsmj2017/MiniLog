#include "MiniLog.h"
#include "sink/BasicFileSink.h"

int main() {
    MiniLog::log("Hello, World!");

    auto str = std::string("str Hello, World!");

    MiniLog::log(str);

    std::string_view sv = "sv Hello, World!";
    MiniLog::log(sv);

    MINILOG("hello, world!");


    auto file_logger = MiniLog::create_file_logger("file_logger", "/Users/zsmj/MiniLogGit/test.log");
    file_logger->log("Hello, World!");
    file_logger->log(str);
    file_logger->log(sv);
    return 0;
}
