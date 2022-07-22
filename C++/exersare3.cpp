#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>//for abs
#include<random>
#include "Employee.hpp"

using namespace std;
int main()
{
    vector<int> v{4,1,0,1,-2,3,7,-6,2,0,0,-9,9};
    auto v2=v;
    sort(begin(v2),end(v2));
    sort(begin(v2),end(v2),[](int elem1, int elem2){return elem1>elem2;});
    sort(begin(v2),end(v2),[](int elem1, int elem2){return abs(elem1)>abs(elem2);});
   /* for(auto i:v2)
    {
        cout<<i<<" ";
    }*/
    cout<<endl;
    vector<Employee> staff{
        {"Kate","Gregory",1000},
        {"Obvious","Artificial",2000},
        {"Fake","Name",1000},
        {"Alan","Turing",2000},
        {"Grace","Hopper",2000},
        {"Anita","Borg",2000}
    };
    sort(begin(staff),end(staff),[](Employee e1, Employee e2){return e1.getSalary()<e2.getSalary();});
    sort(begin(staff),end(staff),[](Employee e1, Employee e2){return e1.getSortingName()<e2.getSortingName();});

    sort(begin(staff),end(staff),[](Employee e1, Employee e2){return e1.getSortingName()<e2.getSortingName();});
    stable_sort(begin(staff),end(staff),[](Employee e1, Employee e2){return e1.getSalary()<e2.getSalary();});
   /* for(auto i: staff)
    {
        cout<<i.getSortingName()<<" "<<i.getSalary()<<endl;
    }*/
    auto sorted=is_sorted(begin(v2),end(v2));
    sorted=is_sorted(begin(v2),end(v2),[](int elem1, int elem2){return abs(elem1)>abs(elem2);});

    //cout<<sorted;
    /* for(auto i:v2)
    {
        cout<<i<<" ";
    }*/
    cout<<endl;
    int high=*(max_element(begin(v),end(v))); //cout<<high<<endl;
    int low=*(min_element(begin(v),end(v))); //cout<<low<<endl;
    
    sort(begin(v2),end(v2));

    low=*begin(v2); //cout<<low<<endl;
    high=*(end(v2)-1); //cout<<high<<endl;
    int positive=*upper_bound(begin(v2),end(v2),0); //cout<<positive<<endl;

    sort(begin(staff),end(staff),[](Employee e1, Employee e2){return e1.getSortingName()<e2.getSortingName();});
    
    /*for(auto i: staff)
    {
        cout<<i.getSortingName()<<" "<<i.getSalary()<<endl;
    }*/

    auto p=lower_bound(begin(staff),end(staff),"Gregory, Kate",[](Employee e1, string n){return e1.getSortingName()<n;});
    //cout<<"\n"<<p->getSortingName()<<" ";
    int sal=p->getSalary(); //cout<<sal;

    random_device randomdevice;
    mt19937 generator(randomdevice());

    shuffle(begin(v2),end(v2),generator);
    partial_sort(begin(v2), find(begin(v2),end(v2),4),end(v2));
   /* for(auto i:v2)
    {
        cout<<i<<" ";
    }*/
    int breakpoint=*is_sorted_until(begin(v2),end(v2));
   // cout<<"\n"<<breakpoint;
   vector<int> v3(3);
   partial_sort_copy(begin(v),end(v),begin(v3),end(v3));
  /* for(auto i:v3)
   {
      cout<<i<<" ";
   }*/
   v2={1,5,4,2,9,7,3,8,2};
   int i=*(begin(v2)+4); cout<<i<<endl;
   nth_element(begin(v2),begin(v2)+4,end(v2));
   for(auto i:v2)
   {
    cout<<i<<" ";
   }
   i=*(begin(v2)+4); cout<<"\n"<<i;
}