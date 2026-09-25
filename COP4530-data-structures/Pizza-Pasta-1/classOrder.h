/* Class definitions for abstract class Order, as well as subclasses PizzaOrder and PastaOrder, which are going to be used for the templated queue. 
A customer can only order either pizza or pasta. */

#ifndef CLASSORDER_H
#define CLASSORDER_H
#include <iostream>
#include <string>

using namespace std;

// Enumarations for pizza type and crust
enum PizzaType { Vegetarian = 11, Margherita = 12, Pepperoni = 13, Cheese = 14, BBQChicken = 16 };
enum CrustType { thin = 0, thick = 1, stuffed = 2 };
// Pasta Type Enumeration
enum PastaType {Spaghetti = 10, Fettuccine = 11, Penne = 12, Linguine = 13};

// Parent abstract class Order
class Order {
    protected:
        string name;
        string phone;
        bool drink;
        double total;
    public:
        Order(); // default constructor
        virtual void printOrder() = 0; // pure virtual function to print order details
        virtual void changeOrder() = 0; // pure virtual function to modify order details
        // accessor functions
        double getTotal() const { return total; }
        string getName() const { return name; }
        string getPhone() const { return phone; }
        bool getDrink() const { return drink; }
        // modifier functions
        void setName(const string& newName) { name = newName; }
        void setPhone(const string& newPhone) { phone = newPhone; }
        void setTotal(int newTotal) { total = newTotal; }
        // other functions
        bool phoneValidation(const string& phone);
        char validateChoice();
};

// Derived class of Order: PizzaOrder
class PizzaOrder : public Order {
    private:
        PizzaType type;
        int size;
        CrustType crust;
    public:
        PizzaOrder();
        PizzaType getType() const { return type; }
        int getSize() const { return size; }
        CrustType getCrust() const { return crust; }
        virtual void printOrder() override;
        virtual void changeOrder() override;
};

// Derived class of Order: Pasta
class PastaOrder : public Order {
    private:
        PastaType type;
        bool withChicken;
        bool withShrimp;
        bool withMushroom;
    public:
        PastaOrder();
        // accessor functions
        PastaType getType() const { return type; }
        bool hasChicken() const { return withChicken; }
        bool hasShrimp() const { return withShrimp; }
        bool hasMushroom() const { return withMushroom; }
        virtual void printOrder() override;
        // modifier function
        void setPastaType(PastaType newType);
        void setChicken(bool newChicken) { withChicken = newChicken; }
        void setMushroom(bool newMushroom) { withMushroom = newMushroom; }
        void setShrimp(bool newShrimp) { withShrimp = newShrimp; }
        // change order function
        virtual void changeOrder() override;
};


#endif