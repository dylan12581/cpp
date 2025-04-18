#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Computer{
public:
    Computer(const char * brand,double price)
    : _brand(new char[strlen(brand) + 1]())
    , _price(price)
    {
        _totalPrice += _price;
        strcpy(_brand,brand);
        cout << "Computer(const char *,double)" << endl;
    }
    Computer(const Computer & rhs)
    : _brand(new char[strlen(rhs._brand) + 1]())
    , _price(rhs._price)
    {
        _totalPrice += _price;
        strcpy(_brand,rhs._brand);
        cout << "拷贝构造函数" << endl;
    }
    Computer & operator=(const Computer & rhs){
        cout << "赋值运算符函数" << endl;
        if(this != &rhs){//1.判断自赋值的情况
            _totalPrice -= _price;
            delete [] _brand;//2.回收左操作数管理的堆空间
            _brand = new char[strlen(rhs._brand) + 1]();
            strcpy(_brand,rhs._brand);//3.深拷贝
            _price = rhs._price;//对其他的数据成员完成赋值
            _totalPrice += _price;
        }
        return *this;//4.返回本对象
    }

     ~Computer(){
        cout << "~Computer()" << endl;
        if(_brand){
            _totalPrice -= _price;
            delete [] _brand;
            _brand = nullptr;
        }
    }
    void print()const{
        //_price = 0;
        cout << "brand:" << this->_brand << endl;
        cout << "price:" << this->_price << endl;
        //如下可以访问
        cout << "totalPrice:" << _totalPrice << endl; 
    }
    static void printTotalPrice(){
        cout << "totalPrice:" << _totalPrice << endl;
        //cout << _price << endl;//error
    }

private:
    char * _brand;
    double _price;
    static double _totalPrice;
};
double Computer::_totalPrice = 0;

void test0(){
    cout << sizeof(Computer) << endl;
    Computer pc("apple",2000);
    Computer pc2("xiaomi",3000);
    Computer pc3("dell",4000);
    Computer pc4 = pc3;
    pc3 = pc;
    pc.printTotalPrice();
    Computer::printTotalPrice();
    pc.print();
}

int main(){
    test0();
    cout << "over" << endl;
    Computer::printTotalPrice();
    return 0;
}

