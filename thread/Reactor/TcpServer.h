/**
 * Project C++
 */


#ifndef _TCPSERVER_H
#define _TCPSERVER_H
#include <string>
#include "Acceptor.h"
#include "EpollLoop.h"

using std::string;

class TcpServer {
public: 
    
/**
 * @param ip
 * @param port
 */
TcpServer(const string& ip, unsigned short port);
    
~TcpServer();
    
void start();
    
void stop();
private: 
    Acceptor _acceptor;
    EpollLoop _epollLoop;
};

#endif //_TCPSERVER_H
