#include<iostream>

using namespace std;

int foo(int a, int /*unused*/) // no longer need second int
{
    return a*a;
}

bool final()
{ return true; }

int main()
{
   int final=3;
   auto override=2;

   int i=0,j=2,k=3;

   auto u=1u; cout<<u<<endl;

   auto f=foo(i,j); cout<<f<<endl;
   if(f==j)
     j++;
   if(f<u)
     f=3;
     u-=f;
    cout<<f<<" "<<j<<" "<<u;

    unsigned int really=-2;
    really=-k;
    if(f>j)
        really++;
        return i;

    if(i<f)
        j++;
        i++;
}