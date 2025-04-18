/**
 * Project C++
 */


#include "InetAddress.h"

/**
 * InetAddress implementation
 */


/**
 * @param ip
 * @param port
 */
InetAddress::InetAddress(const string& ip, unsigned short port) {
        _addr.sin_family = AF_INET;
        _addr.sin_addr.s_addr = inet_addr(ip.c_str());
        _addr.sin_port = htons(port);
}
InetAddress::InetAddress(const struct sockaddr_in& addr)
    :_addr(addr)
{}
InetAddress::~InetAddress() {}
/**
 * @return const string
 */
const string InetAddress::getIp() {
        return inet_ntoa(_addr.sin_addr);
}

/**
 * @return unsigned short
 */
unsigned short InetAddress::getPort() {
    return ntohs(_addr.sin_port);
}

/**
 * @return struct sockaddr*
 */
struct sockaddr* InetAddress::getInetAddressPtr() {
    return (struct sockaddr*)&_addr;
}
