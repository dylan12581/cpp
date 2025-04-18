#include <iostream>
using std::cout;
using std::endl;
/* #pragma pack(4) */

// 16
class A{
    int _num;
    double _price;
};
//8
class B{
    int _num;
    int _price;
};
//16
class C{
    int _c1;
    int _c2;
    double _c3;
};
//24
class D{
    int _d1;
    double _d2;
    int _d3;
};
// 8 + 24 + 8 = 40
class E{
    double _e;
    char _eArr[20];
    int _e2;
    double _e1;
};
// 20 + 4 + 8 = 32
class I{
    char _eArr[20];
    int _e2;
    double _e1;
};
// 4 + 20 + 8 = 32
class J{
    int _e2;
    char _eArr[20];
    double _e1;
};
// 4
class F{
    int _num;
};
// 1 
class G
{
    char _ch;
};
// 20
class H
{
    char _arr[20];
};

//声明了一个类
//没有完成定义，也就是没有具体实现
class Y;

//定义了一个空类
class X
{};

void test0(){
   cout << sizeof(A) << endl;
   cout << sizeof(B) << endl;
   cout << sizeof(C) << endl;
   cout << sizeof(D) << endl;
   cout << sizeof(E) << endl;
   cout << sizeof(F) << endl;
   cout << sizeof(G) << endl;
   cout << sizeof(H) << endl;
   cout << sizeof(I) << endl;
   cout << sizeof(J) << endl;



   /* Y y;//error */

   X x;
   X x2;
   //针对空类，编译器的占位机制会分配一个字节的空间
   //让该类对象拥有一个独一无二的地址
   cout << &x << endl;
   cout << &x2 << endl;
   cout << sizeof(x) << endl;
}

int main(void){
    test0();
    return 0;
}
