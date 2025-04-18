#include <iostream>

using std::cout;
using std::endl;

class Base{
public:
	virtual void print() {
		cout << "Base::print()" << endl;
		}
	virtual void display() {
		cout << "Base::display()" << endl;
	}
	virtual void show() {
		cout << "Base::show()" << endl;
	}
private:
	long _base = 10;
};

class Derived
: public Base
{
public:
	virtual void display() {
		cout << "Derived::display()" << endl;
	}
	virtual void show() {
		cout << "Derived::show()" << endl;
	}

 	virtual void print() {
		cout << "Derived::print()" << endl;
	}

    virtual void func(){
        cout << "Derived::func()" << endl;
    }
private:
	long _derived = 100;
};

void test0()
{
    Derived d;
    cout << sizeof(d) << endl;
    cout << sizeof(long) << endl;
    cout << endl;

    long* pderived = (long*)&d;
    // *(pderived + 0)
    cout << pderived[0] << endl;
    // *(pderived + 8)
    cout << pderived[1] << endl;
    // *(pderived + 16)
    cout << pderived[2] << endl;
    cout << endl;

    long* pVtable = (long*)pderived[0];
    int* p = new int(1);
    cout <<"dui:"<<  p << endl;
    static int sp = 1;
    cout <<"static:" << &sp << endl;
    const char* cp = "hello1";
    printf("wenzi:%p\n",cp);
    cout << pVtable << endl;
    const char* cp2 = "hello";
    printf("wenzi:%p\n",cp2);
    cout << pVtable[0] << endl;
    cout << pVtable[1] << endl;
    cout << pVtable[2] << endl;
    cout << pVtable[3] << endl;
    cout << endl;

    typedef void(*Function)();
    Function f = (Function)(pVtable[0]);
    f();
    f = (Function)(pVtable[1]);
    f();
    f = (Function)(pVtable[2]);
    f();
    f = (Function)(pVtable[3]);
    f();


}

int main()
{
    test0();
    return 0;
}

