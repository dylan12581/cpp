#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
    static Computer * getInstance(){
        if(nullptr == _pInstance){
            _pInstance = new Computer("huawei",8000);
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

    void init(const char * brand,double price){
        release();
        _brand = new char[strlen(brand) + 1]();
        strcpy(_brand,brand);
        _price = price;
    }
    
   
    void print() 
    {
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }

private:
    Computer(const char * brand,double price)
    : _brand(new char[strlen(brand) + 1]())
    , _price(price)
    {
        cout << "Computer(const char *,double)" << endl;
        strcpy(_brand,brand);
    }
    
    ~Computer(){
        cout << "~Computer()" << endl;
        release();
    }
    
    void release(){
        if(_brand){
            delete [] _brand;
            _brand = nullptr;
        }
    }

    Computer(const Computer & rhs) = delete;
    Computer & operator=(const Computer & rhs) = delete;
private:
    char * _brand;
    double _price;
    static Computer * _pInstance;
};
Computer * Computer::_pInstance = nullptr;


void test0(){
    Computer::getInstance()->init("xiaomi",6000);
    Computer::getInstance()->print();
    Computer::getInstance()->init("apple",18000);
    Computer::getInstance()->print();
    Computer::destroy();
}

int main(void){
    test0();
    return 0;
}


