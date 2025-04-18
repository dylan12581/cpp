#include "ThreadPool.h"
/**
 * @param threadNums
 * @param queueSize
 */
ThreadPool::ThreadPool(size_t threadNums, size_t queueSize) 
    :_threadNums(threadNums)
    ,_taskQueue(queueSize)
{}

ThreadPool::~ThreadPool() {
}

/**
 * @return void
 */
void ThreadPool::doWork() {
    while(_poolStatus){
    elemType task = getTask();
    task();
    }
}

/**
 * @param task
 * @return void
 */
void ThreadPool::addTask(elemType task) {
        _taskQueue.push(task);
}

/**
 * @return void
 */
void ThreadPool::start() {
    for(size_t i = 0;i < _threads.size();++i){
        thread th(&ThreadPool::doWork);
    }
}

/**
 * @return void
 */
void ThreadPool::stop() {
    while(!_taskQueue.isEmpty()){
        // 睡1s
    }
    _poolStatus = false;
    _taskQueue.wakeUp();
    for(size_t i = 0;i < _threadNums;++i){
        _threads[i].join();
    }
}

/**
 * @return ElemType
 */
elemType ThreadPool::getTask() {
    return _taskQueue.pop();
}
