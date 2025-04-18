/**
 * Project C++
 */


#include "Socket.h"
#include <unistd.h>


/**
 * Socket implementation
 */


Socket::Socket() 
    :_sockFd(socket(AF_INET,SOCK_STREAM,0))
{}

Socket::~Socket() {
    close(_sockFd);
}

/**
 * @param int fd
 */
Socket::Socket( int fd) 
    :_sockFd(fd)
{}

int Socket::getFd()const{
    return _sockFd;
}
