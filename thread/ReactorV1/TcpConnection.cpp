/**
 * Project C++
 */
#include "TcpConnection.h"
#include <sstream>
using std::ostringstream;
/**
 * TcpConnection implementation
 */

/**
 * @param fd
 */

TcpConnection::TcpConnection(int fd)
    :_sock(fd)
     ,_soc(fd)
     ,_localAddress(getLocalAddress())
     ,_peerAddress(getPeerAddress())
{}

/**
 * @param msg
 * @return void
 */
void TcpConnection::send(const string& msg) {
    _sock.writen(msg.c_str(),msg.size());
}

/**
 * @return string
 */
string TcpConnection::receive() {
    char buf[65535] = {0};
    _sock.getLine(buf,sizeof(buf));
    return string(buf);
}

TcpConnection::~TcpConnection(){};
InetAddress TcpConnection::getLocalAddress(){
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr);
    int ret = getsockname(_soc.getFd(),(struct sockaddr*)&addr,&len);
    if(ret == -1){
        perror("getsockname");
    }
    return InetAddress(addr);
}

InetAddress TcpConnection::getPeerAddress(){

    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr);
    int ret = getpeername(_soc.getFd(),(struct sockaddr*)&addr,&len);
    if(ret == -1){
        perror("getpeername");
    }
    return InetAddress(addr);
}

string TcpConnection::toString(){
    ostringstream oss;
    oss << _localAddress.getIP() <<" " <<  _localAddress.getPort() << "---->" 
        << _peerAddress.getIP() << " " << _peerAddress.getPort() ;
    return oss.str();
}

