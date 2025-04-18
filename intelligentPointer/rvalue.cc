#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Computer{
public:

private:

};

void test0()
{
    int a = 1;
    //&(std::move(a)); //error，左值转成了右值
    
	string s1("hello");
	cout << "s1:" << s1 << endl;
	string s2 = std::move(s1);
	cout << "s1:" << s1 << endl;// 会将s1 nullptr
	cout << "s2:" << s2 << endl;
}
int gNum = 10;
int&& func(){
    return std::move(gNum);
   // return gNum;
}
void test1(){
    //&func();
    int &&ref = func();
    &ref;
}
int&& func1(int a,int b){
    return a + b;
}
void test2(){
    //&func1(1,2);
    int && ref = func1(1,2);
    // &ref;                //未定义行为
    // cout << ref << endl; //未定义行为
}
int main()
{
    test2();
    return 0;
}

