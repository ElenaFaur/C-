//adapter design pattern

//adapter is a structural design pattern that allows objects with incompatible
// -- interfaces to collaborate

//this design pattern is often used in systems based on legacy code
//adapters make legacy code work with modern classes

//identification: adapter is recognizable by a constructor which takes
// -- an instance of a different abstract/interface type
//when the adapter receives a call to any of its methods, it translates parameters
// -- to the appropiate format and then directs the call to one or several methods 
// -- of the wrapped object

#include <iostream>
#include <algorithm>

//the target defines the domain-specific interface used by client-code
class Target{

    public:
        virtual ~Target() = default;

        virtual std::string Request() const{
            return "target: the default target's behaviour";
        }
};

//the adaptee contains some useful behaviour, but its interface is incompatible
// -- with the existing client code
//the adaptee needs some adaptation before the client code can use it

class Adaptee{

    public:
        std::string specificRequest() const{
            return ".eetpadA eht fo roivaheb laicepS";
        }
};

//the adapter makes the Adaptee's interface compatible with the Target's interface
class Adapter : public Target{

    private:
        Adaptee *adaptee_;

    public:
        Adapter(Adaptee *adaptee) : adaptee_(adaptee) {};

        std::string Request() const override {
            
            std::string to_reverse = this -> adaptee_ -> specificRequest();
            //storing the weird return from the adaptee

            std::reverse(begin(to_reverse), end(to_reverse));
            return "Adapter (translated): " + to_reverse;
        }
};

//the client code supports all classes that follow the Target interface
void ClientCode(const Target *target){

    std::cout << target -> Request();
}

int main(){

    //client: i can work fine with target objects
    Target *target = new Target();  //same with new Target;
    ClientCode(target);

    std::cout << "\n\n";

    Adaptee *adaptee = new Adaptee();   //same with new Adaptee;
    std::cout << adaptee -> specificRequest();
    //the adaptee has a weird interface, the client doesn't understand it

    std::cout << "\n\n";
    //fortunately, we can work it out via the adapter
    Adapter *adapter = new Adapter(adaptee);
    ClientCode(adapter);

    delete target;
    delete adaptee;
    delete adapter;
}