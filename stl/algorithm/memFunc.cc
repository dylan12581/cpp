#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::for_each;
using std::remove_if;
using std::mem_fn;
using std::bind;
using std::cout;
using std::endl;
using std::function;

class Number
{
public:
    Number(size_t data = 0)
    : _data(data)
    {

    }

    void print() const
    {
        cout << _data << "  ";
    }

    //判断是不是偶数
    bool isEven() const
    {
        return (0 == _data%2);
    }

    //判断是不是质数
    bool isPrime() const
    {
        if(1 == _data)
        {
            return false;
        }

        for(size_t idx = 2; idx <= _data/2; ++idx)
        {
            if(0 == _data % idx)
            {
                return false;
            }
        }

        return true;
    }
private:
    size_t _data;
};

void test0()
{
    vector<Number> vec;
    for(int idx = 0;idx < 5;++idx){
        vec.push_back(Number(idx));
    }


    using namespace std::placeholders;
    Number num;
    for_each(vec.begin(),vec.end(),mem_fn(&Number::print));
    //for_each(vec.begin(),vec.end(),bind(&Number::print,&num));
    
    function<void(Number&)> f = bind(&Number::print,_1);
    function<void(Number)> f2 = bind(&Number::print,_1);
    for_each(vec.begin(),vec.end(),f);
    //for_each(vec.begin(),vec.end(),bind(&Number::print,_1));


    // 遍历vector
    //for_each(vec.begin(),vec.end(),mem_fn(&Number::print));
    ////for_each(vec.begin(),vec.end(),&Number::print);//error
    //vec.erase(remove_if(vec.begin(),vec.end(),mem_fn(&Number::isEven)),vec.end());
    //for_each(vec.begin(),vec.end(),mem_fn(&Number::print));
}

int main()
{
    test0();
    return 0;
}

