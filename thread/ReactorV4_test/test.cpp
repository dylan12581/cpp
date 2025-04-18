#include "TcpConnection.h"
#include "Acceptor.h"
#include "EpollEvent.h"
#include "Socket.h"
#include "SocketIO.h"
#include "InetAddress.h"
#include "EpollEvent.h"
#include "TcpServer.h"
#include "ThreadPool.h"

#include <unistd.h>
#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::bind;
using std::string;

ThreadPool* gPool;
class MyTask{
public:
    MyTask(string msg,TcpConnectionPtr conn)
        :_msg(msg),_conn(conn)
    {}
    void process(){
        for(auto & ch :_msg){
            ch = toupper(ch);
        }
        _conn->sendInLoop(_msg);
    }
    ~MyTask(){}
private:
    string _msg;
    TcpConnectionPtr _conn;
};

void OnNewConnection(const TcpConnectionPtr& conn){
    cout << conn->toString() << " connected" << endl;
} 
void OnClose(const TcpConnectionPtr& conn){
    cout << conn->toString() << "closed" << endl;
}
//void MessageConn(const TcpConnectionPtr& conn){
void MessageConn(const TcpConnectionPtr& conn,ThreadPool& pool){
    string msg = conn->receive();
    cout << msg << endl;
    MyTask task(msg,conn);
    //gPool->pushTask(bind(&MyTask::process,task));
    pool.pushTask(bind(&MyTask::process,task));
    //it->second->send(msg);
    //conn->send("hello");
}
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

int main(){
    test0();
    return 0;
}

