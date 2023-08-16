cmake_minimum_required(VERSION 3.26)
project(Section_17_Smart_Pointers)

set(CMAKE_CXX_STANDARD 17)

add_executable(Section_17_Smart_Pointers main.cpp
        Test.cpp
        Test.h
        unique_ptr/Account.h
        unique_ptr/Account.cpp
        unique_ptr/Account_Util.cpp
        unique_ptr/Account_Util.h
        unique_ptr/Checking_Account.h
        unique_ptr/Checking_Account.cpp
        unique_ptr/I_Printable.h
        unique_ptr/I_Printable.cpp
        unique_ptr/Savings_Account.h
        unique_ptr/Savings_Account.cpp
        unique_ptr/Trust_Account.h
        unique_ptr/Trust_Account.cpp
)
