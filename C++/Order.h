#pragma once
#include "Discount.h"
#include<memory>

class Order
{
    private:
        std::unique_ptr<Discount> discount;
    public:
        void SetDiscount(int amt);
        int getDiscountAmount();
};