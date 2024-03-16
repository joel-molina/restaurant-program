//Parent class for food and drink and performs functions relevant to both.
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "../dynamicArray/dynamicArray.cpp"
using namespace std;
#define MAX_NUMBER_INGREDIENTS 50

class MenuItem
{
    private:
        virtual ostream& displayItemInformation(ostream& out) const
        {
            out << itemName << " $" << cost << endl;
            return out;
        }
        friend class Food;
        friend class Drink;

    protected:
        float cost;
        string itemName; 
        int pointWorth; 

    public:
        MenuItem();
        MenuItem(float const&, string const&, int const&); //added PBR
        MenuItem(const MenuItem&);
        virtual ~MenuItem();
    
        float getCost() const;
        void setCost(float const&); //added PBR

        string getItemName() const;
        void setItemName(string const&); //added PBR
        
        int getPointWorth() const;
        void setPointWorth(int const&); //added PBR

        //new
        virtual void calculateMenuItemCost() = 0;

        float operator+(const float& rhs);
        friend ostream& operator << (ostream&, const MenuItem&);
};
#endif