#include <iostream>
#include <string>
#include <list>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::unique_ptr;

class Observer{
public:
    virtual void update(int x) = 0;
    virtual ~Observer(){}
};
class ConcreteObserverA
:public Observer
{
public:
    ConcreteObserverA(const string& name)
        :_name(name)
    {}
    void update(int x)override{
        cout << "ConcreteObserverA" << _name << ",X=" << x << endl;
    }
private:
    string _name;
};
class ConcreteObserverB
:public Observer
{
public:
    ConcreteObserverB(const string& name)
        :_name(name)
    {}
    void update(int x)override{
        cout << "ConcreteObserverB" << _name << ",X=" << x << endl;
    }
private:
    string _name;
};
// 订阅主题
class Subject{
public:
    virtual void attach(Observer* pObserver) = 0;
    virtual void detach(Observer* pObserver) = 0;
    virtual void notify() = 0;
    virtual ~Subject(){};
};
class ConcreteSubject
:public Subject
{
public:
    void attach(Observer* pObserver)override{
        if(pObserver){
            _obList.push_back(pObserver);
        }
    }
    void detach(Observer* pObserver)override{
        if(pObserver){
            _obList.remove(pObserver);
        }
    }
    void notify()override{
        for(auto& ob:_obList){
            ob->update(_status);
        }
    }
    void setStatus(int status){
        _status = status;
    }
    int getStatus()const{
        return _status;
    }
    ~ConcreteSubject(){}
private:
     list<Observer*> _obList;
     int _status;
};


void test0()
{
    unique_ptr<Observer> pa(new ConcreteObserverA("lili"));
    unique_ptr<Observer> pb(new ConcreteObserverB("shy"));
    unique_ptr<ConcreteSubject> psub(new ConcreteSubject());

    psub->attach(pa.get());
    psub->attach(pb.get());
    psub->setStatus(1);
    psub->notify();

    cout << "------" << endl;
    psub->detach(pb.get());
    psub->setStatus(2);
    psub->notify();
}

int main()
{
    test0();
    return 0;
}

