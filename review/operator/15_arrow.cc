#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Data{
public:
    Data(int data = 10)
        :_data(data)
    {cout << "Data(int)" << endl;}
    ~Data(){cout << "~Data(int)" << endl;}
    int getData(){
        return _data;
    }
private:
    int _data;
};

class MiddleLayer{
public:
    MiddleLayer(Data* p)
        :_pdata(p){
            cout << "MiddleLayer(Data*)" << endl;
        }
    ~MiddleLayer(){
        cout << "~MiddleLayer()" << endl;
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
    Data* _pdata;
};

class ThirdLayer{
public:
    ThirdLayer(MiddleLayer* pml)
        :_pml(pml){
            cout << "ThirdLayer(MiddleLayer*)" << endl;
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

    //MiddleLayer& operator*(){
    //    return *_pml;
    //}
    
    //一步到位解引用
    Data& operator*(){
        return *(*_pml);
    }
private:
    MiddleLayer* _pml;
};

void test0(){
    Data* pdata = new Data();
    cout << pdata->getData() << endl;
    delete pdata;
    pdata = nullptr;
    MiddleLayer ml(new Data());
    cout << ml->getData() << endl;
    cout << ml.operator->()->getData() << endl;
    cout << (*ml).getData() << endl;
    ml.operator*().getData();
}
void test1(){
    Data* pdata = new Data();
    MiddleLayer* pml = new MiddleLayer(pdata);
    ThirdLayer tl(pml);
    // ThirdLayer --> MiddleLayer -- > Data
    cout << tl.operator->().operator->()->getData() << endl;
    // ThirdLayer --> MiddleLayer
    cout << tl.operator->()->getData() << endl;
    // ThirdLayer 
    cout << tl->getData() << endl;

    cout << endl;
    //cout << (*(*tl)).getData() << endl;
    //cout << (tl.operator*().operator*()).getData() << endl;
    cout << (*tl).getData() << endl;
    cout << tl.operator*().getData() << endl;



}

int main()
{
    test1();
    return 0;
}

