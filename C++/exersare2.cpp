#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v{2,4,6,6,1,3,-2,0,11,2,3,2,4,4,2,4};
    string s{"Hellaaauu dc nu mere am hmm?"};
    //find the first zero in the collection
    auto result=find(begin(v),end(v),0); //cout<<"\n result: "<<*result;
    int weLookedFor=*result; //cout<<"\nweLookedFor: "<<weLookedFor;

    //find the first 2 after that zero
    result=find(result,end(v),2); //cout<<"\n result: "<<*result;
    if(result!=end(v))
    {
        weLookedFor=*result;
    }
    //cout<<"\nweLookedFor: "<<weLookedFor;

    //find the first a
    auto letter=find(begin(s),end(s),'a'); //cout<<"\nletter: "<<*letter;
    char a=*letter;  //cout<<"\na= "<<a;

    //find first odd value
    result=find_if(begin(v),end(v),[](auto elem){return elem%2!=0;}); //cout<<"\n result: "<<*result;
    weLookedFor=*result; //cout<<"\nweLookedFor: "<<weLookedFor;

    //find first even value
    result=find_if_not(begin(v),end(v),[](auto elem){return elem%2!=0;}); //cout<<"\n result: "<<*result;
    weLookedFor=*result; //cout<<"\nweLookedFor: "<<weLookedFor;

    vector<int> primes{1,2,3,5,7,11,13};
    result=find_first_of(begin(v),end(v),begin(primes),end(primes)); //cout<<"\n result: "<<*result;
    weLookedFor=*result; //cout<<"\nweLookedFor: "<<weLookedFor;

    vector<int> subsequence{2,4};
    result=search(begin(v),end(v),begin(subsequence),end(subsequence));
    weLookedFor=*result; //cout<<"\nweLookedFor: "<<weLookedFor;
    result++; /*cout<<"\nresult dupa primul ++: "<<*result;*/ result++;
    int six=*result; //cout<<"\nsix: "<<six;

    string am="am";
    letter=search(begin(s),end(s),begin(am),end(am)); //cout<<"\nletter: "<<*letter;
    a=*letter; /*cout<<"\na= "<<a;*/ letter++; //cout<<"\nletter: "<<*letter;

    result=find_end(begin(v),end(v),begin(subsequence),end(subsequence)); //cout<<"\nresult:"<<*result;
    result++; /*cout<<"\nresult:"<<*result;*/ result++; //cout<<"\nresult:"<<*result;
    if(result !=end(v))
    {
        weLookedFor=*result;
    }
    //cout<<"\nweLookedFor: "<<weLookedFor;

    result=search_n(begin(v),end(v),2,4); //cout<<"\nresult: "<<*result;
    result--; //cout<<"\nresult: "<<*result;
    int two=*result; //cout<<"\ntwo: "<<two;

    result=adjacent_find(begin(v),end(v)); cout<<"\nresult: "<<*result;
    six=*result;
    result++; cout<<"\nresult: "<<*result;
    six=*result;
}