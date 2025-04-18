#include <iostream>
using std::cout;
using std::endl;

class FunctionObject{
public:
    //第一个()与operator一起作为函数名
    //第二个()代表参数列表
    void operator()(){
        ++_cnt;
        cout << "hello" << endl;
    }

    void operator()(int x){
        ++_cnt;
        cout << "hello " << x << endl;
    }

    double operator()(double x){
        ++_cnt;
        return x;
    }
    
    int getCnt() const{ return _cnt; }
private:
    int _cnt = 0;
};

int count = 0;

void func(){
    ++count;
    cout << "hello" << endl;
}

void func(int x){
    ++count;
    cout << "hello " << x << endl;
}

double func(double x){
    ++count;
    return x;
}

void test0(){
    func();
    func(3);
    cout << func(5.6) << endl;
    cout << "count:" << count << endl;
    cout << endl;

    FunctionObject fo;
    /* fo.operator()();//本质 */
    fo();  //让对象像一个函数一样被调用
    fo(4);
    cout << fo(4.8) << endl; 
    cout << "count:" << fo.getCnt() << endl;
    
}

int main(void){
    test0();
    return 0;
}

