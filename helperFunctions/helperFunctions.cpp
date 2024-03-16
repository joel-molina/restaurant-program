#include "helperFunctions.h"

//user functions
template <typename T>
T getUserChoice()
{
    T tempValue;
    cin >> tempValue;
    return tempValue;
}

//display functions
void displayLoyaltyInformationPrompt()
{
    cout << "Enrolling in the Sample's Loyalty Program is simple!" << endl;
    cout << "Just enter your 7 digit phone number without any dashes and your first and last name!" << endl;
    cout << "For example: 1111111 Pete Wentz" << endl << endl;
}
void displayPointRedemptionMenu()
{
    cout << "1.) Sandwich, 450 pts" << endl;
    cout << "2.) 32 oz. Drink, 50 pts" << endl;
    cout << "3.) Meat Man Meal, 500 pts" << endl;
    cout << "4.) Small Tater Tot, 75 pts" << endl;
}
void displayMemberJoin()
{
    cout << endl << endl<<"Don't have a loyalty number?" << endl;
    cout << "Join today and earn a free large drink!" << endl;
    cout << "Being a member of the Sample's Loyalty Program provides the following benefits: " << endl;
    displayPointRedemptionMenu();
    cout << endl<< "Would you like to join the Sample's Loyalty Program?(y/n) ";
}
void displayMenuItems()
{
    cout << endl<< "=====Sample's Restaurant Menu===== " << endl;
    cout << "1.) Smoked Meat Sandwich $12.99" << endl;
    cout << "2.) Restaurant Special Sandwich $15.99" << endl;
    cout << "3.) Fountain Drink ($2.99 16oz | $3.25 20oz | $3.75 32oz)" <<endl;
    cout << "4.) Tater Tots $3.99" << endl;
    cout << "0.) Finish Order" << endl;
    cout <<endl<< "Please Enter a Value [0-4]: ";
}

//customer functions
Customer* createCustomer()
{
    displayLoyaltyInformationPrompt();
    int loyaltyNum = getUserChoice<int>();
    string first = getUserChoice<string>();
    string last = getUserChoice<string>();

    Customer* newCustomer = new Customer( first, last, loyaltyNum, 50);
    return newCustomer;
}

MenuItem* addItemToOrder(int& numObject) 
{
    Food *newFood = new Food();
    Drink *newDrink = new Drink();

    if(numObject == 1)
    {
        newFood->setCost(12.99);
        newFood->addIngredient("Smoked Meat");
        newFood->addIngredient("White Bread");
        newFood->addIngredient("Mustard");
        newFood->addIngredient("Swiss Cheese");
        newFood->setItemName("Smoked Meat Sandwich");
        newFood->setAvailableExtras();
        promptFoodAddOns(newFood);
        newFood->setPointWorth(450);
        delete newDrink;
        return newFood;
    }
    else if(numObject == 2)
    {
        newFood->setCost(15.99);
        newFood->addIngredient("Smoked Meat");
        newFood->addIngredient("Toast");
        newFood->addIngredient("Potatoes");
        newFood->addIngredient("BBQ Sauce");
        newFood->addIngredient("Broccoli");
        newFood->setItemName("Restaurant Special");
        newFood->setPointWorth(500);
        newFood->setAvailableExtras();
        promptFoodAddOns(newFood);
        delete newDrink;
        return newFood;
    }
    else if(numObject == 3)
    {
        promptDrinkExtras(newDrink);
        delete newFood;
        return newDrink;
    }
    else if(numObject == 4)
    {
        newFood->setCost(3.99);
        newFood->addIngredient("Potatos");
        newFood->addIngredient("Ranch Dressing");
        newFood->setItemName("Tater Tots");
        newFood->setPointWorth(75);
        newFood->setAvailableExtras();
        promptFoodAddOns(newFood);
        delete newDrink;
        return newFood;
    }
    else if(numObject == 0)
    {
        // do nothing
    }
    else
    {
        cout << "Invalid option entered. Please enter a value [0-4]" << endl;
    }
    return newFood;
}
DynamicArray<MenuItem*> placeOrder()
{
    DynamicArray<MenuItem*> items;
    int menuItem = -1;
    do
    {
        displayMenuItems();
        menuItem = getUserChoice<int>();
        items.addElement(addItemToOrder(menuItem));

    }
    while(menuItem != 0);

    return items;
}

//loyalty functions
int runLoyaltyProgram(DynamicArray<Customer*>& customers)
{
    cout <<endl << endl<< "Welcome to Sample's Restaurant!" << endl;
    cout << endl << "Are you a member of the Sample's Loyalty Program? (y/n), or choose e to exit";
    char loyal = getUserChoice<char>();
    char userChoice = '.';
    if(loyal == 'e' || loyal == 'E')
    {
        return -2;
    }

    do{
        if (loyal == 'y' || loyal == 'Y'){
            cout << endl<<"Please enter your loyalty number: ";
            int loyaltyNumber = getUserChoice<int>();
            for(int i = 0; i < customers.getCurrentSize(); i++)
            {
                if(customers.returnElement(i)->getLoyaltyNumber() == loyaltyNumber)
                {
                    customers.returnElement(i)->displayCustomerInformation();
                    return i;
                }
            }
            loyal = 'N';
        }
        if(loyal == 'N' || loyal == 'n'){
            char join;
            do{
                displayMemberJoin();
                join = getUserChoice<char>();
            }while(join != 'y' && join != 'Y' && join != 'n' && join != 'N');
            if(join != 'y' && join != 'Y'){        
                return -1;
            }
            if(join == 'Y' || join == 'y')
            {
                Customer* newMember = createCustomer();
                customers.addElement(newMember);
                newMember->displayCustomerInformation();
                return customers.getCurrentSize()-1;
            }

            
        }
    }while(loyal != 'y' || loyal != 'Y' || loyal != 'n' || loyal != 'N');

    return -1;
}
void getLoyaltyDatabase(DynamicArray<Customer*>& loyaltyCustomers)
{
    string firstName, lastName;
    long int loyaltyNumber, numberPoints;
    int numCustomers = 0;
    string space = " ";

    

    ifstream loyaltyMemberStream("loyalty.txt"); 
    if (loyaltyMemberStream.is_open()) 
    { 
        while(loyaltyMemberStream.good())
        {
            loyaltyMemberStream >> loyaltyNumber >> firstName >> lastName >> numberPoints;
            Customer* newCustomer = new Customer(firstName, lastName, loyaltyNumber, numberPoints);
            loyaltyCustomers.addElement(newCustomer);
            numCustomers++;
        }
    }
    loyaltyMemberStream.close();
}


void overwriteLoyaltyDatabase(DynamicArray<Customer*>& customers)
{
    ofstream loyaltyMemberStream("loyalty.txt"); 
    for(int i = 0; i < customers.getCurrentSize(); i++)
    {
        bool foundDuplicate = false;
        for(int j = 0; j < i; j++)
        {
            if(customers.returnElement(i)->getLoyaltyNumber() == customers.returnElement(j)->getLoyaltyNumber())
            {
                // Found a duplicate loyalty number, update loyalty points
                customers.returnElement(j)->setNumberLoyaltyPoints(customers.returnElement(j)->getNumberLoyaltyPoints() + customers.returnElement(i)->getNumberLoyaltyPoints());
                foundDuplicate = true;
                break;
            }
        }
        
        if(!foundDuplicate)
        {
            loyaltyMemberStream << customers.returnElement(i)->getLoyaltyNumber() << " " << customers.returnElement(i)->getCustomerFirst() << " " << customers.returnElement(i)->getCustomerLast() << " " << customers.returnElement(i)->getNumberLoyaltyPoints();
            if(i != customers.getCurrentSize() - 1)
            {
                loyaltyMemberStream << endl;
            }
        }
    }
}

bool pointSystemPrompt(const Customer& customer)
{
    char useLoyalty = ' ';
    int availablePts = customer.getNumberLoyaltyPoints();
    if(availablePts >= 50){
        do{
            cout << endl << "Would you like to use any of your " <<availablePts<< " Loyalty Points (y/n)? ";
            int temp;
            cin >> useLoyalty;
        }while(useLoyalty != 'y' && useLoyalty != 'Y' && useLoyalty != 'n' && useLoyalty != 'N');
        if((useLoyalty == 'N' || useLoyalty == 'n') ){
            cout << "Cool, we'll bank those points for later!" <<endl;
            return false;
        }
        return true;
    }
    else{
        return false;
    }
}
void useLoyalty(Customer* customer, int& numCustomers, int& availablePts)
{
    int userOption = -99; 
    int numPts = 0;
    string foodName; 

    do{
        displayPointRedemptionMenu();
        cout << "0.) I've changed my mind!" << endl;
        cout << endl<< "Which offer would you like to redeem? [0-4] ";
        userOption = getUserChoice<int>();
        numPts = getNumberOfPointsToRedeem(&foodName, userOption);
        
        bool found = false;
        for( int i=0; i < customer->getCurrentOrder().getCurrentSize(); i++){

            if(customer->getCurrentOrder().returnElement(i)->getItemName() == foodName)
            {
                found = true;
                if(numPts <= availablePts)
                {
                    availablePts -= numPts;
                    int ptsToAdd = customer->calculateCost();
                    availablePts+=ptsToAdd;
                    customer->getCurrentOrder().returnElement(i)->setCost(0);
                    customer->setNumberLoyaltyPoints(availablePts);
                }
                else
                {
                    cout << endl<< "Insufficient number of points! Try again another time :) " << endl << endl;
                }
            }
        }
        
        if(!found){
            cout <<endl << "Sorry you didn't order that! Try again another time :)" << endl << endl;
            userOption = -1;
        }

    } while((userOption < 0 || userOption >4));
}
int getNumberOfPointsToRedeem(string* foodName, int& userOption)
{
    int numPts;
    switch(userOption){
        case 1:
            *foodName = "Smoked Meat Sandwich";
            numPts = 450;
            break;
        case 2:
            *foodName = "Fountain Drink";
            numPts = 50;
            break;
        case 3:
            *foodName = "Restaurant Special";
            numPts = 500;
            break;
        case 4:
            *foodName = "Tater Tots";
            numPts = 75;
            break;
        case 0:
            break;
    }
    return numPts;
}

//money function
void calculateChange(Customer* currentCustomer)
{
    float customerMoney = 0;
    do{
        if(currentCustomer->calculateCost()  != 0){
            cout << endl << endl << "Please enter the amount you'd like to pay with: $";
            cin >> customerMoney;
            if(customerMoney < currentCustomer->calculateCost()){
                cout << "Insufficient Funds, Trying Again..." << endl;
            }
            else
            {
                cout << "Your change today is: $" << std::fixed <<setprecision(2) <<customerMoney - currentCustomer->calculateCost() << endl;
            }
        }
    }while(customerMoney < currentCustomer->calculateCost());
}

//food functions
void promptFoodAddOns(Food* newFood)
{
    char choice;

    do
    {
        cout<<"Would you like to add any additional ingredients? (y/n) ";
        choice = getUserChoice<char>();
    } 
    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');

    if(choice == 'y' || choice == 'Y')
    {
        selectIngredient(newFood);
    }

}
void selectIngredient(Food* newFood)
{
    int userInput;

    cout << endl << "AVAILABLE ADD ONS" << endl << endl;
    for(int i=0; i<newFood->getNumAvailableExtras(); i++)
    {
        cout << i+1 << ". " << newFood->getAvailableExtras().returnElement(i) << endl;
    }
    cout << newFood->getNumAvailableExtras()+1 << ". Done Adding" << endl << endl;

    do
    {
        cout << "What would you like to add? ";
        userInput = getUserChoice<int>();

        if(userInput > 0 && userInput < newFood->getNumAvailableExtras())
        {
            newFood->addIngredient(newFood->getAvailableExtras().returnElement(userInput-1));
        }

    } while ((userInput < newFood-> getNumAvailableExtras() || userInput > newFood->getNumAvailableExtras()) && userInput != newFood->getNumAvailableExtras()+1);
    newFood->calculateMenuItemCost();
}

void promptDrinkExtras(Drink* newDrink)
{
    int size;

    do
    {
        cout<<"What size? (16, 20, 32) oz: ";
        size = getUserChoice<int>();
        newDrink->setSize(size);
    }
    while(size != 16 && size != 20 && size != 32);

    cout<<"Would you like a straw? (y/n): ";
    char userChoice;
    do
    {
        userChoice = getUserChoice<char>();
        if(userChoice == 'y' || userChoice == 'Y')
        {
            newDrink->setNeedsStraw(true);
        }
    }
    while(userChoice != 'n' && userChoice != 'N' && userChoice != 'y' && userChoice != 'Y');

    cout<<"Would you like ice? (y/n): ";
    do
    {
        userChoice = getUserChoice<char>();
        if(userChoice == 'y' || userChoice == 'Y')
        {
            newDrink->setNeedsIce(true);
        }
    } while(userChoice != 'n' && userChoice != 'N' && userChoice != 'y' && userChoice != 'Y');
    
    
    newDrink->calculateMenuItemCost();
}





















