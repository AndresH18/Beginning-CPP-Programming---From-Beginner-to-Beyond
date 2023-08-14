//
// Created by andre on 13/8/2023.
//

#ifndef SECTION_15_INHERITANCE_SAVINGS_ACCOUNT_H
#define SECTION_15_INHERITANCE_SAVINGS_ACCOUNT_H


#include "Account.h"

class SavingsAccount : public Account {
private:
    double rate;
public:
    SavingsAccount();
    SavingsAccount(double rate);
    SavingsAccount(double rate, double amount);
    ~SavingsAccount();
    void deposit(double amount) override;
    void withdraw(double amount) override;
};


#endif //SECTION_15_INHERITANCE_SAVINGS_ACCOUNT_H
