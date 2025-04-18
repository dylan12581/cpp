#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

static int num = 100;

namespace {
int num = 0;

void print(){
    cout << "printf()" << endl;
}
};



