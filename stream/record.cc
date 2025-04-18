#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;
using std::to_string;

struct Record{
    string _word;
    int _frequency;
};
class Dictionary{
public:
    void read(const string& filename);
    void store(const string& filename);
private:
    vector<Record> _dict;

};
/* 去除字母外的其他字符就是非法 */
string getResult(const string& word){
    string result;
    for(auto & ch : word){
        if(isalpha(ch)){
            result += ch;
        }
    }
    // word.erase();
    return result;
}

void Dictionary::read(const string& filename){
    // 创建文件流对象
    ifstream ifs(filename);
    if(!ifs){
        cerr << "ifstream open file failed" << endl; 
        return;
    }
    // 逐行读取文件内容
    string line;
    while(getline(ifs,line)){
        istringstream iss(line);
        string word;
        string result;
        while(iss >> word){
            // 非法字符，下一次循环
            result = getResult(word);
            int flag = 0;
            for(auto &rec : _dict){
                if(rec._word == result){
                    rec._frequency++;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                Record newRecord;
                newRecord._word = result;
                newRecord._frequency = 1;
                _dict.push_back(newRecord);
            }
        }
    }
}
void Dictionary:: store(const string& filename){

    ofstream ofs(filename,std::ios::app);
    ostringstream oss;
    for(auto & rec : _dict){
        ofs << "|" << rec._word << " " << to_string(rec._frequency) << "|" << endl;
    }
    ofs.close();
}


void test0(const string& filename,const string& filename2)
{
    Dictionary dict;
    dict.read(filename);
    dict.store(filename2);
}

int main(int argc,char* argv[])
{
    if(argc != 3){
        cerr << "worng argc!" << endl;
        return -1;
    }
    test0(argv[1],argv[2]);

    return 0;
}
