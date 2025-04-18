/**
 * Project C++
 */


#ifndef _TCPCONNECTION_H
#define _TCPCONNECTION_H
#include "Socket.h"
#include "SocketIO.h"
#include "InetAddress.h"
#include <string>
using std::string;

class TcpConnection {

public: 
    
/**
 * @param fd
 */
TcpConnection(int fd);
    
~TcpConnection();
    
/**
 * @param msg
 */
void send(const string& msg);
    
string receive();

const string toString();
private: 
    SocketIO _sockIO;
    Socket _sock;
    InetAddress _localAddress;
    InetAddress _peerAddress;
    
InetAddress getLocalAddress();
    
InetAddress getPeerAddress();
};

#endif //_TCPCONNECTION_H
