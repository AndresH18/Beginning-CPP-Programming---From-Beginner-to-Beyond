cmake_minimum_required(VERSION 3.26)
project(Section_18_Exception_Handling)

set(CMAKE_CXX_STANDARD 17)

add_executable(18_Exception_Handling main.cpp
        illegal_balance_exception.cpp
        illegal_balance_exception.h
        account.cpp
        account.h)
