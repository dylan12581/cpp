#include <my_header.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class SafeFile{
public:
    SafeFile(FILE* fp)
        :_fp(fp){
            cout << "SafeFile(FILE* fp)" << endl;
        }
    void write(const string& msg){
        fwrite(msg.c_str(),1,msg.size(),_fp);
    }
    ~SafeFile(){
            cout << "~SafeFile(FILE* fp)" << endl;
            if(_fp){
                fclose(_fp);
                cout << "fclose(_fp)" << endl;
            }
    }
private:
    FILE* _fp;
};

void test0()
{
    string msg("hello");
    SafeFile sf(fopen("wd.txt","a+"));
    sf.write(msg);
}

int main()
{
    test0();
    return 0;
}

