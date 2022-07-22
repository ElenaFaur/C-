#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main()
{
    vector<int> v{2,7,1,6,2,-2,4,0};

    int twos=0,odds=0;
    int const target=2;

    twos=count(v.begin(),v.end(),target);
    cout<<"twos: "<<twos;

    odds=count_if(begin(v),end(v),[](auto elem){return elem%2!=0;});
    cout<<"\nodds: "<<odds;

    map<int,int> monthlengths{{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
    int longmonths=count_if(begin(monthlengths),end(monthlengths),[](auto elem){return elem.second==31;});
    cout<<"\nnr de luni cu 31 de zile: "<<longmonths;

    bool allof,noneof,anyof;
   /* allof=(odds==v.size());
    noneof=(odds==0);
    anyof=(odds>0);*/

    allof=all_of(begin(v),end(v),[](auto elem){return elem%2!=0;});
    noneof=none_of(begin(v),end(v),[](auto elem){return elem%2!=0;});
    anyof=any_of(begin(v),end(v),[](auto elem){return elem%2!=0;});

    cout<<"\nallof: "<<allof<<"\nnoneof: "<<noneof<<"\nanyof: "<<anyof;
    return 0;
}