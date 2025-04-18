#include <iostream>
#include <mutex>
#include <thread>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;

class MutexLock{
public:
    MutexLock()
        :_mutex(){}
    void lock(){
        _mutex.lock();
    }
    void tryLock(){
        _mutex.try_lock();
    }
    void unlock(){
        _mutex.unlock();
    }
    ~MutexLock(){};
private:
    mutex _mutex;
};

class MutexLockGuard{
    MutexLockGuard(mutex& mt)//注意此处是引用
        :_pmutex(&mt){
            _pmutex->lock();
        }
    ~MutexLockGuard(){
        _pmutex->unlock();
    }
private:
    mutex* _pmutex;
};

void test0()
{
    cout << " " << endl;
}

int main()
{
    test0();
    return 0;
}

