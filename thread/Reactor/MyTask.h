/**
 * Project C++
 */
#ifndef _MYTASK_H
#define _MYTASK_H

#include "TcpConnection.cpp"
#include <string>
using std::string;

class MyTask {
public: 
    
/**
 * @param conn
 * @param msg
 */
MyTask(TcpConnectionPtr conn, const string& msg);
    
~MyTask();
    
void process();
private: 
    TcpConnectionPtr _conn;
    string _msg;
};

#endif //_MYTASK_H
