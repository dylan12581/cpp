#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <cmath>

using std::cout;
using std::endl;
using std::function;
using std::bind;

class Figure{
public:
    using DisplayCallBack = function<void()>;
    using AreaCallBack = function<double()>;

    void setDisplayCallBack(const DisplayCallBack& cb){
        _displayCallBack = cb;
    }
    void setDisplayCallBack(DisplayCallBack&& cb){
        _displayCallBack = std::move(cb);
    }

    void setAreaCallBack(const AreaCallBack& cb){
        _areaCallBack = cb;
    }
    void setAreaCallBack(AreaCallBack&& cb){
        _areaCallBack = std::move(cb);
    }
    void handleDisplayCallBack()const{
        if(_displayCallBack){
            _displayCallBack();
        }
    }
    double handAreaCallBack()const{
        if(_areaCallBack){
            return _areaCallBack();
        }else{
            return 0.0;
        }
    }
private:
    DisplayCallBack _displayCallBack;
    AreaCallBack _areaCallBack;
};
class Rectangle{
public:
    Rectangle(double length = 0, double width = 0)
    : _length(length)
    , _width(width){
        cout << "Rectangle(double = 0, double = 0)" << endl;
    }
    void display(int x)const{
        cout << "Rectangle";
    }
     double area() const
    {
        return _length * _width;
    }
    ~Rectangle(){
        cout << "~Rectangle()" << endl;
    }
private:
    double _length;
    double _width;
};

class Circle
{
public:
    Circle(double radius = 0)
    : _radius(radius)
    {
        cout << "Circle(double = 0)" << endl;
    }

    void print() const
    {
        cout << "Circle";
    }

    double printArea() const
    {
        return 3.14 * _radius *_radius;;
    }

    ~Circle()
    {
        cout << "~Circle()" << endl;
    }

private:
    double _radius;
};

class Triangle
{
public:
    Triangle(double a = 0, double b = 0, double c = 0)
    : _a(a)
    , _b(b)
    , _c(c){
        cout << "Triangle(double = 0, double = 0, double = 0)" << endl;
    }
    void show() const{
        cout << "Triangle";
    }

    double showArea(int) const{
        //海伦公式
        double tmp = (_a + _b + _c)/2;

        return sqrt(tmp * (tmp - _a) * (tmp - _b) * (tmp - _c));
    }

    ~Triangle()
    {
        cout << "~Triangle()" << endl;
    }
private:
    double _a;
    double _b;
    double _c;
};
void func(const Figure& fig){
    fig.handleDisplayCallBack();
    cout << "的面积 : " << fig.handAreaCallBack() << endl;
}
void test0(){
    Rectangle rec(10,20);
    Circle cir(10);
    Triangle tri(3,4,5);
    cout << endl;

    using namespace std::placeholders;
    Figure fig;
    fig.setDisplayCallBack(std::bind(&Rectangle::display,&rec,10));
    fig.setAreaCallBack(std::bind(&Rectangle::area,&rec));
    func(fig);
    fig.setDisplayCallBack(bind(&Circle::print,&cir));
    fig.setAreaCallBack(bind(&Circle::printArea,&cir));
    func(fig);
    fig.setDisplayCallBack(bind(&Triangle::show,&tri));
    fig.setAreaCallBack(bind(&Triangle::showArea,&tri,1));
    func(fig);
}
void test1(){
    int num = 100;
    int a = 200;
    function<void(int&)> f = [&num](int &value){
        ++num;
        cout << "num = " << num << endl;
        cout << "value=" << value << endl;
    };
    f(a);
    cout << num << endl;

}

int main()
{
    test1();
    return 0;
}

