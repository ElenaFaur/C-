#include "Order.h"
using std::make_unique;

void Order::SetDiscount(int amt)
{
   discount=make_unique<Discount>(amt);
}
int Order::getDiscountAmount()
{
    if(discount)
        return discount->getAmount();
    return 0;
}
