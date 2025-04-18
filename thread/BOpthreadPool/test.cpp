#include "ThreadPool.h"
#include <time.h>
#include <iostream>
#include <memory>
#include <algorithm>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::bind;

class TaskA
{
public:
     void process(){
        srand(clock());
        int num = rand()%10;
        cout << "num = " << num <<  endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
};

void test0()
{

    unique_ptr<TaskA> up(new TaskA());
    ThreadPool tp(3,10);
    tp.start();

    //TaskA taskA;
    for(size_t idx = 0;idx < 20 ; ++idx){
        tp.pushTask(bind(&TaskA::process,up.get()));
        cout << "main is pushing" << endl;
    }
    cout << "before stop" << endl;

    tp.stop();
}

int main()
{
    test0();
    return 0;
}

