/**
 * Project C++
 */
#ifndef _TIMERFD_H
#define _TIMERFD_H
#include <functional>
using std::function;

using callBack = function<void()>;
class TimerFd {
public: 
    
/**
 * @param cb
 * @param initSec
 * @param periodSec
 */
TimerFd(callBack&& cb, int initSec, int periodSec);
    
~TimerFd();
    
int createTimerFd();
    
void start();
    
/**
 * @param initSec
 * @param PeriodSec
 */
void setTimer(int initSec, int PeriodSec);
    
void stop();
    
void handleRead();
private: 
    int _timerFd;
    callBack _cb;
    bool _isLoop;
    int _initSec;
    int _periodSec;
};

#endif //_TIMERFD_H
