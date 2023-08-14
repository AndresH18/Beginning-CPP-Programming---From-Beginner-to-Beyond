//
// Created by andre on 13/8/2023.
//

#include <iostream>
#include "Account.h"

Account::Account() : amount{0} {
}

Account::Account(double amount) : amount{amount} {}

Account::Account(const Account& account) : amount{account.amount} {}

Account::Account(Account&& account) : amount{account.amount} {}


Account::~Account() {}

void Account::deposit(double amount) {
    std::cout << "Account deposit called with " << amount << std::endl;
}

void Account::withdraw(double amount) {
    std::cout << "Account withdraw called with " << amount << std::endl;
}

double Account::get_amount() const {
    return amount;
}

void Account::set_amount(double amount) {
    Account::amount = amount;
}

Account& Account::operator=(const Account& other) {
    if (this == &other)
        return *this;

    this->amount = other.amount;

    return *this;
}

Account& Account::operator=(const Account&& other) {
    if (this == &other)
        return *this;


}

