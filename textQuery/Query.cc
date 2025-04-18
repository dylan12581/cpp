#include "Query.hh"
#include "WordQuery.hh"

Query::Query(const string &sought)
	: _sp(new WordQuery(sought)) {}

QueryResult Query::eval(TextQuery &t) const
{
	return _sp->eval(t);// 多态的体现
}
string Query::repl()const{
	return _sp->repl();
}
