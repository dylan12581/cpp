#include "taskQueue.h"

void taskQueue::push(ElemType ptask){
    unique_lock<mutex> ul(_mutex);
    while(full()){
        _notFull.wait(ul);
    }
    _que.push(ptask);
    _notEmpty.notify_one();
};

taskQueue::ElemType taskQueue::pop(){
    unique_lock<mutex> ul(_mutex);
    while(empty()&&_flag){
        _notEmpty.wait(ul);
    }
    if(_flag){
        ElemType tmp = _que.front();
        _que.pop();
        _notFull.notify_one();
        return tmp;
    }else{
        return nullptr;
    }
};

bool taskQueue::full(){
    return _que.size() == _capacity;
};

bool taskQueue::empty(){
    return _que.size() == 0;
}

void taskQueue::wakeup(){
    _flag = false;
    _notEmpty.notify_all();
}


