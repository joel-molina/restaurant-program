#include "menuItem.h"

MenuItem::MenuItem()
{
    itemName = "NONE";
    cost = 0;
    pointWorth = 0;
}
MenuItem::MenuItem(const MenuItem& rhs)
{
    itemName = rhs.itemName;
    cost = rhs.cost;
    pointWorth = rhs.pointWorth;
}
MenuItem::MenuItem(float const& val, string const& name, int const& pts)
{
    itemName = name;
    cost = val;
    pointWorth = pts;
}
//Virtual destructor
MenuItem::~MenuItem(){}

float MenuItem::getCost() const
{
    return cost;
}
void MenuItem::setCost(float const& val){
    cost = val;
}

string MenuItem::getItemName() const
{
    return itemName;
}
void MenuItem::setItemName(string const& name)
{
    itemName = name;
}

int MenuItem::getPointWorth() const
{
    return pointWorth;
}
void MenuItem::setPointWorth(int const& pts)
{
    pointWorth = pts;
}

float MenuItem::operator+(const float& rhs)
{
    return cost + rhs;
}
ostream& operator << (ostream& out, const MenuItem& menuItem)
{
    menuItem.displayItemInformation(out);
    return out;
}

