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

    string line;
    while(getline(ifs,line)){
        cout << line << endl;
    }

    ifs.close();


    return 0;
}

