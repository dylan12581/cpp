#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Sigleton{
public:
    static Sigleton* getInstance(){
        if(_pInstance == nullptr){
            atexit(destroy);
            // 多线程重复申请堆空间，导致内存泄漏问题
            _pInstance = new Sigleton(1,2);
        }
        return _pInstance;
    }
    void print()const{
        cout << _ix << "," << _iy << endl;
    }
    void init(int x,int y){
        _ix = x;
        _iy = y;
    }
private:
    // 防止调用析构函数
    ~Sigleton(){
        cout << "~Sigleton()" << endl;
    }
    // 私有，防止饱汉情况下被手动调用此函数又带来多线程问题
    static void destroy(){
        if(_pInstance){
            cout << "delete heap" << endl;
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

private:
    // 默认无参构造
    Sigleton() = default;
    Sigleton(int x,int y)
        :_ix(x)
         ,_iy(y)
    {
        cout << "Sigleton(int int)" << endl;
    }
private:
    Sigleton(const Sigleton& rhs)  = delete;
    Sigleton& operator=(const Sigleton& rhs)  = delete;

    int _ix;
    int _iy;
    static Sigleton* _pInstance;
};
// 饱汉式创建
//Sigleton* Sigleton::_pInstance = nullptr;
// 饿汉式创建
Sigleton* Sigleton::_pInstance = Sigleton::getInstance();


void test0()
{
    Sigleton::getInstance()->print();
    Sigleton::getInstance()->init(2,4);
    Sigleton::getInstance()->print();

    // Sigleton::destroy();
    //Sigleton::destroy();
    //Sigleton::destroy();
}

int main()
{
    test0();
    return 0;
}

