#include <math.h>
#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::function;
using std::bind;

class Figure
{
public:
    using DisplayFunction = function<void()>;
    using AreaFunction = function<double()>;

    DisplayFunction _displayFunction;
    AreaFunction _areaFunction;


    void setDisFun(DisplayFunction && cb){
        _displayFunction = std::move(cb);
        //_displayFunction = cb;
    }
    void setAreaFun(AreaFunction && cb){
        //_areaFunction = cb;
        _areaFunction = std::move(cb);
    }
    //执行回调函数   void handleDispalyCallback() const    {
        //将两个数据成员进行了执行(回调函数的执行)
    void handleDisplayCallback() const
    {
        if(_displayFunction)
        {
            _displayFunction();
        }
    }

    double handleAreaCallback() const
    {
        if(_areaFunction)
        {
            return _areaFunction();
        }
        else
        {
            return 0.0;
        }
    }
};

class Rectangle
{
public:
    Rectangle(double length = 0, double width = 0)
        : _length(length)
          , _width(width)
    {
        cout << "Rectangle(double = 0, double = 0)" << endl;
    }

    void display() const 
    {
        cout << "Rectangle";
    }

    double area() const 
    {
        return _length * _width;
    }

    ~Rectangle()
    {
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

    void display(int) const
    {
        cout << "Circle";
    }

    double area() const 
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
          , _c(c)
    {
        cout << "Triangle(double = 0, double = 0, double = 0)" << endl;
    }

    void display() const 
    {
        cout << "Triangle";
    }

    double area() const 
    {
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
void func(const Figure &fig)
{
    fig._displayFunction();
    cout << "的面积 : " << fig._areaFunction() << endl;
}

int main(int argc, char **argv)
{
    Rectangle rectangle(10, 20);
    Circle circle(10);
    Triangle triangle(3, 4, 5);

    Figure fg;
    fg.setDisFun(bind(&Rectangle::display,&rectangle));
    fg.setAreaFun(bind(&Rectangle::area,&rectangle));
    func(fg);
    fg.setDisFun(bind(&Circle::display,&circle,1));
    fg.setAreaFun(bind(&Circle::area,&circle));
    func(fg);


    return 0;
}
