#ifndef _QUERY_H_
#define _QUERY_H_

#include "TextQuery.hh"
#include "andQuery.hh"

class Query_base;
class Query
{
public:
    Query(const string &sought);
    Query(shared_ptr<Query_base> sp)// 隐式转换时使用，相当于1直接转换成Point
    :_sp(sp)
    {

    }

    QueryResult eval(TextQuery &t) const;
    
    string repl()const;

    friend
    Query operator&(const Query& lhs,const Query& rhs);
private:
    shared_ptr<Query_base> _sp;// 基类指针
};

Query operator&(const Query& lhs,const Query& rhs){
    shared_ptr<Query_base> sp(new andQuery(lhs,rhs)());
    return sp;
    // 下面写法相同
    //return shared_ptr<Query_base> sp(new andQuery(lhs,rhs)());
}

#endif
