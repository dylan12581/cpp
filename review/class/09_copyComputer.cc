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
    Computer(const Computer& rhs)
        :_brand(new char[strlen(rhs._brand) + 1]())
         ,_price(rhs._price)
    {
        strcpy(_brand,rhs._brand);
        cout << "自定义的拷贝构造函数" << endl;
    }
    ~Computer(){
        cout << "~Computer" << endl;
        display();
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
    Computer pc("apple",4000);
    pc.display();


    Computer pc2 = pc; 
    pc2.display();

    cout << "over" << endl;
}

int main()
{
    test0();
    return 0;
}

