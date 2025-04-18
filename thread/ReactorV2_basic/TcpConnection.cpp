/**
 * Project C++
 */


#include "TcpConnection.h"
#include "string.h"
#include <sys/socket.h>
#include <sstream>

using std::ostringstream;



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

const string TcpConnection::toString(){
    ostringstream oss;
    oss << _peerAddress.getIP() << " " << _peerAddress.getPort() << "---------"
        << _localAddress.getIP() << " " << _localAddress.getPort();
    return oss.str();

}






