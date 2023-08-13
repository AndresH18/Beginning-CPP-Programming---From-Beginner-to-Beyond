#include <iostream>
#include "MyString.h"

bool operator!=(const MyString &lhs, const MyString &rhs);

std::ostream &operator<<(std::ostream &os, const MyString &);

std::istream &operator>>(std::istream &is, MyString &obj);

int main() {

    std::cout << std::boolalpha; // display booleans as true/false

    MyString empty;
    MyString andres{"Andres"};
    MyString david{andres}; // initializing a new MyString using the copy constructor
    MyString myString;

    andres.display();
    empty.display();
    david.display();

    myString = andres; // copy assignment
    myString.display();
//
    myString = "Hello";// copy assignment - creates a temporary variable using the overloaded constructor
//
    myString.display();
//
    (-MyString{"LOWER CASE"}).display();

    std::cout << "andres.operator==(david) : " << (andres == david) << std::endl;

    MyString full_name;
    full_name = andres + " David";
    std::cout << "operator!=(andres, david) : " << (andres != david) << std::endl;

    full_name.display();

    std::cout << "Full name using stream operator : " << full_name << std::endl;
    std::cout << "Insert string for MyString" << std::endl;
    MyString cinString;
    std::cin >> cinString;

    std::cout << "cinString object : " << cinString << std::endl;

    std::cout << std::flush;
    return 0;
}

bool operator!=(const MyString &l, const MyString &r) {
    return !(l == r);
}

std::ostream &operator<<(std::ostream &os, const MyString &ob) {
    os << ob.str;
    return os;
}

std::istream &operator>>(std::istream &is, MyString &obj) {
    char *buff = new char[1000];
    is >> buff;
    obj = MyString{buff};
    delete[] buff;
    return is;
}