#include<iostream>
#include<string>

using namespace std;

#define MAX_STUDENTS 3

class StudentMaster
{
    public:
        virtual void showStudentName()=0;
        virtual bool isNull()=0;
};
class Student:public StudentMaster
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
            cout<<"Student name associated to this object is "<< this->name << "\n";
        }
        bool isNull()
        {
            return false;
        }
};
class NullStudent:public StudentMaster
{
    public:
        void showStudentName()
        {
            cout<<"Invalid student\n";
        }
        bool isNull()
        {
            return true;
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
        StudentMaster* getStudent(string name)
        {
            StudentMaster *ob;
            for(int i=0;i<MAX_STUDENTS;i++)
            {
                if(!name.compare(student_name[i]))
                {
                    ob=new Student(name);
                    return ob;
                }
            }
            ob=new NullStudent();
            return ob;
        }
};
int main(void)
{
    StudentDb sdb;
    StudentMaster* std1=sdb.getStudent("Mark");
    StudentMaster* std2=sdb.getStudent("Jen");
    StudentMaster* std3=sdb.getStudent("Angie");
    StudentMaster* std4=sdb.getStudent("Julie");

    std1->showStudentName();
    std2->showStudentName();
    std3->showStudentName();
    std4->showStudentName();
    return 0;
}