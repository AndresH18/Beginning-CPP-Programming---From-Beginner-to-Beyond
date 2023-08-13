
#ifndef SECTION_14_OPERATORS_OVERLOADING_MY_STRING_H
#define SECTION_14_OPERATORS_OVERLOADING_MY_STRING_H

class MyString {
    friend bool operator!=(const MyString &lhs, const MyString &rhs);

    friend std::ostream &operator<<(std::ostream &os, const MyString &);

    friend std::istream &operator>>(std::istream &is, MyString &);

private:
    char *str;  // pointer to a char[] that holds a C-style string
public:
    /**
     * No args constructor
     */
    MyString();

    /**
     * Overloaded constructor
     */
    MyString(const char *str);

    /**
     * Copy constructor
     */
    MyString(const MyString &source);

    /**
     * Move constructor
     */
    MyString(MyString &&);

    /** Destructor
     */
    ~MyString();

    /**
     * Copy Assignment operator
     */
    MyString &operator=(const MyString &rhs);

    /**
     * Move Assignment Operator
     */
    MyString &operator=(MyString &&rhs);

    /**
     * == Operator
     */
    bool operator==(const MyString &rhs) const;

    MyString operator+(const MyString &rhs) const;

    MyString operator-() const;

    void display() const;

    int get_length() const;

    const char *get_str() const;
};

#endif
