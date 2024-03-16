//Class containing variables and functions specific to a food menu item.
#ifndef FOOD_H
#define FOOD_H

#include "../menuItem/menuItem.h"

class Food : public MenuItem
{
    DynamicArray<string> ingredients;
    int numberIngredients; 
    
    DynamicArray<string> availableExtras;
    int numAvailableExtras;

    public: 
        Food();
        Food(DynamicArray<string>, int const&, DynamicArray<string>, int const&); 
        Food(const Food&);

        DynamicArray<string> getIngredients();
        void addIngredient(const string&); 

        int getNumberIngredients() const;

        void setAvailableExtras();
        DynamicArray<string> getAvailableExtras();

        int getNumAvailableExtras() const;
        void setNumAvailableExtras(const int);

        ostream& displayItemInformation(ostream& out) const override;
        void calculateMenuItemCost() override;
};
#endif