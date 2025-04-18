#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Data
{
public:
    Data(){
        cout << "Data" << endl;
    }
    ~Data(){
        cout << "~Data" << endl;
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
    {
        cout << "MiddleLayer" << endl;
    }
    ~MiddleLayer(){
        cout << "~MiddleLayer" << endl;
        if(_pdata){
            delete _pdata;
            _pdata = nullptr;
        }
    }
    Data* operator->(){
        return _pdata;
    }
    Data & operator*(){
        return *_pdata;
    }
    //friend class ThirdLayer;
private:
    Data * _pdata;
};
class ThirdLayer{
public:
    ThirdLayer(MiddleLayer* pml)
        :_pml(pml)
    {
        cout << "ThirdLayer(MiddleLayer)" << endl;
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
    // 连续解引用
    //MiddleLayer operator*(){
    //    return *_pml;
    //}
    Data& operator*(){
        return *(*_pml);
        //return (*_pml).operator*();
        //return *(*_pml)._pdata;
    }


private:
    MiddleLayer* _pml;
};

void test0()
{
    Data* pdata = new Data();
    MiddleLayer ml(pdata);
    //delete pdata;
}
void test1(){
    Data* pdata = new Data();
    delete pdata;
    MiddleLayer ml(new Data());
}
void test2(){
    MiddleLayer ml(new Data());
    ml->getData();
    ml.operator->()->getData();// 本质
    (*ml).getData();
    (ml.operator*()).getData();
}
void test3(){
    ThirdLayer tl(new MiddleLayer(new Data()));
    cout << tl->getData() << endl;
    cout << tl.operator->().operator->()->getData() << endl;
    cout << (*tl).getData() << endl;

    // 连续
    //tl.operator*().operator*().getData();
    //(*(*tl)).getData();
}
int main()
{
    test3();
    return 0;
}

