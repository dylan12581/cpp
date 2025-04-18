/**
 * Project C++
 */
#include "InetAddress.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "string.h"
/**
 * InetAddress implementation
 */
/**
 * @param ip
 * @param port
 */
 InetAddress::InetAddress(const string& ip, unsigned short port) {
     memset(&_addr,0,sizeof(_addr));
     _addr.sin_family = AF_INET;
     _addr.sin_addr.s_addr = inet_addr(ip.c_str());
     _addr.sin_port = htons(port);
}

/**
 * @param addr
 */
InetAddress::InetAddress(const struct sockaddr_in& addr)
    :_addr(addr)
{}

InetAddress::~InetAddress() {
}

/**
 * @return string
 */
 struct sockaddr* InetAddress::getInetAddressPtr(){

    return (struct sockaddr*)&_addr;
}

/**
 * @return const string&
 */
const string InetAddress::getIP()const {
    return inet_ntoa(_addr.sin_addr);
}

/**
 * @return unsigned short
 */
unsigned short InetAddress::getPort()const {
    return ntohs(_addr.sin_port);
}
