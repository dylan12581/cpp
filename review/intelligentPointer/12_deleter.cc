#include <my_header.h>
#include <iostream>
#include <string>
#include <memory>


using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
using std::shared_ptr;


struct FILECloser{
    void operator()(FILE* fp){
        if(fp){
            fclose(fp);
            cout << "fclose(fp)" << endl;
        }
    }
};

void test0()
{
    string msg = "hello,world\n";
    unique_ptr<FILE,FILECloser> up(fopen("res2.txt","a+"));
    //unique_ptr<FILE> up(fopen("res2.txt","a+"));
    //get函数可以从智能指针中获取到裸指针
    fwrite(msg.c_str(),1,msg.size(),up.get());
    //fclose(up.get());
}
void test1()
{
    string msg = "hello,world\n";
    FILECloser fc;
    shared_ptr<FILE> sp(fopen("res3.txt","a+"),fc);
    //unique_ptr<FILE> up(fopen("res2.txt","a+"));
    //get函数可以从智能指针中获取到裸指针
    fwrite(msg.c_str(),1,msg.size(),sp.get());
    //fclose(up.get());
}



int main()
{
    test1();
    return 0;
}

