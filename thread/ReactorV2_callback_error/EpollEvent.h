/**
 * Project C++
 */


#ifndef _EPOLLEVENT_H
#define _EPOLLEVENT_H
#include "TcpConnection.h"

#include <map>
#include <vector>
#include <memory>
#include <functional>


using std::shared_ptr;
using std::map;
using std::vector;
using std::function;


class Acceptor;
using TcpConnectionPtr = shared_ptr<TcpConnection>;
using TcpConnectionCallBack = function<void(const TcpConnectionPtr&)>;
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
private: 
    int _epollFd;
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
