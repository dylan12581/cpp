#include <iostream>

using std::cout;
using std::endl;

class Singleton{
public:
    static Singleton* getInstance(){
        if(_pInstance == nullptr){
            _pInstance = new Singleton(1,2);
        }
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

    /* static void destroy(){ */
    /*     if(_pInstance){ */
    /*         delete _pInstance; */
    /*         _pInstance = nullptr; */
    /*         cout << ">>delete heap" << endl; */
    /*     } */
    /* } */

    friend class AutoRelease;
    Singleton(const Singleton & rhs) = delete;
    Singleton & operator=(const Singleton & rhs) = delete;
private:
    Singleton() = default;
    Singleton(int x,int y)
        :_ix(x),_iy(y){
        cout << "Singleton(int,int)" << endl;
    }
    ~Singleton(){
        cout << "~Singleton()" << endl;
    }

private:
    int _ix;
    int _iy;
    static Singleton* _pInstance;
};
Singleton* Singleton::_pInstance = nullptr;

class AutoRelease{
public:
    AutoRelease(Singleton * p)
    : _p(p)
    {}

    ~AutoRelease(){
        if(_p){
            delete _p;
            _p = nullptr;
        }
    }
private:
    Singleton * _p;
};

void test0()
{
    AutoRelease ar(Singleton::getInstance());
    Singleton::getInstance()->init(1,1);
    Singleton::getInstance()->print();
}

int main()
{
    test0();
    return 0;
}

