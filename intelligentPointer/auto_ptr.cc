#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::auto_ptr;

class Computer{
public:

private:

};

void test0()
{
    int * pInt = new int(10);
    // 创建auto_ptr对象接管资源
    auto_ptr<int> ap(pInt);
    cout << "*pInt:" << *pInt << endl;
    cout << "*ap:" << *ap << endl;
    cout << ap.get() << endl;

    auto_ptr<int> ap2(ap);
    cout << "*ap2:" << *ap2 << endl;
    //cout << "*ap:" << *ap << endl;
    cout << ap2.get() << endl;

}

int main()
{
    test0();
    return 0;
}

