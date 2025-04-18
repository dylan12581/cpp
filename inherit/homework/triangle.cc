#include <cmath>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Point{
public:
    Point(float ix,float iy)
        :_ix(ix),_iy(iy)
    {
        cout << "Point(int ,int)" << endl;
    }
    ~Point(){ cout << "~Point()" << endl; }
    float getX(){
        return _ix;
    }
    float getY(){
        return _iy;
    }
private:
    float _ix;
    float _iy;
};
class Colour{
public:
    Colour(string colour)
        :_colour(colour)
    {
        cout << "Colour(string)" << endl;
    }
    ~Colour(){cout << "~Colour()" << endl;}

    string getColour(){
        return _colour;
    }
private:
    string _colour;
};
class Line{
public:
    Line(float x1,float y1,float x2,float y2)
        :_pt1(x1,y1),_pt2(x2,y2)
    {
        cout << "Line(int * 4)" << endl;
    }
    ~Line(){cout << "~Line()" << endl;}
    float getLineLength(){
        float dx = _pt2.getX() - _pt1.getX();
        float dy = _pt2.getY() - _pt1.getY();
        return sqrt(pow(dx,2) + pow(dy,2));
    }


private:
    Point _pt1;
    Point _pt2;
};

class Triangle
:public Colour,public Line
{
public:
    Triangle(float x1,float y1,float x2,float y2,float height,string colour)
    :Colour(colour)
     ,Line(x1,y1,x2,y2)
     ,_height(height)
    {
        cout << "Triangle(float * 4,string)" << endl;
    }
    ~Triangle(){cout << "~Triangle()" << endl;}
    string calcColour(){
        return getColour();
    }
    float  calcPerimeters(){
        float lineLength = getLineLength();
        return  lineLength + _height + sqrt(pow(lineLength,2) + pow(_height,2));
    }
    float calcArea(){
        return (getLineLength() * _height) / 2; 
    }
private:
    float _height;
};
void test0()
{
    Triangle t1(0,0,3,0,4,"red");
    cout <<"三角形颜色 : " <<t1.calcColour() <<"周长 : " <<  t1.calcPerimeters() << "面积 : "<<  t1.calcArea() << endl;
}

int main()
{
    test0();
    return 0;
}

