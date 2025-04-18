#ifndef __REDIS_H__
#define __REDIS_H__

#include <hiredis/hiredis.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

using std::string;

class Redis
{
public:
    Redis();
    ~Redis();
    bool connect(const string &host, int port);
    void set(string key, string value);
    string get(string key);

private:
    redisContext *_pConnect;
    redisReply *_pReply;
};

#endif

