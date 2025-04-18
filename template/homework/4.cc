#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
double add(){
    return 0;
}
template <class T,class ...Args>
double add(T x,Args ...args){
    return x + add(args...);
}


void test0()
{
    cout << add(1,2,3,4,1.1,1.2,1.3) << endl;
}

int main()
{
    test0();
    return 0;
}

