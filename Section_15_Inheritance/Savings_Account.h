//
// Created by andre on 13/8/2023.
//

#ifndef SECTION_15_INHERITANCE_SAVINGS_ACCOUNT_H
#define SECTION_15_INHERITANCE_SAVINGS_ACCOUNT_H


#include "Account.h"

class Savings_Account : public Account {
public:
    Savings_Account();
    ~Savings_Account();
    void deposit(double amount);
    void withdraw(double amount);
};


#endif //SECTION_15_INHERITANCE_SAVINGS_ACCOUNT_H
