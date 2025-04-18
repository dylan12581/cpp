/**
 * Project C++
 */


#ifndef _TASKQUEUE_H
#define _TASKQUEUE_H
#include <iostream>
#include <functional>
#include <condition_variable>
#include <mutex>
#include <queue>
using std::mutex;
using std::condition_variable;
using std::function;
using std::queue;


using elemType = function<void()>;
class TaskQueue {
public: 
    
/**
 * @param QueueSize
 */
TaskQueue(size_t QueueSize);
    
 ~TaskQueue();
    
/**
 * @param task
 */
void push(elemType task);
    
elemType pop();
bool isEmpty();
    
void wakeUp();
private: 
    size_t _QueueSize;
    mutex _mutex;
    condition_variable _isEmptyCon;
    condition_variable _isFullCon;
    queue<elemType> _queue;
    bool _flag;

    
    
bool isFull();
};

#endif //_TASKQUEUE_H
