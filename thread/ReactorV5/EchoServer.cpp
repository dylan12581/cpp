#include "EchoServer.h"
EchoServer::EchoServer(const string &ip,unsigned short port,int threadNums,int taskQueueSize)
    :_server(ip,port)
     ,_pool(threadNums,taskQueueSize)
{
}
EchoServer::~EchoServer(){};

class MyTask{
public:
    MyTask(string msg,TcpConnectionPtr conn)
        :_msg(msg)
         ,_conn(conn)
    {}
    void process(){
        for(auto & ch :_msg){
            ch = toupper(ch);
            while(1){
                
            }
        }
        cout << "process" <<  _msg << endl;
        _conn->sendInLoop(_msg);
    }
    ~MyTask(){}
private:
string _msg;
TcpConnectionPtr _conn;
};

void EchoServer::OnNewConnection(const TcpConnectionPtr& conn){
    cout << conn->toString() << " connected" << endl;
} 
void EchoServer::OnClose(const TcpConnectionPtr& conn){
    cout << conn->toString() << "closed" << endl;
}
//void MessageConn(const TcpConnectionPtr& conn){
void EchoServer::MessageConn(const TcpConnectionPtr& conn){
    string msg = conn->receive();
    cout << msg << endl;
    MyTask task(msg,conn);
    //gPool->pushTask(bind(&MyTask::process,task));
    _pool.pushTask(bind(&MyTask::process,task));
    //it->second->send(msg);
    //conn->send("hello");
}
void EchoServer::start(){
    _pool.start();
    using namespace std::placeholders;
    _server.setAllCallBack(bind(&EchoServer::OnNewConnection,this,_1),bind(&EchoServer::OnClose,this,_1),bind(&EchoServer::MessageConn,this,_1));
    //function<void(const TcpConnectionPtr)> f = bind(&EchoServer::OnNewConnection,this,_1);
    _server.start();
}

void EchoServer::stop(){
    _pool.stop();
    _server.stop();
}
