#include <unistd.h>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

void test0(){
    for(int idx = 0; idx < 1030; ++idx){
        cout << 'a';
    }
    cout.flush();
    sleep(3);
}

void test1(){
    for(int idx = 0; idx < 1030; ++idx){
        cerr << 'a';
    }
    sleep(3);
}

int main(void){
    test0();
    return 0;
}
