#include "task.h"
#include "threadPool.h"
#include "taskQueue.h"
#include <my_header.h>

using std::unique_ptr;
using std::cout;
using std::endl;

class MyTask
:public Task{
public:
    void process()override{
        srand(clock());
        int num = rand() % 100;
        std::cout << "myTask number = " << num << std::endl;
    }
};

void test0(){
    unique_ptr<Task> ptask(new MyTask());
    threadPool pool(4,10);
    pool.start();

    int cnt = 20;
    while(cnt--){
        pool.addTask(ptask.get());
        cout << "cnt=" << cnt << endl;
    }
    pool.stop();
}

int main(){
    test0();
    return 0;
}

