#pragma once
#define CURRENT_YEAR 2022 //remember to update this each new year
class Employee
{
    private:
        char empName[100];
        int NameLength, empStartYear;
        double empSalary;
        bool empIsExempt;
    public:
        Employee(char const *name, double salary, int startyear, bool isexempt);
        void ReverseName(char *revName);
        void AdjustSalary();
};
