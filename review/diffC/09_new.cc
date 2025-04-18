#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{
public:

private:

};

void test0()
{
    int *p = new int();
    cout << *p << endl;
    delete p;

    int *p2 = new int(1);
    cout << *p2 << endl;
    delete p2;
    char* p3 = new char[5]{"hell"};
    cout << p3 << endl;
}
void test1(){
    int* p = new int[10]();
    for(int i = 0;i < 10;++i){
        p[i] = i;
        cout << p[i] << endl;
    }
}

void test2(){
    const char* pstr = "hello world!";
    /* pstr[0] = 'j'; */
    cout << strlen(pstr) << endl;
    cout << sizeof(pstr) << endl;

    char* p = new char[strlen(pstr) + 1]();
    strcpy(p,pstr);
    for(size_t idx = 0;idx < strlen(pstr) + 1;++idx){
        cout << p[idx] << " ";
    }
    cout << endl;
    delete []p;
}
void test3(){

    int *p = new int[10]{1,2,3,4,5};
    for(int i = 0;i < 10;++i){
        cout << p[i] << endl;
    }
    delete  []p;
    p = nullptr;
    char* pstr = new char[6]{'h','e','l','l','o',0};
    cout << pstr << endl;
    delete  []pstr;
    pstr = nullptr;
    
    const char* pstr2 = "world";
    cout << sizeof(pstr2) << endl;
    cout << strlen(pstr2) << endl;
    char* p2 = new char[strlen(pstr2) + 1]();
    strcpy(p2,pstr2);
    cout << p2 << endl;
    delete []p2;
    p2 = nullptr;

}

int main()
{
    test0();
    return 0;
}

