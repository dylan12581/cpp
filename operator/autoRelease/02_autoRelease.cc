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

    Sigleton(int x, int y)
        :_ix(x)
         ,_iy(y)
    {
        cout << "Sigleton(int int)" << endl;
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
    // static void destroy(){
    //     if(_pInstance){
    //         delete _pInstance;
    //         _pInstance = nullptr;
    //     }
    // }

private:
    ~Sigleton(){
        cout << "~Sigleton()" << endl;
    }
private:
    class AutoRelease{
    public:
        ~AutoRelease(){
            if(_pInstance){
                delete _pInstance;
                _pInstance = nullptr;
            }
        }
    };
private:
    int _ix;
    int _iy;
    static AutoRelease _ar;
    static Sigleton* _pInstance;

};
Sigleton* Sigleton::_pInstance = nullptr;
Sigleton::AutoRelease Sigleton::_ar;// 初始化静态成员对象,使用AutoReleas类的无参构造对_ar进行初始化
//前面表示类名        后面表示类名作用域
void test0(){

    Sigleton::getInstance()->print();
    Sigleton::getInstance()->init(2,3);
    Sigleton::getInstance()->print();
    // Sigleton::destroy();
    // Sigleton::destroy();
}

int main(){
    test0();
    return 0;
}
