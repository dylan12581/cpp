#include <iostream>
#include <thread>
#include <functional>
#include <string>

using std::cout;
using std::endl;
using std::thread;
using std::function;
using std::bind;
using std::string;

// 传递函数名
void func()
{
    cout << "void func()" << endl;
}

void func1(int i)
{
    cout << "void func()" << endl;
}

void test0(){
    thread th1(func);
}

// 传递函数指针
void test1(){
    void (*pFunc)() = &func;
    void (*pFunc1)() = func;
    thread th1(pFunc);
    thread th2(pFunc1);
}
// 传递函数引用
void test2(){
    void (&pFunc)() = func;
    thread th1(pFunc);
}
//3.
class Example{
public:
    void operator()(int x){
        cout << "void operator()()" << endl;
        cout << "x="<< x <<endl;
    }
};
void test3(){
    Example ex;
    thread th1(ex,10);
}
void test4(){
    int a = 10;
    thread th1([&a](){
               a = 100;
               cout << "a=" << a << endl;
               });
}
void test5(){
    function<void()> f = bind(&func);
    thread th1(f);
}
void func2(int x){
    cout << "x" << x << endl;
}
void test5_2(){
    using namespace std::placeholders;
    //thread th1(bind(&func2,_1),2);
    thread th1(bind(&func2,2));
    th1.join();
}
// join
void test6(){
    cout << "i am main thread" << endl;
    thread th1(func);
    th1.join();

}
// detach
void threadFunc(){
    cout << "I'm child thread 1" << endl;
    cout << "I'm child thread 2" << endl; 
    cout << "I'm child thread 3" << endl; 
    cout << "I'm child thread 4" << endl;
    cout << "I'm child thread 5" << endl;
}
void test7(){
    thread th1(threadFunc);
    th1.detach();
    cout << "I'm main thread 1" << endl;
    cout << "I'm main thread 2" << endl;
    cout << "I'm main thread 3" << endl;
    cout << "I'm main thread 4" << endl;
    cout << "I'm main thread 5" << endl;

}
void threadFunc2(const int&val,char* pstr){
    cout << "I'm child thread 1" << endl;
    printf("&val = %p\n",&val);
    printf("pstr=%p\n",pstr);
}
void test8(){
    // 传递局部变量
    int num = 8;
    char str[] = "hello";
    printf("num = %p\n",&num);
    printf("str=%p\n",str);

    thread th1(threadFunc2,num,str);
    //thread th2([&num,&str](){
    //           printf("th2num = %p\n",&num);
    //           printf("th2str=%p\n",str);
    //           });
    //th1.join();
    th1.detach();
    cout << "i am main thread" << endl;
}
void threadFunc3(int val,const string & s){
    cout << "i am child" << endl;
    printf("&val = %p\n",&val);
    printf("s.c_str() = %p\n",s.c_str());
    printf("s.c_str() = %s\n",s.c_str());
}

// int main()
// {
//     int num  = 10;
//     char str[] = "hello";
//     printf("num = %p\n",&num);
//     printf("str=%p\n",str);

//     thread th1(threadFunc3,num,str);// const string& s = string(str);
//     th1.detach();
//     cout << "i am main" << endl;
//     return 0;
// }
int main(){
    test5_2();
    return 0;
}
