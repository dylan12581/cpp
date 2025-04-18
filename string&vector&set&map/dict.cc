#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::map;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::pair;


// 处理一个单词
void dealWord(string &word){
    string::iterator it = word.begin();
    while(it != word.end()){
        if(!isalpha(*it)){
            it = word.erase(it);
        }else{
            ++it;
        }
    }
}
class Dictionary{
public:

    void read(const string& filename){
        ifstream ifs(filename);
        if(!ifs){
            cerr << "ifstream open file failed" << endl;
            return;
        }
        string line;
        while(getline(ifs,line)){
            istringstream iss(line);
            string word;
            while(iss >> word){
                dealWord(word);
                // 跳过空字符
                if(word == string()){
                    continue;
                }
                // pair<map<string,int>::iterator,bool> ret = _dict.insert({word,1});
                // if(ret.second == 0){
                //     ++ret.first->second;
                // }
                ++_dict[word];
            }
        }
    }
    void store(const string& filename){
        ofstream ofs(filename);
        if(!ofs){
            cerr << "ofstream open failed " << endl;
            return;
        }
        for(auto & ele:_dict){
            ofs << "|" << ele.first << " " << ele.second << "|" << endl;
        }
        map<string,int>::iterator it = _dict.begin();
        for(;it != _dict.end();++it){
            cout << it->first << " " << it->second << endl;
        }
        ofs.close();
    }
private:
    map<string,int> _dict;
};

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
