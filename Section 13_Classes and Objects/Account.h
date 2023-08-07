//
// Created by andre on 2/8/2021.
//
/*
 * This is called an include-guard.
 * It's used to prevent multiple #include that are calling the same class,
 * from causing an error
 */
#ifndef SECTION_13_CLASSES_AND_OBJECTS_ACCOUNT_H
#define SECTION_13_CLASSES_AND_OBJECTS_ACCOUNT_H

#include <string>


class Account {

private:
    std::string name;
    double balance{};
public:
    Account();

    Account(std::string name, double balance);

    Account(const Account &source);

    void set_balance(double);

    double get_balance();

    const std::string &getName() const;

    double getBalance() const;
};

#endif //SECTION_13_CLASSES_AND_OBJECTS_ACCOUNT_H
