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
private: 
    int _connFd;
    
/**
 * @param buff
 * @param n
 */
public:
size_t getLine(char* buff, size_t n);
    
/**
 * @param buff
 * @param n
 */
private:
size_t readn(char* buff, size_t n);
    
/**
 * @param buff
 * @param n
 */
public:
size_t writen(const char* buff, size_t n);
};

#endif //_SOCKETIO_H
