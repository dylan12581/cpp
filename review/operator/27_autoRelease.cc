#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton * getInstance(){
        //当多个线程同时进入if语句
        //会造成Singleton对象被创建多个
        //但是只有一个对象的地址被_pInstance保存
        //因此造成内存泄露
        pthread_once(&_once,init_r);
        return _pInstance;
    }
    
    void init(int x,int y){
        _ix = x;
        _iy = y;
    }

    void print(){
        cout << "(" << this->_ix
            << "," << this->_iy
            << ")" << endl;
    }

    Singleton(const Singleton & rhs) = delete;
    Singleton & operator=(const Singleton & rhs) = delete;
private:
    Singleton() = default;
    Singleton(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        cout << "Singleton(int,int)" << endl;
    }

    ~Singleton(){
        cout << "~Singleton()" << endl;
    }
    
    static void init_r(){
        atexit(&destroy);
        _pInstance = new Singleton(1,2);
    }
    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
            cout << ">>delete heap" << endl;
        }
    }

private:
    int _ix;
    int _iy;
    static Singleton * _pInstance;
    static pthread_once_t _once;
};
//饱汉式（懒汉式）—— 懒加载，不使用到该对象，就不会创建
 Singleton * Singleton::_pInstance = nullptr;
 pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;
//饿汉式 —— 最开始就创建（即使不使用这个单例对象）
//Singleton * Singleton::_pInstance = Singleton::getInstance();


void test0(){
    Singleton::getInstance()->init(7,8);
    Singleton::getInstance()->print();
    //手动调用destroy不会有double free的风险
    //因为destroy执行后会将_pInstance置空
    //但是由于_pInstance被设为了空指针，
    //多线程环境下getInstance函数又会存在内存泄露的风险
    /* Singleton::destroy(); */
}

void test1(){
    Singleton::getInstance()->init(7,8);
    Singleton::getInstance()->print();
    /* Singleton::destroy(); */
    Singleton::getInstance()->init(7,8);
    Singleton::getInstance()->print();

    //如果手动调用init_r会绕开pthread_once的限制
    //造成内存泄露
    /* Singleton::init_r(); */
    /* Singleton::init_r(); */
    /* Singleton::init_r(); */
    /* Singleton::init_r(); */

}

int main(void){
    test1();
    return 0;
}

