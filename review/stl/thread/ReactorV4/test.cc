#include "Acceptor.h"
#include "TcpConnection.h"
#include "EventLoop.h"
#include "ThreadPool.h"
#include <iostream>

using std::cout;
using std::endl;

ThreadPool *gPool = nullptr;

class MyTask{
public:
    MyTask(const string& msg,const TcpConnectionPtr& con)
        :_msg(msg),_con(con){}
    void process(){
        _con->sendInLoop(_msg);
    }

private:
    string _msg;
    TcpConnectionPtr _con;
};
void onNewConnection(const TcpConnectionPtr& con){
    cout << con->toString() << "has connected!!!" << endl;
}
void onMessage(const TcpConnectionPtr& con){
    string msg = con->receive();
    cout << ">>recv msg from client:" << msg << endl;
    MyTask task(msg,con);
    gPool->addTask(std::bind(&MyTask::process,task));
}
void onClose(const TcpConnectionPtr& con){
    cout << con->toString() << "has closed" << endl;
}
void test(){
    ThreadPool pool(4,10);
    pool.start();
    gPool = &pool;
    Acceptor acceptor("127.0.0.1",8080);
    acceptor.ready();
    EventLoop eventLoop(acceptor);
    eventLoop.setNewConnectionCallback(std::move(onNewConnection));
    eventLoop.setMessageCallback(std::move(onMessage));
    eventLoop.setCloseCallback(std::move(onClose));
    eventLoop.loop();
}

int main()
{
    test();
    return 0;
}

