#include "food.h"

Food::Food()
{
    numberIngredients = 0;
    numAvailableExtras = 0;
}
Food::Food(DynamicArray<string> ing, int const& numIngredients, DynamicArray<string> ext, int const& numExtras)
{
    numberIngredients = numIngredients;
    numAvailableExtras = numExtras;
    
    //Initializing arrays
    ingredients = DynamicArray<string>();
    availableExtras = DynamicArray<string>();

    for(int i = 0; i < numIngredients; i++)
    {
        ingredients.addElement(ing.returnElement(i));
    }
    for(int i=0; i<numAvailableExtras; i++)
    {
        availableExtras.addElement(ext.returnElement(i));
    }
}
Food::Food(const Food& rhs)
{
    numberIngredients = rhs.numberIngredients;
    numAvailableExtras = rhs.numAvailableExtras;

    ingredients = DynamicArray<string>();
    availableExtras = DynamicArray<string>();

    for(int i = 0; i < rhs.numberIngredients; i++)
    {
        ingredients.addElement(rhs.ingredients.returnElement(i));
    }
    for(int i = 0; i < rhs.numAvailableExtras; i++)
    {
        availableExtras.addElement(rhs.availableExtras.returnElement(i));
    }
}

DynamicArray<string> Food::getIngredients()
{
    return ingredients;
}
void Food::addIngredient(string const& ingredient)
{
    ingredients.addElement(ingredient); 
    numberIngredients++;
}

int Food::getNumberIngredients() const
{
    return numberIngredients;
}

void Food::setAvailableExtras()
{
    if(itemName == "Smoked Meat Sandwich")
    {
        numAvailableExtras = 5;
        availableExtras.addElement("Toast");
        availableExtras.addElement("Potatoes");
        availableExtras.addElement("BBQ Sauce");
        availableExtras.addElement("Broccoli");
        availableExtras.addElement("Ranch Dressing");
    }
    else if(itemName == "Restaurant Special")
    {
        numAvailableExtras = 4;
        availableExtras.addElement("White Bread");
        availableExtras.addElement("Mustard");
        availableExtras.addElement("Swiss Cheese");
        availableExtras.addElement("Ranch Dressing");
    }
    else if(itemName == "Tater Tots")
    {
        numAvailableExtras = 7;
        availableExtras.addElement("Smoked Meat");
        availableExtras.addElement("White Bread");
        availableExtras.addElement("Mustard");
        availableExtras.addElement("Swiss Cheese");
        availableExtras.addElement("Toast");
        availableExtras.addElement("BBQ Sauce");
        availableExtras.addElement("Broccoli");
    }
}
DynamicArray<string> Food::getAvailableExtras()
{
    return availableExtras;
}

int Food::getNumAvailableExtras() const
{
    return numAvailableExtras;
}
void Food::setNumAvailableExtras(const int ext)
{
    numAvailableExtras = ext;
}

ostream& Food::displayItemInformation(ostream& out) const
{
    MenuItem::displayItemInformation(out);

    out << "INGREDIENTS: ";
    for(int i=0; i<numberIngredients; i++)
    {
        out << ingredients.returnElement(i);
        if(i != numberIngredients - 1)
        {
            out << ", ";
        }
    }
        out << endl << endl;

   return out;
}
void Food::calculateMenuItemCost() 
{
    int extrasAdded = 0;
    if(itemName == "Smoked Meat Sandwich")
    {
        extrasAdded = numberIngredients - 4;
    }
    else if(itemName == "Restaurant Special")
    {
        extrasAdded = numberIngredients - 5;
    }
    else if(itemName == "Tater Tots")
    {
        extrasAdded = numberIngredients - 2;
    }

    if(extrasAdded > 0)
    {
        cost += (0.5 * (double) extrasAdded);
    }
}



