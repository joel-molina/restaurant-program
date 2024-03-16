//#include <gtest/gtest.h>
#include "../../customer/customer.h"
#include "../../menuItem/menuItem.h"
#include "../../drink/drink.h"

TEST(drinkTests, checkOutPutDrink)
{
    //Testing function: calculateMenuItemCost()
    Drink* faygo = new Drink();

    //Testing expected value
    float expectedCost = (2.99 + 0.25 + 0.5); //size 16 drink that needs a straw and ice.

    //Testing actual value
    faygo->setSize(16);
    faygo->setNeedsStraw(true);
    faygo->setNeedsIce(true);
    faygo->calculateMenuItemCost();

    //Determing that addItemToOrder works by comparing the expected vs actual cost of the item added from an expected value in an array vs the actual value from the function.
    EXPECT_NEAR(expectedCost, faygo->getCost(), 0.1);
    delete faygo;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}


