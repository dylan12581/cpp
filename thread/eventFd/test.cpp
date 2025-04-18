#include "eventFd.h"
#include <unistd.h>
#include <iostream>
#include <functional>
#include <thread>

using std::cout;
using std::endl;
using std::bind;
using std::thread;

class MyTask{
public:
    void process(){
        cout << "MyTask is running" << endl;
    }
};

void test(){
    MyTask task;
    EventFd efd(bind(&MyTask::process, &task));
    /* efd.start(); */
    //A线程就是子线程，子线程中要执行read
    thread th(bind(&EventFd::start, &efd));//线程入口函数该怎么写呢

    int cnt = 10;
    while(cnt--){
        efd.wakeup();//B线程,主线程
        sleep(1);
    }

    efd.stop();
    th.join();
}

int main(int argc, char *argv[]){

    test();
    return 0;
}

