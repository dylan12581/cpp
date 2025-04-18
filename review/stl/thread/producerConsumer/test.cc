#include "producer.h"
#include "consumer.h"
#include "taskQueue.h"
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

int main(int argc, char *argv[]){

    TaskQueue<int> taskQue(10);

    Producer<int> pr;//生产者对象
    Consumer<int> co;//消费者对象

    thread pro(&Producer<int>::produce,&pr,std::ref(taskQue));
    thread con(&Consumer<int>::consume,&co,std::ref(taskQue));

    pro.join();
    con.join();

    return 0;
}
