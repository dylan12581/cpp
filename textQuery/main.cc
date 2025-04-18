#include "WordQuery.hh"
#include "Query.hh"
#include "Query_base.hh"
#include "TextQuery.hh"
#include "QueryResult.hh"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;


#if 0
int main(int argc,char** argv)
{
    if(argc != 2){
        cerr << "argc nums wrong" << endl;
        return 0;
    }
    TextQuery file = get_file(argv[1]);
    string sought;
    cin >> sought;
    Query name(sought);
    QueryResult result = name.eval(file);
    print(cout,result);

    return 0;
}
#endif
int main(int argc,char** argv)
{
    if(argc != 3){
        cerr << "argc nums wrong" << endl;
        return 0;
    }
    TextQuery file = get_file(argv[1]);
    string sought1,sought2;
    cin >> sought1 >> sought2;
    Query  andQ = Query(sought1) & Query(sought2);
    QueryResult result = andQ.eval(file);
    print(cout,result);
    
    // 分别打印每个单词的出现情况
    result = name1.eval(file);
    print(cout,result);

    result = name2.eval(file);
    print(cout,result);

    return 0;
}
