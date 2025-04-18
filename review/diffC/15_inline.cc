#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

#define MAX(x,y) (   ((x) > (y)) ? (x) : (y) )         
#define MULTIPLY(x,y) ((x)*(y))

inline int multiply(int x,int y){
    return x * y;
}
inline int max(int a,int b){
    return a > b ? a : b;
}
void test0()
{
    int a = 1,b = 2;

    cout << MAX(a,b) << endl;
    cout << MULTIPLY(a,b) << endl;
    cout << multiply(a + b,a) << endl;
}
void test1(){
    int i = 4,j = 3;
    int result = MAX(i++,j);
    cout << result << endl;
    cout << i << endl;
    int res = max(4,3);
    cout << res << endl;
}
int main()
{
    test1();
    return 0;
}

