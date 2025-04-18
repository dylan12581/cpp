#include "TcpConnection.h"
#include "Acceptor.h"
#include "EpollEvent.h"
#include "Socket.h"
#include "SocketIO.h"
#include "InetAddress.h"
#include "EpollEvent.h"

#include <unistd.h>
#include <iostream>
using std::endl;
using std::cout;
using std::bind;

void OnNewConnection(const TcpConnectionPtr& conn){
    cout << conn->toString() << " connected" << endl;
} 
void OnClose(const TcpConnectionPtr& conn){
    
    cout << conn->toString() << "closed" << endl;
}
void MessageConn(const TcpConnectionPtr& conn){
    string msg = conn->receive();
    cout << msg << endl;
    //it->second->send(msg);
    conn->send("hello");
}
void test0()
{
    Acceptor acceptor("192.168.182.128",8080);
    acceptor.ready();
    EpollEvent epoll(acceptor);
    epoll.setNewConnCb(std::move(OnNewConnection));
    using namespace std::placeholders;
    //epoll.setNewConnCb(std::bind(&OnNewConnection,_1));
    epoll.setCloseConnCb(std::move(OnClose));
    epoll.setMessageConnCb(std::move(MessageConn));
    epoll.loop();
}

int main()
{
    test0();
    return 0;
}

