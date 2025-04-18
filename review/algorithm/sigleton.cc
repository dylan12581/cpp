#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Singleton{
public:
    static Singleton*  getInstance(){
        pthread_once(&_once,init_r);
        return _pInstance;
    }
    void init(int x,int y){
        _ix = x;
        _iy = y;
    }
    void print(){
        cout << _ix << " " << _iy << endl;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton& ) = delete;
private:
    Singleton() = default;
    Singleton(int x,int y)
        :_ix(x),_iy(y)
    {}
    static void init_r(){
        atexit(&destroy);
        _pInstance = new Singleton(1,2);
    }
    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
    ~Singleton(){
    }

private:
    int _ix;
    int _iy;
    static Singleton* _pInstance;
    static pthread_once_t _once;
};
Singleton* Singleton::_pInstance = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

void test0()
{
    Singleton::getInstance()->init(1,7);
    Singleton::getInstance()->print();
}

int main()
{
    test0();
    return 0;
}

