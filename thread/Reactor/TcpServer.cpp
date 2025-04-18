/**
 * Project C++
 */
#include "TcpServer.h"
#include "TcpConnection.h"
#include "MyTask.h"
#include "ThreadPool.h"
#include <iostream>
ThreadPool* gpool;

using std::cout;
using std::endl;
using std::bind;

/**
 * TcpServer implementation
 */
void onNewConn(const TcpConnectionPtr& conn){
   cout << conn->toString() << "has connected..." << endl; 
}
void onMessageCb(const TcpConnectionPtr& conn){
    cout << "onMessageCb" << endl;
    const string msg = conn->reveive();
    cout << msg << endl;
    MyTask task(conn,msg);
    gpool->addTask(bind(&MyTask::process,&task));
}
void onCloseConn(const TcpConnectionPtr& conn){
   cout << conn->toString() << "has closed..." << endl; 
}

/**
 * @param ip
 * @param port
 */
TcpServer::TcpServer(const string& ip, unsigned short port)
    :_acceptor(ip,port)
     ,_epollLoop(&_acceptor)
{}

TcpServer::~TcpServer() {
}

/**
 * @return void
 */
void TcpServer::start() {
    _acceptor.ready();
    _epollLoop.setNewConnCb(std::move(&onNewConn));
    _epollLoop.setMessageCb(std::move(&onMessageCb));
    _epollLoop.setCloseConnCb(std::move(&onCloseConn));
    _epollLoop.loop();
}

/**
 * @return void
 */
void TcpServer::stop() {
    _epollLoop.unloop();
}

void test0()
{
    TcpServer server("192.168.182.128",8080);
    ThreadPool pool(4,20);
    
    server.start();
}

int main()
{
    test0();
    return 0;
}

