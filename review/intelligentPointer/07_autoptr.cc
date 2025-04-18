#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::auto_ptr;

void test0()
{
    int* p = new int(10);
    auto_ptr<int> ap(p);
    cout << *ap << endl;
    cout << ap.get() << endl;
    cout << p << endl;
    
    // 底层指针被置空,相当于移交了管理权
    auto_ptr<int> ap2(ap);
    cout << *ap2 << endl;
    cout << ap2.get() << endl;
    cout << *ap << endl;
}

int main()
{
    test0();
    return 0;
}

