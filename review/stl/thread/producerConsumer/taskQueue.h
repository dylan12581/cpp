#pragma once
#include <my_header.h>
#include <iostream>
#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>

using std::cout;
using std::endl;
using std::queue;
using std::mutex;
using std::condition_variable;
using std::unique_lock;

template <class T>
class TaskQueue{
public:
    TaskQueue(size_t capa):
        _capacity(capa){
        };

    ~TaskQueue(){};

    void push(const T& val);

    T pop();

    bool full(){
        return _que.size() == _capacity;
    }

    bool empty(){
        return _que.size() == 0;
    }

private:
    size_t _capacity;
    queue<T> _que;
    mutex _mutex;
    condition_variable _notEmpty;
    condition_variable _notFull;
};

template <class T>
void TaskQueue<T>::push(const T& val){

    unique_lock<mutex> ul(_mutex);
    while(full()){
        _notFull.wait(ul);
    }
    _que.push(val);
    _notEmpty.notify_one();
}

template <class T>
T TaskQueue<T>::pop(){
    unique_lock<mutex> ul(_mutex);
    while(empty()){
        _notEmpty.wait(ul);
    }
    T tmp = _que.front();
    _que.pop();
    _notFull.notify_one();
    return tmp;
}


