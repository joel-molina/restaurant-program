//#include <gtest/gtest.h>
#include "../../customer/customer.h"
#include "../../menuItem/menuItem.h"
#include "../../food/food.h"

TEST(foodTests, checkOutPutFood)
{
    //Testing function: setAvailableExtras()
    Food* sandwich = new Food();

    //Testing expected value
    Food* testFood[5];
    for(int i=0; i<5; i++)
    {
        testFood[i] = new Food(); //initializes each object
    }
    testFood[0]->setItemName("Toast");
    testFood[1]->setItemName("Potatoes");
    testFood[2]->setItemName("BBQ Sauce");
    testFood[3]->setItemName("Broccoli");
    testFood[4]->setItemName("Ranch Dressing");

    //Testing actual value
    sandwich->setItemName("Smoked Meat Sandwich");
    sandwich->setAvailableExtras();

    //Comparing
    for(int i=0; i<5; i++)
    {
        EXPECT_EQ(testFood[i]->getItemName(), sandwich->getAvailableExtras().returnElement(i));
    }
    delete sandwich;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
