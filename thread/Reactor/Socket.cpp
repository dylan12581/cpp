/**
 * Project C++
 */
#include "Socket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include "unistd.h"

/**
 * Socket implementation
 */
Socket::Socket() 
    :_fd(socket(AF_INET,SOCK_STREAM,0))
{}

/**
 * @param fd
 */
Socket::Socket(int fd)
    :_fd(fd)
{}

Socket::~Socket() {
    close(_fd);
}
/**
 * @return int
 */
int Socket::getFd() {
    return _fd;
}
