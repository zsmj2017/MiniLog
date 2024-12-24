#include "MiniLog.h"

int main() {
    MiniLog::log("Hello, World!");

    auto str = std::string("str Hello, World!");

    MiniLog::log(str);

    std::string_view sv = "sv Hello, World!";
    MiniLog::log(sv);
    return 0;
}
