#include <iostream>
#include <string>
#include <thread>
#include <functional>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::thread;
using std::function;
using std::bind;

typedef void(*pFunc)(int);

typedef void(& pFunc1)(int);
void threadFunc(int x){
    cout << "x=" << x << endl;
    cout << "child thread id = " << std::this_thread::get_id() << endl;
}
class Example{
public:
    void operator()(int x){
        cout << "x=" << x << endl;
        cout << "child thread id = " << std::this_thread::get_id() << endl;
    }
};


int main(){
    cout << "main thread id = " << std::this_thread::get_id() << endl;
    //thread thl([](int x){
    //    cout << "x=" << x << endl;
    //    cout << "child thread id = " << std::this_thread::get_id() << endl;
    //           },5);

    //pFunc f = &threadFunc;
    //pFunc1 f1 = threadFunc;
    //thread th(threadFunc,1);// 普通函数
    //thread th(f,1);//函数指针
    //thread th1(f1,1);//函数引用
    //Example ex;
    //thread the(ex,4);// 函数对象
    
    //function<void(int)> f = [](int x){
    //   cout << "x=" << x << endl;
    //   cout << "child thread id = " << std::this_thread::get_id() << endl;
    //          };
    //thread thf(f,1);

    using std::placeholders::_1;
    thread thb(std::bind(threadFunc,_1),3);
    cout << "child thread id = " << thb.get_id() << endl;
    thb.join();
    //the.join();
    //th.join();
    //th1.join();
    return 0;
}

