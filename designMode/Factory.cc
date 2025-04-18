#include <math.h>
#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
class Figure
{
public:
    Figure(){
        cout <<"Figure()"<< endl;
    }
    //纯虚函数
    virtual void display() const = 0;
    virtual double area() const = 0;

    virtual ~Figure() {
        cout << "~Figure()" << endl;
    }
};

class Rectangle
: public Figure
{
public:
    Rectangle(double length = 0, double width = 0)
    : _length(length)
    , _width(width)
    {
        cout << "Rectangle(double = 0, double = 0)" << endl;
    }

    void display() const override
    {
        cout << "Rectangle";
    }

    double area() const override
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
: public Figure
{
public:
    Circle(double radius = 0)
    : _radius(radius)
    {
        cout << "Circle(double = 0)" << endl;
    }

    void display() const override
    {
        cout << "Circle";
    }

    double area() const override
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
: public Figure
{
public:
    Triangle(double a = 0, double b = 0, double c = 0)
    : _a(a)
    , _b(b)
    , _c(c)
    {
        cout << "Triangle(double = 0, double = 0, double = 0)" << endl;
    }

    void display() const override
    {
        cout << "Triangle";
    }

    double area() const override
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

void func(Figure* pfig){
    pfig->display();
    cout << "的面积 : " << pfig->area() << endl;
}
class Factory{
public:
    Factory(){
        cout << "Factory()" << endl;
    }
    virtual Figure* create() = 0;
    virtual ~Factory(){
        cout << "~Factory()" << endl;
    };
};

class RectangleFactory
:public Factory
{
public:
    RectangleFactory(){
        cout << "RectangleFactory()" << endl;
    }
    virtual Figure* create()override{
        Rectangle* prec = new Rectangle(10,20);
        return  prec;
    }
    virtual ~RectangleFactory(){
        cout << "~RectangleFactory()" << endl;
    };
};
class CircleFactory
:public Factory{
public:
    CircleFactory(){
        cout << "CircleFactory()" << endl;
    }
    virtual Figure * create() override{
        Circle* pcir = new Circle(10);
        return pcir;
    }
    virtual ~CircleFactory(){
        cout << "~CircleFactory()" << endl;
    };
};
class TriangleFactory
:public Factory
{
public:
    TriangleFactory(){
        cout << "TriangleFactory()" << endl;
    }
    virtual Figure * create() override{
        Triangle* ptri = new Triangle(3,4,5);
        return ptri;
    }
    virtual ~TriangleFactory(){
        cout << "~TriangleFactory()" << endl;
    };
};

int main()
{
    unique_ptr<Factory> frec(new RectangleFactory());
    unique_ptr<Figure> prec(frec->create());

    unique_ptr<Factory> fcir(new CircleFactory());
    unique_ptr<Figure> pcir(fcir->create());

    unique_ptr<Factory> ftri(new TriangleFactory());
    unique_ptr<Figure> ptri(ftri->create());

    func(prec.get());
    func(pcir.get());
    func(ptri.get());

    return 0;
}

