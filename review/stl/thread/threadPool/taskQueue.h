#pragma once
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

using std::mutex; 
using std::thread;
using std::queue;
using std::condition_variable;
using std::unique_lock;

class Task;
class taskQueue{
public:
    using ElemType = Task*;
    taskQueue(size_t capacity)
        :_capacity(capacity),_flag(true){}
    ~taskQueue() {}
    void push(ElemType ptask);
    ElemType pop();
    bool full();
    bool empty();
    void wakeup();

private:
    size_t _capacity;
    queue<ElemType> _que;
    mutex _mutex;
    condition_variable _notFull;
    condition_variable _notEmpty;
    bool _flag;

};

