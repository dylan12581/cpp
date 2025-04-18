#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {}

    void print() const{
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
private:
    int _ix;
    int _iy;
};

template <class T>
class RAII{
public:
    RAII(T* data)
        :_data(data){
            cout << "RAII(T* data)" << endl;
        }
    ~RAII(){
        if(_data){
            delete _data;
            _data = nullptr;
        }
    }
    T* operator->(){
        return _data;
    }
    T& operator*(){
        return *_data;
    }
    T* get(){
        return _data;
    }
    void set(T* data){
        if(_data){
            delete _data;
            _data = nullptr;
        }
        _data = data;
    }

    RAII(const RAII & rhs) = delete;
    RAII& operator=(const RAII& rhs) = delete;
private:
    T* _data;
};

void test0()
{
    Point*pt = new Point(1,2);
    RAII<Point> raii(pt);
    raii->print();
    (*raii).print();
}

int main()
{
    test0();
    return 0;
}

