#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <vector>
#include <thread>

using std::cout;
using std::endl;
using std::vector;
using std::thread;

class MutexLock{
public:
    MutexLock(){
        int ret = pthread_mutex_init(&_mutex,nullptr);
        if(ret != 0){
            throw "failed in init MutexLock";
        }
    }
    ~MutexLock(){
    }
    int destroy(){
        return pthread_mutex_destroy(&_mutex);
    }
    int lock(){
        return pthread_mutex_lock(&_mutex);
    }
    int unlock(){
        return  pthread_mutex_unlock(&_mutex);
    }
    int tryLock(){
        return  pthread_mutex_trylock(&_mutex);
    }
    pthread_mutex_t& getMutexLock(){// 返回裸锁
        return _mutex;
    }

private:
    pthread_mutex_t _mutex;
    MutexLock(const MutexLock&) = delete;
    MutexLock& operator=(const MutexLock&) = delete;
};

class MutexLockGuard{
public:
    MutexLockGuard(MutexLock& mutex)
        :_mutex(mutex)
    {
        _mutex.lock();

    }
    ~MutexLockGuard(){
        _mutex.unlock();
        _mutex.destroy();
    }
private:
    MutexLock& _mutex;
    MutexLockGuard(const MutexLockGuard&) = delete;
    MutexLockGuard& operator=(const MutexLockGuard&) = delete;
};

class Condition{
public:
    Condition(MutexLock& mutex)
        :_mutex(mutex){
        pthread_cond_init(&_cond,nullptr);
    }
    int wait(){
        return pthread_cond_wait(&_cond,&_mutex.getMutexLock());
    }
    int notify(){
        return pthread_cond_signal(&_cond);
    }
    int notifyAll(){
        return pthread_cond_broadcast(&_cond);
    }
    ~Condition(){
        pthread_cond_destroy(&_cond);
    }
private:
    pthread_cond_t _cond;
    MutexLock& _mutex;
    Condition(const Condition&) = delete;
    Condition& operator=(const Condition&) = delete;
};

int gNum = 0;
MutexLock mutex;
Condition cond(mutex);

void doWork(int i){
    MutexLockGuard ml(mutex);
    while(gNum < 100){
        while(0 == gNum % 5){// 注意while;避免虚假唤醒问题
            cond.wait();
            if(gNum >= 100){
                cout << "worker " << i << " is existing " << endl;
                return;
            }
        }
        ++gNum;
        cout << "worker " << i << " is working gnum is " << gNum << endl;
    }
    cout << "worker " << i << " is existing " << endl;
}

int main(){
    vector<thread> workers;
    for(size_t idx = 0;idx < 5;++idx){
        workers.emplace_back(doWork,idx);// thread不能拷贝，这里是直接构建
                                         // workers.push_back(thread(doWork));//error
    }

    while(gNum < 100){
        {
        MutexLockGuard ml(mutex);
        ++gNum;
        cout << "main thread is working gNum is" << gNum << endl;
        cond.notifyAll();
        }
        sleep(1);
    }

    for(auto& elem:workers){
        elem.join();
    }
    return 0;
}
