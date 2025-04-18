#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{
public:
    void setBrand(const char* brand){
        strcpy(_brand,brand);
    }
    void setPrice(float price){
        _price = price;
    }
    void print(){
        cout << _brand << endl;
        cout << _price << endl;
    }
private:
    char _brand[20];
    float _price;

};
void test0(){
    Computer pc;
    pc.setBrand("xiaomi");
    pc.setPrice(5000);
    pc.print();
}
typedef struct{
    int number;
    char name[20];
    int score;
    void display(){
        cout << number << " " << name << " " << score << endl;
    } 
}Student;
void test1(){
    Student s1 = {1,"zs",100};
    s1.display();
}

int main()
{
    test1();
    return 0;
}

