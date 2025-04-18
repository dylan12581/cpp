#include <iostream>

using std::cout;
using std::endl;
class Point
{
public:
    /* Point() = default; */
    Point(int x = 0,int y = 0)
        : _ix(x)
          , _iy(y)
    {
        /* cout << "Point(int,int)" << endl; */
    }

    void print() const{
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

    ~Point(){
         cout << "~Point()" << endl; 
    }
protected:
    int _ix;
private:
    int _iy;
};


template<class T>
class RAII{
public:
    RAII(T* data)
    :_data(data){
        cout << "RAII(T*)" << endl;
    }
    ~RAII(){
        cout << "~RAII()" << endl;
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
    T * get() const{
        return _data;
    }
    void set(T* data){
        if(_data){
            delete _data;
            _data = nullptr;
        }
        _data = data;
    }
    //4.不允许复制或赋值
    RAII(const RAII & rhs) = delete;
    RAII& operator=(const RAII & rhs) = delete;

private:
    T* _data;

};

void test0()
{
    Point * pt = new Point(1, 2);
	//智能指针的雏形
	RAII<Point> raii(pt);
	raii->print();
	(*raii).print();
}

int main()
{
    test0();
    return 0;
}

