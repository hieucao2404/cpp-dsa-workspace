cmake_minimum_required(VERSION 3.10)
project(DSA_Workspace)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Other exercises
add_executable(main src/main.cpp)
add_executable(ex1_stack exercises/ex1_stack.cpp)

# Build CreditCard as a library
add_library(creditcard exercises/CreditCard.cpp)

# Test program that links with CreditCard
add_executable(ex_creditcard src/testCard.cpp)
target_link_libraries(ex_creditcard PRIVATE creditcard)

#Program examle1-4-5
add_executable(ex_ptfunc src/Example1-4-5.cpp)
