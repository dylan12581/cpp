#pragma once
#include "taskQueue.h"

template<class T>
class Producer{
public:

    Producer(){};
    ~Producer(){};
    void produce(TaskQueue<T>& TaskQueue);

};

template <class T>
void Producer<T>::produce(TaskQueue<T>& taskQueue){

    srand(clock());//种随机种子
    int cnt = 20;
    while(cnt--){
        int number = rand() % 100;//产生随机数
        taskQueue.push(number);
        cout << "Producer::produce number = " << number << endl;
        sleep(1);
    }
}

