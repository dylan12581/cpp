#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

// file2.c
// 下面的代码会导致编译错误，因为 staticGlobalVar 具有文件作用域
// extern int staticGlobalVar; //erroe
extern int GlobalVar;
int main() {
    // 无法访问 staticGlobalVar
    // printf("%d\n", staticGlobalVar); //error
     printf("%d\n", GlobalVar); 
    return 0;
}

