#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Data
{
public:
    Data(){}
    ~Data(){
        cout << "~Data()" << endl;
    }

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
            cout << "~MiddleLayer()" << endl;
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
class ThirdLayer
{
    public:
    ThirdLayer(MiddleLayer* pml)
    :_pml(pml){
        cout << "ThirdLayer()" << endl;
    }
    ~ThirdLayer(){
        cout << "~ThirdLayer()" << endl;
        if(_pml){
            delete _pml;
            _pml = nullptr;
        }
    }
    MiddleLayer& operator->(){
        return *_pml;
    }

    MiddleLayer& operator*(){
        return *_pml;
    }
    private:
    MiddleLayer* _pml;
};

void test0()
{
    // Data* p = new Data();
    // MiddleLayer ml(p);
    // ThirdLayer  tl(&ml);//error,会发生double free

    // Data* p = new Data();
    // MiddleLayer ml(p);
    // ml->getData();
    // (*ml).getData();

    ThirdLayer tl(new MiddleLayer(new Data()));
    cout << tl->getData() << endl;
    cout << tl.operator->().operator->()->getData() << endl;
    cout << (*(*tl)).getData() << endl;     
}

int main()
{
    test0();
    return 0;
}

