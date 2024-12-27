# 从零开始实现一个日志库(三)

## Day-3

### 今日目标

1. 支持多logger与多sink，为后续日志多目的地做准备
   新增注册机制，提供default logger
2. 新增Basic File Sink

### 具体实现

1. 新增`LoggerRegister`类，单例，用于管理所有logger
2. 去除`Logger`和`Sink`的单例属性
3. 新增`FileSink`类，用于将日志写入文件

#### 细节

LoggerRegister提供`get_default_logger`接口，并在初始化时直接创建default logger,其sink为stdout。