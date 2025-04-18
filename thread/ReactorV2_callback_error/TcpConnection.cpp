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
{}

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

void TcpConnection::setOnNewConnCb(TcpConnectionCallBack&& cb){
     if(cb){
         cout << "setOnNewConnCb" << endl;
     }
     //_onNewConnCallBack = std::move(cb);
    _onNewConnCallBack = cb;

}
void TcpConnection::setOnCloseConnCb(TcpConnectionCallBack&& cb){
    _onCloseConnCallBack = cb;//这么写也是可以的，因为这里没有走移动赋值运算符函数，cb是一个左值
    if(cb){
         cout << "setOnCloseConnCb" << endl;
     }
    // _onCloseConnCallBack = std::move(cb);

}

void TcpConnection::setMessageConnCb(TcpConnectionCallBack&& cb){
    _OnMessageCallBack = cb;// 没有发生控制权的转移
     if(cb){
         cout << "setMessageConnCb" << endl;
     }
    //_OnMessageCallBack = std::move(cb);// 发生控制权的转移error，这里走了赋值运算符函数，std::move(cb)之后是一个右值，走了函数调用运算符函数
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





