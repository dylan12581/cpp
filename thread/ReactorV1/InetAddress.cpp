/**
 * Project C++
 */
#include "InetAddress.h"
#include "stdlib.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/**
 * InetAddress implementation
 */
/**
 * @param ip
 * @param port
 */
InetAddress::InetAddress(const string& ip, unsigned short port)
{
    _addr.sin_family = AF_INET;
    _addr.sin_addr.s_addr = inet_addr(ip.c_str());
    _addr.sin_port = htons(port);// host to nets 小端存储转大端存储
}

InetAddress::~InetAddress() {

}

/**
 * @param addr
 */
InetAddress::InetAddress(const struct sockaddr_in& addr)
    :_addr(addr)
{}

/**
 * @return struct sockaddr*
 */
struct sockaddr* InetAddress::getInetAddressPtr() {
    return (struct sockaddr*)&_addr;
}

/**
 * @return string
 */
string InetAddress::getIP() {
    return inet_ntoa(_addr.sin_addr);
}

/**
 * @return string
 */
unsigned short  InetAddress::getPort() {
    return ntohs(_addr.sin_port);
}
