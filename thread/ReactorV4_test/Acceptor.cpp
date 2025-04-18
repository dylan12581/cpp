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
    :_addr(ip,port)
     ,_sock()
{

}

Acceptor::~Acceptor() {

}
int Acceptor::getFd(){
    return _sock.getFd();
}

/**
 * @return void
 */
void Acceptor::ready() {
    setReUseAddr();
    setReUsePort();
    bind();
    listen();
}

/**
 * @return int
 */
int Acceptor::accept() {
    socklen_t len = sizeof(_addr);
    int connFd = ::accept(_sock.getFd(),_addr.getInetAddressPtr(),&len) ;
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

    if(::bind(_sock.getFd(),_addr.getInetAddressPtr(),sizeof(_addr)) < 0)
    {
        perror("bind");
        return;
    }
}

/**
 * @return void
 */
void Acceptor::listen() {
    if(::listen(_sock.getFd(),128) < 0){
        perror("listen");
        return;
    }
}
void Acceptor::setReUseAddr(){
    int opt = 1;
    socklen_t len = sizeof(opt);
    if(setsockopt(_sock.getFd(),SOL_SOCKET,SO_REUSEADDR,&opt,len) < 0){
        perror("setsockopt setReUseAddr");
        return;
    }

}

void Acceptor::setReUsePort(){
    int opt = 1;
    socklen_t len = sizeof(opt);
    if(setsockopt(_sock.getFd(),SOL_SOCKET,SO_REUSEPORT,&opt,len) < 0){
        perror("setsockopt setReUsePort");
        return;
    }

}
