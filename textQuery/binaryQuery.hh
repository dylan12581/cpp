#ifndef _BINARY_QUERY_H_
#define _BINARY_QUERY_H_
#include "Query_base.hh"

class binaryQuery
:public Query_base
{
public:
    binaryQuery(const Query& lhs,const Query& rhs,const string& ops) 
    :_lhs(lhs),_rhs(rhs),_ops(ops){}

    string repl()const{
        return "(" + _lhs.repl() + _ops + _rhs.repl() + ")";
    }
private:
    Query _lhs;
    Query _rhs;
    string _ops;
};

#endif
