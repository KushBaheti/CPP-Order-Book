cmake_minimum_required(VERSION 3.21)
project(order_book)

set(CMAKE_CXX_STANDARD 17)

add_executable(order_book main.cpp)

add_subdirectory(tests)
