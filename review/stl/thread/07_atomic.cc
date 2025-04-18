#include <iostream>
#include <string>
#include <atomic>
#include <thread>

using std::cout;
using std::endl;
using std::atomic;
using std::thread;

atomic<int> gCnt(0);

void threadFunc()
{
    for(size_t idx = 0;idx < 10000000;++idx){
            ++gCnt;
    }
}

int main()
{
    thread th1(threadFunc);
    thread th2(threadFunc);

    th1.join();
    th2.join();

    cout << "gCnt = " << gCnt << endl;

    return 0;
}

