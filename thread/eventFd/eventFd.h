#ifndef __EVENTFD_H__
#define __EVENTFD_H__

#include <functional>
using std::function;

class EventFd{
    using EventFdCallback = function<void()>;
public:
    EventFd(EventFdCallback &&cb);
    ~EventFd();

    //开始与结束
    void start();
    void stop();
    //创建用于通知的文件描述符
    int createEventFd();
    //封装read操作
    void handleRead();
    //封装write函数
    void wakeup();

private:
    int _evtfd;//用于通知的文件描述符
    EventFdCallback _cb;//被唤醒后需要执行的任务
    bool _isStarted;//标识循环是否运行的标志
};

#endif
