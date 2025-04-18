#include "Thread.h"
#include <unistd.h>
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::bind;

class MyTask
{
public:
    void process(int x) 
    {
        //...实现具体的逻辑
        while(1)
        {
            cout << "MyTask is running!!!" << endl;
            sleep(x);
        }
    }
};

void func(int x) 
{
    //...实现具体的逻辑
    while(1)
    {
        cout << "func is running!!!" << endl;
        sleep(x);
    }
}

void test()
{
    MyTask task;//栈对象
    function<void()> f = bind(&MyTask::process, &task, 1);
    Thread mth(std::move(f));
    /* Thread mth(bind(&MyTask::process, &task, 1)); */
    mth.start();
    mth.stop();
}

void test2()
{
    MyTask task;
    unique_ptr<Thread> 
        up(new Thread(std::bind(&MyTask::process, &task, 1))) ;//堆对象
    up->start();
    up->stop();
}

void test3()
{
    unique_ptr<Thread> 
        up(new Thread(std::bind(&func, 1))) ;//堆对象
    up->start();
    up->stop();

}

int main(int argc, char *argv[])
{
    cout << "test3" << endl;
    test3();
    return 0;
}

