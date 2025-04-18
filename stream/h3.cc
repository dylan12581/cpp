#include <string.h>
#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::string;

void checkStreamStatus(istream is)
{
    cout << "is goodbit" << is.good()<< endl;
    cout << "is failbit? " << is.fail() << endl;
    cout << "is eofbit? " << is.eof() << endl;
    cout << "is badbit? " << is.bad() << endl;
}

void test0()
{

    int num;

    cin >> num;

    if(!cin.good()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    }

    string word;
    cin >> word;
    cout << word;
}

int main()
{
    test0();
    return 0;
}

