#include "customer.h"

//constructors
Customer::Customer()
{
    customerFirst = "Jane";
    customerLast = "Doe";
    loyaltyNumber = 0;
    numberLoyaltyPoints = 1111111;
}
Customer::Customer(string const first, string const last, long int const id, long int const numPts)
{
    customerFirst = first;
    customerLast = last;
    loyaltyNumber = id;
    numberLoyaltyPoints = numPts;
}
Customer::Customer(const Customer& rhs)
{
    customerFirst = rhs.customerFirst;
    customerLast = rhs.customerLast;
    loyaltyNumber = rhs.loyaltyNumber;
    numberLoyaltyPoints = rhs.numberLoyaltyPoints;
    for(int i = 0; i < currentOrder.getCurrentSize(); i++)
    {
        currentOrder.addElement(rhs.currentOrder.returnElement(i)); 
    }
}

//getters
string Customer::getCustomerFirst() const
{
    return customerFirst;
}
string Customer::getCustomerLast() const
{
    return customerLast;
}
long int Customer::getLoyaltyNumber() const
{
    return loyaltyNumber;
}
long int Customer::getNumberLoyaltyPoints() const
{
    return numberLoyaltyPoints;
}

//setters
void Customer::setCustomerFirst(string const& name)
{
    customerLast = name;
}
void Customer::setCustomerLast(string const& name)
{
    customerLast = name;
}
void Customer::setLoyaltyNumber(long int const& id)
{
    loyaltyNumber = id;
}   
void Customer::setNumberLoyaltyPoints(long int const& numPts){
    numberLoyaltyPoints = numPts;
}


//Order functions
DynamicArray<MenuItem*> Customer::getCurrentOrder() const
{
    return currentOrder;
}
void Customer::addItemToOrder(MenuItem* newItem)
{
    currentOrder.addElement(newItem);
}

float Customer::calculateCost() const
{
    float customerTotal = 0;
    float currentTaxRate = 1.0827;
    for(int i = 0; i < currentOrder.getCurrentSize(); i++)
    {
        customerTotal = currentOrder.returnElement(i)->getCost() + customerTotal;
    }
    customerTotal *= currentTaxRate;
    return customerTotal;
}

void Customer::displayCustomerInformation() const
{
    cout <<endl << "Welcome " <<getCustomerFirst() <<" " << getCustomerLast() << "!" << endl;
    cout << "You have " << getNumberLoyaltyPoints() << " Loyalty Points." << endl;
}
void Customer::clearOrder()
{
    currentOrder.deleteArray();
}

//insertion overload
ostream& operator << (ostream& out, const Customer& customer)
{
    out << endl << "=====Your Order=====" << endl;
    for(int i = 0; i<customer.getCurrentOrder().getCurrentSize()-1; i++)
    {
        out << *(customer.getCurrentOrder().returnElement(i));

    }
    out << "Your Total Today Is: $" << std::fixed << setprecision(2) << customer.calculateCost() << endl << endl;

    return out;
}
