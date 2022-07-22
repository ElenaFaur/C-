#include "Collection.h"
#include<algorithm>
using std::vector;

void Collection::OldOne(int howmany)
{
    OldNumbers=new int[howmany];
    count=howmany;
}
void Collection::OldTwo(int repeat, int value)
{
    if(repeat>count)
        repeat=count;
    while(repeat--)
        OldNumbers[repeat]=value;
}
void Collection::OldThree()
{
    delete[] OldNumbers;
}
void Collection::NewOne(int howmany)
{
    std::generate_n(back_inserter(NewNumbers),howmany,[](){return -1;});
}
void Collection::NewTwo(int repeat, int value)
{
    if(repeat>NewNumbers.size())
        repeat=NewNumbers.size();
    fill(begin(NewNumbers),begin(NewNumbers)+repeat,value);
}
void Collection::NewThree()
{

}