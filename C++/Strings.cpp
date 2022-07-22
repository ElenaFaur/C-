#include<iostream>
#include<cstring>
#include "Employee.h"
#define CURRENT_YEAR 2022 //remember to update this each new year
using namespace std;

int main()
{
    char empName[100];
    int NameLength,empStartYear;
    double empSalary;
    bool empIsExempt;

    strcpy(empName,"Kate Gregory"); //cout<<empName<<" "<<endl;
    NameLength=strlen(empName); //cout<<NameLength<<" ";
    empSalary=1;
    empStartYear=1986;
    empIsExempt=false;

    Employee e{"Kate Gregory",1,1986,false};

    char *fname=strtok(empName," ");
    char *lname=strtok(NULL," ");

    char revName[100];
    strcpy(revName,lname);
    strcat(revName,", ");
    strcat(revName,fname); //cout<<revName;

    char revName2[100];
    e.ReverseName(revName2); //cout<<revName2;

    if(!empIsExempt)
    {
        empSalary*=1.05;
    }
    if((CURRENT_YEAR-empStartYear)%5==0)
    {
        empSalary*=1.20;
    }
    e.AdjustSalary();
}