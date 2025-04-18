#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Computer{
public:
    Computer(const char* brand,int price)
        :_brand(new char[strlen(brand) + 1]())
         ,_price(price)
    {
        cout << "Computer(const char* ,int)" << endl;
        strcpy(_brand,brand);
    }
    ~Computer(){
        cout << "~Computer()" << endl;
        if(_brand){
            delete []_brand;
            _brand = nullptr;
        }
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
            delete []_brand;
            _brand = new char[strlen(rhs._brand) + 1]();
            strcpy(_brand,rhs._brand);
            _price = rhs._price;
        }
        return *this;
    }
    void print(){
        cout << _brand << " " << _price << endl;
    }

private:
    char* _brand;
    int _price;

};

template <class T>
class RAII{
public:
    RAII(T* data)
        :_data(data)
    {
        cout << "RAII(T* data)" << endl;
    }
    ~RAII(){
        cout << "~RAII()" << endl;
        if(_data){
            delete _data;
            _data = nullptr;
        }
    }

    RAII(const RAII& lhs) = delete;
    RAII& operator=(const RAII& rhs) = delete;
    
    T* operator->(){
        return _data;
    }
    T& operator*(){
        return *_data;
    }
    T* get()const{
        return _data;
    }
    void reset(T* data){
        if(_data){
            delete _data;
            _data = nullptr;
        }
        _data = data;
    }

private:
    T* _data;
};
void test0()
{
    RAII<Computer> ra(new Computer("xiaomi",9000));
    ra->print();
    (*ra).print();
    cout << ra.get() << endl;

    cout << endl;
    ra.reset(new Computer("lenovo",10000));
    ra->print();
    (*ra).print();
    cout << ra.get() << endl;

}

int main()
{
    test0();
    return 0;
}

