#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Point
{
public:

    static Point* getInstance(){
        if(_pInstance == nullptr){
            _pInstance = new Point(1,2);
        }
        return _pInstance;
    }
    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
            cout << ">>delete heap" << endl;
        }
    }
    void init(int x,int y){
        _ix = x;
        _iy = y;
    }
    
    void print() const{
        cout << "(" << this->_ix
            << "," << this->_iy
            << ")" << endl;
    }
    
private:
     Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }
     ~Point(){
         cout << "~Point()" << endl;
     }
     Point(const Point&) = delete;
     Point* operator=(const Point& rhs) = delete;
private:
    int _ix;
    int _iy;
    static Point* _pInstance;
};
Point* Point::_pInstance = nullptr;
#if 0
void test0()
{
   Point* p = Point::getInstance();
   p->print();
   //delete p;
}
#endif
void test1(){
    Point::getInstance()->print();
    Point::getInstance()->init(1,1);
    Point::getInstance()->print();
    Point::getInstance()->init(2,2);
    Point::getInstance()->print();
    Point::destroy();
    Point::destroy();
    Point::destroy();

}

int main()
{
    test1();
    return 0;
}

