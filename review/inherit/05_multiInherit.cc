#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    A(){ cout << "A()" << endl; }
    ~A(){ cout << "~A()" << endl; }
    void print() const{
        cout << "A::print()" << endl;
    }
};

class B
{
public:
    B(){ cout << "B()" << endl; }
    ~B(){ cout << "~B()" << endl; }
    void show() const{
        cout << "B::show()" << endl;
    }
};

class C
{
public:
    C(){cout << "C()" << endl; }
    ~C(){ cout << "~C()" << endl; }
    void display() const{
        cout << "C::display()" << endl;
    }
};

class D
: public A
, public B
, public C
{
public:
    D()
    /* : A() */
    /* , B() */
    /* , C() */
    { cout << "D()" << endl; }

    ~D(){ cout << "~D()" << endl; }

    void print() const{
        cout << "D::print()" << endl;
    }
};

void test0(){
    D d1;
    d1.print();
    d1.show();
    d1.display();
    cout << sizeof(A) << endl;
    cout << sizeof(D) << endl;
}

int main(void){
    test0();
    return 0;
}

