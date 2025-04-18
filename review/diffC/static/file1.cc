#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

// file1.c
#include <stdio.h>

// 定义静态全局变量
static int staticGlobalVar = 10;
int GlobalVar = 10;

void printStaticGlobalVar() {
    printf("Static global variable: %d\n", staticGlobalVar);
}


