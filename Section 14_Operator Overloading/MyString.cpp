#include <cstring>
#include <iostream>
#include "MyString.h"

MyString::MyString() : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

MyString::MyString(const char *str) : str{nullptr} {
    if (str == nullptr) {
        this->str = new char[1];
        *(this->str) = '\0'; // *this->str
    } else {
        this->str = new char[std::strlen(str) + 1];
        std::strcpy(this->str, str);
    }
}

MyString::MyString(const MyString &source) : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

MyString::MyString(MyString &&source) : str{source.str} {
    source.str = nullptr;
    std::cout << "Move constructor used\n";
}

MyString &MyString::operator=(const MyString &rhs) {
    std::cout << "Using Copy Assignment\n";
    if (this == &rhs)
        return *this;
    delete[] str;

    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);

    return *this;
}

MyString &MyString::operator=(MyString &&rhs) {
    std::cout << "Using Move Assignment\n";

    if (this == &rhs)   // check self assignment
        return *this;   // return current object

    delete[] str;       // deallocate current storage
    str = rhs.str;// steal pointer;
    rhs.str = nullptr;  // null out the rhs pointer

    return *this;       // return current object
}

bool MyString::operator==(const MyString &rhs) const {
    return std::strcmp(str, rhs.str) == 0;
}

MyString MyString::operator+(const MyString &rhs) const {
    size_t buff_size = std::strlen(str) + std::strlen(rhs.str) + 1;

    char *buff = new char[buff_size];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    MyString temp{buff};
    delete[] buff;

    return temp;
}

MyString MyString::operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);

    MyString temp{buff};
    delete[] buff;
    return temp;
}

MyString::~MyString() {
    std::cout << "destructor called for " << (str == nullptr || std::strlen(str) == 0? "nullptr" : str) << "\n";;
    delete[] str;
}

void MyString::display() const {
    std::cout << str << " : " << get_length() << "\n";;
}

int MyString::get_length() const {
    return std::strlen(str);
}

const char *MyString::get_str() const {
    return str;
}

