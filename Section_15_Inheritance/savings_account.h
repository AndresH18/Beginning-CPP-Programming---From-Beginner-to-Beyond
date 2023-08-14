//
// Created by andre on 13/8/2023.
//

#ifndef SECTION_15_INHERITANCE_SAVINGS_ACCOUNT_H
#define SECTION_15_INHERITANCE_SAVINGS_ACCOUNT_H


#include "account.h"

class SavingsAccount : public Account {
private:
    double* p_rate;
public:
    SavingsAccount();

    SavingsAccount(double rate);

    SavingsAccount(double rate, double amount);

    /**
     * Copy constructor for Account
     */
    SavingsAccount(const SavingsAccount&);

    /**
     * Move constructor for Account
     */
    SavingsAccount(SavingsAccount&&);

    ~SavingsAccount();

    void deposit(double amount) override;

    void withdraw(double amount) override;

    SavingsAccount& operator=(const SavingsAccount& sa);

    SavingsAccount& operator=(SavingsAccount&& sa);
};


#endif //SECTION_15_INHERITANCE_SAVINGS_ACCOUNT_H
