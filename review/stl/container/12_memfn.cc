#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::function;
using std::bind;
using std::for_each;

class Number
{
public:
    Number(size_t data = 0)
    : _data(data){ }
    void print() const{
        cout << _data << "  ";
    }
    //判断是不是偶数
    bool isEven() const{
        return (0 == _data%2);
    }
    //判断是不是质数
    bool isPrime() const{
        if(1 == _data){
            return false;
        }
        for(size_t idx = 2; idx <= _data/2; ++idx){
            if(0 == _data % idx){
                return false;
            }
        }
        return true;
    }
private:
    size_t _data;
};

int add(int a){
    return a + 5;
}
void test0()
{
    vector<Number> vec;
    for(size_t idx = 1; idx != 30; ++idx){
        vec.push_back(Number(idx));
    }

    Number num;
    using namespace std::placeholders;
    function<void(Number)> f = bind(&Number::print,_1);
    function<void(Number*)> f1 = bind(&Number::print,_1);
    function<void(Number&)> f2 = bind(&Number::print,_1);
    // f(num);
    // f1(&num);
    // f2(num);
    
    // for_each(vec.begin(),vec.end(),f);
    // for_each(vec.begin(),vec.end(),f2);
    
    /* for_each(vec.begin(),vec.end(),bind(&Number::print,&num)); */
    cout << endl;
    //vec.erase(std::remove_if(vec.begin(),vec.end(),bind(&Number::isEven,_1)),vec.end());
    //for_each(vec.begin(),vec.end(),bind(&Number::print,_1));
    //bool(Number)const = std::mem_fn(&Number::isEven);
    function<bool(Number)> f3 = std::mem_fn(&Number::isEven);
    cout << f3(num) << endl;
    /* //bool(Number::*f5)()const = std::mem_fn(&Number::isEven); *///error
    vec.erase(std::remove_if(vec.begin(),vec.end(),std::mem_fn(&Number::isPrime)),vec.end());
    for_each(vec.begin(),vec.end(),std::mem_fn(&Number::print));

}

int main(){
    test0();
    return 0;
}

