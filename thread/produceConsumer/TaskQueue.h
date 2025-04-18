/**
 * Project C++
 */
#ifndef _TASKQUEUE_H
#define _TASKQUEUE_H
#include <queue>
#include <mutex>
#include <condition_variable>

using std::mutex;
using std::queue;
using std::condition_variable;

class TaskQueue {
public: 
    using goodsType = size_t;
/**
 * @param goods
 */
void push(goodsType goods);
    
goodsType pop();
    
bool isFull();
    
bool isEmpty();
    
/**
 * @param capacity
 */
TaskQueue(size_t capacity);
    
~TaskQueue();
private: 
    size_t _capacity;
    queue<goodsType> _queue;
    mutex _mutex;
    condition_variable _notFullCond;
    condition_variable _notEmptyCond;
};

#endif //_TASKQUEUE_H
