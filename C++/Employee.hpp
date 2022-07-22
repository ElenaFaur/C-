#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include<string>
using namespace std;
class Employee
{
    private: 
            string firstname, lastname;
            int salary;
    public:
            Employee(string first, string last, int sal): firstname(first),lastname(last),salary(sal){}
            int getSalary()
            { return salary; }
            string getSortingName()
            { return lastname + ", " + firstname;}
};
#endif;