#pragma once
#include <vector>

class Collection
{
    private:
        int * OldNumbers; //could be any type at all
        int count;
        std::vector<int> NewNumbers;
    public:
        void OldOne(int howmany);
        void OldTwo(int repeat, int value);
        void OldThree();
        void NewOne(int howmany);
        void NewTwo(int repeat, int value);
        void NewThree();
};