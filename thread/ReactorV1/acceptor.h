/**
 * Project C++
 */
#ifndef _ACCEPTOR_H
#define _ACCEPTOR_H
#include "Socket.h"
#include "InetAddress.h"
#include <string>
using std::string;

class acceptor {
public: 
    Socket _sock;
    InetAddress _addr;
/**
 * @param ip
 * @param port
 */
acceptor(const string& ip, unsigned short port);
    
~acceptor();
    
void ready();
    
void bind();
    
void listen();
    
int accept();
    
void reuseAddr();
    
void reusePort();
};

#endif //_ACCEPTOR_H
