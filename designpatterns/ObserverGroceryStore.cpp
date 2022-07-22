#include<iostream>
#include<iterator>
#include<list>
#include<string>
using namespace std;

#define TOTAL_GROCERY_ITEMS 5
struct GroceryItem
{
    string itemName;
    bool available;
};

GroceryItem groceryItems[TOTAL_GROCERY_ITEMS];

//This is an interface class for Customer (Observer) class

class Observer
{
    public:
        virtual ~Observer(){};
        virtual void update(const string &message_from_subject)=0;
};

//This is an interface class for GroceryStore (Subject/Publisher) class

class Subject
{
    public:
        virtual ~Subject(){};
        virtual void subscribe(Observer *observer)=0;
        virtual void unsubscribe(Observer *observer)=0;
        virtual void notify(string msg)=0;
};
/*GroceryStore is the Subject/Publisher here that owns some important state and notifies
observers (i.e. customers) when the state changes.*/

class GroceryStore: public Subject
{
    private:
        list<Observer*>list_observer;
    public:
        GroceryStore(GroceryItem *grocery)
        {
            for(int i=0;i<TOTAL_GROCERY_ITEMS;i++)
            {
                groceryItems[i].itemName=grocery[i].itemName;
                groceryItems[i].available=grocery[i].available;
            }
        }
        virtual ~GroceryStore()
        {
            cout<<"Goodbye, I was the Subject.\n";
        }
        void subscribe(Observer *observer)
        {
            cout<<"An observer has subscribed\n";
            list_observer.remove(observer);
        }
        void unsubscribe(Observer *observer)
        {
            cout<<"A customer has unsubcribed\n";
            list_observer.remove(observer);
        }
        void notify(string msg)
        {
            list<Observer *>::iterator iterator=list_observer.begin();
            while(iterator!=list_observer.end())
            {
                cout<<"GroceryStore is sending an update to the customer\n";
                (*iterator)->update(msg);
                ++iterator;
            }
        }
        void refillInventory(string itemName)
        {
            for(int i=0;i<TOTAL_GROCERY_ITEMS;i++)
            {
                if(itemName==groceryItems[i].itemName)
                {
                    groceryItems[i].available=true;
                    cout<<"Refilling the stock for item "<<itemName<<"\n";
                    notify(("Item "+itemName+" has been refilled in the Grocery Store"));
                }
            }
        }
};
class Customer:public Observer
{
    private:
        GroceryStore &subject_;
    public:
        Customer(GroceryStore &subject):subject_(subject)
        {
            this->subject_.subscribe(this);
        }
        virtual ~Customer()
        {
            cout<<"Goodbye, I was the Observer.\n";
        }
        void update(const string &msg)
        {
            cout<<"Hey customer! A new message is available --> "<<msg<<"\n"; 
        }
        void unsubscribeCustomer()
        {
            cout<<"Customer wants to unsubscribe the Grocery Store notifications -";
            subject_.unsubscribe(this);
        }
        bool purchaseItem(string itemName)
        {
            cout<<"Customer wants to purchase item "<<itemName<<" - ";
            for(int i=0;i<TOTAL_GROCERY_ITEMS;i++)
            {
                if(itemName==groceryItems[i].itemName)
                {
                    if(groceryItems[i].available)
                    {
                        cout<<"Item "<<itemName<<" is available\n";
                        return true;
                    }
                }
            }
            cout<<"The item "<<itemName<<" is not available in the GroceryStore\n";
            return false;
        }
};
int main()
{
    GroceryItem itemList[]={{"Flour",true},{"Rice",true},{"Brown Bread",false},{"Blueberry Syrup",false},{"Detergent",true}};
    GroceryStore *objGs= new GroceryStore(itemList);
    Customer *objCust=new Customer(*objGs);

    objCust->purchaseItem("Detergent");
    objCust->purchaseItem("Flour");
    objCust->purchaseItem("Rice");
    objCust->purchaseItem("Brown Bread");
    objCust->purchaseItem("Blueberry Syrup");
    cout<<"\n";
    objGs->refillInventory("Brown Bread");
    objCust->purchaseItem("Brown Bread");
    objCust->unsubscribeCustomer();
    cout<<"\n";
    objGs->refillInventory("Blueberry Syrup");

    return 0;
}
