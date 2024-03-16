restaurant: main.o customer.o drink.o dynamicArray.o food.o helperFunctions.o menuItem.o
	g++ -o restaurant main.o customer.o drink.o dynamicArray.o food.o helperFunctions.o menuItem.o

main.o: main.cpp 
	g++ -c main.cpp

helperFunctions.o: helperFunctions/helperFunctions.cpp
	g++ -c helperFunctions/helperFunctions.cpp

customer.o: customer/customer.cpp 
	g++ -c customer/customer.cpp

drink.o: drink/drink.cpp
	g++ -c drink/drink.cpp

food.o: food/food.cpp
	g++ -c food/food.cpp

menuItem.o: menuItem/menuItem.cpp 
	g++ -c menuItem/menuItem.cpp

dynamicArray.o: dynamicArray/dynamicArray.cpp 
	g++ -c dynamicArray/dynamicArray.cpp

clean:
	rm *.o restaurant
