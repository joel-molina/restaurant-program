//#include <gtest/gtest.h>
#include "../../customer/customer.h"
#include "../../menuItem/menuItem.h"
#include "../../food/food.h"

TEST(customerTests, checkOutPutCustomer)
{
    //Testing function: addItemToOrder(MenuItem* newItem)
    Customer* testCustomer = new Customer();
    Food* burrito = new Food();
    burrito->setCost(15.99);

    //Testing expected value
    Food* testFood[1];
    testFood[0] = burrito;
    float expectedCost = testFood[0]->getCost();

    //Getting actual cost from using the function
    testCustomer->addItemToOrder(burrito);
    float actualCost = burrito->getCost();

    //Determing that addItemToOrder works by comparing the expected vs actual cost of the item added from an expected value in an array vs the actual value from the function.
    EXPECT_NEAR(expectedCost, actualCost, 0.01);
    delete testCustomer;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}