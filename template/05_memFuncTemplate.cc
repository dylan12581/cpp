#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Point{
public:
    Point(double x,double y)
        :_x(x),_y(y)
    {}
    template<class T = int>
        T convert(){
            return (T)_x;
        }

    template<class T>
        T add(T t1);
private:
    double _x;
    double _y;
};
template <class T>
T Point::add(T t1){
    return _x +_y + t1;
}
void test0()
{
    Point pt(1.6,1.7);
    cout << pt.convert<int>() << endl;
    cout << pt.convert() << endl;
    cout << pt.add<double>(10) << endl;
}

int main()
{
    test0();
    return 0;
}

