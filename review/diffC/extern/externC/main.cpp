#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

#include <iostream>

// 使用 extern "C" 声明 C 语言函数
extern "C" {
    void printMessage();
}
//void printMessage();// error编译器会有名字改编

int main() {
    // 调用 C 语言函数
    printMessage();
    return 0;
}



