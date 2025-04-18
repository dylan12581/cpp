#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

double division(double x,double y){
    if(y == 0){
        throw "division by zero condition!";
    }
    return x / y;
}

void test0()
{
    try{
        cout << division(9,0) << endl;
        cout << division(0,100) << endl;
        cout << division(1,2) << endl;
    }catch(const char*){
        cout << "there exists a problem" << endl;
    }catch(double){
        cout << "double" << endl;
    }
    cout << "over" << endl;
}
void test1(){
    try{
        cout << division(9,0) << endl;
    }catch(const  char*){
        cout << "error:" << "problem" << endl;
    }
}

int main()
{
    
    test1();
    return 0;
}

