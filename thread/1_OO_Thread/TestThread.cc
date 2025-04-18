#include "Thread.h"
#include <unistd.h>
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

class MyThread
: public Thread
{
/* public: */
private:
    void run() override
    {
        //...实现具体的逻辑
        while(1)
        {
            cout << "MyThread is running!!!" << endl;
            sleep(1);
        }
    }
};

void test()
{
    MyThread mth;//栈对象
    mth.start();
    mth.stop();
}

void test2()
{
    unique_ptr<Thread> up(new MyThread()) ;//堆对象
    up->start();
    up->stop();
}
int main(int argc, char *argv[])
{
    test2();
    return 0;
}

