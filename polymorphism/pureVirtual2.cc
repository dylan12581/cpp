#include <cmath>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

#define PI 3.14
class Figure{
public:
    virtual string getName() const = 0;
    virtual double getArea() const = 0;
};
void display(Figure & fig) {
    cout << fig.getName()
         << "的面积是:"
         << fig.getArea() << endl ;
}

class Rectangle//矩形
: public Figure
{
public:
    Rectangle(double len,double wid)
    : _length(len)
    , _width(wid)
    {}

    string getName() const override
    {
        return "矩形";
    }
    double getArea() const override
    {
        return _length * _width;
    }
private:
    double _length;
    double _width;
};
class Circle
: public Figure
{
public:
    Circle(double r)
    : _radius(r)
    {}

    string getName() const override
    {
        return "圆形";
    }
    double getArea() const override
    {
        return PI * _radius * _radius;
    }
private:
    double _radius;
};
class Triangle
: public Figure
{
public:
    Triangle(double a,double b,double c)
    : _a(a)
    , _b(b)
    , _c(c)
    {}

    string getName() const override
    {
        return "三角形";
    }
    double getArea() const override
    {
        double p = (_a + _b + _c)/2;
        return sqrt(p * (p -_a) * (p - _b)* (p - _c));
    }
private:
    double _a,_b,_c;
};
void test0()
{
    Triangle t(3,4,5);
    Circle c(2);
    Rectangle rec(1,1);
    Figure &f1 = t;
    Figure &f2 = c;
    Figure &f3 = rec;
    display(f1);
    display(f2);
    display(f3);

}

int main()
{
    test0();
    return 0;
}

