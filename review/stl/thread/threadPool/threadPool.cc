#include "threadPool.h"
#include "task.h"
#include <functional>
using std::function;
using std::bind;

threadPool::threadPool(size_t threadNum,size_t queSize)
    :_threadNum(threadNum),_threads(),_queSize(queSize),_isExit(false),_taskQueue(_queSize){
}

void threadPool::start(){
        for(size_t idx = 0;idx < _threadNum;++idx){
            _threads.emplace_back(thread(&threadPool::doTask,this));
            //thread th(&threadPool::doTask,this);
            //_threads.push_back(th);
        };
}

void threadPool::stop(){

    //只要任务队列中还有任务，就不应该让主线程急着向下执行去
    //回收子线程，在此处可以添加对应代码控制主线程向下走
    while(!_taskQueue.empty()){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    _taskQueue.wakeup();
    _isExit = true;
    for(auto& thr:_threads){
        thr.join();
    }
}
void threadPool::addTask(Task* ptask){
    if(ptask){
        _taskQueue.push(ptask);
    }
}
void threadPool::doTask(){
    while(!_isExit){
        Task* ptask = getTask();
        if(ptask){
            ptask->process();
        }else{
            std::cout << "nullptr == ptask" << std::endl;
        }
    }
}

Task* threadPool::getTask(){
    return _taskQueue.pop();
}

