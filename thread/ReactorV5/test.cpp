#include "EchoServer.h"
#if 0
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
#endif
#if 0
void test0(){
    TcpServer server("192.168.182.128",8080);
    using namespace std::placeholders;
    ThreadPool pool(4,10);
    gPool = &pool;
    pool.start();
    //server.setAllCallBack(std::move(OnNewConnection),std::move(OnClose),std::move(MessageConn));
    TcpConnectionCallBack cb = bind(&MessageConn,_1,pool);
    server.setAllCallBack(std::move(OnNewConnection),std::move(OnClose),std::bind(&MessageConn,_1,pool));
    server.start();
    pool.stop();
}
#endif

void test0(){
    EchoServer server("192.168.182.128",8080,4,10);
    server.start();
    server.stop();
}
int main()
{
    test0();
    return 0;
}

