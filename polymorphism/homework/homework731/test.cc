#include <iostream>
#include <string.h>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;

class B;
class A{
public:
    A(shared_ptr<B> sp)
        :_sp(sp)
    {
        cout << "A" << endl;
    }

    void rep(){
        _sp->display();
    }

private:
    shared_ptr<B> _sp;
};

class B{
private:
    void display(){
        cout << "B" << endl;
    }
};

void test0()
{
    A a(new B());
    a.rep();
}

int main()
{
    test0();
    return 0;
}

