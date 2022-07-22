#include "CommandLine.h"
#include "Collection.h"
#include "Order.h"

bool Process(Order &order)
{
    //doesn't matter
    return true;
}
int main()
{
    CommandLine CL;
    char test1[256];
    strncpy_s(test1, "first second",256);
    CL.oldway(test1);

    CL.newway("first second");

    Collection C;
    C.OldOne(10);
    C.OldTwo(11,3);
    C.OldTwo(8,4);
    C.OldThree();

    C.NewOne(10);
    C.NewTwo(11,3);
    C.NewTwo(8,4);
    C.NewThree();

    Order o;
    o.SetDiscount(10);
    o.SetDiscount(10);
    Process(o);

    return 0;
}