#include <string.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Person{
public:
    Person(int age,const char* name)
        :_name(new char[strlen(name) + 1]())
         ,_age(age){
             strcpy(_name,name);
             cout << "Person(int ,const char*)" << endl;
         }
    Person(const Person& rhs)
        :_name(new char[strlen(rhs._name) + 1]())
         ,_age(rhs._age){
             cout << "Person(const Person&)" << endl;
             strcpy(_name,rhs._name);
         }
    ~Person(){
        cout << "~Person()" << endl;
        if(_name){
            delete []_name;
            _name = nullptr;
        }
    }
    Person& operator=(const Person& rhs){
        cout << "Person& operator=(const Person& rhs)" << endl;
        if(this != &rhs){
            delete []_name;
            _name = new char[strlen(rhs._name) + 1]();
            strcpy(_name,rhs._name);
            _age = rhs._age;
        }
        return *this;
    }
    void display(){
        cout <<  _name << " " <<   _age ;
    }
private:
    char* _name;
    int _age;
};
class Employee
:public Person{
public:
    Employee(const char* name,int age,const char* department,int salary)
        :Person(age,name)
         ,_department(new char[strlen(department) + 1]())
         ,_salary(salary){
             cout << "Employee(const char* ,int)" << endl;
             strcpy(_department,department);
         }
    Employee(const Employee& rhs)
        :Person(rhs)
         ,_department(new char[strlen(rhs._department) + 1]())
         ,_salary(rhs._salary){
             cout << "Employee(const Employee& rhs)" << endl;
             strcpy(_department,rhs._department);
         }
    Employee& operator=(const Employee& rhs){
        if(this != &rhs){
            cout << "Employee& operator=(const Employee& rhs)" << endl;
            Person::operator=(rhs);
            delete []_department;
            _department = new char[strlen(rhs._department) + 1]();
            strcpy(_department,rhs._department);
            _salary = rhs._salary;
        }
        return *this;
    }

    ~Employee(){
        if(_department){
            cout << "~Employee()" << endl;
            delete []_department;
            _department = nullptr;
        }
    }
    void display(){
        Person::display();
        cout  << _department << " " << _salary << endl;
    }
   static  double calcAvgSalary(vector<Employee> employees){
        double totalSalary = 0;
        if(employees.size() == 0){
            throw "employees is empty";
        }
        for(auto & ele:employees){
            totalSalary += ele._salary;
        }
        return totalSalary / employees.size();
    }

private:
    char* _department;
    int _salary;
};

void test0()
{
    vector<Employee> employees;
    Employee e1("zs",21,"design",5000);
    e1.display();
    Employee e2("ls",22,"sell",3000);
    e2.display();
    Employee e3 = e1;
    e3.display();
    e3 = e2;
    e3.display();
    employees.push_back(e1);
    employees.push_back(e2);
    employees.push_back(e3);
    for(auto & ele:employees){
        ele.display();
    }
    cout << Employee::calcAvgSalary(employees) << endl;
}

int main()
{
    test0();
    return 0;
}

