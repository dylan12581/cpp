#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{
public:

private:

};

//C风格的强制转换
void test0()
{
    int num = 10;
    const int * p = &num;
    int* p2 = (int*)p;// 将const int* 转换为int*
    *p2 = 20;
    cout << num << endl;
}
void test1(){
    int num = 10;
    float fNum = 0;
    //fNum = (float)num;//C风格
    fNum = static_cast<float>(num);
    cout << fNum << endl;

    void* p = malloc(sizeof(int));
    int* pInt = static_cast<int*>(p);
    *pInt = 1; 
    cout << *pInt << endl;
    free(p);
}
void test2(){

    const int num = 1;
    //int a = const_cast<int> num; error
    const int* p = &num;
    int* pi = const_cast<int*>(p);
    *pi = 0;
    cout << *pi << endl;
    cout << num << endl; 
    cout << pi << endl;
    cout << &num << endl;
}

int main()
{
    test2();
    return 0;
}

