/**
 * Project C++
 */
#ifndef _TCPCONNECTION_H
#define _TCPCONNECTION_H
#include "Socket.h"
#include "SocketIO.h"
#include "InetAddress.h"
#include <string>
#include <functional>
#include <memory>
using std::string;
using std::function;
using std::shared_ptr;

class EpollEvent;
class TcpConnection 
:public std::enable_shared_from_this<TcpConnection>
{
    using TcpConnectionPtr = shared_ptr<TcpConnection>;
    using TcpConnectionCallBack = function<void(const TcpConnectionPtr&)>;
    using Functor = function<void()>;
public: 
/**
 * @param fd
 */
TcpConnection(int fd,EpollEvent* eventLoop);
    
~TcpConnection();
/**
 * @param msg
 */
void send(const string& msg);
    
string receive();

const string toString()const;
bool isClosed()const;

void setOnNewConnCb(const TcpConnectionCallBack& cb);
void setOnCloseConnCb(const TcpConnectionCallBack& cb);
void setMessageConnCb(const TcpConnectionCallBack& cb);
void handleNewConnCb();
void handleCloseConnCb();
void handleMessageConnCb();

void sendInLoop(const string& msg);
    
private: 
    SocketIO _sockIO;
    Socket _sock;
    InetAddress _localAddress;
    InetAddress _peerAddress;
    TcpConnectionCallBack _onNewConnCallBack;
    TcpConnectionCallBack _onCloseConnCallBack;
    TcpConnectionCallBack _OnMessageCallBack;
    EpollEvent* _epollLoop;

InetAddress getLocalAddress();
    
InetAddress getPeerAddress();
};

#endif //_TCPCONNECTION_H
