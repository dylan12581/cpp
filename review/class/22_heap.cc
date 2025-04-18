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
    
    
	void * operator new(size_t sz)
	{
        cout << "operator new" << endl;
		void * ret = malloc(sz);
		return ret;
	}
    
    
	void print() const
	{
		cout << "id:" << _id << endl
			<< "name:" << _name << endl;
	}

    void destroy(){
        delete this;
    }

	void operator delete(void * pointer)
	{
        cout << "operator delete" << endl;
		free(pointer);
	}
private:
	~Student()
	{
        cout << "~Student()" << endl;
        if(_name){
            delete [] _name;
            _name = nullptr;
        }
	}

	int _id;
	char * _name;
};

void test0()
{
	Student * stu = new Student(100, "Jackie");
	stu->print();
    stu->destroy();
    /* delete stu; */
}

int main(void){
    test0();
    return 0;
}

