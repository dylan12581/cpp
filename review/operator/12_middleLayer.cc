#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Data
{
public:
    Data(){}
    ~Data(){}

    int getData() const{ return _data; }
private:
    int _data = 10;
};

class MiddleLayer
{
public:
    MiddleLayer(Data * p)
    : _pdata(p)
    {}

    ~MiddleLayer(){
        if(_pdata){
            delete _pdata;
            _pdata = nullptr;
        }
    }
    Data* operator->(){
        return _pdata;
    }
    Data& operator*(){
        return *_pdata;
    }
private:
    Data * _pdata;
};

void test0()
{
    MiddleLayer ml(new Data());
    cout << ml->getData() << endl;
    cout << ml.operator->()->getData() << endl;
    cout << ml.operator*().getData() << endl;
    cout << (*ml).getData() << endl;

}

int main()
{
    test0();
    return 0;
}

