#pragma once
#include <my_header.h>
#include <iostream>
#include <string>

using std::string;

class httpServer
{
public:
    httpServer(const string& ip,unsigned short port)
        :_fd(-1),
        _ip(ip)
         ,_port(port)
    {}
    ~httpServer() {
        if(_fd > 0){
            close(_fd);
        }
    }
    void start();
    void recvAndShow();
    //void handleRequest(int netFd);
    string response();

private:
    int _fd;
    string _ip;
    unsigned short _port;

};

