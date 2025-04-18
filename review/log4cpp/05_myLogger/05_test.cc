#include "./05_myLogger.hh"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
    

void test0(){
    myLogger::getInstance()->warn(addPrefix("The log is warn message"));
}

void test1(){
    LogWarn("The log is warn message");
    LogInfo("The log is info message");
    LogDebug("The log is debug message");
    LogError("The log is error message");
}

int main(void){
    test1();
    return 0;
}
