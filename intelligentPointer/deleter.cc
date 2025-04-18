#include <iostream>
#include <string>
#include <memory>
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
using std::shared_ptr;

void test0(){
    string msg("hello world\n");
    FILE* fp = fopen("wd.txt","a+");
    fwrite(msg.c_str(),1,msg.size(),fp);
    fclose(fp);
}
void test1(){
    string msg("hello world\n");
    FILE* fp = fopen("wd.txt","a+");
    unique_ptr<FILE> up(fp);
    fwrite(msg.c_str(),1,msg.size(),fp);// 如果没有fclose，内容不会冲刷到文件流中
    fclose(fp);// double free
}
struct FileClose{
    void operator()(FILE* fp){
        if(fp){
            fclose(fp);
            cout << "fclose(fp)" << endl;
        }
    }
};
void test2(){
    string msg("hello world\n");
    unique_ptr<FILE,FileClose> up(fopen("wd.txt","a+"));
    fwrite(msg.c_str(),1,msg.size(),up.get());
}
void test3(){
    string msg("hello world\n");
    shared_ptr<FILE> sp(fopen("wd.txt","a+"),FileClose());
    fwrite(msg.c_str(),1,msg.size(),sp.get());
}
int main(){
    test1();
    return 0;
}