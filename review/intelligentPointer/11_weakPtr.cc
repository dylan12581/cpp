
#include <iostream>
#include <string.h>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Father;

class Child{
public:

    shared_ptr<Father> _spFather;
};

class Father{
public:
    weak_ptr<Child> _spChild;
};

void test0()
{
    cout << sizeof(shared_ptr<Child>) << endl;
    cout << sizeof(shared_ptr<Father>) << endl;
    cout << sizeof(shared_ptr<int>) << endl;
    shared_ptr<Father> spFather(new Father());
    shared_ptr<Child> spChild(new Child());
    cout << spFather.use_count() << "\n";
    cout << spChild.use_count() << "\n";
    spFather->_spChild = spChild;
    spChild->_spFather = spFather;
    cout << spFather.use_count() << "\n";
    cout << spChild.use_count() << "\n";
}
void test1(){
    shared_ptr<int> sp(new int(10));
    weak_ptr<int> wp;
    wp = sp;
    cout << sp.use_count() << endl;
    cout << wp.use_count() << endl;
    cout << *sp << endl;
    //cout << *wp << endl;
    shared_ptr<int> sp2 = wp.lock();
    if(sp2){
        cout << "提升成功" << endl;
        cout << *sp2 << endl;
    }else{
        cout << "提升失败，托管的空间已经被销毁" << endl;
    }
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;
    cout << wp.use_count() << endl;
    bool flag = wp.expired();
        if(flag){
        cout << "托管的空间已经被销毁" << endl;
            }else{
        cout << "托管的空间还在" << endl;
        }
}
void test4(){
    int a = 1;
    int& ref = a;
    int&& ref2 = std::move(ref);
    cout << &ref << endl;
    cout << &ref2 << endl;
}


int main()
{
    test4();
    return 0;
}

