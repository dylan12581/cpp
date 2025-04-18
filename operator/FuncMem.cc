#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Fun{
public:
    void operator()(){
        ++_count;
        cout << "hello" << endl;
    }
    int operator()(int x){
        ++_count;
        return x;
    }
    double operator()(double x,double y){
        return x + y;
    }
    int getCount(){
      return _count;  
    }

private:
    int _count = 0;
};

void test0()
{
    Fun fun;
    fun();
    cout << fun(1) << endl;
    cout << fun(2.2,2.2) << endl;
    cout << fun.getCount() << endl;
}

int main()
{
    test0();
    return 0;
}

