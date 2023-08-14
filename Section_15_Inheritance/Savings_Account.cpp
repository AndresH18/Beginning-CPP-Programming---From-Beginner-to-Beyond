//
// Created by andre on 13/8/2023.
//

#include "Savings_Account.h"

Savings_Account::Savings_Account() {

}

Savings_Account::~Savings_Account() {

}

void Savings_Account::deposit(double amount) {
    Account::deposit(amount);
}

void Savings_Account::withdraw(double amount) {
    Account::withdraw(amount);
}
