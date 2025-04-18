/**
 * Project C++
 */


#ifndef _ACCEPTOR_H
#define _ACCEPTOR_H
#include "Socket.h"
#include "InetAddress.h"

class Acceptor {
public: 
    
/**
 * @param ip
 * @param port
 */
Acceptor(const string& ip, unsigned short port);
    
~Acceptor();
    
void ready();
    
int accept();
int getSockFd();
private: 
    Socket _sockFd;
    InetAddress _addr;
    
void bind();
    
void listen();
    
void setReuseIp();
    
void setReUsePort();
};

#endif //_ACCEPTOR_H
