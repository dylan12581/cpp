#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

extern int num;
namespace {
  extern void print();
}
void test0(){
    ::print();
}
int main(){
    cout << num << endl;
    print();
    return 0;
}



