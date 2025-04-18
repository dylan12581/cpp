#ifndef _TASKQUEUE_H
#define _TASKQUEUE_H
#include <mutex>
#include <condition_variable>
#include <queue>

using std::queue;
using std::condition_variable;
using std::mutex;

class Task;
using elemType = Task*;
class TaskQueue {
public: 

    /**
     * @param capacity
     */
    TaskQueue(size_t capacity);


    bool isEmpty();
    bool isFull();

    void wakeUp();

    /**
     * @param ptask
     */
    void push(elemType ptask);

    ~TaskQueue();

    elemType pop();
    
private: 
    size_t _capacity;
    queue<elemType> _que;
    mutex _mutex;
    condition_variable _notEmpty;
    condition_variable _notFull;
    bool _flag;
};

#endif //_TASKQUEUE_H
