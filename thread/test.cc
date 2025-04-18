#include <iostream>
#include <string.h>
#include <memory>
#include <functional>

using std::cout;
using std::endl;
using std::function;
using std::shared_ptr;

class Point{
public:
    Point(int x,int y)
        :_ix(x),_iy(y)
    {}
    void display(){
        cout << _ix << _iy << endl;
    }
private:
    int _ix;
    int _iy;
};

void test0(){
    using f = function<void (const shared_ptr<Point>)>;
    shared_ptr<Point> sp1(new Point(1,2));
    shared_ptr<Point>&& sp2  =  std::move(sp1);
    shared_ptr<Point>   sp3  =  std::move(sp2);
    sp3->display();
    cout << "------\n";
    sp2->display();
    cout << "------\n";
    sp1->display();
    cout << "------\n";
}

int main(){
    test0();
    return 0;
}

