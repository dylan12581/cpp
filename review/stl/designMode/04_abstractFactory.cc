#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

// A类型的抽象产品
class AbstractProductA{
public:
    virtual void show() = 0;
    virtual ~AbstractProductA() {}
};
// B类型的抽象产品
class AbstractProductB{
public:
    virtual void show() = 0;
    ~AbstractProductB() {}
};
class ProductA1
: public AbstractProductA{
public:
    virtual void show() override{
        cout << "void ProductA1::show()" << endl;
    }
};

class ProductA2
    : public AbstractProductA{
public:
    virtual void show() override{
        cout << "void ProductA2::show()" << endl;
    }
};
class ProductB1
    : public AbstractProductB{
public:
    virtual void show() override{
        cout << "void ProductB1::show()" << endl;
    }
};
class ProductB2
    : public AbstractProductB{
public:
    virtual void show() override{
        cout << "void ProductB2::show()" << endl;
    }
};
class AbstractFactory
{
public:
    virtual AbstractProductA *createProductA() = 0;
    virtual AbstractProductB *createProductB() = 0;
    virtual ~AbstractFactory() {}
};
class ConcreteFactory1
: public AbstractFactory{
public:
    AbstractProductA *createProductA() override{
        return new ProductA1();
    }
    AbstractProductB *createProductB() override{
        return new ProductB1();
    }
};
class ConcreteFactory2
    : public AbstractFactory{
public:
    AbstractProductA *createProductA() override{
        return new ProductA2();
    }
    AbstractProductB *createProductB() override{
        return new ProductB2();
    }
};
#if 0
void test0()
{
    AbstractFactory *factory1 = new ConcreteFactory1();
    AbstractProductA *productA = factory1->createProductA();
    AbstractProductB *productB = factory1->createProductB();
    productA->show();
    productB->show();
    delete factory1;
    cout << endl;
    AbstractFactory *factory2 = new ConcreteFactory2();
    productA = factory2->createProductA();
    productB = factory2->createProductB();
    productA->show();
    productB->show();
    delete factory2;
}
#endif
void test1(){
    unique_ptr<AbstractFactory> fac1(new ConcreteFactory1());
    unique_ptr<AbstractProductA> proa1(fac1->createProductA());
    unique_ptr<AbstractProductB> prob1(fac1->createProductB());
    proa1->show();
    prob1->show();


    unique_ptr<AbstractFactory> fac2(new ConcreteFactory2());
    unique_ptr<AbstractProductA> proa2(fac2->createProductA());
    unique_ptr<AbstractProductB> prob2(fac2->createProductB());
    proa2->show();
    prob2->show();

}

int main()
{
    test1();
    return 0;
}

