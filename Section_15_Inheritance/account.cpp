//
// Created by andre on 13/8/2023.
//

#include <iostream>
#include "account.h"

Account::Account() {
    std::cout << "(" << this << ")Account constructor ()" << std::endl;
    p_balance = new double;
    *p_balance = 0;
}

Account::Account(double amount) : Account() {
    std::cout << "(" << this << ")Account constructor (double)" << std::endl;
    *this->p_balance = amount;
}

Account::Account(const Account& account) : p_balance{nullptr} {
    std::cout << "(" << this << ")Account copy constructor (" << &account << ")" << std::endl;
    p_balance = new double;
    *p_balance = *account.p_balance;
}

Account::Account(Account&& account) : p_balance{account.p_balance} {
    std::cout << "(" << this << ")Account move constructor (" << &account << ")" << std::endl;
    account.p_balance = nullptr;
}


Account::~Account() {
    std::cout << "(" << this << ")Account Destructor" << std::endl;
    delete p_balance;
}

void Account::deposit(double amount) {
    std::cout << "(" << this << ")Account deposit called with " << amount << std::endl;
}

void Account::withdraw(double amount) {
    std::cout << "(" << this << ")Account withdraw called with " << amount << std::endl;
}

double Account::get_balance() const {
    return *p_balance;
}

void Account::set_balance(double amount) {
    *Account::p_balance = amount;
}

Account& Account::operator=(const Account& other) {
    std::cout << "(" << this << ")Account copy assignment (" << &other << ")" << std::endl;
    if (this == &other)
        return *this;

    delete p_balance; // delete
    // create new storage
    p_balance = new double;
    // copy value
    *p_balance = *other.p_balance;

    return *this;
}

Account& Account::operator=(Account&& other) {
    std::cout << "(" << this << ")Account move assignment (" << &other << ")" << std::endl;
    if (this == &other)
        return *this;
    // delete storage
    delete p_balance;
    // steal pointer
    p_balance = other.p_balance;
    // set other's pointer to nullptr
    other.p_balance = nullptr;

    return *this;
}

