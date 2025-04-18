#ifndef _TCP_SERVER_H_
#define _TCP_SERVER_H_
#include "Acceptor.h"
#include "EpollEvent.h"
#include <string>
using  std::string;
class TcpServer
{
public:
    TcpServer(const string& ip,unsigned short port);
    ~TcpServer();
    void start();
    void stop();
    void setAllCallBack(TcpConnectionCallBack&& newCb,TcpConnectionCallBack&& closeCb,TcpConnectionCallBack&& MessageCb);
private:

    Acceptor _acceptor;
    EpollEvent _epollEvent;
};

#endif
