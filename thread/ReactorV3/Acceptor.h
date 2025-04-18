/**
 * Project C++
 */


#ifndef _ACCEPTOR_H
#define _ACCEPTOR_H

#include "InetAddress.h"
#include "Socket.h"

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
int getFd();// EpollEvent中放到红黑树上
private: 
    InetAddress _addr;
    Socket _sock;
    
void bind();
    
void listen();

void setReUseAddr();

void setReUsePort();

};

#endif //_ACCEPTOR_H
