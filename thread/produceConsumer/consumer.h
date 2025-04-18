/**
 * Project C++
 */


#ifndef _CONSUMER_H
#define _CONSUMER_H
#include <iostream>
class TaskQueue;
class consumer {
public: 
    using goodsType = size_t;
    
/**
 * @param taskQueue
 */
void consume(TaskQueue& taskQueue);
};

#endif //_CONSUMER_H
