#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{
public:

private:

};

void test0()
{
    int num  = 1;
    int num2 = 2;

     /* int* p = &num; */// error
    const int * p = &num;
    /* *p = 2; error */
    p = &num2;
    cout << " " << endl;
}
void test1(){
    int arr[5] = {1,2,3,4,5};
    cout << arr << endl;
    cout << arr + 1 << endl;
    cout << &arr << endl;
    cout << &arr + 1 << endl;
    int (*p)[5] = &arr;
    for(int i = 0;i < 5;++i){
        cout << (*p)[i] << endl;
    }

}

int main()
{
    test1();
    return 0;
}

