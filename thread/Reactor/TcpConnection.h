/**
 * Project C++
 */
#ifndef _TCPCONNECTION_H
#define _TCPCONNECTION_H
#include "InetAddress.h"
#include <functional>
#include <memory>
#include "SocketIO.h"
#include "Socket.h"

using std::function;
using std::shared_ptr;
using std::enable_shared_from_this;

using Functor = function<void()>;
class EpollLoop;

class TcpConnection
:public enable_shared_from_this<TcpConnection>
{

using TcpConnectionPtr = shared_ptr<TcpConnection>;
using callBack = function<void(const TcpConnectionPtr&)>;
public: 
    
/**
 * @param connFd;int
 */
TcpConnection(int connFd,EpollLoop* epollLoop);
    
~TcpConnection();
    
void send(const string& msg);
string reveive();
    
InetAddress getPeerInetAddress();
InetAddress getLocalInetAddress();
string toString();
    
void setNewConnCb(const callBack& cb);
void setCloseConnCb(const callBack& cb);
void setMessageCb(const callBack& cb);
void handleNewConnCb();
void handleCloseConnCb();
void handleMessageCb();

bool isClosed();
    
void sendInLoop(const string& msg);
private: 
    SocketIO _sockIo;
    Socket _sock;
    InetAddress _peerInetAddress;
    InetAddress _localInetAddress;
    callBack _onNewConnCb;
    callBack _onCloseConnCb;
    callBack _onMessageCb;
    EpollLoop* _epollLoop;
};

#endif //_TCPCONNECTION_H
