/**
 * Project C++
 */


#ifndef _SOCKET_H
#define _SOCKET_H
#include "NoCopyable.h"
#include <sys/types.h>
#include <sys/socket.h>

class Socket
:public NoCopyable
{

public: 
    
Socket();
    
~Socket();
    
/**
 * @param int fd
 */
Socket(int fd);
int getFd()const;
private: 
    int _sockFd;
};

#endif //_SOCKET_H
