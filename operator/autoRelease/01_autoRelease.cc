#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Sigleton{
public:
    static Sigleton* getInstance(){
        if(_pInstance == nullptr){
            _pInstance = new Sigleton(1,2);
        }
        return _pInstance;
    }
   // static void destroy(){
   //     if(_pInstance){
   //     cout << "delete heap" << endl;
   //         delete _pInstance;
   //         _pInstance = nullptr;
   //     }
   // }
    void print()const{
        cout << _ix << "," << _iy << endl;
    }
    void init(int x,int y){
        _ix = x;
        _iy = y;
    }
friend class AutoRelease;// AutoRelease 析构函数会调用Singleton的析构函数，要声明友元
private:
    // 防止调用析构函数
    ~Sigleton(){
        cout << "~Sigleton()" << endl;
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
Sigleton* Sigleton::_pInstance = nullptr;

class AutoRelease{
public:

    AutoRelease(Sigleton* p)
        :_p(p)
    {
        cout << "AutoRelease(Sigleton* )" << endl;
    }
    ~AutoRelease(){
        if(_p){
            cout << "~AutoRelease()" << endl;
            delete _p;
            _p = nullptr;
        }
    }

private:
    Sigleton* _p;
};

void test0()
{
    Sigleton::getInstance()->print();
    Sigleton::getInstance()->init(2,4);
    Sigleton::getInstance()->print();

    // Sigleton::getInstance()->~Sigleton();

   // Sigleton::destroy();
    //Sigleton::destroy();
    //Sigleton::destroy();
}
void test1(){
    AutoRelease ar(Sigleton::getInstance());
    // 不能够被多个AutoRelease对象托管,会出现多次free的问题
    //AutoRelease ar2(Sigleton::getInstance());
    Sigleton::getInstance()->print();
    Sigleton::getInstance()->init(2,4);
    Sigleton::getInstance()->print();
    //Sigleton::destroy();
}

int main()
{
    test1();
    return 0;
}

