#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Record{
    int _fre;
    string _word;
};
 class Dictionary{
  public:
      Dictionary()
        :_dict(vector<Record>())
      {          

      }
      void print(){
          for(auto ele& : vector<Record>)
          
      }
  private:
      vector<Record> _dict;
 
  };


void test0()
{
    Dictionary dir;
}

int main()
{
    test0();
    return 0;
}

