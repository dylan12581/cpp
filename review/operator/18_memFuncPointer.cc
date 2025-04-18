#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class FFF
{
public:
    void print(int x){
        cout << "FFF::print:" << x << endl;
    }

    void display(int x){
        cout << "FFF::display:" << x << endl;
    }
};

void test0()
{
    void (FFF::*p)(int) = &FFF::print;
    FFF fff;
    (fff.*p)(3);

    typedef void(FFF::*pMemFunc)(int) ;
    pMemFunc pMF = &FFF::display;
    FFF fff2;
    (fff2.*pMF)(15);
    FFF* fff3 = new FFF();
    (fff3->*pMF)(13);
    delete fff3;
    fff3 = nullptr;

    (fff3->*pMF)(11);

    (fff3->display)(12);

}

int main()
{
    test0();

    return 0;
}

