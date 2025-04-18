#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Child;
class Parent{
public:
    Parent(){
        cout << "Parent()" << endl;
    }
    ~Parent(){
        cout << "~Parent()" << endl;
    }
    weak_ptr<Child> _wpchild;

};
class Child{
public:
    Child(){
        cout << "Child()" << endl;
    }
    ~Child(){
        cout << "~Child()" << endl;
    }

    shared_ptr<Parent> _spParent;
};

void test0()
{
    shared_ptr<Parent> parentPtr(new Parent());
    shared_ptr<Child> childPtr(new Child());
    cout << parentPtr.use_count() << endl;
    cout << childPtr.use_count() << endl;

    parentPtr->_wpchild = childPtr;
    childPtr->_spParent = parentPtr;
    cout << parentPtr.use_count() << endl;
    cout << childPtr.use_count() << endl;
}

int main()
{
    test0();
    return 0;
}

