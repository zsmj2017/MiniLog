# 从零开始实现一个日志库(一)

## 前言

本系列将尝试从零开始实现一个c++ `header-only`的demo级日志库。
设计思路将follow [spdlog](https://github.com/gabime/spdlog)，并在其基础上使用现代c++特性做一些代码简化。
计划从最基本的日志库开始实现，逐步完善，最终实现以下基本功能。

1. 支持同步/异步日志
2. 支持日志消息多目的地落盘
3. 支持简单的消息格式化
4. 支持运行时日志级别过滤

<------More------>


## Day-1

### 今日目标

撰写一个基础header-only的日志库，其只具备以下功能：
1. 同步输出msg到stdout
2. 为msg实现基础格式化（timestamp + msg）

使用方式类似于：
```cpp
#include "spdlog/spdlog.h"

int main() {
    MiniLog::log("Hello, World!");
    return 0;
}
```

### 设计思路

1.follow常规设计思路，将日志库分为前端(logger)和后端(sink)两部分，前端负责日志消息格式化，后端负责日志消息输出。

### 具体实现

Summary:
1. 对外暴露接口层`MiniLog`
2. Logger类本用于负责日志消息格式化，但由于今日只需要给出demo级实现，因此实际上只是将消息转发至Sink
3. Sink类负责日志消息输出，当前只实现了一个stdout sink
4. 由于当前只会有一个logger和一个sink，因此将他们设置为单例


TODO:
1. 抽象msg类，否则后续无法做formatting，甚至连添加日志现场（src file info + func info）实现起来都很困难
2. 当前log函数只支持string_like类型，需要扩展
3. 引入gtest，对当前代码进行单元测试



