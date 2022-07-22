#pragma once
class Discount{

    private:
        int amount;
    public:
        Discount(int amt) : amount(amt) {}
        int get_amount(){
            return amount;
        }
};