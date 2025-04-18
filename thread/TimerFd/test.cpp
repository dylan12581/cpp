#include "TimerFd.h"
#include <iostream>
#include <thread>
#include <functional>
#include <unistd.h>
using std::endl;
using std::cout;
using std::thread;
using std::bind;

class TaskA
{
public:
    void Process() {
        cout << "this is TaskA" << endl;
    }
};

void test0()
{
    TaskA task;
    TimerFd tfd(bind(&TaskA::Process,task),1,4);

    thread th(bind(&TimerFd::start,&tfd));
    // thread th(bind(&TimerFd::start,tfd));error此处要传文件描述符对象的地址，因为文件描述符不可以拷贝

    sleep(30);
    tfd.stop();
    th.join();
}

int main()
{
    test0();
    return 0;
}

