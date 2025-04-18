#ifndef  _ECHO_SERVER_H_
#define  _ECHO_SERVER_H_
#include "TcpServer.h"
#include "ThreadPool.h"
#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::bind;

class EchoServer
{
public:
    EchoServer(const string &ip,unsigned short port,int threadNums,int taskQueueSize);
    ~EchoServer();
    void start();
    void stop();
    void OnNewConnection(const TcpConnectionPtr& conn);
    void OnClose(const TcpConnectionPtr& conn);
    void MessageConn(const TcpConnectionPtr& conn);
private:
    TcpServer _server;
    ThreadPool _pool;
};

#endif

