#include <iostream>

using std::cout;
using std::endl;

int x = 10;
int* intPtr = &x;
char* charPtr = reinterpret_cast<char*>(intPtr);

cout << "intPtr: " << intPtr << endl;
cout << "charPtr: " << static_cast<void*>(charPtr) << endl;
