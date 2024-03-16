//Class containing variables and functions specific to a drink menu item.
#ifndef DRINK_H
#define DRINK_H
#include "../menuItem/menuItem.h"

class Drink : public MenuItem{
    int size; 
    bool needsStraw; 
    bool needsIce; 

    public:
        Drink();
        Drink(int const&, bool const&, bool const&, string&); 
        Drink(const Drink&);

        int getSize() const;
        void setSize(int const&); 

        bool getNeedsStraw() const;
        void setNeedsStraw(bool const&); 

        bool getNeedsIce() const;
        void setNeedsIce(bool const&); 

        ostream& displayItemInformation(ostream& out) const override;
        void calculateMenuItemCost() override;
};
#endif