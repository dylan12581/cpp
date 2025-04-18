#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(int base)
    : _base(base)
    {}

    friend
    int operator+(const Base & lhs,const Base & rhs);
private:
    int _base;
};

int operator+(const Base & lhs,const Base & rhs){
    return rhs._base - lhs._base;
}


void test0(){
    int i=2;
    int j=7;

    Base x(i);
    Base y(j);
    cout << (x + y == j - i) << endl;
    cout << (operator+(x,y) == (j - i)) << endl;
}

int main(void){
    test0();
    return 0;
}



