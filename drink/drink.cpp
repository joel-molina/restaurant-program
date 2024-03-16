#include "drink.h"

Drink::Drink()
{
    size = 0;
    needsIce = false;
    needsStraw = false;
    cost = 0;
    itemName = "Fountain Drink";
    pointWorth = 50;
}
Drink::Drink(int const& sz, bool const& ice, bool const& straw, string& nm)
{
    size = sz;
    needsIce = ice;
    needsStraw = straw;
    calculateMenuItemCost();
    itemName = nm;
}
Drink::Drink(const Drink& rhs)
{
    size = rhs.size;
    needsIce = rhs.needsIce;
    needsStraw = rhs.needsStraw;
    cost = rhs.cost;
}

int Drink::getSize() const
{
    return size;
}
void Drink::setSize(int const& sz)
{
    size = sz;
}

bool Drink::getNeedsStraw() const
{
    return needsStraw; 
}
void Drink::setNeedsStraw(bool const& straw)
{
    needsStraw = straw;
}

bool Drink::getNeedsIce() const
{
    return needsIce;
}
void Drink::setNeedsIce(bool const& ice)
{
    needsIce = ice;
}

ostream& Drink::displayItemInformation(ostream& out) const
{
    MenuItem::displayItemInformation(out);

    if(needsIce || needsStraw)
    {
        out << "INCLUDE: ";
        if(needsIce)
        {
            out << "Ice";
        }
        if(needsIce && needsStraw)
        {
            out << ", Straw";
        }
        else if(needsStraw)
        {
            out << "Straw";
        }
        out << endl << endl;
    }
    return out;
}

void Drink::calculateMenuItemCost() 
{
    if(size == 16)
    {
        cost = 2.99;
    }
    else if(size == 20)
    {
        cost = 3.25;
    }
    else if(size == 32)
    {
        cost = 3.75;
    }

    if(needsIce)
    {
        cost += 0.25;
    }
    if(needsStraw)
    {
        cost += 0.50;
    }
}