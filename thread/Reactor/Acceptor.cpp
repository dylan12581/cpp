/**
 * Project C++
 */
#include "Acceptor.h"
#include <sys/types.h>
#include <sys/socket.h>

/**
 * Acceptor implementation
 */


/**
 * @param ip
 * @param port
 */
Acceptor::Acceptor(const string& ip, unsigned short port)
    :_sockFd()
    ,_addr(ip,port)
{}

Acceptor::~Acceptor() {
}
int Acceptor::getSockFd(){
    return _sockFd.getFd();
}

/**
 * @return void
 */
void Acceptor::ready() {
    setReuseIp();
    setReUsePort();
    bind();
    listen();
}

/**
 * @return int
 */
int Acceptor::accept() {
    socklen_t len = sizeof(_addr);
    int connFd = ::accept(_sockFd.getFd(),(struct sockaddr*)&_addr,&len);
    if(connFd < 0){
        perror("accept");
        return -1;
    }
    return connFd;
}

/**
 * @return void
 */
void Acceptor::bind() {
    socklen_t len = sizeof(_addr);
    int ret = ::bind(_sockFd.getFd(),(struct sockaddr*)&_addr,len);
    if(ret < 0){
        perror("bind");
        return;
    }
}

/**
 * @return void
 */
void Acceptor::listen() {
    int ret = ::listen(_sockFd.getFd(),128);
    if(ret < 0){
        perror("listen");
        return;
    }
}

/**
 * @return void
 */
void Acceptor::setReuseIp() {
    int opt = 1;
    int ret = setsockopt(_sockFd.getFd(),SOCK_STREAM,SO_REUSEADDR,&opt,sizeof(opt));
    if(ret < 0){
        perror("setsockopt addr");
        return;
    }
}

/**
 * @return void
 */
void Acceptor::setReUsePort() {
    int opt = 1;
    int ret = setsockopt(_sockFd.getFd(),SOCK_STREAM,SO_REUSEPORT,&opt,sizeof(opt));
    if(ret < 0){
        perror("setsockopt port");
        return;
    }
    return;
}
