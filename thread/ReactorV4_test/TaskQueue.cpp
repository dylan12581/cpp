/**
 * Project C++
 */
#include "TaskQueue.h"
#include <thread>
#include <iostream>
using std::unique_lock;
using std::cout;
using std::endl;

/**
 * TaskQueue implementation
 */


/**
 * @param capacity
 */
TaskQueue::TaskQueue(size_t capacity)
    :_capacity(capacity)
     ,_flag(true)
{}

TaskQueue::~TaskQueue() {}

bool TaskQueue::isEmpty(){
    return _que.size() == 0;
}
bool TaskQueue::isFull(){
    return _que.size() == _capacity;
}

void TaskQueue:: wakeUp(){
    _flag = false;
    _notEmpty.notify_all();
}

/**
 * @param ptask
 * @return void
 */
void TaskQueue::push(elemType&& ptask) {
    unique_lock<mutex> ul(_mutex);
    while(isFull()){
        _notFull.wait(ul);
    }
    _que.push(std::move(ptask));
    _notEmpty.notify_all();
}

/**
 * @return elemType
 */
elemType TaskQueue::pop() {
    unique_lock<mutex>  ul(_mutex);
    while(isEmpty() && _flag){
        _notEmpty.wait(ul);
    }
    if(_flag){
        elemType tmp = _que.front();
        _que.pop();
        _notFull.notify_all();
        return tmp;
    }else{
        cout << "no task" << endl;
        return nullptr;
    }
}
