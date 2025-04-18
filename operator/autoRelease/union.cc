#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

#include <iostream>

union Data {
    int intValue;
    float floatValue;
    char charValue;
    double doubleValue;
};

int main() {
    Data data;

    data.intValue = 65;
    std::cout << "intValue: " << data.intValue << std::endl;
    std::cout << "charValue: " << data.charValue << std::endl; // 共享内存

    data.floatValue = 3.14f;
    std::cout << "intValue: " << data.intValue << std::endl; // 可能输出不正确
    std::cout << "floatValue: " << data.floatValue << std::endl;

    data.charValue = 'a';
    std::cout << "charValue: " << data.charValue << std::endl; // 共享内存
    std::cout << "intValue: " << data.intValue << std::endl; // 可能输出不正确
    std::cout << "floatValue: " << data.floatValue << std::endl;
    cout << sizeof(Data) << endl;

    return 0;
}


