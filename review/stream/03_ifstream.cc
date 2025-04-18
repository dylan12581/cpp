#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::cerr;
using std::istream;
using std::ifstream;
using std::string;

void checkStreamStatus(istream & is){
    cout << "is goodbit? " << is.good() << endl;
    cout << "is failbit? " << is.fail() << endl;
    cout << "is eofbit? " << is.eof() << endl;
    cout << "is badbit? " << is.bad() << endl;
}

void test0()
{
    ifstream ifs("./02_explicit.cc");
    checkStreamStatus(ifs);
    if(!ifs.good()){
        cerr << "ifstream open file failed" << "\n";
        return;
    }

    string word;
    while(ifs >> word){
        cout << word << " ";
    }
    cout << endl;
    ifs.close();
}
void test1(){
    ifstream ifs("./02_explicit.cc");
    checkStreamStatus(ifs);

    // 兼容C的写法
    char buff[100] = {0};
    while(ifs.getline(buff,sizeof(buff))){
        cout << buff << endl;
        memset(buff,0,sizeof(buff));
    }
    cout << ifs.eof() << endl;
    ifs.clear();
    cout << ifs.good() << "\n";
    ifs.seekg(0);

    string line;
    while(getline(ifs,line)){
        cout << line << endl;
    }
    ifs.close();

}
void readFile(){
    string fileName("./02_explicit.cc");
    ifstream ifs(fileName,std::ios_base::ate);

    if(!ifs){
        cerr << "ifs open file failed\n";
        return;
    }
    long length = ifs.tellg();
    cout << sizeof(long) << endl;
    cout << length << endl;

    char* pData = new char[length + 1]();
    ifs.seekg(0,std::ios::beg);
    ifs.read(pData,length);
    cout << pData << endl;
    delete  []pData;
    ifs.close();
}

int main()
{
    readFile();
    return 0;
}

