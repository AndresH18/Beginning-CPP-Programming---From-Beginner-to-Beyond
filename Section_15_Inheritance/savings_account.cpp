//
// Created by andre on 13/8/2023.
//

#include "savings_account.h"

SavingsAccount::SavingsAccount() : rate{0.1} {
}

SavingsAccount::SavingsAccount(double rate) : rate{rate}, Account{0} {
}

SavingsAccount::SavingsAccount(double rate, double amount) : Account{amount}, rate{rate} {}

SavingsAccount::~SavingsAccount() {

}

void SavingsAccount::deposit(double amount) {
    Account::deposit(amount);
}

void SavingsAccount::withdraw(double amount) {
    Account::withdraw(amount);
}

