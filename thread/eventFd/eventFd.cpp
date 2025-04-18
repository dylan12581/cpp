#include "eventFd.h"
#include <unistd.h>
#include <poll.h>
#include <sys/eventfd.h>
#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

EventFd::EventFd(EventFdCallback &&cb)
: _evtfd(createEventFd())
, _cb(std::move(cb))
, _isStarted(false)
{}

EventFd::~EventFd(){
    close(_evtfd);
}

//开始与结束
void EventFd::start(){
    struct pollfd pfd;
    pfd.fd = _evtfd;//监听该文件描述符
    pfd.events = POLLIN;

    _isStarted = true;
    while(_isStarted){
        int nready = poll(&pfd, 1, 5000);
        if(-1 == nready && errno == EINTR){
            continue;
        }
        else if(-1 == nready){
            cerr << "-1 == nready" << endl;
            return;
        }
        else if(0 == nready){
            cout << ">>poll time_out!!!" << endl;
        }
        else {
            if(pfd.revents & POLLIN){
                handleRead();
                if(_cb){
                    _cb();//执行任务
                }
            }
        }
    }
}

void EventFd::stop(){
    _isStarted = false;
}
//创建用于通知的文件描述符
int EventFd::createEventFd(){
    int fd = eventfd(0, 0);
    if(fd < 0){
        perror("createEventFd");
        return -1;
    }
    return fd;
}
//封装read操作
void EventFd::handleRead(){
    uint64_t one = 1;
    ssize_t ret = read(_evtfd, &one, sizeof(uint64_t));
    if(ret != sizeof(uint64_t)){
        perror("handleRead");
    }
}
//封装write函数
void EventFd::wakeup(){
    uint64_t one = 1;
    ssize_t ret = write(_evtfd, &one, sizeof(uint64_t));
    if(ret != sizeof(uint64_t)){
        perror("wakeup");
    }
}

