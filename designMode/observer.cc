#include <iostream>
#include <string>
#include <list>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::unique_ptr;

class Observer
{
public:
    //更新状态的函数
    virtual void update(int x) = 0;
    virtual ~Observer() {}
};

class ConcreateObserverA
: public Observer
{
public:
    ConcreateObserverA(const string &name)
    : _name(name)
    {
    }

    virtual void update(int x) override
    {
        cout << "ConcreateObserverA " << _name << ", x = " << x << endl;
    }
private:
    string _name;
};

class ConcreateObserverB
: public Observer
{
public:
    ConcreateObserverB(const string &name)
    : _name(name)
    {
    }

    virtual void update(int x) override
    {
        cout << "ConcreateObserverB " << _name << ", x = " << x << endl;
    }
private:
    string _name;
};
// 订阅主题
class Subject
{
public:
    virtual void attach(Observer *pObserver) = 0;
    virtual void detach(Observer *pObserver) = 0;
    virtual void notity() = 0;

    virtual ~Subject(){}
};
class ConcreateSubject
: public Subject
{
public:
    //添加观察者
    virtual void attach(Observer *pObserver) override
    {
        if(pObserver)
        {
            _obtList.push_back(pObserver);
        }
    }

    //删除观察者
    virtual void detach(Observer *pObserver) override
    {
        if(pObserver)
        {
            _obtList.remove(pObserver);
        }
    }

    //当主题的状态发生变更之后，就发通知
    virtual void notity() override
    {
        //遍历观察者
        for(auto &ob : _obtList)//list中存放的都是基类指针但指向的是派生类的对象
        {
            ob->update(_status);//肯定会体现多态
        }
    }

    void setStatus(int status)
    {
        _status = status;
    }

    int getStatus() const
    {
        return _status;
    }
private:
    list<Observer *> _obtList;
    int _status;
};
void test(){
      //创建具体的观察者
    unique_ptr<Observer> pa(new ConcreateObserverA("lili"));
    unique_ptr<Observer> pb(new ConcreateObserverB("lucy"));
    //创建主题的对象
    unique_ptr<ConcreateSubject> psub(new ConcreateSubject());

    //将观察者添加到主题中(将两个观察者添加到了主题中)
    psub->attach(pa.get());
    psub->attach(pb.get());

    //主题的状态发生变更
    psub->setStatus(1);

    //发通知，告知所有的观察者，主题的状态发生了变更
    psub->notity();

    cout << endl << endl;
    //加入现在观察者B不想观察主题，就需要删除
    psub->detach(pb.get());

    //当主题的状态发生变更
    psub->setStatus(2);
    //发通知，告知所有的观察者，主题的状态发生了变更
    psub->notity();
}
int main(){
    test();
    return 0;
}
