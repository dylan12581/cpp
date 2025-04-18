#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Base{
public:
    Base(int x)
    :_num(x){}
    friend int operator+(const Base & lhs,const Base & rhs);
private:
    int _num;
};
     int operator+(const Base & lhs,const Base & rhs){
        return -(lhs._num  - rhs._num);
     }

void test0()
{
    int i = 2;
    int j = 7;
    Base x(i);
    Base y(j);
    cout << (x + y == j - i) << endl;
}

int main()
{
    test0();
    return 0;
}

