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
        cout << "Computer(const Computer& rhs)" << endl;
    }

    Computer& operator=(const Computer& rhs){
        if(this != &rhs){
            delete  []_brand;
            _brand = new char[strlen(rhs._brand) + 1]();
            strcpy(_brand,rhs._brand);
            _price = rhs._price;
            
        }
        cout << "Computer& operator=(const Computer&)" << endl;
        return *this;
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

void test2(){
    Computer pc("xiaomi",2000);
    Computer pc2("huawei",3000);
    Computer pc3("apple",4000);

    //pc = pc2;
    pc3.operator=(pc2.operator=(pc));
    pc.display();
    pc2.display();
    pc3.display();
}
void test0(){
    int x = 10;
    int y = 10;
    cout << &y << endl;
    cout << &(y = x) << endl;
    cout << endl;

    Computer pc("xiaomi",2000);
    Computer pc2("huawei",3000);
    cout << &pc2 << endl;
    cout << &(pc2 = pc) << endl;
}
void test1(){
    Computer pc("xiaomi",2000);
    pc = Computer("huawei",3000);
    pc.display();
}
void test3(){
    Computer("huawei",3000);
}


int main(){
    test3();
    return 0;
}

