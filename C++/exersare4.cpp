#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>

using namespace std;

int main()
{
    vector <int> a{1,2,3,4,5};
    vector <int> b{1,2,0,4};

    bool same=a.size()==b.size();// cout<<same<<" ";
    for(size_t i=0;i<a.size() && same; i++)
    {
        if(a[i]!=b[i])
         same=false;
    }
    //cout<<same<<" ";
    same=equal(begin(a),end(a),begin(b),end(b));
    //cout<<same<<" ";
    auto firstchange=mismatch(begin(a),end(a),begin(b));
    int avalue=*(firstchange.first);// cout<<avalue<<" ";
    int bvalue=*(firstchange.second);// cout<<bvalue<<" ";
    auto distance=firstchange.first-begin(a);// cout<<distance<<" ";
    
    int total=0;
    for(int i:a)
    {
        total+=i;
    }
   // cout<<total<<" ";
    total=accumulate(begin(a),end(a),0);  //cout<<total<<" ";
    total=accumulate(begin(a),end(a),0,[](int total, int i){if(i%2==0) return total+i; return total;});
   // cout<<total<<" ";
    total=accumulate(begin(a),end(a),1,[](int total,int i){return total*i;});
   // cout<<total<<" ";

   vector<string> words{"one","two","three"};
   auto allwords=accumulate(begin(words),end(words),string{}); cout<<allwords<<" ";
   int length=allwords.size(); cout<<length<<" ";
   allwords=accumulate(begin(words),end(words),string{"words:"},[](const string& total,string &s){return total+" "+s;});
   cout<<allwords<<" ";
   length=allwords.size();

   string s=accumulate(begin(a),end(a),string{"The numbers are: "},[](const string &total,int i){return total+" "+to_string(i);});
   cout<<s<<" ";

   b=a;
   for(auto it=begin(b); it!=end(b);it++)
   {  *it=0;  }
   for(auto &i:b)
   {  i=1;  }
   for_each(begin(b),end(b),[](int &elem){elem=2;});
}