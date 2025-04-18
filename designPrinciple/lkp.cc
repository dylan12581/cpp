#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Building{
public:
    virtual void sale() = 0;
    virtual string getQuality() = 0;
    ~Building(){};
};
class WankeBuilding
:public Building{
public:
        WankeBuilding()
    : _quality("高品质")
    {

    }

    void sale() override
    {
        cout << "万科楼盘" << _quality << "的房子被出售" << endl;
    }

    string getQuality() override
    {
        return _quality;
    }

private:
    string _quality;
};
class HengdaBuilding
: public Building
{
public:
    HengdaBuilding()
    : _quality("低品质")
    {
    }

    void sale() override
    {
        cout << "恒大楼盘" << _quality << "的房子被出售" << endl;
    }

    string getQuality() override
    {
        return _quality;
    }
private:
    string _quality;
};

void test0()
{
    Building* pA = new WankeBuilding();
    Building* pB = new HengdaBuilding();
    string demand = "低品质";
    if(pA->getQuality() == demand){
        pA->sale();
    }
     if(pB->getQuality() == demand)
    {
        pB->sale();
    }
     delete pA;
     delete pB;
}

int main()
{
    test0();
    return 0;
}

