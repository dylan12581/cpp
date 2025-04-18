#pragma once
#include "taskQueue.h"
#include <vector>

using std::vector;

class threadPool
{
public:
    threadPool(size_t threadNum,size_t queSize);
    ~threadPool(){}
    void start();
    void stop();
    void addTask(Task* ptask);
private:
    void doTask();
    Task* getTask();

private:
    size_t _threadNum;
    vector<thread> _threads;
    size_t _queSize;
    bool _isExit;
    taskQueue _taskQueue;
};

