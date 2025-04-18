#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{
public:

private:

};
float add(float x,float y){
    return x + y;
}
float add(int x,float y){
    return x + y;
}
float add(float x,int y){
    return x + y;
}

int add(int x,int y){
    return x + y;
}
//void add(int x,int y){
//    return x + y;
//}

void test0(){
    int a = 1,b = 2;
    float x = 1.1,y = 1.2;
    cout << add(a,b) << endl;
    cout << add(x,y) << endl;
    cout << add(a,x) << endl;
    cout << add(x,a) << endl;
}
extern "C" {
    int add1(int x,int y){
        return x + y;
    }
}

int main()
{
    test0();
    return 0;
}

