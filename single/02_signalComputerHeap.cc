#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{
public:
    static Computer* getInstant()// 静态函数,不需要对象就能够访问
    {
        if(_pInstant == nullptr){// 防止每次调用都new
        _pInstant = new Computer("xiaomi",9000);
        }
        return _pInstant;
    }
    void init(const char* brand,double price){
        // delete []_pInstant->_brand;
        delete []_brand;
        _price = price;
        //_pInstant->_brand = new char[strlen(brand) + 1]();// 实拷贝
        _brand = new char[strlen(brand) + 1]();// 实拷贝
        //strcpy(_pInstant->_brand,brand);
        strcpy(_brand,brand);
    }
    static void destroy(){
        if(_pInstant){// 防止多次delete空指针的问题
            delete _pInstant;
            _pInstant = nullptr;
            cout << "destroy" << endl;
        }
    }
    void print() const{
        //const成员函数中不允许修改对象的数据成员
        //_brand是一个指针
        //const的属性施加在指针，体现在地址值不能修改
        //也就是不能修改
        /* _price = 1; */
        /* _brand = new char[10](); */

        //将_brand设为const char *,才能避免这样的修改
        //但是这样声明会使_brand初始化后在任何地方
        //都不能修改内容，不合理
        /* _brand[0] = 'X';//只能人为避免 */
        cout << "brand:" << this->_brand << endl;
        cout << "price:" << this->_price << endl;
    }
    void release(){
        if(_brand){
            delete []_brand;
            _brand = nullptr;
        }
    }
private:
    // 构造函数私有,析构函数私有
     Computer(const char * brand,double price)
    : _brand(new char[strlen(brand) + 1]())
    , _price(price)
    {
        strcpy(_brand,brand);
        cout << "Computer(const char *,double)" << endl;
    }
    // 析构函数
    ~Computer(){
    cout << "~Computer()" << endl;
    release();
    // if(_brand){
    //     delete [] _brand;
    //     _brand = nullptr;
    //     }
    }
   char* _brand;
   double _price;
    static Computer* _pInstant;// 实例的指针
};
Computer* Computer::_pInstant = nullptr;// 初始化静态
void test0()
{
    //单例模式的规范写法
    //直接使用getInstance函数的返回值（指针）
    //来控制单例对象
    Computer::getInstant()->print();
    Computer::getInstant()->init("apple",10000);
    Computer::getInstant()->print();
    Computer::getInstant()->init("apple",100);
    Computer::getInstant()->print();
    //即使多次调用destroy函数也不会出错double_free的问题
    Computer::destroy();
    Computer::destroy();
    Computer::destroy();
}

int main()
{
    test0();
    return 0;
}

