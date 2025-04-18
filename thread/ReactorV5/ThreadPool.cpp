/**
 * Project C++
 */
#include "ThreadPool.h"
#include <iostream>

using std::endl;
using std::cout;

/**
 * ThreadPool implementation
 */


/**
 * @param threadNums
 * @param taskQueueSize
 */
ThreadPool::ThreadPool(size_t threadNums, size_t taskQueueSize)
    :_threadNums(threadNums)
    ,_taskQueueSize(taskQueueSize)
    ,_poolStatus(false)
     ,_taskQueue(taskQueueSize)
{
}

ThreadPool::~ThreadPool() {}

/**
 * @return void
 */
void ThreadPool::doTask() {
    while(_poolStatus){
        Task  task = getTask();
        if(task){
            //task->process();
            task();
            cout << "over" << endl;
        }
    }
}
/**
 * @return void
 */
void ThreadPool::start() {
    _poolStatus = true;
    for(size_t idx = 0;idx < _threadNums;++idx){
        //thread th(&ThreadPool::doTask,this);
        //_threads.push_back(std::move(th));
        //_threads.push_back(thread(&ThreadPool::doTask,this));
        _threads.emplace_back(thread(&ThreadPool::doTask,this));
        cout << "empalce_back " << idx + 1 << "threads" << endl;
    }
}

/**
 * @return void
 */
void ThreadPool::stop() {
    //for(size_t idx = 0;idx < _threadNums ;++idx){
    cout << "stop()" << endl;
    while(!_taskQueue.isEmpty()){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    _poolStatus = false;
    cout << "stop2()" << endl;
    //for(size_t idx = 0;idx < _threadNums ;++idx){
    //    cout << "join " << endl;
    //    _threads[idx].join();
    //}
    _taskQueue.wakeUp();
    for(auto &th:_threads){
        th.join();
        cout << "join" << endl;
    }
}

/**
 * @param task
 * @return void
 */
void ThreadPool::pushTask(Task&& ptask) {
    if(ptask){
        _taskQueue.push(std::move(ptask));
    }
}

/**
 * @return Task*
 */
Task ThreadPool::getTask() {
    return _taskQueue.pop();
}

