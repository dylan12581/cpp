#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton * getInstance(){
        if(nullptr == _pInstance){
            _pInstance = new Singleton(1,2);
        }
        return _pInstance;
    }

   //static void destroy(){
   //    if(_pInstance){
   //        delete _pInstance;
   //        _pInstance = nullptr;
   //        cout << ">>delete heap" << endl;
   //    }
   //}

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
    class AutoRelease{
    public:
        AutoRelease()
        {}
        ~AutoRelease(){
           cout << "~AutoRelease()" << endl;
          if(_pInstance){
              delete _pInstance;
              _pInstance = nullptr;
          }
        }
    };
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

    void * operator new(size_t sz)
	{
        cout << "operator new sz = " << sz << endl;
		void * ret = malloc(sz);
		return ret;
	}

    void operator delete(void * pointer)
	{
        cout << "operator delete" << endl;
		free(pointer);
	}
private:
   //...
    int _ix;
    int _iy;
    static Singleton * _pInstance;
    static AutoRelease _ar;
};
Singleton* Singleton::_pInstance = nullptr;
//使用AutoReleas类的无参构造对_ar进行初始化
Singleton::AutoRelease Singleton::_ar;

void test0(){
    Singleton::getInstance()->init(7,8);
    Singleton::getInstance()->print();
    //Singleton::destroy();
}


int main(void){
    test0();
    return 0;
}
