#ifndef _WORDQUERY_H
#define _WORDQUERY_H

#include "Query_base.hh"

class WordQuery
    : public Query_base
{
public:
    WordQuery(const string &sought);

    QueryResult eval(TextQuery &t) const;
    
    string repl()const;
private:
    string _queryWord;
};

#endif
