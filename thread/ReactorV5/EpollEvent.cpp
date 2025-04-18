/**
 * Project C++
 */
#include "EpollEvent.h"
#include <sys/epoll.h>
#include "Acceptor.h"
#include "unistd.h"
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::lock_guard;


/**
 * EpollEvent implementation
 */


/**
 * @param acceptor
 */
EpollEvent::EpollEvent(Acceptor& acceptor)
    :_epollFd(epollCreate())
    ,_evFd(createEventFd())
    ,_events(1024)// count 个 value值
     ,_acceptor(acceptor)
{
    int listenFd = _acceptor.getFd();
    AddEpoll(listenFd);

    AddEpoll(_evFd);
}

EpollEvent::~EpollEvent() {
    close(_epollFd);
    close(_evFd);
}
void EpollEvent::loop(){
    _isLoop = true;
    while(_isLoop){
        cout << "server is waiting" << endl;
        epollWait();
    }
}
void EpollEvent::unloop(){
    _isLoop = false;
}
/**
 * @return void
 */
void EpollEvent::epollWait() {
    int num;
    do{
        num = epoll_wait(_epollFd,&_events[0],_events.size(),3000);
    } while(num < 0 && errno == EINTR);
    if(num  < 0){
        perror("epollWait");
        return;
    }else if(num == 0){
        cout << "epoll time out" << endl;
    }else{
        // 考虑扩容问题
        if((int)_events.size() == num){
            _events.reserve(2 * num);
        }
        for(int idx = 0;idx < num ;++idx){
            int fd = _events[idx].data.fd;
            int listenFd = _acceptor.getFd();
            if( fd == listenFd){
                handleNewConn();
            }else if(fd == _evFd){
                handleRead();
                doPundings();
            }
            else{
                handleCommConn(fd);
            }
        }
    }
}

/**
 * @return int
 */
int EpollEvent::epollCreate() {
    int epfd = epoll_create(1);
    if(epfd < 0){
        perror("epoll_create");
    }
    return epfd;
}

/**
 * @param fd
 * @return void
 */
void EpollEvent::AddEpoll(int fd) {
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;
    int ret = epoll_ctl(_epollFd,EPOLL_CTL_ADD,fd,&event);
    if(ret < 0){
        perror("EPOLL_CTL_ADD");
    }
}

/**
 * @param fd
 * @return void
 */
void EpollEvent::DelEpoll(int fd) {
    struct epoll_event event;
    event.data.fd = fd;
    int ret = epoll_ctl(_epollFd,EPOLL_CTL_DEL,fd,&event);
    if(ret < 0){
        perror("EPOLL_CTL_DEL");
    }
    return;
}

/**
 * @return void
 */
void EpollEvent::handleNewConn() {
    int connFd = _acceptor.accept();
    if(connFd < 0){
        perror("handleNewConn");
        return;
    }
    AddEpoll(connFd);
    shared_ptr<TcpConnection> conn(new TcpConnection(connFd,this));
    //TcpConnection conn2(connFd);
    //_conns2[connFd] = std::move(conn2);
    _conns[connFd] = conn; 

    conn->setOnNewConnCb(std::move(_onNewConnCallBack));
    conn->setOnCloseConnCb(std::move(_onCloseConnCallBack));
    conn->setMessageConnCb(std::move(_OnMessageConnCallBack));
    // cout << conn->toString() << endl;
    conn->handleNewConnCb();
}

void EpollEvent::setNewConnCb(TcpConnectionCallBack&& cb){
    _onNewConnCallBack = std::move(cb);
}
void EpollEvent::setCloseConnCb(TcpConnectionCallBack&& cb){
    _onCloseConnCallBack = std::move(cb);
}
void EpollEvent::setMessageConnCb(TcpConnectionCallBack&& cb){
    _OnMessageConnCallBack = std::move(cb);
}

/**
 * @return void
 */
void EpollEvent::handleCommConn(int fd) {
    auto it = _conns.find(fd);
    if(it != _conns.end()){
        if(it->second->isClosed()){
            it->second->handleCloseConnCb();
            DelEpoll(fd);
            _conns.erase(it);
        }else{
            it->second->handleMessageConnCb();
            //string msg = it->second->receive();
            //cout << msg << endl;
            ////it->second->send(msg);
            //it->second->send("hello");
        }
    }
    else{
        cout << "不存在的连接" << endl;
        return ;
    }
}
int EpollEvent::createEventFd(){
    int evfd = eventfd(0,0);
    if(evfd < 0){
        perror("eventfd");
        return -1;
    }
    return evfd;
}
void EpollEvent::handleRead(){
    uint64_t one = 1;
    ssize_t ret = read(_evFd, &one, sizeof(uint64_t));
    if(ret != sizeof(uint64_t))
    {
        perror("handleRead");
    }

}
void EpollEvent::wakeUp(){
    uint64_t one = 1;
    ssize_t ret = write(_evFd, &one, sizeof(uint64_t));
    if(ret != sizeof(uint64_t))
    {
        perror("wakeup");
    }

}
void EpollEvent::runInLoop(Functor&& functor){
    {
    lock_guard<mutex> lg(_mutex);
    _pundings.push_back(std::move(functor));
    }
    wakeUp();
}
void EpollEvent::doPundings(){
    vector<Functor> tmp;
    {
        lock_guard<mutex> lg(_mutex);
        tmp.swap(_pundings);
    }
    for(auto& functor:tmp){
        if(functor){
            functor();
        }else{
            cout << "_pundings is empty" << endl;
        }
    }
}
