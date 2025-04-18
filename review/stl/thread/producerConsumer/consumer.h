#pragma once
#include "taskQueue.h"

template<class T>
class Consumer{
public:
    void consume(TaskQueue<T>& taskQue);
    Consumer(){};
    ~Consumer(){};
};

template<class T>
void Consumer<T>::consume(TaskQueue<T>& taskQue){
     int cnt = 20;
     while(cnt--){
         T number =  taskQue.pop();
         cout << "Consumer::consume number = " << number << endl;
         sleep(1);
     }
};



