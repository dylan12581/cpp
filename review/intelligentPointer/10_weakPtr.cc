#include <iostream>
#include <string.h>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;

class Father;

class Child{
public:

    shared_ptr<Father> _spFather;
};

class Father{
public:
    shared_ptr<Child> _spChild;
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

int main()
{
    test0();
    return 0;
}

