/**
 * Project C++
 */
#include "MyTask.h"

/**
 * MyTask implementation
 */
/**
 * @param conn
 * @param msg
 */
MyTask::MyTask(TcpConnectionPtr conn, const string& msg) {
}
MyTask::~MyTask() {

}

/**
 * @return void
 */
void MyTask::process() {
    for(auto& ele:_msg){
        ele = toupper(ele);
    }
    // todo
    _conn->sendInLoop(_msg);
}
