/**
 * Project C++
 */


#ifndef _SOCKET_H
#define _SOCKET_H

class Socket {
public: 
Socket();
    
/**
 * @param fd
 */
Socket(int fd);
    
int getFd();

~Socket();
private: 
    int _fd;
    
};

#endif //_SOCKET_H
