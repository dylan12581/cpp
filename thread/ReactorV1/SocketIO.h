/**
 * Project C++
 */
#ifndef _SOCKETIO_H
#define _SOCKETIO_H
#include <sys/types.h>
#include <sys/socket.h>
#include <string>
using std::string;

class SocketIO {

public: 
int _connfd;

SocketIO(int fd);
~SocketIO();
/**
 * @param fd
 * @param n
 */
size_t readn(char* buf, size_t n);
/**
 * @param fd
 * @param n
 */
size_t writen(const char* buf, size_t n);
/**
 * @param fd
 */
size_t getLine(char* buf,size_t n);

};

#endif //_SOCKETIO_H
