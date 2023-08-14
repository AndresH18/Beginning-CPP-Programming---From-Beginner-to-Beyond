//
// Created by andre on 13/8/2023.
//

#include <iostream>
#include "savings_account.h"


SavingsAccount::SavingsAccount() : SavingsAccount(0.1) {
    std::cout << "(" << this << ")SavingsAccount constructor ()" << std::endl;
}

SavingsAccount::SavingsAccount(double rate) : Account{}, p_rate{nullptr} {
    std::cout << "(" << this << ")SavingsAccount constructor (double)" << std::endl;
    this->p_rate = new double;
    *this->p_rate = rate;
}

SavingsAccount::SavingsAccount(double rate, double amount) : Account{amount}, p_rate{nullptr} {
    std::cout << "(" << this << ")SavingsAccount constructor (double, double)" << std::endl;
    this->p_rate = new double;
    *this->p_rate = rate;
}

SavingsAccount::SavingsAccount(const SavingsAccount& other) : Account(other) {
    std::cout << "(" << this << ")SavingsAccount copy constructor (" << &other << ")" << std::endl;
}

SavingsAccount::SavingsAccount(SavingsAccount&& other) : Account(other) {
    std::cout << "(" << this << ")SavingsAccount move constructor (" << &other << ")" << std::endl;
    other.p_rate = nullptr;
}

SavingsAccount::~SavingsAccount() {
    std::cout << "(" << this << ")SavingsAccount destructor" << std::endl;
    delete p_rate;
}

void SavingsAccount::deposit(double amount) {
    Account::deposit(amount);
}

void SavingsAccount::withdraw(double amount) {
    Account::withdraw(amount);
}

SavingsAccount& SavingsAccount::operator=(const SavingsAccount& sa) {
    std::cout << "(" << this << ")SavingsAccount copy assignment (" << &sa << ")" << std::endl;
    if (this == &sa)
        return *this;
    // Base copy assignment. uses reference so there it modifies source
    Account::operator=(sa);
    // delete current storage
    delete p_rate;
    // create new storage
    p_rate = new double; // I don't think this is necessary, we could just copy the value in the next statement
    // copy value
    *p_rate = *sa.p_rate;

    return *this;
}

SavingsAccount& SavingsAccount::operator=(SavingsAccount&& sa) {
    std::cout << "(" << this << ")SavingsAccount move assignment (" << &sa << ")" << std::endl;
    if (this == &sa)
        return *this;

    // Base move assignment. uses reference
    SavingsAccount::operator=(sa);

    // delete storage
    delete p_rate;
    // steal pointer
    p_rate = sa.p_rate;
    // set other's pointer to nullptr
    sa.p_rate = nullptr;

    return *this;
}
