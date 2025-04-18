/**
 * Project C++
 */


#include "TcpConnection.h"
#include "string.h"
#include <sys/socket.h>
#include <sstream>
#include <iostream>

using std::ostringstream;
using std::cout;
using std::endl;
/**
 * TcpConnection implementation
 */
/**
 * @param fd
 */
TcpConnection::TcpConnection(int fd)
    :_sockIO(fd)
     ,_sock(fd)
     ,_localAddress(getLocalAddress())
     ,_peerAddress(getPeerAddress())
{
}

TcpConnection::~TcpConnection() {
}

/**
 * @param msg
 * @return void
 */
void TcpConnection::send(const string& msg) {
    _sockIO.writen(msg.c_str(),msg.size());
}

/**
 * @return string
 */
string TcpConnection::receive() {
    char buff[65535] = {0};
    _sockIO.getLine(buff,sizeof(buff));
    return string(buff);
}

bool TcpConnection::isClosed()const{

    char buff[5] = {0};
    int ret = recv(_sock.getFd(),buff,sizeof(buff),MSG_PEEK);
    return ret == 0;
}

/**
 * @return InetAddress
 */
InetAddress TcpConnection::getLocalAddress() {
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    socklen_t len = sizeof(addr);
    getsockname(_sock.getFd(),(struct sockaddr*)&addr,&len);
    return InetAddress(addr);
}

/**
 * @return InetAddress
 */
InetAddress TcpConnection::getPeerAddress() {
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    socklen_t len = sizeof(addr);
    getpeername(_sock.getFd(),(struct sockaddr*)&addr,&len);
    return InetAddress(addr);
}

const string TcpConnection::toString()const{
    ostringstream oss;
    oss << _peerAddress.getIP() << " " << _peerAddress.getPort() << "---------"
        << _localAddress.getIP() << " " << _localAddress.getPort();
    return oss.str();

}

void TcpConnection::setOnNewConnCb(const TcpConnectionCallBack& cb){
    _onNewConnCallBack = cb;

}
void TcpConnection::setOnCloseConnCb(const TcpConnectionCallBack& cb){
    _onCloseConnCallBack = cb;

}
void TcpConnection::setMessageConnCb(const TcpConnectionCallBack& cb){
    _OnMessageCallBack = cb;

}
void TcpConnection::handleNewConnCb(){
    if(_onNewConnCallBack){
        _onNewConnCallBack(shared_from_this());
    }else{
        cout << "_onNewConnCallBack == nullptr" << endl;
    }

}
void TcpConnection::handleCloseConnCb(){
    if(_onCloseConnCallBack){
        _onCloseConnCallBack(shared_from_this());
    }else{
        cout << "_onCloseConnCallBack == nullptr" << endl;
    }
    
}
void TcpConnection::handleMessageConnCb(){
    if(_OnMessageCallBack){
        _OnMessageCallBack(shared_from_this());
    }else{
        cout << "_OnMessageCallBack == nullptr" << endl;
    }
}





