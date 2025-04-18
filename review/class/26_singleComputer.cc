#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{
public:
    static Computer* getInstance(){
        if(_pInstance == nullptr){
            _pInstance = new Computer("xiaomi",2000);
        }
        return _pInstance;
    }
    static void destroy(){
        if(_pInstance){
            cout << ">> delete heap" << endl;
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
    void init(const char* brand,int price){
        release();
        _brand = new char[strlen(brand) + 1]();
        strcpy(_brand,brand);
        _price = price;
        cout << "void init()" << endl;
    }
    void display(){
        cout << "_brand" << _brand << "_price" << _price << endl;
    }

private:
    Computer(const char* brand,int price)
        :_brand(new char[strlen(brand) + 1]())
         ,_price(price)
    {
        strcpy(_brand,brand);
        cout << "Computer(const char* brand,int price)" << endl;
    }
    Computer(const Computer& rhs) = delete;
    Computer& operator=(const Computer& rhs) = delete;
    ~Computer(){
        release();
        cout << "~Computer" << endl;
    }
    void release(){
        if(_brand){
        delete []_brand;
        _brand = nullptr;
        }
    }

private:
    char* _brand;
    int _price;
    static Computer* _pInstance;
};
Computer* Computer::_pInstance = nullptr;

void test0()
{
    Computer::getInstance()->init("apple",3000);
    Computer::getInstance()->display();
    cout << "over" << endl;
    Computer::destroy();
    cout << "over" << endl;
}

int main()
{
    test0();
    return 0;
}

