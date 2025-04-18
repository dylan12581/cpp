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
    bool operator==(const Base & lhs,int x);
    friend
    Base operator+(const Base & lhs,const Base & rhs);
private:
    int _base;
};

Base operator+(const Base & lhs,const Base & rhs){
    return Base(rhs._base - lhs._base);
}

bool operator==(const Base & lhs,int x){
    return lhs._base == x;
}

void test0(){
    int i=2;
    int j=7;

    Base x(i);
    Base y(j);
    cout << (x + y == j - i) << endl;
    cout << operator==(operator+(x,y),(j - i)) << endl;
}

int main(void){
    test0();
    return 0;
}



