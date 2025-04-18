#include <iostream>
#include <mutex>
#include <thread>

using std::cout;
using std::endl;
using std::mutex;
using std::lock_guard;
using std::thread;



int gCount = 0;
mutex mtx;//初始化互斥锁
void threadFunc()
{
for(int idx = 0; idx < 1000000; ++idx)  {
lock_guard<mutex> autoLock(mtx); 
++gCount;
 }
}
int main(int argc, char *argv[]){
thread th1(threadFunc);
thread th2(threadFunc);
th1.join();
th2.join();
cout << "gCount = " << gCount << endl;
return 0;
}
