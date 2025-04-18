#include "ThreadPool.h"
#include "Task.h"
#include <time.h>
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

class TaskA
:public Task
{
public:
    virtual void process() override{
        srand(clock());
        int num = rand()%10;
        cout << "num = " << num <<  endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
};

void test0()
{

    unique_ptr<Task> up(new TaskA());
    ThreadPool tp(3,10);
    tp.start();

    //TaskA taskA;
    for(size_t idx = 0;idx < 20 ; ++idx){
        tp.pushTask(up.get());
        cout << "main is pushing" << endl;
    }
    cout << "before stop" << endl;

    tp.stop();
}

int main(){

    test0();
    return 0;
}

