#ifndef _QUERY_BASE_H_
#define _QUERY_BASE_H_

#include "Query.hh"

class Query_base{
    //friend class Query;
    public:
    //private:
    virtual
    QueryResult eval( TextQuery& t)const = 0;
    virtual 
    string repl()const = 0;
    virtual
    ~Query_base(){};
};


#endif
