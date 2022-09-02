#include<iostream>
#include<string>

using namespace std;

#define MAX_STUDENTS 3

class Student
{
    private:
         string name;
    public:
        Student(string name)
        {
            this->name=name;
        }
        void showStudentName()
        {
            cout<<"Student name associated to this object is "<<this->name<<"\n";
        }
};
class StudentDb
{
    private:
        string student_name[MAX_STUDENTS];
    public:
        StudentDb()
        {
            student_name[0]="Mark";
            student_name[1]="Jen";
            student_name[2]="Angie";
        }
        Student* getStudent(string name)
        {
            for(int i=0;i<MAX_STUDENTS;i++)
            {
                if(!name.compare(student_name[i]))
                {
                    return new Student(name);
                }
            }
            return NULL;
        }
};
int main(void)
{
    StudentDb sdb;
    Student* std1=sdb.getStudent("Mark");
    Student* std2=sdb.getStudent("Jen");
    Student* std3=sdb.getStudent("Angie");
    Student* std4=sdb.getStudent("Julie");

    if(std1!=NULL)
    {
        std1->showStudentName();
    }
      if(std2!=NULL)
    {
        std2->showStudentName();
    }
      if(std3!=NULL)
    {
        std3->showStudentName();
    }
      if(std4!=NULL)
    {
        std4->showStudentName();
    }
    else
    {
        cout<<"Invalid student\n";
    }
    return 0;
}