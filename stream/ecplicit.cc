#include <iostream>

class Box {
public:
    // 单参数构造函数，没有explicit
    Box(int size) : size(size) {}
    
    int getSize() const {
        return size;
    }

private:
    int size;
};

void printBoxSize(Box box) {
    std::cout << "Box size: " << box.getSize() << std::endl;
}

int main() {
    Box b1 = 10;  // 隐式转换，从int到Box
    printBoxSize(20);  // 隐式转换，从int到Box

    return 0;
}

