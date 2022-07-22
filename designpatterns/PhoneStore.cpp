#include<iostream>
using namespace std;

class BasicPhone
{
    private:
        uint16_t batteryCapacity, ramSize;
    public:
        BasicPhone(uint16_t batCap, uint16_t ram)
        {
            this->batteryCapacity=batCap;
            this->ramSize=ram;
        }
        void showMobilePhoneSpecifications()
        {
            cout<<"Mobile Phone Specifications:\n";
            cout<<"Phone Type: Basic Phone\nBattery Capacity: "<<this->batteryCapacity<<"mAh\nRAM Size: "<<this->ramSize<<" GB\n";
        }
};
class SmartPhone
{
    private:
    uint16_t batteryCapacity, ramSize;
    public:
        SmartPhone(uint16_t batCap, uint16_t ram)
        {
            this->batteryCapacity=batCap;
            this->ramSize=ram;
        }
        void showMobilePhoneSpecifications()
        {
            cout<<"Mobile Phone Specifications:\n";
            cout<<"Phone Type: Smart Phone\nBattery Capacity: "<<this->batteryCapacity<<"mAh\nRAM Size: "<<this->ramSize<<" GB\n";
        }
};
int main()
{
    BasicPhone *objBasicPhone=new BasicPhone(2000,2);
    SmartPhone *objSmartPhone=new SmartPhone(4000,6);

    objBasicPhone->showMobilePhoneSpecifications();
    cout<<"\n";
    objSmartPhone->showMobilePhoneSpecifications();

    return 0;
}