file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(drinkTests ${SRCS})

TARGET_LINK_LIBRARIES(drinkTests libgtest libgmock customer menuItem drink)

add_test(NAME drinkTests COMMAND drinkTests) 








