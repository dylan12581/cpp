#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Building
{
public:
    virtual void sale() = 0;
    virtual string getQuality() = 0;
    virtual ~Building(){}
};

class WankeBuilding
: public Building
{
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
class Mediator{
public:
    Mediator(){
        Building* pa = new WankeBuilding();
        Building* pb = new HengdaBuilding();
        _buildings.push_back(pa);
        _buildings.push_back(pb);
        }
        Building* findBuilding(const string& quality){
            for(auto & building: _buildings){
                if(building->getQuality() == quality){
                    return building;
                }
            }
            return nullptr;
        }
        ~Mediator(){
            for(auto& building:_buildings){
                if(building){
                    delete building;
                }
            }
        }
private:
    vector<Building*> _buildings;
};

void test0(){
   string demand = "低品质";
    Mediator mediator;

    Building* pb = mediator.findBuilding(demand);
    if(pb){
        pb->sale();
    }else{
        cout << "没有符合要求的楼盘" << endl;
    }
//    delete pb;//double free

}
int main(){
    test0();
    return 0;
}
