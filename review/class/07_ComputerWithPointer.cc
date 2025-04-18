#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{
public:
    Computer(const char* brand,double price)
    :_brand(new char[strlen(brand) + 1]())
     ,_price(price)
    {
        strcpy(_brand,brand);
    }
    void display(){
         cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }
    ~Computer(){
        cout << "~Computer" << endl;
        if(_brand){
                delete  []_brand;
                _brand = nullptr;
        }
    }
private:
    char* _brand;
    int _price;
};

void test0()
{
    cout << sizeof(Computer) << endl;
    Computer pc("Apple",20);
    pc.display();
    Computer pc2("lenovo",200);
    pc2.display();
    //pc2.~Computer();
    cout << endl;
    cout << sizeof(pc) << endl;
    cout << sizeof(pc2) << endl;
}
void test2(){
    int *p = nullptr;
    cout << p << endl;
    char *pc = nullptr;
    //cout << *pc << endl;
    cout << pc << endl;

    cout << "over" << endl;
}

int main()
{
    test2();
    return 0;
}

