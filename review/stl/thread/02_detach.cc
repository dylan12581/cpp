#include <my_header.h>
#include <iostream>
#include <string>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

void threadFunc()
{
    cout << "I'm child thread 1" << endl;
    cout << "I'm child thread 2" << endl;
    cout << "I'm child thread 3" << endl;
    cout << "I'm child thread 4" << endl;
    cout << "I'm child thread 5" << endl;
}
void threadFunc2(const int &value, char *pstr)
{
    cout << "I'm child thread" << endl;
    printf("&value = %p\n", &value);//value的地址与num的地址不一致
    printf("pstr = %p\n", pstr);//与str指向变量的地址一样，如果主线程先执行完，pstr指向为空
}

#if 0
int main()
{
    thread th1(threadFunc);
    th1.detach();
    cout << "I'm main thread 1" << endl;
    cout << "I'm main thread 2" << endl;
    cout << "I'm main thread 3" << endl;
    cout << "I'm main thread 4" << endl;
    cout << "I'm main thread 5" << endl;
    return 0;
}
#endif

int main(void){
    //传递局部(变量)对象作为参数详解
    int num = 10;
    char str[] = "hello";
    printf("&num = %p\n", &num);
    printf("str = %p\n", str);

    thread th1(threadFunc2,num,str);
    th1.detach();
    sleep(1);
    cout << "i am main thread" << endl;

    return 0;
}

