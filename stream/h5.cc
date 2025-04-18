#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;

int main(int argc,char* argv[])
{
    if(argc != 2){
        cerr << "argv nums error" << endl;
        return 0;
    }

    ifstream ifs(argv[1]);

    if(!ifs){
        cerr << "ifstream open file failed\n" << endl;
        return 0;
    }

    // 
    ifs.seekg(0,std::ios::end);
    int length = ifs.tellg();

    char* pdata = new char[length + 1]();
    ifs.seekg(0);
    
    ifs.read(pdata,length);

    cout << pdata << endl;

    delete[] pdata;

    ifs.close();


    return 0;
}

