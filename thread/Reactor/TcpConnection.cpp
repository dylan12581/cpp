#include "TcpConnection.h"
#include "EpollLoop.h"
#include "string.h"
#include <functional>
#include <sstream>
using std::ostringstream;
using std::cout;
using std::endl;
using std::bind;

TcpConnection::TcpConnection(int connFd,EpollLoop* EpollLoop) 
     :_sockIo(connFd)
      ,_sock(connFd)
      ,_peerInetAddress(getPeerInetAddress())
      ,_localInetAddress(getLocalInetAddress())
      ,_epollLoop(EpollLoop)
{}

TcpConnection::~TcpConnection() {}

void TcpConnection::send(const string& msg) {
     _sockIo.writen(msg.c_str(),msg.size()); 
}
string TcpConnection::reveive() {
    char buff[65535] = {0};
    cout << "before getline" << endl;
    _sockIo.getLine(buff);
    return string(buff);
}
InetAddress TcpConnection::getPeerInetAddress() {
    struct sockaddr_in peerAddr;
    memset(&peerAddr,0,sizeof(peerAddr));
    peerAddr.sin_family = AF_INET;
    socklen_t len = sizeof(peerAddr);
    getpeername(_sock.getFd(),(struct sockaddr*)&peerAddr,&len);
    return InetAddress(peerAddr);
}
InetAddress TcpConnection::getLocalInetAddress() {
    struct sockaddr_in localAddr;
    memset(&localAddr,0,sizeof(localAddr));
    localAddr.sin_family = AF_INET;
    socklen_t len = sizeof(localAddr);
    getsockname(_sock.getFd(),(struct sockaddr*)&localAddr,&len);
    return InetAddress(localAddr);
}
string TcpConnection::toString() {
    ostringstream oss;
    oss << _localInetAddress.getIp() << " " << _localInetAddress.getPort()
        <<"------>" << _peerInetAddress.getIp() << " " << _peerInetAddress.getPort();
    return oss.str();
}

void TcpConnection::setNewConnCb(const callBack& cb) {
    _onNewConnCb = cb;
}
void TcpConnection::setCloseConnCb(const callBack& cb) {
    _onCloseConnCb = cb;
}
void TcpConnection::setMessageCb(const callBack& cb) {
    _onMessageCb = cb;
}

void TcpConnection::handleNewConnCb() {
    if(_onNewConnCb){
        _onNewConnCb(shared_from_this());
    }else{
        cout << "_onNewConnCb == nullptr" << endl;
    }
}
void TcpConnection::handleCloseConnCb() {
    if(_onCloseConnCb){
        _onCloseConnCb(shared_from_this());
    }else{
        cout << "_onCloseConnCb == nullptr" << endl;
    }
}
void TcpConnection::handleMessageCb() {
    if(_onMessageCb){
        _onMessageCb(shared_from_this());
    }else{
        cout << "_onMessageCb == nullptr" << endl;
    }
}

/**
 * @return void
 */
void TcpConnection::sendInLoop(const string& msg) {
    _epollLoop->runInLoop(bind(&TcpConnection::send,this,msg));
}

bool TcpConnection::isClosed(){
    char buff[5] = {0};
    int ret  = recv(_sock.getFd(),buff,sizeof(buff),MSG_PEEK);
    return ret == 0;
}
