#include <iostream>
#include <vector>  
using namespace std;

class Pizza {
    public:
        virtual void bake() = 0;
        virtual void cut() = 0;
        virtual void box() = 0;
};

class NewYorkCheesePizza: public Pizza{
    void bake() override{
        cout << "Baking New York-style cheese pizza." << '\n';
    }
    void cut() override{
        cout << "Cutting New York-style cheese pizza." << '\n';
    }
    void box() override{
        cout << "Boxing New York-style cheese pizza." << '\n';
    }
};

class NewYorkPepperoniPizza: public Pizza{
    void bake() override{
        cout << "Baking New York-style pepperoni pizza." << '\n';
    }
    void cut() override{
        cout << "Cutting New York-style pepperoni pizza." << '\n';
    }
    void box() override{
        cout << "Boxing New York-style pepperoni pizza." << '\n';
    }
};

class ChicagoCheesePizza: public Pizza{
    void bake() override{
        cout << "Baking Chicago-style cheese pizza." << '\n';
    }
    void cut() override{
        cout << "Cutting Chicago-style cheese pizza." << '\n';
    }
    void box() override{
        cout << "Boxing Chicago-style cheese pizza." << '\n';
    }
};


class ChicagoPepperoniPizza: public Pizza{
    void bake() override{
        cout << "Baking Chicago-style pepperoni pizza." << '\n';
    }
    void cut() override{
        cout << "Cutting Chicago-style pepperoni pizza." << '\n';
    }
    void box() override{
        cout << "Boxing Chicago-style pepperoni pizza." << '\n';
    }
};

class PizzaFactory{
    public:
        virtual Pizza* createCheesePizza() = 0;
        virtual Pizza* createPepperoniPizza() = 0;
};

class NewYorkPizzaFactory : public PizzaFactory{
    Pizza* createCheesePizza() override{
        return new NewYorkCheesePizza();
    }
    Pizza* createPepperoniPizza() override
    {
        return new NewYorkPepperoniPizza();
    }
};

class ChicagoPizzaFactory : public PizzaFactory {
public:
    Pizza* createCheesePizza() override
    {
        return new ChicagoCheesePizza();
    }

    Pizza* createPepperoniPizza() override
    {
        return new ChicagoPepperoniPizza();
    }
};

int main(){
    // Create a New York Pizza Factory
    PizzaFactory* newYorkFactory
        = new NewYorkPizzaFactory();
    Pizza* newYorkCheesePizza
        = newYorkFactory->createCheesePizza();
    Pizza* newYorkPepperoniPizza
        = newYorkFactory->createPepperoniPizza();

    // Create a Chicago Pizza Factory
    PizzaFactory* chicagoFactory
        = new ChicagoPizzaFactory();
    Pizza* chicagoCheesePizza
        = chicagoFactory->createCheesePizza();
    Pizza* chicagoPepperoniPizza
        = chicagoFactory->createPepperoniPizza();

    // Order and prepare the pizzas
    newYorkCheesePizza->bake();
    newYorkCheesePizza->cut();
    newYorkCheesePizza->box();

    newYorkPepperoniPizza->bake();
    newYorkPepperoniPizza->cut();
    newYorkPepperoniPizza->box();

    chicagoCheesePizza->bake();
    chicagoCheesePizza->cut();
    chicagoCheesePizza->box();

    chicagoPepperoniPizza->bake();
    chicagoPepperoniPizza->cut();
    chicagoPepperoniPizza->box();

    // Clean up
    delete newYorkFactory;
    delete newYorkCheesePizza;
    delete newYorkPepperoniPizza;
    delete chicagoFactory;
    delete chicagoCheesePizza;
    delete chicagoPepperoniPizza;

    return 0;
}