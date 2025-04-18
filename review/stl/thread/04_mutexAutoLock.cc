#include <iostream>
#include <mutex>
#include <thread>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;

int gCnt = 0;
mutex mtx;
class MutexLockGuard{
public:
    MutexLockGuard(mutex& mutex)
        :_mutex(mutex){
            _mutex.lock();
        }
    ~MutexLockGuard(){
        _mutex.unlock();
    }
private:
        mutex& _mutex;
};

void threadFunc(){
    for(size_t idx = 0;idx < 1000000;++idx){
        MutexLockGuard autoLock(mtx);
        ++gCnt;
    }
}

int main()
{
    thread th1(threadFunc);
    thread th2(threadFunc);

    th1.join();
    th2.join();

    cout << gCnt << endl;
    return 0;
}

