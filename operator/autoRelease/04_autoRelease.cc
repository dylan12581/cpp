#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Sigleton{
public:
    static Sigleton* getInstance(){
        //确保初始化代码只会执行一次                                                                              
        pthread_once(&_once,init_r);
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
    // 私有，防止饱汉情况下被手动调用又带来多线程问题
    static void destroy(){
        if(_pInstance){
            cout << "delete heap" << endl;
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
    // 私有，防止手动调用，导致内存泄漏
    static void init_r(){
        atexit(destroy);
        _pInstance = new Sigleton(1,2);

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
    static pthread_once_t _once;
};
// 饱汉式创建
Sigleton* Sigleton::_pInstance = nullptr;
// 饿汉式创建
//Sigleton* Sigleton::_pInstance = Sigleton::getInstance();
pthread_once_t _once = PTHREAD_ONCE_INIT;


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

