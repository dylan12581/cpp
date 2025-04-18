#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


class Point{
public:

    Point(int ix = 0,int iy = 0)
        :_ix(ix),_iy(iy)
    {
        cout << "Point(int ,int )" << endl;
    }

//private:
    Point(const Point& rhs)
        :_ix(rhs._ix),_iy(rhs._iy)
    {
        cout << "Point(const Point& )" << endl;
    }
    void display(){
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }
private:
    //Point( Point&& rhs)
    //    :_ix(rhs._ix),_iy(rhs._iy)
    //{
    //    cout << "Point(Point&& )" << endl;
    //}
    //void display(){
    //    cout << _ix << _iy << endl;
    //}

private:
    int _ix;
    int _iy;
};
void test0()
{
    vector<Point> vec;

    //vec.emplace_back(Point(1,2));
    vec.emplace_back(1,2);
    //vec.push_back(Point(1,2));
    cout << vec.size() << endl;

    for(auto& elem : vec){
        elem.display();
    }
    

}

int main()
{
    test0();
    return 0;
}

