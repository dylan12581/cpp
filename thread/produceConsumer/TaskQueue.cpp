/**
 * Project C++
 */
#include "TaskQueue.h"
/**
 * TaskQueue implementation
 */
using std::unique_lock;
/**
 * @param goods
 * @return void
 */
void TaskQueue::push(goodsType goods) {

    unique_lock<mutex> ul(_mutex);
    while(isFull()){
        //_notFullCond.wait(unique_lock<mutex>(_mutex));//error只能传递左值
        _notFullCond.wait(ul);
    }
        _queue.push(goods);
        _notEmptyCond.notify_one();
}

/**
 * @return goodsType
 */
TaskQueue::goodsType TaskQueue::pop() {
    unique_lock<mutex> ul(_mutex); 
    while(isEmpty()){
        _notEmptyCond.wait(ul);
    }
    goodsType front = _queue.front();
    _queue.pop();
    _notFullCond.notify_one();
    return front;
}

/**
 * @return bool
 */
bool TaskQueue::isFull() {
    return _queue.size() == _capacity;
}

/**
 * @return bool
 */
bool TaskQueue::isEmpty() {
    return _queue.size() == 0;
}

/**
 * @param capacity
 */
TaskQueue::TaskQueue(size_t capacity)
    :_capacity(capacity)
     ,_queue(queue<goodsType>())
     ,_mutex(mutex())
     ,_notFullCond(condition_variable())
     ,_notEmptyCond(condition_variable())
{}

TaskQueue::~TaskQueue() {}
