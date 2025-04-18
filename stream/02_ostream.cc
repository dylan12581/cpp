#include <iostream>
#include <string.h>
#include <unistd.h>

using std::cout;
using std::endl;
using std::cerr;



void test0()
{
    for(int i = 0;i < 1024;i++){
        cout << 'a';
    }
}
void test1()
{
    for(int i = 0;i < 1025;i++){
        cout << 'a';
    }
    
    sleep(3);
}
void test2(){

    for(int i = 0;i < 5;i++){
        cout << 'a';
    }
    cout << endl;
    
    sleep(3);
}
void test3(){
    for(int i = 0;i < 1024;i++)
    {
        cout << 'a';
    }
    sleep(2);
        cout << 'b';
    sleep(2);
}
void test4(){
    cerr << 1;
    cout << 2;
    sleep(1);
    cout.flush();
    sleep(2);
}



int main()
{
    test4();
    return 0;
}

