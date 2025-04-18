/**
 * Project C++
 */
#ifndef _EPOLLLOOP_H
#define _EPOLLLOOP_H
#include "Acceptor.h"
#include <sys/epoll.h>
#include <memory>
#include <functional>
#include <map>
#include <vector>
#include <vector>
#include <mutex>

class TcpConnection;
using std::shared_ptr;
using std::function;
using std::vector;
using std::map;
using std::mutex;
using TcpConnectionPtr  = shared_ptr<TcpConnection>;
using callBack = function<void(const TcpConnectionPtr&)>;
using Functor = function<void()>;

class EpollLoop {
public: 
    
/**
 * @param acceptor
 */
EpollLoop(Acceptor* acceptor);
    
~EpollLoop();
    
void loop();
    
void unloop();
    
/**
 * @param cb
 */
void setNewConnCb(callBack&& cb);
    
/**
 * @param cb
 */
void setCloseConnCb(callBack&& cb);
    
/**
 * @param cb
 */
void setMessageCb(callBack&& cb);
    
int createEventFd();
    
void handleRead();
    
void wake();
    
void runInLoop(Functor&& functor);
void doPundings();
private: 
    int _epollFd;
    bool _isLooping;
    map<int,shared_ptr<TcpConnection>> _conns;
    vector<struct epoll_event> _events;
    callBack _onNewConnCb;
    callBack _onCloseConnCb;
    callBack _onMessageCb;
    int _eventFd;
    Acceptor* _acceptor;
    vector<Functor> _pundings;
    mutex _mutex;
    
int createEpollFd();
    
void waitEpoll();
    
/**
 * @param fd
 */
void addEpollFd(int fd);
    
/**
* @param fd
*/
void delEpollFd(int fd);
    
void handleNewConn();
    
void handleMessage(int connFd);

};

#endif //_EPOLLLOOP_H
