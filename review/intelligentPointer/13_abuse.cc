#include <iostream>
#include <string.h>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::enable_shared_from_this;

class Point
:public enable_shared_from_this<Point>
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
    //Point * addPoint(Point * pt){
	//_ix += pt->_ix;
	//_iy += pt->_iy;
	//return this;
//}
   
   shared_ptr<Point> addPoint(Point * pt){
       _ix += pt->_ix;
   	_iy += pt->_iy;
   /*     //创建出匿名的shared_ptr对象与sp共用了裸指针 */
   	return shared_ptr<Point>(this);// 先移动拷贝 运算符，这行结束时，会delete一次，返回
   }
//    shared_ptr<Point> addPoint(Point * pt){
//        _ix += pt->_ix;
//    	_iy += pt->_iy;
//    /*     //创建出匿名的shared_ptr对象与sp共用了裸指针 */
//    	return shared_from_this();
//    }

private:
    int _ix;
    int _iy;
};


void test0(){
    Point* pt = new Point(1,2);
    unique_ptr<Point> up1(pt);
    unique_ptr<Point> up2(pt);
    //error
}
void test1(){
    unique_ptr<Point> up(new Point(1,2));
    unique_ptr<Point> up2(new Point(2,2));
    up.reset(up2.get());
    //error
}
void test2(){
    Point* pt = new Point(1,2);
    shared_ptr<Point> up1(pt);
    shared_ptr<Point> up2(pt);
    //error
}
void test3(){
    shared_ptr<Point> up(new Point(1,2));
    shared_ptr<Point> up2(new Point(2,2));
    up.reset(up2.get());
    //error
}
void test4(){
    shared_ptr<Point> sp(new Point(1,2));
    shared_ptr<Point> sp2(new Point(2,2));
    shared_ptr<Point> sp3(sp->addPoint(sp2.get()));
    //error
    cout << "sp3=";
    sp3->print();
}

void test5(){
    shared_ptr<Point> sp(new Point(1,2));
    shared_ptr<Point> sp2(new Point(2,2));
    sp->addPoint(sp2.get());
    delete sp.get();
    cout << "over" << endl;
}
void test6(){
    shared_ptr<Point> sp(new Point(1,2));
    shared_ptr<Point> sp2(new Point(2,2));
    sp->addPoint(sp2.get());
    sp->print();// 属于编译器优化
    delete sp.get();
    cout << "over" << endl;
}
int main()
{
    test6();
    return 0;
}

