/*
 * Author: Joel Molina
 * Date: Fall 2023
 * Purpose: Create restaurant ordering system with a loyalty rewards system.
 * Max customers: 1000
 * Max menu items: 100
 * Max ingredients: 50
*/

#include "helperFunctions/helperFunctions.h"

int main()
{
    bool isLoyaltyMember;
    int customerIndex = 0;

    do
    { 
        DynamicArray<Customer*> customers;
        getLoyaltyDatabase(customers); 
        int numCustomers = customers.getCurrentSize();
        customerIndex = runLoyaltyProgram(customers);

        if(customerIndex == -2)
        {
            return -2;
        }
        else if(customerIndex == -1)
        {
            customerIndex = numCustomers;

            customers.addElement(new Customer());
            isLoyaltyMember = false;
        }
        else
        {
            isLoyaltyMember = true;
        }
        customers.returnElement(customerIndex)->getCurrentOrder().setCurrentSize(0);

        //New Place Order
        DynamicArray<MenuItem*> items = placeOrder();
        for(int i=0; i<items.getCurrentSize(); i++)
        {
            customers.returnElement(customerIndex)->addItemToOrder(items.returnElement(i));
        }

        if(isLoyaltyMember)
        {
            int availablePts = customers.returnElement(customerIndex)->getNumberLoyaltyPoints();
            int numPts = customers.returnElement(customerIndex)->calculateCost();
            bool usingLoyalty = pointSystemPrompt(*(customers.returnElement(customerIndex)));

            float customerMoney = 0;
            if(!usingLoyalty)
            {
                availablePts += numPts;
                //customers.returnElement(customerIndex)->displayOrder();
                cout << *customers.returnElement(customerIndex);
                customers.returnElement(customerIndex)->setNumberLoyaltyPoints(availablePts);
                calculateChange(customers.returnElement(customerIndex));
                cout<< "Have a nice day!" << endl << endl <<endl << endl;
                customers.returnElement(customerIndex)->clearOrder();
            }
            else
            {
                useLoyalty(customers.returnElement(customerIndex), numCustomers, availablePts);
                //customers.returnElement(customerIndex)->displayOrder();
                cout << *customers.returnElement(customerIndex);
                calculateChange(customers.returnElement(customerIndex));
                cout<< "Have a nice day!" << endl << endl <<endl << endl;
                customers.returnElement(customerIndex)->clearOrder();
            }
            overwriteLoyaltyDatabase(customers);
        }
        else
        {
            //customers.returnElement(customerIndex)->displayOrder();  
            cout << *customers.returnElement(customerIndex);
            calculateChange(customers.returnElement(customerIndex));
            cout<< "Have a nice day!" << endl << endl <<endl << endl;
            customers.returnElement(customerIndex)->getCurrentOrder().setCurrentSize(0);
            customers.returnElement(customerIndex)->clearOrder();
        }
    }
    while(customerIndex != -2);
    
    return 0;
}

