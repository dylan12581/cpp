/**
 * Project C++
 */
#include "TimerFd.h"
#include "unistd.h"
#include "stdio.h"
#include "errno.h"
#include "sys/timerfd.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <cstdint>
#include "poll.h"
#include <iostream>

using std::cerr;
using std::endl;
using std::cout;
/**
 * TimerFd implementation
 */
/**
 * @param cb
 * @param initSec
 * @param periodSec
 */
TimerFd::TimerFd(callBack&& cb, int initSec, int periodSec) 
    :_timerFd(createTimerFd())
    ,_cb(std::move(cb))
    ,_isLoop(false)
    ,_initSec(initSec)
     ,_periodSec(periodSec)
{}

TimerFd::~TimerFd() {
    close(_timerFd);
}

/**
 * @return int
 */
int TimerFd::createTimerFd() {
    int TimerFd = timerfd_create(CLOCK_REALTIME,0);
    if(TimerFd < 0){
        perror("TimerFd");
        return TimerFd;
    }
    return TimerFd;
}

/**
 * @return void
 */
void TimerFd::start() {
    _isLoop = true;
    struct pollfd event;
    event.fd = _timerFd;
    event.events = POLLIN;
    setTimer(_initSec,_periodSec);
    while(_isLoop){
        int ret = poll(&event,1,5000);
        if(ret < 0 && errno == EINTR){
            continue;
        }else if(ret < 0){
            cerr << "poll";
            return;
        }else if(ret == 0){
            cout << "time out" << endl;
        }else{
            if(event.events & POLLIN){
                handleRead();
                if(_cb){
                    _cb();
                }else{
                    cout << "_cb == nullptr" << endl;
                }
            } 
        }
    }
}

/**
 * @param initSec
 * @param PeriodSec
 */
void TimerFd::setTimer(int initSec, int PeriodSec) {
    struct itimerspec newValue;
    newValue.it_interval.tv_sec = PeriodSec;
    newValue.it_interval.tv_nsec = 0;
    newValue.it_value.tv_sec = initSec;
    newValue.it_value.tv_nsec = 0;
    int ret = timerfd_settime(_timerFd,0,&newValue,nullptr);
    if(ret < 0){
        perror("timerfd_settime");
        return;
    }
}

/**
 * @return void
 */
void TimerFd::stop() {
    if(_isLoop){
        _isLoop = false;
        setTimer(0,0);
        return;
    }
}

/**
 * @return void
 */
void TimerFd::handleRead() {
    uint64_t one = 1;
    ssize_t ret = read(_timerFd, &one, sizeof(uint64_t));
    if(ret != sizeof(uint64_t))
    {
        perror("handleRead");
    }
}
