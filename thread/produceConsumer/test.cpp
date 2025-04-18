#include "TaskQueue.h"
#include "producer.h"
#include "consumer.h"

#include <thread>

using std::thread;
using goodsType = size_t;
using std::cout;
using std::endl;
#include <time.h>
#include <unistd.h>

void consume(TaskQueue& taskQueue) {

    int cnt = 20;
    while(--cnt){
         goodsType tmp =  taskQueue.pop();
         cout <<"consume:"<< tmp << endl;
    } 
 
 }
 void produce(TaskQueue& taskQueue) {
    int cnt = 20;
    srand(clock());
    
    while(--cnt){
        size_t number = rand()%100;
        taskQueue.push(number);
        cout << "produce:" << number << endl;
        sleep(1);
    }
}
#if 0
void test0()
{
    TaskQueue tq(10);

    producer pd;
    consumer cs;

    thread th1(&producer::produce,&pd,std::ref(tq));
    thread th2(&consumer::consume,&cs,std::ref(tq));

    th1.join();
    th2.join();
}
#endif
#if 1
void test0()
{
    TaskQueue tq(10);

    

    thread th1(produce,std::ref(tq));
    thread th2(consume,std::ref(tq));

    th1.join();
    th2.join();
}
#endif
int main()
{
    test0();
    return 0;
}

