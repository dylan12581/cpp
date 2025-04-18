#include <cmath>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
#define PI 3.14

class Figure {
public:
    virtual string getName() const = 0;
    virtual double getArea() const = 0;
};

void display(Figure & fig) {
    cout << fig.getName() 
         << "的面积是:" 
         << fig.getArea() << endl ;
}
class Triangle
:public Figure
{
public:
    Triangle(float a,float b,float c)
        :_a(a),_b(b),_c(c)
    {}
    virtual string getName() const override{
        return "Triangle";
    }
    virtual double getArea() const override{
        float p = (_a + _b + _c) / 2;
        float area = sqrt(p * (p - _a) * (p - _b) * (p - _c));
        return area;
    }

private:
    float _a;
    float _b;
    float _c;
};
class Rectangle
:public Figure 
{
public:
    Rectangle(float a,float b)
        :_a(a),_b(b)
    {}
    virtual string getName() const override{
        return "Rectangle";
    }
    virtual double getArea() const override{
        return _a * _b;
    }
private:
    float _a;
    float _b;
};
class Circle
:public Figure{
public:
    Circle(float radius)
        :_radius(radius){}
    virtual string getName() const override{
        return "Circle";
    }
    virtual double getArea() const override{
        return PI * _radius * _radius;
    }

private:
    float _radius;
};
void test() {
    Rectangle r(10, 20);
    Circle c(15);
    Triangle t(3, 4, 5);
    display(r);
    display(c);
    display(t);
}

int main()
{
    test();
    return 0;
}

