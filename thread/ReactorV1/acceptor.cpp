/**
 * Project C++
 */
#include "acceptor.h"
#include <sys/types.h>
#include <sys/socket.h>

/**
 * acceptor implementation
 */
/**
 * @param ip
 * @param port
 */
acceptor::acceptor(const string& ip, unsigned short port)
     :_sock()
     ,_addr(ip,port)
{}

acceptor::~acceptor() {}

/**
 * @return void
 */
void acceptor::ready() {
    reuseAddr();
    reusePort();
    bind();
    listen();
}

/**
 * @return void
 */
void acceptor::bind() {
    socklen_t len = sizeof(_addr._addr);
    if(::bind(_sock.getFd(),_addr.getInetAddressPtr(),len) < 0){
        perror("bind failed");
        return;
    }
}

/**
 * @return void
 */
void acceptor::listen() {
    if(::listen(_sock.getFd(),128) < 0){
        perror("listen");
        return;
    }
}

/**
 * @return int
 */
int acceptor::accept() {
    socklen_t len = sizeof(_addr);
    int connFd = ::accept(_sock.getFd(),_addr.getInetAddressPtr(),&len);
    return connFd;
}

/**
 * @return void
 */
void acceptor::reuseAddr() {
    int opt = 1;
    int ret = ::setsockopt(_sock.getFd(),SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    if(-1 == ret){
        perror("setsockopt addr");
        return;
    }
}
/**
* @return void
*/
void acceptor::reusePort() {
    int opt = 1;
    int ret = ::setsockopt(_sock.getFd(),SOL_SOCKET,SO_REUSEPORT,&opt,sizeof(opt));
    if(-1 == ret){
        perror("setsockopt port");
        return;
    }
}
