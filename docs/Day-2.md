# 从零开始实现一个日志库(二)

## Day-2

### 今日目标

1. 提取和抽象msg类
2. 打印source location

### 具体实现

1. Msg类

当前仅包含3个字段, `source location`, `timestamp`, `payload`。

2. 记录source location

通过新增

```cpp
#define MINILOG_CALL(...)                                                                \
    MiniLog::log(MiniLog::Detail::SourceLoc{std::source_location::current().file_name(), \
                                            std::source_location::current().line(),      \
                                            __func__},                                   \
                 __VA_ARGS__)
#define MINILOG(...) MINILOG_CALL(__VA_ARGS__)
```

完成记录，需要注意的是，`std::source_location::current().file_name()`返回的是完整函数签名，因此暂时使用`__func__`代替。

## Day-3 TODO

1. 实现日志落盘

