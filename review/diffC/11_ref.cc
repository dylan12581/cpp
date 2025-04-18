#include <iostream>
#include <string.h>

using std::cout;
using std::endl;


int& func(){
    int * p = new int(1);
    return *p;
}
void test0()
{
    int& ref = func();
    cout << "ref = " << ref << endl;
}
int & func2()
{
	int number = 1;
    return number;// 
}
void test2(){
    int& ref = func2();
    cout << ref << endl;
}
int main()
{
    test2();
    return 0;
}

