//bridge design pattern

//bridge is a structural design pattern that lets you split a large class 
// -- or a set of closely related classes into two separate hierarchies 
// - abstraction and implementation, which can be developed independently of each other

//bridge is a structural design pattern that divides business logic or huge class
// -- into separate class hierarchies that can be developed independently

#include <iostream>

/**
 * The Implementation defines the interface for all implementation classes. It
 * doesn't have to match the Abstraction's interface. In fact, the two
 * interfaces can be entirely different. Typically the Implementation interface
 * provides only primitive operations, while the Abstraction defines higher-
 * level operations based on those primitives.
 */

class Implementation{

    public:
        virtual ~Implementation() {};
        virtual std::string OperationImplementation() const = 0;
};

//each concrete implementation corresponds to a specific platform and implements
// -- the implementation interface using that platform's API

class ConcreteImplementationA : public Implementation{

    public:
        std::string OperationImplementation() const override{
            return "ConcreteImplementationA :  here's the result on platform A";
        }
};

class ConcreteImplementationB : public Implementation{

    public:
        std::string OperationImplementation() const override{
            return "ConcreteImplementationB :  here's the result on platform B";
        }
};

/**
 * The Abstraction defines the interface for the "control" part of the two class
 * hierarchies. It maintains a reference to an object of the Implementation
 * hierarchy and delegates all of the real work to this object.
 */

class Abstraction{

    protected:
        Implementation *implementation_;

    public:
        Abstraction(Implementation *implementation) : implementation_(implementation){};

        virtual ~Abstraction(){};

        virtual std::string Operation() const{
            return "Abstraction: Base operation with: " + 
                this -> implementation_ -> OperationImplementation();
        }
};

/**
 * You can extend the Abstraction without changing the Implementation classes.
 */
class ExtendedAbstraction : public Abstraction {
    
    public:
        ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation) {};

        std::string Operation() const override {
          return "ExtendedAbstraction: Extended operation with: " +
                 this->implementation_->OperationImplementation();
        }
};//we can ignore this class 

/**
 * Except for the initialization phase, where an Abstraction object gets linked
 * with a specific Implementation object, the client code should only depend on
 * the Abstraction class. This way the client code can support any abstraction-
 * implementation combination.
 */

void ClientCode(const Abstraction& abstraction) {
  // ...
     std::cout << abstraction.Operation();
  // ...
}

int main(){

    Implementation *implementation = new ConcreteImplementationA();
    Abstraction *abstraction = new Abstraction(implementation);

    ClientCode(*abstraction);

    delete implementation;
    delete abstraction;

    implementation = new ConcreteImplementationB();
    abstraction = new ExtendedAbstraction(implementation);
    ClientCode(*abstraction);

    delete implementation;
    delete abstraction;
}