#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{
public:
    void setBrand(const char* brand);
    void setPrice(float price);
    void print();
private:
    char _brand[20];
    float _price;

};
void Computer::setBrand(const char* brand){
        strcpy(_brand,brand);
    }
void Computer::setPrice(float price){
        _price = price;
}
void Computer::print(){
    cout << _brand << endl;
    cout << _price << endl;
}

void test0(){
    Computer pc;
    pc.setBrand("xiaomi");
    pc.setPrice(5000);
    pc.print();
}

int main()
{
    test0();
    return 0;
}

