#include <string.h>
#include <iostream>

using std::cout;
using std::endl;
// 栈上创建单例对象
class Computer{
public:
    static Computer& getInstance(const char* brand,int price){
        static Computer pInstance(brand,price);
        return pInstance;
    }
private:
    Computer(const char* brand,int price)
        :_price(price),_brand(new char[strlen(brand + 1)]())
    {
        cout << "Computer(char*,int)" << endl;
        strcpy(_brand,brand);
    }
    ~Computer(){
        if(_brand){
            delete[] _brand;
            _brand = nullptr;
        }
        cout << "~Computer()" << endl;
    }
    Computer(const Computer& rhs) = delete;
    //    :_price(rhs._price),_brand(new char[strlen(rhs._brand) + 1]())
    //{
    //    cout << "Computer(const Computer& lhs)" << endl;
    //    strcpy(_brand,rhs._brand);
    //}
    Computer operator=(const Computer& rhs) = delete;
   //{
   //     if(this != &rhs){
   //         delete []_brand;
   //         _brand = new char[strlen(rhs._brand) + 1]();
   //         strcpy(_brand,rhs._brand);
   //         _price = rhs._price;
   //     }
   //     return *this;
   // }
    // 平时可不写出
	//void * operator new(size_t sz)
	//{
    //    cout << "operator new" << endl;
	//	void * ret = malloc(sz);
	//	return ret;
	//}
    //// 平时可不写出
	//void operator delete(void * pointer)
	//{
    //    cout << "operator delete" << endl;
	//	free(pointer);
	//}

public:
    void display(){
        cout << _brand << " " << _price << endl;
    }

private:
    int _price;
    char* _brand;

};

void test0()
{
    Computer &cp = Computer::getInstance("xiaomi",900);
    cp.display();
}

int main()
{
    test0();
    return 0;
}

