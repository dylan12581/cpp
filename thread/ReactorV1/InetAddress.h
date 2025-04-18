/**
 * Project C++
 */
#ifndef _INETADDRESS_H
#define _INETADDRESS_H
#include <netinet/in.h>
#include <string>

using std::string;

class InetAddress {
public: 
    struct sockaddr_in _addr;
/**
 * @param ip
 * @param port
 */
InetAddress(const string& ip, unsigned short port);
    
~InetAddress();
    
/**
 * @param addr
 */
InetAddress(const struct sockaddr_in& addr);
    
struct sockaddr* getInetAddressPtr();
    
string getIP();
    
unsigned short getPort();
};

#endif //_INETADDRESS_H
