cmake_minimum_required(VERSION 3.26)
project(Section_15_Inheritance)

set(CMAKE_CXX_STANDARD 17)

add_executable(Section_15_Inheritance main.cpp
        Account.cpp
        Account.h
        Savings_Account.cpp
        Savings_Account.h)
