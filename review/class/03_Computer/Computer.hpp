#pragma once
#include <string.h>
#include <iostream>

class Computer
{
public:
    Computer() {}
    ~Computer() {}
	//成员函数
	void setBrand(const char * brand);//设置品牌

	void setPrice(float price);//设置价格

    void print();//打印信息
private:
	//数据成员
	char _brand[20];
	float _price;
};

inline void Computer::setBrand(const char * brand)
{
    strcpy(_brand, brand);
}
inline
void Computer::setPrice(float price)
{
    _price = price;
}
inline 
void Computer:: print(){
    std::cout << _brand << std::endl;
    std::cout << _price << std::endl;
}

