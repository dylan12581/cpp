/**
 * Project C++
 */
#ifndef _INETADDRESS_H
#define _INETADDRESS_H
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using std::string;


class InetAddress {
public: 
    
/**
 * @param ip
 * @param port
*/
InetAddress(const string& ip, unsigned short port);
InetAddress(const struct sockaddr_in& addr);
    
~InetAddress();
    
const string getIp();
    
unsigned short getPort();
    
struct sockaddr* getInetAddressPtr();
private: 
    struct sockaddr_in _addr;
};

#endif //_INETADDRESS_H
