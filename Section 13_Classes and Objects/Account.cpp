//
// Created by andre on 2/8/2021.
//

#include "Account.h"

// #include with "" tells the compiler to include header local to this project
// #include with <>tells the compiler to include system header files
Account::Account() : Account{"no name", 0} {

}

Account::Account(std::string name, double balance) : name{name}, balance{balance} {

}

void Account::set_balance(double bal) {
    balance = bal;
}

double Account::get_balance() { return balance; }

const std::string &Account::getName() const {
    return name;
}

double Account::getBalance() const {
    return balance;
}

Account::Account(const Account &source) : balance{source.balance}, name{source.name} {

}
