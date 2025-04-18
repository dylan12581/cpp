/**
 * Project C++
 */
#ifndef _EPOLLEVENT_H
#define _EPOLLEVENT_H
#include "TcpConnection.h"

#include <map>
#include <vector>
#include <memory>

using std::shared_ptr;
using std::map;
using std::vector;

class Acceptor;
class EpollEvent {
public: 
    
/**
 * @param acceptor
 */
EpollEvent(Acceptor& acceptor);
    
 ~EpollEvent();
void loop();
void unloop();
    
private: 
    int _epollFd;
    vector<struct epoll_event> _events;
    Acceptor& _acceptor;
    map<int,shared_ptr<TcpConnection>> _conns;
    //map<int,TcpConnection> _conns2;
    bool _isLoop;
    
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
