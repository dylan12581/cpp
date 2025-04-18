/**
 * Project C++
 */
#include "EpollLoop.h"
#include "TcpConnection.h"
#include "unistd.h"
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <memory>
#include <iostream>
using std::lock_guard;
using std::endl;
using std::cout;
/**
 * EpollLoop implementation
 */

/**
 * @param acceptor
 */
EpollLoop::EpollLoop(Acceptor* acceptor)
    :_epollFd(createEpollFd())
    ,_isLooping(false)
    ,_events(1024)
    ,_eventFd(createEventFd())
     ,_acceptor(acceptor)
{
    addEpollFd(acceptor->getSockFd()); 
    addEpollFd(_eventFd);
}

EpollLoop::~EpollLoop() {
    close(_epollFd);
    close(_eventFd);
}

/**
 * @return void
 */
void EpollLoop::loop() {
    _isLooping = true;
    while(_isLooping){
        waitEpoll();
    }
}

/**
 * @return void
 */
void EpollLoop::unloop() {
    _isLooping = false;
}

/**
 * @param cb
 */
void EpollLoop::setNewConnCb(callBack&& cb) {
    _onNewConnCb = std::move(cb);
}
void EpollLoop::setCloseConnCb(callBack&& cb) {
    _onCloseConnCb = std::move(cb);
}
void EpollLoop::setMessageCb(callBack&& cb) {
    _onMessageCb = std::move(cb);
}

/**
 * @return int
 */
int EpollLoop::createEventFd() {
    int _eventFd = eventfd(0,0);
    if(_eventFd < 0){
        perror("eventfd");
        return -1;
    }
    return _eventFd;
}
void EpollLoop::handleRead() {
    uint64_t u = 1;
    ssize_t ret = read(_eventFd,&u,sizeof(uint64_t));
    if(ret != sizeof(uint64_t)){
        perror("handleRead");
    }
}

void EpollLoop::wake() {
    uint64_t u = 1;
    ssize_t ret = write(_eventFd,&u,sizeof(uint64_t));
    if(ret != sizeof(uint64_t)){
        perror("wake");
    }
}

void EpollLoop::runInLoop(Functor && functor) {
    // 加锁
    {
    lock_guard<mutex> lg(_mutex);
    _pundings.push_back(std::move(functor));
    }
}
void EpollLoop::doPundings(){
    vector<Functor> tmp;
    {
    lock_guard<mutex> lg(_mutex);
    _pundings.swap(tmp);
    }
    for(auto& ele : tmp){
        ele();
    }
}

/**
 * @return int
 */
int EpollLoop::createEpollFd() {
    int epollFd = epoll_create(1);
    if(epollFd < 0){
        perror("epoll_create");
        return -1;
    }
    return epollFd;
}

/**
 * @return void
 */
void EpollLoop::waitEpoll() {
    int ret = epoll_wait(_epollFd,&_events[0],_events.size(),3000);
    if(ret < 0){
        perror("epoll_wait");
        return;
    }else if(ret == 0){
        cout << "time out !!!" << "\n";
    }else{
        for(int idx = 0;idx < ret;++idx){
            int fd = _events[idx].data.fd;
            if( fd == _acceptor->getSockFd()){
                handleNewConn();
            }else if(fd == _eventFd){
                handleRead();
            }else{
                handleMessage(fd);
            }
        }
    }
}

/**
 * @param fd
 * @return void
 */
void EpollLoop::addEpollFd(int fd) {
    if(_events.size() == _events.capacity()){
        _events.reserve(2 * _events.capacity());// 2倍扩容
    }
    struct epoll_event add;
    add.data.fd = fd;
    add.events = EPOLL_CTL_ADD;
    int ret = epoll_ctl(_epollFd,EPOLLIN,fd,&add);
    if(ret < 0){
        perror("failed in addEpollFd");
        return;
    }
}

/**
 * @param fd
 * @return void
 */
void EpollLoop::delEpollFd(int fd) {
    struct epoll_event del;
    del.data.fd = fd;
    del.events = EPOLL_CTL_DEL;
    int ret = epoll_ctl(_epollFd,EPOLLIN,fd,&del);
    if(ret < 0){
        perror("failed in delEpollFd");
        return;
    }
}

void EpollLoop::handleNewConn() {
    int connFd = _acceptor->accept();
    if(connFd < 0){
        return;
    }
    // 添加到监听集合
    addEpollFd(connFd);
    // 增添到map中
    TcpConnectionPtr con(new TcpConnection(connFd,this));
    _conns.insert({connFd,con});

    con->setNewConnCb(_onNewConnCb);
    con->setCloseConnCb(_onCloseConnCb);
    con->setMessageCb(_onMessageCb);
    con->handleNewConnCb();
}
/**
 * @return void
 */
void EpollLoop::handleMessage(int connFd) {
    auto it = _conns.find(connFd);
    // todo :不存在在红黑树上删除，存在调用conn的处理函数
    if(it != _conns.end()){
        bool flag = it->second->isClosed();
        if(flag){
            it->second->handleCloseConnCb();
            delEpollFd(connFd);
            _conns.erase(it);
        }else{
            cout << "before handleMessage" << endl;
            it->second->handleMessageCb();
            cout << "after handleMessage" << endl;
        }
    }else{
        cout << "连接不存在！！！！" << endl;
    }
}
