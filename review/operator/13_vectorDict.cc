#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;

struct Record
{
    Record(const string & word,int fre)
    : _word(word)
    , _frequency(fre)
    {}

	string _word;
	int _frequency;
};

bool operator<(const Record & lhs,const Record & rhs){
    return lhs._word < rhs._word;
}

class Dictionary
{
public:
    Dictionary(int capa){
        _dict.reserve(capa);
    }
    void read(const std::string &filename){
        ifstream ifs(filename);
        if(!ifs){
            cerr << "ifstream open file failed!" << endl;
            return;
        }

        /* string word; */
        /* while(ifs >> word){ */
        /* } */

        string line;
        while(getline(ifs,line)){
            istringstream iss(line);
            string word;
            while(iss >> word){
                //处理单词
                dealWord(word);

                //尝试加入到vector
                insert(word);
            }
        }

        //将元素进行排序
        sort(_dict.begin(),_dict.end());

        ifs.close();
    }

    void dealWord(string & word){
        auto it = word.begin();
        while(it != word.end()){
            if(!isalpha(*it)){
                it = word.erase(it);
            }else{
                ++it;
            }
        }
    }

    void insert(const string & word){
        if(word == string()){
            return;
        }

        size_t idx = 0;
        for(; idx < _dict.size(); ++idx){
            if(word == _dict[idx]._word){
                ++_dict[idx]._frequency;
                break;//如果找到了相同单词就结束遍历
            } 
        }

        if(idx == _dict.size()){
            _dict.push_back(Record(word,1));
        }
    }

    void store(const std::string &filename){
        ofstream ofs(filename);
        if(!ofs){
            cerr << "ofstream open file failed" << endl;
            return;
        }

        for(size_t idx = 0; idx < _dict.size(); ++idx){
            ofs << _dict[idx]._word << "  "
                << _dict[idx]._frequency << endl;
        }

        ofs.close();
    }
private:
    vector<Record> _dict;
};

void test0(){
    Dictionary dict(10000);
    dict.read("The_Holy_Bible.txt");
    dict.store("dictVector.dat");
}

int main(void){
    test0();
    return 0;
}

