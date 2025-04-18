/**
 * Project C++
 */


#ifndef _EPOLLEVENT_H
#define _EPOLLEVENT_H
#include "TcpConnection.h"
#include "sys/eventfd.h"

#include <map>
#include <vector>
#include <memory>
#include <functional>
#include <mutex>


using std::shared_ptr;
using std::map;
using std::vector;
using std::function;
using std::mutex;


class Acceptor;
using TcpConnectionPtr = shared_ptr<TcpConnection>;
using TcpConnectionCallBack = function<void(const TcpConnectionPtr&)>;
using Functor = function<void()>;
class EpollEvent {
public: 
    
/**
 * @param acceptor
 */
EpollEvent(Acceptor& acceptor);
    
 ~EpollEvent();
void loop();
void unloop();
void setNewConnCb(TcpConnectionCallBack&& cb);
void setCloseConnCb(TcpConnectionCallBack&& cb);
void setMessageConnCb(TcpConnectionCallBack&& cb);

int createEventFd();
void handleRead();
void wakeUp();
void runInLoop(Functor&& functor);
void doPundings();
private: 
    int _epollFd;
    int _evFd;
    mutex _mutex;
    vector<Functor> _pundings;
    vector<struct epoll_event> _events;
    Acceptor& _acceptor;
    map<int,shared_ptr<TcpConnection>> _conns;
    //map<int,TcpConnection> _conns2;
    bool _isLoop;
    TcpConnectionCallBack _onNewConnCallBack;
    TcpConnectionCallBack _onCloseConnCallBack;
    TcpConnectionCallBack _OnMessageConnCallBack;
    
void epollWait();
int epollCreate();
    
/**
 * @param fd
 */
void AddEpoll(int fd);
    
/**
 * @param fd
 */
void DelEpoll(int fd);
    
void handleNewConn();
    
void handleCommConn(int fd);
};

#endif //_EPOLLEVENT_H
