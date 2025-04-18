#include <iostream>
#include <string>
#include <thread>
#include <mutex> 

using std::cout;
using std::endl;
using std::mutex;
using std::lock_guard;
using std::thread;

int gCnt;
mutex mtx;

void threadFunc()
{
    for(size_t idx = 0; idx < 200000; ++ idx){
        {
            lock_guard<mutex> lg(mtx);
            ++gCnt;
        }
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

