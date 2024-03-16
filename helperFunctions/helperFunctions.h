#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include "../customer/customer.h"
#include "../drink/drink.h"
#include "../food/food.h"
#include <fstream>
#define MAX_NUM_CUSTOMERS 1000

//display functions
void displayPointRedemptionMenu();
void displayLoyaltyInformationPrompt();
void displayMenuItems();
void displayMemberJoin();

//loyalty functions
int runLoyaltyProgram(DynamicArray<Customer*>&); 
void overwriteLoyaltyDatabase(DynamicArray<Customer*>&); 
bool pointSystemPrompt(const Customer&);
void getLoyaltyDatabase(DynamicArray<Customer*>&);
int getNumberOfPointsToRedeem(string*, int&); 
void useLoyalty(Customer*, int&, int&); 

//customer functions
DynamicArray<MenuItem*> placeOrder();
Customer* createCustomer();

//user functions
template <typename T>
T getUserChoice();

MenuItem* addItemToOrder(int&); 
void calculateChange(Customer*);

//food functions
void promptFoodAddOns(Food*);
void selectIngredient(Food*);

//drink function
void promptDrinkExtras(Drink*);

#endif
