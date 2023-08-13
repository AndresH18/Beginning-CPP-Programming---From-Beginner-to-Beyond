#pragma clang diagnostic push
#pragma ide diagnostic ignored "google-explicit-constructor"
#pragma ide diagnostic ignored "modernize-use-nodiscard"

#ifndef SECTION_14_OPERATORS_OVERLOADING_MY_STRING_H
#define SECTION_14_OPERATORS_OVERLOADING_MY_STRING_H

class MyString {
private:
    char *str;  // pointer to a char[] that holds a C-style string
public:
    MyString();
    MyString(char *str);
    MyString(const MyString& source);
    ~MyString();

    void display() const;
    int get_length() const;
    const char *get_str() const;
};

MyString::MyString() {

}

MyString::MyString(char *str) {

}

MyString::MyString(const MyString &source) {

}

MyString::~MyString() {

}

void MyString::display() const {

}

int MyString::get_length() const {
    return 0;
}

const char *MyString::get_str() const {
    return nullptr;
}

#endif
#pragma clang diagnostic pop
#pragma clang diagnostic pop