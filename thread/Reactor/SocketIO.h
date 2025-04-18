/**
 * Project C++
 */
#ifndef _SOCKETIO_H
#define _SOCKETIO_H
#include <iostream>

class SocketIO {
public: 
    
/**
 * @param fd
 */
SocketIO(int fd);
    
~SocketIO();
    
/**
 * @param msg
 * @param n
 */
size_t writen(const char* msg, size_t n);
    
/**
 * @param buff
 */
size_t getLine(char* buff);
private: 
    int _connFd;
    
/**
 * @param buff
 * @param n
 */
size_t readn(char* buff, size_t n);
};

#endif //_SOCKETIO_H
