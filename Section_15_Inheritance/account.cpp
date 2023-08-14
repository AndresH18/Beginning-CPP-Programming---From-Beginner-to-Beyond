//
// Created by andre on 13/8/2023.
//

#include <iostream>
#include "account.h"

Account::Account() {
    std::cout << "(" << this << ")Account constructor ()" << std::endl;
    p_amount = new double;
    *p_amount = 0;
}

Account::Account(double amount) : Account() {
    std::cout << "(" << this << ")Account constructor (double)" << std::endl;
    *this->p_amount = amount;
}

Account::Account(const Account& account) : p_amount{nullptr} {
    std::cout << "(" << this << ")Account copy constructor (" << &account << ")" << std::endl;
    p_amount = new double;
    *p_amount = *account.p_amount;
}

Account::Account(Account&& account) : p_amount{account.p_amount} {
    std::cout << "(" << this << ")Account move constructor (" << &account << ")" << std::endl;
    account.p_amount = nullptr;
}


Account::~Account() {
    std::cout << "(" << this << ")Account Destructor" << std::endl;
    delete p_amount;
}

void Account::deposit(double amount) {
    std::cout << "(" << this << ")Account deposit called with " << amount << std::endl;
}

void Account::withdraw(double amount) {
    std::cout << "(" << this << ")Account withdraw called with " << amount << std::endl;
}

double Account::get_amount() const {
    return *p_amount;
}

void Account::set_amount(double amount) {
    *Account::p_amount = amount;
}

Account& Account::operator=(const Account& other) {
    std::cout << "(" << this << ")Account copy assignment (" << &other << ")" << std::endl;
    if (this == &other)
        return *this;

    delete p_amount; // delete
    // create new storage
    p_amount = new double;
    // copy value
    *p_amount = *other.p_amount;

    return *this;
}

Account& Account::operator=(Account&& other) {
    std::cout << "(" << this << ")Account move assignment (" << &other << ")" << std::endl;
    if (this == &other)
        return *this;
    // delete storage
    delete p_amount;
    // steal pointer
    p_amount = other.p_amount;
    // set other's pointer to nullptr
    other.p_amount = nullptr;

    return *this;
}

