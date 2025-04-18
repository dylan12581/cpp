#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point()
    : _ix(0)
    , _iy(0){
        cout << "Point()" << endl;
    }

    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    Point(const Point & rhs)
    : _ix(rhs._ix)//int _ix = rhs._ix;
    , _iy(rhs._iy)
    {
         cout << "拷贝构造函数" << endl;
    }
    Point & operator=(const Point & rhs){
        cout << "赋值运算符函数" << endl;
        this->_ix = rhs._ix;
        this->_iy = rhs._iy;
        return *this;
    }

    void print(){
        cout << "(" << this->_ix
            << "," << this->_iy
            << ")" << endl;
    }

    ~Point(){
        cout << "~Point()" << endl;
    }

private:
    int _ix;
    int _iy;
};

void test0(){

   Point pt1(3,9); 
   Point pt2(1,5); 
   Point pt3(5,7); 

   Point arr[3] = {pt1,pt2,pt3};
   cout << &pt1 << endl; 
   cout << &arr[0] << endl;  

   Point arr2[3] = {Point(2,6),Point(6,6)}; 

    Point arr3[3] = {{2,4},{8,9},{6,9}};
    for(int idx = 0; idx < 3; ++idx){
        arr3[idx].print();
    }
}

void test1(){
    Point * p1 = new Point();
    p1->print();
    delete p1;
    p1 = nullptr;

    //Point * p2 = new Point(4,7);
    Point * p2 = new Point(4,7);
    p2->print();
    delete p2;
    p2 = nullptr;

    cout << endl;
    Point * p3 = new Point[3]();
    //Point * p3 = new Point[3]{{3,8},{7,9},{5,4}};
    for(int idx = 0; idx < 3; ++idx){
        p3[idx].print();
    }
    delete [] p3;
    p3 = nullptr;
}

int main(void){
    test1();
    return 0;
}

