/**
 * Project C++
 */


#include "TaskQueue.h"
using std::unique_lock;

/**
 * TaskQueue implementation
 */


/**
 * @param QueueSize
 */
TaskQueue::TaskQueue(size_t QueueSize)
    :_QueueSize(QueueSize)
    ,_mutex()
    ,_isEmptyCon()
    ,_isFullCon()
     ,_flag(true)
{}

TaskQueue::~TaskQueue() {
}

/**
 * @param task
 * @return void
 */
void TaskQueue::push(elemType task) {
    while(isFull()){
        unique_lock<mutex> ul(_mutex);
        _isEmptyCon.wait(ul);
    }
    _queue.push(task);
    _isFullCon.notify_one();
}

/**
 * @return elemType
 */
elemType TaskQueue::pop() {
    while(isEmpty() && _flag){
        unique_lock<mutex> ul(_mutex);
        _isFullCon.wait(ul);
    }
    if(!_flag){
        elemType tmp = _queue.back();
        _queue.pop();
        _isFullCon.notify_one();
        return tmp;
    }
    return nullptr;
}

/**
 * @return void
 */
void TaskQueue::wakeUp() {
    _flag = false;
    _isFullCon.notify_all();
}

/**
 * @return bool
 */
bool TaskQueue::isEmpty() {
    return _queue.empty();
}

/**
 * @return bool
 */
bool TaskQueue::isFull() {
    return _queue.size() == _QueueSize;
}
