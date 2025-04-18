#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class SafeFile{
public:
    SafeFile(FILE* fp)
        :_fp(fp)
    {
        cout << "SafeFile(FILE*)" << endl;
    }
    void write(const String& msg){
        fwrite(msg.)
    }

private:
    FILE* _fp;

};

void test0()
{
    cout << " " << endl;
}

int main()
{
    test0();
    return 0;
}

