#include <iostream>
#include <string.h>

using std::cout;
using std::endl;


class Calc{
    public:
    virtual int getResult(int x,int y) = 0;
    virtual ~Calc(){};
   
    int minus(int x,int y){
        return x - y;
    }
    int multiply(int x,int y){
        return x * y;
    }
};
class plusCalc
:public Calc
{
    
public:
     virtual int getResult(int x,int y)override{
        return x + y;
    }
    ~plusCalc(){};
};


void test0(){
  Calc* c = new plusCalc();
  cout << c->getResult(1,2) << endl;
  delete c;
}
int main()
{
    test0();
    return 0;
}

