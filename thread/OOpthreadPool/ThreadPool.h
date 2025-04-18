/**
 * Project C++
 */
#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include "TaskQueue.h"
#include <thread>
#include <vector>

using std::thread;
using std::vector;

class ThreadPool {
public: 
    
/**
 * @param threadNums
 * @param taskQueueSize
 */
 ThreadPool(size_t threadNums, size_t taskQueueSize);
    
    
void start();
    
void stop();
    
/**
 * @param task
 */
void pushTask(Task* ptask);
~ThreadPool();
private: 
    size_t _threadNums;
    vector<thread> _threads;
    size_t _taskQueueSize;
    bool _poolStatus;
    TaskQueue _taskQueue;
    
Task* getTask();
    
void doTask();
};

#endif //_THREADPOOL_H
