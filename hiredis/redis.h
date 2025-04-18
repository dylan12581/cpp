#ifndef  _REDIS_H_
#define  _REDIS_H_
#include <hiredis/hiredis.h>
#include <string>
using std::string;

class redis
{
public:
    redis();
    ~redis();
    bool connect(const string& host,int port);
    void set(string key,string value);
    string get(string key);
private:
    redisContext* _pConnect;
    redisReply* _pReply;
};

#endif

