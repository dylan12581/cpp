#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Point {
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
    ,_ref(ix)
    {
           cout << "Point()" << endl;
    }
    void print(){
        cout << "(" << _ix
            << "," << _iy
            << "," << _ref
            << ")" << endl;
    }
    
private:
	int _ix;
	int _iy;
	int & _ref = _iy;
};

void test0()
{
    Point pt1(1,2);
    pt1.print();

}

int main()
{
    test0();
    return 0;
}

