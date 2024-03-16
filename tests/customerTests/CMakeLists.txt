file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(customerTests ${SRCS})

TARGET_LINK_LIBRARIES(customerTests libgtest libgmock customer menuItem food)

add_test(NAME customerTests COMMAND customerTests)