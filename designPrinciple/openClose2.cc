#include <iostream>
#include <string.h>

using std::cout;
using std::endl;


class Calc{
    public:
    int puls(int x,int y){
        return x + y;
    }
    int minus(int x,int y){
        return x - y;
    }
    int multiply(int x,int y){
        return x * y;
    }
};

void test0(){
    Calc c;
    cout << c.puls(1,2) << endl;
    cout << c.minus(1,2) << endl;
    cout << c.multiply(1,2) << endl;
}
int main()
{
    test0();
    return 0;
}

