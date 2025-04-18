#include "redis.h"
#include <memory>
#include <iostream>

using std::cout;
using std::endl;
using std::unique_ptr;

void test0()
{
    unique_ptr<redis> cliPtr(new redis());
    if (!cliPtr->connect("127.0.0.1", 6379))
    {
        std::cerr << "connect error!" << endl;
        return;
    }
    cliPtr->set("k11", "hello");
    cout << cliPtr->get("k11") << endl;
}

int main()
{
    test0();
    return 0;
}
