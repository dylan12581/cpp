#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Student
{
public:
    Student(int id, const char * name)
        : _id(id)
        , _name(new char[strlen(name) + 1]())
    {
        strcpy(_name, name);
        cout << "Student()" << endl;
    }

    ~Student()
    {
        cout << "~Student()" << endl;
        if(_name){
            delete [] _name;
            _name = nullptr;
        }
    }

    void * operator new(size_t sz)
    {
        cout << "operator new" << endl;
        void * ret = malloc(sz);
        return ret;
    }
    void operator delete(void* pointer){
        cout << "operator delete" << endl;
        free(pointer);
    }
    void print() const
	{
		cout << "id:" << _id << endl
			<< "name:" << _name << endl;
	}
private:
    int _id;
    char * _name;
};
void test0(){
    Student* stu = new Student(100,"jackie");
    stu->print();
    delete stu;
}
void test1(){
    int * p = new int(10);
    cout << *p << endl;
    delete p;
    p = nullptr;
}

int main(void){
    test0();
    return 0;
}

