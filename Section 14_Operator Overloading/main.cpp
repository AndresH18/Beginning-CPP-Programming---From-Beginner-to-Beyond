#include <iostream>
#include "MyString.h"

int main() {

    MyString empty;
    MyString andres{"Andres"};
    MyString david{andres}; // initializing a new MyString using the copy constructor
    MyString myString;

    andres.display();
    empty.display();
    david.display();

    myString = andres; // copy assignment
//    myString.display();
//
    myString = "Hello";// copy assignment - creates a temporary variable using the overloaded constructor
//
    myString.display();
//
//    (-andres).display();

    std::cout << "Hello World" << std::endl;

    std::cout << std::flush;
    return 0;
}
