//
// Created by andre on 18/8/2023.
//

#include "account.h"


#include "illegal_balance_exception.h"

Account::Account(std::string name, double balance) : name{std::move(name)}, balance{balance} {
    if (balance < 0.0)
        throw IllegalBalanceException{};
}