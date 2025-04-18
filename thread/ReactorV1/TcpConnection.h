/**
 * Project C++
 */
#ifndef _TCPCONNECTION_H
#define _TCPCONNECTION_H
#include "SocketIO.h"
#include "Socket.h"
#include "InetAddress.h"
#include <string>
using std::string;

class TcpConnection {
private: 
    SocketIO _sock;
    // 三个数据成员用于测试用
    Socket _soc;// 
    InetAddress _localAddress;
    InetAddress _peerAddress;
public:
/**
 * @param fd
 */
TcpConnection(int fd);
/**
 * @param msg
 */
void send(const string& msg);
    
string receive();
~TcpConnection();

InetAddress getLocalAddress();
InetAddress getPeerAddress();
string toString();

};

#endif //_TCPCONNECTION_H
