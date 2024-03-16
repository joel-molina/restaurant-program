//Class containing variables and functions specific to a customer (guest or not)

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <iomanip>
using namespace std;
#include "../menuItem/menuItem.h"


#define MAX_SIZE_ORDER 50

class Customer
{
    string customerFirst, customerLast; 
    long int loyaltyNumber;
    long int numberLoyaltyPoints; 
    DynamicArray<MenuItem*> currentOrder;

    public:
        Customer();
        Customer(string const, string const, long int const, long int const); 
        Customer(const Customer&);

        string getCustomerFirst() const;
        void setCustomerFirst(string const&); 

        string getCustomerLast() const;
        void setCustomerLast(string const&); 

        long int getLoyaltyNumber() const;
        void setLoyaltyNumber(long int const&);

        long int getNumberLoyaltyPoints() const;
        void setNumberLoyaltyPoints(long int const&); 

        DynamicArray<MenuItem*> getCurrentOrder() const;
        void addItemToOrder(MenuItem*);

        float calculateCost() const;
        void displayCustomerInformation() const;

        void clearOrder();
        friend ostream& operator << (ostream&, const Customer&);
};
#endif