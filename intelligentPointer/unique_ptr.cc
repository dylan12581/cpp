#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

class Point
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
private:
    int _ix;
    int _iy;
};


void test0()
{
    unique_ptr<int> upp(new int(10));
    cout << *upp << endl;
    cout << upp.get() << endl;
    upp.reset(new int(30));
    cout << *upp << endl;
    cout << upp.get() << endl;

    //unique_ptr<int> upp2(upp);
    unique_ptr<int> upp2(new int(50));
    //upp = upp2;
    

}
void test1(){
    unique_ptr<Point> upp1(new Point(1,2));
    unique_ptr<Point> upp2(new Point(3,4));
    upp2.reset(new Point(5,6));
    upp1->print();
    upp2->print();

    vector<unique_ptr<Point>> v1;
    v1.push_back(std::move(upp1));
    v1.push_back(std::move(upp2));

   // upp1->print();
   //upp2->print();
   v1[0]->print();
   v1[1]->print();
   for(auto & ele:v1){
       ele->print();
   }

}

int main()
{
    test1();
    return 0;
}

