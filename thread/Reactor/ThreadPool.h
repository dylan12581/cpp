/**
 * Project C++
 */


#ifndef _THREADPOOL_H
#define _THREADPOOL_H
#include "TaskQueue.h"
#include <functional>
#include <thread>
#include <vector>
using std::function;
using std::thread;
using std::vector;

using elemType = function<void()>;
class ThreadPool {
public: 
    
/**
 * @param threadNums
 * @param queueSize
 */
ThreadPool(size_t threadNums, size_t queueSize);
    
~ThreadPool();
    
void doWork();
    
/**
 * @param task
 */
void addTask(elemType task);
    
void start();
    
void stop();
private: 
    size_t _threadNums;
    TaskQueue _taskQueue;
    vector<thread> _threads;
    bool _poolStatus;
    
elemType getTask();
};

#endif //_THREADPOOL_H
